
//
#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include <dbents.h>
#include <dbapserv.h>
#include "adscodes.h"


void initApp();
void unloadApp();

void CreateLayer();
void ModifyLayerProp();
void ModifyEntityLayer();
void DelLayer();


void initApp()
{
	acedRegCmds->addCommand(_T("LAYERSAMPLE"), _T("CreateLayer"), _T("CreateLayer"), ACRX_CMD_TRANSPARENT, CreateLayer);
	acedRegCmds->addCommand(_T("LAYERSAMPLE"), _T("ModifyLayerProp"), _T("ModifyLayerProp"), ACRX_CMD_TRANSPARENT, ModifyLayerProp);
	acedRegCmds->addCommand(_T("LAYERSAMPLE"), _T("ModifyEntityLayer"), _T("ModifyEntityLayer"), ACRX_CMD_TRANSPARENT, ModifyEntityLayer);
	acedRegCmds->addCommand(_T("LAYERSAMPLE"), _T("DelLayer"), _T("DelLayer"), ACRX_CMD_TRANSPARENT, DelLayer);
}

void unloadApp()
{
	acedRegCmds->removeGroup(_T("LAYERSAMPLE"));
}

void CreateLayer()
{
	Acad::ErrorStatus es;
	ACHAR szNewName[255];
	_tcscpy(szNewName, _T("NewLayer"));

	AcDbDatabase* pCurDb = acdbHostApplicationServices()->workingDatabase();
	if (pCurDb == NULL)
	{
		acutPrintf(_T("\nError:Current database is NULL!"));
		return;
	}

	AcDbLayerTableRecord* pNewLayer = new AcDbLayerTableRecord;
	es = pNewLayer->setName(szNewName);
	if (es != Acad::eOk)
	{
		acutPrintf(_T("\nFailed setName of the layer!"));
		delete pNewLayer;
		return;
	}

	AcCmColor cmColor;
	cmColor.setColorIndex(1);
	pNewLayer->setColor(cmColor);

	pNewLayer->setIsFrozen(false);
	pNewLayer->setIsOff(false);
	pNewLayer->setVPDFLT(false);
	pNewLayer->setIsLocked(false);

	bool bStat = false;
	AcDbLayerTable* pLayerTbl = NULL;
	es = pCurDb->getLayerTable(pLayerTbl, AcDb::kForWrite);
	if (es == Acad::eOk)
	{
		if (pLayerTbl->has(szNewName))
		{
			acutPrintf(_T("\nThe Layer \"%s\" has existed!"), szNewName);
			delete pNewLayer;
		}
		else
		{
			es = pLayerTbl->add(pNewLayer);
			if (es == Acad::eOk)
			{
				bStat = true;
				pNewLayer->close();
			}
			else
			{
				acutPrintf(_T("\nFailed to add a new layer in LayerTable!"));
				delete pNewLayer;
			}
		}

		pLayerTbl->close();
	}

	if (bStat)
	{
		acutPrintf(_T("\nCreated the new layer: \"%s\" successfully!"), szNewName);
	}
	else
	{
		acutPrintf(_T("\nFailed to create the layer: \"%s\""), szNewName);
	}
}

void ModifyLayerProp()
{
	CString strLayerName(_T("NewLayer"));

	AcDbLayerTable* pLayerTbl = NULL;
	acdbHostApplicationServices()->workingDatabase()->getLayerTable(pLayerTbl, AcDb::kForRead);

	if (!pLayerTbl->has(strLayerName))
	{
		pLayerTbl->close();
		acutPrintf(_T("\nNo existed layer:\"%s\"."), strLayerName);
		return;
	}

	Acad::ErrorStatus es;
	AcDbLayerTableRecord* pLayerTblRcd = NULL;
	pLayerTbl->getAt(strLayerName, pLayerTblRcd, AcDb::kForWrite);

	AcCmColor oldColor = pLayerTblRcd->color();
	int nCurColor = oldColor.colorIndex();
	int nNewColor = oldColor.colorIndex();

	if (acedSetColorDialog(nNewColor, Adesk::kFalse, nCurColor))
	{
		AcCmColor color;
		color.setColorIndex(nNewColor);
		pLayerTblRcd->setColor(color);
		acutPrintf(_T("\nThe color of  layer:\"%s\" has modified!"), strLayerName);
	}

	pLayerTblRcd->close();
	pLayerTbl->close();
}

