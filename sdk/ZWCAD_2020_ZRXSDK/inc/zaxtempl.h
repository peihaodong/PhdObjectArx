

#ifndef __ZAXTEMPL_H_
#define __ZAXTEMPL_H_

#include "zadesk.h"
#include "zaxobjref.h"
#include "zaxboiler.h"
#include "zoleaprot.h"

#include "zopmext.h"
#include "zopmimp.h"
#include "zdbobjptr.h"
#include "zrxregsvc.h"
#pragma pack (push, 8)

#pragma warning (disable : 4786)
interface IZcadShadowDisplay;

#define ZCAX_VARIANT_TRUE (VARIANT_BOOL) -1
#define ZCAX_VARIANT_FALSE (VARIANT_BOOL) 0

template<class T>
class ATL_NO_VTABLE IOPMPropertyExtensionImpl : 
    public ICategorizeProperties, 
    public IPerPropertyBrowsing, 
    public IOPMPropertyExtension
{
public:
    IOPMPropertyExtensionImpl()
    {
    }

    virtual ~IOPMPropertyExtensionImpl()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;

    STDMETHODIMP MapPropertyToCategory(DISPID dispid, PROPCAT* ppropcat)
    {
        return ZcOpmMapPropertyToCategory(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispid, ppropcat);
    }

    STDMETHODIMP GetCategoryName(PROPCAT propcat, LCID lcid, BSTR* pbstrName)
    {
       return ZcOpmGetCategoryName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), propcat, lcid, pbstrName);
    }

    STDMETHODIMP GetDisplayString(DISPID dispID, BSTR *pBstr)
    {
        return ZcOpmGetDisplayString(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, pBstr);
    }
    
    STDMETHODIMP MapPropertyToPage(DISPID dispID, CLSID *pClsid)
    {
        return ZcOpmMapPropertyToPage(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, pClsid);
    }

    STDMETHODIMP GetPredefinedStrings(DISPID dispID, CALPOLESTR *pCaStringsOut, CADWORD *pCaCookiesOut)
    {
        return ZcOpmGetPredefinedStrings(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), dispID, pCaStringsOut, pCaCookiesOut);
    }

    STDMETHODIMP GetPredefinedValue(DISPID dispID, DWORD dwCookie, VARIANT *pVarOut)
    {
        return ZcOpmGetPredefinedValue(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, dwCookie, pVarOut);
    }

    STDMETHODIMP GetDisplayName(
        DISPID dispID, 
        BSTR *pBstr)
    {
        return ZcOpmGetDisplayName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), dispID, pBstr);
    }

    STDMETHODIMP Editable(
         DISPID dispID,
         BOOL __RPC_FAR *bEditable)
    {
        return ZcOpmEditable(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, bEditable);
    }

    STDMETHODIMP ShowProperty(
         DISPID dispID,
         BOOL *pShow)
    {
        return ZcOpmShowProperty(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, pShow);
    }
};

template <class T>
class CProxy_ZcadObjectEvents : 
    public IConnectionPointImpl<T, &IID_IZcadObjectEvents, CComDynamicUnkArray>
{
public:
	virtual ~CProxy_ZcadObjectEvents()
	{
	}
    void Fire_Modified()
    {
        T* pT = static_cast<T*>(this);
        CComPtr<IZcadObject> pZcadObject;
        pT->QueryInterface(__uuidof(IZcadObject),(void**)&pZcadObject);
        pT->Lock();
        IUnknown** pp = m_vec.begin();
        while (pp < m_vec.end())
        {
            if (*pp != NULL)
            {
                IZcadObjectEvents* pZcadObjectEvents = reinterpret_cast<IZcadObjectEvents*>(*pp);
                _ASSERTE(pZcadObjectEvents != NULL);

                pZcadObjectEvents->Modified(pZcadObject);
            }
            pp++;
        }
        pT->Unlock();
    }
};

template <class T>
class CProxy_PropertyNotifySink : 
    public IConnectionPointImpl<T, &IID_IPropertyNotifySink, CComDynamicUnkArray>
{
public:
	virtual ~CProxy_PropertyNotifySink()
	{
	}
    void Fire_OnChanged()
    {
        Fire_OnChanged(DISPID_UNKNOWN);
    }

    void Fire_OnChanged(DISPID dispId)
    {
        T* pT = static_cast<T*>(this);
        pT->Lock();
        IUnknown** pp = m_vec.begin();
        while (pp < m_vec.end())
        {
            IPropertyNotifySink* pNotifySink = reinterpret_cast<IPropertyNotifySink*>(*pp);
            if(pNotifySink) 
                pNotifySink->OnChanged(dispId);
            pp++;
        }
        pT->Unlock();
    }
};

