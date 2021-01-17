#include "StdAfx.h"
#include "ZsdkSign.h"
#include "dbents.h"

ACRX_DXF_DEFINE_MEMBERS(ZsdkSign, AcDbEntity,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kTransformAllowed |
	AcDbProxyEntity::kColorChangeAllowed |
	AcDbProxyEntity::kLayerChangeAllowed,
	ZSDKSIGN, SignDb|Product: ZRX Enabler for Sign Entity|Company: ZWSOFT|Website: www.zwcad.com
	);

const double kCurrentVersionNumber = 1.0;

bool ZsdkSign::s_bHasClsid = false;
CLSID ZsdkSign::s_clsid;

ZsdkSign::ZsdkSign(void)
{
	mNormal = AcGeVector3d::kZAxis;
	mCenter = AcGePoint3d::kOrigin;
	mRadius = 10;
	mTextColor.setRGB(255, 255, 0);
	mText = _T("A");
}


ZsdkSign::~ZsdkSign(void)
{
}



Adesk::Boolean ZsdkSign::worldDraw(AcGiWorldDraw* wd)
{
	assertReadEnabled();

	wd->subEntityTraits().setTrueColor(entityColor());
	wd->subEntityTraits().setFillType(kAcGiFillNever);

	wd->geometry().circle(center(), radius(), normal());

	AcGePoint3dArray rectarray;
	AcGePoint3d ptTemp;
	double textHeight = radius() / 2;
	double rectsidelen = textHeight * 1.1;
	ptTemp = center();
	ptTemp[X] += rectsidelen / 2;
	ptTemp[Y] += rectsidelen / 2;
	rectarray.append(ptTemp);
	ptTemp[X] -= rectsidelen;
	rectarray.append(ptTemp);
	ptTemp[Y] -= rectsidelen;
	rectarray.append(ptTemp);
	ptTemp[X] += rectsidelen;
	rectarray.append(ptTemp);
	ptTemp[Y] += rectsidelen;
	rectarray.append(ptTemp);
	wd->geometry().polyline(5, rectarray.asArrayPtr(), &normal());

	AcGePoint3dArray lineptarray;
	lineptarray.append(rectarray[0]);
	ptTemp = center() + (lineptarray[0] - center()).normalize() * radius();
	lineptarray.append(ptTemp);
	wd->geometry().polyline(2, lineptarray.asArrayPtr(), &normal());
	
	lineptarray.removeAll();
	lineptarray.append(rectarray[1]);
	ptTemp = center() + (lineptarray[0] - center()).normalize() * radius();
	lineptarray.append(ptTemp);
	wd->geometry().polyline(2, lineptarray.asArrayPtr(), &normal());
	
	lineptarray.removeAll();
	lineptarray.append(rectarray[2]);
	ptTemp = center() + (lineptarray[0] - center()).normalize() * radius();
	lineptarray.append(ptTemp);
	wd->geometry().polyline(2, lineptarray.asArrayPtr(), &normal());
	
	lineptarray.removeAll();
	lineptarray.append(rectarray[3]);
	ptTemp = center() + (lineptarray[0] - center()).normalize() * radius();
	lineptarray.append(ptTemp);
	wd->geometry().polyline(2, lineptarray.asArrayPtr(), &normal());

	AcDbMText* pText = new AcDbMText();
	pText->setDatabaseDefaults();
	pText->setNormal(normal());
	pText->setContents(text());
	pText->setTextHeight(textHeight);
	pText->setColor(textTrueColor());
	pText->setLocation(center());
	pText->setAttachment(AcDbMText::kMiddleCenter);
	pText->worldDraw(wd);
	delete pText;
	pText = NULL;

	return Adesk::kTrue;
}

