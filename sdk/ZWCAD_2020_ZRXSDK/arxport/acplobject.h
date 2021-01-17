
#ifndef __ACPLOBJECT_H__
#define __ACPLOBJECT_H__

#include "rxobject.h"
#include "AcHeapOpers.h"

#include "../inc/zAcPlObject.h"

#ifndef ACPL_DECLARE_MEMBERS
#define ACPL_DECLARE_MEMBERS		ZCPL_DECLARE_MEMBERS
#endif //#ifndef ACPL_DECLARE_MEMBERS

#ifndef ACPL_DEFINE_MEMBERS
#define ACPL_DEFINE_MEMBERS		ZCPL_DEFINE_MEMBERS
#endif //#ifndef ACPL_DEFINE_MEMBERS

#ifndef ACPL_PORT
#define ACPL_PORT		ZCPL_PORT
#endif //#ifndef ACPL_PORT

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef ACRX_NO_CONS_DEFINE_MEMBERS
#define ACRX_NO_CONS_DEFINE_MEMBERS		ZCRX_NO_CONS_DEFINE_MEMBERS
#endif //#ifndef ACRX_NO_CONS_DEFINE_MEMBERS

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcHeapOperators
#define AcHeapOperators		ZcHeapOperators
#endif //#ifndef AcHeapOperators

#ifndef AcHeapOpers
#define AcHeapOpers		ZcHeapOpers
#endif //#ifndef AcHeapOpers

#ifndef AcPlObject
#define AcPlObject		ZcPlObject
#endif //#ifndef AcPlObject

#ifndef AcPlObjectImp
#define AcPlObjectImp		ZcPlObjectImp
#endif //#ifndef AcPlObjectImp

#ifndef AcPlSystemInternals
#define AcPlSystemInternals		ZcPlSystemInternals
#endif //#ifndef AcPlSystemInternals

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#endif //#ifndef __ACPLOBJECT_H__
