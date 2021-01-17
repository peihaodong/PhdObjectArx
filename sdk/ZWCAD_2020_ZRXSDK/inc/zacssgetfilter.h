

#ifndef _ZCSSGETFILTER_H
#define _ZCSSGETFILTER_H

class ZcApDocument;

class ZcEdSelectionSetService
{
public:

    virtual Zcad::ErrorStatus ssNameX(
        bool bIsSubSelectionIndex,
    	int index,
        resbuf*& result) = 0;

    virtual Zcad::ErrorStatus ssNameSubentityX(
        bool bIsSubSelectionIndex,
        int index,
        int subentityIndex,
        resbuf*& result) = 0;

    virtual Zcad::ErrorStatus ssNameSubentities(
        bool bIsSubSelectionIndex,
        int index,
        ZcDbFullSubentPathArray& subEntities) = 0;

    virtual Zcad::ErrorStatus add(
        resbuf *ssnameXList,
        const ZcDbFullSubentPath *pPath = NULL,
        const ZcDbObjectId* pEntselSubent = NULL) = 0;

    virtual Zcad::ErrorStatus addSubentity(
        resbuf *ssnameXList,
        const ZcDbFullSubentPath& subEntity) = 0;

    virtual Zcad::ErrorStatus remove(
        int index) = 0;

    virtual Zcad::ErrorStatus removeSubentity(
        int entityIndex,
        int subEntityIndex) = 0;

    virtual Zcad::ErrorStatus highlight(
    	int subSelectionIndex,
        const ZcDbFullSubentPath& path) = 0;

	virtual int subSelectionMode() = 0;

	virtual Zcad::ErrorStatus getSubSelectionPoints(ZcGePoint3dArray& points) = 0;

	virtual Zcad::ErrorStatus add(const ZcArray<resbuf*>& ssnameXList,	const ZcArray<ZcDbFullSubentPath *> *pPath,	bool bAddsAreUnique) = 0;

	virtual Zcad::ErrorStatus addSubentities(resbuf* ssnameXList, const ZcArray<ZcDbFullSubentPath>& subEntities, bool bAddsAreUnique) = 0;

	virtual Zcad::ErrorStatus remove(const ZcArray<int>& indices) = 0;

	virtual Zcad::ErrorStatus removeSubentities(int entityIndex, const ZcArray<int>& subEntityIndices) = 0;
};

typedef ZcArray<ZcDbIntArray, ZcArrayObjectCopyReallocator<ZcDbIntArray> >
    ZcDbArrayIntArray;

class ZcEdSSGetFilter: public ZcEdInputContextReactor
{
public:

    virtual void
    ssgetAddFilter(
	    int ssgetFlags,
	    ZcEdSelectionSetService &service,
	    const ZcDbObjectIdArray& selectionSet,
	    const ZcDbObjectIdArray& subSelectionSet)
    {  }

    virtual void
    ssgetRemoveFilter(
	    int ssgetFlags,
	    ZcEdSelectionSetService &service,
	    const ZcDbObjectIdArray& selectionSet,
	    const ZcDbObjectIdArray& subSelectionSet,
        ZcDbIntArray& removeIndexes,
        ZcDbArrayIntArray& removeSubentIndexes)
    {  }

    virtual void
    ssgetAddFailed(
	    int ssgetFlags,
	    int ssgetMode,
	    ZcEdSelectionSetService &service,
	    const ZcDbObjectIdArray& selectionSet,
        resbuf *rbPoints)
    {  }

    virtual void
    ssgetRemoveFailed(
	    int ssgetFlags,
	    int ssgetMode,
	    ZcEdSelectionSetService &service,
	    const ZcDbObjectIdArray& selectionSet,
	    resbuf *rbPoints,
        ZcDbIntArray& removeIndexes,
        ZcDbArrayIntArray& removeSubentIndexes)
    {  }

    virtual void
    endSSGet(
	    Zcad::PromptStatus returnStatus,
	    int ssgetFlags,
	    ZcEdSelectionSetService &service,
	    const ZcDbObjectIdArray& selectionSet)
    {  }

    virtual void
    endEntsel(
        Zcad::PromptStatus       returnStatus,
        const ZcDbObjectId&      pickedEntity,
        const ZcGePoint3d&       pickedPoint,
        ZcEdSelectionSetService& service)
    {  }
};

Zcad::ErrorStatus addSSgetFilterInputContextReactor(
                        ZcApDocument *pDoc, ZcEdSSGetFilter *pFilter);

Zcad::ErrorStatus removeSSgetFilterInputContextReactor(
                        ZcApDocument *pDoc, ZcEdSSGetFilter *pFilter);

