

#ifndef _ZDYNPROPS_H
#define _ZDYNPROPS_H

#include "zadesk.h"
#include "zAdAChar.h"

#ifdef _ZSOFT_WINDOWS_
#define S_NOTIFYCMD MAKE_HRESULT(0,0,0x02)

interface IPropertyManager;
interface IDynamicProperty;
interface IPropertyManager2;
interface IDynamicProperty2;
interface IPropertySource;

class OPMPerInstancePropertySources : public ZcRxObject  
{
public:
    ZCRX_DECLARE_MEMBERS(OPMPerInstancePropertySources);
    virtual ~OPMPerInstancePropertySources(){}

    virtual bool SetPropertySourceAt(const BSTR* pName, IPropertySource* pSource) = 0;

    virtual IPropertySource* GetPropertySourceAt(const BSTR* pName) = 0;
    
    virtual bool RemovePropertySourceAt(const BSTR* pName) = 0;

    virtual bool GetPropertySourceNames(VARIANT* pNames) = 0;
    
};

class OPMPerInstancePropertyExtension : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(OPMPerInstancePropertyExtension);
    virtual ~OPMPerInstancePropertyExtension() {};
    
    virtual bool AddObjectPropertySourceName(const BSTR* pName) = 0;
    
    virtual bool RemoveObjectPropertySourceName(const BSTR* pName) = 0;

    virtual bool GetObjectPropertySourceNames(VARIANT* pNames) = 0;
};

class OPMPerInstancePropertyExtensionFactory : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(OPMPerInstancePropertyExtensionFactory);
    virtual ~OPMPerInstancePropertyExtensionFactory(){};

    virtual OPMPerInstancePropertyExtension* CreateOPMPerInstancePropertyExtension(ZcRxClass* pClass) = 0;
};

#define GET_OPM_PERINSTANCE_CREATE_PROTOCOL() \
OPMPerInstancePropertyExtensionFactory::cast(ZcDbDatabase::desc()->queryX(OPMPerInstancePropertyExtensionFactory::desc()))

#define GET_OPM_PERINSTANCE_PROPERTY_SOURCES() \
OPMPerInstancePropertySources::cast(ZcDbDatabase::desc()->queryX(OPMPerInstancePropertySources::desc()))

#define GET_OPM_PERINSTANCE_EXTENSION_PROTOCOL(pZcRxClass) \
GET_OPM_PERINSTANCE_CREATE_PROTOCOL()->CreateOPMPerInstancePropertyExtension(pZcRxClass)

class OPMPropertyExtension : public ZcRxObject  
{
public:
    ZCRX_DECLARE_MEMBERS(OPMPropertyExtension);
    virtual ~OPMPropertyExtension(){}

    virtual IPropertyManager* GetPropertyManager() = 0;
    
    virtual void SetPropertyManager(IPropertyManager* pPropManager) = 0;
};

class OPMPropertyExtensionFactory: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(OPMPropertyExtensionFactory);
    virtual ~OPMPropertyExtensionFactory(){}

    virtual OPMPropertyExtension* CreateOPMObjectProtocol(ZcRxClass* pClass, 
                                                             LONG lReserved = 0) = 0;
    
    virtual OPMPropertyExtension* CreateOPMCommandProtocol(const ZTCHAR * pGlobalCommand,
                                                             LONG lReserved = 0) = 0;

    virtual BOOL GetOPMManager(const ZTCHAR * pGlobalCommand, IPropertyManager** pManager) = 0;

    virtual BOOL GetPropertyCount(ZcRxClass* pClass, LONG* pPropCount) = 0;

    virtual LONG GetPropertyClassArray(ZcRxClass* pClass, 
                                       IDynamicProperty**  pPropertyArray) = 0;

    virtual BOOL GetPropertyCountEx(ZcRxClass* pClass, LONG* pPropCount) = 0;

    virtual LONG GetPropertyClassArray(ZcRxClass* pClass, 
                                       IUnknown**  pPropertyArray) = 0; 
};

#define GET_OPMEXTENSION_CREATE_PROTOCOL() \
OPMPropertyExtensionFactory::cast(ZcDbDatabase::desc()->queryX(OPMPropertyExtensionFactory::desc()))

#define GET_OPMPROPERTY_MANAGER(pZcRxClass) \
GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMObjectProtocol(pZcRxClass)->GetPropertyManager() 

#define GET_OPM_COMMAND_PROPERTY_MANAGER(pCommandName) \
GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMCommandProtocol(pCommandName)->GetPropertyManager() 

typedef BOOL (*OPMDIALOGPROC)(void);

const int MAX_OPMSTRLEN = 256;

