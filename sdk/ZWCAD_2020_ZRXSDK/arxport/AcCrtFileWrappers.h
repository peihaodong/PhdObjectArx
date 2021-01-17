
#ifndef __ACCRTFILEWRAPPERS_H__
#define __ACCRTFILEWRAPPERS_H__
#include "stdio.h"      
#include <malloc.h>     
#include "AdCharFmt.h"

#include "../inc/zAcCrtFileWrappers.h"

#ifndef AcFILE
#define AcFILE		ZcFILE
#endif //#ifndef AcFILE

#ifndef AcFILE_Assert
#define AcFILE_Assert		ZcFILE_Assert
#endif //#ifndef AcFILE_Assert

#endif //#ifndef __ACCRTFILEWRAPPERS_H__
