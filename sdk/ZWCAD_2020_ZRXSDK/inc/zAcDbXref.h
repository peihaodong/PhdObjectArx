

#pragma once

#include "zAdAChar.h"
#include "zxgraph.h"

Zcad::ErrorStatus zcdbResolveCurrentXRefs(ZcDbDatabase* pHostDb,
    bool useThreadEngine = true, bool doNewOnly = false);

Zcad::ErrorStatus zcdbAttachXref(ZcDbDatabase* pHostDb,
                                 const ZTCHAR * pFilename,
                                 const ZTCHAR * pBlockName,
                                 ZcDbObjectId& xrefBlkId);
Zcad::ErrorStatus zcdbOverlayXref(ZcDbDatabase* pHostDb,
                                  const ZTCHAR * pFilename,
                                  const ZTCHAR * pBlockName,
                                  ZcDbObjectId& xrefBlkId);
Zcad::ErrorStatus zcdbDetachXref(ZcDbDatabase* pHostDb,
                           const ZcDbObjectId& xrefBlkId);
Zcad::ErrorStatus zcdbUnloadXrefs(ZcDbDatabase*      pHostDb,
                            const ZcDbObjectIdArray& xrefBlkIds,
                            const bool               bQuiet = true);

Zcad::ErrorStatus zcdbReloadXrefs(ZcDbDatabase*      pHostDb,
                            const ZcDbObjectIdArray& xrefBlkIds,
                                  bool               bQuiet = true);

Zcad::ErrorStatus zcdbBindXrefs(ZcDbDatabase*      pHostDb,
                          const ZcDbObjectIdArray& xrefBlkIds,
                          const bool               bInsertBind,
                          const bool               bAllowUnresolved = false,
                          const bool               bQuiet = true);

Zcad::ErrorStatus zcdbXBindXrefs(ZcDbDatabase*     pHostDb,
                           const ZcDbObjectIdArray xrefSymbolIds,
                           const bool              bInsertBind,
                           const bool              bQuiet = true);
void zcdbReleaseHostDwg(ZcDbDatabase* pHostDb);

Zcad::ErrorStatus
zcdbGetHostDwgXrefGraph(ZcDbDatabase* pHostDb, ZcDbXrefGraph& graph,
    ZSoft::Boolean includeGhosts = ZSoft::kFalse);

class ZcDbXrefObjectId {
public:

    ZcDbXrefObjectId();
    ZcDbXrefObjectId(const ZcDbXrefObjectId& other);

    ZcDbXrefObjectId& operator= (const ZcDbXrefObjectId& other);
    bool operator== (const ZcDbXrefObjectId& other) const;
    bool operator!= (const ZcDbXrefObjectId& other) const;

    bool isValid(void) const;
    bool isXref(void) const { return !m_handle.isNull(); }
    bool isNull(void) const { return m_localId.isNull(); }

    Zcad::ErrorStatus setNull(void);

    Zcad::ErrorStatus setXrefId(ZcDbObjectId xrefBlkId, const ZcDbHandle & hObject);
    Zcad::ErrorStatus getXrefId(ZcDbObjectId& xrefBlkId, ZcDbHandle& hObject) const;

    Zcad::ErrorStatus setLocalId(ZcDbObjectId objId);
    Zcad::ErrorStatus getLocalId(ZcDbObjectId& objId) const;

    Zcad::ErrorStatus resolveObjectId(ZcDbObjectId& id) const;

    Zcad::ErrorStatus serializeToResbuf(resbuf*& pResBuf, resbuf*& pEndOfChain) const;
    Zcad::ErrorStatus serializeFromResbuf(const resbuf* pResBuf, resbuf*& pNextInChain);

private:

    ZcDbObjectId        m_localId;
    ZcDbHandle          m_handle;
                                        
};

