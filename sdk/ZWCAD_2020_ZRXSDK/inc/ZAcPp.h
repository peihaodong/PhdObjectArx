
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

#ifndef ___ZcPp_h__
#define ___ZcPp_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif
#ifndef __IZcPpZcadInput_FWD_DEFINED__
#define __IZcPpZcadInput_FWD_DEFINED__
typedef interface IZcPpZcadInput IZcPpZcadInput;
#endif
#ifndef __IZcPpPalette_FWD_DEFINED__
#define __IZcPpPalette_FWD_DEFINED__
typedef interface IZcPpPalette IZcPpPalette;
#endif
#ifndef __IZcPpPaletteEvents_FWD_DEFINED__
#define __IZcPpPaletteEvents_FWD_DEFINED__
typedef interface IZcPpPaletteEvents IZcPpPaletteEvents;
#endif
#ifndef __IZcPpPaletteSet_FWD_DEFINED__
#define __IZcPpPaletteSet_FWD_DEFINED__
typedef interface IZcPpPaletteSet IZcPpPaletteSet;
#endif
#ifndef __IZcPpPaletteSetEvents_FWD_DEFINED__
#define __IZcPpPaletteSetEvents_FWD_DEFINED__
typedef interface IZcPpPaletteSetEvents IZcPpPaletteSetEvents;
#endif
#ifndef __IZcPpNavTreeNode_FWD_DEFINED__
#define __IZcPpNavTreeNode_FWD_DEFINED__
typedef interface IZcPpNavTreeNode IZcPpNavTreeNode;
#endif
#ifndef __IZcPpNavTreeNodeCollectionIter_FWD_DEFINED__
#define __IZcPpNavTreeNodeCollectionIter_FWD_DEFINED__
typedef interface IZcPpNavTreeNodeCollectionIter IZcPpNavTreeNodeCollectionIter;
#endif
#ifndef __IZcPpNavTreeNodeCollection_FWD_DEFINED__
#define __IZcPpNavTreeNodeCollection_FWD_DEFINED__
typedef interface IZcPpNavTreeNodeCollection IZcPpNavTreeNodeCollection;
#endif
#ifndef __IZcPpNavTreeCmdBtn_FWD_DEFINED__
#define __IZcPpNavTreeCmdBtn_FWD_DEFINED__
typedef interface IZcPpNavTreeCmdBtn IZcPpNavTreeCmdBtn;
#endif
#ifndef __IZcPpNavTreeCmdBtnCollectionIter_FWD_DEFINED__
#define __IZcPpNavTreeCmdBtnCollectionIter_FWD_DEFINED__
typedef interface IZcPpNavTreeCmdBtnCollectionIter IZcPpNavTreeCmdBtnCollectionIter;
#endif
#ifndef __IZcPpNavTreeCmdBtnCollection_FWD_DEFINED__
#define __IZcPpNavTreeCmdBtnCollection_FWD_DEFINED__
typedef interface IZcPpNavTreeCmdBtnCollection IZcPpNavTreeCmdBtnCollection;
#endif
#ifndef __IZcPpNavTree_FWD_DEFINED__
#define __IZcPpNavTree_FWD_DEFINED__
typedef interface IZcPpNavTree IZcPpNavTree;
#endif
#ifndef __IZcPpNavTreeEvents_FWD_DEFINED__
#define __IZcPpNavTreeEvents_FWD_DEFINED__
typedef interface IZcPpNavTreeEvents IZcPpNavTreeEvents;
#endif
#ifndef __IZcPpPalette2_FWD_DEFINED__
#define __IZcPpPalette2_FWD_DEFINED__
typedef interface IZcPpPalette2 IZcPpPalette2;
#endif
#ifndef __ZcPpZcadInput_FWD_DEFINED__
#define __ZcPpZcadInput_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPpZcadInput ZcPpZcadInput;
#else
typedef struct ZcPpZcadInput ZcPpZcadInput;
#endif

#endif
#ifndef __ZcPpPaletteSet_FWD_DEFINED__
#define __ZcPpPaletteSet_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPpPaletteSet ZcPpPaletteSet;
#else
typedef struct ZcPpPaletteSet ZcPpPaletteSet;
#endif

#endif
#ifndef __ZcPpPalette_FWD_DEFINED__
#define __ZcPpPalette_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPpPalette ZcPpPalette;
#else
typedef struct ZcPpPalette ZcPpPalette;
#endif

#endif
#ifndef __ZcPpPalette2_FWD_DEFINED__
#define __ZcPpPalette2_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPpPalette2 ZcPpPalette2;
#else
typedef struct ZcPpPalette2 ZcPpPalette2;
#endif

#endif
#ifndef __ZcPpNavTree_FWD_DEFINED__
#define __ZcPpNavTree_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPpNavTree ZcPpNavTree;
#else
typedef struct ZcPpNavTree ZcPpNavTree;
#endif

#endif
#ifndef __ZcPpNavTreeNode_FWD_DEFINED__
#define __ZcPpNavTreeNode_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZcPpNavTreeNode ZcPpNavTreeNode;
#else
typedef struct ZcPpNavTreeNode ZcPpNavTreeNode;
#endif

#endif
#include "oaidl.h"
#include "ocidl.h"
#include "acpi.h"

#ifdef __cplusplus
extern "C"{
#endif

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * );
#define ZCPPINPUT_ID_VALUE           1
#define ZCPPINPUT_ID_STATUS          2
#define ZCPPINPUT_ID_DOCUMENT        3
#define ZCPPINPUT_ID_CRONLY          4
#define ZCPPINPUT_ID_PROMPT          5
#define ZCPPINPUT_ID_PROMPT2         6
#define ZCPPINPUT_ID_INITGETBIT      7
#define ZCPPINPUT_ID_INITGETKWORD    8
#define ZCPPINPUT_ID_BASEPOINT       9
#define ZCPPINPUT_ID_PROMPTTYPE      10
#define ZCPPINPUT_ID_ENABLENOTIFICATION 11
extern RPC_IF_HANDLE __MIDL_itf_ZcPp_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ZcPp_0000_v0_0_s_ifspec;

#ifndef __IZcPpZcadInput_INTERFACE_DEFINED__
#define __IZcPpZcadInput_INTERFACE_DEFINED__
typedef 
enum StatusType
    {
        StatusPrompting	= -1,
        StatusRTNORM	= 5100,
        StatusRTERROR	= -5001,
        StatusRTCAN	= -5002,
        StatusRTNONE	= 5000,
        StatusRTREJ	= -5003,
        StatusRTKWORD	= -5005,
        StatusMODELESS	= 5027
    } 	StatusType;