Acad::ErrorStatus ZsdkSign::dwgInFields(AcDbDwgFiler* filer)
{
	assertWriteEnabled();
	AcDbEntity::dwgInFields(filer);
	// Read version number
    double version;
    filer->readItem(&version);

    if (version > kCurrentVersionNumber)
	{
        return Acad::eMakeMeProxy;
    }
	
    filer->readItem(&mNormal);
    filer->readItem(&mCenter);
    filer->readItem(&mRadius);
	Adesk::UInt32 color;
    filer->readUInt32(&color);
	mTextColor.setColor(color);
	ACHAR* pszBuf = NULL;
	filer->readString(&pszBuf);
	setText(AcString(pszBuf));
	delString(pszBuf);
		
    return filer->filerStatus();
}

Acad::ErrorStatus ZsdkSign::dwgOutFields(AcDbDwgFiler* filer) const
{
	assertReadEnabled();
	AcDbEntity::dwgOutFields(filer);
	filer->writeItem(kCurrentVersionNumber);
	filer->writeItem(mNormal);
	filer->writeItem(mCenter);
	filer->writeItem(mRadius);
	filer->writeItem(mTextColor.color());
	filer->writeString((LPCTSTR)mText);
	return filer->filerStatus();
}

Acad::ErrorStatus ZsdkSign::dxfInFields(AcDbDxfFiler* filer)
{
	assertWriteEnabled();
	
	struct resbuf rb;
    AcGePoint3d center, mouthleftpt, mouthbottompt, mouthrightpt;
    double radius;

    Acad::ErrorStatus es = AcDbEntity::dxfInFields( filer );

    if( Acad::eOk != es ) {
        return es;
    }

    // Check that we are at the correct subclass data
    //
    if( !filer->atSubclassData( _T("ZsdkSign") ))
	{
        return Acad::eBadDxfSequence;
    }

    // First piece of data MUST be the version number
    if( Acad::eOk != ( es = filer->readItem( &rb )))
	{
        return es;
    }

    if ( AcDb::kDxfReal != rb.restype )
	{
        return Acad::eMakeMeProxy;
    }

    // Check version first
    if ( rb.resval.rreal > 1.0 )
	{
        return Acad::eMakeMeProxy;
    }

    // Set the normal's default value in case it's not in the
    // DXF information coming in
    //
    mNormal = AcGeVector3d( 0, 0, 1 ); // set default value:

    while( Acad::eOk == es ) {
        if( Acad::eOk == ( es = filer->readItem( &rb ))) {
            switch( rb.restype ) {
            case AcDb::kDxfXCoord:
                center.set( rb.resval.rpoint[X],
                            rb.resval.rpoint[Y],
                            rb.resval.rpoint[Z]);
                setCenter( center );
                break;
            case AcDb::kDxfReal+1:
                radius = rb.resval.rreal;
                setRadius( radius );
                break;
            case AcDb::kDxfNormalX:
                mNormal.set( rb.resval.rpoint[X],
                             rb.resval.rpoint[Y],
                             rb.resval.rpoint[Z]);
				break;
			case AcDb::kDxfColor:
				{
					filer->pushBackItem();
					AcCmColor col;
					col.dxfIn(filer);
					setColor(col);
				}
				break;
			case AcDb::kDxfText:
				setText(AcString(rb.resval.rstring));
				break;
            }
        }
    }

    return filer->filerStatus();
}

Acad::ErrorStatus ZsdkSign::dxfOutFields(AcDbDxfFiler* filer) const
{
	assertReadEnabled();
	
	AcDbEntity::dxfOutFields( filer );

    filer->writeItem( AcDb::kDxfSubclass, _T("ZsdkSign") );
    // Write version number
    filer->writeItem( AcDb::kDxfReal, kCurrentVersionNumber );
    filer->writeItem( AcDb::kDxfXCoord, center() );
    filer->writeItem( AcDb::kDxfReal+1, radius() );
    if( filer->includesDefaultValues()
        || mNormal != AcGeVector3d( 0, 0, 1 ))
    {
        filer->writeItem( AcDb::kDxfNormalX, mNormal );
    }
	AcCmColor col = textTrueColor();
	col.dxfOut( filer );
	filer->writeString( AcDb::kDxfText, (LPCTSTR)mText );

    return filer->filerStatus();

}

