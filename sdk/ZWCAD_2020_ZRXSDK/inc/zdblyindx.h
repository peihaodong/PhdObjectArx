

#ifndef ZD_DBLYINDX_H
#define ZD_DBLYINDX_H

#include "zdbindex.h"

#pragma pack (push, 8)

class ZcDbLayerIndex: public ZcDbIndex
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLayerIndex);
	     ZcDbLayerIndex();
    virtual ~ZcDbLayerIndex();
    virtual ZcDbFilteredBlockIterator* newIterator(const ZcDbFilter* pFilter)
                                                   const;

    virtual Zcad::ErrorStatus rebuildFull(ZcDbIndexUpdateData* pIdxData);

    Zcad::ErrorStatus compute(ZcDbLayerTable*       pLT,
                              ZcDbBlockTableRecord* pBTR);

protected:
    virtual Zcad::ErrorStatus rebuildModified(ZcDbBlockChangeIterator* iter);
};

class ZcDbImpLayerIndexIterator;
class ZcDbLayerFilter;

class ZcDbLayerIndexIterator : public ZcDbFilteredBlockIterator
{
public:
    ZcDbLayerIndexIterator(const ZcDbLayerIndex*  pIndex,
                           const ZcDbLayerFilter* pFilter);
    virtual ~ZcDbLayerIndexIterator();

    virtual Zcad::ErrorStatus start();
    virtual ZcDbObjectId      next();
    virtual ZcDbObjectId      id() const;
    virtual Zcad::ErrorStatus seek(ZcDbObjectId id);

    virtual double estimatedHitFraction() const;
    virtual Zcad::ErrorStatus accepts(ZcDbObjectId id, 
                      ZSoft::Boolean& idPassesFilter) const;

private:
        ZcDbImpLayerIndexIterator* mpImpIter;
};

#pragma pack (pop)

#endif 
