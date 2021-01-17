
#ifndef __ADS_H__
#define __ADS_H__

#ifndef DISABLE_OLD_ADS_NAMES
#include "adsmigr.h"
#endif  

#include "acedads.h"
#include "acdbads.h"
#include "acutads.h"

#include "../inc/zads.h"

#ifndef acdbads
#define acdbads		zcdbads
#endif //#ifndef acdbads

#ifndef acedads
#define acedads		zcedads
#endif //#ifndef acedads

#ifndef acutads
#define acutads		zcutads
#endif //#ifndef acutads

#endif //#ifndef __ADS_H__