typedef 
enum PromptType
    {
        GetAngle	= 1,
        GetCorner	= 2,
        GetDist	= 3,
        GetInt	= 4,
        GetKword	= 5,
        GetOrient	= 6,
        GetPoint	= 7,
        GetReal	= 8,
        GetString	= 9,
        EntSel	= 10
    } 	PromptType;
EXTERN_C const IID IID_IZcPpZcadInput;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("21186390-9FDA-40D7-82C1-FB8C5153B91E")
    IZcPpZcadInput : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE get_Value(
             VARIANT *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_Value(
             VARIANT newVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_Status(
             long *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_Status(
             long newVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_Document(
             IUnknown **pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_Document(
             IUnknown *newVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_CrOnly(
             VARIANT_BOOL *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_CrOnly(
             VARIANT_BOOL newVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_Prompt(
             BSTR *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_Prompt(
             BSTR newVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_Prompt2(
             BSTR *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_Prompt2(
             BSTR newVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_InitGetBit(
             long *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_InitGetBit(
             long newVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_InitGetKword(
             BSTR *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_InitGetKword(
             BSTR newVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_BasePoint(
             VARIANT *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_BasePoint(
             VARIANT newVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_PromptType(
             short *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_PromptType(
             short newVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_EnableNotification(
             VARIANT_BOOL *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_EnableNotification(
             VARIANT_BOOL newVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE DoPrompt( void) = 0;

        virtual  HRESULT STDMETHODCALLTYPE CancelPrompt( void) = 0;

    };

#else

    typedef struct IZcPpZcadInputVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpZcadInput * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpZcadInput * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpZcadInput * This);

         HRESULT ( STDMETHODCALLTYPE *get_Value )(
            IZcPpZcadInput * This,
             VARIANT *pVal);

         HRESULT ( STDMETHODCALLTYPE *put_Value )(
            IZcPpZcadInput * This,
             VARIANT newVal);

         HRESULT ( STDMETHODCALLTYPE *get_Status )(
            IZcPpZcadInput * This,
             long *pVal);

         HRESULT ( STDMETHODCALLTYPE *put_Status )(
            IZcPpZcadInput * This,
             long newVal);

         HRESULT ( STDMETHODCALLTYPE *get_Document )(
            IZcPpZcadInput * This,
             IUnknown **pVal);

         HRESULT ( STDMETHODCALLTYPE *put_Document )(
            IZcPpZcadInput * This,
             IUnknown *newVal);

         HRESULT ( STDMETHODCALLTYPE *get_CrOnly )(
            IZcPpZcadInput * This,
             VARIANT_BOOL *pVal);

         HRESULT ( STDMETHODCALLTYPE *put_CrOnly )(
            IZcPpZcadInput * This,
             VARIANT_BOOL newVal);

         HRESULT ( STDMETHODCALLTYPE *get_Prompt )(
            IZcPpZcadInput * This,
             BSTR *pVal);

         HRESULT ( STDMETHODCALLTYPE *put_Prompt )(
            IZcPpZcadInput * This,
             BSTR newVal);

         HRESULT ( STDMETHODCALLTYPE *get_Prompt2 )(
            IZcPpZcadInput * This,
             BSTR *pVal);

         HRESULT ( STDMETHODCALLTYPE *put_Prompt2 )(
            IZcPpZcadInput * This,
             BSTR newVal);

         HRESULT ( STDMETHODCALLTYPE *get_InitGetBit )(
            IZcPpZcadInput * This,
             long *pVal);

         HRESULT ( STDMETHODCALLTYPE *put_InitGetBit )(
            IZcPpZcadInput * This,
             long newVal);

         HRESULT ( STDMETHODCALLTYPE *get_InitGetKword )(
            IZcPpZcadInput * This,
             BSTR *pVal);

         HRESULT ( STDMETHODCALLTYPE *put_InitGetKword )(
            IZcPpZcadInput * This,
             BSTR newVal);

         HRESULT ( STDMETHODCALLTYPE *get_BasePoint )(
            IZcPpZcadInput * This,
             VARIANT *pVal);

         HRESULT ( STDMETHODCALLTYPE *put_BasePoint )(
            IZcPpZcadInput * This,
             VARIANT newVal);

         HRESULT ( STDMETHODCALLTYPE *get_PromptType )(
            IZcPpZcadInput * This,
             short *pVal);

         HRESULT ( STDMETHODCALLTYPE *put_PromptType )(
            IZcPpZcadInput * This,
             short newVal);

         HRESULT ( STDMETHODCALLTYPE *get_EnableNotification )(
            IZcPpZcadInput * This,
             VARIANT_BOOL *pVal);

         HRESULT ( STDMETHODCALLTYPE *put_EnableNotification )(
            IZcPpZcadInput * This,
             VARIANT_BOOL newVal);

         HRESULT ( STDMETHODCALLTYPE *DoPrompt )(
            IZcPpZcadInput * This);

         HRESULT ( STDMETHODCALLTYPE *CancelPrompt )(
            IZcPpZcadInput * This);

        END_INTERFACE
    } IZcPpZcadInputVtbl;

    interface IZcPpZcadInput
    {
        CONST_VTBL struct IZcPpZcadInputVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpZcadInput_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpZcadInput_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpZcadInput_Release(This)	\
    ((This)->lpVtbl -> Release(This))
#define IZcPpZcadInput_get_Value(This,pVal)	\
    ((This)->lpVtbl -> get_Value(This,pVal))

#define IZcPpZcadInput_put_Value(This,newVal)	\
    ((This)->lpVtbl -> put_Value(This,newVal))

#define IZcPpZcadInput_get_Status(This,pVal)	\
    ((This)->lpVtbl -> get_Status(This,pVal))

#define IZcPpZcadInput_put_Status(This,newVal)	\
    ((This)->lpVtbl -> put_Status(This,newVal))

#define IZcPpZcadInput_get_Document(This,pVal)	\
    ((This)->lpVtbl -> get_Document(This,pVal))

#define IZcPpZcadInput_put_Document(This,newVal)	\
    ((This)->lpVtbl -> put_Document(This,newVal))

#define IZcPpZcadInput_get_CrOnly(This,pVal)	\
    ((This)->lpVtbl -> get_CrOnly(This,pVal))

#define IZcPpZcadInput_put_CrOnly(This,newVal)	\
    ((This)->lpVtbl -> put_CrOnly(This,newVal))

#define IZcPpZcadInput_get_Prompt(This,pVal)	\
    ((This)->lpVtbl -> get_Prompt(This,pVal))

#define IZcPpZcadInput_put_Prompt(This,newVal)	\
    ((This)->lpVtbl -> put_Prompt(This,newVal))

#define IZcPpZcadInput_get_Prompt2(This,pVal)	\
    ((This)->lpVtbl -> get_Prompt2(This,pVal))

#define IZcPpZcadInput_put_Prompt2(This,newVal)	\
    ((This)->lpVtbl -> put_Prompt2(This,newVal))

#define IZcPpZcadInput_get_InitGetBit(This,pVal)	\
    ((This)->lpVtbl -> get_InitGetBit(This,pVal))

#define IZcPpZcadInput_put_InitGetBit(This,newVal)	\
    ((This)->lpVtbl -> put_InitGetBit(This,newVal))

#define IZcPpZcadInput_get_InitGetKword(This,pVal)	\
    ((This)->lpVtbl -> get_InitGetKword(This,pVal))

#define IZcPpZcadInput_put_InitGetKword(This,newVal)	\
    ((This)->lpVtbl -> put_InitGetKword(This,newVal))

#define IZcPpZcadInput_get_BasePoint(This,pVal)	\
    ((This)->lpVtbl -> get_BasePoint(This,pVal))

#define IZcPpZcadInput_put_BasePoint(This,newVal)	\
    ((This)->lpVtbl -> put_BasePoint(This,newVal))

#define IZcPpZcadInput_get_PromptType(This,pVal)	\
    ((This)->lpVtbl -> get_PromptType(This,pVal))

#define IZcPpZcadInput_put_PromptType(This,newVal)	\
    ((This)->lpVtbl -> put_PromptType(This,newVal))

#define IZcPpZcadInput_get_EnableNotification(This,pVal)	\
    ((This)->lpVtbl -> get_EnableNotification(This,pVal))

#define IZcPpZcadInput_put_EnableNotification(This,newVal)	\
    ((This)->lpVtbl -> put_EnableNotification(This,newVal))

#define IZcPpZcadInput_DoPrompt(This)	\
    ((This)->lpVtbl -> DoPrompt(This))

#define IZcPpZcadInput_CancelPrompt(This)	\
    ((This)->lpVtbl -> CancelPrompt(This))

#endif


#endif 	




#endif 	


#ifndef __IZcPpPalette_INTERFACE_DEFINED__
#define __IZcPpPalette_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPpPalette;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1FFB5C38-2566-4150-9CE4-D3406BE08DCC")
    IZcPpPalette : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE get_Name(
             BSTR *name) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_Name(
             BSTR name) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_InspectorControl(
             IZcPiPropertyInspector **pInspector) = 0;

    };

#else

    typedef struct IZcPpPaletteVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpPalette * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpPalette * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpPalette * This);

         HRESULT ( STDMETHODCALLTYPE *get_Name )(
            IZcPpPalette * This,
             BSTR *name);

         HRESULT ( STDMETHODCALLTYPE *put_Name )(
            IZcPpPalette * This,
             BSTR name);

         HRESULT ( STDMETHODCALLTYPE *get_InspectorControl )(
            IZcPpPalette * This,
             IZcPiPropertyInspector **pInspector);

        END_INTERFACE
    } IZcPpPaletteVtbl;

    interface IZcPpPalette
    {
        CONST_VTBL struct IZcPpPaletteVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpPalette_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpPalette_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpPalette_Release(This)	\
    ((This)->lpVtbl -> Release(This))
#define IZcPpPalette_get_Name(This,name)	\
    ((This)->lpVtbl -> get_Name(This,name))

#define IZcPpPalette_put_Name(This,name)	\
    ((This)->lpVtbl -> put_Name(This,name))

#define IZcPpPalette_get_InspectorControl(This,pInspector)	\
    ((This)->lpVtbl -> get_InspectorControl(This,pInspector))

#endif


#endif 	




#endif 	


#ifndef __IZcPpPaletteEvents_INTERFACE_DEFINED__
#define __IZcPpPaletteEvents_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPpPaletteEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3ADCEB15-D5FD-482E-B622-20F8D0A3F03C")
    IZcPpPaletteEvents : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE OnNameChanged(
             BSTR newName) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnSelectionChanged(
             VARIANT *newObjectArray,
             VARIANT *newPropMgrArray,
             VARIANT_BOOL *bHandled) = 0;

    };

#else

    typedef struct IZcPpPaletteEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpPaletteEvents * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpPaletteEvents * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpPaletteEvents * This);

         HRESULT ( STDMETHODCALLTYPE *OnNameChanged )(
            IZcPpPaletteEvents * This,
             BSTR newName);

         HRESULT ( STDMETHODCALLTYPE *OnSelectionChanged )(
            IZcPpPaletteEvents * This,
             VARIANT *newObjectArray,
             VARIANT *newPropMgrArray,
             VARIANT_BOOL *bHandled);

        END_INTERFACE
    } IZcPpPaletteEventsVtbl;

    interface IZcPpPaletteEvents
    {
        CONST_VTBL struct IZcPpPaletteEventsVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpPaletteEvents_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpPaletteEvents_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpPaletteEvents_Release(This)	\
    ((This)->lpVtbl -> Release(This))
#define IZcPpPaletteEvents_OnNameChanged(This,newName)	\
    ((This)->lpVtbl -> OnNameChanged(This,newName))

#define IZcPpPaletteEvents_OnSelectionChanged(This,newObjectArray,newPropMgrArray,bHandled)	\
    ((This)->lpVtbl -> OnSelectionChanged(This,newObjectArray,newPropMgrArray,bHandled))

#endif


#endif 	




#endif 	


#ifndef __IZcPpPaletteSet_INTERFACE_DEFINED__
#define __IZcPpPaletteSet_INTERFACE_DEFINED__
typedef
enum DockPos
    {
        Floating	= -1,
        Left	= 0xe81c,
        Right	= 0xe81d
    } 	DockPos;
EXTERN_C const IID IID_IZcPpPaletteSet;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FC0DB1B9-0B5C-40D0-8411-F612830DF409")
    IZcPpPaletteSet : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE AddPalette(
             IZcPpPalette *pPalette) = 0;

        virtual  HRESULT STDMETHODCALLTYPE DeletePalette(
             IZcPpPalette *pPalette) = 0;

        virtual  HRESULT STDMETHODCALLTYPE InsertPalette(
             int index,
             IZcPpPalette *pPalette) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetPalette(
             int index,
             IZcPpPalette **pPalette) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetPaletteByName(
             BSTR paletteName,
             IZcPpPalette **pPalette) = 0;

        virtual  HRESULT STDMETHODCALLTYPE ActivatePalette(
             IZcPpPalette *pPalette) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_PaletteCount(
             int *nPalettes) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_Visibility(
             VARIANT_BOOL *bIsVisible) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_Visibility(
             VARIANT_BOOL bIsVisible) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_CurrentIndex(
             int *nCurrentIndex) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetDockingState(
             int *nDockPos,
             long *left,
             long *top,
             long *width,
             long *height) = 0;

        virtual  HRESULT STDMETHODCALLTYPE SetDockingState(
             int nDockPos,
             long left,
             long top,
             long width,
             long height) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetFloatingRect(
             long *left,
             long *top,
             long *width,
             long *height) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetDockingRect(
             int *nDockPos,
             long *left,
             long *top,
             long *width,
             long *height) = 0;

    };

#else

    typedef struct IZcPpPaletteSetVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpPaletteSet * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpPaletteSet * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpPaletteSet * This);

         HRESULT ( STDMETHODCALLTYPE *AddPalette )(
            IZcPpPaletteSet * This,
             IZcPpPalette *pPalette);

         HRESULT ( STDMETHODCALLTYPE *DeletePalette )(
            IZcPpPaletteSet * This,
             IZcPpPalette *pPalette);

         HRESULT ( STDMETHODCALLTYPE *InsertPalette )(
            IZcPpPaletteSet * This,
             int index,
             IZcPpPalette *pPalette);

         HRESULT ( STDMETHODCALLTYPE *GetPalette )(
            IZcPpPaletteSet * This,
             int index,
             IZcPpPalette **pPalette);

         HRESULT ( STDMETHODCALLTYPE *GetPaletteByName )(
            IZcPpPaletteSet * This,
             BSTR paletteName,
             IZcPpPalette **pPalette);

         HRESULT ( STDMETHODCALLTYPE *ActivatePalette )(
            IZcPpPaletteSet * This,
             IZcPpPalette *pPalette);

         HRESULT ( STDMETHODCALLTYPE *get_PaletteCount )(
            IZcPpPaletteSet * This,
             int *nPalettes);

         HRESULT ( STDMETHODCALLTYPE *get_Visibility )(
            IZcPpPaletteSet * This,
             VARIANT_BOOL *bIsVisible);

         HRESULT ( STDMETHODCALLTYPE *put_Visibility )(
            IZcPpPaletteSet * This,
             VARIANT_BOOL bIsVisible);

         HRESULT ( STDMETHODCALLTYPE *get_CurrentIndex )(
            IZcPpPaletteSet * This,
             int *nCurrentIndex);

         HRESULT ( STDMETHODCALLTYPE *GetDockingState )(
            IZcPpPaletteSet * This,
             int *nDockPos,
             long *left,
             long *top,
             long *width,
             long *height);

         HRESULT ( STDMETHODCALLTYPE *SetDockingState )(
            IZcPpPaletteSet * This,
             int nDockPos,
             long left,
             long top,
             long width,
             long height);

         HRESULT ( STDMETHODCALLTYPE *GetFloatingRect )(
            IZcPpPaletteSet * This,
             long *left,
             long *top,
             long *width,
             long *height);

         HRESULT ( STDMETHODCALLTYPE *GetDockingRect )(
            IZcPpPaletteSet * This,
             int *nDockPos,
             long *left,
             long *top,
             long *width,
             long *height);

        END_INTERFACE
    } IZcPpPaletteSetVtbl;

    interface IZcPpPaletteSet
    {
        CONST_VTBL struct IZcPpPaletteSetVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpPaletteSet_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpPaletteSet_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpPaletteSet_Release(This)	\
    ((This)->lpVtbl -> Release(This))
#define IZcPpPaletteSet_AddPalette(This,pPalette)	\
    ((This)->lpVtbl -> AddPalette(This,pPalette))

#define IZcPpPaletteSet_DeletePalette(This,pPalette)	\
    ((This)->lpVtbl -> DeletePalette(This,pPalette))

#define IZcPpPaletteSet_InsertPalette(This,index,pPalette)	\
    ((This)->lpVtbl -> InsertPalette(This,index,pPalette))

#define IZcPpPaletteSet_GetPalette(This,index,pPalette)	\
    ((This)->lpVtbl -> GetPalette(This,index,pPalette))

#define IZcPpPaletteSet_GetPaletteByName(This,paletteName,pPalette)	\
    ((This)->lpVtbl -> GetPaletteByName(This,paletteName,pPalette))

#define IZcPpPaletteSet_ActivatePalette(This,pPalette)	\
    ((This)->lpVtbl -> ActivatePalette(This,pPalette))

#define IZcPpPaletteSet_get_PaletteCount(This,nPalettes)	\
    ((This)->lpVtbl -> get_PaletteCount(This,nPalettes))

#define IZcPpPaletteSet_get_Visibility(This,bIsVisible)	\
    ((This)->lpVtbl -> get_Visibility(This,bIsVisible))

#define IZcPpPaletteSet_put_Visibility(This,bIsVisible)	\
    ((This)->lpVtbl -> put_Visibility(This,bIsVisible))

#define IZcPpPaletteSet_get_CurrentIndex(This,nCurrentIndex)	\
    ((This)->lpVtbl -> get_CurrentIndex(This,nCurrentIndex))

#define IZcPpPaletteSet_GetDockingState(This,nDockPos,left,top,width,height)	\
    ((This)->lpVtbl -> GetDockingState(This,nDockPos,left,top,width,height))

#define IZcPpPaletteSet_SetDockingState(This,nDockPos,left,top,width,height)	\
    ((This)->lpVtbl -> SetDockingState(This,nDockPos,left,top,width,height))

#define IZcPpPaletteSet_GetFloatingRect(This,left,top,width,height)	\
    ((This)->lpVtbl -> GetFloatingRect(This,left,top,width,height))

#define IZcPpPaletteSet_GetDockingRect(This,nDockPos,left,top,width,height)	\
    ((This)->lpVtbl -> GetDockingRect(This,nDockPos,left,top,width,height))

#endif


#endif 	




#endif 	

#ifndef __IZcPpPaletteSetEvents_INTERFACE_DEFINED__
#define __IZcPpPaletteSetEvents_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPpPaletteSetEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3B4D50F1-5519-44E7-9F22-0CC1978E83D3")
    IZcPpPaletteSetEvents : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE OnPaletteAdded(
             IZcPpPalette *pNewPalette) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnPaletteDeleted(
             IZcPpPalette *pPalette) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnPaletteActivated(
             IZcPpPalette *pPalette) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnPaletteDeActivated(
             IZcPpPalette *pPalette) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnSelectionChanged(
             VARIANT *newObjectArray,
             VARIANT *newPropMgrArray) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnVisibilityChanged(
             VARIANT_BOOL bIsVisible) = 0;

    };

#else

    typedef struct IZcPpPaletteSetEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpPaletteSetEvents * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpPaletteSetEvents * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpPaletteSetEvents * This);

         HRESULT ( STDMETHODCALLTYPE *OnPaletteAdded )(
            IZcPpPaletteSetEvents * This,
             IZcPpPalette *pNewPalette);

         HRESULT ( STDMETHODCALLTYPE *OnPaletteDeleted )(
            IZcPpPaletteSetEvents * This,
             IZcPpPalette *pPalette);

         HRESULT ( STDMETHODCALLTYPE *OnPaletteActivated )(
            IZcPpPaletteSetEvents * This,
             IZcPpPalette *pPalette);

         HRESULT ( STDMETHODCALLTYPE *OnPaletteDeActivated )(
            IZcPpPaletteSetEvents * This,
             IZcPpPalette *pPalette);

         HRESULT ( STDMETHODCALLTYPE *OnSelectionChanged )(
            IZcPpPaletteSetEvents * This,
             VARIANT *newObjectArray,
             VARIANT *newPropMgrArray);

         HRESULT ( STDMETHODCALLTYPE *OnVisibilityChanged )(
            IZcPpPaletteSetEvents * This,
             VARIANT_BOOL bIsVisible);

        END_INTERFACE
    } IZcPpPaletteSetEventsVtbl;

    interface IZcPpPaletteSetEvents
    {
        CONST_VTBL struct IZcPpPaletteSetEventsVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpPaletteSetEvents_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpPaletteSetEvents_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpPaletteSetEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IZcPpPaletteSetEvents_OnPaletteAdded(This,pNewPalette)	\
    ((This)->lpVtbl -> OnPaletteAdded(This,pNewPalette))

#define IZcPpPaletteSetEvents_OnPaletteDeleted(This,pPalette)	\
    ((This)->lpVtbl -> OnPaletteDeleted(This,pPalette))

#define IZcPpPaletteSetEvents_OnPaletteActivated(This,pPalette)	\
    ((This)->lpVtbl -> OnPaletteActivated(This,pPalette))

#define IZcPpPaletteSetEvents_OnPaletteDeActivated(This,pPalette)	\
    ((This)->lpVtbl -> OnPaletteDeActivated(This,pPalette))

#define IZcPpPaletteSetEvents_OnSelectionChanged(This,newObjectArray,newPropMgrArray)	\
    ((This)->lpVtbl -> OnSelectionChanged(This,newObjectArray,newPropMgrArray))

#define IZcPpPaletteSetEvents_OnVisibilityChanged(This,bIsVisible)	\
    ((This)->lpVtbl -> OnVisibilityChanged(This,bIsVisible))

#endif


#endif 	




#endif 	


#ifndef __IZcPpNavTreeNode_INTERFACE_DEFINED__
#define __IZcPpNavTreeNode_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPpNavTreeNode;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("11E68B1B-2A9F-4B1D-BB58-CD5A43FB6F30")
    IZcPpNavTreeNode : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE get_ID(
             long *pID) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_ParentID(
             long *pID) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_Label(
             BSTR *pLabel) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_LeftIconRes(
             BSTR *pPath) = 0;

        virtual  HRESULT STDMETHODCALLTYPE get_LeftIconResType(
             ULONG *pVal) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetObject(
            VARIANT *pObject) = 0;

    };

#else

    typedef struct IZcPpNavTreeNodeVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpNavTreeNode * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpNavTreeNode * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpNavTreeNode * This);

         HRESULT ( STDMETHODCALLTYPE *get_ID )(
            IZcPpNavTreeNode * This,
             long *pID);

         HRESULT ( STDMETHODCALLTYPE *get_ParentID )(
            IZcPpNavTreeNode * This,
             long *pID);

         HRESULT ( STDMETHODCALLTYPE *get_Label )(
            IZcPpNavTreeNode * This,
             BSTR *pLabel);

         HRESULT ( STDMETHODCALLTYPE *get_LeftIconRes )(
            IZcPpNavTreeNode * This,
             BSTR *pPath);

         HRESULT ( STDMETHODCALLTYPE *get_LeftIconResType )(
            IZcPpNavTreeNode * This,
             ULONG *pVal);

         HRESULT ( STDMETHODCALLTYPE *GetObject )(
            IZcPpNavTreeNode * This,
            VARIANT *pObject);

        END_INTERFACE
    } IZcPpNavTreeNodeVtbl;

    interface IZcPpNavTreeNode
    {
        CONST_VTBL struct IZcPpNavTreeNodeVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpNavTreeNode_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpNavTreeNode_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpNavTreeNode_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IZcPpNavTreeNode_get_ID(This,pID)	\
    ((This)->lpVtbl -> get_ID(This,pID))

#define IZcPpNavTreeNode_get_ParentID(This,pID)	\
    ((This)->lpVtbl -> get_ParentID(This,pID))

#define IZcPpNavTreeNode_get_Label(This,pLabel)	\
    ((This)->lpVtbl -> get_Label(This,pLabel))

#define IZcPpNavTreeNode_get_LeftIconRes(This,pPath)	\
    ((This)->lpVtbl -> get_LeftIconRes(This,pPath))

#define IZcPpNavTreeNode_get_LeftIconResType(This,pVal)	\
    ((This)->lpVtbl -> get_LeftIconResType(This,pVal))

#define IZcPpNavTreeNode_GetObject(This,pObject)	\
    ((This)->lpVtbl -> GetObject(This,pObject))

#endif


#endif 	




#endif 	


#ifndef __IZcPpNavTreeNodeCollectionIter_INTERFACE_DEFINED__
#define __IZcPpNavTreeNodeCollectionIter_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPpNavTreeNodeCollectionIter;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("82AE492A-56B9-45CB-81DD-9678CA98E3B4")
    IZcPpNavTreeNodeCollectionIter : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE Start( void) = 0;

        virtual  HRESULT STDMETHODCALLTYPE Next( void) = 0;

        virtual  HRESULT STDMETHODCALLTYPE Current(
             IZcPpNavTreeNode **pNode) = 0;

        virtual  HRESULT STDMETHODCALLTYPE Done(
             VARIANT_BOOL *pBool) = 0;

    };

#else

    typedef struct IZcPpNavTreeNodeCollectionIterVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpNavTreeNodeCollectionIter * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpNavTreeNodeCollectionIter * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpNavTreeNodeCollectionIter * This);

         HRESULT ( STDMETHODCALLTYPE *Start )(
            IZcPpNavTreeNodeCollectionIter * This);

         HRESULT ( STDMETHODCALLTYPE *Next )(
            IZcPpNavTreeNodeCollectionIter * This);

         HRESULT ( STDMETHODCALLTYPE *Current )(
            IZcPpNavTreeNodeCollectionIter * This,
             IZcPpNavTreeNode **pNode);

         HRESULT ( STDMETHODCALLTYPE *Done )(
            IZcPpNavTreeNodeCollectionIter * This,
             VARIANT_BOOL *pBool);

        END_INTERFACE
    } IZcPpNavTreeNodeCollectionIterVtbl;

    interface IZcPpNavTreeNodeCollectionIter
    {
        CONST_VTBL struct IZcPpNavTreeNodeCollectionIterVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpNavTreeNodeCollectionIter_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpNavTreeNodeCollectionIter_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpNavTreeNodeCollectionIter_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IZcPpNavTreeNodeCollectionIter_Start(This)	\
    ((This)->lpVtbl -> Start(This))

#define IZcPpNavTreeNodeCollectionIter_Next(This)	\
    ((This)->lpVtbl -> Next(This))

#define IZcPpNavTreeNodeCollectionIter_Current(This,pNode)	\
    ((This)->lpVtbl -> Current(This,pNode))

#define IZcPpNavTreeNodeCollectionIter_Done(This,pBool)	\
    ((This)->lpVtbl -> Done(This,pBool))

#endif


#endif 	




#endif 	


#ifndef __IZcPpNavTreeNodeCollection_INTERFACE_DEFINED__
#define __IZcPpNavTreeNodeCollection_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPpNavTreeNodeCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9A28A23F-9714-4C48-8BE9-CB8D591F1F3C")
    IZcPpNavTreeNodeCollection : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE AddNode(
             IZcPpNavTreeNode *pNode) = 0;

        virtual  HRESULT STDMETHODCALLTYPE DeleteNode(
             IZcPpNavTreeNode *pNode) = 0;

        virtual  HRESULT STDMETHODCALLTYPE DeleteAllNodes( void) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetNodeCollectionIter(
             IZcPpNavTreeNodeCollectionIter **PIter) = 0;

    };

#else

    typedef struct IZcPpNavTreeNodeCollectionVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpNavTreeNodeCollection * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpNavTreeNodeCollection * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpNavTreeNodeCollection * This);

         HRESULT ( STDMETHODCALLTYPE *AddNode )(
            IZcPpNavTreeNodeCollection * This,
             IZcPpNavTreeNode *pNode);

         HRESULT ( STDMETHODCALLTYPE *DeleteNode )(
            IZcPpNavTreeNodeCollection * This,
             IZcPpNavTreeNode *pNode);

         HRESULT ( STDMETHODCALLTYPE *DeleteAllNodes )(
            IZcPpNavTreeNodeCollection * This);

         HRESULT ( STDMETHODCALLTYPE *GetNodeCollectionIter )(
            IZcPpNavTreeNodeCollection * This,
             IZcPpNavTreeNodeCollectionIter **PIter);

        END_INTERFACE
    } IZcPpNavTreeNodeCollectionVtbl;

    interface IZcPpNavTreeNodeCollection
    {
        CONST_VTBL struct IZcPpNavTreeNodeCollectionVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpNavTreeNodeCollection_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpNavTreeNodeCollection_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpNavTreeNodeCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IZcPpNavTreeNodeCollection_AddNode(This,pNode)	\
    ((This)->lpVtbl -> AddNode(This,pNode))

#define IZcPpNavTreeNodeCollection_DeleteNode(This,pNode)	\
    ((This)->lpVtbl -> DeleteNode(This,pNode))

#define IZcPpNavTreeNodeCollection_DeleteAllNodes(This)	\
    ((This)->lpVtbl -> DeleteAllNodes(This))

#define IZcPpNavTreeNodeCollection_GetNodeCollectionIter(This,PIter)	\
    ((This)->lpVtbl -> GetNodeCollectionIter(This,PIter))

#endif


#endif 	




#endif 	


#ifndef __IZcPpNavTreeCmdBtn_INTERFACE_DEFINED__
#define __IZcPpNavTreeCmdBtn_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPpNavTreeCmdBtn;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("17F515C8-18E6-4731-A29A-12A5AB72F2A9")
    IZcPpNavTreeCmdBtn : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE get_Name(
             BSTR *pName) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetBtnImage(
             BSTR *pPath,
             ULONG *pImgType) = 0;

        virtual  HRESULT STDMETHODCALLTYPE Execute( void) = 0;

    };

#else

    typedef struct IZcPpNavTreeCmdBtnVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpNavTreeCmdBtn * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpNavTreeCmdBtn * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpNavTreeCmdBtn * This);

         HRESULT ( STDMETHODCALLTYPE *get_Name )(
            IZcPpNavTreeCmdBtn * This,
             BSTR *pName);

         HRESULT ( STDMETHODCALLTYPE *GetBtnImage )(
            IZcPpNavTreeCmdBtn * This,
             BSTR *pPath,
             ULONG *pImgType);

         HRESULT ( STDMETHODCALLTYPE *Execute )(
            IZcPpNavTreeCmdBtn * This);

        END_INTERFACE
    } IZcPpNavTreeCmdBtnVtbl;

    interface IZcPpNavTreeCmdBtn
    {
        CONST_VTBL struct IZcPpNavTreeCmdBtnVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpNavTreeCmdBtn_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpNavTreeCmdBtn_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpNavTreeCmdBtn_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IZcPpNavTreeCmdBtn_get_Name(This,pName)	\
    ((This)->lpVtbl -> get_Name(This,pName))

#define IZcPpNavTreeCmdBtn_GetBtnImage(This,pPath,pImgType)	\
    ((This)->lpVtbl -> GetBtnImage(This,pPath,pImgType))

#define IZcPpNavTreeCmdBtn_Execute(This)	\
    ((This)->lpVtbl -> Execute(This))

#endif


#endif 	




#endif 	


#ifndef __IZcPpNavTreeCmdBtnCollectionIter_INTERFACE_DEFINED__
#define __IZcPpNavTreeCmdBtnCollectionIter_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPpNavTreeCmdBtnCollectionIter;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1B14B5F9-D967-4C62-AE3B-FAD4CF051F63")
    IZcPpNavTreeCmdBtnCollectionIter : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE Start( void) = 0;

        virtual  HRESULT STDMETHODCALLTYPE Next( void) = 0;

        virtual  HRESULT STDMETHODCALLTYPE Current(
             IZcPpNavTreeCmdBtn **pNode) = 0;

        virtual  HRESULT STDMETHODCALLTYPE Done(
             VARIANT_BOOL *pBool) = 0;

    };

#else

    typedef struct IZcPpNavTreeCmdBtnCollectionIterVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpNavTreeCmdBtnCollectionIter * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpNavTreeCmdBtnCollectionIter * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpNavTreeCmdBtnCollectionIter * This);

         HRESULT ( STDMETHODCALLTYPE *Start )(
            IZcPpNavTreeCmdBtnCollectionIter * This);

         HRESULT ( STDMETHODCALLTYPE *Next )(
            IZcPpNavTreeCmdBtnCollectionIter * This);

         HRESULT ( STDMETHODCALLTYPE *Current )(
            IZcPpNavTreeCmdBtnCollectionIter * This,
             IZcPpNavTreeCmdBtn **pNode);

         HRESULT ( STDMETHODCALLTYPE *Done )(
            IZcPpNavTreeCmdBtnCollectionIter * This,
             VARIANT_BOOL *pBool);

        END_INTERFACE
    } IZcPpNavTreeCmdBtnCollectionIterVtbl;

    interface IZcPpNavTreeCmdBtnCollectionIter
    {
        CONST_VTBL struct IZcPpNavTreeCmdBtnCollectionIterVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpNavTreeCmdBtnCollectionIter_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpNavTreeCmdBtnCollectionIter_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpNavTreeCmdBtnCollectionIter_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IZcPpNavTreeCmdBtnCollectionIter_Start(This)	\
    ((This)->lpVtbl -> Start(This))

#define IZcPpNavTreeCmdBtnCollectionIter_Next(This)	\
    ((This)->lpVtbl -> Next(This))

#define IZcPpNavTreeCmdBtnCollectionIter_Current(This,pNode)	\
    ((This)->lpVtbl -> Current(This,pNode))

#define IZcPpNavTreeCmdBtnCollectionIter_Done(This,pBool)	\
    ((This)->lpVtbl -> Done(This,pBool))

#endif


#endif 	




#endif 	


#ifndef __IZcPpNavTreeCmdBtnCollection_INTERFACE_DEFINED__
#define __IZcPpNavTreeCmdBtnCollection_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPpNavTreeCmdBtnCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5AD8767E-93C1-4256-8031-29D726F4D8ED")
    IZcPpNavTreeCmdBtnCollection : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE AddButton(
             IZcPpNavTreeCmdBtn *pBtn) = 0;

        virtual  HRESULT STDMETHODCALLTYPE DeleteButton(
             IZcPpNavTreeCmdBtn *pBtn) = 0;

        virtual  HRESULT STDMETHODCALLTYPE DeleteAllButtons( void) = 0;

        virtual  HRESULT STDMETHODCALLTYPE GetCmdBtnCollectionIter(
             IZcPpNavTreeCmdBtnCollectionIter **pIter) = 0;

    };

#else

    typedef struct IZcPpNavTreeCmdBtnCollectionVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpNavTreeCmdBtnCollection * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpNavTreeCmdBtnCollection * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpNavTreeCmdBtnCollection * This);

         HRESULT ( STDMETHODCALLTYPE *AddButton )(
            IZcPpNavTreeCmdBtnCollection * This,
             IZcPpNavTreeCmdBtn *pBtn);

         HRESULT ( STDMETHODCALLTYPE *DeleteButton )(
            IZcPpNavTreeCmdBtnCollection * This,
             IZcPpNavTreeCmdBtn *pBtn);

         HRESULT ( STDMETHODCALLTYPE *DeleteAllButtons )(
            IZcPpNavTreeCmdBtnCollection * This);

         HRESULT ( STDMETHODCALLTYPE *GetCmdBtnCollectionIter )(
            IZcPpNavTreeCmdBtnCollection * This,
             IZcPpNavTreeCmdBtnCollectionIter **pIter);

        END_INTERFACE
    } IZcPpNavTreeCmdBtnCollectionVtbl;

    interface IZcPpNavTreeCmdBtnCollection
    {
        CONST_VTBL struct IZcPpNavTreeCmdBtnCollectionVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpNavTreeCmdBtnCollection_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpNavTreeCmdBtnCollection_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpNavTreeCmdBtnCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IZcPpNavTreeCmdBtnCollection_AddButton(This,pBtn)	\
    ((This)->lpVtbl -> AddButton(This,pBtn))

#define IZcPpNavTreeCmdBtnCollection_DeleteButton(This,pBtn)	\
    ((This)->lpVtbl -> DeleteButton(This,pBtn))

#define IZcPpNavTreeCmdBtnCollection_DeleteAllButtons(This)	\
    ((This)->lpVtbl -> DeleteAllButtons(This))

#define IZcPpNavTreeCmdBtnCollection_GetCmdBtnCollectionIter(This,pIter)	\
    ((This)->lpVtbl -> GetCmdBtnCollectionIter(This,pIter))

#endif


#endif 	




#endif 	


#ifndef __IZcPpNavTree_INTERFACE_DEFINED__
#define __IZcPpNavTree_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPpNavTree;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3412E0C1-20F7-43DD-B9ED-4299CCD4506C")
    IZcPpNavTree : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE Reset(
             IZcPpNavTreeNodeCollection *pNodeCollection,
             IZcPpNavTreeCmdBtnCollection *pCmdBtnCollection) = 0;

    };

