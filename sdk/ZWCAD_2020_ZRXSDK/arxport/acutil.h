
#ifndef __ACUTIL_H__
#define __ACUTIL_H__

#include <stddef.h>
#include "acadstrc.h"

#include "../inc/zacutil.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef acutSplitString
#define acutSplitString		zcutSplitString
#endif //#ifndef acutSplitString

#ifndef acutTrimWhiteSpace
#define acutTrimWhiteSpace		zcutTrimWhiteSpace
#endif //#ifndef acutTrimWhiteSpace

#ifndef acutWcMatchEx
#define acutWcMatchEx		zcutWcMatchEx
#endif //#ifndef acutWcMatchEx

#ifndef acutXStrLength
#define acutXStrLength		zcutXStrLength
#endif //#ifndef acutXStrLength

#ifndef acutXStrNormalize
#define acutXStrNormalize		zcutXStrNormalize
#endif //#ifndef acutXStrNormalize

#ifndef acutXStrUppercase
#define acutXStrUppercase		zcutXStrUppercase
#endif //#ifndef acutXStrUppercase

#endif //#ifndef __ACUTIL_H__
