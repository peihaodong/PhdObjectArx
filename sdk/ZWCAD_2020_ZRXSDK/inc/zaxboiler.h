

#ifndef __ZAXBOILER_H_
#define __ZAXBOILER_H_

#ifndef ZXAUTOEXP
#ifdef ZXAUTO_DLL
    #define ZXAUTOEXP __declspec(dllexport)
#else
    #define ZXAUTOEXP __declspec(dllimport)
#endif
#endif

#include "zaxobjref.h"
#include "zadesk.h"

#ifdef _ZSOFT_WINDOWS_
DEFINE_GUID(IID_IZcadBaseObject, 
0x4a54e06b, 0x820b, 0x42fc, 0xba, 0xe1, 0x91, 0x10, 0x0e, 0x6d, 0xf2, 0xad);

#undef INTERFACE
#define INTERFACE IZcadBaseObject

interface DECLSPEC_UUID("4A54E06B-820B-42FC-BAE1-91100E6DF2AD") 
IZcadBaseObject : public IUnknown
{
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(SetObjectId)(THIS_ ZcDbObjectId& objId, 
                           ZcDbObjectId ownerId = ZcDbObjectId::kNull, 
                           ZTCHAR* keyName = NULL) PURE;
    STDMETHOD(GetObjectId)(THIS_ ZcDbObjectId* objId) PURE;
    STDMETHOD(Clone)(THIS_ ZcDbObjectId ownerId, LPUNKNOWN* pUnkClone) PURE;
    STDMETHOD(GetClassID)(THIS_ CLSID& clsid) PURE;
    STDMETHOD(NullObjectId)(THIS) PURE;
    STDMETHOD(OnModified)(THIS) PURE;
};

typedef IZcadBaseObject* LPZCADBASEOBJECT;

DEFINE_GUID(IID_IZcadBaseObject2,
0xf6abc0a4, 0x748a, 0x4bc0, 0xa6, 0xb0, 0x7d, 0x25, 0xd7, 0x00, 0x13, 0x90);

interface DECLSPEC_UUID("F6ABC0A4-748A-4BC0-A6B0-7D25D7001390") 
IZcadBaseObject2 : public IUnknown       
{
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(ForceDbResident)(THIS_ VARIANT_BOOL* forceDbResident) PURE;
    STDMETHOD(AddToDb)(THIS_ ZcDbObjectId& objId, 
                       ZcDbObjectId ownerId = ZcDbObjectId::kNull,
                       ZTCHAR* keyName = NULL) PURE;
    STDMETHOD(CreateObject)(THIS_ ZcDbObjectId ownerId = ZcDbObjectId::kNull,
                            ZTCHAR* keyName = NULL) PURE;
    STDMETHOD(ObjectExists)(THIS_ VARIANT_BOOL* objectExists) PURE;
    STDMETHOD(SetObject)(THIS_ ZcDbObject*& pObj) PURE;
    STDMETHOD(GetObject)(THIS_ ZcDbObject*& pObj) PURE;
    STDMETHOD(OnModified)(THIS_ DISPID = DISPID_UNKNOWN) PURE;
};

typedef IZcadBaseObject2* LPZCADBASEOBJECT2;

DEFINE_GUID(IID_IRetrieveApplication, 
0x810d2e0f, 0xd7f9, 0x4e3a, 0x8c, 0x85, 0x60, 0x1b, 0x9a, 0x66, 0xe6, 0xa0);

interface DECLSPEC_UUID("810D2E0F-D7F9-4E3A-8C85-601B9A66E6A0") 
IRetrieveApplication : public IUnknown
{
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(SetApplicationObject)(THIS_ LPDISPATCH pAppDisp) PURE;
    STDMETHOD(GetApplicationObject)(THIS_ LPDISPATCH* pAppDisp) PURE;
};

typedef IRetrieveApplication* LPRETRIEVEAPPLICATION;

DEFINE_GUID(IID_IZcadBaseDatabase, 
0x9cc45791, 0x9df5, 0x48db, 0xb2, 0x8f, 0x12, 0xba, 0x4e, 0x50, 0x92, 0x25);

interface DECLSPEC_UUID("9CC45791-9DF5-48DB-B28F-12BA4E509225") 
IZcadBaseDatabase : public IUnknown
{
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(SetDatabase)(THIS_ ZcDbDatabase*& pDb) PURE;
    STDMETHOD(GetDatabase)(THIS_ ZcDbDatabase** pDb) PURE;
    STDMETHOD(GetClassID)(THIS_ CLSID& clsid) PURE;
};