template <class T, const CLSID* pclsid>
class ATL_NO_VTABLE IZcadBaseObjectImpl : 
    public IZcadBaseObject,
    public IConnectionPointContainerImpl<T>,
    public CProxy_ZcadObjectEvents<T>,
    public CProxy_PropertyNotifySink<T>
{
public:
    IZcadBaseObjectImpl()
    {
    }

    virtual ~IZcadBaseObjectImpl()
    {

        if (!m_objId.isValid())
            return;

        ZcDbObjectPointer<ZcDbObject> pObject(m_objId, ZcDb::kForRead, ZSoft::kTrue);
        if(pObject.openStatus() != Zcad::eOk)
        {

            ZcDbObject* pTemp;
            if (Zcad::eOk != zcdbOpenObject(pTemp,m_objId,ZcDb::kForNotify,ZSoft::kTrue))
            {
                return; 
            }
            pObject.acquire(pTemp);
        }

        ZcAxOleLinkManager* pOleLinkManager = ZcAxGetOleLinkManager();
        _ASSERTE(pOleLinkManager != NULL);

        pOleLinkManager->SetIUnknown(pObject.object(), NULL);
    }

    virtual HRESULT CreateNewObject(ZcDbObjectId& objId,
                                ZcDbObjectId& ownerId, ZTCHAR* keyName) = 0;

    STDMETHOD(SetObjectId)(ZcDbObjectId& objId,
                    ZcDbObjectId ownerId = ZcDbObjectId::kNull,
                    ZTCHAR* keyName = NULL)
    {

        if (!m_objId.isNull())
            return E_FAIL;
        
        if(objId == ZcDbObjectId::kNull) 
        {
            HRESULT hr;
            if(FAILED(hr = CreateNewObject(objId, ownerId, keyName)))
                return hr;
        }

        m_objId = objId;
        _ASSERTE(m_objId != ZcDbObjectId::kNull);
        ObjectIdModified();

        return S_OK;
    }

    STDMETHOD(GetObjectId)(ZcDbObjectId* objId)
    {
        *objId = m_objId;
        return S_OK;
    }

    STDMETHOD(Clone)(ZcDbObjectId , LPUNKNOWN* )
    {
        return E_NOTIMPL;
    }
    
    STDMETHOD(GetClassID)(CLSID& clsid) 
    {
        clsid = *pclsid;
        return S_OK;
    }
    
    STDMETHOD(NullObjectId)(void)
    {
        m_objId = ZcDbObjectId::kNull;
        ObjectIdModified();
        return S_OK;
    }

    STDMETHOD(OnModified)(void)
    {
        Fire_Modified();
        Fire_OnChanged();
        return S_OK;
    }

BEGIN_CONNECTION_POINT_MAP(T)
    CONNECTION_POINT_ENTRY(IID_IZcadObjectEvents)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
END_CONNECTION_POINT_MAP()

protected:
    ZcDbObjectId m_objId;

    virtual void ObjectIdModified()
    {};
};

#pragma warning(push)
#pragma warning(disable : 4100) 
template <class T, const CLSID* pclsid>
class ATL_NO_VTABLE IZcadBaseObject2Impl :
    public IZcadBaseObject2,
    public IZcadBaseObjectImpl<T, pclsid>
{
public:
    IZcadBaseObject2Impl()
    {
    };

    virtual ~IZcadBaseObject2Impl()
    {
    };

    STDMETHOD(SetObject)(ZcDbObject*& pObj)
    {
        if (pObj->objectId().isNull()) 
        {
            NullObjectId();
            m_objRef.acquire(pObj);
            return S_OK;
        }
        else
        {
            ZcDbObjectId tmpId = pObj->objectId();
            return SetObjectId(tmpId);
        }
    }

    STDMETHOD(GetObject)(ZcDbObject*& pObj)
    {
        pObj = NULL;
        if (!m_objRef.objectId().isNull())
            return E_FAIL;

        ZcDbObjectId tmpId;
        m_objRef.release(tmpId, pObj);
        _ASSERTE(m_objId.isNull());
        _ASSERTE(tmpId.isNull());
        return S_OK;
    }

    STDMETHOD(ForceDbResident)(VARIANT_BOOL *forceDbResident) 
    {
        if (NULL == forceDbResident)
            return E_POINTER;
        
        *forceDbResident = ZCAX_VARIANT_TRUE;
        return S_OK;
    }
    STDMETHOD(AddToDb)(ZcDbObjectId& objId,
                       ZcDbObjectId ownerId = ZcDbObjectId::kNull,
                       ZTCHAR* keyName = NULL)
    {
        return E_NOTIMPL;
    }
    STDMETHOD(CreateObject)(ZcDbObjectId ownerId = ZcDbObjectId::kNull,
                            ZTCHAR *keyName = NULL)
    {

        return E_NOTIMPL;
    }

    STDMETHOD(ObjectExists)(VARIANT_BOOL *objectExists)
    {
        if (NULL == objectExists)
            return E_POINTER;
        
        *objectExists = m_objRef.isNull() ? ZCAX_VARIANT_FALSE : ZCAX_VARIANT_TRUE;
        return S_OK;
    }

    STDMETHOD(OnModified)(DISPID dispId = DISPID_UNKNOWN)
    {
        Fire_Modified();
        Fire_OnChanged(dispId);
        return S_OK;
    }

protected:
    ZcAxObjectRef m_objRef;

    virtual void ObjectIdModified()
    {
        releaseReference();
        m_objRef.acquire(m_objId);        
    }

    void Fire_Notification(DISPID dispId = DISPID_UNKNOWN) 
    {
        if (m_objRef.objectId().isNull())
        {
            Fire_Modified();
            Fire_OnChanged(dispId);
        }
    }

    STDMETHOD(releaseReference)()
    {
        ZcDbObjectId tmpId;
        ZcDbObject*  pTmp = NULL;
        m_objRef.release(tmpId, pTmp);
        if (NULL != pTmp && pTmp->objectId().isNull())
            delete pTmp;   
        return S_OK;
    }
};
#pragma warning(pop)

