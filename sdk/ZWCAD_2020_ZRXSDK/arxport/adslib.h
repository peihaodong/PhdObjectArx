
#ifndef __ADSLIB_H__
#define __ADSLIB_H__

#include "ads.h"
#include "adscodes.h"

#include "../inc/zadslib.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef acrxApplicationIsLocked
#define acrxApplicationIsLocked		zcrxApplicationIsLocked
#endif //#ifndef acrxApplicationIsLocked

#ifndef acrxLockApplication
#define acrxLockApplication		zcrxLockApplication
#endif //#ifndef acrxLockApplication

#ifndef acrxUnlockApplication
#define acrxUnlockApplication		zcrxUnlockApplication
#endif //#ifndef acrxUnlockApplication

#endif //#ifndef __ADSLIB_H__
