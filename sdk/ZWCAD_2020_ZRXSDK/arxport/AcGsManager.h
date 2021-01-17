
#ifndef __ACGSMANAGER_H__
#define __ACGSMANAGER_H__

#include "../inc/zAcGsManager.h"

#ifndef AcDbViewportTableRecord
#define AcDbViewportTableRecord		ZcDbViewportTableRecord
#endif //#ifndef AcDbViewportTableRecord

#ifndef AcGiDrawable
#define AcGiDrawable		ZcGiDrawable
#endif //#ifndef AcGiDrawable

#ifndef AcGsClassFactory
#define AcGsClassFactory		ZcGsClassFactory
#endif //#ifndef AcGsClassFactory

#ifndef AcGsDevice
#define AcGsDevice		ZcGsDevice
#endif //#ifndef AcGsDevice

#ifndef AcGsManager
#define AcGsManager		ZcGsManager
#endif //#ifndef AcGsManager

#ifndef AcGsModel
#define AcGsModel		ZcGsModel
#endif //#ifndef AcGsModel

#ifndef AcGsView
#define AcGsView		ZcGsView
#endif //#ifndef AcGsView

#ifndef createAutoCADDevice
#define createAutoCADDevice		createZWCADDevice
#endif //#ifndef createAutoCADDevice

#ifndef createAutoCADModel
#define createAutoCADModel		createZWCADModel
#endif //#ifndef createAutoCADModel

#ifndef createAutoCADOffScreenDevice
#define createAutoCADOffScreenDevice		createZWCADOffScreenDevice
#endif //#ifndef createAutoCADOffScreenDevice

#ifndef createAutoCADView
#define createAutoCADView		createZWCADView
#endif //#ifndef createAutoCADView

#ifndef createAutoCADViewport
#define createAutoCADViewport		createZWCADViewport
#endif //#ifndef createAutoCADViewport

#ifndef destroyAutoCADDevice
#define destroyAutoCADDevice		destroyZWCADDevice
#endif //#ifndef destroyAutoCADDevice

#ifndef destroyAutoCADModel
#define destroyAutoCADModel		destroyZWCADModel
#endif //#ifndef destroyAutoCADModel

#ifndef destroyAutoCADView
#define destroyAutoCADView		destroyZWCADView
#endif //#ifndef destroyAutoCADView

#endif //#ifndef __ACGSMANAGER_H__