DEFINE_GUID(IID_IDynamicPropertyNotify, 0x70c4624a, 0x0c5e, 0x4241, 0x9a, 0xac, 0xce, 0x26, 0x11, 0x18, 0xc5, 0x2c);

interface DECLSPEC_UUID("70C4624A-0C5E-4241-9AAC-CE261118C52C")
IDynamicPropertyNotify : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(OnChanged)(THIS_ IDynamicProperty* pDynamicProperty) PURE;

    STDMETHOD(GetCurrentSelectionSet)(THIS_ VARIANT* pSelection) PURE;
};

typedef IDynamicPropertyNotify FAR* LPDYNAMICPROPERTYNOTIFY;

DEFINE_GUID(IID_IDynamicPropertyNotify2, 0x2ca92ac3, 0x6af3, 0x4a48, 0xa1, 0xe3, 0x8b, 0x95, 0xa7, 0xf1, 0x53, 0xcc);

interface DECLSPEC_UUID("2CA92AC3-6AF3-4A48-A1E3-8B95A7F153CC")
IDynamicPropertyNotify2 : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(OnChanged)(THIS_ IUnknown* pDynamicProperty) PURE;

    STDMETHOD(GetCurrentSelectionSet)(THIS_ VARIANT* pSelection) PURE;
};

typedef IDynamicPropertyNotify2 FAR* LPDYNAMICPROPERTYNOTIFY2;

DEFINE_GUID(IID_IDynamicProperty, 0xb8dbe00a, 0xa0a9, 0x4882, 0x9f, 0xe0, 0x9f, 0x4e, 0xdc, 0x3d, 0x93, 0x5f);

interface DECLSPEC_UUID("B8DBE00A-A0A9-4882-9FE0-9F4EDC3D935F")
IDynamicProperty : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(GetGUID)(THIS_ GUID* propGUID) PURE;
    
    STDMETHOD(GetDisplayName)(THIS_ BSTR* bstrName) PURE;
    
    STDMETHOD(IsPropertyEnabled)(THIS_ LONG_PTR objectID,
                                      BOOL* pbEnabled) PURE;
    
    STDMETHOD(IsPropertyReadOnly)(THIS_ BOOL* pbReadonly) PURE;
    
    STDMETHOD(GetDescription)(THIS_ BSTR* bstrName) PURE;

    STDMETHOD(GetCurrentValueName)(THIS_ BSTR* pbstrName) PURE;
    
    STDMETHOD(GetCurrentValueType)(THIS_ VARTYPE* pVarType) PURE;

    STDMETHOD(GetCurrentValueData)(THIS_ LONG_PTR objectID,
                                      VARIANT* pvarData) PURE;

    STDMETHOD(SetCurrentValueData)(THIS_ LONG_PTR objectID,
                                         const VARIANT varData) PURE;

    STDMETHOD(Connect)(THIS_ IDynamicPropertyNotify* pSink) PURE;
    STDMETHOD(Disconnect)(THIS_ ) PURE;
};

typedef IDynamicProperty FAR* LPDYNAMICPROPERTY;

DEFINE_GUID(IID_IDynamicProperty2, 0x5ac6977f, 0x5fcf, 0x4295, 0x93, 0xf7, 0x93, 0x42, 0x23, 0x52, 0xab, 0x9d);

interface DECLSPEC_UUID("5AC6977F-5FCF-4295-93F7-93422352AB9D")
IDynamicProperty2 : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(GetGUID)(THIS_ GUID* propGUID) PURE;
    
    STDMETHOD(GetDisplayName)(THIS_ BSTR* bstrName) PURE;
    
    STDMETHOD(IsPropertyEnabled)(THIS_ IUnknown *pUnk,
                                      BOOL* pbEnabled) PURE;
    
    STDMETHOD(IsPropertyReadOnly)(THIS_ BOOL* pbReadonly) PURE;
    
    STDMETHOD(GetDescription)(THIS_ BSTR* bstrName) PURE;

    STDMETHOD(GetCurrentValueName)(THIS_ BSTR* pbstrName) PURE;
    
    STDMETHOD(GetCurrentValueType)(THIS_ VARTYPE* pVarType) PURE;

    STDMETHOD(GetCurrentValueData)(THIS_ IUnknown *pUnk, 
                                      VARIANT* pvarData) PURE;

    STDMETHOD(SetCurrentValueData)(THIS_ IUnknown *pUnk, 
                                         const VARIANT varData) PURE;

    STDMETHOD(Connect)(THIS_ IDynamicPropertyNotify2* pSink) PURE;
    STDMETHOD(Disconnect)(THIS_ ) PURE;
};

typedef IDynamicProperty2 FAR* LPDYNAMICPROPERTY2;

const int DISPID_DYNAMIC = -23; 

