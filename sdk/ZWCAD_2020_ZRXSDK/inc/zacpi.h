
#pragma warning( disable: 4049 )
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif

#ifndef __ZcPi_h__
#define __ZcPi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif
#ifndef __IZcPiPropertyInspector_FWD_DEFINED__
#define __IZcPiPropertyInspector_FWD_DEFINED__
typedef interface IZcPiPropertyInspector IZcPiPropertyInspector;
#endif
#ifndef __IZcPiPropertyEditControl_FWD_DEFINED__
#define __IZcPiPropertyEditControl_FWD_DEFINED__
typedef interface IZcPiPropertyEditControl IZcPiPropertyEditControl;
#endif
#ifndef __IZcPiPropertyEditEventsSink_FWD_DEFINED__
#define __IZcPiPropertyEditEventsSink_FWD_DEFINED__
typedef interface IZcPiPropertyEditEventsSink IZcPiPropertyEditEventsSink;
#endif
#ifndef __IZcPiPropertyUnspecified_FWD_DEFINED__
#define __IZcPiPropertyUnspecified_FWD_DEFINED__
typedef interface IZcPiPropertyUnspecified IZcPiPropertyUnspecified;
#endif
#ifndef __IZcPiPropertyDisplay_FWD_DEFINED__
#define __IZcPiPropertyDisplay_FWD_DEFINED__
typedef interface IZcPiPropertyDisplay IZcPiPropertyDisplay;
#endif
#ifndef __IZcPiCategorizeProperties_FWD_DEFINED__
#define __IZcPiCategorizeProperties_FWD_DEFINED__
typedef interface IZcPiCategorizeProperties IZcPiCategorizeProperties;
#endif
#ifndef __IZcPiPropCommandButtons_FWD_DEFINED__
#define __IZcPiPropCommandButtons_FWD_DEFINED__
typedef interface IZcPiPropCommandButtons IZcPiPropCommandButtons;
#endif
#ifndef __IZcPiCommandButton_FWD_DEFINED__
#define __IZcPiCommandButton_FWD_DEFINED__
typedef interface IZcPiCommandButton IZcPiCommandButton;
#endif
#ifndef __IZcPiCommandButton2_FWD_DEFINED__
#define __IZcPiCommandButton2_FWD_DEFINED__
typedef interface IZcPiCommandButton2 IZcPiCommandButton2;
#endif
#ifndef __IZcPiPropertyInspectorEventsSink_FWD_DEFINED__
#define __IZcPiPropertyInspectorEventsSink_FWD_DEFINED__
typedef interface IZcPiPropertyInspectorEventsSink IZcPiPropertyInspectorEventsSink;
#endif
#ifndef __IZcPiPropertyInspectorInputEventSink_FWD_DEFINED__
#define __IZcPiPropertyInspectorInputEventSink_FWD_DEFINED__
typedef interface IZcPiPropertyInspectorInputEventSink IZcPiPropertyInspectorInputEventSink;
#endif
#ifndef __IZcPiPropertyInspectorTheme_FWD_DEFINED__
#define __IZcPiPropertyInspectorTheme_FWD_DEFINED__
typedef interface IZcPiPropertyInspectorTheme IZcPiPropertyInspectorTheme;
#endif


#ifndef __ZcPiPropertyInspector_FWD_DEFINED__
#define __ZcPiPropertyInspector_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPiPropertyInspector ZcPiPropertyInspector;
#else
typedef struct ZcPiPropertyInspector ZcPiPropertyInspector;
#endif

#endif
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif





#define ZCPI_DEFAULT             0x00000000
#define ZCPI_CLEARCACHE_REFRESH  0x00000001
#define ZCPI_CLEARCACHE_DYNAMIC  0x00000002
#define ZCPI_CLEARCACHE_INCLUDED 0x00000004
#define ZCPI_ZCAD_DYN            0x00000008
#define ZCPI_UNION               0x00000010
#define ZCPI_SORTBYNAME          0x00000020
#define ZCPI_SORTBYWEIGHT        0x00000040
#define ZCPI_REFRESH             0x00000080
#define ZCPI_FILTERABLE          0x00000100
#define ZCPI_EMPTYDISPLAY        0x00000200
#define ZCPI_SETCONTROLFOCUS     0x00000001
#define ZCPI_SCROLLTOCONTROL     0x00000002
#define     ZC_TVS_TOOLTIPS             0x00000001
#define     ZC_TVS_GRIDLINES            0x00000002
#define     ZC_TVS_SELHIGHLIGHT         0x00000004
#define     ZC_TVS_GRIDMARKER           0x00000008
#define     ZC_TVS_GRIDROUNDSTYLE       0x00000010
#define     ZC_TVS_GRIDSTATUSBAR        0x00000020
#define     ZC_TVS_GRIDSCROLLRIGHT      0x00000040
#define     ZC_TVS_CALCULATOR           0x00000080
#define     ZC_TVS_NOGRIDINDENTATION    0x00000100
#define     ZC_TVS_NOCATEGORIES         0x00000200
#define     ZC_TVS_NOCONTEXTMENU        0x00000400
#define     ZC_TVS_GRIDGRADIENTSTYLE    0x00000800

