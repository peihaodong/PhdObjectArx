
#ifndef __MGDHOST_H__
#define __MGDHOST_H__

#include "AdAChar.h"

#include "../inc/zmgdhost.h"

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ADESK_STDCALL
#define ADESK_STDCALL		ZSOFT_STDCALL
#endif //#ifndef ADESK_STDCALL

#ifndef AcDbManagedHost
#define AcDbManagedHost		ZcDbManagedHost
#endif //#ifndef AcDbManagedHost

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef acdbGetManagedHost
#define acdbGetManagedHost		zcdbGetManagedHost
#endif //#ifndef acdbGetManagedHost

#ifndef acdbInitializeManagedLayer
#define acdbInitializeManagedLayer		zcdbInitializeManagedLayer
#endif //#ifndef acdbInitializeManagedLayer

#ifndef acdbSetManagedHost
#define acdbSetManagedHost		zcdbSetManagedHost
#endif //#ifndef acdbSetManagedHost

#ifndef acdbTerminateManagedLayer
#define acdbTerminateManagedLayer		zcdbTerminateManagedLayer
#endif //#ifndef acdbTerminateManagedLayer

#endif //#ifndef __MGDHOST_H__
