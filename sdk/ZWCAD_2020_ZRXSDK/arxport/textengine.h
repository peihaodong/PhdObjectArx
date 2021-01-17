
#ifndef __TEXTENGINE_H__
#define __TEXTENGINE_H__

#include "acgi.h"
#include "AdAChar.h"
#include "Adesk.h"

#include "../inc/ztextengine.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGiTextEngine
#define AcGiTextEngine		ZcGiTextEngine
#endif //#ifndef AcGiTextEngine

#ifndef AcGiTextStyle
#define AcGiTextStyle		ZcGiTextStyle
#endif //#ifndef AcGiTextStyle

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __TEXTENGINE_H__