#define     ZC_TVS_GRID                 ((ZC_TVS_SELHIGHLIGHT) | (ZC_TVS_GRIDSTATUSBAR) | (ZC_TVS_GRIDLINES) | (ZC_TVS_TOOLTIPS) | (ZC_TVS_GRIDROUNDSTYLE))
#define DISPID_READONLYBACKCOLOR -2000
#define DISPID_READONLYFORECOLOR -2001
#define DISPID_RBUTTONDOWN -2030
#define DISPID_MBUTTONDOWN -2031
#define DISPID_CHECKED -2010
#define DISPID_BEGINPROPERTYUPDATE -2002
#define DISPID_ENDPROPERTYUPDATE -2003
typedef   DECLSPEC_UUID("EC9231D3-5A17-11E7-B72E-BC5FF42AC839")
enum ZcPiColorIndex
    {
        ZCPI_COLOR_TOP	= 0,
        ZCPI_COLOR_CATEGORY	= 0x1,
        ZCPI_COLOR_ITEM	= 0x2,
        ZCPI_COLOR_BORDER	= 0x3,
        ZCPI_COLOR_BORDER_ITEM	= 0x4,
        ZCPI_COLOR_TEXT_TOP	= 0x5,
        ZCPI_COLOR_TEXT_CATEGORY	= 0x6,
        ZCPI_COLOR_TEXT_ITEM	= 0x7,
        ZCPI_COLOR_FORE_HIGHLIGHT	= 0x8,
        ZCPI_COLOR_BACK_HIGHLIGHT	= 0x9,
        ZCPI_COLOR_3DSHADOW	= 0xa,
        ZCPI_COLOR_BACK_CONTROL	= 0xb,
        ZCPI_COLOR_SCROLLBACKGROUND	= 0xc,
        ZCPI_COLOR_SCROLLTHUMB	= 0xd,
        ZCPI_COLOR_SCROLLARROW	= 0xe,
        ZCPI_COLOR_DOUBLECHEVRON1	= 0xf,
        ZCPI_COLOR_DOUBLECHEVRON2	= 0x10,
        ZCPI_COLOR_SINGLECHEVRON	= 0x11,
        ZCPI_COLOR_TOP_GRADIENT1	= 0x12,
        ZCPI_COLOR_TOP_GRADIENT2	= 0x13,
        ZCPI_COLOR_TOP_CLOSED_OUTER_BORDER	= 0x14,
        ZCPI_COLOR_TOP_OPEN_OUTER_BORDER	= 0x15,
        ZCPI_COLOR_TOP_INNER_BORDER	= 0x16,
        ZCPI_COLOR_SCROLL_BACKGROUNDBORDER	= 0x17,
        ZCPI_COLOR_SCROLL_BACKGROUNDGRADIENT1	= 0x18,
        ZCPI_COLOR_SCROLL_BACKGROUNDGRADIENT2	= 0x19,
        ZCPI_COLOR_SCROLL_SLIDER_INACTIVE	= 0x1a,
        ZCPI_COLOR_SCROLL_SLIDER_ACTIVE_OUTERBORDER	= 0x1b,
        ZCPI_COLOR_SCROLL_SLIDER_ACTIVE_OUTERGRADIENT1	= 0x1c,
        ZCPI_COLOR_SCROLL_SLIDER_ACTIVE_OUTERGRADIENT2	= 0x1d,
        ZCPI_COLOR_SCROLL_SLIDER_ACTIVE_OUTERGRADIENT3	= 0x1e,
        ZCPI_COLOR_SCROLL_SLIDER_ACTIVE_OUTERGRADIENT4	= 0x1f,
        ZCPI_COLOR_SCROLL_SLIDER_ACTIVE_INNERGRADIENT1	= 0x20,
        ZCPI_COLOR_SCROLL_SLIDER_ACTIVE_INNERGRADIENT2	= 0x21,
        ZCPI_COLOR_TEXT_LABEL	= 0x22,
        ZCPI_COLOR_CELL_HIGHLIGHT	= 0x23,
        ZCPI_COLOR_DISABLED_TEXT_ITEM	= 0x24
    } 	ZcPiColorIndex;

#define IPropertyInspector IZcPiPropertyInspector
#define IID_IPropertyInspector IID_IZcPiPropertyInspector
#define CLSID_PropertyInspector CLSID_ZcPiPropertyInspector
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0000_v0_0_s_ifspec;

#ifndef __IZcPiPropertyInspector_INTERFACE_DEFINED__
#define __IZcPiPropertyInspector_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPiPropertyInspector;

