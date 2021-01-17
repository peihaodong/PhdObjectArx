
#ifndef __ACGIUTIL_H__
#define __ACGIUTIL_H__

#include "dbid.h"
#include "AdAChar.h"
#include "acgi.h"

#include "../inc/zacgiutil.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbStyleId
#define AcDbStyleId		ZcDbStyleId
#endif //#ifndef AcDbStyleId

#ifndef AcDbStyleName
#define AcDbStyleName		ZcDbStyleName
#endif //#ifndef AcDbStyleName

#ifndef AcGiTextStyle
#define AcGiTextStyle		ZcGiTextStyle
#endif //#ifndef AcGiTextStyle

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef fromAcDbTextStyle
#define fromAcDbTextStyle		fromZcDbTextStyle
#endif //#ifndef fromAcDbTextStyle

#ifndef toAcDbTextStyle
#define toAcDbTextStyle		toZcDbTextStyle
#endif //#ifndef toAcDbTextStyle

#endif //#ifndef __ACGIUTIL_H__
