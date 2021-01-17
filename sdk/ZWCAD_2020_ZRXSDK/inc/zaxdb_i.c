

#pragma warning( disable: 4049 )

#ifdef __cplusplus
extern "C"{
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_ZXAUTOLib,0xEC92300C,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadObject,0xEC9230C6,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDictionary,0xEC922FDA,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadEntity,0xEC922FE0,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadBlock,0xEC9230D7,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDatabase,0xEC923099,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSectionTypeSettings,0xEC92308C,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSectionTypeSettings2,0xB51F3969,0xDB28,0x49AA,0x81,0x6A,0x41,0xF9,0xFF,0xCE,0x4F,0xFB);

MIDL_DEFINE_GUID(IID, IID_IZcadHyperlink,0xEC923112,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadHyperlink,0xEC9230B3,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDynamicBlockReferenceProperty,0xEC92310E,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDynamicBlockReferenceProperty,0xEC922FC3,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadZcCmColor,0xEC922FFB,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadZcCmColor,0xEC9231C3,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadObjectEvents,0xEC92317E,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadObject,0xEC923157,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadXRecord,0xEC92307A,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadXRecord,0xEC923032,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSortentsTable,0xEC9230B5,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSortentsTable,0xEC92308A,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDimStyle,0xEC923160,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimStyle,0xEC923085,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadLayer,0xEC9230C0,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLayer,0xEC9231D0,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadLineType,0xEC922FF1,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLineType,0xEC922FF6,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadMaterial,0xEC9230DD,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMaterial,0xEC923024,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadRegisteredApplication,0xEC92318F,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadRegisteredApplication,0xEC923107,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadTextStyle,0xEC922FF8,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadTextStyle,0xEC9231A2,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadUCS,0xEC9230AB,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadUCS,0xEC922FCB,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadView,0xEC923075,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadView,0xEC923014,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadViewport,0xEC92303D,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadViewport,0xEC9231D1,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadGroup,0xEC92319A,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadGroup,0xEC92316E,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadPlotConfiguration,0xEC9231DB,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPlotConfiguration,0xEC9231A5,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadLayout,0xEC923115,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLayout,0xEC922FF9,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadIdPair,0xEC9230D6,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadIdPair,0xEC9230BC,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadTableStyle,0xEC923133,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadTableStyle,0xEC923111,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSectionSettings,0xEC9230B0,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSectionSettings,0xEC923094,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSectionTypeSettings,0xEC923027,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadMLeaderStyle,0xEC923040,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMLeaderStyle,0xEC923148,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadHyperlinks,0xEC9231DD,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadHyperlinks,0xEC923046,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDictionary,0xEC9230BF,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadLayers,0xEC923043,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLayers,0xEC9230B8,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDimStyles,0xEC9230AF,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimStyles,0xEC923002,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDictionaries,0xEC92309D,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDictionaries,0xEC923015,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadLineTypes,0xEC923098,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLineTypes,0xEC922FE5,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadMaterials,0xEC9230AC,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMaterials,0xEC92310B,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadTextStyles,0xEC923131,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadTextStyles,0xEC9230C5,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadUCSs,0xEC9230EC,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadUCSs,0xEC9231CD,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadRegisteredApplications,0xEC9231AE,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadRegisteredApplications,0xEC923188,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadViews,0xEC92318D,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadViews,0xEC9230A8,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadViewports,0xEC923149,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadViewports,0xEC922FCD,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadGroups,0xEC92316B,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadGroups,0xEC9231D7,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadBlocks,0xEC923166,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadBlocks,0xEC9231B1,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadLayouts,0xEC92312D,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLayouts,0xEC923079,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadPlotConfigurations,0xEC9231BD,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPlotConfigurations,0xEC923069,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadEntity,0xEC92304D,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadShadowDisplay,0xEC923137,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadRasterImage,0xEC923005,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadRasterImage,0xEC923047,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcad3DFace,0xEC9231DC,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_Zcad3DFace,0xEC9231B4,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcad3DPolyline,0xEC923081,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_Zcad3DPolyline,0xEC92304C,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadRegion,0xEC9231E9,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadRegion,0xEC9231E7,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcad3DSolid,0xEC92309B,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_Zcad3DSolid,0xEC923173,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadArc,0xEC923095,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadArc,0xEC9230B1,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadAttribute,0xEC923192,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadAttribute,0xEC923182,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadAttributeReference,0xEC92304E,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadAttributeReference,0xEC9231A3,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadBlockReference,0xEC9230D5,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadBlockReference,0xEC92315A,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadCircle,0xEC923048,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadCircle,0xEC92303A,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadEllipse,0xEC9230CA,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadEllipse,0xEC9231C5,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadHatch,0xEC92319B,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadHatch,0xEC923120,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadLeader,0xEC92308B,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLeader,0xEC922FD3,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

//MIDL_DEFINE_GUID(IID, IID_IZcadSubEntity,0xEC923058,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

//MIDL_DEFINE_GUID(IID, IID_IZcadMLeaderLeader,0x408BA371,0xAD97,0x47EE,0xB9,0x10,0xD3,0x66,0x00,0xEC,0xFC,0x59);

//MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMLeaderLeader,0xF3146902,0x1BAB,0x49C0,0x8A,0x51,0x9E,0x8B,0xA4,0xB7,0xE5,0x2C);

MIDL_DEFINE_GUID(IID, IID_IZcadMLeader,0xEC922FC2,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMLeader,0xEC923004,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadLWPolyline,0xEC92311E,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLWPolyline,0xEC92307B,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadLine,0xEC9230FB,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLine,0xEC923177,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadMText,0xEC922FE1,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMText,0xEC92302D,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadPoint,0xEC92315D,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPoint,0xEC92314D,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadPolyline,0xEC9230F2,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPolyline,0xEC92305E,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadPolygonMesh,0xEC923073,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPolygonMesh,0xEC923017,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadRay,0xEC92300F,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadRay,0xEC9231F2,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadShape,0xEC92301C,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadShape,0xEC92304F,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSolid,0xEC9230E8,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSolid,0xEC92312B,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSpline,0xEC92319E,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSpline,0xEC923158,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadText,0xEC9230C3,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadText,0xEC923067,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadTolerance,0xEC923101,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadTolerance,0xEC9230D2,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadTrace,0xEC9231B0,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadTrace,0xEC923159,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadXline,0xEC923055,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadXline,0xEC9231CE,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadPViewport,0xEC923139,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPViewport,0xEC923088,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadMInsertBlock,0xEC922FC1,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMInsertBlock,0xEC9230F1,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadPolyfaceMesh,0xEC923114,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPolyfaceMesh,0xEC9231F8,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadMLine,0xEC9231D9,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadMLine,0xEC9230C1,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadExternalReference,0xEC923029,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadExternalReference,0xEC923009,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadTable,0xEC9231D2,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadTable,0xEC923019,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadOle,0xEC923045,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadOle,0xEC92311B,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadHelix,0xEC923142,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadHelix,0xEC923012,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSurface,0xEC9231DF,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSurface,0xEC92305A,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadPlaneSurface,0xEC9230A4,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPlaneSurface,0xEC923036,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadExtrudedSurface,0xEC923285,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadExtrudedSurface,0xEC923284,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadRevolvedSurface,0xEC9231B7,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadRevolvedSurface,0xEC922FE4,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSweptSurface,0xEC92304B,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSweptSurface,0xEC923060,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadLoftedSurface,0x6AF68CD2,0x4810,0x4795,0x9B,0xA7,0x52,0x7E,0x74,0x2D,0xB9,0xA6);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLoftedSurface,0x12973215,0xFD58,0x4538,0xB5,0x0E,0xA2,0x83,0x58,0xC3,0x17,0x38);