#else

    typedef struct IZcPpNavTreeVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpNavTree * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpNavTree * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpNavTree * This);

         HRESULT ( STDMETHODCALLTYPE *Reset )(
            IZcPpNavTree * This,
             IZcPpNavTreeNodeCollection *pNodeCollection,
             IZcPpNavTreeCmdBtnCollection *pCmdBtnCollection);

        END_INTERFACE
    } IZcPpNavTreeVtbl;

    interface IZcPpNavTree
    {
        CONST_VTBL struct IZcPpNavTreeVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpNavTree_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpNavTree_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpNavTree_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IZcPpNavTree_Reset(This,pNodeCollection,pCmdBtnCollection)	\
    ((This)->lpVtbl -> Reset(This,pNodeCollection,pCmdBtnCollection))

#endif


#endif 	




#endif 	


#ifndef __IZcPpNavTreeEvents_INTERFACE_DEFINED__
#define __IZcPpNavTreeEvents_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPpNavTreeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E08AE839-864C-42A7-90D2-F700306C811C")
    IZcPpNavTreeEvents : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE OnSelectionChanged(
             VARIANT *pIntArray,
             VARIANT *pObjUnkArray,
             VARIANT_BOOL *bHandled) = 0;

        virtual  HRESULT STDMETHODCALLTYPE OnDblClickTreeItem(
             ULONG index,
             UINT nResourceId) = 0;

    };

