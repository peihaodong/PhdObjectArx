

#ifndef _ZOPMEXT_H
#define _ZOPMEXT_H
#pragma pack (push, 8)

typedef struct  tagOPMLPOLESTR
    {
    ULONG cElems;
     LPOLESTR __RPC_FAR *pElems;
    }	OPMLPOLESTR;

typedef struct tagOPMLPOLESTR __RPC_FAR *LPOPMLPOLESTR;

typedef struct  tagOPMDWORD
    {
    ULONG cElems;
     DWORD __RPC_FAR *pElems;
    }	OPMDWORD;

typedef struct tagOPMDWORD __RPC_FAR *LPOPMDWORD;

DEFINE_GUID(IID_IOPMPropertyExtension, 
0x021bebdb, 0xf94d, 0x43d7, 0x8d, 0x4b, 0xe7, 0x8b, 0x30, 0x15, 0x8b, 0x43);
  
interface DECLSPEC_UUID("021BEBDB-F94D-43D7-8D4B-E78B30158B43") IOPMPropertyExtension : public IUnknown
{
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    virtual HRESULT STDMETHODCALLTYPE GetDisplayName(
         DISPID dispID,
		 BSTR * propName) = 0;

	virtual HRESULT STDMETHODCALLTYPE Editable( 
		 DISPID dispID,
		 BOOL __RPC_FAR *bEditable) = 0;

	virtual HRESULT STDMETHODCALLTYPE ShowProperty(
		 DISPID dispID, 
		 BOOL *pShow) = 0;
};

DEFINE_GUID(IID_IOPMPropertyExpander, 
0x71fad207, 0xb429, 0x4b81, 0x89, 0xcb, 0x63, 0x3e, 0xc5, 0x77, 0xae, 0x2a);

interface DECLSPEC_UUID("71FAD207-B429-4B81-89CB-633EC577AE2A") IOPMPropertyExpander : public IUnknown
{
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

	virtual HRESULT STDMETHODCALLTYPE GetElementValue(
		 DISPID dispID,
		 DWORD dwCookie,
		 VARIANT * pVarOut) = 0;

	virtual HRESULT STDMETHODCALLTYPE SetElementValue(
		 DISPID dispID,
		 DWORD dwCookie,
		 VARIANT VarIn) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetElementStrings( 
		 DISPID dispID,
		 OPMLPOLESTR __RPC_FAR *pCaStringsOut,
		 OPMDWORD __RPC_FAR *pCaCookiesOut) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetElementGrouping(
         DISPID dispID,
		 short *groupingNumber) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetGroupCount(
         DISPID dispID,
		 long *nGroupCnt) = 0;
};

DEFINE_GUID(IID_IOPMPropertyExpander2, 
0xf69456ad, 0x71aa, 0x4997, 0xbc, 0xad, 0x7c, 0xac, 0x97, 0x04, 0x5e, 0xa7);
interface DECLSPEC_UUID("F69456AD-71AA-4997-BCAD-7CAC97045EA7") IOPMPropertyExpander2 : public IUnknown
{
    
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

	virtual HRESULT STDMETHODCALLTYPE GetElementValue(
		 DISPID dispID,
		 IUnknown * pUnk,
		 DWORD dwCookie,
		 VARIANT * pVarOut) = 0;

	virtual HRESULT STDMETHODCALLTYPE SetElementValue(
		 DISPID dispID,
		 IUnknown * pUnk,
		 DWORD dwCookie,
		 VARIANT VarIn) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetElementStrings( 
		 DISPID dispID,
		 IUnknown * pUnk,
		 OPMLPOLESTR __RPC_FAR *pCaStringsOut,
		 OPMDWORD __RPC_FAR *pCaCookiesOut) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetElementGrouping(
         DISPID dispID,
		 IUnknown * pUnk,
		 short *groupingNumber) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetGroupCount(
         DISPID dispID,
		 IUnknown * pUnk,
		 long *nGroupCnt) = 0;
};

#pragma pack (pop)
#endif 

