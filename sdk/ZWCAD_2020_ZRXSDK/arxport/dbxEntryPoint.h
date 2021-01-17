
#ifndef __DBXENTRYPOINT_H__
#define __DBXENTRYPOINT_H__

#include "../inc/zdbxEntryPoint.h"

#ifndef ACDB_REGISTER_OBJECT_ENTRY_AUTO
#define ACDB_REGISTER_OBJECT_ENTRY_AUTO		ZCDB_REGISTER_OBJECT_ENTRY_AUTO
#endif //#ifndef ACDB_REGISTER_OBJECT_ENTRY_AUTO

#ifndef ACDB_REGISTER_OBJECT_ENTRY_PRAGMA
#define ACDB_REGISTER_OBJECT_ENTRY_PRAGMA		ZCDB_REGISTER_OBJECT_ENTRY_PRAGMA
#endif //#ifndef ACDB_REGISTER_OBJECT_ENTRY_PRAGMA

#ifndef AcRx
#define AcRx		ZcRx
#endif //#ifndef AcRx

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef AcRxDbxApp
#define AcRxDbxApp		ZcRxDbxApp
#endif //#ifndef AcRxDbxApp

#ifndef _ACRX_T
#define _ACRX_T		_ZCRX_T
#endif //#ifndef _ACRX_T

#ifndef _acrxGetApiVersion
#define _acrxGetApiVersion		_zcrxGetApiVersion
#endif //#ifndef _acrxGetApiVersion

#ifndef acrxBuildClassHierarchy
#define acrxBuildClassHierarchy		zcrxBuildClassHierarchy
#endif //#ifndef acrxBuildClassHierarchy

#ifndef acrxDynamicLinker
#define acrxDynamicLinker		zcrxDynamicLinker
#endif //#ifndef acrxDynamicLinker

#ifndef acrxEntryPoint
#define acrxEntryPoint		zcrxEntryPoint
#endif //#ifndef acrxEntryPoint

#ifndef acrxGetApiVersion
#define acrxGetApiVersion		zcrxGetApiVersion
#endif //#ifndef acrxGetApiVersion

#ifndef acrxGetApp
#define acrxGetApp		zcrxGetApp
#endif //#ifndef acrxGetApp

#ifndef deleteAcRxClass
#define deleteAcRxClass		deleteZcRxClass
#endif //#ifndef deleteAcRxClass

#ifndef IMPLEMENT_ARX_ENTRYPOINT_STD
#define IMPLEMENT_ARX_ENTRYPOINT_STD 		IMPLEMENT_ZRX_ENTRYPOINT_STD
#endif //#ifndef IMPLEMENT_ARX_ENTRYPOINT_STD

#ifndef IMPLEMENT_ARX_ENTRYPOINT_CLR
#define IMPLEMENT_ARX_ENTRYPOINT_CLR            IMPLEMENT_ZRX_ENTRYPOINT_CLR
#endif //#ifndef IMPLEMENT_ARX_ENTRYPOINT_CLR

#ifndef IMPLEMENT_ARX_ENTRYPOINT
#define IMPLEMENT_ARX_ENTRYPOINT		IMPLEMENT_ZRX_ENTRYPOINT
#endif //#ifndef IMPLEMENT_ARX_ENTRYPOINT




#endif //#ifndef __DBXENTRYPOINT_H__
