
#pragma once

#include "zdbxEntryPoint.h"
#ifdef __ATLCOM_H__
#include "zdynpropmgr.h"
#endif

struct _ZRXCOMMAND_ENTRY {
    const ZTCHAR *pszCmdGroupName ;
    const ZTCHAR *pszCmdGlobalName ;
    const ZTCHAR *pszCmdLocalName ;
    ZSoft::Int32 commandFlags ;
    ZcRxFunctionPtr pCmdFct ;
    ZcEdUIContext *pUIContext ;
    UINT localNameID ;
} ;

#pragma section("ZRXCOMMAND$__a", read, shared)
#pragma section("ZRXCOMMAND$__z", read, shared)
#pragma section("ZRXCOMMAND$__m", read, shared)

extern "C" {
	__declspec(selectany) __declspec(allocate("ZRXCOMMAND$__a")) _ZRXCOMMAND_ENTRY* __pZrxCmdMapEntryFirst =NULL ;
	__declspec(selectany) __declspec(allocate("ZRXCOMMAND$__z")) _ZRXCOMMAND_ENTRY* __pZrxCmdMapEntryLast =NULL ;
}

#if defined(_WIN64) || defined(_ZC64)
#define ZCED_ZRXCOMMAND_ENTRY_PRAGMA(group,globCmd) __pragma(comment(linker, "/include:__pZrxCmdMap_" #group #globCmd)) ;
#else
#define ZCED_ZRXCOMMAND_ENTRY_PRAGMA(group,globCmd) __pragma(comment(linker, "/include:___pZrxCmdMap_" #group #globCmd)) ;
#endif


#define ZCED_ZRXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext) \
    __declspec(selectany) _ZRXCOMMAND_ENTRY __ZrxCmdMap_##group##globCmd = { _RXST(#group), _RXST(#globCmd), _RXST(#locCmd), cmdFlags, classname::##group ##globCmd, UIContext, -1 } ; \
    extern "C" __declspec(allocate("ZRXCOMMAND$__m")) __declspec(selectany) _ZRXCOMMAND_ENTRY* const __pZrxCmdMap_##group##globCmd = &__ZrxCmdMap_##group##globCmd ; \
    ZCED_ZRXCOMMAND_ENTRY_PRAGMA(group, globCmd)

#define ZCED_ZRXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext) \
    __declspec(selectany) _ZRXCOMMAND_ENTRY __ZrxCmdMap_##group##globCmd = { _RXST(#group), _RXST(#globCmd), NULL, cmdFlags, classname::##group ##globCmd, UIContext, locCmdId } ; \
    extern "C" __declspec(allocate("ZRXCOMMAND$__m")) __declspec(selectany) _ZRXCOMMAND_ENTRY* const __pZrxCmdMap_##group##globCmd = &__ZrxCmdMap_##group##globCmd ; \
    ZCED_ZRXCOMMAND_ENTRY_PRAGMA(group, globCmd)

struct _ZDSSYMBOL_ENTRY {
    const ZTCHAR *pszName ;
    int (*fptr) () ;
    bool bRegFunc ;
    UINT nameID ;
} ;

#pragma section("ZDSSYMBOL$__a", read, shared)
#pragma section("ZDSSYMBOL$__z", read, shared)
#pragma section("ZDSSYMBOL$__m", read, shared)

extern "C" {
    __declspec(selectany) __declspec(allocate("ZDSSYMBOL$__a")) _ZDSSYMBOL_ENTRY* __pZdsSymbolMapEntryFirst =NULL ;
    __declspec(selectany) __declspec(allocate("ZDSSYMBOL$__z")) _ZDSSYMBOL_ENTRY* __pZdsSymbolMapEntryLast =NULL ;
}

#if defined(_WIN64) || defined(_ZC64)
#define ZCED_ZDSSYMBOL_ENTRY_PRAGMA(name) __pragma(comment(linker, "/include:__pZdsSymbolMap_" #name)) ;
#else
#define ZCED_ZDSSYMBOL_ENTRY_PRAGMA(name) __pragma(comment(linker, "/include:___pZdsSymbolMap_" #name)) ;
#endif