class ATL_NO_VTABLE IRetrieveApplicationImpl : 
    public IRetrieveApplication
{
public:
    IRetrieveApplicationImpl()
    {
        m_App = NULL;
    }

    virtual ~IRetrieveApplicationImpl()
    {
        if(m_App != NULL)
            m_App->Release();
    }
    
    STDMETHOD(SetApplicationObject)(LPDISPATCH pApp)
    {
        if(m_App != NULL)
            return E_FAIL;
        m_App = pApp;

        if(m_App != NULL)
            m_App->AddRef();

        return S_OK;
    }

    STDMETHOD(GetApplicationObject)(LPDISPATCH* pApp)
    {
        *pApp = m_App;
        if(m_App == NULL)
            return E_FAIL;

        m_App->AddRef();
        return S_OK;
    }

protected:
    LPDISPATCH m_App;
};

template <class C, const CLSID* pclsid, class T, const IID* piid, const GUID* plibid, 
WORD wMajor = 1, WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
class ATL_NO_VTABLE IZcadObjectDispatchImpl : 
    public IDispatchImpl<T, piid, plibid, wMajor, wMinor, tihclass>,
    public IZcadBaseObject2Impl<C, pclsid>,
    public IRetrieveApplicationImpl
{
public:
    
    IZcadObjectDispatchImpl()
    {

		_tih.EnsureTI(zcrxProductLCID());
    }

    virtual ~IZcadObjectDispatchImpl()
    {
    }

    STDMETHOD(get_Application)(LPDISPATCH* pVal)
    {
        return GetApplicationObject(pVal);
    }

    STDMETHOD(get_ObjectID)(ZSoft::IntDbId *pVal)
    {
        *pVal = m_objRef.objectId().asOldId();
        return S_OK;
    }

    STDMETHOD(get_OwnerID)(ZSoft::IntDbId *pVal)
    {
        return ZcAxGetOwnerId(m_objRef, pVal);
    }

    STDMETHOD(Delete)()
    {
        return ZcAxErase(m_objRef);
    }

    STDMETHOD(SetXData)(VARIANT type, VARIANT data)
    {
        return ZcAxSetXData(m_objRef, type, data);
    }

    STDMETHOD(GetXData)(BSTR bstrName, VARIANT* type, VARIANT* data)
    {
        return ZcAxGetXData(m_objRef, bstrName, type, data);
    }

    STDMETHOD(get_ObjectName)(BSTR *pVal)
    {
        return ZcAxGetObjectName(m_objRef, pVal);
    }

    STDMETHOD(get_Handle)(BSTR *pVal)
    {
        return ZcAxGetHandle(m_objRef, pVal);
    }

    STDMETHOD(get_HasExtensionDictionary)(VARIANT_BOOL* bHasDictionary)
    {
        return ZcAxHasExtensionDictionary(m_objRef, bHasDictionary);
    }

    STDMETHOD(GetExtensionDictionary)(IZcadDictionary** pExtDictionary)
    {
        return ZcAxGetExtensionDictionary(m_objRef, m_App, pExtDictionary);
    }

    STDMETHOD(get_Database)(IZcadDatabase** pDatabase)
    {
        if(m_objRef.objectId() == ZcDbObjectId::kNull ||
           m_objRef.objectId().database() == NULL)
        {
            return RaiseZrxException(*piid, 0, Zcad::eNoDatabase);
        }

        CComPtr<IDispatch> pDispatch;
        HRESULT hr = ZcAxGetDatabase(m_objRef.objectId().database(), m_App, &pDispatch);

        if(SUCCEEDED(hr))
        {
            hr = pDispatch->QueryInterface(IID_IZcadDatabase,
                 reinterpret_cast<LPVOID*>(pDatabase));
        }

        return hr;
    }

    STDMETHOD(get_Document)(LPDISPATCH* pDocument)
    {
        if(m_objRef.objectId() == ZcDbObjectId::kNull ||
           m_objRef.objectId().database() == NULL)
        {
            return RaiseZrxException(*piid, 0, Zcad::eNoDatabase);
        }

        ZcAxOleLinkManager* pOleLinkManager = ZcAxGetOleLinkManager();
        _ASSERTE(pOleLinkManager != NULL);

        *pDocument = pOleLinkManager->GetDocIDispatch(m_objRef.objectId().database());
        if(*pDocument == NULL)
        {
            return RaiseZrxException(*piid, 0, Zcad::eNoDocument);
        }

        (*pDocument)->AddRef();

        return S_OK;
    }

    STDMETHOD(Erase)()
    {
        return Delete();
    }
	STDMETHOD(Invoke)(DISPID dispidMember, REFIID riid,	LCID lcid, WORD wFlags, DISPPARAMS* pdispparams, VARIANT* pvarResult, EXCEPINFO* pexcepinfo, UINT* puArgErr)
	{
		HRESULT hr =  _tih.Invoke((IDispatch*)this, dispidMember, riid, lcid, 
			wFlags, pdispparams, pvarResult, pexcepinfo, puArgErr);
		if (hr == DISP_E_MEMBERNOTFOUND && wFlags == DISPATCH_PROPERTYPUTREF)
		{
			HRESULT hr2 =  _tih.Invoke((IDispatch*)this, dispidMember, riid, 
				lcid,DISPATCH_PROPERTYPUT, pdispparams, pvarResult, pexcepinfo, puArgErr);
			if (SUCCEEDED(hr2))
				return hr2;
		}
		return hr;
	}
};

