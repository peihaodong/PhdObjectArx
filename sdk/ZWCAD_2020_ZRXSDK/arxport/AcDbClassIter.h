
#ifndef __ACDBCLASSITER_H__
#define __ACDBCLASSITER_H__

#include "dbmain.h"
#include "../inc/zAcDbClassIter.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef ADESK_STDCALL
#define ADESK_STDCALL		ZSOFT_STDCALL
#endif //#ifndef ADESK_STDCALL

#ifndef AcDbClassIterator
#define AcDbClassIterator		ZcDbClassIterator
#endif //#ifndef AcDbClassIterator

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __ACDBCLASSITER_H__