#define ZCED_ZDSSYMBOL_ENTRY_AUTO(classname, name, regFunc) \
    __declspec(selectany) _ZDSSYMBOL_ENTRY __ZdsSymbolMap_##name = { _RXST(#name), classname::zds_ ##name, regFunc, -1 } ; \
    extern "C" __declspec(allocate("ZDSSYMBOL$__m")) __declspec(selectany) _ZDSSYMBOL_ENTRY* const __pZdsSymbolMap_##name = &__ZdsSymbolMap_##name ; \
    ZCED_ZDSSYMBOL_ENTRY_PRAGMA(name)
#define ZCED_ZDSCOMMAND_ENTRY_AUTO(classname, name, regFunc) \
    __declspec(selectany) _ZDSSYMBOL_ENTRY __ZdsSymbolMap_##name = { _RXST("c:") _RXST(#name), classname::zds_ ##name, regFunc, -1 } ; \
    extern "C" __declspec(allocate("ZDSSYMBOL$__m")) __declspec(selectany) _ZDSSYMBOL_ENTRY* const __pZdsSymbolMap_##name = &__ZdsSymbolMap_##name ; \
    ZCED_ZDSSYMBOL_ENTRY_PRAGMA(name)

#define ZCED_ZDSSYMBOL_ENTRYBYID_AUTO(classname, name, nameId, regFunc) \
    __declspec(selectany) _ZDSSYMBOL_ENTRY __ZdsSymbolMap_##name = { NULL, classname::zds_ ##name, regFunc, nameId } ; \
    extern "C" __declspec(allocate("ADSSYMBOL$__m")) __declspec(selectany) _ZDSSYMBOL_ENTRY* const __pZdsSymbolMap_##name = &__ZdsSymbolMap_##name ; \
    ZCED_ZDSSYMBOL_ENTRY_PRAGMA(name)
#define ZCED_ZDSCOMMAND_ENTRYBYID_AUTO(classname, name, nameId, regFunc) \
    ZCED_ZDSSYMBOL_ENTRYBYID_AUTO(classname, name, nameId, regFunc)

class ZcRxZrxApp : public ZcRxDbxApp {

#ifdef __ATLCOM_H__
protected:
    ZcRxDynPropManager *m_pDynPropManager ;
#endif

public:
#ifdef __ATLCOM_H__
    ZcRxZrxApp () : ZcRxDbxApp (), m_pDynPropManager(NULL) {}
#else
    ZcRxZrxApp () : ZcRxDbxApp () {}
#endif

    virtual ZcRx::AppRetCode On_kInitAppMsg (void *pkt) {
        ZcRx::AppRetCode retCode =ZcRxDbxApp::On_kInitAppMsg (pkt) ;
#ifdef __ATLCOM_H__

        m_pDynPropManager =new ZcRxDynPropManager ;
#endif

        _ZRXCOMMAND_ENTRY **ppZrxCmdMapEntryFirst =&__pZrxCmdMapEntryFirst + 1 ;
        _ZRXCOMMAND_ENTRY **ppZrxCmdMapEntryLast =&__pZrxCmdMapEntryLast ;
        ZTCHAR buffer [133] ;
        for ( _ZRXCOMMAND_ENTRY **ppEntry =ppZrxCmdMapEntryFirst ; ppEntry < ppZrxCmdMapEntryLast ; ppEntry++ ) {
            if ( *ppEntry != NULL ) {
                if ( (*ppEntry)->pszCmdLocalName == NULL )
                    ::LoadString (m_hdllInstance, (*ppEntry)->localNameID, buffer, 132) ;
                zcedRegCmds->addCommand (
                    (*ppEntry)->pszCmdGroupName,
                    (*ppEntry)->pszCmdGlobalName,
                    (*ppEntry)->pszCmdLocalName == NULL ? buffer : (*ppEntry)->pszCmdLocalName,
                    (*ppEntry)->commandFlags,
                    (*ppEntry)->pCmdFct,
                    (*ppEntry)->pUIContext,
                    -1,
                    ((*ppEntry)->commandFlags & ZCRX_CMD_SESSION) ? NULL : m_hdllInstance,
                    NULL
                ) ;
            }
        }
        return (retCode) ;
    }

    virtual ZcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
        ZcRx::AppRetCode retCode =ZcRxDbxApp::On_kUnloadAppMsg (pkt) ;
#ifdef __ATLCOM_H__

