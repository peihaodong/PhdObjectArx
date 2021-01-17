
#pragma once

#include "zAcImportXml.h"
using namespace MSXML;
#include "zAcPExCtl.h"
#include "zopmdialog.h"
#include "zAc64BitHelpers.h"

typedef CTypedPtrArray<CPtrArray, ZcTcCatalogItem*> ZcTcCatalogItemArray;
BOOL ZcTcUiFilterShapesDialog(ZcTcCatalogItem* pPackage,
                                            ZcTcCatalogItemArray* pActiveShapes,
                                            ZcTcTool*& pCurrentShape,
                                            CWnd* pParentWnd);
struct PER_PROP_DISP_ENTRY2
{
    DISPID    m_dispid;
    LPCWSTR   m_ProgID;
    LPCWSTR   m_lpLeftIconRes;
    UINT      m_nLeftIconType;
    LPCWSTR   m_lpEllipsisBmpRes;
    UINT      m_nEllipsisBmpType;
    COLORREF  m_TextColor;
    bool      m_bFullView;
    DWORD     m_dwIntegralHeight;
    long      m_nWeight;
};

#ifndef TEXTCOLOR_DEFAULT
#define TEXTCOLOR_DEFAULT 0x80000008
#endif

#define BEGIN_PERPROPDISPLAY_MAP2()                                                            \
    static PER_PROP_DISP_ENTRY2* GetPerPropDisplayArray2()                                    \
    {                                                                                        \
        static PER_PROP_DISP_ENTRY2 pPerPropDisplayArray[] =                                 \
        {

#define PROP_DISP_ENTRY2(dispid, progid, lpLeftIconRes, lpLeftIconType,                        \
    lpEllipsisBmpRes, lpEllipsisBmpType, textcolor,                                          \
    bFullView, dwIntegralHeight, nWeight)                                                    \
        {dispid, progid, lpLeftIconRes, lpLeftIconType, lpEllipsisBmpRes,                    \
        lpEllipsisBmpType, textcolor, bFullView,                                             \
        dwIntegralHeight, nWeight},                                                            \

#define END_PERPROPDISPLAY_MAP2()                                                            \
        {-1, NULL, NULL, (UINT)PICTYPE_UNINITIALIZED, NULL, (UINT)PICTYPE_UNINITIALIZED, TEXTCOLOR_DEFAULT, false, (DWORD)-1, -1}\
        };                                                                                    \
        return pPerPropDisplayArray;                                                        \
    }

struct PER_FLYOUT_ENTRY
{
    DISPID    dispid;
};


#define BEGIN_FLYOUT_SPECIFIC_MAP()\
    static PER_FLYOUT_ENTRY* GetFlyoutMap()\
    {\
        static PER_FLYOUT_ENTRY pFlyoutEntry[]=\
        {

#define FLYOUT_ENTRY(dispid)\
            {dispid},

#define END_FLYOUT_SPECIFIC_MAP()\
            {-1}\
        };\
        return pFlyoutEntry;\
    }
    

#define CF_AUTOCAD      L"ZWCAD.r17"

static void *pZcadToolImpl=NULL;

