

#ifndef ZD_DBPROXY_H
#define ZD_DBPROXY_H 1

#include "zdbmain.h"
#include "zdbintar.h"

#pragma pack (push, 8)

class ZSOFT_NO_VTABLE ZcDbProxyObject : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbProxyObject);
    
    virtual ~ZcDbProxyObject() {};
    
    virtual int   proxyFlags() const = 0;
    virtual const ZTCHAR * originalClassName() const = 0;
    virtual const ZTCHAR * originalDxfName() const = 0;
    virtual const ZTCHAR * applicationDescription() const = 0;
    virtual Zcad::ErrorStatus getReferences(ZcDbObjectIdArray&,
        ZcDbIntArray&) const = 0;

    virtual ZcDb::DuplicateRecordCloning mergeStyle() const = 0;

    enum {kNoOperation          = 0,
          kEraseAllowed         = 0x01,
          kCloningAllowed       = 0x80,
          kAllButCloningAllowed = 0x01,
          kAllAllowedBits       = 0x81,
          kMergeIgnore          = 0,      
          kMergeReplace         = 0x100,  
          kMergeMangleName      = 0x200,  
          kDisableProxyWarning  = 0x400
           };
};

class ZSOFT_NO_VTABLE ZcDbProxyEntity : public ZcDbEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbProxyEntity);
    
    virtual ~ZcDbProxyEntity() {};
    
    virtual int   proxyFlags() const = 0;
    virtual const ZTCHAR * originalClassName() const = 0;
    virtual const ZTCHAR * originalDxfName() const = 0;
    virtual const ZTCHAR * applicationDescription() const = 0;
    virtual Zcad::ErrorStatus getReferences(ZcDbObjectIdArray&,
        ZcDbIntArray&) const = 0;

    enum GraphicsMetafileType {
        kNoMetafile   = 0,
        kBoundingBox  = 1,
        kFullGraphics = 2 };

    virtual ZcDbProxyEntity::GraphicsMetafileType graphicsMetafileType()
        const = 0;

    virtual Zcad::ErrorStatus   explode(ZcDbVoidPtrArray& entitySet) const;
    virtual Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform);
    virtual Zcad::ErrorStatus   getGeomExtents(ZcDbExtents& extents) const;

    enum  {kNoOperation                = 0,
           kEraseAllowed               = 0x1,
           kTransformAllowed           = 0x2,
           kColorChangeAllowed         = 0x4,
           kLayerChangeAllowed         = 0x8,
           kLinetypeChangeAllowed      = 0x10,
           kLinetypeScaleChangeAllowed = 0x20,
           kVisibilityChangeAllowed    = 0x40,
           kCloningAllowed             = 0x80,
           kLineWeightChangeAllowed    = 0x100,
           kPlotStyleNameChangeAllowed = 0x200,
           kAllButCloningAllowed       = 0x37F,
           kAllAllowedBits             = 0xBFF,
           kDisableProxyWarning        = 0x400,
           kMaterialChangeAllowed      = 0x800,
            };
};

#pragma pack (pop)

#endif 