Zcad::ErrorStatus setAllowDuplicateSelection(
                        ZcApDocument *pDoc, ZSoft::Boolean flag);

bool              duplicateSelectionsAllowed(ZcApDocument *pDoc);

namespace ZcEdSSGet {

enum ZcEdSSGetFlags {
    kNormal         =  0,
    kPickPoints     =  1,
    kDuplicates     =  2,
    kNestedEntities =  4,
    kSubEntities    =  8,
    kSinglePick     = 16,
    kPickfirstSet   = 32,
    kPreviousSet    =  64,
    kSubSelection   = 128,
	kUndo           = 256,
	kFailedPickAuto = 512,
	kCommandPreview = 1024,
	kAllViewports   = 2048,
	kForBoxPick     = 4096,
	kPreSelectionHilite = 8192,
};

enum ZcEdSSGetModes {
    kWin = 1,   
    kCross,     
    kBox,       
    kLast,      
    kEntity,    
    kAll,       
    kFence,     
    kCPoly,     
    kWPoly,     
    kPick,      
    kEvery,     
    kXten,      
    kGroup,     
    kPrevious,
	kMultiple,
};

};

class ZcEdSSGetFilter2 : public ZcEdSSGetFilter
{
public:

    virtual void
    ssgetRolloverFilter(
        const ZcDbFullSubentPath &subEntityPath,
        ZcDbFullSubentPath &highlightPath)
    {  }
};

Zcad::ErrorStatus addSSgetFilterInputContextReactor(
                        ZcApDocument *pDoc, ZcEdSSGetFilter2 *pFilter);

Zcad::ErrorStatus removeSSgetFilterInputContextReactor(
                        ZcApDocument *pDoc, ZcEdSSGetFilter2 *pFilter);

class ZcEdSSGetFilter3 : public ZcEdSSGetFilter
{
public:

    virtual void
    ssgetRolloverFilter(
        const ZcDbFullSubentPath &subEntityPath,
        ZcDbFullSubentPathArray &highlightPaths)
    {  }
};

Zcad::ErrorStatus addSSgetFilterInputContextReactor(
    ZcApDocument *pDoc, ZcEdSSGetFilter3 *pFilter);
Zcad::ErrorStatus removeSSgetFilterInputContextReactor(
    ZcApDocument *pDoc, ZcEdSSGetFilter3 *pFilter);

class ZcEdSubSelectFilterService
{
public:

    virtual Zcad::ErrorStatus ssNameX(
        bool bIsSubSelectionIndex,
        int index,
        resbuf*& result) = 0;

    virtual Zcad::ErrorStatus add(
        resbuf *ssnameXList,
        const ZcDbFullSubentPath& path) = 0;

    virtual Zcad::ErrorStatus remove(
        bool bIsSubSelectionIndex,
        int index) = 0;
};

class ZcEdSSGetSubSelectFilter : public ZcEdInputContextReactor
{
public:

    virtual Zcad::ErrorStatus
        getSubentPathsAtGsMarker(
            ZcDbEntity*                    pEnt,
            bool                           bAdding,
            const ZcDbFullSubentPathArray& selectedPaths,
            ZcDb::SubentType               type,
            ZSoft::GsMarker                gsMark,
            const ZcGePoint3d&             pickPoint,
            const ZcGeMatrix3d&            viewXForm,
            int&                           numPaths,
            ZcDbFullSubentPath*&           subentPaths,
            int                            numInserts,
            ZcDbObjectId*                  entAndInsertStack) = 0;

    virtual Zcad::ErrorStatus
        subSelectClassList(ZcArray<ZcRxClass*>& classes) = 0;

    virtual void
        ssgetAddFilter(
            int                            ssgetFlags,
            ZcEdSubSelectFilterService&    service,
            const ZcDbObjectId&            object,
            const ZcDbFullSubentPathArray& selectedPaths,
            const ZcDbFullSubentPathArray& addedPaths) = 0;

    virtual void
        ssgetRemoveFilter(
            int                            ssgetFlags,
            ZcEdSubSelectFilterService&    service,
            const ZcDbObjectId&            object,
            const ZcDbFullSubentPathArray& selectedPaths,
            const ZcDbFullSubentPathArray& removedPaths) = 0;
};

Zcad::ErrorStatus addSSgetFilterInputContextReactor(
                        ZcApDocument             *pDoc,
                        ZcEdSSGetSubSelectFilter *pFilter);

Zcad::ErrorStatus removeSSgetFilterInputContextReactor(
                        ZcApDocument             *pDoc,
                        ZcEdSSGetSubSelectFilter *pFilter);

#endif  

