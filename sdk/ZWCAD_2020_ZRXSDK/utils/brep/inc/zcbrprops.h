#ifndef ZC_BRPROPS_H
#define ZC_BRPROPS_H 1

#include "zadesk.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"


struct ZcBrMassProps
{
	double			mVolume; // 2nd field in AmiMassProps
	double			mMass; // 1st field in AmiMassProps
	ZcGePoint3d		mCentroid; // 5th field in AmiMassProps
	double			mRadiiGyration[3]; // 3rd field in AmiMassProps
	double			mMomInertia[3]; // 7th field in AmiMassProps
	double			mProdInertia[3]; // 8th field in AmiMassProps
	double			mPrinMoments[3]; // 4th field in AmiMassProps
	ZcGeVector3d	mPrinAxes[3]; // 6th field in AmiMassProps
};


#endif

