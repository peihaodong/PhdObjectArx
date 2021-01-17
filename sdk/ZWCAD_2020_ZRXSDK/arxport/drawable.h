
#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__

#include "rxobject.h"
#include "dbid.h"

#include "../inc/zdrawable.h"

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbSubentId
#define AcDbSubentId		ZcDbSubentId
#endif //#ifndef AcDbSubentId

#ifndef AcGiDrawable
#define AcGiDrawable		ZcGiDrawable
#endif //#ifndef AcGiDrawable

#ifndef AcGiDrawableTraits
#define AcGiDrawableTraits		ZcGiDrawableTraits
#endif //#ifndef AcGiDrawableTraits

#ifndef AcGiViewportDraw
#define AcGiViewportDraw		ZcGiViewportDraw
#endif //#ifndef AcGiViewportDraw

#ifndef AcGiWorldDraw
#define AcGiWorldDraw		ZcGiWorldDraw
#endif //#ifndef AcGiWorldDraw

#ifndef AcGsNode
#define AcGsNode		ZcGsNode
#endif //#ifndef AcGsNode

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef AcGiDrawStream
#define AcGiDrawStream	ZcGiDrawStream
#endif 

#endif //#ifndef __DRAWABLE_H__