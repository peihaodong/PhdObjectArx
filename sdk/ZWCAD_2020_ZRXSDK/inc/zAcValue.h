

#pragma once

#include "zadesk.h"
#include "zAdAChar.h"

class ZcDbEvalVariant;
typedef struct tagVARIANT VARIANT;
typedef struct _SYSTEMTIME SYSTEMTIME;
class ZcDbObjectId;
class ZcGePoint2d;
class ZcGePoint3d;
class ZcCmColor;
struct resbuf;
class ZcDbDwgFiler;
class ZcDbDxfFiler;
#if __LP64__
typedef unsigned int DWORD;
#else
typedef unsigned long       DWORD;
#endif

class ZcValue : public ZcRxObject
{
public:
    enum DataType
    {
        kUnknown            = 0,
        kLong               = (0x1 << 0),
        kDouble             = (0x1 << 1),
        kString             = (0x1 << 2),
        kDate               = (0x1 << 3),
        kPoint              = (0x1 << 4),
        k3dPoint            = (0x1 << 5),
        kObjectId           = (0x1 << 6),
        kBuffer             = (0x1 << 7),
        kResbuf             = (0x1 << 8),
        kGeneral            = (0x1 << 9),
        kColor              = (0x1 << 10),
    };

    enum UnitType
    {
        kUnitless           = 0,
        kDistance           = (0x1 << 0),
        kAngle              = (0x1 << 1),
        kArea               = (0x1 << 2),
        kVolume             = (0x1 << 3),
        kCurrency           = (0x1 << 4),
        kPercentage         = (0x1 << 5),
    };

    enum ParseOption
    {
        kParseOptionNone        = 0,
        kSetDefaultFormat       = (0x1 << 0),
        kPreserveMtextFormat    = (0x1 << 1),
        kConvertTextToValue     = (0x1 << 2),
        kChangeDataType         = (0x1 << 3),
        kParseTextForFieldCode  = (0x1 << 4),
    };

    enum FormatOption
    {
        kFormatOptionNone       = 0,
        kForEditing             = (0x1 << 0),
        kForExpression          = (0x1 << 1),
        kUseMaximumPrecision    = (0x1 << 2),
        kIgnoreMtextFormat      = (0x1 << 3),
    };

public:
    static bool     isValidDataType         (const VARIANT& var);

public:
    ZCRX_DECLARE_MEMBERS(ZcValue);
    
    ZCDB_PORT ZcValue(void);
    ZCDB_PORT ZcValue(ZcValue::DataType nDataType);
    ZCDB_PORT ZcValue(const ZcValue& value);
    ZCDB_PORT ZcValue(const ZTCHAR * pszValue);
    ZCDB_PORT ZcValue(ZSoft::Int32 lValue);
    ZCDB_PORT ZcValue(double fValue);
    ZCDB_PORT ZcValue(const __time64_t& date);
    ZCDB_PORT ZcValue(const SYSTEMTIME& date);
    ZCDB_PORT ZcValue(const ZcGePoint2d& pt);
    ZCDB_PORT ZcValue(double x, double y);
    ZCDB_PORT ZcValue(const ZcGePoint3d& pt);
    ZCDB_PORT ZcValue(double x, double y, double z);
    ZCDB_PORT ZcValue(const ZcDbObjectId& id);
    ZCDB_PORT ZcValue(const resbuf& rb);
    ZCDB_PORT ZcValue(const ZcDbEvalVariant& evalVar);
    ZCDB_PORT ZcValue(const VARIANT& var);
    ZCDB_PORT ZcValue(const ZcCmColor& var);
    ZCDB_PORT ZcValue(const void* pBuf, DWORD dwBufSize);

    ZCDB_PORT ~ZcValue(void);

    ZCDB_PORT bool  reset                   (void);
    ZCDB_PORT bool  reset                   (ZcValue::DataType nDataType);
    ZCDB_PORT bool  resetValue              (void);
    ZCDB_PORT ZcValue::DataType dataType     (void) const;
    ZCDB_PORT ZcValue::UnitType unitType     (void) const;
    ZCDB_PORT bool  setUnitType             (ZcValue::UnitType nUnitType);
    ZCDB_PORT const ZTCHAR* getFormat        (void) const;
    ZCDB_PORT bool  setFormat               (const ZTCHAR* pszFormat);

    ZCDB_PORT bool  isValid                 (void) const;

    ZCDB_PORT       operator const ZTCHAR *  (void) const;
    ZCDB_PORT       operator ZSoft::Int32           (void) const;
    ZCDB_PORT       operator double         (void) const;
    ZCDB_PORT       operator __time64_t     (void) const;
    ZCDB_PORT       operator ZcGePoint2d    (void) const;
    ZCDB_PORT       operator ZcGePoint3d    (void) const;
    ZCDB_PORT       operator ZcDbObjectId   (void) const;

