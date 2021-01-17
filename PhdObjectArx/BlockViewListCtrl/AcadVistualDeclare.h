//////////////////////////////////////////////////////////////////////////
#pragma once


//////////////////////////////////////////////////////////////////////////
// ����һϵ��Acad�����꣬���ڴ���ͬ�汾ARX,��subXX()�Ĳ�����⡣

#if !defined(ARX) || (ARX < 18)

// ��Ҫ������������������subXX()
#define _NotSubAbstract

#endif


#if !defined(ARX) || (ARX < 18)


//////////////////////////////////////////////////////////////////////////
// setAttributes
#define _setAttributes \
	virtual Adesk::UInt32   setAttributes   (AcGiDrawableTraits * traits) \
	{ \
		return subSetAttributes(traits); \
	}

//////////////////////////////////////////////////////////////////////////
// worldDraw
#define _worldDraw \
	virtual Adesk::Boolean  worldDraw       (AcGiWorldDraw * wd)\
	{\
		return subWorldDraw(wd);\
	}

//////////////////////////////////////////////////////////////////////////
// viewportDraw
#define _viewportDraw \
	virtual void viewportDraw    (AcGiViewportDraw * pViewportDraw) \
	{\
		return subViewportDraw(pViewportDraw); \
	}

//////////////////////////////////////////////////////////////////////////
// 


#else
#define _setAttributes
#define _worldDraw
#define _viewportDraw
#endif