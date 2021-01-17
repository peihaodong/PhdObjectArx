
#pragma once

#ifdef _UNICODE
#define _RXST(a) _ZCRX_T(a)
#else
#define _RXST(a) ZCRX_T(a)
#endif
struct _DBX_REGISTER_OBJECT_ENTRY {
    ZcRxClass* (*desc) () ;
    void (*rxInit) () ;
    bool bRegistered ;
} ;

#pragma section("DBXCUSTOBJ$__a", read, shared)
#pragma section("DBXCUSTOBJ$__z", read, shared)
#pragma section("DBXCUSTOBJ$__m", read, shared)

extern "C" {
    __declspec(selectany) __declspec(allocate("DBXCUSTOBJ$__a")) _DBX_REGISTER_OBJECT_ENTRY* __pDbxCustObjMapEntryFirst =NULL ;
    __declspec(selectany) __declspec(allocate("DBXCUSTOBJ$__z")) _DBX_REGISTER_OBJECT_ENTRY* __pDbxCustObjMapEntryLast =NULL ;
}

#if defined(_WIN64) || defined(_ZC64)
#define ZCDB_REGISTER_OBJECT_ENTRY_PRAGMA(classname) __pragma(comment(linker, "/include:__pDbxCustObjMap_" #classname)) ;
#else
#define ZCDB_REGISTER_OBJECT_ENTRY_PRAGMA(classname) __pragma(comment(linker, "/include:___pDbxCustObjMap_" #classname)) ;
#endif

#define ZCDB_REGISTER_OBJECT_ENTRY_AUTO(classname) \
    __declspec(selectany) _DBX_REGISTER_OBJECT_ENTRY __DbxCustObjMap_##classname = { classname::desc, classname::rxInit } ; \
    extern "C" __declspec(allocate("DBXCUSTOBJ$__m")) __declspec(selectany) _DBX_REGISTER_OBJECT_ENTRY* const __pDbxCustObjMap_##classname = &__DbxCustObjMap_##classname ; \
    ZCDB_REGISTER_OBJECT_ENTRY_PRAGMA(classname)

#define DISPATCH_PKTMSG(pktmsg) case ZcRx::pktmsg: return (On_ ##pktmsg (pkt))

extern HINSTANCE _hdllInstance ;

class ZcRxDbxApp {

protected:
    HINSTANCE m_hdllInstance ;
    bool m_bUnlocked ;
    bool m_bMDIAware ;

public:
    ZcRxDbxApp () : m_hdllInstance(NULL), m_bUnlocked(true), m_bMDIAware(true) {}