Acad::ErrorStatus ZsdkSign::explode(AcDbVoidPtrArray& entitySet) const
{
	assertReadEnabled();

	AcDbCircle *pCircle = new AcDbCircle( center(), normal(), radius() );
    entitySet.append( pCircle );

	AcDbLine *pLine = NULL;

	AcGePoint3dArray rectarray;
	AcGePoint3d ptTemp;
	double textHeight = radius() / 2;
	double rectsidelen = textHeight * 1.1;
	ptTemp = center();
	ptTemp[X] += rectsidelen / 2;
	ptTemp[Y] += rectsidelen / 2;
	rectarray.append(ptTemp);
	ptTemp[X] -= rectsidelen;
	rectarray.append(ptTemp);
	ptTemp[Y] -= rectsidelen;
	rectarray.append(ptTemp);
	ptTemp[X] += rectsidelen;
	rectarray.append(ptTemp);
	ptTemp[Y] += rectsidelen;
	rectarray.append(ptTemp);

	pLine = new AcDbLine( rectarray[0], rectarray[1] );
    entitySet.append( pLine );
	pLine = new AcDbLine( rectarray[1], rectarray[2] );
    entitySet.append( pLine );
	pLine = new AcDbLine( rectarray[2], rectarray[3] );
    entitySet.append( pLine );
	pLine = new AcDbLine( rectarray[3], rectarray[0] );
    entitySet.append( pLine );

	AcGePoint3dArray lineptarray;
	lineptarray.append(rectarray[0]);
	ptTemp = center() + (lineptarray[0] - center()).normalize() * radius();
	lineptarray.append(ptTemp);
	
	pLine = new AcDbLine( lineptarray[0], lineptarray[1] );
    entitySet.append( pLine );
	
	lineptarray.removeAll();
	lineptarray.append(rectarray[1]);
	ptTemp = center() + (lineptarray[0] - center()).normalize() * radius();
	lineptarray.append(ptTemp);
	
	pLine = new AcDbLine( lineptarray[0], lineptarray[1] );
    entitySet.append( pLine );
	
	lineptarray.removeAll();
	lineptarray.append(rectarray[2]);
	ptTemp = center() + (lineptarray[0] - center()).normalize() * radius();
	lineptarray.append(ptTemp);
	
	pLine = new AcDbLine( lineptarray[0], lineptarray[1] );
    entitySet.append( pLine );
	
	lineptarray.removeAll();
	lineptarray.append(rectarray[3]);
	ptTemp = center() + (lineptarray[0] - center()).normalize() * radius();
	lineptarray.append(ptTemp);
	
	pLine = new AcDbLine( lineptarray[0], lineptarray[1] );
    entitySet.append( pLine );

	AcDbMText* pText = new AcDbMText();
	pText->setDatabaseDefaults();
	pText->setNormal(normal());
	pText->setContents(text());
	pText->setTextHeight(textHeight);
	pText->setColor(textTrueColor());
	pText->setLocation(center());
	pText->setAttachment(AcDbMText::kMiddleCenter);
	entitySet.append( pText );

    return Acad::eOk;
}

void ZsdkSign::list() const
{
	assertReadEnabled();

    AcGePoint3d cen(center());
	
    AcDbEntity::list();
    acutPrintf(
        _T("%12scenter point, X=%9.16q0  Y=%9.16q0  Z=%9.16q0\n")
        _T("%11s radius %9.16q0\n"),
        _T(""), cen[X], cen[Y], cen[Z],
		_T(""), radius()
    );
}

Acad::ErrorStatus ZsdkSign::getGripPoints(AcGePoint3dArray& gripPoints,
	AcDbIntArray& osnapModes,
	AcDbIntArray& geomIds) const
{
	assertReadEnabled();

	AcGePoint3d cen( center() );
    gripPoints.append( cen );

    AcGeVector3d xoff( radius(), 0, 0 );
    AcGeVector3d yoff( 0, radius(), 0 );
    gripPoints.append( cen + xoff );
    gripPoints.append( cen + yoff );
    gripPoints.append( cen - xoff );
    gripPoints.append( cen - yoff );

	return Acad::eOk;
}