#else

    typedef struct IZcPpNavTreeEventsVtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpNavTreeEvents * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpNavTreeEvents * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpNavTreeEvents * This);

         HRESULT ( STDMETHODCALLTYPE *OnSelectionChanged )(
            IZcPpNavTreeEvents * This,
             VARIANT *pIntArray,
             VARIANT *pObjUnkArray,
             VARIANT_BOOL *bHandled);

         HRESULT ( STDMETHODCALLTYPE *OnDblClickTreeItem )(
            IZcPpNavTreeEvents * This,
             ULONG index,
             UINT nResourceId);

        END_INTERFACE
    } IZcPpNavTreeEventsVtbl;

    interface IZcPpNavTreeEvents
    {
        CONST_VTBL struct IZcPpNavTreeEventsVtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpNavTreeEvents_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpNavTreeEvents_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpNavTreeEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IZcPpNavTreeEvents_OnSelectionChanged(This,pIntArray,pObjUnkArray,bHandled)	\
    ((This)->lpVtbl -> OnSelectionChanged(This,pIntArray,pObjUnkArray,bHandled))

#define IZcPpNavTreeEvents_OnDblClickTreeItem(This,index,nResourceId)	\
    ((This)->lpVtbl -> OnDblClickTreeItem(This,index,nResourceId))

#endif


#endif 	




#endif 	


#ifndef __IZcPpPalette2_INTERFACE_DEFINED__
#define __IZcPpPalette2_INTERFACE_DEFINED__
EXTERN_C const IID IID_IZcPpPalette2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("772460DD-82F1-4E99-B7BF-5AA4B31E3DB1")
    IZcPpPalette2 : public IUnknown
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE get_NavTree(
             IZcPpNavTree **pNavTree) = 0;

        virtual  HRESULT STDMETHODCALLTYPE put_NavTree(
             IZcPpNavTree *pNavTree) = 0;

    };