typedef IZcadBaseDatabase* LPZCADBASEDATABASE;

DEFINE_GUID(IID_IIMetaColorSuppressor, 
0x9e2c8e3c, 0xd8a6, 0x4917, 0x81, 0xee, 0xaf, 0x88, 0x13, 0x3c, 0x1d, 0xeb);

interface DECLSPEC_UUID("9E2C8E3C-D8A6-4917-81EE-AF88133C1DEB")
IMetaColorSuppressor : public IUnknown
{
    
    STDMETHOD(GetSuppressor)(THIS_ bool* val) PURE;
    STDMETHOD(SetSuppressor)(THIS_ bool val) PURE;
};

typedef IMetaColorSuppressor* LPMETACOLORSUPPRESSOR;

DEFINE_GUID(IID_IZcadZcCmColorAccess,
0x4b363b98, 0xf861, 0x41d9, 0x9f, 0xf1, 0xa9, 0xd4, 0x7e, 0xa7, 0xca, 0x63);

#undef INTERFACE
#define INTERFACE IZcadZcCmColorAccess

interface DECLSPEC_UUID("4B363B98-F861-41D9-9FF1-A9D47EA7CA63")
IZcadZcCmColorAccess : public IUnknown
{
    
    STDMETHOD(GetZcCmColor)(THIS_ ZcCmColor* clr) PURE;
    STDMETHOD(SetZcCmColor)(THIS_ ZcCmColor* clr) PURE;
};

typedef IZcadZcCmColorAccess* LPZCADZCCMCOLORACCESS;
DEFINE_GUID(IID_IZcadBaseSubEntity,
0xb374d885, 0xeece, 0x4138, 0x8c, 0x82, 0x3f, 0xb2, 0xc, 0x53, 0x87, 0x88);

#undef INTERFACE
#define INTERFACE IZcadBaseSubEntity

interface DECLSPEC_UUID("B374D885-EECE-4138-8C82-3FB20C538788")
IZcadBaseSubEntity : public IUnknown
{

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
    STDMETHOD(OnModified)() PURE;
    STDMETHOD(SetFullSubEntPath)(THIS_ ZcDbFullSubentPath& subentPath) PURE;
    STDMETHOD(GetFullSubEntPath)(THIS_ ZcDbFullSubentPath* subentPath) PURE;
    STDMETHOD(GetClassID)(THIS_ CLSID& clsid) PURE;
};

typedef IZcadBaseSubEntity* LPZCADSUBENTITY;

HRESULT ZXAUTOEXP 
ZcAxErase(ZcDbObjectId& objId);

HRESULT ZXAUTOEXP 
ZcAxSetXData(ZcDbObjectId& objId, VARIANT type, VARIANT data);

HRESULT ZXAUTOEXP 
ZcAxGetXData(ZcDbObjectId& objId, BSTR bstrName, VARIANT* type, VARIANT* data);

HRESULT ZXAUTOEXP 
ZcAxGetObjectName(ZcDbObjectId& objId, BSTR* pName);

HRESULT ZXAUTOEXP 
ZcAxGetHandle(ZcDbObjectId& objId, BSTR* pHandle);

HRESULT ZXAUTOEXP 
ZcAxGetColor(ZcDbObjectId& objId, ZcColor* pColor);

HRESULT ZXAUTOEXP 
ZcAxPutColor(ZcDbObjectId& objId, ZcColor color);

HRESULT ZXAUTOEXP
ZcAxGetTrueColor(ZcDbObjectId& objId, IZcadZcCmColor** pColor);

HRESULT ZXAUTOEXP 
ZcAxPutTrueColor(ZcDbObjectId& objId, IZcadZcCmColor* color);

HRESULT ZXAUTOEXP 
ZcAxGetLayer(ZcDbObjectId& objId, BSTR* pLayer);

HRESULT ZXAUTOEXP 
ZcAxPutLayer(ZcDbObjectId& objId, BSTR layer);

HRESULT ZXAUTOEXP 
ZcAxGetLinetype(ZcDbObjectId& objId, BSTR* pLinetype);

HRESULT ZXAUTOEXP 
ZcAxPutLinetype(ZcDbObjectId& objId, BSTR linetype);

HRESULT ZXAUTOEXP 
ZcAxGetTransparency(ZcDbObjectId& objId, BSTR* pTransparency);

HRESULT ZXAUTOEXP 
ZcAxPutTransparency(ZcDbObjectId& objId, BSTR transparency);

