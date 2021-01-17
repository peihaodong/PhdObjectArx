
#ifndef __ADACHAR_H__
#define __ADACHAR_H__

#include "../inc/zAdAChar.h"

#ifndef ACRX_T
#define ACRX_T		ZCRX_T
#endif //#ifndef ACRX_T

#ifndef AD_UNICODE
#ifdef  ZW_UNICODE_SWITCH
#define AD_UNICODE		ZD_UNICODE
#endif
#endif //#ifndef AD_UNICODE

#ifndef _ACRX_T
#define _ACRX_T		_ZCRX_T
#endif //#ifndef _ACRX_T

#ifndef ACHAR
#define ACHAR ZTCHAR
#endif //#ifndef ACHAR

#endif //#ifndef __ADACHAR_H__