MIDL_DEFINE_GUID(IID, IID_IZcadSection,0xEC9231D6,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSection,0xEC92302B,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSectionManager,0xEC923035,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSectionManager,0xEC9230EB,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadUnderlay,0xEC9230F8,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

//MIDL_DEFINE_GUID(IID, IID_IZcadDwfUnderlay,0xEC92319C,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDwfUnderlay,0xEC92312A,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDgnUnderlay,0xF779D165,0x9A0A,0x4482,0xB1,0x8D,0xF9,0x40,0x59,0xE3,0xCB,0x4A);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPdfUnderlay,0xEC92327C,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSubEntity,0xEC9231A7,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSubEntSolidFace,0xB2B924B8,0xC431,0x4BD7,0x88,0x51,0x4C,0xB5,0x61,0x5A,0xD5,0x7F);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSubEntSolidFace,0x605545E6,0x33F8,0x47E0,0x8B,0xEA,0x89,0x40,0x8A,0x7C,0x58,0xF5);

MIDL_DEFINE_GUID(IID, IID_IZcadSubEntSolidEdge,0xEC923136,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSubEntSolidEdge,0xEC923191,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSubEntSolidVertex,0xEC922FEF,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSubEntSolidVertex,0xEC9230E1,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSubEntSolidNode,0x8153157B,0xC750,0x4788,0xA3,0x3D,0x96,0xAD,0xE0,0x37,0xF8,0x7F);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSubEntSolidNode,0xC87E3A37,0xF999,0x432D,0xA7,0x1A,0x31,0xE5,0x01,0xFE,0xD5,0x2B);