#if defined(__cplusplus) && !defined(CINTERFACE)
  
    MIDL_INTERFACE("EC92316D-5A17-11E7-B72E-BC5FF42AC839")
    IZcPiPropertyInspector : public IDispatch
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE Reset(
             VARIANT *pObjUnkArray,
             VARIANT *pDynUnkArray,
             DWORD dwFlags) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_Style(
             DWORD *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_Style(
             DWORD newVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_KeepFocus(
             VARIANT_BOOL *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE SetColor(
             ZcPiColorIndex index,
             OLE_COLOR color) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetColor(
             ZcPiColorIndex __MIDL__IZcPiPropertyInspector0000,
             OLE_COLOR *pColor) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_Font(
             IUnknown **pIFont) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_Font(
             IUnknown *pIFont) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_BoldFont(
             IUnknown **pIFont) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_BoldFont(
             IUnknown *pIFont) = 0;

        virtual  HRESULT STDMETHODCALLTYPE SetPersistence(
             IUnknown *pINode) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetPersistence(
             IUnknown *pINode) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_DelayRefresh(
             VARIANT_BOOL *pbDelayRefresh) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_DelayRefresh(
             VARIANT_BOOL bDelayRefresh) = 0;

    };

#else

    typedef struct IZcPiPropertyInspectorVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPiPropertyInspector * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPiPropertyInspector * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPiPropertyInspector * This);

        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )(
            IZcPiPropertyInspector * This,
             UINT *pctinfo);

        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )(
            IZcPiPropertyInspector * This,
             UINT iTInfo,
             LCID lcid,
             ITypeInfo **ppTInfo);

        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )(
            IZcPiPropertyInspector * This,
             REFIID riid,
             LPOLESTR *rgszNames,
             UINT cNames,
             LCID lcid,
             DISPID *rgDispId);

         HRESULT ( STDMETHODCALLTYPE *Invoke )(
            IZcPiPropertyInspector * This,
             DISPID dispIdMember,
             REFIID riid,
             LCID lcid,
             WORD wFlags,
             DISPPARAMS *pDispParams,
             VARIANT *pVarResult,
             EXCEPINFO *pExcepInfo,
             UINT *puArgErr);

         HRESULT ( STDMETHODCALLTYPE *Reset )(
            IZcPiPropertyInspector * This,
             VARIANT *pObjUnkArray,
             VARIANT *pDynUnkArray,
             DWORD dwFlags);

         HRESULT ( STDMETHODCALLTYPE *get_Style )(
            IZcPiPropertyInspector * This,
             DWORD *pVal);

         HRESULT ( STDMETHODCALLTYPE *put_Style )(
            IZcPiPropertyInspector * This,
             DWORD newVal);

         HRESULT ( STDMETHODCALLTYPE *get_KeepFocus )(
            IZcPiPropertyInspector * This,
             VARIANT_BOOL *pVal);

         HRESULT ( STDMETHODCALLTYPE *SetColor )(
            IZcPiPropertyInspector * This,
             ZcPiColorIndex index,
             OLE_COLOR color);

         HRESULT ( STDMETHODCALLTYPE *GetColor )(
            IZcPiPropertyInspector * This,
             ZcPiColorIndex __MIDL__IZcPiPropertyInspector0000,
             OLE_COLOR *pColor);

         HRESULT ( STDMETHODCALLTYPE *get_Font )(
            IZcPiPropertyInspector * This,
             IUnknown **pIFont);

         HRESULT ( STDMETHODCALLTYPE *put_Font )(
            IZcPiPropertyInspector * This,
             IUnknown *pIFont);

         HRESULT ( STDMETHODCALLTYPE *get_BoldFont )(
            IZcPiPropertyInspector * This,
             IUnknown **pIFont);

         HRESULT ( STDMETHODCALLTYPE *put_BoldFont )(
            IZcPiPropertyInspector * This,
             IUnknown *pIFont);

         HRESULT ( STDMETHODCALLTYPE *SetPersistence )(
            IZcPiPropertyInspector * This,
             IUnknown *pINode);

         HRESULT ( STDMETHODCALLTYPE *GetPersistence )(
            IZcPiPropertyInspector * This,
             IUnknown *pINode);

         HRESULT ( STDMETHODCALLTYPE *get_DelayRefresh )(
            IZcPiPropertyInspector * This,
             VARIANT_BOOL *pbDelayRefresh);

         HRESULT ( STDMETHODCALLTYPE *put_DelayRefresh )(
            IZcPiPropertyInspector * This,
             VARIANT_BOOL bDelayRefresh);

        END_INTERFACE
    } IZcPiPropertyInspectorVtbl;

    interface IZcPiPropertyInspector
    {
        CONST_VTBL struct IZcPiPropertyInspectorVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPiPropertyInspector_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPiPropertyInspector_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPiPropertyInspector_Release(This)	\
    ((This)->lpVtbl -> Release(This))
#define IZcPiPropertyInspector_GetTypeInfoCount(This,pctinfo)	\
    ((This)->lpVtbl -> GetTypeInfoCount(This,pctinfo))

#define IZcPiPropertyInspector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ((This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo))

#define IZcPiPropertyInspector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ((This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId))

#define IZcPiPropertyInspector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ((This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr))
#define IZcPiPropertyInspector_Reset(This,pObjUnkArray,pDynUnkArray,dwFlags)	\
    ((This)->lpVtbl -> Reset(This,pObjUnkArray,pDynUnkArray,dwFlags))

#define IZcPiPropertyInspector_get_Style(This,pVal)	\
    ((This)->lpVtbl -> get_Style(This,pVal))

#define IZcPiPropertyInspector_put_Style(This,newVal)	\
    ((This)->lpVtbl -> put_Style(This,newVal))

#define IZcPiPropertyInspector_get_KeepFocus(This,pVal)	\
    ((This)->lpVtbl -> get_KeepFocus(This,pVal))

#define IZcPiPropertyInspector_SetColor(This,index,color)	\
    ((This)->lpVtbl -> SetColor(This,index,color))

#define IZcPiPropertyInspector_GetColor(This,__MIDL__IZcPiPropertyInspector0000,pColor)	\
    ((This)->lpVtbl -> GetColor(This,__MIDL__IZcPiPropertyInspector0000,pColor))

#define IZcPiPropertyInspector_get_Font(This,pIFont)	\
    ((This)->lpVtbl -> get_Font(This,pIFont))

#define IZcPiPropertyInspector_put_Font(This,pIFont)	\
    ((This)->lpVtbl -> put_Font(This,pIFont))

#define IZcPiPropertyInspector_get_BoldFont(This,pIFont)	\
    ((This)->lpVtbl -> get_BoldFont(This,pIFont))

#define IZcPiPropertyInspector_put_BoldFont(This,pIFont)	\
    ((This)->lpVtbl -> put_BoldFont(This,pIFont))

#define IZcPiPropertyInspector_SetPersistence(This,pINode)	\
    ((This)->lpVtbl -> SetPersistence(This,pINode))

#define IZcPiPropertyInspector_GetPersistence(This,pINode)	\
    ((This)->lpVtbl -> GetPersistence(This,pINode))

#define IZcPiPropertyInspector_get_DelayRefresh(This,pbDelayRefresh)	\
    ((This)->lpVtbl -> get_DelayRefresh(This,pbDelayRefresh))

#define IZcPiPropertyInspector_put_DelayRefresh(This,bDelayRefresh)	\
    ((This)->lpVtbl -> put_DelayRefresh(This,bDelayRefresh))

#endif


#endif 	




#endif 	



#define IPropertyEditControl IZcPiPropertyEditControl
#define IID_IPropertyEditControl IID_IZcPiPropertyEditControl
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0001_v0_0_s_ifspec;

#ifndef __IZcPiPropertyEditControl_INTERFACE_DEFINED__
#define __IZcPiPropertyEditControl_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPiPropertyEditControl;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EC92308E-5A17-11E7-B72E-BC5FF42AC839")
    IZcPiPropertyEditControl : public IDispatch
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE InitEditControl(
             LPVARIANT pVarObjDispArray,
             LPVARIANT pVarDynPropArray,
             LPVARIANT pDispidArray,
             VARIANT_BOOL bReadOnly) = 0;

        virtual  HRESULT STDMETHODCALLTYPE Refresh(
             DWORD dwFlags) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_KeepFocus(
             VARIANT_BOOL *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_BackColor(
             OLE_COLOR clr) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_BackColor(
             OLE_COLOR *pclr) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_ForeColor(
             OLE_COLOR clr) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_ForeColor(
             OLE_COLOR *pclr) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_ReadOnlyBackColor(
             OLE_COLOR clr) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_ReadOnlyBackColor(
             OLE_COLOR *pclr) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_ReadOnlyForeColor(
             OLE_COLOR clr) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_ReadOnlyForeColor(
             OLE_COLOR *pclr) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_Font(
             IUnknown *pIFont) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_Font(
             IUnknown **pIFont) = 0;

    };

#else

    typedef struct IZcPiPropertyEditControlVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPiPropertyEditControl * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPiPropertyEditControl * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPiPropertyEditControl * This);

        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )(
            IZcPiPropertyEditControl * This,
             UINT *pctinfo);

        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )(
            IZcPiPropertyEditControl * This,
             UINT iTInfo,
             LCID lcid,
             ITypeInfo **ppTInfo);

        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )(
            IZcPiPropertyEditControl * This,
             REFIID riid,
             LPOLESTR *rgszNames,
             UINT cNames,
             LCID lcid,
             DISPID *rgDispId);

         HRESULT ( STDMETHODCALLTYPE *Invoke )(
            IZcPiPropertyEditControl * This,
             DISPID dispIdMember,
             REFIID riid,
             LCID lcid,
             WORD wFlags,
             DISPPARAMS *pDispParams,
             VARIANT *pVarResult,
             EXCEPINFO *pExcepInfo,
             UINT *puArgErr);

         HRESULT ( STDMETHODCALLTYPE *InitEditControl )(
            IZcPiPropertyEditControl * This,
             LPVARIANT pVarObjDispArray,
             LPVARIANT pVarDynPropArray,
             LPVARIANT pDispidArray,
             VARIANT_BOOL bReadOnly);

         HRESULT ( STDMETHODCALLTYPE *Refresh )(
            IZcPiPropertyEditControl * This,
             DWORD dwFlags);

         HRESULT ( STDMETHODCALLTYPE *get_KeepFocus )(
            IZcPiPropertyEditControl * This,
             VARIANT_BOOL *pVal);

         HRESULT ( STDMETHODCALLTYPE *put_BackColor )(
            IZcPiPropertyEditControl * This,
             OLE_COLOR clr);

         HRESULT ( STDMETHODCALLTYPE *get_BackColor )(
            IZcPiPropertyEditControl * This,
             OLE_COLOR *pclr);

         HRESULT ( STDMETHODCALLTYPE *put_ForeColor )(
            IZcPiPropertyEditControl * This,
             OLE_COLOR clr);

         HRESULT ( STDMETHODCALLTYPE *get_ForeColor )(
            IZcPiPropertyEditControl * This,
             OLE_COLOR *pclr);

         HRESULT ( STDMETHODCALLTYPE *put_ReadOnlyBackColor )(
            IZcPiPropertyEditControl * This,
             OLE_COLOR clr);

         HRESULT ( STDMETHODCALLTYPE *get_ReadOnlyBackColor )(
            IZcPiPropertyEditControl * This,
             OLE_COLOR *pclr);

         HRESULT ( STDMETHODCALLTYPE *put_ReadOnlyForeColor )(
            IZcPiPropertyEditControl * This,
             OLE_COLOR clr);

         HRESULT ( STDMETHODCALLTYPE *get_ReadOnlyForeColor )(
            IZcPiPropertyEditControl * This,
             OLE_COLOR *pclr);

         HRESULT ( STDMETHODCALLTYPE *put_Font )(
            IZcPiPropertyEditControl * This,
             IUnknown *pIFont);

         HRESULT ( STDMETHODCALLTYPE *get_Font )(
            IZcPiPropertyEditControl * This,
             IUnknown **pIFont);

        END_INTERFACE
    } IZcPiPropertyEditControlVtbl;

    interface IZcPiPropertyEditControl
    {
        CONST_VTBL struct IZcPiPropertyEditControlVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPiPropertyEditControl_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPiPropertyEditControl_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPiPropertyEditControl_Release(This)	\
    ((This)->lpVtbl -> Release(This))


#define IZcPiPropertyEditControl_GetTypeInfoCount(This,pctinfo)	\
    ((This)->lpVtbl -> GetTypeInfoCount(This,pctinfo))

#define IZcPiPropertyEditControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ((This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo))

#define IZcPiPropertyEditControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ((This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId))

#define IZcPiPropertyEditControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ((This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr))


#define IZcPiPropertyEditControl_InitEditControl(This,pVarObjDispArray,pVarDynPropArray,pDispidArray,bReadOnly)	\
    ((This)->lpVtbl -> InitEditControl(This,pVarObjDispArray,pVarDynPropArray,pDispidArray,bReadOnly))

#define IZcPiPropertyEditControl_Refresh(This,dwFlags)	\
    ((This)->lpVtbl -> Refresh(This,dwFlags))

#define IZcPiPropertyEditControl_get_KeepFocus(This,pVal)	\
    ((This)->lpVtbl -> get_KeepFocus(This,pVal))

#define IZcPiPropertyEditControl_put_BackColor(This,clr)	\
    ((This)->lpVtbl -> put_BackColor(This,clr))

#define IZcPiPropertyEditControl_get_BackColor(This,pclr)	\
    ((This)->lpVtbl -> get_BackColor(This,pclr))

#define IZcPiPropertyEditControl_put_ForeColor(This,clr)	\
    ((This)->lpVtbl -> put_ForeColor(This,clr))

#define IZcPiPropertyEditControl_get_ForeColor(This,pclr)	\
    ((This)->lpVtbl -> get_ForeColor(This,pclr))

#define IZcPiPropertyEditControl_put_ReadOnlyBackColor(This,clr)	\
    ((This)->lpVtbl -> put_ReadOnlyBackColor(This,clr))

#define IZcPiPropertyEditControl_get_ReadOnlyBackColor(This,pclr)	\
    ((This)->lpVtbl -> get_ReadOnlyBackColor(This,pclr))

#define IZcPiPropertyEditControl_put_ReadOnlyForeColor(This,clr)	\
    ((This)->lpVtbl -> put_ReadOnlyForeColor(This,clr))

#define IZcPiPropertyEditControl_get_ReadOnlyForeColor(This,pclr)	\
    ((This)->lpVtbl -> get_ReadOnlyForeColor(This,pclr))

#define IZcPiPropertyEditControl_put_Font(This,pIFont)	\
    ((This)->lpVtbl -> put_Font(This,pIFont))

#define IZcPiPropertyEditControl_get_Font(This,pIFont)	\
    ((This)->lpVtbl -> get_Font(This,pIFont))

#endif
#endif






#endif 	



#define IPropEditUIEventsSink IZcPiPropertyEditEventsSink
#define IID_IPropEditUIEventsSink IID_IZcPiPropertyEditEventsSink
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0002_v0_0_s_ifspec;

#ifndef __IZcPiPropertyEditEventsSink_INTERFACE_DEFINED__
#define __IZcPiPropertyEditEventsSink_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPiPropertyEditEventsSink;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EC923153-5A17-11E7-B72E-BC5FF42AC839")
    IZcPiPropertyEditEventsSink : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE OnClick( void) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnDblClick( void) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnKeyDown(
             LONG_PTR pnChar,
             LONG_PTR keyData) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnKeyUp(
             LONG_PTR pnChar,
             LONG_PTR keyData) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnRButtonDown(
             WPARAM wParam,
             LPARAM lParam) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnMButtonDown(
             WPARAM wParam,
             LPARAM lParam) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnBeginPropertyUpdate( void) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnEndPropertyUpdate( void) = 0;

    };

#else

    typedef struct IZcPiPropertyEditEventsSinkVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPiPropertyEditEventsSink * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPiPropertyEditEventsSink * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPiPropertyEditEventsSink * This);

         HRESULT ( STDMETHODCALLTYPE *OnClick )(
            IZcPiPropertyEditEventsSink * This);

         HRESULT ( STDMETHODCALLTYPE *OnDblClick )(
            IZcPiPropertyEditEventsSink * This);

         HRESULT ( STDMETHODCALLTYPE *OnKeyDown )(
            IZcPiPropertyEditEventsSink * This,
             LONG_PTR pnChar,
             LONG_PTR keyData);

         HRESULT ( STDMETHODCALLTYPE *OnKeyUp )(
            IZcPiPropertyEditEventsSink * This,
             LONG_PTR pnChar,
             LONG_PTR keyData);

         HRESULT ( STDMETHODCALLTYPE *OnRButtonDown )(
            IZcPiPropertyEditEventsSink * This,
             WPARAM wParam,
             LPARAM lParam);

         HRESULT ( STDMETHODCALLTYPE *OnMButtonDown )(
            IZcPiPropertyEditEventsSink * This,
             WPARAM wParam,
             LPARAM lParam);

         HRESULT ( STDMETHODCALLTYPE *OnBeginPropertyUpdate )(
            IZcPiPropertyEditEventsSink * This);

         HRESULT ( STDMETHODCALLTYPE *OnEndPropertyUpdate )(
            IZcPiPropertyEditEventsSink * This);

        END_INTERFACE
    } IZcPiPropertyEditEventsSinkVtbl;

    interface IZcPiPropertyEditEventsSink
    {
        CONST_VTBL struct IZcPiPropertyEditEventsSinkVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPiPropertyEditEventsSink_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPiPropertyEditEventsSink_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPiPropertyEditEventsSink_Release(This)	\
    ((This)->lpVtbl -> Release(This))
#define IZcPiPropertyEditEventsSink_OnClick(This)	\
    ((This)->lpVtbl -> OnClick(This))

#define IZcPiPropertyEditEventsSink_OnDblClick(This)	\
    ((This)->lpVtbl -> OnDblClick(This))

#define IZcPiPropertyEditEventsSink_OnKeyDown(This,pnChar,keyData)	\
    ((This)->lpVtbl -> OnKeyDown(This,pnChar,keyData))

#define IZcPiPropertyEditEventsSink_OnKeyUp(This,pnChar,keyData)	\
    ((This)->lpVtbl -> OnKeyUp(This,pnChar,keyData))

#define IZcPiPropertyEditEventsSink_OnRButtonDown(This,wParam,lParam)	\
    ((This)->lpVtbl -> OnRButtonDown(This,wParam,lParam))

#define IZcPiPropertyEditEventsSink_OnMButtonDown(This,wParam,lParam)	\
    ((This)->lpVtbl -> OnMButtonDown(This,wParam,lParam))

#define IZcPiPropertyEditEventsSink_OnBeginPropertyUpdate(This)	\
    ((This)->lpVtbl -> OnBeginPropertyUpdate(This))

#define IZcPiPropertyEditEventsSink_OnEndPropertyUpdate(This)	\
    ((This)->lpVtbl -> OnEndPropertyUpdate(This))

#endif


#endif 	




#endif 	


#define IPropertyUnspecified  IZcPiPropertyUnspecified
#define IID_IPropertyUnspecified IID_IZcPiPropertyUnspecified
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0003_v0_0_s_ifspec;

#ifndef __IZcPiPropertyUnspecified_INTERFACE_DEFINED__
#define __IZcPiPropertyUnspecified_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPiPropertyUnspecified;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EC923213-5A17-11E7-B72E-BC5FF42AC839")
    IZcPiPropertyUnspecified : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE IsValueUnspecified(
             VARIANT varId,
             VARIANT_BOOL *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE SetUnspecified(
             VARIANT varId,
             VARIANT_BOOL bIsUnspecified) = 0;

        virtual  HRESULT STDMETHODCALLTYPE IsUnspecifiedAllowed(
             VARIANT varId,
             VARIANT_BOOL *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetUnspecifiedString(
             VARIANT varId,
             BSTR *pVal) = 0;

    };

#else

    typedef struct IZcPiPropertyUnspecifiedVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPiPropertyUnspecified * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPiPropertyUnspecified * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPiPropertyUnspecified * This);

         HRESULT ( STDMETHODCALLTYPE *IsValueUnspecified )(
            IZcPiPropertyUnspecified * This,
             VARIANT varId,
             VARIANT_BOOL *pVal);

         HRESULT ( STDMETHODCALLTYPE *SetUnspecified )(
            IZcPiPropertyUnspecified * This,
             VARIANT varId,
             VARIANT_BOOL bIsUnspecified);

         HRESULT ( STDMETHODCALLTYPE *IsUnspecifiedAllowed )(
            IZcPiPropertyUnspecified * This,
             VARIANT varId,
             VARIANT_BOOL *pVal);

         HRESULT ( STDMETHODCALLTYPE *GetUnspecifiedString )(
            IZcPiPropertyUnspecified * This,
             VARIANT varId,
             BSTR *pVal);

        END_INTERFACE
    } IZcPiPropertyUnspecifiedVtbl;

    interface IZcPiPropertyUnspecified
    {
        CONST_VTBL struct IZcPiPropertyUnspecifiedVtbl *lpVtbl;
    };
#ifdef COBJMACROS


#define IZcPiPropertyUnspecified_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPiPropertyUnspecified_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPiPropertyUnspecified_Release(This)	\
    ((This)->lpVtbl -> Release(This))
#define IZcPiPropertyUnspecified_IsValueUnspecified(This,varId,pVal)	\
    ((This)->lpVtbl -> IsValueUnspecified(This,varId,pVal))

#define IZcPiPropertyUnspecified_SetUnspecified(This,varId,bIsUnspecified)	\
    ((This)->lpVtbl -> SetUnspecified(This,varId,bIsUnspecified))

#define IZcPiPropertyUnspecified_IsUnspecifiedAllowed(This,varId,pVal)	\
    ((This)->lpVtbl -> IsUnspecifiedAllowed(This,varId,pVal))

#define IZcPiPropertyUnspecified_GetUnspecifiedString(This,varId,pVal)	\
    ((This)->lpVtbl -> GetUnspecifiedString(This,varId,pVal))

#endif


#endif 	




#endif 	



#define IPerPropertyDisplay IZcPiPropertyDisplay
#define IID_IPerPropertyDisplay IID_IZcPiPropertyDisplay
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0004_v0_0_s_ifspec;

#ifndef __IZcPiPropertyDisplay_INTERFACE_DEFINED__
#define __IZcPiPropertyDisplay_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPiPropertyDisplay;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EC923214-5A17-11E7-B72E-BC5FF42AC839")
    IZcPiPropertyDisplay : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE GetCustomPropertyCtrl(
             VARIANT Id,
             LCID lcid,
             BSTR *pProgId) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetPropertyIcon(
             VARIANT Id,
             IUnknown **pIcon) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetPropTextColor(
             VARIANT Id,
             OLE_COLOR *pTextColor) = 0;

        virtual  HRESULT STDMETHODCALLTYPE IsFullView(
             VARIANT Id,
             VARIANT_BOOL *pbVisible,
             DWORD *pIntegralHeight) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetPropertyWeight(
             VARIANT Id,
             long *pPropertyWeight) = 0;

    };