        if ( m_pDynPropManager != NULL ) {
            delete m_pDynPropManager ;
            m_pDynPropManager =NULL ;
        }
#endif
        _ZRXCOMMAND_ENTRY **ppZrxCmdMapEntryFirst =&__pZrxCmdMapEntryFirst + 1 ;
        _ZRXCOMMAND_ENTRY **ppZrxCmdMapEntryLast =&__pZrxCmdMapEntryLast ;
        for ( _ZRXCOMMAND_ENTRY **ppEntry =ppZrxCmdMapEntryFirst ; ppEntry < ppZrxCmdMapEntryLast ; ppEntry++ ) {
            if ( *ppEntry != NULL ) {
                zcedRegCmds->removeCmd (
                    (*ppEntry)->pszCmdGroupName,
                    (*ppEntry)->pszCmdGlobalName
                ) ;
            }
        }
        return (retCode) ;
    }

    virtual ZcRx::AppRetCode On_kLoadDwgMsg (void *pkt) {
        ZcRx::AppRetCode retCode =ZcRxDbxApp::On_kLoadDwgMsg (pkt) ;

        _ZDSSYMBOL_ENTRY **ppZdsSymbolMapEntryFirst =&__pZdsSymbolMapEntryFirst + 1 ;
        _ZDSSYMBOL_ENTRY **ppZdsSymbolMapEntryLast =&__pZdsSymbolMapEntryLast ;
        ZTCHAR buffer [133] ;
        int param =0 ;
        for ( _ZDSSYMBOL_ENTRY **ppEntry =ppZdsSymbolMapEntryFirst ; ppEntry < ppZdsSymbolMapEntryLast ; ppEntry++ ) {
            if ( *ppEntry != NULL ) {
                if ( (*ppEntry)->pszName == NULL )
                    ::LoadString (m_hdllInstance, (*ppEntry)->nameID, buffer, 132) ;
                zcedDefun (
                    (*ppEntry)->pszName == NULL ? buffer : (*ppEntry)->pszName,
                    param
                ) ;
                if ( (*ppEntry)->bRegFunc == true )
                    zcedRegFunc ((*ppEntry)->fptr, param) ;
                param++ ;
            }
        }
        return (retCode) ;
    }

    virtual ZcRx::AppRetCode On_kUnloadDwgMsg (void *pkt) {
        ZcRx::AppRetCode retCode =ZcRxDbxApp::On_kUnloadDwgMsg (pkt) ;

        _ZDSSYMBOL_ENTRY **ppZdsSymbolMapEntryFirst =&__pZdsSymbolMapEntryFirst + 1 ;
        _ZDSSYMBOL_ENTRY **ppZdsSymbolMapEntryLast =&__pZdsSymbolMapEntryLast ;
        ZTCHAR buffer [133] ;
        int param =0 ;
        for ( _ZDSSYMBOL_ENTRY **ppEntry =ppZdsSymbolMapEntryFirst ; ppEntry < ppZdsSymbolMapEntryLast ; ppEntry++ ) {
            if ( *ppEntry != NULL ) {
                if ( (*ppEntry)->pszName == NULL )
                    ::LoadString (m_hdllInstance, (*ppEntry)->nameID, buffer, 132) ;
                zcedUndef (
                       (*ppEntry)->pszName == NULL ? buffer : (*ppEntry)->pszName,
                    param++
                ) ;
            }
        }
        return (retCode) ;
    }

    virtual ZcRx::AppRetCode On_kInvkSubrMsg (void *pkt) {
        ZcRx::AppRetCode retCode =ZcRxDbxApp::On_kInvkSubrMsg (pkt) ;

        int param =zcedGetFunCode () ;
        _ZDSSYMBOL_ENTRY **ppZdsSymbolMapEntryFirst =&__pZdsSymbolMapEntryFirst + 1 ;
        _ZDSSYMBOL_ENTRY **ppZdsSymbolMapEntryLast =&__pZdsSymbolMapEntryLast ;
        int paramIter =0 ;
        for ( _ZDSSYMBOL_ENTRY **ppEntry =ppZdsSymbolMapEntryFirst ; ppEntry < ppZdsSymbolMapEntryLast ; ppEntry++ ) {
            if ( *ppEntry != NULL ) {
                if ( paramIter++ == param ) {
                    (*((*ppEntry)->fptr)) () ;
                    break ;
                }
            }
        }
        return (retCode) ;
    }
} ;

