

#ifndef _ZOPMDRVR_H
#define _ZOPMDRVR_H

HRESULT ZXAUTOEXP ZcOpmMapPropertyToCategory(IUnknown* pUnk, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispid, PROPCAT* ppropcat);
HRESULT ZXAUTOEXP ZcOpmGetCategoryName(IUnknown* pUnk, HINSTANCE hResInstance, ZCAD_OPMPROPMAP_ENTRY* pMap, PROPCAT propcat, LCID lcid, BSTR* pbstrName);

HRESULT ZXAUTOEXP ZcOpmGetCategoryName(IUnknown* pUnk, HINSTANCE hResInstance, CATEGORY_VECTOR & arr, PROPCAT propcat, LCID lcid, BSTR* pbstrName);
HRESULT ZXAUTOEXP ZcOpmGetCategoryCommandButtons(IUnknown *pUnk, HINSTANCE hResInstance, CATCMDBTN_VECTOR & arr, PROPCAT propcat, VARIANT *pCatCmdBtns);
HRESULT ZXAUTOEXP ZcOpmGetParentCategory(IUnknown *pUnk, CATEGORY_VECTOR & arr, PROPCAT propcat, PROPCAT *pParentCatID);
HRESULT ZXAUTOEXP ZcOpmGetCategoryWeight(IUnknown *pUnk, CATEGORY_VECTOR & arr, PROPCAT propcat, long *pCategoryWeight);
HRESULT ZXAUTOEXP ZcOpmGetCategoryDescription(IUnknown *pUnk, HINSTANCE hResInstance, CATEGORY_VECTOR & arr, PROPCAT propcat, LCID lcid, BSTR* pbstrDesc);

HRESULT ZXAUTOEXP ZcOpmGetDisplayString(IUnknown* pUnk, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BSTR *pBstr);
HRESULT ZXAUTOEXP ZcOpmMapPropertyToPage(IUnknown* pUnk, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, CLSID *pClsid);
HRESULT ZXAUTOEXP ZcOpmGetPredefinedStrings(IUnknown* pUnk, HINSTANCE hResInstance, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, CALPOLESTR *pCaStringsOut, CADWORD *pCaCookiesOut);
HRESULT ZXAUTOEXP ZcOpmGetPredefinedValue(IUnknown* pUnk, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, DWORD dwCookie, VARIANT *pVarOut);

HRESULT ZXAUTOEXP ZcOpmGetDisplayName(IUnknown* pUnk, HINSTANCE hResInstance, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BSTR *pBstr);
HRESULT ZXAUTOEXP ZcOpmEditable(IUnknown* pUnk, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BOOL __RPC_FAR *bEditable);
HRESULT ZXAUTOEXP ZcOpmShowProperty(IUnknown* pUnk, ZCAD_OPMPROPMAP_ENTRY* pMap, DISPID dispID, BOOL *pShow);

HRESULT ZXAUTOEXP ZcOpmGetPropertyWeight(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, long *pPropertyWeight);
HRESULT ZXAUTOEXP ZcOpmIsPropFullView(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, VARIANT_BOOL *pbVisible, DWORD *pIntegralHeight);
HRESULT ZXAUTOEXP ZcOpmGetPropTextColor(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, OLE_COLOR *pTextColor);
HRESULT ZXAUTOEXP ZcOpmGetPropertyIcon(IUnknown *pUnk, HINSTANCE hResInstance, PROP_DISP_VECTOR & arr, VARIANT Id, IUnknown **ppIcon);
HRESULT ZXAUTOEXP ZcOpmGetCustomPropertyCtrl(IUnknown *pUnk, PROP_DISP_VECTOR & arr, VARIANT Id, LCID lcid, BSTR *psProdId);

HRESULT ZXAUTOEXP ZcOpmGetCommandButtons(IUnknown *pUnk, HINSTANCE hResInstance, CMDBTN_VECTOR & arr, VARIANT *pCmdBtns);

#endif 