#else

    typedef struct IZcPpPalette2Vtbl
    {
        BEGIN_INTERFACE

        HRESULT ( STDMETHODCALLTYPE *QueryInterface )(
            IZcPpPalette2 * This,
             REFIID riid,
             void **ppvObject);

        ULONG ( STDMETHODCALLTYPE *AddRef )(
            IZcPpPalette2 * This);

        ULONG ( STDMETHODCALLTYPE *Release )(
            IZcPpPalette2 * This);

         HRESULT ( STDMETHODCALLTYPE *get_NavTree )(
            IZcPpPalette2 * This,
             IZcPpNavTree **pNavTree);

         HRESULT ( STDMETHODCALLTYPE *put_NavTree )(
            IZcPpPalette2 * This,
             IZcPpNavTree *pNavTree);

        END_INTERFACE
    } IZcPpPalette2Vtbl;

    interface IZcPpPalette2
    {
        CONST_VTBL struct IZcPpPalette2Vtbl *lpVtbl;
    };
#ifdef COBJMACROS
#define IZcPpPalette2_QueryInterface(This,riid,ppvObject)	\
    ((This)->lpVtbl -> QueryInterface(This,riid,ppvObject))

#define IZcPpPalette2_AddRef(This)	\
    ((This)->lpVtbl -> AddRef(This))

