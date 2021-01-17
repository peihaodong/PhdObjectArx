#ifndef AECMODELER_INC_WALLCRNR_H
#define AECMODELER_INC_WALLCRNR_H

#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN


DllImpExp ZwBody ZwCreateWallCornerBody(
                    const ZwPoint2d& pt1,     // Start of wall 1
                    const ZwPoint2d& pt2,     // End of wall 1, start of wall 2
                    const ZwPoint2d& pt3,     // End of wall 2
                    bool           materialToTheLeft,
                    double         width1,  // Wall 1 width
                    double         width2,  // Wall 2 width
                    double         height,  // Wall height
                    ZwColor          matingFacesColor,
                    ZwPlane&         matingPlane1,
                    ZwPlane&         matingPlane2,
                    bool&          wall1NeedsToBeSectioned,
                    bool&          wall2NeedsToBeSectioned);

AECMODELER_NAMESPACE_END
#endif

