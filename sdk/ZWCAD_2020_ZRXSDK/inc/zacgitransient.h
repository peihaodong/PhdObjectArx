

#ifndef _ZCGITRANSIENTMANAGER_H
#define _ZCGITRANSIENTMANAGER_H

typedef enum
{
	kZcGiMain = 0,
	kZcGiSprite,
	kZcGiDirectShortTerm,
	kZcGiHighlight,
	kZcGiDirectTopmost,
	kZcGiContrast,
	kZcGiDrawingModeCount
} ZcGiTransientDrawingMode;

class ZcGiDrawable;

class ZcGiTransientManager
{
public:
	virtual		~ZcGiTransientManager	(void)	{	}
	
	virtual bool addTransient			(ZcGiDrawable* pDrawable, ZcGiTransientDrawingMode mode, 
										 int subDrawingMode, 
										 const ZcArray<int>& viewportNumbers)	= 0;
	
	virtual bool eraseTransient			(ZcGiDrawable* pDrawable, 
										 const ZcArray<int>& viewportNumbers)	= 0;
	
	virtual bool eraseTransients		(ZcGiTransientDrawingMode mode, 
										 int subDrawingMode, 
										 const ZcArray<int>& viewportNumbers)	= 0;
	
	virtual void updateTransient		(ZcGiDrawable* pDrawable, 
										 const ZcArray<int>& viewportNumbers)	= 0;
	
	virtual bool addChildTransient		(ZcGiDrawable * pDrawable, 
										 ZcGiDrawable * pParentDrawable)		= 0;
	
	virtual bool eraseChildTransient	(ZcGiDrawable * pDrawable, 
										 ZcGiDrawable * pParentDrawable)		= 0;
	
	virtual void updateChildTransient	(ZcGiDrawable * pDrawable, 
										 ZcGiDrawable * pParentDrawable)		= 0;
	
	virtual int  getFreeSubDrawingMode	(ZcGiTransientDrawingMode mode, 
										 int& subDrawingMode, 
										 const ZcArray<int>& viewportNumbers)	= 0;
};

ZcGiTransientManager* zcgiGetTransientManager();
void zcgiSetTransientManager(ZcGiTransientManager* transientManager);

#endif	//_ZCGITRANSIENTMANAGER_H