void ModifyEntityLayer()
{
	int nRet = 0;
	ads_name entName;
	ads_point ptPick;
	nRet = acedEntSel(_T("\nSelect an entity to change it's layer:"), entName, ptPick);
	if (nRet != RTNORM)
	{
		acutPrintf(_T("\nFailed to select!"));
		return;
	}

	Acad::ErrorStatus es;
	AcDbObjectId objId;
	AcDbEntity* pEnt = NULL;
	acdbGetObjectId(objId, entName);
	es = acdbOpenAcDbEntity(pEnt, objId, AcDb::kForWrite);
	if (es != Acad::eOk)
	{
		acutPrintf(_T("\nFailed to open entity!"));
		return;
	}

	ACHAR szNewName[255];
	_tcscpy(szNewName, _T("NewLayer"));
	bool bHasDone = false;

	AcDbDatabase* pCurDb = acdbHostApplicationServices()->workingDatabase();
	if (pCurDb == NULL)
	{
		acutPrintf(_T("\nError:Current database is NULL!"));
		return;
	}

	AcDbObjectId layerId;
	AcDbLayerTable* pLayerTbl = NULL;
	es = pCurDb->getLayerTable(pLayerTbl, AcDb::kForRead);
	if (es == Acad::eOk)
	{
		if (pLayerTbl->has(szNewName))
		{
			es = pLayerTbl->getAt(szNewName, layerId);
			if (es == Acad::eOk)
			{
				es = pEnt->setLayer(layerId);
				if (es == Acad::eOk)
				{
					bHasDone = true;
				}
			}
		}

		pLayerTbl->close();
	}

	pEnt->close();

	if (bHasDone)
	{
		acutPrintf(_T("\nThe layer of entity has modified to layer:\"%s\""), szNewName);
	}
	else
	{
		acutPrintf(_T("\nFailed to modify the layer of entity to layer:\"%s\""), szNewName);
	}

}

void DelLayer()
{
	ACHAR szNewName[256];
	_tcscpy(szNewName, _T("NewLayer"));
	AcDbDatabase* pCurDb = acdbHostApplicationServices()->workingDatabase();
	if (pCurDb == NULL)
	{
		acutPrintf(_T("\nError:Current database is NULL!"));
		return;
	}

	bool bHas = false;
	bool bDeled = false;
	Acad::ErrorStatus es;
	AcDbObjectId layerId;
	AcDbLayerTable* pLayerTbl = NULL;
	es = pCurDb->getLayerTable(pLayerTbl, AcDb::kForRead);
	if (es == Acad::eOk)
	{
		if (pLayerTbl->has(szNewName))
		{
			AcDbLayerTableRecord* pLayerTblRcd = NULL;
			AcDbLayerTableIterator* pLTblIter = NULL;
			pLayerTbl->newIterator(pLTblIter);

			for (pLTblIter->start(); !pLTblIter->done(); pLTblIter->step())
			{
				ACHAR* szLayerName = NULL;
				pLTblIter->getRecord(pLayerTblRcd, AcDb::kForWrite, true);
				if (pLayerTblRcd)
				{
					pLayerTblRcd->getName(szLayerName);
					if (_tcscmp(szNewName, szLayerName) == 0)
					{
						es = pLayerTblRcd->erase(true);
						if (es == Acad::eOk)
						{
							bDeled = true;
						}
					}

					if (szLayerName)
					{
						ads_free(szLayerName);
					}

					pLayerTblRcd->close();
				}
			}

			if (pLTblIter)
			{
				delete pLTblIter;
				pLTblIter = NULL;
			}
		}

		pLayerTbl->close();
	}

	if (bDeled)
	{
		acutPrintf(_T("\nErased the layer: \"%s\" successfully!"), szNewName);
	}
	else
	{
		acutPrintf(_T("\nFailed to erase the layer: \"%s\""), szNewName);
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