Acad::ErrorStatus ZsdkSign::moveGripPointsAt(const AcDbIntArray& indices,
	const AcGeVector3d& offset)
{
	assertWriteEnabled();

	AcGePoint3dArray eyearray;
    AcGePoint3d oldquad, newquad;

    for( int i = 0; i < indices.length(); i++ )
	{
        int idx = indices[i];
        switch( idx )
		{
        case 0:
            setCenter( center() + offset );
            continue;
			break;
        case 1:
            oldquad = center() + AcGeVector3d( radius(), 0, 0 );
            break;
        case 2:
            oldquad = center() + AcGeVector3d( 0, radius(), 0 );
            break;
        case 3:
            oldquad = center() - AcGeVector3d( radius(), 0, 0 );
            break;
        case 4:
            oldquad = center() - AcGeVector3d( 0, radius(), 0 );
            break;
        }
        newquad = oldquad + offset;
        setRadius( newquad.distanceTo( center() ));
    }
	return Acad::eOk;
}

Acad::ErrorStatus ZsdkSign::transformBy(const AcGeMatrix3d& xform)
{
	assertWriteEnabled();
	
	setCenter(center().transformBy(xform));

	return Acad::eOk;
}

void ZsdkSign::initCLSID()
{
	s_bHasClsid = SUCCEEDED(CLSIDFromProgID(L"SignDb.Entity", &s_clsid));
	if (!s_bHasClsid)
	{
		HMODULE hModule = GetModuleHandle(_T("SignDb.zrx"));
		TCHAR szBuf[MAX_PATH] = {0};
		::GetModuleFileName(hModule, szBuf, MAX_PATH);
		_tcscpy(szBuf + _tcslen(szBuf) - _tcslen(_T("SignDb.zrx")), _T("SignDbCom.dll"));
		HMODULE hMod = ::LoadLibrary(szBuf);
		if (hMod)
		{
			typedef HRESULT (WINAPI *SETUP)(void);
			SETUP pSetUp = (SETUP)GetProcAddress(hMod, "SetUp");
			if (pSetUp)
			{
				pSetUp();
				s_bHasClsid = SUCCEEDED(CLSIDFromProgID(L"SignDb.Entity", &s_clsid));
			}
			::FreeLibrary(hMod);
		}
	}
}

Acad::ErrorStatus ZsdkSign::getClassID(CLSID* pClsid) const
{
	assertReadEnabled();
	if (s_bHasClsid)
	{
		*pClsid = s_clsid;
		return Acad::eOk;
	}
	else
	{
		return Acad::eNotImplementedYet;
	}
}

AcGeVector3d ZsdkSign::normal() const
{
	assertReadEnabled();
	return mNormal;
}

void ZsdkSign::setNormal(const AcGeVector3d v)
{
	assertWriteEnabled();
	mNormal = v;
	recordGraphicsModified();
}

AcGePoint3d ZsdkSign::center() const
{
	assertReadEnabled();
	return mCenter;
}

void ZsdkSign::setCenter(const AcGePoint3d c)
{
	assertWriteEnabled();
	mCenter = c;
	recordGraphicsModified();
}

double ZsdkSign::radius() const
{
	assertReadEnabled();
	return mRadius;
}

void ZsdkSign::setRadius(const double r)
{
	assertWriteEnabled();
	mRadius = r;
	recordGraphicsModified();
}

AcCmColor ZsdkSign::textTrueColor() const
{
	assertReadEnabled();
	return mTextColor;
}

void ZsdkSign::setTextTrueColor(const AcCmColor& color)
{
	assertWriteEnabled();
	mTextColor = color;
	recordGraphicsModified();
}

AcString ZsdkSign::text() const
{
	assertReadEnabled();
	return mText;
}

void ZsdkSign::setText(const AcString& t)
{
	assertWriteEnabled();
	if (t.length() > 1)
		mText = t.mid(0, 1);
	else
		mText = t;
	recordGraphicsModified();
}
