

#ifndef ZD_DBSPFILT_H
#define ZD_DBSPFILT_H

#include "zdbfilter.h"
#include "zgepnt2d.h"
#include "zgevec2d.h"
#include "zgept2dar.h"

#pragma pack (push, 8)

#define ZCDB_INFINITE_XCLIP_DEPTH (1.0e+300)

class ZcDbExtents;

class ZcDbSpatialFilter: public  ZcDbFilter
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbSpatialFilter);

	     ZcDbSpatialFilter();
    virtual ~ZcDbSpatialFilter();

    virtual ZcRxClass* indexClass() const;

    virtual void queryBounds(ZcDbExtents& ext, 
                             const ZcDbBlockReference * pRefBlkRef) const;

    ZcDbSpatialFilter(const ZcGePoint2dArray& pts, 
                      const ZcGeVector3d&     normal,
                      double                  elevation,
                      double                  frontClip,
                      double                  backClip,
                      ZSoft::Boolean          enabled);

    void queryBounds(ZcDbExtents& ext) const;

    Zcad::ErrorStatus  getVolume(ZcGePoint3d&  fromPt, 
                                 ZcGePoint3d&  toPt, 
                                 ZcGeVector3d& upDir,
                                 ZcGeVector2d& viewField) const;

    Zcad::ErrorStatus setDefinition(const ZcGePoint2dArray& pts, 
                                    const ZcGeVector3d&     normal,
                                    double                  elevation,
                                    double                  frontClip,
                                    double                  backClip,
                                    ZSoft::Boolean          enabled);                                    

   Zcad::ErrorStatus getDefinition(ZcGePoint2dArray& pts, 
                                   ZcGeVector3d&     normal,
                                   double&           elevation,
                                   double&           frontClip,
                                   double&           backClip,
                                   ZSoft::Boolean&   enabled) const;

    ZcGeMatrix3d& getClipSpaceToWCSMatrix(ZcGeMatrix3d& mat) const;
    ZcGeMatrix3d& getOriginalInverseBlockXform(ZcGeMatrix3d& mat) const;
   Zcad::ErrorStatus setPerspectiveCamera(const ZcGePoint3d& fromPt);

   ZSoft::Boolean    clipVolumeIntersectsExtents(const ZcDbExtents& ext) const;

   ZSoft::Boolean    hasPerspectiveCamera() const;

};

#pragma pack (pop)

#endif 