DEFINE_GUID(IID_IDynamicEnumProperty, 0xb1887ce8, 0x1127, 0x42c6, 0x9f, 0xd1, 0xa5, 0x50, 0x07, 0x24, 0xd7, 0x51);

interface DECLSPEC_UUID("B1887CE8-1127-42C6-9FD1-A5500724D751")
IDynamicEnumProperty : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(GetNumPropertyValues)(THIS_ LONG* numValues) PURE;
    
    STDMETHOD(GetPropValueName)(THIS_ LONG index, 
                                   BSTR* valueName) PURE;
    
    STDMETHOD(GetPropValueData)(THIS_ LONG index, 
                                   VARIANT* valueName) PURE;
};

typedef IDynamicEnumProperty FAR* LPDYNAMICENUMPROPERTY;

DEFINE_GUID(IID_IDynamicDialogProperty, 0x38e4a655, 0x1518, 0x4135, 0x93, 0x28, 0x57, 0xd2, 0x58, 0x47, 0x0a, 0x43);

interface DECLSPEC_UUID("38E4A655-1518-4135-9328-57D258470A43")
IDynamicDialogProperty : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(GetCustomDialogProc)(THIS_ OPMDIALOGPROC* pDialogProc) PURE;
    
    STDMETHOD(GetMacroName)(THIS_ BSTR* bstrName) PURE;

};

typedef IDynamicDialogProperty FAR* LPDYNAMICDIALOGPROPERTY;

DEFINE_GUID(IID_IPropertyManager, 0xb8dbe00a, 0xa0a9, 0x4882, 0x9f, 0xe0, 0x9f, 0x4e, 0xdc, 0x3d, 0x93, 0x5f);

interface DECLSPEC_UUID("B8DBE00A-A0A9-4882-9FE0-9F4EDC3D935F")
IPropertyManager : public IUnknown
{
    BEGIN_INTERFACE
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(AddProperty)(THIS_ IDynamicProperty FAR* pProperty) PURE;
    STDMETHOD(RemoveProperty)(THIS_ IDynamicProperty FAR* pProperty) PURE;
    STDMETHOD(GetDynamicProperty)(THIS_ LONG index,
                                     IDynamicProperty ** pProperty) PURE;
    STDMETHOD(GetDynamicPropertyByName)(THIS_ BSTR propName,
                                           IDynamicProperty ** pProperty) PURE;
    STDMETHOD(GetDynamicPropertyCount)(THIS_ LONG* count) PURE;
    
    STDMETHOD(GetDynamicClassInfo)(THIS_ IUnknown* pObj,
                                        ITypeInfo** pptiDynamic,
                                        DWORD* dwCookie) PURE;
};

typedef IPropertyManager FAR* LPPROPERTYMANAGER;

DEFINE_GUID(IID_IPropertyManager2, 0xf6bb2e86, 0xa442, 0x40f5, 0x97, 0x47, 0x75, 0x1d, 0xbd, 0x6d, 0x81, 0x45);

interface DECLSPEC_UUID("F6BB2E86-A442-40F5-9747-751DBD6D8145")
IPropertyManager2 : public IUnknown
{
    BEGIN_INTERFACE
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(AddProperty)(THIS_ IUnknown FAR* pDynPropObj) PURE;
    STDMETHOD(RemoveProperty)(THIS_ IUnknown FAR* pDynPropObj) PURE;
    STDMETHOD(GetDynamicProperty)(THIS_ LONG index,
                                     IUnknown ** pDynPropObj) PURE;
    STDMETHOD(GetDynamicPropertyByName)(THIS_ BSTR propName,
                                           IUnknown ** pDynPropObj) PURE;
    STDMETHOD(GetDynamicPropertyCountEx)(THIS_ LONG* count) PURE;
    
    STDMETHOD(GetDynamicClassInfo)(THIS_ IUnknown* pObj,
                                        ITypeInfo** pptiDynamic,
                                        DWORD* dwCookie) PURE;
};

typedef IPropertyManager2 FAR* LPPROPERTYMANAGER2;

DEFINE_GUID(IID_IPropertySource, 0x284905ca, 0x17b8, 0x42c6, 0x8c, 0xee, 0xd8, 0xea, 0xd4, 0xdb, 0x59, 0xac);

interface DECLSPEC_UUID("284905CA-17B8-42C6-8CEE-D8EAD4DB59AC")
IPropertySource : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    STDMETHOD(get_Name)(THIS_ BSTR* pName) PURE;

    STDMETHOD(GetProperties)(THIS_ IUnknown* pObject, VARIANT *pPropertyArray) PURE;
};

typedef IPropertySource FAR* LPPROPERTYSOURCE;
#endif
#endif 
