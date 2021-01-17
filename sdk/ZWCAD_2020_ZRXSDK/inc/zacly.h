

#ifndef _ZC_LY_H
#define _ZC_LY_H

#include "zAdAChar.h"
#include "zacadstrc.h"
#include "zacarray.h"
#include "zdbsymtb.h"
#include "zdbxrecrd.h"

class ZcLySystemInternals;
class ZcLyRelExpr 
{
public:
	virtual ~ZcLyRelExpr(){}
    virtual const ZTCHAR * getVariable() const = 0;
    virtual const ZTCHAR * getConstant() const = 0;
};

class ZcLyAndExpr 
{
public:
    virtual ~ZcLyAndExpr() { }
    virtual const ZcArray<ZcLyRelExpr*>& getRelExprs() const = 0;
};

class ZcLyBoolExpr 
{
public:
    virtual ~ZcLyBoolExpr() { }
    virtual const ZcArray<ZcLyAndExpr*>& getAndExprs() const = 0;
};

#ifndef HIMAGELIST
struct _IMAGELIST;
typedef struct _IMAGELIST* HIMAGELIST;
#endif

class ZcLyLayerFilter : public ZcRxObject, public ZcHeapOperators
{
public:
    ZCRX_DECLARE_MEMBERS(ZcLyLayerFilter);
    ZcLyLayerFilter ();
    virtual ~ZcLyLayerFilter ();

    virtual const ZTCHAR * name() const;
    virtual Zcad::ErrorStatus setName(const ZTCHAR *);
    virtual bool allowRename() const;

    virtual Zcad::ErrorStatus getImages(HIMAGELIST& imageList, ZSoft::UInt32& normalImage, ZSoft::UInt32& selected) const;

    virtual ZcLyLayerFilter* parent() const;

    virtual const ZcArray<ZcLyLayerFilter*>& getNestedFilters() const;
    virtual Zcad::ErrorStatus addNested(ZcLyLayerFilter* filter);
    virtual Zcad::ErrorStatus removeNested(ZcLyLayerFilter* filter);

    virtual Zcad::ErrorStatus generateNested();

    virtual bool dynamicallyGenerated() const;

    virtual bool allowNested() const;

    virtual bool allowDelete() const;

    virtual bool isProxy() const;

    virtual bool isIdFilter() const;

    virtual bool filter(ZcDbLayerTableRecord* layer) const;

    enum DialogResult {kOk = 0, kCancel=1, kUseDefault = 2};
    virtual  DialogResult showEditor();

    virtual const ZTCHAR * filterExpression() const;
    virtual Zcad::ErrorStatus setFilterExpression(const ZTCHAR * expr);

    virtual const ZcLyBoolExpr* filterExpressionTree() const;

    virtual bool compareTo(const ZcLyLayerFilter* pOther) const;

    virtual Zcad::ErrorStatus readFrom(ZcDbDxfFiler* filer);
    virtual Zcad::ErrorStatus writeTo(ZcDbDxfFiler* pFiler) const;

private:
    void *mp_impObj;
    friend class ZcLySystemInternals;

protected:
    ZcLyLayerFilter(ZcLySystemInternals*);
};

class ZcLyLayerGroup : public ZcLyLayerFilter
{
public:
    ZCRX_DECLARE_MEMBERS(ZcLyLayerGroup);
    ZcLyLayerGroup();

    virtual Zcad::ErrorStatus        addLayerId    (const ZcDbObjectId& id);
    virtual Zcad::ErrorStatus        removeLayerId (const ZcDbObjectId& id);
    virtual const ZcDbObjectIdArray& layerIds      () const;

protected:
    ZcLyLayerGroup(ZcLySystemInternals*);
};

class ZcLyLayerFilterManager
{
public:
	virtual ~ZcLyLayerFilterManager(){}
    virtual Zcad::ErrorStatus getFilters(ZcLyLayerFilter*& pRoot, ZcLyLayerFilter*& pCurrent) = 0;

    virtual Zcad::ErrorStatus setFilters( const ZcLyLayerFilter* pRoot, const ZcLyLayerFilter* pCurrent) = 0;
};

ZcLyLayerFilterManager* zclyGetLayerFilterManager(ZcDbDatabase* pDb);

#endif  
