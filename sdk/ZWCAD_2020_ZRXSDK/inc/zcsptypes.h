
#pragma warning( disable: 4049 )


#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif


#ifndef __csptypes_h__
#define __csptypes_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif


#ifndef __Csp_FWD_DEFINED__
#define __Csp_FWD_DEFINED__

#ifdef __cplusplus
typedef class Csp Csp;
#else
typedef struct Csp Csp;
#endif

#endif


#ifndef __CspErrorLookup_FWD_DEFINED__
#define __CspErrorLookup_FWD_DEFINED__

#ifdef __cplusplus
typedef class CspErrorLookup CspErrorLookup;
#else
typedef struct CspErrorLookup CspErrorLookup;
#endif

#endif


#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * );


#ifndef __CSPLib_LIBRARY_DEFINED__
#define __CSPLib_LIBRARY_DEFINED__


typedef   DECLSPEC_UUID("DCB5B0C0-B806-11d1-A8A8-00805F02B922")
enum tagStatement
    {	kAsiTYPE_UNDEFINED	= 0,
	kAsiALLOC_CURSOR	= kAsiTYPE_UNDEFINED + 1,
	kAsiALLOC_STATEMENT	= kAsiALLOC_CURSOR + 1,
	kAsiALTER_DOMAIN	= kAsiALLOC_STATEMENT + 1,
	kAsiALTER_TABLE	= kAsiALTER_DOMAIN + 1,
	kAsiCREATE_ASSERTION	= kAsiALTER_TABLE + 1,
	kAsiCREATE_CATALOG	= kAsiCREATE_ASSERTION + 1,
	kAsiCREATE_CHARACTER_SET	= kAsiCREATE_CATALOG + 1,
	kAsiCREATE_COLLATION	= kAsiCREATE_CHARACTER_SET + 1,
	kAsiCREATE_DOMAIN	= kAsiCREATE_COLLATION + 1,
	kAsiCLOSE_CURSOR	= kAsiCREATE_DOMAIN + 1,
	kAsiCOMMIT	= kAsiCLOSE_CURSOR + 1,
	kAsiCONNECT	= kAsiCOMMIT + 1,
	kAsiCREATE_SCHEMA	= kAsiCONNECT + 1,
	kAsiCREATE_TABLE	= kAsiCREATE_SCHEMA + 1,
	kAsiCREATE_VIEW	= kAsiCREATE_TABLE + 1,
	kAsiCREATE_INDEX	= kAsiCREATE_VIEW + 1,
	kAsiCREATE_TRANSLATION	= kAsiCREATE_INDEX + 1,
	kAsiCURSOR	= kAsiCREATE_TRANSLATION + 1,
	kAsiDELETE_CURSOR	= kAsiCURSOR + 1,
	kAsiDELETE_WHERE	= kAsiDELETE_CURSOR + 1,
	kAsiDEALLOCATE_STATEMENT	= kAsiDELETE_WHERE + 1,
	kAsiDISCONNECT	= kAsiDEALLOCATE_STATEMENT + 1,
	kAsiDROP_ASSERTION	= kAsiDISCONNECT + 1,
	kAsiDROP_CATALOG	= kAsiDROP_ASSERTION + 1,
	kAsiDROP_CHARACTER_SET	= kAsiDROP_CATALOG + 1,
	kAsiDROP_COLLATION	= kAsiDROP_CHARACTER_SET + 1,
	kAsiDROP_DOMAIN	= kAsiDROP_COLLATION + 1,
	kAsiDROP_SCHEMA	= kAsiDROP_DOMAIN + 1,
	kAsiDROP_TABLE	= kAsiDROP_SCHEMA + 1,
	kAsiDROP_TRANSLATION	= kAsiDROP_TABLE + 1,
	kAsiDROP_VIEW	= kAsiDROP_TRANSLATION + 1,
	kAsiDROP_INDEX	= kAsiDROP_VIEW + 1,
	kAsiEXECUTE_IMMEDIATE	= kAsiDROP_INDEX + 1,
	kAsiEXECUTE	= kAsiEXECUTE_IMMEDIATE + 1,
	kAsiFETCH	= kAsiEXECUTE + 1,
	kAsiGRANT	= kAsiFETCH + 1,
	kAsiINSERT	= kAsiGRANT + 1,
	kAsiOPEN	= kAsiINSERT + 1,
	kAsiPREPARE	= kAsiOPEN + 1,
	kAsiREVOKE	= kAsiPREPARE + 1,
	kAsiROLLBACK	= kAsiREVOKE + 1,
	kAsiSELECT	= kAsiROLLBACK + 1,
	kAsiSET_CATALOG	= kAsiSELECT + 1,
	kAsiSET_SCHEMA	= kAsiSET_CATALOG + 1,
	kAsiSET_TIME_ZONE	= kAsiSET_SCHEMA + 1,
	kAsiSET_NAMES	= kAsiSET_TIME_ZONE + 1,
	kAsiSET_TRANSACTION	= kAsiSET_NAMES + 1,
	kAsiSET_CONSTRAINT	= kAsiSET_TRANSACTION + 1,
	kAsiSET_AUTHORIZATION	= kAsiSET_CONSTRAINT + 1,
	kAsiUPDATE_CURSOR	= kAsiSET_AUTHORIZATION + 1,
	kAsiUPDATE_WHERE	= kAsiUPDATE_CURSOR + 1
    } 	EAsiStatement;


EXTERN_C const IID LIBID_CSPLib;

EXTERN_C const CLSID CLSID_Csp;

#ifdef __cplusplus

class DECLSPEC_UUID("49E0BE0A-39E0-4932-B7BE-F249D56ACD31")
Csp;
#endif

EXTERN_C const CLSID CLSID_CspErrorLookup;

#ifdef __cplusplus

class DECLSPEC_UUID("2A9A858F-79E8-4be6-B205-E7D41B137114")
CspErrorLookup;
#endif
#endif



#ifdef __cplusplus
}
#endif

#endif



