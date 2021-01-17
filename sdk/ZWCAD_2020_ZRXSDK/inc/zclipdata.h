
#ifndef _ZCLIPDATA_H 
#define _ZCLIPDATA_H 1

#pragma pack (push, 8)

#include "zAdAChar.h"

enum eClipInfoFlags {
    kbDragGeometry  = 0x01,
};

enum eXrefType {
    kXrefTypeAttach     = 1,
    kXrefTypeOverlay    = 2
};

enum eExpandedClipDataTypes {
    kDcPlotStyles       = 1,
    kDcXrefs            = 2,
    kDcLayouts          = 3,
    kDcBlocks           = 4,
    kDcLayers           = 5,
    kDcDrawings         = 6,
    kDcLinetypes        = 7,
    kDcTextStyles       = 8,
    kDcDimStyles        = 9,
    kDcBlocksWithAttdef = 10,

    kDcHatches          = 11,

    kTpXrefs            = 12,
    kTpImages           = 13,
    kTpTable            = 14,
	kDcTableStyles      = 15, 
	kDcMultileaderStyles = 16,
	kDcVisualStyles      = 17,
	kDcSectionViewStyles = 18,
	kDcDetailViewStyles  = 19,    
};

const int nBlockFileSize = 260;
const int nSignatureSize = 4;

typedef struct tagClipboardInfo {
    ZTCHAR        szTempFile[nBlockFileSize];
    ZTCHAR        szSourceFile[nBlockFileSize];
    ZTCHAR        szSignature[nSignatureSize];
    int         nFlags;                         
    ZcGePoint3d dptInsert;                      
    RECT        rectGDI;                        
    void*       mpView;                         
    DWORD       m_dwThreadId;                   
    int         nLen;                           
    int         nType;                          
    ZTCHAR        chData[1];
} ClipboardInfo;

#define szClipSignature ZCRX_T("R15")
#pragma pack (pop)

#endif
