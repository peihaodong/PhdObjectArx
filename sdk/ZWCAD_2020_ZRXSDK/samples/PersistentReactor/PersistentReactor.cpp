// PersistentReactor.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "PersistentReactor.h"
#include "LinePersistentReactor.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CPersistentReactorApp

BEGIN_MESSAGE_MAP(CPersistentReactorApp, CWinApp)
END_MESSAGE_MAP()


// CPersistentReactorApp construction

CPersistentReactorApp::CPersistentReactorApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CPersistentReactorApp object

CPersistentReactorApp theApp;


// CPersistentReactorApp initialization

BOOL CPersistentReactorApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}


/////////////////////////////////////////////////////////////////

AcDbObjectId createLine()
{
	AcGePoint3d startPt(4.0, 2.0, 0.0);
	AcGePoint3d endPt(10.0, 7.0, 0.0);
	AcDbLine *pLine = new AcDbLine(startPt, endPt);

	AcDbBlockTable *pBlockTable;
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	if (!pDb)
		return AcDbObjectId::kNull;

	pDb->getSymbolTable(pBlockTable, AcDb::kForRead);

	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId lineId;
	pBlockTableRecord->appendAcDbEntity(lineId, pLine);

	pBlockTableRecord->close();
	pLine->close();

	return lineId;
}

AcDbObjectId createCircle()
{
	AcGePoint3d center(9.0, 3.0, 0.0);
	AcGeVector3d normal(0.0, 0.0, 1.0);
	AcDbCircle *pCirc = new AcDbCircle(center, normal, 2.0);

	AcDbBlockTable *pBlockTable;
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	pDb->getSymbolTable(pBlockTable, AcDb::kForRead);

	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,	AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId circleId;
	pBlockTableRecord->appendAcDbEntity(circleId, pCirc);

	pBlockTableRecord->close();
	pCirc->close();

	return circleId;
}

void initApp();
void unloadApp();
void RegisterZrxApp();

void cmd_PersistentReactor();

extern "C" AcRx::AppRetCode
zcrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);

		initApp();
		break;
	case AcRx::kUnloadAppMsg:
		unloadApp();
		break;
	default:
		break;
	}

	return AcRx::kRetOK;
}

void initApp()
{
	acedRegCmds->addCommand(_T("PERSISTENTREACTOR_CMDS"),
		_T("PersistentReactor"),
		_T("PersistentReactor"),
		ACRX_CMD_MODAL,
		cmd_PersistentReactor);
	
	LinePersistentReactor::rxInit();
	acrxBuildClassHierarchy();

	RegisterZrxApp();
}

void unloadApp()
{
	acedRegCmds->removeGroup(_T("PERSISTENTREACTOR_CMDS"));
	
	deleteAcRxClass(LinePersistentReactor::desc());
}

void RegisterZrxApp()
{
    // Fill the AppInfo structure with our demand loading details.
    AcadAppInfo appInfo;
    appInfo.setAppName(_T("PersistentReactor"));// Application Name
    appInfo.setModuleName(acedGetAppName());// ARX File Location
    appInfo.setAppDesc(_T("PersistentReactor Sample")); // Description
    appInfo.setLoadReason( // Specify when we want this to load
        AcadApp::LoadReasons(
        AcadApp::kOnCommandInvocation |
        AcadApp::kOnLoadRequest));
    
    appInfo.writeToRegistry(false,true);// Write the AppInfo to the registry, don't write to DBX registry section.
    appInfo.writeGroupNameToRegistry(_T("PERSISTENTREACTOR_CMDS")); // Write the Group Name
    appInfo.writeCommandNameToRegistry(_T("PersistentReactor"),_T("PersistentReactor"));// Write our command.
}

void cmd_PersistentReactor()
{
	AcDbObjectId lineId = createLine();
	AcDbObjectId circleId = createCircle();
	
	AcDbObjectId reactorId1;
	AcDbObjectId reactorId2;
	LinePersistentReactor* pReactor1 = new LinePersistentReactor(circleId);
	LinePersistentReactor* pReactor2 = new LinePersistentReactor(lineId);

	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	AcDbDictionary* pDict = NULL;
	AcDbDictionary* pNamedList = NULL;

	pDb->getNamedObjectsDictionary(pDict, ZcDb::kForWrite);
	if (pDict)
	{
		if (pDict->getAt(_T("Zsdk_PersistentReactor_Dict"), (AcDbObject*&)pNamedList, ZcDb::kForWrite) == Zcad::eKeyNotFound)
		{
			pNamedList = new AcDbDictionary();
			AcDbObjectId listId;
			pDict->setAt(_T("Zsdk_PersistentReactor_Dict"), pNamedList, listId);
		}
		pDict->close();

		int nNameIdx = 0;
		AcString sPeriReactorName;
		AcDbObjectId oid;
		do
		{
			sPeriReactorName.format(_T("ZsdkLinePeriReactor%d"), nNameIdx++);
		}while(Acad::eOk == pNamedList->getAt(sPeriReactorName, oid));

		pNamedList->setAt(sPeriReactorName, pReactor1, reactorId1);
		pReactor1->close();

		do
		{
			sPeriReactorName.format(_T("ZsdkLinePeriReactor%d"), nNameIdx++);
		}while(Acad::eOk == pNamedList->getAt(sPeriReactorName, oid));

		pNamedList->setAt(sPeriReactorName, pReactor2, reactorId2);
		pReactor2->close();

		pNamedList->close();
	}

	AcDbLine* pLine = NULL;
	acdbOpenAcDbEntity((AcDbEntity*&)pLine, lineId, ZcDb::kForWrite);
	if (pLine)
	{
		pLine->addPersistentReactor(reactorId1);
		pLine->close();
	}

	AcDbLine* pCircle = NULL;
	acdbOpenAcDbEntity((AcDbEntity*&)pCircle, circleId, ZcDb::kForWrite);
	if (pCircle)
	{
		pCircle->addPersistentReactor(reactorId2);
		pCircle->close();
	}
}