template <class C, const CLSID* pclsid, class T, const IID* piid, const GUID* plibid, 
WORD wMajor = 1, WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
class ATL_NO_VTABLE IZcadEntityDispatchImpl : 
    public IZcadObjectDispatchImpl<C, pclsid, T, piid, plibid, wMajor, wMinor, tihclass>
{
public:
    
    STDMETHODIMP get_Color(ZcColor* pVal)
    {
        return ZcAxGetColor(m_objRef, pVal);
    }

    STDMETHODIMP put_Color(ZcColor newVal)
    {
        return ZcAxPutColor(m_objRef, newVal);
    }

    STDMETHODIMP get_TrueColor(IZcadZcCmColor** pColor)
    {
        return ZcAxGetTrueColor(m_objRef, pColor);
    }

    STDMETHODIMP put_TrueColor(IZcadZcCmColor* color)
    {
        return ZcAxPutTrueColor(m_objRef, color);
    }

    STDMETHODIMP get_Layer(BSTR * pVal)
    {
        return ZcAxGetLayer(m_objRef, pVal);
    }

    STDMETHODIMP put_Layer(BSTR newVal)
    {
        return ZcAxPutLayer(m_objRef, newVal);
    }

    STDMETHODIMP get_Linetype(BSTR * pVal)
    {
        return ZcAxGetLinetype(m_objRef, pVal);
    }

    STDMETHODIMP put_Linetype(BSTR newVal)
    {
        return ZcAxPutLinetype(m_objRef, newVal);
    }

    STDMETHODIMP get_Material(BSTR * pVal)
    {
        return ZcAxGetMaterial(m_objRef, pVal);
    }

    STDMETHODIMP put_Material(BSTR newVal)
    {
        return ZcAxPutMaterial(m_objRef, newVal);
    }

    STDMETHODIMP get_LinetypeScale(double * pVal)
    {
        return ZcAxGetLinetypeScale(m_objRef, pVal);
    }

    STDMETHODIMP put_LinetypeScale(double newVal)
    {
        return ZcAxPutLinetypeScale(m_objRef, newVal);
    }

    STDMETHODIMP get_Visible(VARIANT_BOOL * pVal)
    {
        return ZcAxGetVisible(m_objRef, pVal);
    }

    STDMETHODIMP put_Visible(VARIANT_BOOL newVal)
    {
        return ZcAxPutVisible(m_objRef, newVal);
    }

    STDMETHODIMP ArrayPolar(int numObjs, double fillAngle, VARIANT basePoint, VARIANT * pArrayObjs)
    {
        return ZcAxArrayPolar(m_objRef, m_App, numObjs, fillAngle, basePoint, pArrayObjs);
    }

    STDMETHODIMP ArrayRectangular(int numRows, int numCols, int numLvls, double disRows, double disCols, double disLvls, VARIANT * pArrayObjs)
    {
        return ZcAxArrayRectangular(m_objRef, m_App, numRows, numCols, numLvls, disRows, disCols, disLvls, pArrayObjs);
    }

    STDMETHODIMP Highlight(VARIANT_BOOL bFlag)
    {
        return ZcAxHighlight(m_objRef, bFlag);
    }

    STDMETHODIMP Copy(LPDISPATCH * pCopyObj)
    {
        return ZcAxCopy(m_objRef, m_App, pCopyObj);
    }

    STDMETHODIMP Move(VARIANT fromPoint, VARIANT toPoint)
    {
        return ZcAxMove(m_objRef, fromPoint, toPoint);
    }

    STDMETHODIMP Rotate(VARIANT basePoint, double rotationAngle)
    {
        return ZcAxRotate(m_objRef, basePoint, rotationAngle);
    }

    STDMETHODIMP Rotate3D(VARIANT point1, VARIANT point2, double rotationAngle)
    {
        return ZcAxRotate3D(m_objRef, point1, point2, rotationAngle);
    }

    STDMETHODIMP Mirror(VARIANT point1, VARIANT point2, LPDISPATCH * pMirrorObj)
    {
        return ZcAxMirror(m_objRef, m_App, point1, point2, pMirrorObj);
    }

    STDMETHODIMP Mirror3D(VARIANT point1, VARIANT point2, VARIANT point3, LPDISPATCH * pMirrorObj)
    {
        return ZcAxMirror3D(m_objRef, m_App, point1, point2, point3, pMirrorObj);
    }

    STDMETHODIMP ScaleEntity(VARIANT basePoint, double scaleFactor)
    {
        return ZcAxScaleEntity(m_objRef, basePoint, scaleFactor);
    }

    STDMETHODIMP TransformBy(VARIANT transMatrix)
    {
        return ZcAxTransformBy(m_objRef, transMatrix);
    }

    STDMETHODIMP Update()
    {
        return ZcAxUpdate(m_objRef);
    }

    STDMETHODIMP GetBoundingBox(VARIANT * minPoint, VARIANT * maxPoint)
    {
        return ZcAxGetBoundingBox(m_objRef, minPoint, maxPoint);
    }

    STDMETHODIMP IntersectWith(LPDISPATCH pEntity, ZcExtendOption option, VARIANT * intPoints)
    {
        return ZcAxIntersectWith(m_objRef, pEntity, option, intPoints);
    }

    STDMETHODIMP get_PlotStyleName(BSTR* plotStyleName)
    {
        return ZcAxGetPlotStyleName(m_objRef, plotStyleName);
    }

    STDMETHODIMP put_PlotStyleName(BSTR plotStyleName)
    {
        return ZcAxPutPlotStyleName(m_objRef, plotStyleName);
    }

    STDMETHODIMP get_Lineweight(ZCAD_LWEIGHT* lineweight)
    {
        return ZcAxGetLineWeight(m_objRef, lineweight);
    }

    STDMETHODIMP put_Lineweight(ZCAD_LWEIGHT lineweight)
    {
        return ZcAxPutLineWeight(m_objRef, lineweight);
    }

    STDMETHODIMP get_Hyperlinks(IZcadHyperlinks** pHyperlinks)
    {
        return ZcAxGetHyperlinks(m_objRef, m_App, pHyperlinks);
    }

	STDMETHODIMP get_EntityTransparency(BSTR * pVal)
	{
		return ZcAxGetTransparency(m_objRef, pVal);
	}

	STDMETHODIMP put_EntityTransparency(BSTR newVal)
	{
		return ZcAxPutTransparency(m_objRef, newVal);
	}

    STDMETHOD(get_EntityName)(BSTR *pVal)
    {
        return ZcAxGetObjectName(m_objRef, pVal);
    }

    STDMETHOD(get_EntityType)(long* )
    {
        return E_NOTIMPL;
    }
};

