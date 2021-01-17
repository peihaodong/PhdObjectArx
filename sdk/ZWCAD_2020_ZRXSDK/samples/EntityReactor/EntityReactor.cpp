
//
#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include <dbents.h>
#include <dbapserv.h>
#include "adscodes.h"

#include "ZcEntityReactor.h"


ZcEntityReactor* g_pEntReactor = NULL;


void initApp();
void unloadApp();
void EntityReactor();
void RemoveEntityReactor();
void ClearEntityReactor();

void initApp()
{
	acedRegCmds->addCommand(_T("ENTITYREACTOR"), _T("EntReactor"), _T("EntReactor"), ACRX_CMD_TRANSPARENT, EntityReactor);
	acedRegCmds->addCommand(_T("ENTITYREACTOR"), _T("RemoveEntReactor"), _T("RemoveEntReactor"), ACRX_CMD_TRANSPARENT, RemoveEntityReactor);
	acedRegCmds->addCommand(_T("ENTITYREACTOR"), _T("ClearEntReactor"), _T("ClearEntReactor"), ACRX_CMD_TRANSPARENT, ClearEntityReactor);
}

void unloadApp()
{
	ClearEntityReactor();
	acedRegCmds->removeGroup(_T("ENTITYREACTOR"));
}

void EntityReactor()
{
	AcDbObject* pEnt = ZcEntityReactor::selectObject(AcDb::kForWrite);

	if (g_pEntReactor == NULL)
	{
		g_pEntReactor = new ZcEntityReactor();
	}

	g_pEntReactor->addReactorToObject(pEnt);
	pEnt->close();
}

void RemoveEntityReactor()
{
	AcDbObject* pEnt = ZcEntityReactor::selectObject(AcDb::kForWrite);

	if (g_pEntReactor != NULL)
	{
		g_pEntReactor->delReactorFromObject(pEnt);
	}

	pEnt->close();
}

void ClearEntityReactor()
{
	if (g_pEntReactor != NULL)
	{
		delete g_pEntReactor;
		g_pEntReactor = NULL;
	}
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