#define IZcPpPalette2_Release(This)	\
    (This)->lpVtbl -> Release(This)
#define IZcPpPalette2_get_NavTree(This,pNavTree)	\
    ((This)->lpVtbl -> get_NavTree(This,pNavTree))

#define IZcPpPalette2_put_NavTree(This,pNavTree)	\
    ((This)->lpVtbl -> put_NavTree(This,pNavTree))

#endif


#endif 	




#endif 	



#ifndef __ZcPpLib_LIBRARY_DEFINED__
#define __ZcPpLib_LIBRARY_DEFINED__
EXTERN_C const IID LIBID_ZcPpLib;

EXTERN_C const CLSID CLSID_ZcPpZcadInput;

#ifdef __cplusplus

class DECLSPEC_UUID("89E1C2E7-47F3-464D-8BDA-5E0E4E73DD3F")
ZcPpZcadInput;
#endif

EXTERN_C const CLSID CLSID_ZcPpPaletteSet;

#ifdef __cplusplus

class DECLSPEC_UUID("7B600A29-6FB8-4C83-A295-789182585BB9")
ZcPpPaletteSet;
#endif

EXTERN_C const CLSID CLSID_ZcPpPalette;

#ifdef __cplusplus

class DECLSPEC_UUID("5F2D7602-9376-49E1-A772-CD896E8B4E03")
ZcPpPalette;
#endif

EXTERN_C const CLSID CLSID_ZcPpPalette2;

#ifdef __cplusplus

class DECLSPEC_UUID("D43BEA50-AE29-4bd6-83B6-DE3ED23F517A")
ZcPpPalette2;
#endif

EXTERN_C const CLSID CLSID_ZcPpNavTree;

#ifdef __cplusplus

class DECLSPEC_UUID("F06460E2-3313-47B0-B464-DAC6B1F45A21")
ZcPpNavTree;
#endif

EXTERN_C const CLSID CLSID_ZcPpNavTreeNode;

#ifdef __cplusplus

class DECLSPEC_UUID("927E6A91-B46D-4149-B0F9-EC25712FF1E0")
ZcPpNavTreeNode;
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


