
#ifndef __ADUIVOLUMEDESCRIPTOR_H__
#define __ADUIVOLUMEDESCRIPTOR_H__

#include "AdAChar.h"

#ifdef ACUTIL_INTERNAL
#include <tchar.h>
#include <afx.h>
#ifdef ADUI_PORT
#undef ADUI_PORT
#endif
#define ADUI_PORT
#endif

#include "aduipathenums.h"

#include "../inc/zaduiVolumeDescriptor.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_T
#define ACRX_T		ZCRX_T
#endif //#ifndef ACRX_T

#ifndef ACUTIL_INTERNAL
#define ACUTIL_INTERNAL		ZCUTIL_INTERNAL
#endif //#ifndef ACUTIL_INTERNAL

#ifndef ADUI_PORT
#define ADUI_PORT		ZDUI_PORT
#endif //#ifndef ADUI_PORT

#ifndef CAdUiCDFSVolumeDescriptor
#define CAdUiCDFSVolumeDescriptor		CZdUiCDFSVolumeDescriptor
#endif //#ifndef CAdUiCDFSVolumeDescriptor

#ifndef CAdUiFATVolumeDescriptor
#define CAdUiFATVolumeDescriptor		CZdUiFATVolumeDescriptor
#endif //#ifndef CAdUiFATVolumeDescriptor

#ifndef CAdUiHPFSVolumeDescriptor
#define CAdUiHPFSVolumeDescriptor		CZdUiHPFSVolumeDescriptor
#endif //#ifndef CAdUiHPFSVolumeDescriptor

#ifndef CAdUiNOFSVolumeDescriptor
#define CAdUiNOFSVolumeDescriptor		CZdUiNOFSVolumeDescriptor
#endif //#ifndef CAdUiNOFSVolumeDescriptor

#ifndef CAdUiNTFSVolumeDescriptor
#define CAdUiNTFSVolumeDescriptor		CZdUiNTFSVolumeDescriptor
#endif //#ifndef CAdUiNTFSVolumeDescriptor

#ifndef CAdUiPathname
#define CAdUiPathname		CZdUiPathname
#endif //#ifndef CAdUiPathname

#ifndef CAdUiUFSVolumeDescriptor
#define CAdUiUFSVolumeDescriptor		CZdUiUFSVolumeDescriptor
#endif //#ifndef CAdUiUFSVolumeDescriptor

#ifndef CAdUiVFATVolumeDescriptor
#define CAdUiVFATVolumeDescriptor		CZdUiVFATVolumeDescriptor
#endif //#ifndef CAdUiVFATVolumeDescriptor

#ifndef CAdUiVolumeDescriptor
#define CAdUiVolumeDescriptor		CZdUiVolumeDescriptor
#endif //#ifndef CAdUiVolumeDescriptor

#endif //#ifndef __ADUIVOLUMEDESCRIPTOR_H__
