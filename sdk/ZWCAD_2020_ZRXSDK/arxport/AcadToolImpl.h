
#ifndef __ACADTOOLIMPL_H__
#define __ACADTOOLIMPL_H__

#include "AcImportXml.h"
using namespace MSXML; 
#include "AcPExCtl.h"
#include "opmdialog.h"
#include "Ac64BitHelpers.h"
#include "../inc/zAcadToolImpl.h"

#ifndef ACDB_MODEL_SPACE
#define ACDB_MODEL_SPACE		ZCDB_MODEL_SPACE
#endif //#ifndef ACDB_MODEL_SPACE

#ifndef Ac64BitHelpers
#define Ac64BitHelpers		Zc64BitHelpers
#endif //#ifndef Ac64BitHelpers

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcAxDocLock
#define AcAxDocLock		ZcAxDocLock
#endif //#ifndef AcAxDocLock

#ifndef AcCmColor
#define AcCmColor		ZcCmColor
#endif //#ifndef AcCmColor

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcDbBlockTableRecordIterator
#define AcDbBlockTableRecordIterator		ZcDbBlockTableRecordIterator
#endif //#ifndef AcDbBlockTableRecordIterator

#ifndef AcDbBlockTableRecordPointer
#define AcDbBlockTableRecordPointer		ZcDbBlockTableRecordPointer
#endif //#ifndef AcDbBlockTableRecordPointer

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbEntity
#define AcDbEntity		ZcDbEntity
#endif //#ifndef AcDbEntity

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcImportXml
#define AcImportXml		ZcImportXml
#endif //#ifndef AcImportXml

#ifndef AcIntPtrToInt
#define AcIntPtrToInt		ZcIntPtrToInt
#endif //#ifndef AcIntPtrToInt

#ifndef AcPExCtl
#define AcPExCtl		ZcPExCtl
#endif //#ifndef AcPExCtl

#ifndef AcTc
#define AcTc		ZcTc
#endif //#ifndef AcTc

#ifndef AcTcCatalog
#define AcTcCatalog		ZcTcCatalog
#endif //#ifndef AcTcCatalog

#ifndef AcTcCatalogItem
#define AcTcCatalogItem		ZcTcCatalogItem
#endif //#ifndef AcTcCatalogItem

#ifndef AcTcCatalogItemArray
#define AcTcCatalogItemArray		ZcTcCatalogItemArray
#endif //#ifndef AcTcCatalogItemArray

#ifndef AcTcGetManager
#define AcTcGetManager		ZcTcGetManager
#endif //#ifndef AcTcGetManager

#ifndef AcTcImage
#define AcTcImage		ZcTcImage
#endif //#ifndef AcTcImage

#ifndef AcTcImageList
#define AcTcImageList		ZcTcImageList
#endif //#ifndef AcTcImageList

#ifndef AcTcManager
#define AcTcManager		ZcTcManager
#endif //#ifndef AcTcManager

#ifndef AcTcPackage
#define AcTcPackage		ZcTcPackage
#endif //#ifndef AcTcPackage

#ifndef AcTcPalette
#define AcTcPalette		ZcTcPalette
#endif //#ifndef AcTcPalette

#ifndef AcTcStockTool
#define AcTcStockTool		ZcTcStockTool
#endif //#ifndef AcTcStockTool

#ifndef AcTcTool
#define AcTcTool		ZcTcTool
#endif //#ifndef AcTcTool

#ifndef AcTcUiFilterShapesDialog
#define AcTcUiFilterShapesDialog		ZcTcUiFilterShapesDialog
#endif //#ifndef AcTcUiFilterShapesDialog

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef AcadToolImpl
#define AcadToolImpl		ZcadToolImpl
#endif //#ifndef AcadToolImpl

#ifndef AutoCAD
#define AutoCAD		ZWCAD
#endif //#ifndef AutoCAD

#ifndef CAcModuleResourceOverride
#define CAcModuleResourceOverride		CZcModuleResourceOverride
#endif //#ifndef CAcModuleResourceOverride

#ifndef CLSID_AcadAcCmColor
#define CLSID_AcadAcCmColor		CLSID_ZcadZcCmColor
#endif //#ifndef CLSID_AcadAcCmColor

#ifndef IAcadAcCmColor
#define IAcadAcCmColor		IZcadZcCmColor
#endif //#ifndef IAcadAcCmColor

#ifndef IAcadStockTool
#define IAcadStockTool		IZcadStockTool
#endif //#ifndef IAcadStockTool

#ifndef IAcadTool
#define IAcadTool		IZcadTool
#endif //#ifndef IAcadTool

#ifndef IAcadTool2
#define IAcadTool2		IZcadTool2
#endif //#ifndef IAcadTool2

#ifndef IAcadToolContextMenu
#define IAcadToolContextMenu		IZcadToolContextMenu
#endif //#ifndef IAcadToolContextMenu

#ifndef IAcadToolFlyoutShape
#define IAcadToolFlyoutShape		IZcadToolFlyoutShape
#endif //#ifndef IAcadToolFlyoutShape

#ifndef IAcadToolProperties
#define IAcadToolProperties		IZcadToolProperties
#endif //#ifndef IAcadToolProperties

#ifndef IID_IAcadAcCmColor
#define IID_IAcadAcCmColor		IID_IZcadZcCmColor
#endif //#ifndef IID_IAcadAcCmColor

#ifndef IID_IAcadStockTool
#define IID_IAcadStockTool		IID_IZcadStockTool
#endif //#ifndef IID_IAcadStockTool

#ifndef IID_IAcadTool
#define IID_IAcadTool		IID_IZcadTool
#endif //#ifndef IID_IAcadTool

#ifndef IID_IAcadToolProperties
#define IID_IAcadToolProperties		IID_IZcadToolProperties
#endif //#ifndef IID_IAcadToolProperties

#ifndef acdbHostApplicationServices
#define acdbHostApplicationServices		zcdbHostApplicationServices
#endif //#ifndef acdbHostApplicationServices

#ifndef adsw_acadDocWnd
#define adsw_acadDocWnd		zdsw_zcadDocWnd
#endif //#ifndef adsw_acadDocWnd

#ifndef mcfAutoCAD
#define mcfAutoCAD		mcfZWCAD
#endif //#ifndef mcfAutoCAD

#ifndef pAcadTool
#define pAcadTool		pZcadTool
#endif //#ifndef pAcadTool

#ifndef pAcadToolImpl
#define pAcadToolImpl		pZcadToolImpl
#endif //#ifndef pAcadToolImpl

#ifndef pIAcadAcCmColor
#define pIAcadAcCmColor		pIZcadZcCmColor
#endif //#ifndef pIAcadAcCmColor

#ifndef pIZcadAcCmColor
#define pIZcadAcCmColor		pIZcadZcCmColor
#endif //#ifndef pIZcadAcCmColor


#endif //#ifndef __ZACADTOOLIMPL_H__