template <const CLSID* pclsid>
class ATL_NO_VTABLE IZcadBaseDatabaseImpl : 
    public IZcadBaseDatabase
{
public:
    IZcadBaseDatabaseImpl()
    {
        m_Database = NULL;
    }

    STDMETHOD(SetDatabase)(ZcDbDatabase*& pDb)
    {
        m_Database = pDb;
        return S_OK;
    }

    STDMETHOD(GetDatabase)(ZcDbDatabase** pDb)
    {
        if(pDb == NULL)
            return E_POINTER;

        *pDb = m_Database;
        return S_OK;
    }

    STDMETHOD(GetClassID)(CLSID& clsid) 
    {
        clsid = *pclsid;
        return S_OK;
    }

protected:
    ZcDbDatabase* m_Database;
};

template <class C, const CLSID* pclsid, class T, const IID* piid,
    const GUID* plibid,
    WORD wMajor = 1, WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
class ATL_NO_VTABLE IZcadBaseSubEntityImpl :
    public IDispatchImpl<T, piid, plibid, wMajor, wMinor, tihclass>,
    public IZcadBaseSubEntity,
    public IRetrieveApplicationImpl,
    public IConnectionPointContainerImpl<C>,
    public CProxy_ZcadObjectEvents<C>,
    public CProxy_PropertyNotifySink<C>
{
public:
    IZcadBaseSubEntityImpl()
    {
    }
    virtual ~IZcadBaseSubEntityImpl()
    {

        if (!m_objId.isValid())
            return;

        ZcDbObjectPointer<ZcDbObject> pObject(m_objId, ZcDb::kForRead,
            ZSoft::kTrue);
        if (pObject.openStatus() != Zcad::eOk) {

            ZcDbObject* pTemp;
            if (Zcad::eOk != zcdbOpenObject(pTemp, m_objId, ZcDb::kForNotify,
                ZSoft::kTrue))
            {
                return;
            }
            pObject.acquire(pTemp);
        }
        ZcAxOleLinkManager* pOleLinkManager = ZcAxGetOleLinkManager();
        _ASSERTE(pOleLinkManager != NULL);

        pOleLinkManager->SetIUnknown(pObject.object(), m_subentPath.subentId(),
            NULL);
    }

    STDMETHOD(OnModified)()
    {
        Fire_Modified();
        Fire_OnChanged();
        return S_OK;
    }

    STDMETHOD(SetFullSubEntPath)(ZcDbFullSubentPath& subentPath)
    {
        m_subentPath = subentPath;
        ZcDbObjectIdArray objectIds = m_subentPath.objectIds();
        if (0 != objectIds.length())
            m_objId = objectIds[objectIds.length() - 1];
        return S_OK;
    }

    STDMETHOD(GetFullSubEntPath)(ZcDbFullSubentPath* subentPath)
    {
        *subentPath = m_subentPath;
        return S_OK;
    }

    STDMETHOD(GetClassID)(CLSID& clsid)
    {
        clsid = *pclsid;
        return S_OK;
    }

    STDMETHOD(get_ObjectName)(BSTR *pVal)
    {
        return ZcAxGetObjectName(m_objId, pVal);
    }

    STDMETHODIMP get_Color(IZcadZcCmColor** pColor)
    {
        return ZcAxGetTrueColor(m_objId, pColor);
    }
    STDMETHODIMP get_Layer(BSTR * pVal)
    {
        return ZcAxGetLayer(m_objId, pVal);
    }
    STDMETHODIMP get_Linetype(BSTR * pVal)
    {
        return ZcAxGetLinetype(m_objId, pVal);
    }
    STDMETHODIMP get_LinetypeScale(double * pVal)
    {
        return ZcAxGetLinetypeScale(m_objId, pVal);
    }
    STDMETHODIMP get_PlotStyleName(BSTR* plotStyleName)
    {
        return ZcAxGetPlotStyleName(m_objId, plotStyleName);
    }
    STDMETHODIMP get_Lineweight(ZCAD_LWEIGHT* lineweight)
    {
        return ZcAxGetLineWeight(m_objId, lineweight);
    }
    STDMETHODIMP get_Hyperlinks(IZcadHyperlinks** pHyperlinks)
    {
        return ZcAxGetHyperlinks(m_objId, m_App, pHyperlinks);
    }

BEGIN_CONNECTION_POINT_MAP(C)
    CONNECTION_POINT_ENTRY(IID_IZcadObjectEvents)
    CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
END_CONNECTION_POINT_MAP()

protected:
    STDMETHODIMP parentObjectId(ZcDbObjectId &objID)
    {
        ZcDbObjectIdArray objectIds = m_subentPath.objectIds();
        if (0 != objectIds.length()) {
            objID = objectIds[objectIds.length() - 1];
            return S_OK;
        }
        return E_FAIL;
    }
    ZcDbFullSubentPath m_subentPath;
    ZcDbObjectId m_objId;
};