    ZCDB_PORT ZcValue& operator=            (const ZcValue& value);
    ZCDB_PORT ZcValue& operator=            (const ZTCHAR * pszValue);
    ZCDB_PORT ZcValue& operator=            (ZSoft::Int32 lValue);
    ZCDB_PORT ZcValue& operator=            (double fValue);
    ZCDB_PORT ZcValue& operator=            (__time64_t date);
    ZCDB_PORT ZcValue& operator=            (const ZcGePoint2d& pt);
    ZCDB_PORT ZcValue& operator=            (const ZcGePoint3d& pt);
    ZCDB_PORT ZcValue& operator=            (const ZcDbObjectId& objId);
    ZCDB_PORT ZcValue& operator=            (const resbuf& rb);
    ZCDB_PORT ZcValue& operator=            (const ZcDbEvalVariant& evalVar);
    ZCDB_PORT ZcValue& operator=            (const VARIANT& var);
    ZCDB_PORT ZcValue& operator=            (const ZcCmColor& clr);
    ZCDB_PORT bool  operator==              (const ZcValue& val) const;
    ZCDB_PORT bool  operator!=              (const ZcValue& val) const;

    ZSoft::Boolean  isEqualTo               (const ZcRxObject* pOther) const;

    ZCDB_PORT bool  get                     (const ZTCHAR *& pszValue) const;
    ZCDB_PORT bool  get                     (ZTCHAR *& pszValue) const;
    ZCDB_PORT bool  get                     (ZSoft::Int32& lValue) const;
    ZCDB_PORT bool  get                     (double& fValue) const;
    ZCDB_PORT bool  get                     (__time64_t& date) const;
    ZCDB_PORT bool  get                     (SYSTEMTIME& date) const;
    ZCDB_PORT bool  get                     (ZcGePoint2d& pt) const;
    ZCDB_PORT bool  get                     (double& x,
                                             double& y) const;
    ZCDB_PORT bool  get                     (ZcGePoint3d& pt) const;
    ZCDB_PORT bool  get                     (double& x,
                                             double& y,
                                             double& z) const;
    ZCDB_PORT bool  get                     (ZcDbObjectId& objId) const;
    ZCDB_PORT bool  get                     (resbuf** pRb) const;
    ZCDB_PORT bool  get                     (ZcDbEvalVariant& evalVar) const;
    ZCDB_PORT bool  get                     (VARIANT& var) const;
    ZCDB_PORT bool  get                     (ZcCmColor& clr) const;
    ZCDB_PORT bool  get                     (void*& pBuf,
                                             DWORD& dwBufSize) const;

    ZCDB_PORT bool  set                     (const ZcValue& value);
    ZCDB_PORT bool  set                     (const ZTCHAR* pszValue);
    ZCDB_PORT bool  set                     (ZcValue::DataType nDataType,
                                             const ZTCHAR* pszValue);
    ZCDB_PORT bool  set                     (ZSoft::Int32 lValue);
    ZCDB_PORT bool  set                     (double fValue);
    ZCDB_PORT bool  set                     (const __time64_t& date);
    ZCDB_PORT bool  set                     (const SYSTEMTIME& date);
    ZCDB_PORT bool  set                     (const ZcGePoint2d& pt);
    ZCDB_PORT bool  set                     (double x,
                                             double y);
    ZCDB_PORT bool  set                     (const ZcGePoint3d& pt);
    ZCDB_PORT bool  set                     (double x,
                                             double y,
                                             double z);
    ZCDB_PORT bool  set                     (const ZcDbObjectId& objId);
    ZCDB_PORT bool  set                     (const resbuf& rb);
    ZCDB_PORT bool  set                     (const ZcDbEvalVariant& evalVar);
    ZCDB_PORT bool  set                     (const VARIANT& var);
    ZCDB_PORT bool  set                     (const ZcCmColor& clr);
    ZCDB_PORT bool  set                     (const void* pBuf,
                                             DWORD dwBufSize);

    ZCDB_PORT bool  parse                   (const ZTCHAR* pszText,
                                             ZcValue::DataType nDataType,
                                             ZcValue::UnitType nUnitType,
                                             const ZTCHAR* pszFormat,
                                             ZcValue::ParseOption nOption,
                                             const ZcDbObjectId* pTextStyleId);

    ZCDB_PORT const ZTCHAR* format           (void) const;
    ZCDB_PORT ZcString format               (const ZTCHAR* pszFormat) const;
    ZCDB_PORT bool  format                  (ZTCHAR*& pszValue) const;
    ZCDB_PORT bool  format                  (const ZTCHAR* pszFormat,
                                             ZTCHAR*& pszValue) const;
    ZCDB_PORT ZcString format               (ZcValue::FormatOption nOption);
    ZCDB_PORT ZcString format               (const ZTCHAR* pszFormat,
                                             ZcValue::FormatOption nOption);

    ZCDB_PORT bool  convertTo               (ZcValue::DataType nDataType,
                                             ZcValue::UnitType nUnitType);
    ZCDB_PORT bool  convertTo               (ZcValue::DataType nDataType,
                                             ZcValue::UnitType nUnitType,
                                             bool bResetIfIncompatible);
    Zcad::ErrorStatus dwgInFields           (ZcDbDwgFiler* pFiler);
    Zcad::ErrorStatus dwgOutFields          (ZcDbDwgFiler* pFiler) const;
    Zcad::ErrorStatus dxfInFields           (ZcDbDxfFiler* pFiler);
    Zcad::ErrorStatus dxfOutFields          (ZcDbDxfFiler* pFiler) const;

protected:
    void        *   mpImpObj;

private:
    friend class ZcSystemInternals;
};

typedef ZcArray<ZcValue, ZcArrayObjectCopyReallocator<ZcValue> > ZcValueArray;
