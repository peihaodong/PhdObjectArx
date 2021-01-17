//

#include "stdafx.h"



#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include <dbents.h>
#include <dbapserv.h>

void initApp();
void unloadApp();
void drawLine();

void initApp()
{	
	acedRegCmds->addCommand(_T("DRAWLINE_COMMANDS"),
							_T("DLine"),
							_T("DLine"),
							ACRX_CMD_TRANSPARENT,
							drawLine);
}

void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("DRAWLINE_COMMANDS"));
}

void drawLine()
{ 
	AcGePoint3d startPt(4.0, 2.0, 0.0);
	AcGePoint3d endPt(10.0, 7.0, 0.0);
	AcDbLine *pLine = new AcDbLine(startPt, endPt);

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pBlockTable, AcDb::kForRead);

	AcDbBlockTableRecord *pBlockTableRecord;
	pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,	AcDb::kForWrite);
	pBlockTable->close();

	AcDbObjectId lineId;
	pBlockTableRecord->appendAcDbEntity(lineId, pLine);

	pBlockTableRecord->close();
	pLine->close();
}

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