MIDL_DEFINE_GUID(IID, IID_IZcadSubDMesh,0xEC923287,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSubDMesh,0xEC923286,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(IID, IID_IZcadDimension,0xEC9230DF,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimension,0xEC9230F7,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDimAligned,0xEC923189,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimAligned,0xEC923118,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDimAngular,0xEC923152,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimAngular,0xEC92306D,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDimDiametric,0xEC9231B6,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimDiametric,0xEC9231E5,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDimOrdinate,0xEC923030,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimOrdinate,0xEC92313B,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDimRadial,0xEC923119,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimRadial,0xEC922FEA,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDimRotated,0xEC922FDE,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimRotated,0xEC923179,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDim3PointAngular,0xEC923174,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDim3PointAngular,0xEC923072,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDimArcLength,0xEC923167,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimArcLength,0xEC92301D,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDimRadialLarge,0xEC922FE2,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDimRadialLarge,0xEC923110,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadBlock,0xEC923016,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadModelSpace,0xEC9231E6,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadModelSpace,0xEC9231A1,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadPaperSpace,0xEC9230E3,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadPaperSpace,0xEC9231E4,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadFileDependency,0xEC923096,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadFileDependency,0xEC9231C4,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadFileDependencies,0xEC92302A,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadFileDependencies,0xEC92315B,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSummaryInfo,0xEC922FF0,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSummaryInfo,0xEC9230E6,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadDatabasePreferences,0xEC923099,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDatabasePreferences,0xEC9231F0,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadDatabase,0xEC92317A,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadSecurityParams,0xEC923193,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadSecurityParams,0xEC922FF4,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZcadLayerStateManager,0xEC9230F6,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(CLSID, CLSID_ZcadLayerStateManager,0xEC92312F,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

MIDL_DEFINE_GUID(IID, IID_IZxDbDocumentEvents,0x49C74794,0x57FD,0x4CAF,0xB7,0xC6,0xCC,0x4F,0x33,0x34,0xC7,0x21);

MIDL_DEFINE_GUID(IID, IID_IZxDbDocument,0x30FDAC07,0x01CB,0x4245,0x9A,0x81,0x6E,0xAE,0x0E,0x8D,0x49,0x8E);

MIDL_DEFINE_GUID(CLSID, CLSID_ZxDbDocument,0x6EAC27C5,0x6411,0x46E5,0x82,0xDE,0x94,0x18,0xE5,0x91,0xAF,0x7D);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif


