
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

#ifndef __zAcTc_i_h__
#define __zAcTc_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef __IZcadToolProperties_FWD_DEFINED__
#define __IZcadToolProperties_FWD_DEFINED__
typedef interface IZcadToolProperties IZcadToolProperties;
#endif 	

#ifndef __IZcadToolProperties2_FWD_DEFINED__
#define __IZcadToolProperties2_FWD_DEFINED__
typedef interface IZcadToolProperties2 IZcadToolProperties2;
#endif 	

#ifndef __IZcadStockTool_FWD_DEFINED__
#define __IZcadStockTool_FWD_DEFINED__
typedef interface IZcadStockTool IZcadStockTool;
#endif 	

#ifndef __IZcadToolContextMenu_FWD_DEFINED__
#define __IZcadToolContextMenu_FWD_DEFINED__
typedef interface IZcadToolContextMenu IZcadToolContextMenu;
#endif 	

#ifndef __IZcadTool_FWD_DEFINED__
#define __IZcadTool_FWD_DEFINED__
typedef interface IZcadTool IZcadTool;
#endif 	

#ifndef __IZcadTool2_FWD_DEFINED__
#define __IZcadTool2_FWD_DEFINED__
typedef interface IZcadTool2 IZcadTool2;
#endif 	

#ifndef __IZcadToolFlyoutShape_FWD_DEFINED__
#define __IZcadToolFlyoutShape_FWD_DEFINED__
typedef interface IZcadToolFlyoutShape IZcadToolFlyoutShape;
#endif 	

#ifndef __IZcadToolSort_FWD_DEFINED__
#define __IZcadToolSort_FWD_DEFINED__
typedef interface IZcadToolSort IZcadToolSort;
#endif 	

#ifndef __IZcadToolDropTarget_FWD_DEFINED__
#define __IZcadToolDropTarget_FWD_DEFINED__
typedef interface IZcadToolDropTarget IZcadToolDropTarget;
#endif 	

#ifndef __IZcadToolDragSource_FWD_DEFINED__
#define __IZcadToolDragSource_FWD_DEFINED__
typedef interface IZcadToolDragSource IZcadToolDragSource;
#endif 	

#ifndef __IZcadToolCopyPaste_FWD_DEFINED__
#define __IZcadToolCopyPaste_FWD_DEFINED__
typedef interface IZcadToolCopyPaste IZcadToolCopyPaste;
#endif 	

#ifndef __IZcadToolImage_FWD_DEFINED__
#define __IZcadToolImage_FWD_DEFINED__
typedef interface IZcadToolImage IZcadToolImage;
#endif 	

#ifndef __ZcadToolProperties_FWD_DEFINED__
#define __ZcadToolProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcadToolProperties ZcadToolProperties;
#else
typedef struct ZcadToolProperties ZcadToolProperties;
#endif 

#endif 	

#ifndef __ZcadToolImage_FWD_DEFINED__
#define __ZcadToolImage_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcadToolImage ZcadToolImage;
#else
typedef struct ZcadToolImage ZcadToolImage;
#endif 

#endif 	

#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


typedef  
enum __MIDL___MIDL_itf_zAcTc_0000_0000_0001
    {
        kEditDefault	= 0,
        kEditCustom	= ( kEditDefault + 1 ) ,
        kEditNone	= ( kEditCustom + 1 ) ,
        kEditMultiple	= 0x4
    } 	ToolEditMode;

typedef  
enum __MIDL___MIDL_itf_zAcTc_0000_0000_0002
    {
        kContextNone	= -1,
        kContextMenuPaletteTool	= ( kContextNone + 1 ) ,
        kContextMenuEditorImage	= ( kContextMenuPaletteTool + 1 ) ,
        kContextMenuPaletteBackground	= ( kContextMenuEditorImage + 1 ) ,
        kContextMenuPaletteSetTab	= ( kContextMenuPaletteBackground + 1 ) ,
        kContextMenuPaletteSetCaption	= ( kContextMenuPaletteSetTab + 1 ) ,
        kContextMenuPaletteSetOptionButton	= ( kContextMenuPaletteSetCaption + 1 ) 
    } 	ContextMenuFlag;

typedef  
enum __MIDL___MIDL_itf_zAcTc_0000_0000_0003
    {
        kContextMenuShow	= 0,
        kContextMenuHide	= ( kContextMenuShow + 1 ) ,
        kExecutionCanceled	= ( kContextMenuHide + 1 ) ,
        kExecutionCancelRejected	= ( kExecutionCanceled + 1 ) ,
        kContextMenuUpdatePalette	= ( kExecutionCancelRejected + 1 ) 
    } 	ReturnFlag;

typedef  
enum __MIDL___MIDL_itf_zAcTc_0000_0000_0004
    {
        kLButtonClicked	= 0,
        kDroppedInDrawing	= ( kLButtonClicked + 1 ) 
    } 	ExecutionContext;



extern RPC_IF_HANDLE __MIDL_itf_zAcTc_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_zAcTc_0000_0000_v0_0_s_ifspec;

#ifndef __IZcadToolProperties_INTERFACE_DEFINED__
#define __IZcadToolProperties_INTERFACE_DEFINED__

EXTERN_C const IID IID_IZcadToolProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC923006-5A17-11E7-B72E-BC5FF42AC839")
    IZcadToolProperties : public IDispatch
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE get_ID( 
             GUID *pId) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_Name( 
             BSTR *pVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_Name( 
             BSTR newVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_Description( 
             BSTR *pVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_Description( 
             BSTR newVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_ToolTipText( 
             BSTR *pVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_ToolTipText( 
             BSTR newVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_HelpFile( 
             BSTR *pVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_HelpFile( 
             BSTR newVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_HelpCommand( 
             BSTR *pVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_HelpCommand( 
             BSTR newVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_HelpData( 
             BSTR *pVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_HelpData( 
             BSTR newVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_IsReadOnly( 
             VARIANT_BOOL *pReadOnly) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_ToolType( 
             LONG *pToolType) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_ToolType( 
             LONG lToolType) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_IsFlyoutEnabled( 
             VARIANT_BOOL *pEnabled) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_IsFlyoutEnabled( 
             VARIANT_BOOL bUseFlyout) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_ShapePackageId( 
             GUID *pId) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_ShapePackageId( 
             GUID *pId) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_CurrentShapeId( 
             GUID *pId) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_CurrentShapeId( 
             GUID *pId) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_ActiveShapeIds( 
             VARIANT *pShapes) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_ActiveShapeIds( 
             VARIANT *pShapes) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetImage( 
             long cx,
             long cy,
             IUnknown **pVal,
             BSTR *sResourceName,
             BSTR *sSourceFile) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE SetImage( 
             long cx,
             long cy,
             IUnknown *newVal,
             BSTR sResourceName,
             BSTR sSourceFile) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetCustomData( 
             IUnknown **ppVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetCurrentShape( 
             IUnknown **ppTool) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetOverlayImage( 
             IUnknown **pVal,
             BSTR *pResourceName,
             BSTR *pSourceFile) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE SetOverlayImage( 
             IUnknown *newVal,
             BSTR sResourceName,
             BSTR sSourceFile) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetZcTcTool( 
             DWORD_PTR *ppZcTcTool) = 0;      
    };
    
#else 	

    typedef struct IZcadToolPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolProperties * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZcadToolProperties * This,
             UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZcadToolProperties * This,
             UINT iTInfo,
             LCID lcid,
             ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZcadToolProperties * This,
             REFIID riid,
             LPOLESTR *rgszNames,
             UINT cNames,
             LCID lcid,
             DISPID *rgDispId);
        
         HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZcadToolProperties * This,
             DISPID dispIdMember,
             REFIID riid,
             LCID lcid,
             WORD wFlags,
             DISPPARAMS *pDispParams,
             VARIANT *pVarResult,
             EXCEPINFO *pExcepInfo,
             UINT *puArgErr);
        
         HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IZcadToolProperties * This,
             GUID *pId);
        
         HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IZcadToolProperties * This,
             BSTR *pVal);
        
         HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IZcadToolProperties * This,
             BSTR newVal);
        
         HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IZcadToolProperties * This,
             BSTR *pVal);
        
         HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            IZcadToolProperties * This,
             BSTR newVal);
        
         HRESULT ( STDMETHODCALLTYPE *get_ToolTipText )( 
            IZcadToolProperties * This,
             BSTR *pVal);
        
         HRESULT ( STDMETHODCALLTYPE *put_ToolTipText )( 
            IZcadToolProperties * This,
             BSTR newVal);
        
         HRESULT ( STDMETHODCALLTYPE *get_HelpFile )( 
            IZcadToolProperties * This,
             BSTR *pVal);
        
         HRESULT ( STDMETHODCALLTYPE *put_HelpFile )( 
            IZcadToolProperties * This,
             BSTR newVal);
        
         HRESULT ( STDMETHODCALLTYPE *get_HelpCommand )( 
            IZcadToolProperties * This,
             BSTR *pVal);
        
         HRESULT ( STDMETHODCALLTYPE *put_HelpCommand )( 
            IZcadToolProperties * This,
             BSTR newVal);
        
         HRESULT ( STDMETHODCALLTYPE *get_HelpData )( 
            IZcadToolProperties * This,
             BSTR *pVal);
        
         HRESULT ( STDMETHODCALLTYPE *put_HelpData )( 
            IZcadToolProperties * This,
             BSTR newVal);
        
         HRESULT ( STDMETHODCALLTYPE *get_IsReadOnly )( 
            IZcadToolProperties * This,
             VARIANT_BOOL *pReadOnly);
        
         HRESULT ( STDMETHODCALLTYPE *get_ToolType )( 
            IZcadToolProperties * This,
             LONG *pToolType);
        
         HRESULT ( STDMETHODCALLTYPE *put_ToolType )( 
            IZcadToolProperties * This,
             LONG lToolType);
        
         HRESULT ( STDMETHODCALLTYPE *get_IsFlyoutEnabled )( 
            IZcadToolProperties * This,
             VARIANT_BOOL *pEnabled);
        
         HRESULT ( STDMETHODCALLTYPE *put_IsFlyoutEnabled )( 
            IZcadToolProperties * This,
             VARIANT_BOOL bUseFlyout);
        
         HRESULT ( STDMETHODCALLTYPE *get_ShapePackageId )( 
            IZcadToolProperties * This,
             GUID *pId);
        
         HRESULT ( STDMETHODCALLTYPE *put_ShapePackageId )( 
            IZcadToolProperties * This,
             GUID *pId);
        
         HRESULT ( STDMETHODCALLTYPE *get_CurrentShapeId )( 
            IZcadToolProperties * This,
             GUID *pId);
        
         HRESULT ( STDMETHODCALLTYPE *put_CurrentShapeId )( 
            IZcadToolProperties * This,
             GUID *pId);
        
         HRESULT ( STDMETHODCALLTYPE *get_ActiveShapeIds )( 
            IZcadToolProperties * This,
             VARIANT *pShapes);
        
         HRESULT ( STDMETHODCALLTYPE *put_ActiveShapeIds )( 
            IZcadToolProperties * This,
             VARIANT *pShapes);
        
         HRESULT ( STDMETHODCALLTYPE *GetImage )( 
            IZcadToolProperties * This,
             long cx,
             long cy,
             IUnknown **pVal,
             BSTR *sResourceName,
             BSTR *sSourceFile);
        
         HRESULT ( STDMETHODCALLTYPE *SetImage )( 
            IZcadToolProperties * This,
             long cx,
             long cy,
             IUnknown *newVal,
             BSTR sResourceName,
             BSTR sSourceFile);
        
         HRESULT ( STDMETHODCALLTYPE *GetCustomData )( 
            IZcadToolProperties * This,
             IUnknown **ppVal);
        
         HRESULT ( STDMETHODCALLTYPE *GetCurrentShape )( 
            IZcadToolProperties * This,
             IUnknown **ppTool);
        
         HRESULT ( STDMETHODCALLTYPE *GetOverlayImage )( 
            IZcadToolProperties * This,
             IUnknown **pVal,
             BSTR *pResourceName,
             BSTR *pSourceFile);
        
         HRESULT ( STDMETHODCALLTYPE *SetOverlayImage )( 
            IZcadToolProperties * This,
             IUnknown *newVal,
             BSTR sResourceName,
             BSTR sSourceFile);
        
         HRESULT ( STDMETHODCALLTYPE *GetZcTcTool )( 
            IZcadToolProperties * This,
             DWORD_PTR *ppZcTcTool);
        
        END_INTERFACE
    } IZcadToolPropertiesVtbl;

    interface IZcadToolProperties
    {
        CONST_VTBL struct IZcadToolPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolProperties_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject)) 

#define IZcadToolProperties_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This)) 

#define IZcadToolProperties_Release(This)	\
    ((This)->lpVtbl -> Release(This)) 


#define IZcadToolProperties_GetTypeInfoCount(This,pctinfo)	\
    ((This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)) 

#define IZcadToolProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ((This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)) 

#define IZcadToolProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ((This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)) 

#define IZcadToolProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ((This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)) 


#define IZcadToolProperties_get_ID(This,pId)	\
    ((This)->lpVtbl -> get_ID(This,pId)) 

#define IZcadToolProperties_get_Name(This,pVal)	\
    ((This)->lpVtbl -> get_Name(This,pVal)) 

#define IZcadToolProperties_put_Name(This,newVal)	\
    ((This)->lpVtbl -> put_Name(This,newVal)) 

#define IZcadToolProperties_get_Description(This,pVal)	\
    ((This)->lpVtbl -> get_Description(This,pVal)) 

#define IZcadToolProperties_put_Description(This,newVal)	\
    ((This)->lpVtbl -> put_Description(This,newVal)) 

#define IZcadToolProperties_get_ToolTipText(This,pVal)	\
    ((This)->lpVtbl -> get_ToolTipText(This,pVal)) 

#define IZcadToolProperties_put_ToolTipText(This,newVal)	\
    ((This)->lpVtbl -> put_ToolTipText(This,newVal)) 

#define IZcadToolProperties_get_HelpFile(This,pVal)	\
    ((This)->lpVtbl -> get_HelpFile(This,pVal)) 

#define IZcadToolProperties_put_HelpFile(This,newVal)	\
    ((This)->lpVtbl -> put_HelpFile(This,newVal)) 

#define IZcadToolProperties_get_HelpCommand(This,pVal)	\
    ((This)->lpVtbl -> get_HelpCommand(This,pVal)) 

#define IZcadToolProperties_put_HelpCommand(This,newVal)	\
    ((This)->lpVtbl -> put_HelpCommand(This,newVal)) 

#define IZcadToolProperties_get_HelpData(This,pVal)	\
    ((This)->lpVtbl -> get_HelpData(This,pVal)) 

#define IZcadToolProperties_put_HelpData(This,newVal)	\
    ((This)->lpVtbl -> put_HelpData(This,newVal)) 

#define IZcadToolProperties_get_IsReadOnly(This,pReadOnly)	\
    ((This)->lpVtbl -> get_IsReadOnly(This,pReadOnly)) 

#define IZcadToolProperties_get_ToolType(This,pToolType)	\
    ((This)->lpVtbl -> get_ToolType(This,pToolType)) 

#define IZcadToolProperties_put_ToolType(This,lToolType)	\
    ((This)->lpVtbl -> put_ToolType(This,lToolType)) 

#define IZcadToolProperties_get_IsFlyoutEnabled(This,pEnabled)	\
    ((This)->lpVtbl -> get_IsFlyoutEnabled(This,pEnabled)) 

#define IZcadToolProperties_put_IsFlyoutEnabled(This,bUseFlyout)	\
    ((This)->lpVtbl -> put_IsFlyoutEnabled(This,bUseFlyout)) 

#define IZcadToolProperties_get_ShapePackageId(This,pId)	\
    ((This)->lpVtbl -> get_ShapePackageId(This,pId)) 

#define IZcadToolProperties_put_ShapePackageId(This,pId)	\
    ((This)->lpVtbl -> put_ShapePackageId(This,pId)) 

#define IZcadToolProperties_get_CurrentShapeId(This,pId)	\
    ((This)->lpVtbl -> get_CurrentShapeId(This,pId)) 

#define IZcadToolProperties_put_CurrentShapeId(This,pId)	\
    ((This)->lpVtbl -> put_CurrentShapeId(This,pId)) 

#define IZcadToolProperties_get_ActiveShapeIds(This,pShapes)	\
    ((This)->lpVtbl -> get_ActiveShapeIds(This,pShapes)) 

#define IZcadToolProperties_put_ActiveShapeIds(This,pShapes)	\
    ((This)->lpVtbl -> put_ActiveShapeIds(This,pShapes)) 

#define IZcadToolProperties_GetImage(This,cx,cy,pVal,sResourceName,sSourceFile)	\
    ((This)->lpVtbl -> GetImage(This,cx,cy,pVal,sResourceName,sSourceFile)) 

#define IZcadToolProperties_SetImage(This,cx,cy,newVal,sResourceName,sSourceFile)	\
    ((This)->lpVtbl -> SetImage(This,cx,cy,newVal,sResourceName,sSourceFile)) 

#define IZcadToolProperties_GetCustomData(This,ppVal)	\
    ((This)->lpVtbl -> GetCustomData(This,ppVal)) 

#define IZcadToolProperties_GetCurrentShape(This,ppTool)	\
    ((This)->lpVtbl -> GetCurrentShape(This,ppTool)) 

#define IZcadToolProperties_GetOverlayImage(This,pVal,pResourceName,pSourceFile)	\
    ((This)->lpVtbl -> GetOverlayImage(This,pVal,pResourceName,pSourceFile)) 

#define IZcadToolProperties_SetOverlayImage(This,newVal,sResourceName,sSourceFile)	\
    ((This)->lpVtbl -> SetOverlayImage(This,newVal,sResourceName,sSourceFile)) 

#define IZcadToolProperties_GetZcTcTool(This,ppZcTcTool)	\
    (This)->lpVtbl -> GetZcTcTool(This,ppZcTcTool)

#endif 


#endif 	




#endif 	


#ifndef __IZcadToolProperties2_INTERFACE_DEFINED__
#define __IZcadToolProperties2_INTERFACE_DEFINED__


 


EXTERN_C const IID IID_IZcadToolProperties2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC92303E-5A17-11E7-B72E-BC5FF42AC839")
    IZcadToolProperties2 : public IDispatch
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE get_ItemOption( 
             LONG *pItemOption) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_ItemOption( 
             LONG lItemOption) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_ImageOption( 
             LONG *pImageOption) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_ImageOption( 
             LONG lImageOption) = 0;
        
    };
    
#else 	

    typedef struct IZcadToolProperties2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolProperties2 * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolProperties2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolProperties2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IZcadToolProperties2 * This,
             UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IZcadToolProperties2 * This,
             UINT iTInfo,
             LCID lcid,
             ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IZcadToolProperties2 * This,
             REFIID riid,
             LPOLESTR *rgszNames,
             UINT cNames,
             LCID lcid,
             DISPID *rgDispId);
        
         HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IZcadToolProperties2 * This,
             DISPID dispIdMember,
             REFIID riid,
             LCID lcid,
             WORD wFlags,
             DISPPARAMS *pDispParams,
             VARIANT *pVarResult,
             EXCEPINFO *pExcepInfo,
             UINT *puArgErr);
        
         HRESULT ( STDMETHODCALLTYPE *get_ItemOption )( 
            IZcadToolProperties2 * This,
             LONG *pItemOption);
        
         HRESULT ( STDMETHODCALLTYPE *put_ItemOption )( 
            IZcadToolProperties2 * This,
             LONG lItemOption);
        
         HRESULT ( STDMETHODCALLTYPE *get_ImageOption )( 
            IZcadToolProperties2 * This,
             LONG *pImageOption);
        
         HRESULT ( STDMETHODCALLTYPE *put_ImageOption )( 
            IZcadToolProperties2 * This,
             LONG lImageOption);
        
        END_INTERFACE
    } IZcadToolProperties2Vtbl;

    interface IZcadToolProperties2
    {
        CONST_VTBL struct IZcadToolProperties2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolProperties2_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject)) 

#define IZcadToolProperties2_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This)) 

#define IZcadToolProperties2_Release(This)	\
    ((This)->lpVtbl -> Release(This)) 


#define IZcadToolProperties2_GetTypeInfoCount(This,pctinfo)	\
    ((This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)) 

#define IZcadToolProperties2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ((This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)) 

#define IZcadToolProperties2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ((This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)) 

#define IZcadToolProperties2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ((This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)) 


#define IZcadToolProperties2_get_ItemOption(This,pItemOption)	\
    ((This)->lpVtbl -> get_ItemOption(This,pItemOption)) 

#define IZcadToolProperties2_put_ItemOption(This,lItemOption)	\
    ((This)->lpVtbl -> put_ItemOption(This,lItemOption)) 

#define IZcadToolProperties2_get_ImageOption(This,pImageOption)	\
    ((This)->lpVtbl -> get_ImageOption(This,pImageOption)) 

#define IZcadToolProperties2_put_ImageOption(This,lImageOption)	\
    ((This)->lpVtbl -> put_ImageOption(This,lImageOption)) 

#endif 


#endif 	




#endif 	


#ifndef __IZcadStockTool_INTERFACE_DEFINED__
#define __IZcadStockTool_INTERFACE_DEFINED__


 


EXTERN_C const IID IID_IZcadStockTool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC9230FD-5A17-11E7-B72E-BC5FF42AC839")
    IZcadStockTool : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE CreateTool( 
             IUnknown **ppTool) = 0;
        
    };
    
#else 	

    typedef struct IZcadStockToolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadStockTool * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadStockTool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadStockTool * This);
        
         HRESULT ( STDMETHODCALLTYPE *CreateTool )( 
            IZcadStockTool * This,
             IUnknown **ppTool);
        
        END_INTERFACE
    } IZcadStockToolVtbl;

    interface IZcadStockTool
    {
        CONST_VTBL struct IZcadStockToolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadStockTool_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject)) 

#define IZcadStockTool_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This)) 

#define IZcadStockTool_Release(This)	\
    ((This)->lpVtbl -> Release(This)) 


#define IZcadStockTool_CreateTool(This,ppTool)	\
    ((This)->lpVtbl -> CreateTool(This,ppTool)) 

#endif 


#endif 	




#endif 	


#ifndef __IZcadToolContextMenu_INTERFACE_DEFINED__
#define __IZcadToolContextMenu_INTERFACE_DEFINED__


 


EXTERN_C const IID IID_IZcadToolContextMenu;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC923113-5A17-11E7-B72E-BC5FF42AC839")
    IZcadToolContextMenu : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE Customize( 
             int nContextFlag,
             DWORD_PTR hMenu,
             UINT idCmdFirst,
             UINT idCmdLast,
             GUID *pPaletteId,
             DWORD *pFlag) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetMenuHelp( 
             UINT idCmd,
             BSTR *pbstrHelpText) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE InvokeMenuCommand( 
             UINT idCmd,
             GUID *pPaletteId,
             DWORD_PTR hWnd,
             DWORD *pFlag) = 0;
        
    };
    
#else 	

    typedef struct IZcadToolContextMenuVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolContextMenu * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolContextMenu * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolContextMenu * This);
        
         HRESULT ( STDMETHODCALLTYPE *Customize )( 
            IZcadToolContextMenu * This,
             int nContextFlag,
             DWORD_PTR hMenu,
             UINT idCmdFirst,
             UINT idCmdLast,
             GUID *pPaletteId,
             DWORD *pFlag);
        
         HRESULT ( STDMETHODCALLTYPE *GetMenuHelp )( 
            IZcadToolContextMenu * This,
             UINT idCmd,
             BSTR *pbstrHelpText);
        
         HRESULT ( STDMETHODCALLTYPE *InvokeMenuCommand )( 
            IZcadToolContextMenu * This,
             UINT idCmd,
             GUID *pPaletteId,
             DWORD_PTR hWnd,
             DWORD *pFlag);
        
        END_INTERFACE
    } IZcadToolContextMenuVtbl;

    interface IZcadToolContextMenu
    {
        CONST_VTBL struct IZcadToolContextMenuVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolContextMenu_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject)) 

#define IZcadToolContextMenu_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This)) 

#define IZcadToolContextMenu_Release(This)	\
    ((This)->lpVtbl -> Release(This)) 


#define IZcadToolContextMenu_Customize(This,nContextFlag,hMenu,idCmdFirst,idCmdLast,pPaletteId,pFlag)	\
    ((This)->lpVtbl -> Customize(This,nContextFlag,hMenu,idCmdFirst,idCmdLast,pPaletteId,pFlag)) 

#define IZcadToolContextMenu_GetMenuHelp(This,idCmd,pbstrHelpText)	\
    ((This)->lpVtbl -> GetMenuHelp(This,idCmd,pbstrHelpText)) 

#define IZcadToolContextMenu_InvokeMenuCommand(This,idCmd,pPaletteId,hWnd,pFlag)	\
    ((This)->lpVtbl -> InvokeMenuCommand(This,idCmd,pPaletteId,hWnd,pFlag)) 

#endif 


#endif 	




#endif 	


#ifndef __IZcadTool_INTERFACE_DEFINED__
#define __IZcadTool_INTERFACE_DEFINED__


 


EXTERN_C const IID IID_IZcadTool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC9231AF-5A17-11E7-B72E-BC5FF42AC839")
    IZcadTool : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE get_EditMode( 
             long *pVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetStockTool( 
             IUnknown **ppToolClass) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE SetToolProperties( 
             IUnknown *pProp) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE Load( 
             IUnknown *pXmlElement) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE Save( 
             IUnknown *pXmlElement) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE Execute( 
             LONG_PTR lFlag,
             DWORD_PTR hWnd,
             DWORD point,
             DWORD dwKeyState) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetData( 
             VARIANT *pObjUnkArray,
             VARIANT *pDynUnkArray) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE BeginEdit( void) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE Edit( 
             IUnknown *pProp,
             LONG_PTR hWndParent,
             VARIANT_BOOL *pRet) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE EndEdit( 
             VARIANT_BOOL bEditCancelled) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE New( void) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetDropTarget( 
             IUnknown **ppDropTarget) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetContextMenu( 
             INT_PTR nContextFlag,
             DWORD_PTR hMenu,
             UINT idCmdFirst,
             UINT idCmdLast,
             DWORD_PTR *pFlag) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetCommandString( 
             UINT idCmd,
             BSTR *pbstrHelpText) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE InvokeCommand( 
             UINT idCmd,
             DWORD_PTR hWnd) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetDragDropContextInfo( 
             IUnknown *pIUnknown,
             BSTR *pbstrText,
             DWORD *pFlag) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE Dropped( 
             BSTR bstrUrl) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE Refreshed( 
             BSTR bstrUrl) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE SetEditorWindow( 
             LONG_PTR hWndEditor,
             IUnknown *pPropInspector) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE ValidateEditChanges( void) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetToolProperties( 
             IUnknown **pToolProp) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE BeginMultipleEdit( 
             VARIANT tools,
             VARIANT stockToolIds) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE EndMultipleEdit( 
             VARIANT tools,
             VARIANT stockToolIds,
             VARIANT_BOOL bEditCancelled) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE MultipleEdit( 
             VARIANT tools,
             VARIANT stockToolIds,
             LONG_PTR hWndParent,
             VARIANT_BOOL *pRet) = 0;
        
    };
    
#else 	

    typedef struct IZcadToolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadTool * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadTool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadTool * This);
        
         HRESULT ( STDMETHODCALLTYPE *get_EditMode )( 
            IZcadTool * This,
             long *pVal);
        
         HRESULT ( STDMETHODCALLTYPE *GetStockTool )( 
            IZcadTool * This,
             IUnknown **ppToolClass);
        
         HRESULT ( STDMETHODCALLTYPE *SetToolProperties )( 
            IZcadTool * This,
             IUnknown *pProp);
        
         HRESULT ( STDMETHODCALLTYPE *Load )( 
            IZcadTool * This,
             IUnknown *pXmlElement);
        
         HRESULT ( STDMETHODCALLTYPE *Save )( 
            IZcadTool * This,
             IUnknown *pXmlElement);
        
         HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IZcadTool * This,
             LONG_PTR lFlag,
             DWORD_PTR hWnd,
             DWORD point,
             DWORD dwKeyState);
        
         HRESULT ( STDMETHODCALLTYPE *GetData )( 
            IZcadTool * This,
             VARIANT *pObjUnkArray,
             VARIANT *pDynUnkArray);
        
         HRESULT ( STDMETHODCALLTYPE *BeginEdit )( 
            IZcadTool * This);
        
         HRESULT ( STDMETHODCALLTYPE *Edit )( 
            IZcadTool * This,
             IUnknown *pProp,
             LONG_PTR hWndParent,
             VARIANT_BOOL *pRet);
        
         HRESULT ( STDMETHODCALLTYPE *EndEdit )( 
            IZcadTool * This,
             VARIANT_BOOL bEditCancelled);
        
         HRESULT ( STDMETHODCALLTYPE *New )( 
            IZcadTool * This);
        
         HRESULT ( STDMETHODCALLTYPE *GetDropTarget )( 
            IZcadTool * This,
             IUnknown **ppDropTarget);
        
         HRESULT ( STDMETHODCALLTYPE *GetContextMenu )( 
            IZcadTool * This,
             INT_PTR nContextFlag,
             DWORD_PTR hMenu,
             UINT idCmdFirst,
             UINT idCmdLast,
             DWORD_PTR *pFlag);
        
         HRESULT ( STDMETHODCALLTYPE *GetCommandString )( 
            IZcadTool * This,
             UINT idCmd,
             BSTR *pbstrHelpText);
        
         HRESULT ( STDMETHODCALLTYPE *InvokeCommand )( 
            IZcadTool * This,
             UINT idCmd,
             DWORD_PTR hWnd);
        
         HRESULT ( STDMETHODCALLTYPE *GetDragDropContextInfo )( 
            IZcadTool * This,
             IUnknown *pIUnknown,
             BSTR *pbstrText,
             DWORD *pFlag);
        
         HRESULT ( STDMETHODCALLTYPE *Dropped )( 
            IZcadTool * This,
             BSTR bstrUrl);
        
         HRESULT ( STDMETHODCALLTYPE *Refreshed )( 
            IZcadTool * This,
             BSTR bstrUrl);
        
         HRESULT ( STDMETHODCALLTYPE *SetEditorWindow )( 
            IZcadTool * This,
             LONG_PTR hWndEditor,
             IUnknown *pPropInspector);
        
         HRESULT ( STDMETHODCALLTYPE *ValidateEditChanges )( 
            IZcadTool * This);
        
         HRESULT ( STDMETHODCALLTYPE *GetToolProperties )( 
            IZcadTool * This,
             IUnknown **pToolProp);
        
         HRESULT ( STDMETHODCALLTYPE *BeginMultipleEdit )( 
            IZcadTool * This,
             VARIANT tools,
             VARIANT stockToolIds);
        
         HRESULT ( STDMETHODCALLTYPE *EndMultipleEdit )( 
            IZcadTool * This,
             VARIANT tools,
             VARIANT stockToolIds,
             VARIANT_BOOL bEditCancelled);
        
         HRESULT ( STDMETHODCALLTYPE *MultipleEdit )( 
            IZcadTool * This,
             VARIANT tools,
             VARIANT stockToolIds,
             LONG_PTR hWndParent,
             VARIANT_BOOL *pRet);
        
        END_INTERFACE
    } IZcadToolVtbl;

    interface IZcadTool
    {
        CONST_VTBL struct IZcadToolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadTool_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject)) 

#define IZcadTool_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This)) 

#define IZcadTool_Release(This)	\
    ((This)->lpVtbl -> Release(This)) 


#define IZcadTool_get_EditMode(This,pVal)	\
    ((This)->lpVtbl -> get_EditMode(This,pVal)) 

#define IZcadTool_GetStockTool(This,ppToolClass)	\
    ((This)->lpVtbl -> GetStockTool(This,ppToolClass)) 

#define IZcadTool_SetToolProperties(This,pProp)	\
    ((This)->lpVtbl -> SetToolProperties(This,pProp)) 

#define IZcadTool_Load(This,pXmlElement)	\
    ((This)->lpVtbl -> Load(This,pXmlElement)) 

#define IZcadTool_Save(This,pXmlElement)	\
    ((This)->lpVtbl -> Save(This,pXmlElement)) 

#define IZcadTool_Execute(This,lFlag,hWnd,point,dwKeyState)	\
    ((This)->lpVtbl -> Execute(This,lFlag,hWnd,point,dwKeyState)) 

#define IZcadTool_GetData(This,pObjUnkArray,pDynUnkArray)	\
    ((This)->lpVtbl -> GetData(This,pObjUnkArray,pDynUnkArray)) 

#define IZcadTool_BeginEdit(This)	\
    ((This)->lpVtbl -> BeginEdit(This)) 

#define IZcadTool_Edit(This,pProp,hWndParent,pRet)	\
    ((This)->lpVtbl -> Edit(This,pProp,hWndParent,pRet)) 

#define IZcadTool_EndEdit(This,bEditCancelled)	\
    ((This)->lpVtbl -> EndEdit(This,bEditCancelled)) 

#define IZcadTool_New(This)	\
    ((This)->lpVtbl -> New(This)) 

#define IZcadTool_GetDropTarget(This,ppDropTarget)	\
    ((This)->lpVtbl -> GetDropTarget(This,ppDropTarget)) 

#define IZcadTool_GetContextMenu(This,nContextFlag,hMenu,idCmdFirst,idCmdLast,pFlag)	\
    ((This)->lpVtbl -> GetContextMenu(This,nContextFlag,hMenu,idCmdFirst,idCmdLast,pFlag)) 

#define IZcadTool_GetCommandString(This,idCmd,pbstrHelpText)	\
    ((This)->lpVtbl -> GetCommandString(This,idCmd,pbstrHelpText)) 

#define IZcadTool_InvokeCommand(This,idCmd,hWnd)	\
    ((This)->lpVtbl -> InvokeCommand(This,idCmd,hWnd)) 

#define IZcadTool_GetDragDropContextInfo(This,pIUnknown,pbstrText,pFlag)	\
    ((This)->lpVtbl -> GetDragDropContextInfo(This,pIUnknown,pbstrText,pFlag)) 

#define IZcadTool_Dropped(This,bstrUrl)	\
    ((This)->lpVtbl -> Dropped(This,bstrUrl)) 

#define IZcadTool_Refreshed(This,bstrUrl)	\
    ((This)->lpVtbl -> Refreshed(This,bstrUrl)) 

#define IZcadTool_SetEditorWindow(This,hWndEditor,pPropInspector)	\
    ((This)->lpVtbl -> SetEditorWindow(This,hWndEditor,pPropInspector)) 

#define IZcadTool_ValidateEditChanges(This)	\
    ((This)->lpVtbl -> ValidateEditChanges(This)) 

#define IZcadTool_GetToolProperties(This,pToolProp)	\
    ((This)->lpVtbl -> GetToolProperties(This,pToolProp)) 

#define IZcadTool_BeginMultipleEdit(This,tools,stockToolIds)	\
    ((This)->lpVtbl -> BeginMultipleEdit(This,tools,stockToolIds)) 

#define IZcadTool_EndMultipleEdit(This,tools,stockToolIds,bEditCancelled)	\
    ((This)->lpVtbl -> EndMultipleEdit(This,tools,stockToolIds,bEditCancelled)) 

#define IZcadTool_MultipleEdit(This,tools,stockToolIds,hWndParent,pRet)	\
    ((This)->lpVtbl -> MultipleEdit(This,tools,stockToolIds,hWndParent,pRet)) 

#endif 


#endif 	




#endif 	


#ifndef __IZcadTool2_INTERFACE_DEFINED__
#define __IZcadTool2_INTERFACE_DEFINED__


 


EXTERN_C const IID IID_IZcadTool2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC9230CD-5A17-11E7-B72E-BC5FF42AC839")
    IZcadTool2 : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE UpdateImage( void) = 0;
        
    };
    
#else 	

    typedef struct IZcadTool2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadTool2 * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadTool2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadTool2 * This);
        
         HRESULT ( STDMETHODCALLTYPE *UpdateImage )( 
            IZcadTool2 * This);
        
        END_INTERFACE
    } IZcadTool2Vtbl;

    interface IZcadTool2
    {
        CONST_VTBL struct IZcadTool2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadTool2_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject)) 

#define IZcadTool2_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This)) 

#define IZcadTool2_Release(This)	\
    ((This)->lpVtbl -> Release(This)) 


#define IZcadTool2_UpdateImage(This)	\
    ((This)->lpVtbl -> UpdateImage(This)) 

#endif 


#endif 	




#endif 	


#ifndef __IZcadToolFlyoutShape_INTERFACE_DEFINED__
#define __IZcadToolFlyoutShape_INTERFACE_DEFINED__


 


EXTERN_C const IID IID_IZcadToolFlyoutShape;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC9230B2-5A17-11E7-B72E-BC5FF42AC839")
    IZcadToolFlyoutShape : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE SetFlyoutTools( 
             VARIANT *pFlyoutToolIds) = 0;
        
    };
    
#else 	

    typedef struct IZcadToolFlyoutShapeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolFlyoutShape * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolFlyoutShape * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolFlyoutShape * This);
        
         HRESULT ( STDMETHODCALLTYPE *SetFlyoutTools )( 
            IZcadToolFlyoutShape * This,
             VARIANT *pFlyoutToolIds);
        
        END_INTERFACE
    } IZcadToolFlyoutShapeVtbl;

    interface IZcadToolFlyoutShape
    {
        CONST_VTBL struct IZcadToolFlyoutShapeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolFlyoutShape_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject)) 

#define IZcadToolFlyoutShape_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This)) 

#define IZcadToolFlyoutShape_Release(This)	\
    ((This)->lpVtbl -> Release(This)) 


#define IZcadToolFlyoutShape_SetFlyoutTools(This,pFlyoutToolIds)	\
    ((This)->lpVtbl -> SetFlyoutTools(This,pFlyoutToolIds)) 

#endif 


#endif 	




#endif 	


#ifndef __IZcadToolSort_INTERFACE_DEFINED__
#define __IZcadToolSort_INTERFACE_DEFINED__


 


EXTERN_C const IID IID_IZcadToolSort;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC92318B-5A17-11E7-B72E-BC5FF42AC839")
    IZcadToolSort : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE Compare( 
             IUnknown *pTool,
             long lSortOption,
             long *pResult) = 0;
        
    };
    
#else 	

    typedef struct IZcadToolSortVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolSort * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolSort * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolSort * This);
        
         HRESULT ( STDMETHODCALLTYPE *Compare )( 
            IZcadToolSort * This,
             IUnknown *pTool,
             long lSortOption,
             long *pResult);
        
        END_INTERFACE
    } IZcadToolSortVtbl;

    interface IZcadToolSort
    {
        CONST_VTBL struct IZcadToolSortVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolSort_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject)) 

#define IZcadToolSort_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This)) 

#define IZcadToolSort_Release(This)	\
    ((This)->lpVtbl -> Release(This)) 


#define IZcadToolSort_Compare(This,pTool,lSortOption,pResult)	\
    ((This)->lpVtbl -> Compare(This,pTool,lSortOption,pResult)) 

#endif 


#endif 	




#endif 	


#ifndef __IZcadToolDropTarget_INTERFACE_DEFINED__
#define __IZcadToolDropTarget_INTERFACE_DEFINED__


 


EXTERN_C const IID IID_IZcadToolDropTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC9231AA-5A17-11E7-B72E-BC5FF42AC839")
    IZcadToolDropTarget : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE DragEnter( 
             IDataObject *pDataObj,
             DWORD grfKeyState,
             POINTL pt,
             DWORD *pdwEffect) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE DragOver( 
             DWORD grfKeyState,
             POINTL pt,
             DWORD *pdwEffect) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE DragLeave( void) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE Drop( 
             IDataObject *pDataObj,
             DWORD grfKeyState,
             POINTL pt,
             DWORD *pdwEffect,
             GUID *pCurrentStockToolId,
             GUID *pParentId,
             VARIANT *pNewToolIds) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetDragDropContextMenuItem( 
             IUnknown *pIUnknown,
             BSTR *pbstrText,
             DWORD *pFlag) = 0;
        
    };
    
#else 	

    typedef struct IZcadToolDropTargetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolDropTarget * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolDropTarget * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolDropTarget * This);
        
         HRESULT ( STDMETHODCALLTYPE *DragEnter )( 
            IZcadToolDropTarget * This,
             IDataObject *pDataObj,
             DWORD grfKeyState,
             POINTL pt,
             DWORD *pdwEffect);
        
         HRESULT ( STDMETHODCALLTYPE *DragOver )( 
            IZcadToolDropTarget * This,
             DWORD grfKeyState,
             POINTL pt,
             DWORD *pdwEffect);
        
         HRESULT ( STDMETHODCALLTYPE *DragLeave )( 
            IZcadToolDropTarget * This);
        
         HRESULT ( STDMETHODCALLTYPE *Drop )( 
            IZcadToolDropTarget * This,
             IDataObject *pDataObj,
             DWORD grfKeyState,
             POINTL pt,
             DWORD *pdwEffect,
             GUID *pCurrentStockToolId,
             GUID *pParentId,
             VARIANT *pNewToolIds);
        
         HRESULT ( STDMETHODCALLTYPE *GetDragDropContextMenuItem )( 
            IZcadToolDropTarget * This,
             IUnknown *pIUnknown,
             BSTR *pbstrText,
             DWORD *pFlag);
        
        END_INTERFACE
    } IZcadToolDropTargetVtbl;

    interface IZcadToolDropTarget
    {
        CONST_VTBL struct IZcadToolDropTargetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolDropTarget_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject)) 

#define IZcadToolDropTarget_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This)) 

#define IZcadToolDropTarget_Release(This)	\
    ((This)->lpVtbl -> Release(This)) 


#define IZcadToolDropTarget_DragEnter(This,pDataObj,grfKeyState,pt,pdwEffect)	\
    ((This)->lpVtbl -> DragEnter(This,pDataObj,grfKeyState,pt,pdwEffect)) 

#define IZcadToolDropTarget_DragOver(This,grfKeyState,pt,pdwEffect)	\
    ((This)->lpVtbl -> DragOver(This,grfKeyState,pt,pdwEffect)) 

#define IZcadToolDropTarget_DragLeave(This)	\
    ((This)->lpVtbl -> DragLeave(This)) 

#define IZcadToolDropTarget_Drop(This,pDataObj,grfKeyState,pt,pdwEffect,pCurrentStockToolId,pParentId,pNewToolIds)	\
    ((This)->lpVtbl -> Drop(This,pDataObj,grfKeyState,pt,pdwEffect,pCurrentStockToolId,pParentId,pNewToolIds)) 

#define IZcadToolDropTarget_GetDragDropContextMenuItem(This,pIUnknown,pbstrText,pFlag)	\
    ((This)->lpVtbl -> GetDragDropContextMenuItem(This,pIUnknown,pbstrText,pFlag)) 

#endif 


#endif 	




#endif 	


#ifndef __IZcadToolDragSource_INTERFACE_DEFINED__
#define __IZcadToolDragSource_INTERFACE_DEFINED__


 


EXTERN_C const IID IID_IZcadToolDragSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC923052-5A17-11E7-B72E-BC5FF42AC839")
    IZcadToolDragSource : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE BeginDrag( 
             VARIANT *pToolIds,
             VARIANT *pAllStockToolIds,
             GUID *pCurrentStockToolId,
             IDataObject *pDataObject,
             DWORD dwKeyState) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE DragInProgress( 
             DWORD dwDropEffect) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE EndDrag( 
             DWORD dwDropEffect) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE DragEnterDrawing( 
             IDataObject *pDataObject,
             DWORD grfKeyState,
             POINTL pt,
             DWORD *pDropEffect) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE DragOverDrawing( 
             DWORD grfKeyState,
             POINTL pt,
             DWORD *pDropEffect) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE DragLeaveDrawing( void) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE DropInDrawing( 
             IDataObject *pDataObject,
             DWORD grfKeyState,
             POINTL pt,
             DWORD *pDropEffect) = 0;
        
    };
    
#else 	

    typedef struct IZcadToolDragSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolDragSource * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolDragSource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolDragSource * This);
        
         HRESULT ( STDMETHODCALLTYPE *BeginDrag )( 
            IZcadToolDragSource * This,
             VARIANT *pToolIds,
             VARIANT *pAllStockToolIds,
             GUID *pCurrentStockToolId,
             IDataObject *pDataObject,
             DWORD dwKeyState);
        
         HRESULT ( STDMETHODCALLTYPE *DragInProgress )( 
            IZcadToolDragSource * This,
             DWORD dwDropEffect);
        
         HRESULT ( STDMETHODCALLTYPE *EndDrag )( 
            IZcadToolDragSource * This,
             DWORD dwDropEffect);
        
         HRESULT ( STDMETHODCALLTYPE *DragEnterDrawing )( 
            IZcadToolDragSource * This,
             IDataObject *pDataObject,
             DWORD grfKeyState,
             POINTL pt,
             DWORD *pDropEffect);
        
         HRESULT ( STDMETHODCALLTYPE *DragOverDrawing )( 
            IZcadToolDragSource * This,
             DWORD grfKeyState,
             POINTL pt,
             DWORD *pDropEffect);
        
         HRESULT ( STDMETHODCALLTYPE *DragLeaveDrawing )( 
            IZcadToolDragSource * This);
        
         HRESULT ( STDMETHODCALLTYPE *DropInDrawing )( 
            IZcadToolDragSource * This,
             IDataObject *pDataObject,
             DWORD grfKeyState,
             POINTL pt,
             DWORD *pDropEffect);
        
        END_INTERFACE
    } IZcadToolDragSourceVtbl;

    interface IZcadToolDragSource
    {
        CONST_VTBL struct IZcadToolDragSourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolDragSource_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject)) 

#define IZcadToolDragSource_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This)) 

#define IZcadToolDragSource_Release(This)	\
    ((This)->lpVtbl -> Release(This)) 


#define IZcadToolDragSource_BeginDrag(This,pToolIds,pAllStockToolIds,pCurrentStockToolId,pDataObject,dwKeyState)	\
    ((This)->lpVtbl -> BeginDrag(This,pToolIds,pAllStockToolIds,pCurrentStockToolId,pDataObject,dwKeyState)) 

#define IZcadToolDragSource_DragInProgress(This,dwDropEffect)	\
    ((This)->lpVtbl -> DragInProgress(This,dwDropEffect)) 

#define IZcadToolDragSource_EndDrag(This,dwDropEffect)	\
    ((This)->lpVtbl -> EndDrag(This,dwDropEffect)) 

#define IZcadToolDragSource_DragEnterDrawing(This,pDataObject,grfKeyState,pt,pDropEffect)	\
    ((This)->lpVtbl -> DragEnterDrawing(This,pDataObject,grfKeyState,pt,pDropEffect)) 

#define IZcadToolDragSource_DragOverDrawing(This,grfKeyState,pt,pDropEffect)	\
    ((This)->lpVtbl -> DragOverDrawing(This,grfKeyState,pt,pDropEffect)) 

#define IZcadToolDragSource_DragLeaveDrawing(This)	\
    ((This)->lpVtbl -> DragLeaveDrawing(This)) 

#define IZcadToolDragSource_DropInDrawing(This,pDataObject,grfKeyState,pt,pDropEffect)	\
    ((This)->lpVtbl -> DropInDrawing(This,pDataObject,grfKeyState,pt,pDropEffect)) 

#endif 


#endif 	




#endif 	


#ifndef __IZcadToolCopyPaste_INTERFACE_DEFINED__
#define __IZcadToolCopyPaste_INTERFACE_DEFINED__


 


EXTERN_C const IID IID_IZcadToolCopyPaste;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC923129-5A17-11E7-B72E-BC5FF42AC839")
    IZcadToolCopyPaste : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE Copy( 
             VARIANT *pToolIds,
             VARIANT *pAllStockToolIds,
             GUID *pCurrentStockToolId,
             IDataObject *pDataObject) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE Paste( 
             GUID *pCurrentStockToolId,
             GUID *pParentId,
             IDataObject *pDataObject,
             VARIANT *pNewToolIds) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE CanPaste( 
             IDataObject *pDataObject,
             VARIANT_BOOL *pCanPaste) = 0;
        
    };
    
#else 	

    typedef struct IZcadToolCopyPasteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolCopyPaste * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolCopyPaste * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolCopyPaste * This);
        
         HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IZcadToolCopyPaste * This,
             VARIANT *pToolIds,
             VARIANT *pAllStockToolIds,
             GUID *pCurrentStockToolId,
             IDataObject *pDataObject);
        
         HRESULT ( STDMETHODCALLTYPE *Paste )( 
            IZcadToolCopyPaste * This,
             GUID *pCurrentStockToolId,
             GUID *pParentId,
             IDataObject *pDataObject,
             VARIANT *pNewToolIds);
        
         HRESULT ( STDMETHODCALLTYPE *CanPaste )( 
            IZcadToolCopyPaste * This,
             IDataObject *pDataObject,
             VARIANT_BOOL *pCanPaste);
        
        END_INTERFACE
    } IZcadToolCopyPasteVtbl;

    interface IZcadToolCopyPaste
    {
        CONST_VTBL struct IZcadToolCopyPasteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolCopyPaste_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject)) 

#define IZcadToolCopyPaste_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This)) 

#define IZcadToolCopyPaste_Release(This)	\
    ((This)->lpVtbl -> Release(This)) 


#define IZcadToolCopyPaste_Copy(This,pToolIds,pAllStockToolIds,pCurrentStockToolId,pDataObject)	\
    ((This)->lpVtbl -> Copy(This,pToolIds,pAllStockToolIds,pCurrentStockToolId,pDataObject)) 

#define IZcadToolCopyPaste_Paste(This,pCurrentStockToolId,pParentId,pDataObject,pNewToolIds)	\
    ((This)->lpVtbl -> Paste(This,pCurrentStockToolId,pParentId,pDataObject,pNewToolIds)) 

#define IZcadToolCopyPaste_CanPaste(This,pDataObject,pCanPaste)	\
    ((This)->lpVtbl -> CanPaste(This,pDataObject,pCanPaste)) 

#endif 


#endif 	




#endif 	


#ifndef __IZcadToolImage_INTERFACE_DEFINED__
#define __IZcadToolImage_INTERFACE_DEFINED__


 


EXTERN_C const IID IID_IZcadToolImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC922FE9-5A17-11E7-B72E-BC5FF42AC839")
    IZcadToolImage : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE Load( 
             BSTR bsFileName) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE Save( 
             BSTR bsFileName) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE Render( 
             HDC hdc,
             long x,
             long y,
             long cx,
             long cy,
             long nStyle,
             VARIANT_BOOL bTransparentBitmap) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetSize( 
             long *pWidth,
             long *pHeight) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetType( 
             short *pType) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE IsImageLoaded( 
             BOOL *pVal) = 0;
        
    };
    
#else 	

    typedef struct IZcadToolImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IZcadToolImage * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IZcadToolImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IZcadToolImage * This);
        
         HRESULT ( STDMETHODCALLTYPE *Load )( 
            IZcadToolImage * This,
             BSTR bsFileName);
        
         HRESULT ( STDMETHODCALLTYPE *Save )( 
            IZcadToolImage * This,
             BSTR bsFileName);
        
         HRESULT ( STDMETHODCALLTYPE *Render )( 
            IZcadToolImage * This,
             HDC hdc,
             long x,
             long y,
             long cx,
             long cy,
             long nStyle,
             VARIANT_BOOL bTransparentBitmap);
        
         HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            IZcadToolImage * This,
             long *pWidth,
             long *pHeight);
        
         HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IZcadToolImage * This,
             short *pType);
        
         HRESULT ( STDMETHODCALLTYPE *IsImageLoaded )( 
            IZcadToolImage * This,
             BOOL *pVal);
        
        END_INTERFACE
    } IZcadToolImageVtbl;

    interface IZcadToolImage
    {
        CONST_VTBL struct IZcadToolImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZcadToolImage_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject)) 

#define IZcadToolImage_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This)) 

#define IZcadToolImage_Release(This)	\
    ((This)->lpVtbl -> Release(This)) 


#define IZcadToolImage_Load(This,bsFileName)	\
    ((This)->lpVtbl -> Load(This,bsFileName)) 

#define IZcadToolImage_Save(This,bsFileName)	\
    ((This)->lpVtbl -> Save(This,bsFileName)) 

#define IZcadToolImage_Render(This,hdc,x,y,cx,cy,nStyle,bTransparentBitmap)	\
    ((This)->lpVtbl -> Render(This,hdc,x,y,cx,cy,nStyle,bTransparentBitmap)) 

#define IZcadToolImage_GetSize(This,pWidth,pHeight)	\
    ((This)->lpVtbl -> GetSize(This,pWidth,pHeight)) 

#define IZcadToolImage_GetType(This,pType)	\
    ((This)->lpVtbl -> GetType(This,pType)) 

#define IZcadToolImage_IsImageLoaded(This,pVal)	\
    ((This)->lpVtbl -> IsImageLoaded(This,pVal)) 

#endif 


#endif 	




#endif 	



#ifndef __ZcTcLib_LIBRARY_DEFINED__
#define __ZcTcLib_LIBRARY_DEFINED__


 


EXTERN_C const IID LIBID_ZcTcLib;

EXTERN_C const CLSID CLSID_ZcadToolProperties;

#ifdef __cplusplus

class DECLSPEC_UUID("EC923066-5A17-11E7-B72E-BC5FF42AC839")
ZcadToolProperties;
#endif

EXTERN_C const CLSID CLSID_ZcadToolImage;

#ifdef __cplusplus

class DECLSPEC_UUID("EC922FD4-5A17-11E7-B72E-BC5FF42AC839")
ZcadToolImage;
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