#define IPropCommandButtonsImpl IZcPiPropCommandButtonsImpl
template<class T>
class ATL_NO_VTABLE IZcPiPropCommandButtonsImpl : 
    public IZcPiPropCommandButtons 
{
public:
    CMDBTN_VECTOR m_CmdBtnVector;

    CMDBTN_VECTOR & GetCmdBtnVector() 
    {
        return m_CmdBtnVector;
    }

    bool IsDefaultCmdBtnEntry(CMDBTN_ENTRY in)
    {
        if(in.m_lpEnBtnBmpRes != NULL)
            return false;

        if(in.m_nEnBtnBmpType != PICTYPE_UNINITIALIZED)
            return false;

        if(in.m_lpDisBtnBmpRes != NULL)
            return false;

        if(in.m_nDisBtnBmpType != PICTYPE_UNINITIALIZED)
            return false;

        if(in.m_pfnBtnProc != NULL)
            return false;

        if(in.m_nBtnNameId != NULL)
            return false;

        if(in.m_nStyle != NULL)
            return false;

        return true;
    }

    IZcPiPropCommandButtonsImpl()
    {
        m_CmdBtnVector.clear();
        int i=0;
        while(!IsDefaultCmdBtnEntry(T::GetPropCmdBtnArray()[i]))
        {
            m_CmdBtnVector.push_back(T::GetPropCmdBtnArray()[i]);
            i++;
        }
    }

    virtual ~IZcPiPropCommandButtonsImpl()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;

    STDMETHODIMP GetButtons(VARIANT *pCmdBtns)
    {
       return ZcOpmGetCommandButtons(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetCmdBtnVector(), pCmdBtns);
    }
};

