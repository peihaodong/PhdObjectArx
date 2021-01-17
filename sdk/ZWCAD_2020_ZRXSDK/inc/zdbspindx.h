

#ifndef ZD_DBSPINDX_H
#define ZD_DBSPINDX_H

#include "zdbindex.h"

#pragma pack (push, 8)

class ZcDbSpatialIndex: public ZcDbIndex
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbSpatialIndex);
	     ZcDbSpatialIndex();
    virtual ~ZcDbSpatialIndex();

    virtual ZcDbFilteredBlockIterator* newIterator(const ZcDbFilter* pFilter)
                                                   const;

    virtual Zcad::ErrorStatus rebuildFull(ZcDbIndexUpdateData* pIdxData);

protected:
    virtual Zcad::ErrorStatus rebuildModified(ZcDbBlockChangeIterator* iter);
};

class ZcDbImpSpatialIndexIterator;
class ZcDbSpatialFilter;

class ZcDbSpatialIndexIterator : public ZcDbFilteredBlockIterator
{
public:
	ZcDbSpatialIndexIterator(const ZcDbSpatialIndex*  pIndex,
                                 const ZcDbSpatialFilter* pFilter);
        virtual ~ZcDbSpatialIndexIterator();

	virtual Zcad::ErrorStatus start();
	virtual ZcDbObjectId      next();
	virtual ZcDbObjectId      id() const;
	virtual Zcad::ErrorStatus seek(ZcDbObjectId id);

        virtual double estimatedHitFraction() const;
        virtual Zcad::ErrorStatus accepts(ZcDbObjectId id,
                                    ZSoft::Boolean& stat) const;

private:
        ZcDbImpSpatialIndexIterator* mpImpIter;
};

#pragma pack (pop)

#endif 
