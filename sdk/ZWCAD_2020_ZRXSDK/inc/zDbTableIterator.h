

#pragma once

struct ZcCell;
struct ZcCellRange;
class ZcDbTable;
class ZcDbLinkedTableData;

class ZcDbTableIterator
{
public:
    ZcDbTableIterator(const ZcDbTable* pTable);
    ZcDbTableIterator(const ZcDbTable* pTable, const ZcCellRange* pRange,
        ZcDb::TableIteratorOption nOption);
    ZcDbTableIterator(const ZcDbLinkedTableData* pTable);
    ZcDbTableIterator(const ZcDbLinkedTableData* pTable, const ZcCellRange* pRange,
        ZcDb::TableIteratorOption nOption);
    ZcDbTableIterator(const ZcCellRange& range);
    ZcDbTableIterator(const ZcCellRange& range, ZcDb::TableIteratorOption nOption);
    ~ZcDbTableIterator();

    void            start                   (void);
    void            step                    (void);
    bool            done                    (void);
    bool            seek                    (const ZcCell& cell);
    const ZcCell&   getCell                 (void) const;
    int             getRow                  (void) const;
    int             getColumn               (void) const;

protected:
    ZcDbTableIterator(void);

protected:
    void        *   mpImpObj;
};
