
#ifndef __ACADSTRC_H__
#define __ACADSTRC_H__

#include "../inc/zacadstrc.h"

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef eFileLockedByACAD
#define eFileLockedByACAD		eFileLockedByZCAD
#endif //#ifndef eFileLockedByACAD

#ifndef eInetNoAcadInet
#define eInetNoAcadInet		eInetNoZcadInet
#endif //#ifndef eInetNoAcadInet

#ifndef eNoAcDbHostApplication
#define eNoAcDbHostApplication		eNoZcDbHostApplication
#endif //#ifndef eNoAcDbHostApplication

#ifndef eVSIsAcadDefault
#define eVSIsAcadDefault		eVSIsZcadDefault
#endif //#ifndef eVSIsAcadDefault

#ifndef eGetAdIntImgServicesFailed
#define eGetAdIntImgServicesFailed eGetZdIntImgServicesFailed
#endif 
#endif //#ifndef __ACADSTRC_H__