
#ifndef __DBAPSERV_H__
#define __DBAPSERV_H__

#include "adesk.h"
#include "acdb.h"
#include "acarray.h"
#include "codepgid.h"

#include "inetstrc.h"
#include "rxdlinkr.h"

#include "../inc/zdbapserv.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef ACRX_T
#define ACRX_T		ZCRX_T
#endif //#ifndef ACRX_T

#ifndef ACUTIL_API
#define ACUTIL_API		ZCUTIL_API
#endif //#ifndef ACUTIL_API

#ifndef ACUTIL_INTERNAL
#define ACUTIL_INTERNAL		ZCUTIL_INTERNAL
#endif //#ifndef ACUTIL_INTERNAL

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef kARXApplication
#define kARXApplication		kZRXApplication
#endif //#ifndef kARXApplication

#ifndef reportUnhandledArxException
#define reportUnhandledArxException		reportUnhandledZrxException
#endif //#ifndef reportUnhandledArxException

#ifndef AcDbAbstractClipBoundaryDefinition
#define AcDbAbstractClipBoundaryDefinition		ZcDbAbstractClipBoundaryDefinition
#endif //#ifndef AcDbAbstractClipBoundaryDefinition

#ifndef AcDbAppSystemVariables
#define AcDbAppSystemVariables		ZcDbAppSystemVariables
#endif //#ifndef AcDbAppSystemVariables

#ifndef AcDbAuditInfo
#define AcDbAuditInfo		ZcDbAuditInfo
#endif //#ifndef AcDbAuditInfo

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbGlobals
#define AcDbGlobals		ZcDbGlobals
#endif //#ifndef AcDbGlobals

#ifndef AcDbHostApplicationProgressMeter
#define AcDbHostApplicationProgressMeter		ZcDbHostApplicationProgressMeter
#endif //#ifndef AcDbHostApplicationProgressMeter

#ifndef AcDbHostApplicationServices
#define AcDbHostApplicationServices		ZcDbHostApplicationServices
#endif //#ifndef AcDbHostApplicationServices

#ifndef AcDbHostApplicationServices_INC
#define AcDbHostApplicationServices_INC		ZcDbHostApplicationServices_INC
#endif //#ifndef AcDbHostApplicationServices_INC

#ifndef AcDbLayoutManager
#define AcDbLayoutManager		ZcDbLayoutManager
#endif //#ifndef AcDbLayoutManager

#ifndef AcDbPasswordedFile
#define AcDbPasswordedFile		ZcDbPasswordedFile
#endif //#ifndef AcDbPasswordedFile

#ifndef AcDbPlotSettingsValidator
#define AcDbPlotSettingsValidator		ZcDbPlotSettingsValidator
#endif //#ifndef AcDbPlotSettingsValidator

#ifndef AcDbTransactionManager
#define AcDbTransactionManager		ZcDbTransactionManager
#endif //#ifndef AcDbTransactionManager

#ifndef AcDbUndoController
#define AcDbUndoController		ZcDbUndoController
#endif //#ifndef AcDbUndoController

#ifndef AcPwdCache
#define AcPwdCache		ZcPwdCache
#endif //#ifndef AcPwdCache

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef AcSDIValues
#define AcSDIValues		ZcSDIValues
#endif //#ifndef AcSDIValues

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef AcadApp
#define AcadApp		ZcadApp
#endif //#ifndef AcadApp

#ifndef AcadInet
#define AcadInet		ZcadInet
#endif //#ifndef AcadInet

#ifndef AcadInternalServices
#define AcadInternalServices		ZcadInternalServices
#endif //#ifndef AcadInternalServices

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acadInternalGetvar
#define acadInternalGetvar		zcadInternalGetvar
#endif //#ifndef acadInternalGetvar

#ifndef acadInternalServices
#define acadInternalServices		zcadInternalServices
#endif //#ifndef acadInternalServices

#ifndef acadInternalSetvar
#define acadInternalSetvar		zcadInternalSetvar
#endif //#ifndef acadInternalSetvar

#ifndef acdbHostAppMinorVersion
#define acdbHostAppMinorVersion		zcdbHostAppMinorVersion
#endif //#ifndef acdbHostAppMinorVersion

#ifndef acdbHostApplicationServices
#define acdbHostApplicationServices		zcdbHostApplicationServices
#endif //#ifndef acdbHostApplicationServices

#ifndef acdbSendInitialDwgFileOpenComplete
#define acdbSendInitialDwgFileOpenComplete		zcdbSendInitialDwgFileOpenComplete
#endif //#ifndef acdbSendInitialDwgFileOpenComplete

#ifndef acdbSetBreak3dQueueForRegen
#define acdbSetBreak3dQueueForRegen		zcdbSetBreak3dQueueForRegen
#endif //#ifndef acdbSetBreak3dQueueForRegen

#ifndef acdbSetHostApplicationServices
#define acdbSetHostApplicationServices		zcdbSetHostApplicationServices
#endif //#ifndef acdbSetHostApplicationServices

#ifndef acdbTriggerAcadOctTreeReclassification
#define acdbTriggerAcadOctTreeReclassification		zcdbTriggerZcadOctTreeReclassification
#endif //#ifndef acdbTriggerAcadOctTreeReclassification

#ifndef kProd_ACAD
#define kProd_ACAD		kProd_ZCAD
#endif //#ifndef kProd_ACAD

#ifndef kProd_AcDb
#define kProd_AcDb		kProd_ZcDb
#endif //#ifndef kProd_AcDb

#ifndef mapInetStatusToAcadStatus
#define mapInetStatusToAcadStatus		mapInetStatusToZcadStatus
#endif //#ifndef mapInetStatusToAcadStatus

#endif //#ifndef __DBAPSERV_H__