HRESULT ZXAUTOEXP
ZcAxGetShadowDisplay(ZcDbObjectId& objId, ZcShadowDisplayType* pShadowDisplay);

HRESULT ZXAUTOEXP
ZcAxPutShadowDisplay(ZcDbObjectId& objId, ZcShadowDisplayType shadowDisplay);

HRESULT ZXAUTOEXP
ZcAxEnableShadowDisplay(ZcDbObjectId& objId, bool* pEnabled);

HRESULT ZXAUTOEXP
ZcAxGetMaterial(ZcDbObjectId& objId, BSTR* pMaterial);

HRESULT ZXAUTOEXP
ZcAxPutMaterial(ZcDbObjectId& objId, BSTR material);

HRESULT ZXAUTOEXP 
ZcAxGetLinetypeScale(ZcDbObjectId& objId, double* pLinetypeScale);

HRESULT ZXAUTOEXP 
ZcAxPutLinetypeScale(ZcDbObjectId& objId, double linetypeScale);

HRESULT ZXAUTOEXP 
ZcAxGetVisible(ZcDbObjectId& objId, VARIANT_BOOL* pVisible);

HRESULT ZXAUTOEXP 
ZcAxPutVisible(ZcDbObjectId& objId, VARIANT_BOOL visible);

HRESULT ZXAUTOEXP 
ZcAxArrayPolar(ZcDbObjectId& objId, LPDISPATCH pAppDisp, int numObjs, 
               double fillAngle, VARIANT basePoint, VARIANT* pArrayObjs);

HRESULT ZXAUTOEXP 
ZcAxArrayRectangular(ZcDbObjectId& objId, LPDISPATCH pAppDisp, int numRows, 
                     int numCols, int numLvls, double disRows, double disCols,
                     double disLvls, VARIANT* pArrayObjs);

HRESULT ZXAUTOEXP 
ZcAxHighlight(ZcDbObjectId& objId, VARIANT_BOOL bHighlight);

HRESULT ZXAUTOEXP 
ZcAxCopy(ZcDbObjectId& objId, LPDISPATCH pAppDisp, LPDISPATCH* pCopyObj, 
         ZcDbObjectId ownerId = ZcDbObjectId::kNull);

HRESULT ZXAUTOEXP 
ZcAxMove(ZcDbObjectId& objId, VARIANT fromPoint, VARIANT toPoint);

HRESULT ZXAUTOEXP 
ZcAxRotate(ZcDbObjectId& objId, VARIANT basePoint, double rotationAngle);

HRESULT ZXAUTOEXP 
ZcAxRotate3D(ZcDbObjectId& objId, VARIANT point1, VARIANT point2, 
             double rotationAngle);

HRESULT ZXAUTOEXP 
ZcAxMirror(ZcDbObjectId& objId, LPDISPATCH pAppDisp, VARIANT point1, 
           VARIANT point2, LPDISPATCH* pMirrorObj);

HRESULT ZXAUTOEXP 
ZcAxMirror3D(ZcDbObjectId& objId, LPDISPATCH pAppDisp, VARIANT point1, 
             VARIANT point2, VARIANT point3, LPDISPATCH* pMirrorObj);

HRESULT ZXAUTOEXP 
ZcAxScaleEntity(ZcDbObjectId& objId, VARIANT basePoint, double scaleFactor);

HRESULT ZXAUTOEXP 
ZcAxTransformBy(ZcDbObjectId& objId, VARIANT transMatrix);

HRESULT ZXAUTOEXP 
ZcAxUpdate(ZcDbObjectId& objId);

HRESULT ZXAUTOEXP 
ZcAxGetBoundingBox(ZcDbObjectId& objId, VARIANT* minPoint, VARIANT* maxPoint);

HRESULT ZXAUTOEXP 
ZcAxIntersectWith(ZcDbObjectId& objId, LPDISPATCH pEntity, 
                  ZcExtendOption option, VARIANT* intPoints);

HRESULT ZXAUTOEXP 
ZcAxGetPlotStyleName(ZcDbObjectId& objId, BSTR* plotStyleName);

HRESULT ZXAUTOEXP 
ZcAxPutPlotStyleName(ZcDbObjectId& objId, BSTR plotStyleName);

HRESULT ZXAUTOEXP 
ZcAxGetLineWeight(ZcDbObjectId& objId, ZCAD_LWEIGHT* lineWeight);

HRESULT ZXAUTOEXP 
ZcAxPutLineWeight(ZcDbObjectId& objId, ZCAD_LWEIGHT lineWeight);

