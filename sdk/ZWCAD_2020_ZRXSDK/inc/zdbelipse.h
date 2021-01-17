

#ifndef ZGEOMENT_DBELIPSE_H
#define ZGEOMENT_DBELIPSE_H

#include "zgegbl.h"
#include "zdbmain.h"
#include "zdbcurve.h"

#pragma pack(push, 8)

class ZcDbEllipse: public  ZcDbCurve
{
public:
    ZcDbEllipse();
    ZcDbEllipse(const ZcGePoint3d&  center,
	        const ZcGeVector3d& unitNormal,
	        const ZcGeVector3d& majorAxis,
	        double              radiusRatio,
	        double              startAngle = 0.0,
	        double              endAngle   = 6.28318530717958647692);
    virtual ~ZcDbEllipse();
    ZCDB_DECLARE_MEMBERS(ZcDbEllipse);

    ZcGePoint3d center() const;
    Zcad::ErrorStatus setCenter(const ZcGePoint3d& center);

    ZcGeVector3d normal() const;
    ZcGeVector3d majorAxis() const;
    ZcGeVector3d minorAxis() const;
	ZCDB_PORT double majorRadius() const;
	ZCDB_PORT Zcad::ErrorStatus setMajorRadius(double);
	ZCDB_PORT double minorRadius() const;
	ZCDB_PORT Zcad::ErrorStatus setMinorRadius(double);

    double radiusRatio() const;
    Zcad::ErrorStatus setRadiusRatio(double ratio);

    double startAngle() const;
    Zcad::ErrorStatus setStartAngle(double startAngle);    

    double endAngle() const;
    Zcad::ErrorStatus setEndAngle(double endAngle);

    Zcad::ErrorStatus setStartParam(double startParam);
    Zcad::ErrorStatus setEndParam(double endParam);

    double paramAtAngle(double angle) const;
    double angleAtParam(double param) const;

    Zcad::ErrorStatus get(ZcGePoint3d& center, ZcGeVector3d& unitNormal,
	ZcGeVector3d& majorAxis, double& radiusRatio, double& startAngle,
	double& endAngle) const;
    Zcad::ErrorStatus set(const ZcGePoint3d& center,
	const ZcGeVector3d& unitNormal, const ZcGeVector3d& majorAxis,
	double radiusRatio, double startAngle = 0.0,
	double endAngle = 6.28318530717958647692);

    ZSoft::Boolean isNull() const;
				   
    DBCURVE_METHODS

    virtual Zcad::ErrorStatus getGripPoints(ZcGePoint3dArray&    gripPoints,
	    ZcDbIntArray& osnapMasks, ZcDbIntArray& geomIds) const;

    virtual  Zcad::ErrorStatus moveGripPointsAt(
	const ZcDbIntArray& indices, const ZcGeVector3d& offset);

    virtual  Zcad::ErrorStatus intersectWith(
	const ZcDbEntity* ent, ZcDb::Intersect intType,
        ZcGePoint3dArray& points, ZSoft::GsMarker thisGsMarker = 0,
        ZSoft::GsMarker otherGsMarker = 0) const;

    virtual  Zcad::ErrorStatus intersectWith(
	const ZcDbEntity* ent, ZcDb::Intersect intType,
	const ZcGePlane& projPlane, ZcGePoint3dArray& points,
        ZSoft::GsMarker thisGsMarker = 0, ZSoft::GsMarker otherGsMarker = 0) const;

    virtual Zcad::ErrorStatus getTransformedCopy(
	const ZcGeMatrix3d& xform, ZcDbEntity*& ent) const;

    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
    virtual void gripStatus(const ZcDb::GripStat status);
    virtual Zcad::ErrorStatus   getGripPoints(ZcDbGripDataPtrArray& grips,
        const double curViewUnitSize, const int gripSize,
        const ZcGeVector3d& curViewDir, const int bitflags) const;

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);
};

#pragma pack(pop)

#endif
