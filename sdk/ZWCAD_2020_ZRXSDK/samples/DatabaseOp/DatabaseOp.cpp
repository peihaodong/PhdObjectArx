// DatabaseOp.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "DatabaseOp.h"

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

// CDatabaseOpApp

BEGIN_MESSAGE_MAP(CDatabaseOpApp, CWinApp)
END_MESSAGE_MAP()


// CDatabaseOpApp construction

CDatabaseOpApp::CDatabaseOpApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CDatabaseOpApp object

CDatabaseOpApp theApp;


// CDatabaseOpApp initialization

BOOL CDatabaseOpApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
void createDatabase();
void readDatabase();

void initApp();
void unloadApp();
void RegisterZrxApp();


/////////////////////////////////////////////////////////////////////////////
// ZRX EntryPoint
extern "C" AcRx::AppRetCode 
zcrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
    AcRxDynamicLinker *pLinker = acrxDynamicLinker;
    switch (msg) {
    case AcRx::kInitAppMsg:
        // Comment out the following line if your
        // application should be locked into memory
        pLinker->unlockApplication(pkt);
        pLinker->registerAppMDIAware(pkt);
        initApp();
        break;
    case AcRx::kUnloadAppMsg:
        unloadApp();
        break;
    }
    return AcRx::kRetOK;
}


// Init this application. Register your
// commands, reactors...
void initApp()
{
	acedRegCmds->addCommand(_T("DATABASEOP_CMDS"), _T("ZSDK_CREATEDB"), _T("CREATEDB"), ACRX_CMD_MODAL, createDatabase);
	acedRegCmds->addCommand(_T("DATABASEOP_CMDS"), _T("ZSDK_READDB"),   _T("READDB"),   ACRX_CMD_MODAL, readDatabase);
    RegisterZrxApp();
}

// Unload this application. Unregister all objects
// registered in initApp.
void unloadApp()
{
    acedRegCmds->removeGroup(_T("DATABASEOP_CMDS"));
}

void RegisterZrxApp()
{
    // Fill the AppInfo structure with our demand loading details.
    AcadAppInfo appInfo;
    appInfo.setAppName(_T("DatabaseOp"));// Application Name
    appInfo.setModuleName(acedGetAppName());// ARX File Location
    appInfo.setAppDesc(_T("DatabaseOp Sample")); // Description
    appInfo.setLoadReason( // Specify when we want this to load
        AcadApp::LoadReasons(
        AcadApp::kOnCommandInvocation |
        AcadApp::kOnLoadRequest));
    
    appInfo.writeToRegistry(false, true);// Write the AppInfo to the registry, don't write to DBX registry section.
    appInfo.writeGroupNameToRegistry(_T("DATABASEOP_CMDS")); // Write the Group Name
    appInfo.writeCommandNameToRegistry(_T("CREATEDB"), _T("CREATEDB"));// Write our command.
    appInfo.writeCommandNameToRegistry(_T("READDB"), _T("READDB"));// Write our command.
}


void createDatabase()
{
	// Create a new Database.
	AcDbDatabase *pDb = new AcDbDatabase();

	// Get the BlockTable.
	AcDbBlockTable *pBTable = NULL;
	pDb->getSymbolTable(pBTable, AcDb::kForRead);

	// Get the ModelSpace.
	AcDbBlockTableRecord *pRecord = NULL;
	pBTable->getAt(ACDB_MODEL_SPACE, pRecord, AcDb::kForWrite);
	pBTable->close();

	// Create a new Circle.
	AcDbCircle *pCircle1 = new AcDbCircle(AcGePoint3d(100,100,0),
		AcGeVector3d(0,0,1),
		50.0);
	// Create another new Circle.
	AcDbCircle *pCircle2 = new AcDbCircle(AcGePoint3d(200,200,0),
		AcGeVector3d(0,0,1),
		30.0);

	// Append Circle1 to ModelSpace
	pRecord->appendAcDbEntity(pCircle1);
	pCircle1->close();

	// Append Circle2 to ModelSpace
	pRecord->appendAcDbEntity(pCircle2);
	pCircle2->close();

	pRecord->close();

	// Save to file
	// MUST append a DWG file extension.
	acutPrintf(_T("\nSave file to \"d:\\temp\\testfile.dwg\"."));
	pDb->saveAs(_T("d:\\temp\\testfile.dwg"));

	delete pDb;
}

void readDatabase()
{
	// Use kFalse to create an empty database.
    AcDbDatabase *pDb = new AcDbDatabase(Adesk::kFalse);

    // Use readDwgFile to load the DWG file.
	acutPrintf(_T("\nRead file \"d:\\temp\\testfile.dwg\"."));
    if(Acad::eOk != pDb->readDwgFile(_T("d:\\temp\\testfile.dwg")))
        return;

    // Get the BlockTable.
    AcDbBlockTable *pBTable = NULL;
    pDb->getSymbolTable(pBTable, AcDb::kForRead);

	// Get the ModelSpace.
    AcDbBlockTableRecord *pRecord = NULL;
    pBTable->getAt(ACDB_MODEL_SPACE, pRecord, AcDb::kForRead);
    pBTable->close();

	// Get new iterator.
    AcDbBlockTableRecordIterator *pItr = NULL;
    pRecord->newIterator(pItr);

    AcDbEntity *pEnt = NULL;
    for (pItr->start(); !pItr->done(); pItr->step())
    {
        pItr->getEntity(pEnt, AcDb::kForRead);
        acutPrintf(_T("\nclassname: %s"), (pEnt->isA())->name());
        pEnt->close();
    }
    pRecord->close();
    delete pItr;
    delete pDb;
}

