
#ifndef __ACUTMEM_H__
#define __ACUTMEM_H__

#include "acadstrc.h"   // Acad::ErrorStatus
#include "AdAChar.h"    // ACHAR

#include "../inc/zacutmem.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef acutDelBuffer
#define acutDelBuffer		zcutDelBuffer
#endif //#ifndef acutDelBuffer

#ifndef acutDelString
#define acutDelString		zcutDelString
#endif //#ifndef acutDelString

#ifndef acutNewBuffer
#define acutNewBuffer		zcutNewBuffer
#endif //#ifndef acutNewBuffer

#ifndef acutNewString
#define acutNewString		zcutNewString
#endif //#ifndef acutNewString

#ifndef acutUpdString
#define acutUpdString		zcutUpdString
#endif //#ifndef acutUpdString

#endif //#ifndef __ACUTMEM_H__
