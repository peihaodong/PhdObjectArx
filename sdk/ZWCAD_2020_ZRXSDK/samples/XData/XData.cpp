// XData.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "XData.h"

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

// CXDataApp

BEGIN_MESSAGE_MAP(CXDataApp, CWinApp)
END_MESSAGE_MAP()


// CXDataApp construction

CXDataApp::CXDataApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CXDataApp object

CXDataApp theApp;


// CXDataApp initialization

BOOL CXDataApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}


///////////////////////////////////////////////////////////////////////////////
void addXData();
void printXData();
void printXDList(resbuf* pRb);

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
	acedRegCmds->addCommand(_T("XDATA_CMDS"), _T("ZSDK_ADDXDATA"),   _T("ADDXDATA"),   ACRX_CMD_MODAL, addXData);
	acedRegCmds->addCommand(_T("XDATA_CMDS"), _T("ZSDK_PRINTXDATA"), _T("PRINTXDATA"), ACRX_CMD_MODAL, printXData);
    RegisterZrxApp();
}

// Unload this application. Unregister all objects
// registered in initApp.
void unloadApp()
{
    acedRegCmds->removeGroup(_T("XDATA_CMDS"));
}

void RegisterZrxApp()
{
    // Fill the AppInfo structure with our demand loading details.
    AcadAppInfo appInfo;
    appInfo.setAppName(_T("XData"));// Application Name
    appInfo.setModuleName(acedGetAppName());// ARX File Location
    appInfo.setAppDesc(_T("XData Sample")); // Description
    appInfo.setLoadReason( // Specify when we want this to load
        AcadApp::LoadReasons(
        AcadApp::kOnCommandInvocation |
        AcadApp::kOnLoadRequest));
    
    appInfo.writeToRegistry(false, true);// Write the AppInfo to the registry, don't write to DBX registry section.
    appInfo.writeGroupNameToRegistry(_T("XDATA_CMDS")); // Write the Group Name
    appInfo.writeCommandNameToRegistry(_T("ADDXDATA"), _T("ADDXDATA"));// Write our command.
    appInfo.writeCommandNameToRegistry(_T("PRINTXDATA"), _T("PRINTXDATA"));// Write our command.
}

void printXDList(resbuf* pRb)
{
    int rt = 0;
	int i = 0;
	TCHAR buf[133] = {0};

    for (i = 0;pRb != NULL;i++, pRb = pRb->rbnext)
	{
        if      (pRb->restype < 1010)  rt = RTSTR;
		else if (pRb->restype < 1040)  rt = RT3DPOINT;
		else if (pRb->restype < 1060)  rt = RTREAL;
		else if (pRb->restype < 1071)  rt = RTSHORT;
		else if (pRb->restype == 1071) rt = RTLONG;
		else                           rt = pRb->restype; // other

        switch (rt)
		{
        case RTSHORT:
			acutPrintf(_T("\n(%d . %d)"), pRb->restype, pRb->resval.rint);
            break;
        case RTREAL:
			acutPrintf(_T("\n(%d . %0.3f)"), pRb->restype, pRb->resval.rreal);
            break;
        case RTSTR:
			acutPrintf(_T("\n(%d . \"%s\")"), pRb->restype, pRb->resval.rstring);
            break;
        case RT3DPOINT:
			acutPrintf(_T("\n(%d %0.3f %0.3f %0.3f)"), pRb->restype, pRb->resval.rpoint[X], pRb->resval.rpoint[Y], pRb->resval.rpoint[Z]);
            break;
        case RTLONG:
            acutPrintf(_T("\n%ld"), pRb->resval.rlong);
            break;
        }
    }
}

void addXData()
{
	// Get an Entity.
	ads_name mnEnt;
    ads_point ptSel;
    int nRet = acedEntSel(_T("\nSelect an Entity: "), mnEnt, ptSel);
	if (nRet != RTNORM)
		return;
	AcDbObjectId oid;
	
    Acad::ErrorStatus retStat;
    retStat = acdbGetObjectId(oid, mnEnt);
    if (retStat != Acad::eOk)
		return;

    AcDbObject* pObj = NULL;

    if ((retStat = acdbOpenObject(pObj, oid, AcDb::kForRead)) != Acad::eOk)
    {
        return;
    }
	// Get new XData.
	TCHAR appName[132] = {0};
	TCHAR resString[200] = {0};

    acedGetString(NULL, _T("\nEnter application name: "), appName);
    acedGetString(NULL, _T("\nEnter string to be added: "), resString);

    // XData
    resbuf *pRb = NULL;
	resbuf *pTemp = NULL;
    
    pRb = pObj->xData(appName);

    if (pRb != NULL)
	{
        for (pTemp = pRb; pTemp->rbnext != NULL; pTemp = pTemp->rbnext);
    }
	else
	{
        acdbRegApp(appName);
        pRb = acutNewRb(AcDb::kDxfRegAppName);
        pTemp = pRb;
        pTemp->resval.rstring = (TCHAR*)malloc((_tcslen(appName) + 1) * sizeof(TCHAR));
        _tcscpy(pTemp->resval.rstring, appName);
    }

    pTemp->rbnext = acutNewRb(AcDb::kDxfXdAsciiString);
    pTemp = pTemp->rbnext;
    pTemp->resval.rstring = (TCHAR*)malloc((_tcslen(resString) + 1) * sizeof(TCHAR));
    _tcscpy(pTemp->resval.rstring, resString);

	// Set XData.
    pObj->upgradeOpen();
    pObj->setXData(pRb);
    
    pObj->close();
    acutRelRb(pRb);
}

void printXData()
{
	// Get an Entity.
	ads_name mnEnt;
    ads_point ptSel;
    int nRet = acedEntSel(_T("\nSelect an Entity: "), mnEnt, ptSel);
	if (nRet != RTNORM)
		return;
	AcDbObjectId oid;
	
    Acad::ErrorStatus retStat;
    retStat = acdbGetObjectId(oid, mnEnt);
    if (retStat != Acad::eOk)
		return;

    AcDbObject* pObj = NULL;

    if ((retStat = acdbOpenObject(pObj, oid, AcDb::kForRead)) != Acad::eOk)
    {
        return;
    }

    // Get the application name for the xdata.
    //
	TCHAR appname[133] = {0};
    if (acedGetString(NULL, _T("\nEnter the Xdata application name: "), appname) != RTNORM)
    {
        return;
    }

    // Get the xdata for the application name.
    //
    resbuf *pRb = pObj->xData(appname);

    if (pRb != NULL)
	{
        printXDList(pRb);
        acutRelRb(pRb);
    }
	else
	{
        acutPrintf(_T("\nNo xdata for appname: %s."), appname);
    }
    pObj->close();
}