template <class TT,class T,const CLSID* pclsid,LPCWSTR szToolName,LPCWSTR szToolImage,const IID* piid = &__uuidof(T),const GUID* plibid = &CAtlModule::m_libid>
class ATL_NO_VTABLE ZcadToolImpl :
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<T, piid, plibid,  1,  0>,
    public IZcadTool,
    public IZcadTool2,
    public IZcadStockTool,
    public IDropTarget,
    public IPropertyUnspecified,
    public IPerPropertyDisplayImpl<ZcadToolImpl<TT,T,pclsid,szToolName,szToolImage,piid,plibid> >,
    public IOPMPropertyExtension,
    public IZcadToolContextMenu,
    public IPerPropertyBrowsing,
    public IOPMPropertyDialog,
    public IZcadToolFlyoutShape
{
public:

    ZcadToolImpl()
    {
        wcscpy_s(m_szLayer,L"0");
        wcscpy_s(m_FlyoutTools,L"\0");
        dispColor=dispLayer=0;
        m_bColorUnspecified=m_bLayerUnspecified=TRUE;
        m_hWndEditWindow=NULL;
        m_pToolProp=NULL;
        mcfZWCAD = (CLIPFORMAT)::RegisterClipboardFormat(zcedClipFormatName());
    }
    ~ZcadToolImpl()
    {
        m_ToolMap.setLogicalLength(0);
    }

    static PER_PROP_DISP_ENTRY* GetPerPropDisplayArray()
    {
        return (PER_PROP_DISP_ENTRY*)TT::GetPerPropDisplayArray2();
    }

    ZcCmColor m_Color;
    WCHAR m_szLayer[512];
    DISPID dispColor,dispLayer,dispFlyout;
    HWND m_hWndEditWindow;
    CComPtr<IZcadToolProperties> m_pToolProp;
    bool m_bFlyout;
    GUID m_FlyoutPackageId;
    GUID m_CurrentShapeId;
    WCHAR m_FlyoutTools[64];

BEGIN_COM_MAP(ZcadToolImpl)
    COM_INTERFACE_ENTRY(T)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(IZcadTool)
    COM_INTERFACE_ENTRY(IZcadStockTool)
    COM_INTERFACE_ENTRY(IDropTarget)
    COM_INTERFACE_ENTRY(IPropertyUnspecified)
    COM_INTERFACE_ENTRY(IPerPropertyDisplay)
    COM_INTERFACE_ENTRY(IOPMPropertyExtension)
    COM_INTERFACE_ENTRY(IZcadToolContextMenu)
    COM_INTERFACE_ENTRY(IPerPropertyBrowsing)
    COM_INTERFACE_ENTRY(IOPMPropertyDialog)
    COM_INTERFACE_ENTRY(IZcadToolFlyoutShape)
END_COM_MAP()
protected:

    HWND m_hPreviewWnd;
    BOOL m_bColorUnspecified,m_bLayerUnspecified;

    struct TOOL_MAP_ENTRY
    {
        WCHAR szDesc[512];
        DISPID dispId;
    };
    ZcArray<TOOL_MAP_ENTRY> m_ToolMap;
    CLIPFORMAT mcfZWCAD;

public:

public:
    STDMETHOD(CreateTool) ( IUnknown** ppTool)
    {

        HRESULT hr=GetPropertyTypeInfo();
        return _InternalQueryInterface(IID_IZcadTool, (void**) ppTool);
    }
public:
    STDMETHOD(get_EditMode) ( long* pVal)
    {

        *pVal = kEditDefault;
        return S_OK;
    }

    STDMETHOD(GetStockTool) ( IUnknown** ppToolClass)
    {

        return _InternalQueryInterface(IID_IZcadStockTool, (void**) ppToolClass);
    }

    STDMETHOD(Load) ( IUnknown* pXmlElement)
    {
        CComQIPtr<MSXML::IXMLDOMNode> pEntityNode=pXmlElement;

        if (pEntityNode == NULL)
            return E_INVALIDARG;

        MSXML::IXMLDOMNodePtr pAttributeNode,pChild;

        if(GetChildNode(pEntityNode, L"Tool",&pAttributeNode))

            for(int i=0;i<m_ToolMap.length();i++)
                if(GetChildNode(pAttributeNode, m_ToolMap.at(i).szDesc,&pChild))
                    LoadPropertyValue(pChild,i+1);
        return S_OK;
    }

    STDMETHOD(LoadFromFlyout)(IUnknown* pXmlElement)
    {
        CComQIPtr<MSXML::IXMLDOMNode> pEntityNode=pXmlElement;

        if (pEntityNode == NULL)
            return E_INVALIDARG;

        MSXML::IXMLDOMNodePtr pAttributeNode,pChild;

        PER_FLYOUT_ENTRY *pFlyoutMap=TT::GetFlyoutMap();

        if(GetChildNode(pEntityNode, L"Tool",&pAttributeNode))

            for(int i=0;i<m_ToolMap.length();i++)
                if(GetChildNode(pAttributeNode, m_ToolMap.at(i).szDesc,&pChild))
                {
                    int ii=0;
                    bool bGlobalProp=false;
                    while(pFlyoutMap[ii].dispid!=-1)
                    {
                        if(pFlyoutMap[ii].dispid==i+1)
                        {
                            bGlobalProp=true;
                            break;
                        }
                        ii++;
                    }
                    if(bGlobalProp)
                        LoadPropertyValue(pChild,i+1);
                }
        return S_OK;
    }

    STDMETHOD(Save) ( IUnknown* pXmlElement)
    {
        if (pXmlElement == NULL)
            return E_INVALIDARG;

        MSXML::IXMLDOMNodePtr pEntityNode,pChildNode,pToolNode;
        CComQIPtr<MSXML::IXMLDOMNode> pParentNode=pXmlElement;
        if(!GetChildNode(pParentNode,L"Tool",&pEntityNode))
            AddChildNode(pParentNode, L"Tool", MSXML::NODE_ELEMENT, &pEntityNode);
        for(int i=0;i<m_ToolMap.length();i++)
        {
            if(!GetChildNode(pEntityNode, m_ToolMap.at(i).szDesc,&pChildNode))
                AddChildNode(pEntityNode,m_ToolMap.at(i).szDesc,MSXML::NODE_ELEMENT,&pChildNode);
            SavePropertyValue(pChildNode,i+1);
        }
        return S_OK;
    }

    STDMETHOD(executeCallback)() {return E_NOTIMPL;}
    STDMETHOD(dropCallback)(ZcDbEntity *pEntity){return E_NOTIMPL;}

    STDMETHOD(Execute) ( LONG_PTR lFlag,  DWORD_PTR  hWnd,  DWORD point,  DWORD dwKeyState)
    {
        static bool bExecuteMutex=false;
        if(bExecuteMutex)
            return S_OK;
        bExecuteMutex=true;
        ::SetFocus(zdsw_zcadDocWnd());
        ZcDbDatabase *pDb = zcdbHostApplicationServices()->workingDatabase();
        if(!pDb)
            return E_FAIL;
        ZcAxDocLock docLock( pDb, ZcAxDocLock::kNormal );
        if(docLock.lockStatus() != Zcad::eOk){
            return E_FAIL;
        }
        ZcTcTool *pFlyoutTool=NULL;
        if(GetFlyoutTool(pFlyoutTool))
        {

            CComPtr<IUnknown> pUnk;

            BOOL bRet = pFlyoutTool->GetToolData(&pUnk);
            LoadFromFlyout(pUnk);
        }

        wcscpy_s(m_FlyoutTools,L"");

        executeCallback();

        bExecuteMutex=false;

        return S_OK;
    }

    BOOL GetFlyoutTool(ZcTcTool*& pFlyoutTool)
    {
        pFlyoutTool = NULL;

        if(!wcscmp(m_FlyoutTools,L"")){
            return FALSE;
        }

        GUID flyoutToolId;
        BOOL bRet = FALSE;
        bRet = GuidFromString(m_FlyoutTools, flyoutToolId);
        if (!bRet)

            return FALSE;
        ZcTcManager* pMgr = ZcTcGetManager();
        pFlyoutTool = (ZcTcTool*) pMgr->FindItem(flyoutToolId);
        if (pFlyoutTool == NULL)
            return FALSE;

        if (pFlyoutTool->GetType() != kItemTool)
            return FALSE;
        CComPtr<T> pThisTool;
        if(!SUCCEEDED(QueryInterface(*piid,(void**)&pThisTool)))
            return E_FAIL;

        return TRUE;
    }
    STDMETHOD(GetData) ( VARIANT *pObjUnkArray,  VARIANT *pDynUnkArray)
    {
        CComPtr<IUnknown> pUnk;
        _InternalQueryInterface(IID_IUnknown, (void**) &pUnk);
        GetUnknownArrays(1, &pUnk, pObjUnkArray, pDynUnkArray);
        return S_OK;
    }
    STDMETHOD(BeginEdit) ()
    {
        return S_OK;
    }
    STDMETHOD (Edit) ( IUnknown* pProp, LONG_PTR  hWndParent,  VARIANT_BOOL* pRet)
    {
        m_hWndEditWindow=(HWND)hWndParent;
        return S_OK;
    }
    STDMETHOD (EndEdit)( VARIANT_BOOL bEditCancelled){return E_NOTIMPL;}

    STDMETHOD (Dropped)( BSTR bstrUrl)
    {
        return E_NOTIMPL;
    }
    STDMETHOD(GetDropTarget) ( IUnknown** ppDropTarget)
    {

        return _InternalQueryInterface(IID_IDropTarget, (void**) ppDropTarget);
    }

    STDMETHOD (Refreshed)( BSTR bstrUrl)
    {
        return E_NOTIMPL;
    }
    STDMETHOD (SetEditorWindow)( LONG_PTR  hWndEditor,  IUnknown*	pPropInspector)
    {

        m_hPreviewWnd = (HWND) hWndEditor;
        return E_NOTIMPL;
    }

    STDMETHOD (ValidateEditChanges)()
    {
        return E_NOTIMPL;
    }

    STDMETHOD(SetToolProperties) ( IUnknown* pProp)
    {

        HRESULT hr = pProp->QueryInterface(IID_IZcadToolProperties, (void**) &m_pToolProp);
        if(!m_pToolProp)
            return E_FAIL;

        hr=m_pToolProp->get_ShapePackageId(&m_FlyoutPackageId);
        hr = m_pToolProp->get_CurrentShapeId(&m_CurrentShapeId);
        return S_OK;
    }

    STDMETHOD (GetToolProperties)( IUnknown** pToolProp)
    {

        m_pToolProp->QueryInterface(IID_IZcadToolProperties,(void**)pToolProp);
        return S_OK;
    }

    STDMETHOD(New) ()
    {

        return E_NOTIMPL;
    }
    STDMETHOD(UpdateImage)(void)
    {
        return E_NOTIMPL;
    }

    STDMETHOD(GetContextMenu) ( INT_PTR nContextFlag,  DWORD_PTR  hMenu,  UINT idCmdFirst,  UINT idCmdLast,  DWORD_PTR* pFlag){return E_NOTIMPL;}
    STDMETHOD(GetCommandString) ( UINT idCmd, BSTR* pbstrHelpText){return E_NOTIMPL;}
    STDMETHOD(InvokeCommand) ( UINT idCmd,  DWORD_PTR  hWnd){return E_NOTIMPL;}
    STDMETHOD(GetDragDropContextInfo) ( IUnknown*	pIUnknown, BSTR* pbstrText,  DWORD* pFlag)
    {
        _bstr_t bstrName(szToolName);
        *pbstrText = bstrName.copy();
        return S_OK;
    }

    STDMETHOD(BeginMultipleEdit) ( VARIANT tools,
                                   VARIANT stockToolIds)
    {
        return E_NOTIMPL;
    }

    STDMETHOD(EndMultipleEdit) ( VARIANT tools,
                                 VARIANT stockToolIds,
                                 VARIANT_BOOL bEditCancelled)
    {
        return E_NOTIMPL;
    }

    STDMETHOD (MultipleEdit) ( VARIANT tools,
                               VARIANT stockToolIds,
                               LONG_PTR  hWndParent,
                               VARIANT_BOOL* pRet)
    {
        return E_NOTIMPL;
    }
    STDMETHOD(Customize)( int nContextFlag,
                             DWORD_PTR hMenu,
                             UINT idCmdFirst,
                         UINT idCmdLast,
                         GUID *pPaletteId,
                         DWORD *pFlag)
    {
        return E_NOTIMPL;
    }
    STDMETHOD(GetMenuHelp)(  UINT idCmd,
                             BSTR *pbstrHelpText)
    {
        return E_NOTIMPL;
    }

    STDMETHOD(InvokeMenuCommand)( UINT idCmd,
                                     GUID *pPaletteId,
                                     DWORD_PTR hWnd,
                                     DWORD *pFlag)
    {
        return E_NOTIMPL;
    }
    STDMETHOD(DragEnter) ( IDataObject __RPC_FAR *pDataObj,  DWORD grfKeyState,  POINTL pt,  DWORD __RPC_FAR *pdwEffect)
    {
        *pdwEffect = DROPEFFECT_COPY;
        return S_OK;
    }

    STDMETHOD(DragOver) ( DWORD grfKeyState,  POINTL pt,  DWORD __RPC_FAR *pdwEffect)
    {
        *pdwEffect = DROPEFFECT_COPY;
        return S_OK;
    }

    STDMETHOD(DragLeave) (void){return E_NOTIMPL;}
    STDMETHOD(Drop) ( IDataObject __RPC_FAR *pDataObj,  DWORD grfKeyState,  POINTL pt,  DWORD __RPC_FAR *pdwEffect)
    {
        *pdwEffect = DROPEFFECT_COPY;

        COleDataObject data;
        data.Attach(pDataObj, FALSE);
        ClipboardInfo clipInfo;
        if (!GetClipInfo(&data, &clipInfo))
            return E_FAIL;

        ZcDbDatabase tempDb(false, true);
        Zcad::ErrorStatus es = tempDb.readDwgFile(clipInfo.szTempFile);
        if (es != Zcad::eOk)
            return E_FAIL;

        ZcDbBlockTableRecordIterator *pItr = NULL;
        {
            ZcDbBlockTableRecordPointer pBTR(ZCDB_MODEL_SPACE,&tempDb,ZcDb::kForRead);
            if(pBTR->newIterator(pItr)!=Zcad::eOk)
                return E_FAIL;
        }

        ZcDbEntity *pDropEntity=NULL;
        while(!pItr->done())
        {

            if(pItr->getEntity(pDropEntity, ZcDb::kForRead)!=Zcad::eOk)
            {
                delete pItr;
                return E_FAIL;
            }
            break;
            pItr->step();
        }
        delete pItr;

        if(pDropEntity==NULL)
            return E_FAIL;
        m_bLayerUnspecified=FALSE;
        m_bColorUnspecified=FALSE;

        HRESULT hr=dropCallback(pDropEntity);
        pDropEntity->close();

        if(!SUCCEEDED(hr))
            return E_FAIL;
        if (m_pToolProp != NULL) {

            hr=m_pToolProp->put_Name(CComBSTR(szToolName));
            WCHAR modulePath[MAX_PATH];
            HINSTANCE hInst=_AtlBaseModule.GetResourceInstance();
            DWORD res=GetModuleFileName(hInst,modulePath,MAX_PATH);

            ZcTcImage image;
            HBITMAP hBitmap=::LoadBitmap(_AtlBaseModule.GetResourceInstance(),szToolImage);
            image.Load(hBitmap);
            SIZE size;
            image.GetSize(&size);

            hr=m_pToolProp->SetImage(size.cx,size.cy,NULL,CComBSTR(szToolImage),CComBSTR(modulePath));
        }
        data.Detach();
        return hr;
    }
    STDMETHOD (IsValueUnspecified)( VARIANT varId,  VARIANT_BOOL *pVal)
    {
        *pVal = VARIANT_FALSE;
        if (varId.ulVal == dispColor || varId.ulVal == dispLayer)
        {	if (varId.ulVal ==  dispColor && m_bColorUnspecified)
                *pVal=VARIANT_TRUE;
            if (varId.ulVal ==  dispLayer && m_bLayerUnspecified)
                *pVal=VARIANT_TRUE;
        }
        return S_OK;
    }
    STDMETHOD (SetUnspecified)( VARIANT varId,  VARIANT_BOOL bIsUnspecified)
    {
        if (varId.ulVal == dispColor)
            m_bColorUnspecified = (bIsUnspecified == VARIANT_TRUE ? true : false);
        else if (varId.ulVal == dispLayer)
            m_bLayerUnspecified = (bIsUnspecified == VARIANT_TRUE ? true : false);
        return S_OK;
    }

    STDMETHOD (IsUnspecifiedAllowed)( VARIANT varId,  VARIANT_BOOL *pVal)
    {
        if (varId.ulVal == dispColor || varId.ulVal == dispLayer)
            *pVal=VARIANT_TRUE;
        else
            *pVal = VARIANT_FALSE;
        return S_OK;
    }

    STDMETHOD (GetUnspecifiedString)(VARIANT,BSTR *str)
    {

        _bstr_t unspecifiedString(L"*Unspecified*");
        *str = unspecifiedString.copy();
        return S_OK;
    }

    STDMETHOD(GetEllipsisBitMap) (
         VARIANT varId,
         IUnknown __RPC_FAR *__RPC_FAR *pBitMap){return E_NOTIMPL;}

    STDMETHOD(GetPropHelpProc) (
         VARIANT varId,
         LONG __RPC_FAR *pHelpProc){return E_NOTIMPL;}
    BOOL GetClipInfo(COleDataObject* pDataObject, ClipboardInfo* pClipboardInfo)
    {
        CLIPFORMAT cFormat = mcfZWCAD;

        if (!pDataObject->IsDataAvailable(cFormat)) {
            return FALSE;
        }

        STGMEDIUM stgMedium = { TYMED_HGLOBAL,  NULL };
        FORMATETC fmt = { cFormat, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
        BOOL bValid = pDataObject->GetData(cFormat, &stgMedium, &fmt);

        if (bValid && stgMedium.hGlobal != NULL)
        {
            ClipboardInfo* pClipInfo=(ClipboardInfo*)::GlobalLock(stgMedium.hGlobal);
            *pClipboardInfo = *pClipInfo;

            ::GlobalUnlock(stgMedium.hGlobal);
            ::ReleaseStgMedium(&stgMedium);
            return TRUE;
        }
        return FALSE;
    }

    virtual HRESULT GetPropertyTypeInfo()
    {
        T *pITool;

        if (!SUCCEEDED(QueryInterface(*piid,(void**)&pITool)))
            return E_FAIL;

        unsigned int count = 0;
        if (!SUCCEEDED(pITool->GetTypeInfoCount(&count))) {
            pITool->Release();
            return E_FAIL;
        }

        if (!count)
            return E_FAIL;

        CComPtr<ITypeInfo> pTypeInfo;
        if (!SUCCEEDED(pITool->GetTypeInfo(0, NULL, &pTypeInfo))) {
            pITool->Release();
            return E_FAIL;
        }
        pITool->Release();

        TYPEATTR * pTypeAttr;
        if (!SUCCEEDED(pTypeInfo->GetTypeAttr(&pTypeAttr)))
            return E_FAIL;
        int numFuncs = pTypeAttr->cFuncs;
        pTypeInfo->ReleaseTypeAttr(pTypeAttr);

        m_ToolMap.setLogicalLength(0);
        for(int i = 0; i < numFuncs; i++)
        {

            FUNCDESC * pFuncDesc;
            if (!SUCCEEDED(pTypeInfo->GetFuncDesc(i, &pFuncDesc)))
                return E_FAIL;

            MEMBERID memberID;
            memberID = pFuncDesc->memid;

            if(memberID < 1000)
            {
					UINT nReturnedNames = 0;
                    if(pFuncDesc->invkind==INVOKE_PROPERTYGET)
                        continue;
					BSTR bstrNames[1] = {NULL};
                    if (!SUCCEEDED(pTypeInfo->GetNames(memberID, bstrNames, 1, &nReturnedNames)))
                        return E_FAIL;
                    if(nReturnedNames<1)
                        continue;

                    CComBSTR bstrVal(bstrNames[0]);
                    COLE2T szName(bstrVal);
                    TOOL_MAP_ENTRY mapEntry;
                    wcscpy_s(mapEntry.szDesc,szName);
                    mapEntry.dispId=memberID;
                    m_ToolMap.append(mapEntry);
                    if(!wcscmp(szName,L"Color"))
                        dispColor=memberID;
                    if(!wcscmp(szName,L"Layer"))
                        dispLayer=memberID;
                    if(!wcscmp(szName,L"Flyout"))
                        dispFlyout=memberID;
                    SysFreeString(bstrNames[0]);
            }
        }
        return S_OK;
    }

    HRESULT PutToolProperty(int index,VARIANT vValue)
    {
        WORD wflags = DISPATCH_PROPERTYPUT;
        DISPID putid = DISPID_PROPERTYPUT;
        CComPtr<IDispatch> pDisp;
        if(!SUCCEEDED(QueryInterface(*piid,(void**)&pDisp)))
            return E_FAIL;

        DISPPARAMS dispparams;

        dispparams.rgvarg = &vValue;
        dispparams.rgdispidNamedArgs= &putid;
        dispparams.cArgs = 1;
        dispparams.cNamedArgs = 1;

        return pDisp->Invoke(m_ToolMap[index-1].dispId,
            IID_NULL,
            LOCALE_USER_DEFAULT,
            wflags,
            &dispparams,
            NULL,NULL,NULL);
    }

    HRESULT GetToolProperty(int index,VARIANT& vValue)
    {
        CComPtr<IDispatch> pDisp;
        if(!SUCCEEDED(QueryInterface(*piid,(void**)&pDisp)))
            return E_FAIL;

        DISPPARAMS dispparamsNoArgs = {NULL, NULL, 0, 0};

        return pDisp->Invoke(
        m_ToolMap[index-1].dispId,
        IID_NULL,
        LOCALE_USER_DEFAULT,
        DISPATCH_PROPERTYGET,
        &dispparamsNoArgs, &vValue, NULL, NULL);
    }
    STDMETHOD(GetDisplayString)(DISPID dispID,BSTR *pbstr)
    {
        return E_NOTIMPL;
    }

    STDMETHOD(MapPropertyToPage)(DISPID dispID,CLSID *pCLSID)
    {
        if(dispID==dispFlyout)
        {
            *pCLSID=*pclsid;
            pZcadToolImpl=(void*)this;
            return S_OK;
        }
        else
            return E_NOTIMPL;
    }

    STDMETHOD(GetPredefinedStrings)(DISPID dispID,CALPOLESTR *pcaStringsOut,CADWORD *pcaCookiesOut)
    {
        return E_NOTIMPL;
    }

    STDMETHOD(GetPredefinedValue)(DISPID dispID,DWORD dwCookie,VARIANT *pVarOut)
    {
        return E_NOTIMPL;
    }
    STDMETHOD(DoModal)(BSTR* propValueString,ZcDbObjectIdArray* ObjectIdArray)
    {
        IZcadToolProperties *pToolProp=GetThisToolsProperties();
        if(!pToolProp)
            return E_FAIL;

        ZcTcManager* pMgr = ZcTcGetManager();
        if (!pMgr)
            return E_FAIL;
        GUID id;
        pToolProp->get_ShapePackageId(&id);

        ZcTcCatalogItem* pShapeCatalog = pMgr->GetShapeCatalog();
        ZcTcCatalogItem* pShapePackage=pShapeCatalog->FindInChildren(id);

        if (!pShapePackage)
            return E_FAIL;
        VARIANT varShapes;
        HRESULT hr = pToolProp->get_ActiveShapeIds(&varShapes);

        if(!(varShapes.vt & VT_ARRAY && varShapes.vt & VT_BSTR))
                return E_INVALIDARG;
        SAFEARRAY* sPt=varShapes.parray;

        if(SafeArrayGetDim(sPt)!=1)
            return E_INVALIDARG;

        long lLower,lUpper;
        SafeArrayGetLBound(sPt,1,&lLower);
        SafeArrayGetUBound(sPt,1,&lUpper);
        ZcTcCatalogItemArray activeShapes;
        for(long i=lLower; i<=lUpper; i++) {
            VARIANT val;
            SafeArrayGetElement(sPt,&i,&val);
            GUID id;
            GuidFromString(CW2T(val.bstrVal), id);

            ZcTcCatalogItem* pItem = pShapePackage->FindInChildren(id, FALSE);
            if (pItem == NULL)
                continue;
            if (pItem->GetType() == kItemTool)
                activeShapes.Add(pItem);
        }
        GUID currentShapeId;
        hr = pToolProp->get_CurrentShapeId(&currentShapeId);
        ZcTcTool* pCurrentShape = (ZcTcTool*)pShapePackage->FindInChildren(currentShapeId, FALSE);
        if(!ZcTcUiFilterShapesDialog(pShapePackage, &activeShapes,pCurrentShape, NULL))
            return E_FAIL;
        INT_PTR nCount = activeShapes.GetSize();

        SAFEARRAYBOUND rgsaBound;
        rgsaBound.lLbound = 0L;
        rgsaBound.cElements = ZcIntPtrToInt(nCount);

        VariantClear(&varShapes);
        varShapes.vt = VT_ARRAY | VT_VARIANT;
        sPt=varShapes.parray;
        varShapes.parray = SafeArrayCreate(VT_VARIANT, 1, &rgsaBound);

        for (long i=0; i<nCount; i++) {
            ZcTcCatalogItem* pItem = activeShapes[i];
            pItem->GetID(&id);
            VARIANT varGuid;
            varGuid.vt = VT_BSTR;
            varGuid.bstrVal=StringFromGuid(id);
            hr = SafeArrayPutElement(varShapes.parray, &i,&varGuid);
        }
        hr=pToolProp->put_ActiveShapeIds(&varShapes);

        return S_OK;
    }
    STDMETHOD(SetFlyoutTools) ( VARIANT* pFlyoutToolIds)
    {
        wcscpy_s(m_FlyoutTools,L"");
        if (pFlyoutToolIds == NULL)
            return S_OK;

        SAFEARRAY* saFlyoutToolIds=pFlyoutToolIds->parray;

        if(SafeArrayGetDim(saFlyoutToolIds)!=1)
            return E_INVALIDARG;

        long lLower,lUpper;
        SafeArrayGetLBound(saFlyoutToolIds,1,&lLower);
        SafeArrayGetUBound(saFlyoutToolIds,1,&lUpper);

        for(long i=lLower; i<=lUpper; i++) {
            VARIANT val;
            SafeArrayGetElement(saFlyoutToolIds,&i,&val);
            wcscpy_s(m_FlyoutTools,CW2T(val.bstrVal));
        }
        return S_OK;
    }
    STDMETHOD(Editable)(DISPID dispID,BOOL __RPC_FAR * bEditable)
    {
        return E_NOTIMPL;
    }

    STDMETHOD(GetDisplayName)(DISPID dispID,BSTR * propName)
    {
        return E_NOTIMPL;
    }

    STDMETHOD(ShowProperty)(DISPID dispID,BOOL * pShow)
    {
        *pShow=TRUE;

        IZcadToolProperties *pToolProp=GetThisToolsProperties();
        if(!pToolProp)
            return E_FAIL;

        VARIANT_BOOL vbFlyout;
        pToolProp->get_IsFlyoutEnabled(&vbFlyout);
        if(vbFlyout)
        {
            PER_FLYOUT_ENTRY *pFlyoutMap=TT::GetFlyoutMap();

            for(int i=0;i<m_ToolMap.length();i++)
            {
                int ii=0;
                bool bGlobalProp=false;
                while(pFlyoutMap[ii].dispid!=-1)
                {
                    if(pFlyoutMap[ii].dispid==dispID)
                    {
                        bGlobalProp=true;
                        break;
                    }
                    ii++;
                }
                if(bGlobalProp)
                    *pShow=TRUE;
                else
                    *pShow=FALSE;
            }
        }
        else
            if(dispID==dispFlyout)
                *pShow=FALSE;

        return S_OK;
    }
    BOOL GuidFromString(LPWSTR pszGuid, GUID& id)
    {
        ZeroMemory(&id, sizeof(GUID));

        if (pszGuid == NULL)
            return FALSE;
        WCHAR tsFormatGuid[64]=L"{";
        if(wcslen(pszGuid) > 0 && pszGuid[0] !=L'{')
            wcscat(tsFormatGuid,pszGuid);
        if(wcslen(pszGuid) > 0 && pszGuid[wcslen(tsFormatGuid)-1] !=L'}')
            wcscat(tsFormatGuid,L"}");

        HRESULT hr = CLSIDFromString(CT2W(tsFormatGuid), &id);
        return SUCCEEDED(hr);
    }

    CComBSTR StringFromGuid(const GUID& id)
    {

        LPOLESTR pbstrGuid = NULL;
        HRESULT hr = StringFromCLSID(id, &pbstrGuid);
        if (FAILED(hr) || pbstrGuid == NULL)
            return L"";

        CW2T   szVal(pbstrGuid);
        LPWSTR  sId(szVal);
        sId=_wcsninc(sId,1);
        _wcsrev(sId);
        sId=_wcsninc(sId,1);
        _wcsrev(sId);

        CComBSTR bstr(sId);
        CoTaskMemFree(pbstrGuid);

        return bstr;
    }
    STDMETHOD (get_Color)(VARIANT *pVar)
    {
        if (pVar == NULL)
            return E_FAIL;

        VariantInit(pVar);
        pVar->vt = VT_DISPATCH;

        CComQIPtr<IZcadZcCmColor> pIZcadZcCmColor;
        HRESULT hr = pIZcadZcCmColor.CoCreateInstance(CLSID_ZcadZcCmColor);
        if (FAILED(hr) || !pIZcadZcCmColor)
            return E_FAIL;

        CComBSTR colorName(m_Color.colorName());
        CComBSTR bookName(m_Color.bookName());
        pIZcadZcCmColor->put_EntityColor(m_Color.color());
        pIZcadZcCmColor->SetNames(colorName, bookName);

        hr = pIZcadZcCmColor->QueryInterface(IID_IDispatch, (void**) &pVar->pdispVal);
        if(SUCCEEDED(hr))
            return S_OK;
        else
            return E_FAIL;
    }

    STDMETHOD (put_Color)(VARIANT pVar)
    {
        if (V_VT(&pVar) != VT_DISPATCH)
            return E_FAIL;

        if (pVar.pdispVal == NULL)
            return E_FAIL;

        HRESULT hr = S_OK;
        CComQIPtr<IZcadZcCmColor> pIZcadZcCmColor;
        hr =  pVar.pdispVal->QueryInterface(IID_IZcadZcCmColor, (void**) &pIZcadZcCmColor);
        if (FAILED(hr) || !pIZcadZcCmColor)
            return E_FAIL;
        BSTR colorName, bookName;
        long lEntityColor;
        colorName = bookName = NULL;
        lEntityColor = 0;

        hr = pIZcadZcCmColor->get_EntityColor(&lEntityColor);
        hr = pIZcadZcCmColor->get_ColorName(&colorName);
        hr = pIZcadZcCmColor->get_BookName(&bookName);

        m_Color.setColor(lEntityColor);
        m_Color.setNames(CW2T(colorName),CW2T(bookName));
        return S_OK;
    }
    STDMETHOD (get_Layer)(BSTR* pVal)
    {
        CComBSTR bStr(m_szLayer);
        bStr.CopyTo(pVal);
        return S_OK;
    }

    STDMETHOD (put_Layer)(BSTR newVal)
    {
        CComBSTR bStr(newVal);
        COLE2T szName(bStr);
        wcscpy_s(m_szLayer,szName);
        return S_OK;
    }

    STDMETHOD(put_Flyout)(BSTR var)
    {

        return S_OK;
    }

    STDMETHOD(get_Flyout)(BSTR *pVar)
    {
        CComBSTR bstr(L"<Choose Commands>");
        bstr.CopyTo(pVar);
        return S_OK;
    }

    BOOL GetUnknownArrays(int nCount,
                        IUnknown** pObjUnkArray,
                        VARIANT* pStatUnkArray,
                        VARIANT* pDynPMUnkArrays)
    {
        if (nCount < 1)
            return FALSE;

        pStatUnkArray->vt = VT_ARRAY | VT_VARIANT;
        pDynPMUnkArrays->vt = VT_ARRAY | VT_VARIANT;

        SAFEARRAYBOUND rgsaBound;
        rgsaBound.lLbound = 0L;
        rgsaBound.cElements = nCount;

        pStatUnkArray->parray = SafeArrayCreate(VT_VARIANT, 1, &rgsaBound);
        pDynPMUnkArrays->parray = SafeArrayCreate(VT_VARIANT,1,&rgsaBound);

        HRESULT hr;
        try {
            for (long i = 0; i < nCount; i++)
            {
                VARIANT statVariant;
                VariantClear(&statVariant);
                statVariant.vt = VT_UNKNOWN;
                statVariant.punkVal=pObjUnkArray[i];
                hr = SafeArrayPutElement(pStatUnkArray->parray, &i, &statVariant);

                VARIANT dynamicPMArray;
                VariantClear(&dynamicPMArray);
                dynamicPMArray.vt = VT_ARRAY | VT_VARIANT;
                SAFEARRAYBOUND dynamicBound;
                dynamicBound.lLbound = 0L;
                dynamicBound.cElements = 1L;
                dynamicPMArray.parray = SafeArrayCreate(VT_VARIANT, 1, &dynamicBound);

                VARIANT statVariant2;
                VariantClear(&statVariant2);
                statVariant2.vt = VT_UNKNOWN;
                statVariant2.punkVal=NULL;
                long bound=0;
                hr=SafeArrayPutElement(dynamicPMArray.parray, &bound,&statVariant2);

                hr=SafeArrayPutElement(pDynPMUnkArrays->parray, &i, &dynamicPMArray);
            }
        }
        catch(int)
		{
            return FALSE;
        }
        return TRUE;
    }
    BOOL GetAttribute(MSXML::IXMLDOMNode* pNode,
                    LPCWSTR pszAttName,
                    MSXML::IXMLDOMAttribute** ppChild)
    {
        if (ppChild == NULL)
            return FALSE;

        *ppChild = NULL;

        if (pNode == NULL || pszAttName == NULL)
            return FALSE;
        MSXML::IXMLDOMNamedNodeMapPtr pAttributes;
        pNode->get_attributes(&pAttributes);
        if (pAttributes == NULL) {

            return FALSE;
        }

        long nCount;
        pAttributes->get_length(&nCount);
        if (nCount < 1) {
            return FALSE;
        }

        MSXML::IXMLDOMAttributePtr pAttr;
        pAttr = pAttributes->getNamedItem(_bstr_t(pszAttName));
        if (pAttr == NULL) {

            return FALSE;
        }

        *ppChild = pAttr.GetInterfacePtr();
        if (*ppChild != NULL)
            (*ppChild)->AddRef();

        return TRUE;
    }

    BOOL GetChildNode(MSXML::IXMLDOMNode* pNode,
                    LPCWSTR pszNodeName,
                    MSXML::IXMLDOMNode** ppChild)
    {
        try {
            if (ppChild == NULL)
                return FALSE;

            *ppChild = NULL;

            if (pNode == NULL || pszNodeName == NULL)
                return FALSE;
            MSXML::IXMLDOMNodeListPtr pChildren;
            pNode->get_childNodes(&pChildren);
            if (pChildren == NULL) {
                return FALSE;
            }

            int nCount = pChildren->Getlength();
            if (nCount < 1) {

                return FALSE;
            }

            for (long i=0; i<nCount; i++) {
                MSXML::IXMLDOMNodePtr pNode;
                pChildren->get_item(i, &pNode);
                CComBSTR bstrName;
                pNode->get_nodeName(&bstrName);

                COLE2T szName(bstrName);
                if(wcscmp(szName,pszNodeName) == 0) {
                    *ppChild = pNode.GetInterfacePtr();

                    if (*ppChild != NULL)
                        (*ppChild)->AddRef();
                    return TRUE;
                }
            }
        } catch (_com_error  &e) {
            SetLastError(e.Error());
            return FALSE;
        } catch(...)
		{
            return FALSE;
        }

        return FALSE;
    }

    BOOL GetChildNodeValue(MSXML::IXMLDOMNode* pNode,
                        LPCWSTR pszNodeName,
                        LPWSTR pszValue)
    {
        try {
            if (pNode == NULL || pszNodeName == NULL)
                return FALSE;

            MSXML::IXMLDOMNodePtr pChild;
            if (!GetChildNode(pNode, pszNodeName, &pChild)) {

                return FALSE;
            }

            CComVariant val;
            HRESULT hr = S_OK;
            if (pChild->hasChildNodes()) {
                MSXML::IXMLDOMNodePtr pText;
                pChild->get_firstChild(&pText);

                hr = pText->get_nodeValue(&val);

            } else {

                hr = pChild->get_nodeValue(&val);
            }

            if (FAILED(hr))
                return FALSE;

            if (val.vt != VT_NULL) {

                if (val.vt != VT_BSTR)
                    return FALSE;

                pszValue = COLE2T(val.bstrVal);
            }
        } catch (_com_error  &e) {
            SetLastError(e.Error());
            return FALSE;
        } catch(...) {
            return FALSE;
        }
        return TRUE;
    }

    BOOL AddChildNode(MSXML::IXMLDOMNode* pNode,
                LPCWSTR pszChildNodeName,
                short nNodeType,
                MSXML::IXMLDOMNode** ppChild
                )
    {

        try {
            if (ppChild == NULL)
                return FALSE;

            *ppChild = NULL;

            if (pNode == NULL || pszChildNodeName == NULL)
                return FALSE;

            MSXML::IXMLDOMDocumentPtr pDoc;
            MSXML::DOMNodeType type;
            pNode->get_nodeType(&type);
            if (type == MSXML::NODE_DOCUMENT)
                pDoc = pNode;
            else {
                pNode->get_ownerDocument(&pDoc);
                if (pDoc == NULL)
                    return FALSE;
            }

            _variant_t varType(nNodeType);
            _bstr_t varName(pszChildNodeName);

            MSXML::IXMLDOMNodePtr pNewNode = pDoc->createNode(varType, varName, L"");;
            *ppChild = pNewNode.GetInterfacePtr();

            if (*ppChild != NULL)
                (*ppChild)->AddRef();

            pNode->appendChild(*ppChild);
        } catch (_com_error  &e) {
            SetLastError(e.Error());
            return FALSE;
        } catch(...) {
            return FALSE;
        }
        return TRUE;
    }

    BOOL GetAttributeValue(MSXML::IXMLDOMNode* pNode,
                        LPCWSTR pszAttName,
                        VARIANT& var)
    {
        if (! pNode || !pszAttName)
            return FALSE;

        MSXML::IXMLDOMAttributePtr pAttr;
        if (!GetAttribute(pNode, pszAttName, &pAttr))
            return FALSE;

        HRESULT hr = pAttr->get_value(&var);
        return TRUE;
    }

    BOOL GetAttributeValue(MSXML::IXMLDOMNode* pNode,
                        LPCWSTR pszAttName,
                        long& lValue)
    {
        lValue = 0;

        if (pNode == NULL || pszAttName == NULL)
            return FALSE;

        MSXML::IXMLDOMAttributePtr pAttr;
        if (!GetAttribute(pNode, pszAttName, &pAttr))
            return FALSE;

        CComVariant val;
        HRESULT hr = pAttr->get_value(&val);

        if (val.vt == VT_BSTR) {
            lValue = _tstol(COLE2T(val.bstrVal));
        } else {
            lValue = val.lVal;
        }
        return TRUE;
    }

	template <size_t nSize> inline
		BOOL GetAttributeValue(MSXML::IXMLDOMNode* pNode,
		LPCWSTR pszAttName,
		WCHAR (&pszValue)[nSize])
	{
		return GetAttributeValue(pNode, pszAttName, pszValue, nSize);
	}

    BOOL GetAttributeValue(MSXML::IXMLDOMNode* pNode,
                        LPCWSTR pszAttName,
                        LPWSTR pszValue,
						size_t nSize)
    {
        if (pNode == NULL || pszAttName == NULL)
            return FALSE;

        MSXML::IXMLDOMAttributePtr pAttr;
        if (!GetAttribute(pNode, pszAttName, &pAttr))
            return FALSE;

        CComVariant val;
        HRESULT hr = pAttr->get_value(&val);

        CComBSTR bstr(val.bstrVal);
        COLE2T szValue(bstr);
        wcscpy_s(pszValue, nSize, szValue);
        return TRUE;
    }

    BOOL GetAttributeValue(MSXML::IXMLDOMNode* pNode,
                        LPCWSTR pszAttName,
        short& sValue)
    {
        try {
            sValue = 0;

            if (pNode == NULL || pszAttName == NULL)
                return FALSE;

            MSXML::IXMLDOMAttributePtr pAttr;
            if (!GetAttribute(pNode, pszAttName, &pAttr))
                return FALSE;

            CComVariant val;
            HRESULT hr = pAttr->get_value(&val);

            if(val.vt == VT_BSTR){
                sValue = _tstoi(COLE2T(val.bstrVal));
            } else {
                sValue = 0;
            }
        } catch (_com_error  &e) {
            SetLastError(e.Error());
            return FALSE;
        } catch(...) {
            return FALSE;
        }

        return TRUE;
    }

    BOOL GetAttributeValue(MSXML::IXMLDOMNode* pNode,
        LPCWSTR pszAttName,
                        double& fValue)
    {
        try {
            fValue = 0.0;

            if (pNode == NULL || pszAttName == NULL)
                return FALSE;

            MSXML::IXMLDOMAttributePtr pAttr;
            if (!GetAttribute(pNode, pszAttName, &pAttr))
                return FALSE;

            CComVariant val;
            HRESULT hr = pAttr->get_value(&val);

            if(val.vt == VT_BSTR){
                fValue = _tstof(CW2T(val.bstrVal));
            } else {
                fValue = 0.0;
            }
        } catch (_com_error  &e) {
            SetLastError(e.Error());
            return FALSE;
        } catch(...) {
            return FALSE;
        }
        return TRUE;
    }

    inline BOOL SetAttributeValue(MSXML::IXMLDOMNode* pNode,
                                LPCWSTR pszAttName,
                                double fValue)
    {
        MSXML::IXMLDOMElementPtr pElement = pNode;

        if (pNode == NULL || pElement == NULL || pszAttName == NULL)
            return FALSE;

        CComVariant var(fValue);
        HRESULT hr = pElement->setAttribute(pszAttName, var);

        return SUCCEEDED(hr);
    }

    virtual BOOL LoadPropertyValue(MSXML::IXMLDOMNode* pNode,
                                int index)
    {
        VARIANT vValue;
        VariantInit(&vValue);
        if(dispColor==index)
        {
            MSXML::IXMLDOMNodePtr pColorNode,pColorBookNode;

            if(GetChildNode(pNode, L"TrueColor",&pColorNode))
            {

                if(GetChildNode(pColorNode,L"ColorValue",&pColorBookNode))
                {

                    GetAttributeValue(pColorBookNode, L"Unspecified", (long&)m_bColorUnspecified);
                    long color;
                    GetAttributeValue(pColorBookNode, L"Color", color);
                    m_Color.setColor(color);
                }
                WCHAR sColorName[512]={_T("")},sColorBook[512]={_T("")};
                if(GetChildNode(pColorNode,_T("ColorName"),&pColorBookNode))

                    GetAttributeValue(pColorBookNode, _T("Color"), sColorName);
                if(GetChildNode(pColorNode,L"ColorBook",&pColorBookNode))

                    GetAttributeValue(pColorBookNode,L"Color",sColorBook);
                const WCHAR* pNullName = NULL;
                m_Color.setNames( wcslen(sColorName) ? sColorName : pNullName,
                    wcslen(sColorBook) ? sColorBook : pNullName);
            }
            return TRUE;
        }

        if(dispLayer == index)
            GetAttributeValue(pNode, L"Unspecified", (long&)m_bLayerUnspecified);

        GetAttributeValue(pNode,L"PropertyValue",vValue);

        PutToolProperty(index,vValue);
        return TRUE;
    }

    virtual BOOL SavePropertyValue(MSXML::IXMLDOMNode* pNode,
                                int index)
    {
        VARIANT vValue;
        VariantInit(&vValue);
        HRESULT hr=GetToolProperty(index,vValue);
        if(dispColor==index)
        {
            MSXML::IXMLDOMNodePtr pColorNode,pColorBookNode;
            if(!GetChildNode(pNode,L"TrueColor",&pColorNode))
                AddChildNode(pNode, L"TrueColor", MSXML::NODE_ELEMENT, &pColorNode);
            if (pColorNode == NULL)
                return FALSE;
            if(!GetChildNode(pColorNode,L"ColorValue",&pColorBookNode))
                AddChildNode(pColorNode, L"ColorValue", MSXML::NODE_ELEMENT, &pColorBookNode);
            SetAttributeValue(pColorBookNode, L"Unspecified", (long&)m_bColorUnspecified);
            long color=m_Color.color();
            SetAttributeValue(pColorBookNode, L"Color",color);

            LPWSTR pColorName = (LPWSTR)m_Color.colorName();
            if (pColorName)
            {

                if(!GetChildNode(pColorNode,L"ColorName",&pColorBookNode))
                    AddChildNode(pColorNode, L"ColorName", MSXML::NODE_ELEMENT, &pColorBookNode);
                SetAttributeValue(pColorBookNode,L"Color",pColorName);
            }

            LPWSTR pBookName = (LPWSTR)m_Color.bookName();
            if(pBookName)
            {

                if(!GetChildNode(pColorNode,L"ColorBook",&pColorBookNode))
                    AddChildNode(pColorNode, L"ColorBook",MSXML::NODE_ELEMENT, &pColorBookNode);
                SetAttributeValue(pColorBookNode,L"Color",pBookName);
            }
            return TRUE;
        }
        if(dispLayer==index)
            SetAttributeValue(pNode, L"Unspecified", (long)m_bLayerUnspecified);

        return SetAttributeValue(pNode,L"PropertyValue",vValue);
    }

    BOOL SetAttributeValue(MSXML::IXMLDOMNode* pNode,
                                LPCWSTR pszAttName,
                                long lValue)
    {
        MSXML::IXMLDOMElementPtr pElement = pNode;

        if (pNode == NULL || pElement == NULL || pszAttName == NULL)
            return FALSE;

        CComVariant var(lValue);
        HRESULT hr = pElement->setAttribute(pszAttName, var);

        return SUCCEEDED(hr);
    }

    BOOL SetAttributeValue(MSXML::IXMLDOMNode *pNode,
                                LPCWSTR pszAttName,
                                VARIANT& var)
    {
        MSXML::IXMLDOMElementPtr pElement = pNode;

        if (pNode == NULL || pElement == NULL || pszAttName == NULL)
            return FALSE;

        HRESULT hr = pElement->setAttribute(pszAttName, &var);

        return SUCCEEDED(hr);
    }

    BOOL SetAttributeValue(MSXML::IXMLDOMNode* pNode,
                                LPCWSTR pszAttName,
                                LPWSTR pszValue)
    {
        MSXML::IXMLDOMElementPtr pElement = pNode;

        if (pNode == NULL || pElement == NULL || pszAttName == NULL)
            return FALSE;

        CComVariant var(pszValue);
        HRESULT hr = pElement->setAttribute(pszAttName, var);

        return SUCCEEDED(hr);
    }
    BOOL RemoveChildren(MSXML::IXMLDOMNode* pNode)
    {
        try {
            if (pNode == NULL)
                return FALSE;

            MSXML::IXMLDOMNodeListPtr pChildren;
            HRESULT hr = pNode->get_childNodes(&pChildren);
            if ( FAILED(hr) || (pChildren == NULL))
                return FALSE;

            MSXML::IXMLDOMNodePtr pChildNode = pChildren->nextNode();
            for (; pChildNode != NULL; pChildNode = pChildren->nextNode()){
                MSXML::IXMLDOMNodePtr pRemove = pNode->removeChild(pChildNode);

                pRemove = NULL;
            }
        } catch (_com_error  &e) {
            SetLastError(e.Error());
            return FALSE;
        } catch(...) {
            return FALSE;
        }
        return TRUE;
    }
    ZcTcPalette *CreatePaletteATC(ZcTcCatalog *pCatalog,LPWSTR szPaletteName)
    {
        GUID guid;
        if(!SUCCEEDED(CoCreateGuid(&guid)))
            return NULL;
        ZcTcPalette *pPalette = new ZcTcPalette;
		try
		{
			if(!pPalette->SetID(&guid))
				throw 0;
			if(!pPalette->SetName(szPaletteName))
				throw 0;
			if(-1 == pCatalog->AddChild(pPalette))
				throw 0;
		}
		catch (int)
		{
			delete pPalette;
			return NULL;
		}
		try
		{
			if(!pCatalog->SetToolTipText(szPaletteName))
				throw 0;
			if(!pCatalog->SetDescription(szPaletteName))
				throw 0;
			if(!ZcTcGetManager()->SaveCatalogs())
				throw 0;
		}
		catch(int)
		{
			pCatalog->DeleteChild(pPalette);
			return NULL;
		}
        return pPalette;
    }

    ZcTcTool *CreateToolATC(ZcTcPackage *pPalette, LPCWSTR szToolNameOverride=NULL,
        LPCWSTR szToolImageOverride=NULL,
        BOOL bImageFile=FALSE)
    {
        GUID guid;

        if(!SUCCEEDED(CoCreateGuid(&guid)))
            return NULL;
        ZcTcTool* pTool = new ZcTcTool();
        try
		{
			if(!pTool->SetID(&guid))
				throw 0;
			if(!pTool->SetStockToolID(pclsid))
				throw 0;
			ZcTcImage image;
			HBITMAP hBitmap=NULL;
			if(szToolImageOverride)
			{
				if(bImageFile)
					hBitmap=(HBITMAP)::LoadImage(
					NULL, szToolImageOverride, IMAGE_BITMAP,
					0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
				else
					hBitmap=::LoadBitmap(_AtlBaseModule.GetResourceInstance(),szToolImageOverride);
			}
			else
				hBitmap=::LoadBitmap(_AtlBaseModule.GetResourceInstance(),szToolImage);
			image.Load(hBitmap);

			ZcTcImageList *pList=pTool->GetImageList();
			if(!pList)
				throw 0;

			pList->Add(&image);

			if(szToolNameOverride)
			{
				if(!pTool->SetName(szToolNameOverride))
					throw 0;
				if(!pTool->SetToolTipText(szToolNameOverride))
					throw 0;
				if(!pTool->SetDescription(szToolNameOverride))
					throw 0;
			}
			else
			{
				if(!pTool->SetName(szToolName))
					throw 0;
				if(!pTool->SetToolTipText(szToolName))
					throw 0;
				if(!pTool->SetDescription(szToolName))
					throw 0;
			}

			if(!pTool->SetToolType(ZcTc::kToolNormal))
				throw 0;
			IUnknown *pUnk=NULL;
			MSXML::IXMLDOMNode* pToolData;
			if(!pTool->GetToolData((IUnknown**)&pToolData))
				throw 0;
			if(!SUCCEEDED(GetPropertyTypeInfo()))
				throw 0;
			if(!SUCCEEDED(Save(pToolData)))
				throw 0;

			if(-1 == pPalette->AddChild(pTool))
				throw 0;

		}
		catch(int)
		{
			delete pTool;
			return NULL;
		}

		try
		{

			if(!ZcTcGetManager()->SaveCatalogs())
				throw 0;
			if(!ZcTcGetManager()->SaveCatalogs(ZcTc::kShapeCatalog))
				throw 0;
		}
		catch(int)
		{
			pPalette->DeleteChild(pTool);
			return NULL;
		}
        return pTool;
    }

    ZcTcTool *CreateFlyoutToolATC(ZcTcPackage *pPalette, ZcTcPackage *pShapePackage, LPCWSTR szToolNameOverride=NULL)
    {
        GUID toolGUID;
        ZcTcTool* pTool = new ZcTcTool();
		try
		{
			if(!SUCCEEDED(CoCreateGuid(&toolGUID)))
				throw 0;
			if(!pTool->SetID(&toolGUID))
				throw 0;
			if(!pTool->SetStockToolID(pclsid))
				throw 0;
			if(szToolNameOverride)
			{
				if(!pTool->SetName(szToolNameOverride))
					throw 0;
				if(!pTool->SetToolTipText(szToolNameOverride))
					throw 0;
				if(!pTool->SetDescription(szToolNameOverride))
					throw 0;
			}
			else
			{
				if(!pTool->SetName(szToolName))
					throw 0;
				if(!pTool->SetToolTipText(szToolName))
					throw 0;
				if(!pTool->SetDescription(szToolName))
					throw 0;
			}

			if(!pTool->SetToolType(ZcTc::kToolFlyout))
				throw 0;
			if(!pTool->EnableFlyout(TRUE))
				throw 0;

			if(!pTool->SetShapePackage(pShapePackage))
				throw 0;
			IUnknown *pUnk=NULL;
			MSXML::IXMLDOMNode* pToolData;
			if(!pTool->GetToolData((IUnknown**)&pToolData))
				throw 0;
			if(!SUCCEEDED(GetPropertyTypeInfo()))
				throw 0;
			if(!SUCCEEDED(Save(pToolData)))
				throw 0;

			if(-1 == pPalette->AddChild(pTool))
				throw 0;
		}
		catch(int)
		{
			delete pTool;
			return NULL;
		}
		try
		{
			if(!ZcTcGetManager()->SaveCatalogs())
				throw 0;
			if(!ZcTcGetManager()->SaveCatalogs(ZcTc::kShapeCatalog))
				throw 0;
		}
		catch(int)
		{
			pPalette->DeleteChild(pTool);
			return NULL;
		}
        return pTool;
    }

    ZcTcTool *CreateCommandToolATC(ZcTcPackage *pPalette,LPWSTR szToolName,LPCWSTR szBitmapName, LPWSTR macroString)
    {
        GUID guid;
        BOOL bResult;

        ZcTcTool *pTool = new ZcTcTool();
		try
		{
			if(!SUCCEEDED(CoCreateGuid(&guid)))
				throw 0;
			if(!pTool->SetID(&guid))
				throw 0;

			const GUID GenericStockToolId = {0x2ae7120b,0xcee4,0x47a5,{0x9b,0x50,0xef,0x9f,0x3a,0xde,0x24,0xac}};
			if(!pTool->SetStockToolID(&GenericStockToolId))
				throw 0;
			if(!pTool->SetName(szToolName))
				throw 0;
			ZcTcImage image;
			ZcTcImageList *pList=pTool->GetImageList();
			if(!pList)
				throw 0;

			HBITMAP hBitmap=::LoadBitmap(_AtlBaseModule.GetResourceInstance(),szBitmapName);

			bResult=image.Load(hBitmap);
			pList->Add(&image);
			CComPtr<IUnknown>pToolDataUnk;
			MSXML::IXMLDOMNodePtr pToolData;
			if(pTool->GetToolData(&pToolDataUnk))
			{
				CComQIPtr<MSXML::IXMLDOMNode> pToolData=pToolDataUnk;
				RemoveChildren(pToolData);
				MSXML::IXMLDOMNodePtr pNode,pNodeText;
				if(TRUE == AddChildNode(pToolData, L"Macro", MSXML::NODE_ELEMENT, &pNode))
					if(TRUE == AddChildNode(pNode, L"", MSXML::NODE_CDATA_SECTION, &pNodeText))
						pNodeText->put_text(CComBSTR(macroString));
			}
			else
				throw 0;

			if(-1 == pPalette->AddChild(pTool))
				throw 0;
		}
		catch(int)
		{
			delete pTool;
			return NULL;
		}
        try
		{
			if(!ZcTcGetManager()->SaveCatalogs())
				throw 0;
			if(!ZcTcGetManager()->SaveCatalogs(ZcTc::kShapeCatalog))
				throw 0;
		}
		catch(int)
		{
			pPalette->DeleteChild(pTool);
			return NULL;
		}
        return pTool;
    }

    ZcTcCatalog *CreateStockToolATC(LPWSTR szCatalogName)
    {

        CZcModuleResourceOverride resourceOverride;

        GUID guid;
        ZcTcStockTool *pStockTool=new ZcTcStockTool;
		ZcTcCatalog *pStockToolCatalog=new ZcTcCatalog;
		try
		{
			if(!pStockTool->SetID(pclsid))
				throw 0;

			if(!pStockTool->SetComClassID(*pclsid))
				throw 0;
			WCHAR modulePath[MAX_PATH];
			HINSTANCE hInst=_AtlBaseModule.GetResourceInstance();
			HMODULE moduleHandle=hInst;
			if(!moduleHandle)
				throw 0;
			GetModuleFileName(hInst,modulePath,MAX_PATH);
			if(!pStockTool->SetModuleFileName(modulePath))
				throw 0;
			if(-1 == pStockToolCatalog->AddChild(pStockTool))
				throw 0;
			else
				pStockTool = nullptr;

			if(-1 == ZcTcGetManager()->AddStockToolCatalog(pStockToolCatalog))
				throw 0;
		}
		catch(int)
		{
			delete pStockToolCatalog;
			delete pStockTool;
			return NULL;
		}
		ZcTcCatalog *pCatalog=new ZcTcCatalog;
		try
		{

			if(!SUCCEEDED(CoCreateGuid(&guid)))
				throw 0;
			if(!pCatalog->SetID(&guid))
				throw 0;
			if(!pCatalog->SetName(szCatalogName))
				throw 0;

			if(-1 ==ZcTcGetManager()->AddCatalog(pCatalog))
				throw 0;

			if(!ZcTcGetManager()->SaveCatalogs())
				throw 0;
			if(!ZcTcGetManager()->SaveCatalogs(ZcTc::kStockToolCatalog))
				throw 0;
		}

		catch(int)
		{
			delete pStockToolCatalog;
			delete pCatalog;
			return NULL;
		}

        return pCatalog;
    }

    ZcTcPackage *CreateShapeCatalogATC(LPWSTR szShapeName)
    {
        ZcTcManager *pManager = ZcTcGetManager();
        ZcTcCatalog *pShapesCatalog = NULL;
        if(pManager)
        {
            pShapesCatalog = (ZcTcCatalog *)pManager->GetShapeCatalog();
            if(!pShapesCatalog)
                return NULL;
        }
        else
            return NULL;

        ZcTcPackage *pPackage=GetCustomShapePackage(pShapesCatalog,szShapeName);
        if (NULL==pPackage)
        {
            pPackage = new ZcTcPackage;
            try
			{
				if(!pPackage->SetName(szShapeName))
					throw 0;
				GUID shapeGuid;
				if(!SUCCEEDED(CoCreateGuid(&shapeGuid)))
					throw 0;
				if(!pPackage->SetID(&shapeGuid))
					throw 0;
				if(-1 == pShapesCatalog->AddChild(pPackage))
					throw 0;
			}
			catch(int)
			{
				delete pPackage;
				return NULL;
			}
        }
        if(!ZcTcGetManager()->SaveCatalogs(ZcTc::kShapeCatalog))
		{
			pShapesCatalog->DeleteChild(pPackage);
			return NULL;
		}
        return pPackage;
    }

    IZcadToolProperties* GetThisToolsProperties()
    {
        ZcadToolImpl<TT,T,pclsid,szToolName,szToolImage>* pThisTool=(ZcadToolImpl<TT,T,pclsid,szToolName,szToolImage>*)pZcadToolImpl;

        CComQIPtr<IZcadTool> pZcadTool(pThisTool);
        if (!pZcadTool)
            return NULL;

        CComPtr<IUnknown> pUnkToolProp;
        HRESULT hr = pZcadTool->GetToolProperties(&pUnkToolProp);
        if (FAILED(hr))
            return NULL;

        CComQIPtr<IZcadToolProperties> pToolProp(pUnkToolProp);
        if(!pToolProp)
            return NULL;

        return pToolProp;
    }

    ZcTcPackage* GetCustomShapePackage(ZcTcCatalog *pCatalog,
                            LPCWSTR szPackageName)
    {
        if(!pCatalog)
            return NULL;
        ZcTcPackage *pPackage = NULL;
        for(int i=0;i<pCatalog->GetChildCount();i++)
        {
            pPackage=(ZcTcPackage *)pCatalog->GetChild(i);
            if(pPackage)
            {
                WCHAR szPackageNameEnum[128];
                pPackage->GetName(szPackageNameEnum,128);
                if(!wcscmp(szPackageName,szPackageNameEnum))
                    return pPackage;
            }
        }
        return NULL;
    }
    ZcTcPackage* GetCustomShapePackage(ZcTcCatalog *pCatalog,
                            GUID szPackageID)
    {
        if(!pCatalog)
            return NULL;
        ZcTcPackage *pPackage = NULL;
        for(int i=0;i<pCatalog->GetChildCount();i++)
        {
            pPackage=(ZcTcPackage *)pCatalog->GetChild(i);
            if(pPackage)
            {
                GUID szPackageIdEnum;
                pPackage->GetID(szPackageIdEnum);
                if(IsEqualGuid(szPackageId,szPackageIdEnum))
                    return pPackage;
            }
        }
        return NULL;
    }
};


