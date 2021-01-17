//////////////////////////////////////////////////////////////////////////
#pragma once


//////////////////////////////////////////////////////////////////////////
// 声明一系列Acad派生宏，用于处理不同版本ARX,在subXX()的差别问题。

#if !defined(ARX) || (ARX < 18)

// 需要定义派生函数来调用subXX()
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