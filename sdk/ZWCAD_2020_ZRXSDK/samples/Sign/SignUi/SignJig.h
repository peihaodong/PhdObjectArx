#pragma once

#include "../SignDb/ZsdkSign.h"

class SignJig :
	public AcEdJig
{
public:
	SignJig(const AcGePoint3d&, const AcGeVector3d&);
	virtual ~SignJig(void);
public:
	void start();
    AcDbEntity* entity() const;
    DragStatus sampler();
    Adesk::Boolean update();
private:
	ZsdkSign* mpSign;
	double mRadius;
};

