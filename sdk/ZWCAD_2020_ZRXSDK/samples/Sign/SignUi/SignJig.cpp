#include "StdAfx.h"
#include "SignJig.h"

ACRX_DEFINE_MEMBERS(ZsdkSign);

SignJig::SignJig(const AcGePoint3d& center, const AcGeVector3d& normal)
{
	mpSign = (ZsdkSign*)ZsdkSign::desc()->create();
	mpSign->setDatabaseDefaults();
	mpSign->setCenter(center);
	mpSign->setNormal(normal);
}


SignJig::~SignJig(void)
{
	if (mpSign)
	{
		delete mpSign;
		mpSign = NULL;
	}
}

void SignJig::start()
{
    setDispPrompt(_T("\nRadius: "));
    AcEdJig::DragStatus stat = drag();

    if (kNormal == stat)
	{
        append();
    }
    else
	{
        delete mpSign;
    }
    mpSign = NULL;
}

AcEdJig::DragStatus SignJig::sampler()
{
    double dist;

    setUserInputControls((UserInputControls)(kAccept3dCoordinates | kGovernedByOrthoMode | kDontUpdateLastPoint));

    DragStatus stat = acquireDist(dist, mpSign->center());
    if (kNormal == stat)
	{
        if (0.0 >= dist)
		{
            stat = kOther;
		}
        else
		{
            // save new radius for later update of our entity
            if (dist != mRadius)
                mRadius = dist;
            else
                stat = kNoChange;
        }
    }
    return stat;
}

Adesk::Boolean SignJig::update()
{
	mpSign->setRadius(mRadius);
	return Adesk::kTrue;
}

AcDbEntity * SignJig::entity() const
{
    return mpSign;
}


void createSign()
{
    AcGePoint3d cen;
    struct resbuf rbFrom, rbTo;

    ads_getpoint(NULL, _T("\nCenter point: "), asDblArray(cen));

    rbFrom.restype = RTSHORT;
    rbFrom.resval.rint = 1; // from UCS
    rbTo.restype = RTSHORT;
    rbTo.resval.rint = 0; // to WCS

    ads_trans(asDblArray(cen), &rbFrom, &rbTo, Adesk::kFalse, asDblArray(cen));

    AcGeVector3d x = acdbHostApplicationServices()->workingDatabase()->ucsxdir();
    AcGeVector3d y = acdbHostApplicationServices()->workingDatabase()->ucsydir();

    AcGeVector3d normal = x.crossProduct(y);
    normal.normalize();

    SignJig jig(cen, normal);

    jig.start();
}