HRESULT ZXAUTOEXP 
ZcAxGetHyperlinks(ZcDbObjectId& objId, LPDISPATCH pAppDisp, 
                  IZcadHyperlinks** pHyperlinks);

HRESULT ZXAUTOEXP 
ZcAxHasExtensionDictionary(ZcDbObjectId& objId, VARIANT_BOOL* bHasDictionary);

HRESULT ZXAUTOEXP 
ZcAxGetExtensionDictionary(ZcDbObjectId& objId, LPDISPATCH pAppDisp, 
                           IZcadDictionary** pExtDictionary);

HRESULT ZXAUTOEXP 
ZcAxGetDatabase(ZcDbDatabase* pDb, LPDISPATCH pAppDisp, LPDISPATCH* pDisp);

HRESULT ZXAUTOEXP
ZcAxGetOwnerId(ZcDbObjectId& objId, ZSoft::IntDbId * pOwnerId);

#if defined(_WIN64) || defined(_ZC64)
ZSoft::Int32 ZXAUTOEXP
ZcAxGetObjectId32(const ZSoft::IntDbId& objId);

ZSoft::IntDbId ZXAUTOEXP
ZcAxGetObjectId64(const ZSoft::Int32& objId);
#endif

HRESULT ZXAUTOEXP
RaiseZcAXException(REFGUID iid, HRESULT hRes, DWORD dwException, ...);

HRESULT  ZXAUTOEXP
RaiseZrxException(REFGUID iid, HRESULT hRes, Zcad::ErrorStatus es);

HRESULT ZXAUTOEXP
ZcAxGetIUnknownOfObject(LPUNKNOWN* ppUnk, ZcDbObjectId& objId, LPDISPATCH pApp);

HRESULT ZXAUTOEXP
ZcAxGetIUnknownOfObject(LPUNKNOWN* ppUnk, ZcDbObject* pObj, LPDISPATCH pApp);

HRESULT ZXAUTOEXP 
ZcAxErase(ZcAxObjectRef& objRef);

HRESULT ZXAUTOEXP 
ZcAxSetXData(ZcAxObjectRef& objRef, VARIANT type, VARIANT data);

HRESULT ZXAUTOEXP 
ZcAxGetXData(ZcAxObjectRef& objRef, BSTR bstrName, VARIANT* type, VARIANT* data);

HRESULT ZXAUTOEXP 
ZcAxGetObjectName(ZcAxObjectRef& objRef, BSTR* pName);

HRESULT ZXAUTOEXP 
ZcAxGetHandle(ZcAxObjectRef& objRef, BSTR* pHandle);

HRESULT ZXAUTOEXP 
ZcAxGetColor(ZcAxObjectRef& objRef, ZcColor* pColor);

HRESULT ZXAUTOEXP 
ZcAxPutColor(ZcAxObjectRef& objRef, ZcColor color);

HRESULT ZXAUTOEXP
ZcAxGetTrueColor(ZcAxObjectRef& objRef, IZcadZcCmColor** pColor); 
                                                                  
HRESULT ZXAUTOEXP                                                 
ZcAxPutTrueColor(ZcAxObjectRef& objRef, IZcadZcCmColor* color);   

HRESULT ZXAUTOEXP 
ZcAxGetLayer(ZcAxObjectRef& objRef, BSTR* pLayer);

HRESULT ZXAUTOEXP 
ZcAxPutLayer(ZcAxObjectRef& objRef, BSTR layer);

HRESULT ZXAUTOEXP 
ZcAxGetLinetype(ZcAxObjectRef& objRef, BSTR* pLinetype);

HRESULT ZXAUTOEXP 
ZcAxPutLinetype(ZcAxObjectRef& objRef, BSTR linetype);

HRESULT ZXAUTOEXP 
ZcAxGetMaterial(ZcAxObjectRef& objRef, BSTR* pMaterial);

HRESULT ZXAUTOEXP 
ZcAxGetTransparency(ZcAxObjectRef& objRef, BSTR* pTransparency);

HRESULT ZXAUTOEXP 
ZcAxPutTransparency(ZcAxObjectRef& objRef, BSTR transparency);


HRESULT ZXAUTOEXP
ZcAxPutMaterial(ZcAxObjectRef& objRef, BSTR material);

HRESULT ZXAUTOEXP
ZcAxGetLinetypeScale(ZcAxObjectRef& objRef, double* pLinetypeScale);

HRESULT ZXAUTOEXP 
ZcAxPutLinetypeScale(ZcAxObjectRef& objRef, double linetypeScale);

