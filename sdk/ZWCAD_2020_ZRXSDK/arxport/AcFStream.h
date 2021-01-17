
#ifndef __ACFSTREAM_H__
#define __ACFSTREAM_H__

#include "malloc.h"             // for _alloca()
#include "AdAChar.h"
#include "AdCharFmt.h"

#include "../inc/zAcFStream.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcFStream_Assert
#define AcFStream_Assert		ZcFStream_Assert
#endif //#ifndef AcFStream_Assert

#ifndef AcFStream_curLocale
#define AcFStream_curLocale		ZcFStream_curLocale
#endif //#ifndef AcFStream_curLocale

#ifndef AcFStream_wideToMulti
#define AcFStream_wideToMulti		ZcFStream_wideToMulti
#endif //#ifndef AcFStream_wideToMulti

#ifndef AcIfstream
#define AcIfstream		ZcIfstream
#endif //#ifndef AcIfstream

#ifndef AcOfstream
#define AcOfstream		ZcOfstream
#endif //#ifndef AcOfstream

#endif //#ifndef __ACFSTREAM_H__
