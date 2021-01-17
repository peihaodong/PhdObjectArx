
#ifndef __ADESK_H__
#define __ADESK_H__

#include "AdAChar.h"            // ACHAR typedef

#include "../inc/zadesk.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AC_BYTE
#define AC_BYTE		ZC_BYTE
#endif //#ifndef AC_BYTE

#ifndef ADESK_DEPRECATED
#define ADESK_DEPRECATED		ZSOFT_DEPRECATED
#endif //#ifndef ADESK_DEPRECATED

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef ADESK_STDCALL
#define ADESK_STDCALL		ZSOFT_STDCALL
#endif //#ifndef ADESK_STDCALL

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef ADESK_OVERRIDE
#define ADESK_OVERRIDE	ZSOFT_OVERRIDE
#endif 

#ifndef ADESK_SEALED
#define ADESK_SEALED	ZSOFT_SEALED
#endif 

#ifndef ADESK_SEALED_VIRTUAL
#define ADESK_SEALED_VIRTUAL	ZSOFT_SEALED_VIRTUAL
#endif 


#endif //#ifndef __ADESK_H__