#define IPerPropertyDisplayImpl IZcPiPropertyDisplayImpl
template<class T>
class ATL_NO_VTABLE IZcPiPropertyDisplayImpl : 
    public IZcPiPropertyDisplay
{
public:
    PROP_DISP_VECTOR m_PropDispVector;

    PROP_DISP_VECTOR & GetPerPropDisplayVector() 
    {
        return m_PropDispVector;
    }
    bool IsDefaultPerPropDispEntry(PER_PROP_DISP_ENTRY in)
    {
        if(in.m_bFullView != false)
            return false;

        if(in.m_ProgID != NULL)
            return false;

        if(in.m_dispid != -1)
            return false;

        if(in.m_dwIntegralHeight != -1)
            return false;

        if(in.m_lpEllipsisBmpRes != NULL)
            return false;

        if(in.m_nEllipsisBmpType != PICTYPE_UNINITIALIZED)
            return false;

        if(in.m_lpLeftIconRes != NULL)
            return false;

        if(in.m_nLeftIconType != PICTYPE_UNINITIALIZED)
            return false;

        if(in.m_nWeight != -1)
            return false;

        if(in.m_TextColor != 0x80000008)
            return false;

        return true;
    }
    
    IZcPiPropertyDisplayImpl()
    {
        m_PropDispVector.clear();
        int i=0;
        while(!IsDefaultPerPropDispEntry(T::GetPerPropDisplayArray()[i]))
        {
            m_PropDispVector.push_back(T::GetPerPropDisplayArray()[i]);
            i++;
        }
    }

    virtual ~IZcPiPropertyDisplayImpl()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;

    STDMETHODIMP GetCustomPropertyCtrl(VARIANT Id, LCID lcid, BSTR *psProgId)
    {
        return ZcOpmGetCustomPropertyCtrl(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(), Id, lcid, psProgId);
    }

    STDMETHODIMP GetPropertyIcon(VARIANT Id, IUnknown **ppIcon)
    {
        return ZcOpmGetPropertyIcon(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetPerPropDisplayVector(), Id, ppIcon);
    }

    STDMETHODIMP GetPropTextColor(VARIANT Id, OLE_COLOR *pTextColor)
    {
        return ZcOpmGetPropTextColor(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(), Id, pTextColor);
    }

    STDMETHODIMP IsFullView(VARIANT Id, VARIANT_BOOL *pbVisible, DWORD *pIntegralHeight)
    {
        return ZcOpmIsPropFullView(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(), Id, pbVisible, pIntegralHeight);
    }

    STDMETHODIMP GetPropertyWeight(VARIANT Id, long *pPropertyWeight)
    {
        return ZcOpmGetPropertyWeight(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(), Id, pPropertyWeight);
    }
};

#define ICategorizeProperties2Impl IZcPiCategorizePropertiesImpl 
template<class T>
class ATL_NO_VTABLE IZcPiCategorizePropertiesImpl : 
    public IZcPiCategorizeProperties 
{
public:
    CATEGORY_VECTOR  m_CategoryVector;
    CATCMDBTN_VECTOR m_CatCmdBtnVector;

    CATEGORY_VECTOR & GetCategoryVector() 
    {
        return m_CategoryVector;
    }

    CATCMDBTN_VECTOR & GetCmdBtnVector() 
    {
        return m_CatCmdBtnVector;
    }

    bool IsDefaultCategoryEntry(CATEGORY_ENTRY in)
    {
        if(in.m_CatID != -1)
            return false;

        if(in.m_nWeight != -1)
            return false;

        if(in.m_ParentCatID != -1)
            return false;

        if(in.m_nDescId != 0)
            return false;

        if(in.m_nNameId != 0)
            return false;

        return true;
    }

    bool IsDefaultCmdBtnEntry(CATCMDBTN_ENTRY in)
    {
        if(in.m_CatID != -1)
            return false;

        if(in.m_lpEnBtnBmpRes != NULL)
            return false;

        if(in.m_nEnBtnBmpType != PICTYPE_UNINITIALIZED)
            return false;

        if(in.m_lpDisBtnBmpRes != NULL)
            return false;

        if(in.m_nDisBtnBmpType != PICTYPE_UNINITIALIZED)
            return false;

        if(in.m_nStyle != NULL)
            return false;

        if(in.m_pfnBtnProc != NULL)
            return false;

        if(in.m_nBtnNameId != 0)
            return false;

        return true;
    }

    IZcPiCategorizePropertiesImpl()
    {
        m_CatCmdBtnVector.clear();
        m_CategoryVector.clear();
        int i=0;
        while(!IsDefaultCmdBtnEntry(T::GetCmdBtnArray()[i]))
        {
            m_CatCmdBtnVector.push_back(T::GetCmdBtnArray()[i]);
            i++;
        }

        i=0;
        while(!IsDefaultCategoryEntry(T::GetCatArray()[i]))
        {
            m_CategoryVector.push_back(T::GetCatArray()[i]);
            i++;
        }
    }

    virtual ~IZcPiCategorizePropertiesImpl()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;

    STDMETHODIMP MapPropertyToCategory(DISPID dispid, PROPCAT* ppropcat)
    {
        return ZcOpmMapPropertyToCategory(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispid, ppropcat);
    }

    STDMETHODIMP GetCategoryName(PROPCAT propcat, LCID lcid, BSTR* pbstrName)
    {
       HRESULT hr;
       hr = ZcOpmGetCategoryName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), propcat, lcid, pbstrName);
       if(hr == S_FALSE) {
           hr = ZcOpmGetCategoryName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetCategoryVector(), propcat, lcid, pbstrName);
       }
       return hr;
    }

    STDMETHODIMP GetCategoryDescription(PROPCAT propcat, LCID lcid, BSTR* pbstrDesc)
    {
       return ZcOpmGetCategoryDescription(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetCategoryVector(), propcat, lcid, pbstrDesc);
    }

    STDMETHODIMP GetCategoryWeight(PROPCAT CatID, long *pCategoryWeight)
    {
       return ZcOpmGetCategoryWeight(reinterpret_cast<IUnknown*>(this), GetCategoryVector(), CatID, pCategoryWeight);
    }

    STDMETHODIMP GetParentCategory(PROPCAT CatID, PROPCAT *pParentCatID)
    {
       return ZcOpmGetParentCategory(reinterpret_cast<IUnknown*>(this), GetCategoryVector(), CatID, pParentCatID);
    }

    STDMETHODIMP GetCommandButtons(PROPCAT CatID, VARIANT *pCatCmdBtns)
    {
       return ZcOpmGetCategoryCommandButtons(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetCmdBtnVector(), CatID, pCatCmdBtns);
    }
};

