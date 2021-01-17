
#ifndef ZCDB_DBHELIX_H
#define ZCDB_DBHELIX_H

#include "zgegbl.h"
#include "zdbmain.h"
#include "zdbspline.h"

#pragma pack (push, 8)

class ZcDbHelix : public ZcDbSpline
{
public:
	enum ConstrainType {
		kTurnHeight = 0,
		kTurns      = 1,
		kHeight     = 2
	};

public:
	ZCDB_DECLARE_MEMBERS(ZcDbHelix);

	ZcDbHelix();

	virtual ~ZcDbHelix();
    Zcad::ErrorStatus createHelix();
    virtual Zcad::ErrorStatus getClassID(CLSID* pClsid) const;
    virtual ZcGePoint3d axisPoint() const;
    virtual Zcad::ErrorStatus setAxisPoint(const ZcGePoint3d &axisPoint,
        const bool bMoveStartPoint = true);
    virtual ZcGePoint3d startPoint() const;
    virtual Zcad::ErrorStatus setStartPoint(const ZcGePoint3d &startPoint);
    virtual ZcGeVector3d axisVector() const;
    virtual Zcad::ErrorStatus setAxisVector(const ZcGeVector3d &axisVector);
    virtual double height() const;
    virtual Zcad::ErrorStatus setHeight(double dHeight);
    virtual double baseRadius() const;
    virtual Zcad::ErrorStatus setBaseRadius(double dRadius);
    virtual double topRadius() const;
    virtual Zcad::ErrorStatus setTopRadius(double dRadius);
    virtual double turns() const;
    virtual Zcad::ErrorStatus setTurns(double dTurns);
    virtual double turnHeight() const;
    virtual Zcad::ErrorStatus setTurnHeight(double dTurnHeight);
    virtual ZSoft::Boolean twist() const;
    virtual Zcad::ErrorStatus setTwist(ZSoft::Boolean bTwist);
    virtual ConstrainType constrain() const;
    virtual Zcad::ErrorStatus setConstrain(ConstrainType constrain);
    virtual double turnSlope() const;
    virtual double totalLength() const;
    virtual void gripStatus(const ZcDb::GripStat status);
	virtual Zcad::ErrorStatus reverseCurve();
};

#pragma pack (pop)

#endif 