#else

    typedef struct IZcPiPropertyDisplayVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPiPropertyDisplay * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPiPropertyDisplay * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPiPropertyDisplay * This);

         HRESULT ( STDMETHODCALLTYPE *GetCustomPropertyCtrl )(
            IZcPiPropertyDisplay * This,
             VARIANT Id,
             LCID lcid,
             BSTR *pProgId);

         HRESULT ( STDMETHODCALLTYPE *GetPropertyIcon )(
            IZcPiPropertyDisplay * This,
             VARIANT Id,
             IUnknown **pIcon);

         HRESULT ( STDMETHODCALLTYPE *GetPropTextColor )(
            IZcPiPropertyDisplay * This,
             VARIANT Id,
             OLE_COLOR *pTextColor);

         HRESULT ( STDMETHODCALLTYPE *IsFullView )(
            IZcPiPropertyDisplay * This,
             VARIANT Id,
             VARIANT_BOOL *pbVisible,
             DWORD *pIntegralHeight);

         HRESULT ( STDMETHODCALLTYPE *GetPropertyWeight )(
            IZcPiPropertyDisplay * This,
             VARIANT Id,
             long *pPropertyWeight);

        END_INTERFACE
    } IZcPiPropertyDisplayVtbl;

    interface IZcPiPropertyDisplay
    {
        CONST_VTBL struct IZcPiPropertyDisplayVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPiPropertyDisplay_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPiPropertyDisplay_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPiPropertyDisplay_Release(This)	\
    ((This)->lpVtbl -> Release(This))
#define IZcPiPropertyDisplay_GetCustomPropertyCtrl(This,Id,lcid,pProgId)	\
    ((This)->lpVtbl -> GetCustomPropertyCtrl(This,Id,lcid,pProgId))

#define IZcPiPropertyDisplay_GetPropertyIcon(This,Id,pIcon)	\
    ((This)->lpVtbl -> GetPropertyIcon(This,Id,pIcon))

#define IZcPiPropertyDisplay_GetPropTextColor(This,Id,pTextColor)	\
    ((This)->lpVtbl -> GetPropTextColor(This,Id,pTextColor))

#define IZcPiPropertyDisplay_IsFullView(This,Id,pbVisible,pIntegralHeight)	\
    ((This)->lpVtbl -> IsFullView(This,Id,pbVisible,pIntegralHeight))

#define IZcPiPropertyDisplay_GetPropertyWeight(This,Id,pPropertyWeight)	\
    ((This)->lpVtbl -> GetPropertyWeight(This,Id,pPropertyWeight))

#endif


#endif 	




#endif 	


#define ICategorizeProperties2 IZcPiCategorizeProperties
#define IID_ICategorizeProperties2 IID_IZcPiCategorizeProperties
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0005_v0_0_s_ifspec;

#ifndef __IZcPiCategorizeProperties_INTERFACE_DEFINED__
#define __IZcPiCategorizeProperties_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPiCategorizeProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EC923215-5A17-11E7-B72E-BC5FF42AC839")
    IZcPiCategorizeProperties : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE MapPropertyToCategory(
             DISPID dispID,
             int *pCatID) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetCategoryName(
             int CatID,
             LCID lCid,
             BSTR *pCategoryName) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetCategoryDescription(
             int CatID,
             LCID lCid,
             BSTR *pCategoryDescription) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetCategoryWeight(
             int CatID,
             long *pCategoryWeight) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetParentCategory(
             int CatID,
             int *pParentCatID) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetUniqueID(
             BSTR *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetCommandButtons(
             int CatID,
             VARIANT *pCatCmdBtns) = 0;

    };

#else

    typedef struct IZcPiCategorizePropertiesVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPiCategorizeProperties * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPiCategorizeProperties * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPiCategorizeProperties * This);

         HRESULT ( STDMETHODCALLTYPE *MapPropertyToCategory )(
            IZcPiCategorizeProperties * This,
             DISPID dispID,
             int *pCatID);

         HRESULT ( STDMETHODCALLTYPE *GetCategoryName )(
            IZcPiCategorizeProperties * This,
             int CatID,
             LCID lCid,
             BSTR *pCategoryName);

         HRESULT ( STDMETHODCALLTYPE *GetCategoryDescription )(
            IZcPiCategorizeProperties * This,
             int CatID,
             LCID lCid,
             BSTR *pCategoryDescription);

         HRESULT ( STDMETHODCALLTYPE *GetCategoryWeight )(
            IZcPiCategorizeProperties * This,
             int CatID,
             long *pCategoryWeight);

         HRESULT ( STDMETHODCALLTYPE *GetParentCategory )(
            IZcPiCategorizeProperties * This,
             int CatID,
             int *pParentCatID);

         HRESULT ( STDMETHODCALLTYPE *GetUniqueID )(
            IZcPiCategorizeProperties * This,
             BSTR *pVal);

         HRESULT ( STDMETHODCALLTYPE *GetCommandButtons )(
            IZcPiCategorizeProperties * This,
             int CatID,
             VARIANT *pCatCmdBtns);

        END_INTERFACE
    } IZcPiCategorizePropertiesVtbl;

    interface IZcPiCategorizeProperties
    {
        CONST_VTBL struct IZcPiCategorizePropertiesVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPiCategorizeProperties_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPiCategorizeProperties_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPiCategorizeProperties_Release(This)	\
    ((This)->lpVtbl -> Release(This))


#define IZcPiCategorizeProperties_MapPropertyToCategory(This,dispID,pCatID)	\
    ((This)->lpVtbl -> MapPropertyToCategory(This,dispID,pCatID))

#define IZcPiCategorizeProperties_GetCategoryName(This,CatID,lCid,pCategoryName)	\
    ((This)->lpVtbl -> GetCategoryName(This,CatID,lCid,pCategoryName))

#define IZcPiCategorizeProperties_GetCategoryDescription(This,CatID,lCid,pCategoryDescription)	\
    ((This)->lpVtbl -> GetCategoryDescription(This,CatID,lCid,pCategoryDescription))

#define IZcPiCategorizeProperties_GetCategoryWeight(This,CatID,pCategoryWeight)	\
    ((This)->lpVtbl -> GetCategoryWeight(This,CatID,pCategoryWeight))

#define IZcPiCategorizeProperties_GetParentCategory(This,CatID,pParentCatID)	\
    ((This)->lpVtbl -> GetParentCategory(This,CatID,pParentCatID))

#define IZcPiCategorizeProperties_GetUniqueID(This,pVal)	\
    ((This)->lpVtbl -> GetUniqueID(This,pVal))

#define IZcPiCategorizeProperties_GetCommandButtons(This,CatID,pCatCmdBtns)	\
    ((This)->lpVtbl -> GetCommandButtons(This,CatID,pCatCmdBtns))

#endif


#endif 	




#endif 	





#define IPropCommandButtons IZcPiPropCommandButtons
#define IID_IPropCommandButtons IID_IZcPiPropCommandButtons
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0006_v0_0_s_ifspec;

#ifndef __IZcPiPropCommandButtons_INTERFACE_DEFINED__
#define __IZcPiPropCommandButtons_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPiPropCommandButtons;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EC923216-5A17-11E7-B72E-BC5FF42AC839")
    IZcPiPropCommandButtons : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE GetButtons(
             VARIANT *pButtons) = 0;

    };

