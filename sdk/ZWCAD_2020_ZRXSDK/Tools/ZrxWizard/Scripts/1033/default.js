

// http://msdn.microsoft.com/en-us/library/aa291835(v=VS.71).aspx
// http://msdn.microsoft.com/en-us/library/microsoft.visualstudio.vswizard.vcwizctlclass_members.aspx

function OnFinish (selProj, selObj) {
    try {
        var strProjectPath = wizard.FindSymbol('PROJECT_PATH');
        var strProjectName = wizard.FindSymbol('PROJECT_NAME');
        wizard.AddSymbol("UPPER_CASE_PROJECT_NAME", strProjectName.toUpperCase());

        wizard.AddSymbol("SAFE_PROJECT_NAME", CreateSafeName(strProjectName));
        wizard.AddSymbol("UPPER_CASE_SAFE_PROJECT_NAME", CreateSafeName(strProjectName.toUpperCase()));

        selProj = MakeMainProject(strProjectPath, strProjectName);
       
	} catch (e) {
		if ( e.description.length != 0 )
			SetErrorInfo (e) ;
		return (e.number) ;
	}
}


//-----------------------------------------------------------------------------
function AddFilesToCustomProj (proj, strProjectName, strProjectPath, InfFile) {
	try {
		var projItems =proj.ProjectItems ;

		var strTemplatePath =wizard.FindSymbol ('TEMPLATES_PATH') ;

		var strTpl ='' ;
		var strName ='' ;

		var bUseMFC = wizard.FindSymbol('MFC_EXT_SHARED');

		var strTextStream =InfFile.OpenAsTextStream (1, -2) ;
		while ( !strTextStream.AtEndOfStream ) {
			strTpl =strTextStream.ReadLine () ;
			if ( strTpl != '' ) {
			    strName = strTpl;
                
                if ( !bUseMFC ) {
                    if (strName == 'resource.h' || strName == 'SampleDlg.h' || strName == 'SampleDlg.cpp' || strName == 'DlgSample.rc') {
                        continue;
                    }
                }

				var strTarget =GetTargetName (strName, strProjectName) ;
				var strTemplate =strTemplatePath + '\\' + strTpl ;
				var strFile =strProjectPath + '\\' + strTarget ;

				var bCopyOnly =false ;  //----- "true" will only copy the file from strTemplate to strTarget without rendering/adding to the project
				var strExt =strName.substr (strName.lastIndexOf ('.')) ;
				if ( strExt == '.bmp' || strExt==".ico" || strExt=='.gif' || strExt=='.rtf' || strExt=='.css' )
					bCopyOnly =true ;
				wizard.RenderTemplate (strTemplate, strFile, bCopyOnly) ;
				proj.Object.AddFile (strFile) ;
		}
		}
		strTextStream.Close () ;
	} catch (e) {
		throw e ;
	}
}

//-----------------------------------------------------------------------------
function GetTargetName(strName, strProjectName) {
    try {
        //----- Set the name of the rendered file based on the template filename
        var strTarget = strName;

        if (strName.substr(0, 4) == 'Root')
            strTarget = strProjectName + strName.substr(4, strName.length - 4);

        else if (strName.substr(0, 3) == 'Omf')
            strTarget = strProjectName + strName.substr(3, strName.length - 3);

        else if (strName.substr(0, 10) == 'ProjectDef')
            strTarget = strProjectName + strName.substr(10, strName.length - 10);

        return (strTarget);
    } catch (e) {
        throw e;
    }
}

//-----------------------------------------------------------------------------
function MakeMainProject(strProjectPath, strProjectName)
{
    var selProj = CreateProject(strProjectName, strProjectPath);

    var bUseMFC = wizard.FindSymbol('MFC_EXT_SHARED');

	AddConfig(selProj, strProjectName, true, bUseMFC);
	AddConfig(selProj, strProjectName, false, bUseMFC);

    SetupFilters(selProj);
    var InfFile = CreateInfFile();
    AddFilesToCustomProj(selProj, strProjectName, strProjectPath, InfFile);

    InfFile.Delete();

    SetCommonPchSettings(selProj);
    selProj.Object.Save();

    return selProj;
}

function AddConfig(proj, strProjectName, bDebug, bUseMFC)
{
	try {
	    var szUprProjectName = CreateSafeName(strProjectName.toUpperCase());
		
		var cfgName = bDebug ? 'Debug' : 'Release';
		cfgName += '|Win32';
		var config = proj.Object.Configurations(cfgName);
		if ( config == null )
		    return;

		var CLTool = config.Tools('VCCLCompilerTool');
		CLTool.UsePrecompiledHeader = pchUseUsingSpecific;
		CLTool.PreprocessorDefinitions += ';' + szUprProjectName + '_MODULE';

		var useMFC = !bUseMFC ? useOfMfc.useMfcStdWin : useOfMfc.useMfcDynamic
		config.useOfMfc = useMFC
	}
	catch (e)
	{
		throw e;
	}
}

