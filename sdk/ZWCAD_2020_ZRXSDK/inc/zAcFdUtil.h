
#pragma once

#include "zadesk.h"
#include "zAdAChar.h"
#include "zAcCell.h"

#ifdef _ZSOFT_WINDOWS_
interface IZcSmDatabase;
interface IZcSmSheetSet;
interface IZcSmComponent;
struct ZcHyperlink;
#endif

#ifdef  ZCFD_API
#  define   ZCFD_PORT  __declspec(dllexport)
#else
#  define   ZCFD_PORT  
#endif

typedef ZSoft::UInt32 ZcDbEvalNodeId;

namespace ZcFdEval
{

    enum ObjectFieldOption
    {
        kObjFieldNone                   = 0,
        kObjFieldUnresolvedBlockRef     = (0x1 << 0),
        kObjFieldApplyBlockTransform    = (0x1 << 1),
        kObjFieldUnresolvedObjectRef    = (0x1 << 2),
    };

    enum SheetSetFieldOption
    {
        kSheetSetNone                   = 0,
        kSheetSetHyperlink              = (0x1 << 0),
        kSheetSetUnresolvedComponent    = (0x1 << 1),
    };

    enum ExpressionFieldOption
    {

        kExprFieldNone                  = 0,
        kExprFieldSum                   = (0x1 << 0),
        kExprFieldAverage               = (0x1 << 1),
        kExprFieldCount                 = (0x1 << 2),
        kExprFieldCell                  = (0x1 << 3),
        kExprFieldEquation              = (0x1 << 4),
    };
};

#ifdef _ZSOFT_WINDOWS_
ZCFD_PORT BOOL   ZcFdMakeFieldCode  (const ZcDbObjectId& objId,
                                     ZcDbEvalNodeId blockParamId,
                                     const ZTCHAR * pszPropOrCoectionName,
                                     ZcFdEval::ObjectFieldOption nOption,
                                     const ZTCHAR * pszFormat,
                                     ZcHyperlink* pHyperlink,
                                     ZTCHAR*& pszFieldCode);

ZCFD_PORT BOOL   ZcFdMakeFieldCode  (IZcSmDatabase* pSmDb,
                                     IZcSmSheetSet* pSmSheetSet,
                                     IZcSmComponent* pSmComp,
                                     const ZTCHAR * pszCompName,
                                     const ZTCHAR * pszPropName,
                                     ZcFdEval::SheetSetFieldOption nOption,
                                     const ZTCHAR * pszFormat,
                                     ZTCHAR*& pszFieldCode);

ZCFD_PORT BOOL   ZcFdMakeFieldCode  (const ZcDbObjectId& tableId,
                                     const ZcDbObjectId& targetTableId,
                                     ZcFdEval::ExpressionFieldOption nOption,
                                     const ZcCellRangeArray& cellRanges,
                                     const ZTCHAR * pszFormat,
                                     ZcHyperlink* pHyperlink,
                                     ZTCHAR*& pszFieldCode);

ZCFD_PORT BOOL   ZcFdExtractData    (ZcDbField* pField,
                                     ZTCHAR *& pszSheetSetFile,
                                     ZTCHAR *& pszSheetSetId,
                                     ZTCHAR *& pszCompName,
                                     ZTCHAR *& pszCompId,
                                     ZTCHAR *& pszPropName);

ZCFD_PORT BOOL   ZcFdExtractData    (ZcDbField* pField,
                                     ZcDbObjectId& objId,
									 ZTCHAR *& pszPropName);
#endif