#else

    typedef struct IZcPiPropCommandButtonsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPiPropCommandButtons * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPiPropCommandButtons * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPiPropCommandButtons * This);

         HRESULT ( STDMETHODCALLTYPE *GetButtons )(
            IZcPiPropCommandButtons * This,
             VARIANT *pButtons);

        END_INTERFACE
    } IZcPiPropCommandButtonsVtbl;

    interface IZcPiPropCommandButtons
    {
        CONST_VTBL struct IZcPiPropCommandButtonsVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPiPropCommandButtons_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPiPropCommandButtons_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPiPropCommandButtons_Release(This)	\
    ((This)->lpVtbl -> Release(This))


#define IZcPiPropCommandButtons_GetButtons(This,pButtons)	\
    ((This)->lpVtbl -> GetButtons(This,pButtons))

#endif


#endif 	




#endif 	





#define ICommandButton IZcPiCommandButton
#define IID_ICommandButton IID_IZcPiCommandButton
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0007_v0_0_s_ifspec;

#ifndef __IZcPiCommandButton_INTERFACE_DEFINED__
#define __IZcPiCommandButton_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPiCommandButton;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EC923217-5A17-11E7-B72E-BC5FF42AC839")
    IZcPiCommandButton : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE GetName(
             LCID lcid,
             BSTR *name) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_EnabledPicture(
             IUnknown **pPicture) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_DisabledPicture(
             IUnknown **pPicture) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_Enabled(
             VARIANT_BOOL *bEnabled) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_Enabled(
             VARIANT_BOOL bEnabled) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_Checked(
             VARIANT_BOOL *bChecked) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_Checked(
             VARIANT_BOOL bChecked) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_ButtonStyle(
             long *style) = 0;

        virtual  HRESULT STDMETHODCALLTYPE Execute(
             VARIANT Objects) = 0;

    };

#else

    typedef struct IZcPiCommandButtonVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPiCommandButton * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPiCommandButton * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPiCommandButton * This);

         HRESULT ( STDMETHODCALLTYPE *GetName )(
            IZcPiCommandButton * This,
             LCID lcid,
             BSTR *name);

         HRESULT ( STDMETHODCALLTYPE *get_EnabledPicture )(
            IZcPiCommandButton * This,
             IUnknown **pPicture);

         HRESULT ( STDMETHODCALLTYPE *get_DisabledPicture )(
            IZcPiCommandButton * This,
             IUnknown **pPicture);

         HRESULT ( STDMETHODCALLTYPE *get_Enabled )(
            IZcPiCommandButton * This,
             VARIANT_BOOL *bEnabled);

         HRESULT ( STDMETHODCALLTYPE *put_Enabled )(
            IZcPiCommandButton * This,
             VARIANT_BOOL bEnabled);

         HRESULT ( STDMETHODCALLTYPE *get_Checked )(
            IZcPiCommandButton * This,
             VARIANT_BOOL *bChecked);

         HRESULT ( STDMETHODCALLTYPE *put_Checked )(
            IZcPiCommandButton * This,
             VARIANT_BOOL bChecked);

         HRESULT ( STDMETHODCALLTYPE *get_ButtonStyle )(
            IZcPiCommandButton * This,
             long *style);

         HRESULT ( STDMETHODCALLTYPE *Execute )(
            IZcPiCommandButton * This,
             VARIANT Objects);

        END_INTERFACE
    } IZcPiCommandButtonVtbl;

    interface IZcPiCommandButton
    {
        CONST_VTBL struct IZcPiCommandButtonVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPiCommandButton_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPiCommandButton_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPiCommandButton_Release(This)	\
    ((This)->lpVtbl -> Release(This))
#define IZcPiCommandButton_GetName(This,lcid,name)	\
    ((This)->lpVtbl -> GetName(This,lcid,name))

#define IZcPiCommandButton_get_EnabledPicture(This,pPicture)	\
    ((This)->lpVtbl -> get_EnabledPicture(This,pPicture))

#define IZcPiCommandButton_get_DisabledPicture(This,pPicture)	\
    ((This)->lpVtbl -> get_DisabledPicture(This,pPicture))

#define IZcPiCommandButton_get_Enabled(This,bEnabled)	\
    ((This)->lpVtbl -> get_Enabled(This,bEnabled))

#define IZcPiCommandButton_put_Enabled(This,bEnabled)	\
    ((This)->lpVtbl -> put_Enabled(This,bEnabled))

#define IZcPiCommandButton_get_Checked(This,bChecked)	\
    ((This)->lpVtbl -> get_Checked(This,bChecked))

#define IZcPiCommandButton_put_Checked(This,bChecked)	\
    ((This)->lpVtbl -> put_Checked(This,bChecked))

#define IZcPiCommandButton_get_ButtonStyle(This,style)	\
    ((This)->lpVtbl -> get_ButtonStyle(This,style))

#define IZcPiCommandButton_Execute(This,Objects)	\
    ((This)->lpVtbl -> Execute(This,Objects))

#endif


#endif 	




#endif 	


#ifndef __IZcPiCommandButton2_INTERFACE_DEFINED__
#define __IZcPiCommandButton2_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPiCommandButton2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EC923218-5A17-11E7-B72E-BC5FF42AC839")
    IZcPiCommandButton2 : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE get_CheckedPicture(
             IUnknown **pPicture) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_UncheckedPicture(
             IUnknown **pPicture) = 0;

    };

#else

    typedef struct IZcPiCommandButton2Vtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPiCommandButton2 * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPiCommandButton2 * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPiCommandButton2 * This);

         HRESULT ( STDMETHODCALLTYPE *get_CheckedPicture )(
            IZcPiCommandButton2 * This,
             IUnknown **pPicture);

         HRESULT ( STDMETHODCALLTYPE *get_UncheckedPicture )(
            IZcPiCommandButton2 * This,
             IUnknown **pPicture);

        END_INTERFACE
    } IZcPiCommandButton2Vtbl;

    interface IZcPiCommandButton2
    {
        CONST_VTBL struct IZcPiCommandButton2Vtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPiCommandButton2_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPiCommandButton2_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPiCommandButton2_Release(This)	\
    ((This)->lpVtbl -> Release(This))


#define IZcPiCommandButton2_get_CheckedPicture(This,pPicture)	\
    ((This)->lpVtbl -> get_CheckedPicture(This,pPicture))

#define IZcPiCommandButton2_get_UncheckedPicture(This,pPicture)	\
    ((This)->lpVtbl -> get_UncheckedPicture(This,pPicture))

#endif


#endif 	




#endif 	



#define IPropertyInspectorSink IZcPiPropertyInspectorEventsSink
#define IID_IPropertyInspectorSink IID_IZcPiPropertyInspectorEventsSink
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0008_v0_0_s_ifspec;

#ifndef __IZcPiPropertyInspectorEventsSink_INTERFACE_DEFINED__
#define __IZcPiPropertyInspectorEventsSink_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPiPropertyInspectorEventsSink;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EC923219-5A17-11E7-B72E-BC5FF42AC839")
    IZcPiPropertyInspectorEventsSink : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE Rebuild(
             DWORD dwFlags) = 0;

        virtual  HRESULT STDMETHODCALLTYPE RefreshControl(
             VARIANT var,
             DWORD dwFlags) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetPropertyControl(
             VARIANT var,
             IUnknown **ppUnk) = 0;

    };