template<class T>
class ATL_NO_VTABLE IOPMPropertyExtensionImpl2 : 
    public IPerPropertyBrowsing, 
    public IOPMPropertyExtension
{
public:
    IOPMPropertyExtensionImpl2()
    {
    }

    virtual ~IOPMPropertyExtensionImpl2()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;

    STDMETHODIMP GetDisplayString(DISPID dispID, BSTR *pBstr)
    {
        return ZcOpmGetDisplayString(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, pBstr);
    }
    
    STDMETHODIMP MapPropertyToPage(DISPID dispID, CLSID *pClsid)
    {
        return ZcOpmMapPropertyToPage(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, pClsid);
    }

    STDMETHODIMP GetPredefinedStrings(DISPID dispID, CALPOLESTR *pCaStringsOut, CADWORD *pCaCookiesOut)
    {
        return ZcOpmGetPredefinedStrings(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), dispID, pCaStringsOut, pCaCookiesOut);
    }

    STDMETHODIMP GetPredefinedValue(DISPID dispID, DWORD dwCookie, VARIANT *pVarOut)
    {
        return ZcOpmGetPredefinedValue(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, dwCookie, pVarOut);
    }

    STDMETHODIMP GetDisplayName(
        DISPID dispID, 
        BSTR *pBstr)
    {
        return ZcOpmGetDisplayName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), dispID, pBstr);
    }

    STDMETHODIMP Editable(
         DISPID dispID,
         BOOL __RPC_FAR *bEditable)
    {
        return ZcOpmEditable(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, bEditable);
    }

    STDMETHODIMP ShowProperty(
         DISPID dispID,
         BOOL *pShow)
    {
        return ZcOpmShowProperty(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), dispID, pShow);
    }
};

template <class C>
class ATL_NO_VTABLE IZcadShadowDisplayImpl :  public IZcadShadowDisplay
{
public:

    STDMETHODIMP get_ShadowDisplay(ZcShadowDisplayType* pShadowDisplay)
    {
        CComPtr<IZcadBaseObject> pZcadBaseObject;
        HRESULT hr = QueryInterface(IID_IZcadBaseObject, (LPVOID*) &pZcadBaseObject);
        if(FAILED(hr))
            return S_FALSE;

        ZcDbObjectId objId;
        pZcadBaseObject->GetObjectId(&objId);
        return ZcAxGetShadowDisplay(objId, pShadowDisplay);
    }

    STDMETHODIMP put_ShadowDisplay(ZcShadowDisplayType shadowDisplay)
    {
        CComPtr<IZcadBaseObject> pZcadBaseObject;
        HRESULT hr = QueryInterface(IID_IZcadBaseObject, (LPVOID*) &pZcadBaseObject);
        if(FAILED(hr))
            return S_FALSE;

        ZcDbObjectId objId;
        pZcadBaseObject->GetObjectId(&objId);
        return ZcAxPutShadowDisplay(objId, shadowDisplay);
    }

    STDMETHODIMP get_EnableShadowDisplay(BOOL* bEnabled)
    {
        *bEnabled = TRUE;

        return S_OK;
    }
};
#pragma pack (pop)
#endif
