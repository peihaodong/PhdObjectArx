// SignEntity.h : Declaration of the CSignEntity

#pragma once
#include "resource.h"       // main symbols

#include "axtempl.h"

#include "SignDbCom_h.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CSignEntity

class ATL_NO_VTABLE CSignEntity :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSignEntity, &CLSID_SignEntity>,
	public ISupportErrorInfo,
    public IAcadEntityDispatchImpl<CSignEntity, &CLSID_SignEntity, ISignEntity, &IID_ISignEntity, &LIBID_SignDbCom>,
    public IOPMPropertyExtensionImpl<CSignEntity>,
    public IOPMPropertyExpander,
	public IPerPropertyDisplay
{
public:
	CSignEntity()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SIGNENTITY)


BEGIN_COM_MAP(CSignEntity)
	COM_INTERFACE_ENTRY(ISignEntity)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IAcadBaseObject)
	COM_INTERFACE_ENTRY(IAcadObject)
	COM_INTERFACE_ENTRY(IAcadEntity)
    COM_INTERFACE_ENTRY(IRetrieveApplication)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
    COM_INTERFACE_ENTRY(IOPMPropertyExtension)
    COM_INTERFACE_ENTRY(ICategorizeProperties)
	COM_INTERFACE_ENTRY(IPerPropertyDisplay)
    COM_INTERFACE_ENTRY(IOPMPropertyExpander)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	/////////////////////////////////////////////////////////////////
	// ISignEntity
	STDMETHOD(get_Normal)(VARIANT* pVal);
	STDMETHOD(put_Normal)(VARIANT newVal);
	STDMETHOD(get_Center)(VARIANT* pVal);
	STDMETHOD(put_Center)(VARIANT newVal);
	STDMETHOD(get_Radius)(DOUBLE* pVal);
	STDMETHOD(put_Radius)(DOUBLE newVal);
	STDMETHOD(get_TextTrueColor)(IAcadAcCmColor** pVal);
	STDMETHOD(put_TextTrueColor)(IAcadAcCmColor* newVal);
	STDMETHOD(get_Text)(BSTR* pVal);
	STDMETHOD(put_Text)(BSTR newVal);

	/////////////////////////////////////////////////////////////////
	// IAcadBaseObjectImpl
    virtual HRESULT CreateNewObject(AcDbObjectId& objId, AcDbObjectId& ownerId, TCHAR* keyName);

	/////////////////////////////////////////////////////////////////
	// IOPMPropertyExtensionImpl

    virtual HINSTANCE GetResourceInstance();
	
	/////////////////////////////////////////////////////////////////
	// IOPMPropertyExtension

	BEGIN_OPMPROP_MAP()
		OPMPROP_ENTRY(0, 0x00000001, 1, 0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, 0x00000002, 1, 0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, 0x00000003, 1, 0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, 0x00000004, 2, 0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
		OPMPROP_ENTRY(0, 0x00000005, 2, 0, 0, 0, _T(""), 0, 1, IID_NULL, IID_NULL, "")
	END_OPMPROP_MAP()
	/////////////////////////////////////////////////////////////////
	// IOPMPropertyExpander

	virtual HRESULT STDMETHODCALLTYPE GetElementValue(
		 DISPID dispID,
		 DWORD dwCookie,
		 VARIANT * pVarOut);

	virtual HRESULT STDMETHODCALLTYPE SetElementValue(
		 DISPID dispID,
		 DWORD dwCookie,
		 VARIANT VarIn);

	virtual HRESULT STDMETHODCALLTYPE GetElementStrings( 
		 DISPID dispID,
		 OPMLPOLESTR __RPC_FAR *pCaStringsOut,
		 OPMDWORD __RPC_FAR *pCaCookiesOut);

    virtual HRESULT STDMETHODCALLTYPE GetElementGrouping(
         DISPID dispID,
		 short *groupingNumber);

    virtual HRESULT STDMETHODCALLTYPE GetGroupCount(
         DISPID dispID,
		 long *nGroupCnt);

	/////////////////////////////////////////////////////////////////
	// IPerPropertyDisplay

	virtual  HRESULT STDMETHODCALLTYPE GetCustomPropertyCtrl(
             VARIANT Id,
             LCID lcid,
             BSTR *pProgId);

        virtual  HRESULT STDMETHODCALLTYPE GetPropertyIcon(
             VARIANT Id,
             IUnknown **pIcon);

        virtual  HRESULT STDMETHODCALLTYPE GetPropTextColor(
             VARIANT Id,
             OLE_COLOR *pTextColor);

        virtual  HRESULT STDMETHODCALLTYPE IsFullView(
             VARIANT Id,
             VARIANT_BOOL *pbVisible,
             DWORD *pIntegralHeight);

        virtual  HRESULT STDMETHODCALLTYPE GetPropertyWeight(
             VARIANT Id,
             long *pPropertyWeight);


		// ICategorizeProperties methods

		STDMETHODIMP MapPropertyToCategory(DISPID dispid, PROPCAT* ppropcat)
		{
			return AcOpmMapPropertyToCategory(reinterpret_cast<IUnknown*>(this), CSignEntity::GetOPMPropertyMap(), dispid, ppropcat);
		}
};

OBJECT_ENTRY_AUTO(__uuidof(SignEntity), CSignEntity)