#else

    typedef struct IZcPiPropertyInspectorEventsSinkVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPiPropertyInspectorEventsSink * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPiPropertyInspectorEventsSink * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPiPropertyInspectorEventsSink * This);

         HRESULT ( STDMETHODCALLTYPE *Rebuild )(
            IZcPiPropertyInspectorEventsSink * This,
             DWORD dwFlags);

         HRESULT ( STDMETHODCALLTYPE *RefreshControl )(
            IZcPiPropertyInspectorEventsSink * This,
             VARIANT var,
             DWORD dwFlags);

         HRESULT ( STDMETHODCALLTYPE *GetPropertyControl )(
            IZcPiPropertyInspectorEventsSink * This,
             VARIANT var,
             IUnknown **ppUnk);

        END_INTERFACE
    } IZcPiPropertyInspectorEventsSinkVtbl;

    interface IZcPiPropertyInspectorEventsSink
    {
        CONST_VTBL struct IZcPiPropertyInspectorEventsSinkVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPiPropertyInspectorEventsSink_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPiPropertyInspectorEventsSink_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPiPropertyInspectorEventsSink_Release(This)	\
    ((This)->lpVtbl -> Release(This))


#define IZcPiPropertyInspectorEventsSink_Rebuild(This,dwFlags)	\
    ((This)->lpVtbl -> Rebuild(This,dwFlags))

#define IZcPiPropertyInspectorEventsSink_RefreshControl(This,var,dwFlags)	\
    ((This)->lpVtbl -> RefreshControl(This,var,dwFlags))

#define IZcPiPropertyInspectorEventsSink_GetPropertyControl(This,var,ppUnk)	\
    ((This)->lpVtbl -> GetPropertyControl(This,var,ppUnk))

#endif


#endif 	




#endif 	


#define IPropertyInspectorInputEventSink IZcPiPropertyInspectorInputEventSink
#define IID_IPropertyInspectorInputEventSink IID_IZcPiPropertyInspectorInputEventSink
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0009_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcPi_0000_0009_v0_0_s_ifspec;

#ifndef __IZcPiPropertyInspectorInputEventSink_INTERFACE_DEFINED__
#define __IZcPiPropertyInspectorInputEventSink_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPiPropertyInspectorInputEventSink;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EC923102-5A17-11E7-B72E-BC5FF42AC839")
    IZcPiPropertyInspectorInputEventSink : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE OnKeyDown(
             long pnChar,
             long keyData) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnPopulateContextMenu(
             VARIANT *flagArray,
             VARIANT *idArray,
             VARIANT *szItemArray) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnContextMenuCommand(
             int cmdId) = 0;

    };

#else

    typedef struct IZcPiPropertyInspectorInputEventSinkVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPiPropertyInspectorInputEventSink * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPiPropertyInspectorInputEventSink * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPiPropertyInspectorInputEventSink * This);

         HRESULT ( STDMETHODCALLTYPE *OnKeyDown )(
            IZcPiPropertyInspectorInputEventSink * This,
             long pnChar,
             long keyData);

         HRESULT ( STDMETHODCALLTYPE *OnPopulateContextMenu )(
            IZcPiPropertyInspectorInputEventSink * This,
             VARIANT *flagArray,
             VARIANT *idArray,
             VARIANT *szItemArray);

         HRESULT ( STDMETHODCALLTYPE *OnContextMenuCommand )(
            IZcPiPropertyInspectorInputEventSink * This,
             int cmdId);

        END_INTERFACE
    } IZcPiPropertyInspectorInputEventSinkVtbl;

    interface IZcPiPropertyInspectorInputEventSink
    {
        CONST_VTBL struct IZcPiPropertyInspectorInputEventSinkVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPiPropertyInspectorInputEventSink_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPiPropertyInspectorInputEventSink_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPiPropertyInspectorInputEventSink_Release(This)	\
    ((This)->lpVtbl -> Release(This))


#define IZcPiPropertyInspectorInputEventSink_OnKeyDown(This,pnChar,keyData)	\
    ((This)->lpVtbl -> OnKeyDown(This,pnChar,keyData))

#define IZcPiPropertyInspectorInputEventSink_OnPopulateContextMenu(This,flagArray,idArray,szItemArray)	\
    ((This)->lpVtbl -> OnPopulateContextMenu(This,flagArray,idArray,szItemArray))

#define IZcPiPropertyInspectorInputEventSink_OnContextMenuCommand(This,cmdId)	\
    ((This)->lpVtbl -> OnContextMenuCommand(This,cmdId))

#endif


#endif 	




#endif 	


#ifndef __IZcPiPropertyInspectorTheme_INTERFACE_DEFINED__
#define __IZcPiPropertyInspectorTheme_INTERFACE_DEFINED__

EXTERN_C const IID IID_IZcPiPropertyInspectorTheme;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC92321A-5A17-11E7-B72E-BC5FF42AC839")
    IZcPiPropertyInspectorTheme : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTheme( 
            /* [in] */ BSTR bstrThemeName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAcPiPropertyInspectorThemeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcPiPropertyInspectorTheme * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcPiPropertyInspectorTheme * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcPiPropertyInspectorTheme * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetTheme )( 
            IZcPiPropertyInspectorTheme * This,
            /* [in] */ BSTR bstrThemeName);
        
        END_INTERFACE
    } IZcPiPropertyInspectorThemeVtbl;

    interface IZcPiPropertyInspectorTheme
    {
        CONST_VTBL struct IZcPiPropertyInspectorThemeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAcPiPropertyInspectorTheme_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAcPiPropertyInspectorTheme_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAcPiPropertyInspectorTheme_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAcPiPropertyInspectorTheme_SetTheme(This,bstrThemeName)	\
    ( (This)->lpVtbl -> SetTheme(This,bstrThemeName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAcPiPropertyInspectorTheme_INTERFACE_DEFINED__ */
#ifndef __ZCPILib_LIBRARY_DEFINED__
#define __ZCPILib_LIBRARY_DEFINED__
EXTERN_C const IID LIBID_ZCPILib;

EXTERN_C const CLSID CLSID_ZcPiPropertyInspector;

#ifdef __cplusplus

class DECLSPEC_UUID("EC923023-5A17-11E7-B72E-BC5FF42AC839")
ZcPiPropertyInspector;
#endif
#endif
unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * );
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * );
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * );
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * );

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * );
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * );
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * );
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * );
#ifdef __cplusplus
}
#endif

#endif