    virtual ZcRx::AppRetCode On_kInitAppMsg (void *pkt) {

		m_hdllInstance =_hdllInstance ;

        if ( m_bUnlocked == true )
            zcrxDynamicLinker->unlockApplication (pkt) ;

        if ( m_bMDIAware == true )
            zcrxDynamicLinker->registerAppMDIAware (pkt) ;
        RegisterServerComponents () ;

        int nDbxCustObjCount =0 ;
        _DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryFirst =&__pDbxCustObjMapEntryFirst + 1 ;
        _DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryLast =&__pDbxCustObjMapEntryLast ;
        for ( _DBX_REGISTER_OBJECT_ENTRY **ppEntry =ppDbxCustObjMapEntryFirst ; ppEntry < ppDbxCustObjMapEntryLast ; ppEntry++ ) {
            if ( *ppEntry != NULL ) {
                nDbxCustObjCount++ ;
                (*ppEntry)->rxInit () ;
                (*ppEntry)->bRegistered =true ;
            }
        }
        if ( nDbxCustObjCount > 0 )
            zcrxBuildClassHierarchy () ;
        return (ZcRx::kRetOK) ;
    }
    virtual ZcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
        _DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryFirst =&__pDbxCustObjMapEntryFirst + 1 ;
        _DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryLast =&__pDbxCustObjMapEntryLast ;
        for ( _DBX_REGISTER_OBJECT_ENTRY **ppEntry =ppDbxCustObjMapEntryFirst ; ppEntry < ppDbxCustObjMapEntryLast ; ppEntry++ ) {
            if ( *ppEntry != NULL && (*ppEntry)->bRegistered == true )
                DeleteClassAndDescendant (ppEntry) ;
        }
        return (ZcRx::kRetOK) ;
    }
    virtual ZcRx::AppRetCode On_kLoadDwgMsg (void *pkt) { return (ZcRx::kRetOK) ; }
    virtual ZcRx::AppRetCode On_kUnloadDwgMsg (void *pkt) { return (ZcRx::kRetOK) ; }
    virtual ZcRx::AppRetCode On_kInvkSubrMsg (void *pkt) { return (ZcRx::kRetOK) ; }
    virtual ZcRx::AppRetCode On_kCfgMsg (void *pkt) { return (ZcRx::kRetOK) ; }
    virtual ZcRx::AppRetCode On_kEndMsg (void *pkt) { return (ZcRx::kRetOK) ; }
    virtual ZcRx::AppRetCode On_kQuitMsg (void *pkt) { return (ZcRx::kRetOK) ; }
    virtual ZcRx::AppRetCode On_kSaveMsg (void *pkt) { return (ZcRx::kRetOK) ; }
    virtual ZcRx::AppRetCode On_kDependencyMsg (void *pkt) { return (ZcRx::kRetOK) ; }
    virtual ZcRx::AppRetCode On_kNoDependencyMsg (void *pkt) { return (ZcRx::kRetOK) ; }
    virtual ZcRx::AppRetCode On_kOleUnloadAppMsg (void *pkt) { return (ZcRx::kRetOK) ; }
    virtual ZcRx::AppRetCode On_kPreQuitMsg (void *pkt) { return (ZcRx::kRetOK) ; }
    virtual ZcRx::AppRetCode On_kInitDialogMsg (void *pkt) { return (ZcRx::kRetOK) ; }
    virtual ZcRx::AppRetCode On_kEndDialogMsg (void *pkt) { return (ZcRx::kRetOK) ; }
    virtual ZcRx::AppRetCode On_kNullMsg (void *pkt) { return (ZcRx::kRetOK) ; }

    ZcRx::AppRetCode zcrxEntryPoint (ZcRx::AppMsgCode msg, void *pkt) {
        switch ( msg ) {
            DISPATCH_PKTMSG (kInitAppMsg) ;
            DISPATCH_PKTMSG (kUnloadAppMsg) ;
            DISPATCH_PKTMSG (kLoadDwgMsg) ;
            DISPATCH_PKTMSG (kUnloadDwgMsg) ;
            DISPATCH_PKTMSG (kInvkSubrMsg) ;
            DISPATCH_PKTMSG (kCfgMsg) ;
            DISPATCH_PKTMSG (kEndMsg) ;
            DISPATCH_PKTMSG (kQuitMsg) ;
            DISPATCH_PKTMSG (kSaveMsg) ;
            DISPATCH_PKTMSG (kDependencyMsg) ;
            DISPATCH_PKTMSG (kNoDependencyMsg) ;
            DISPATCH_PKTMSG (kOleUnloadAppMsg) ;
            DISPATCH_PKTMSG (kPreQuitMsg) ;
            DISPATCH_PKTMSG (kInitDialogMsg) ;
            DISPATCH_PKTMSG (kEndDialogMsg) ;
            DISPATCH_PKTMSG (kNullMsg) ;
        }
        return (ZcRx::kRetOK) ;
    }

    virtual void RegisterServerComponents () = 0 ;
    HINSTANCE &GetModuleInstance () { return (m_hdllInstance) ; }

private:
    void DeleteClassAndDescendant (_DBX_REGISTER_OBJECT_ENTRY **ppEntry) {
        _DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryFirst =&__pDbxCustObjMapEntryFirst + 1 ;
        _DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryLast =&__pDbxCustObjMapEntryLast ;
        for ( _DBX_REGISTER_OBJECT_ENTRY **ppEntry2 =ppDbxCustObjMapEntryFirst ; ppEntry2 < ppDbxCustObjMapEntryLast ; ppEntry2++ ) {
            if ( *ppEntry2 != NULL && *ppEntry2 != *ppEntry && (*ppEntry2)->bRegistered == true ) {
                if ( (*ppEntry2)->desc ()->myParent () == (*ppEntry)->desc () )
                    DeleteClassAndDescendant (ppEntry2) ;
            }
        }
        deleteZcRxClass ((*ppEntry)->desc ()) ;
        (*ppEntry)->bRegistered =false ;
    }
} ;

ZcRxDbxApp *zcrxGetApp () ;

#define IMPLEMENT_ZRX_ENTRYPOINT_STD(classname) \
	HINSTANCE _hdllInstance =NULL ; \
    class classname entryPointObject ; \
    ZcRxDbxApp *zcrxGetApp () { return (&entryPointObject) ; } \
    extern "C" ZcRx::AppRetCode __declspec(dllexport) zcrxEntryPoint (ZcRx::AppMsgCode msg, void *pkt) { \
        return (entryPointObject.zcrxEntryPoint (msg, pkt)) ; \
    }
#define IMPLEMENT_ZRX_ENTRYPOINT_CLR(classname) IMPLEMENT_ZRX_ENTRYPOINT_STD(classname)
#define IMPLEMENT_ZRX_ENTRYPOINT(classname) IMPLEMENT_ZRX_ENTRYPOINT_STD(classname)

#if !defined(_WIN64) && !defined (_ZC64)
#pragma comment(linker, "/export:_zcrxGetApiVersion,PRIVATE")
#else
#pragma comment(linker, "/export:zcrxGetApiVersion,PRIVATE")
#endif