HRESULT ZXAUTOEXP
ZcAxGetShadowDisplay(ZcAxObjectRef& objRef, ZcShadowDisplayType* pShadowDisplay);

HRESULT ZXAUTOEXP
ZcAxPutShadowDisplay(ZcAxObjectRef& objRef, ZcShadowDisplayType shadowDisplay);

HRESULT ZXAUTOEXP
ZcAxEnableShadowDisplay(ZcAxObjectRef& objRef, bool* pEnabled);

HRESULT ZXAUTOEXP 
ZcAxGetVisible(ZcAxObjectRef& objRef, VARIANT_BOOL* pVisible);

HRESULT ZXAUTOEXP 
ZcAxPutVisible(ZcAxObjectRef& objRef, VARIANT_BOOL visible);

HRESULT ZXAUTOEXP 
ZcAxArrayPolar(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, int numObjs, 
               double fillAngle, VARIANT basePoint, VARIANT* pArrayObjs);

HRESULT ZXAUTOEXP 
ZcAxArrayRectangular(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, int numRows, 
                     int numCols, int numLvls, double disRows, double disCols,
                     double disLvls, VARIANT* pArrayObjs);

HRESULT ZXAUTOEXP 
ZcAxHighlight(ZcAxObjectRef& objRef, VARIANT_BOOL bHighlight);

HRESULT ZXAUTOEXP 
ZcAxCopy(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, LPDISPATCH* pCopyObj, 
         ZcDbObjectId ownerId = ZcDbObjectId::kNull);
HRESULT ZXAUTOEXP 
ZcAxMove(ZcAxObjectRef& objRef, VARIANT fromPoint, VARIANT toPoint);

HRESULT ZXAUTOEXP 
ZcAxRotate(ZcAxObjectRef& objRef, VARIANT basePoint, double rotationAngle);

HRESULT ZXAUTOEXP 
ZcAxRotate3D(ZcAxObjectRef& objRef, VARIANT point1, VARIANT point2, 
             double rotationAngle);

HRESULT ZXAUTOEXP 
ZcAxMirror(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, VARIANT point1, 
           VARIANT point2, LPDISPATCH* pMirrorObj);

HRESULT ZXAUTOEXP 
ZcAxMirror3D(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, VARIANT point1, 
             VARIANT point2, VARIANT point3, LPDISPATCH* pMirrorObj);

HRESULT ZXAUTOEXP 
ZcAxScaleEntity(ZcAxObjectRef& objRef, VARIANT basePoint, double scaleFactor);

HRESULT ZXAUTOEXP 
ZcAxTransformBy(ZcAxObjectRef& objRef, VARIANT transMatrix);

HRESULT ZXAUTOEXP 
ZcAxUpdate(ZcAxObjectRef& objRef);

HRESULT ZXAUTOEXP 
ZcAxGetBoundingBox(ZcAxObjectRef& objRef, VARIANT* minPoint, VARIANT* maxPoint);

HRESULT ZXAUTOEXP 
ZcAxIntersectWith(ZcAxObjectRef& objRef, LPDISPATCH pEntity, 
                  ZcExtendOption option, VARIANT* intPoints);

HRESULT ZXAUTOEXP 
ZcAxGetPlotStyleName(ZcAxObjectRef& objRef, BSTR* plotStyleName);

HRESULT ZXAUTOEXP 
ZcAxPutPlotStyleName(ZcAxObjectRef& objRef, BSTR plotStyleName);

HRESULT ZXAUTOEXP 
ZcAxGetLineWeight(ZcAxObjectRef& objRef, ZCAD_LWEIGHT* lineWeight);

HRESULT ZXAUTOEXP 
ZcAxPutLineWeight(ZcAxObjectRef& objRef, ZCAD_LWEIGHT lineWeight);

HRESULT ZXAUTOEXP 
ZcAxGetHyperlinks(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, 
                  IZcadHyperlinks** pHyperlinks);

HRESULT ZXAUTOEXP 
ZcAxHasExtensionDictionary(ZcAxObjectRef& objRef, VARIANT_BOOL* bHasDictionary);

HRESULT ZXAUTOEXP 
ZcAxGetExtensionDictionary(ZcAxObjectRef& objRef, LPDISPATCH pAppDisp, 
                           IZcadDictionary** pExtDictionary);
HRESULT ZXAUTOEXP
ZcAxGetOwnerId(ZcAxObjectRef& objRef, ZSoft::IntDbId * pOwnerId);
#endif

#endif
