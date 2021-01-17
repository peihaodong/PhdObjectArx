

#ifndef ZD_DBCFILERS_H
#define ZD_DBCFILERS_H 1

#include "zdbfiler.h"
#pragma pack (push, 8)

class ZcDbWblockCloneFiler;
class ZcDbImpDeepCloneFiler;

class ZcDbDeepCloneFiler: public ZcDbDwgFiler
{
    friend class ZcDbSystemInternals;
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDeepCloneFiler);
    ZcDbDeepCloneFiler();
    virtual ~ZcDbDeepCloneFiler();

    virtual Zcad::ErrorStatus filerStatus() const;
    virtual ZcDb::FilerType   filerType() const;
    virtual void              setFilerStatus(Zcad::ErrorStatus);
    virtual void              resetFilerStatus();

    virtual Zcad::ErrorStatus readHardOwnershipId(ZcDbHardOwnershipId*);
    virtual Zcad::ErrorStatus writeHardOwnershipId(const ZcDbHardOwnershipId&);

    virtual Zcad::ErrorStatus readSoftOwnershipId(ZcDbSoftOwnershipId*);
    virtual Zcad::ErrorStatus writeSoftOwnershipId(const ZcDbSoftOwnershipId&);

    virtual Zcad::ErrorStatus readHardPointerId(ZcDbHardPointerId*);
    virtual Zcad::ErrorStatus writeHardPointerId(const ZcDbHardPointerId&);

    virtual Zcad::ErrorStatus readSoftPointerId(ZcDbSoftPointerId*);
    virtual Zcad::ErrorStatus writeSoftPointerId(const ZcDbSoftPointerId&);

	virtual Zcad::ErrorStatus readInt8(ZSoft::Int8 *);
	virtual Zcad::ErrorStatus writeInt8(ZSoft::Int8 );

    virtual Zcad::ErrorStatus readString(ZTCHAR **);
    virtual Zcad::ErrorStatus writeString(const ZTCHAR *);

	virtual Zcad::ErrorStatus readString(ZcString &);
	virtual Zcad::ErrorStatus writeString(const ZcString &);

    virtual Zcad::ErrorStatus readBChunk(zds_binary*);
    virtual Zcad::ErrorStatus writeBChunk(const zds_binary&);

    virtual Zcad::ErrorStatus readZcDbHandle(ZcDbHandle*);
    virtual Zcad::ErrorStatus writeZcDbHandle(const ZcDbHandle&);

	virtual Zcad::ErrorStatus readInt64(ZSoft::Int64*);
	virtual Zcad::ErrorStatus writeInt64(ZSoft::Int64);

    virtual Zcad::ErrorStatus readInt32(ZSoft::Int32*);
    virtual Zcad::ErrorStatus writeInt32(ZSoft::Int32);

    virtual Zcad::ErrorStatus readInt16(ZSoft::Int16*);
    virtual Zcad::ErrorStatus writeInt16(ZSoft::Int16);

	virtual Zcad::ErrorStatus readUInt64(ZSoft::UInt64*);
	virtual Zcad::ErrorStatus writeUInt64(ZSoft::UInt64);

    virtual Zcad::ErrorStatus readUInt32(ZSoft::UInt32*);
    virtual Zcad::ErrorStatus writeUInt32(ZSoft::UInt32);

    virtual Zcad::ErrorStatus readUInt16(ZSoft::UInt16*);
    virtual Zcad::ErrorStatus writeUInt16(ZSoft::UInt16);

    virtual Zcad::ErrorStatus readUInt8(ZSoft::UInt8*);
    virtual Zcad::ErrorStatus writeUInt8(ZSoft::UInt8);

    virtual Zcad::ErrorStatus readBoolean(ZSoft::Boolean*);
    virtual Zcad::ErrorStatus writeBoolean(ZSoft::Boolean);

    virtual Zcad::ErrorStatus readBool(bool*);
    virtual Zcad::ErrorStatus writeBool(bool);

    virtual Zcad::ErrorStatus readDouble(double*);
    virtual Zcad::ErrorStatus writeDouble(double);

    virtual Zcad::ErrorStatus readPoint2d(ZcGePoint2d*);
    virtual Zcad::ErrorStatus writePoint2d(const ZcGePoint2d&);

    virtual Zcad::ErrorStatus readPoint3d(ZcGePoint3d*);
    virtual Zcad::ErrorStatus writePoint3d(const ZcGePoint3d&);

    virtual Zcad::ErrorStatus readVector2d(ZcGeVector2d*);
    virtual Zcad::ErrorStatus writeVector2d(const ZcGeVector2d&);

    virtual Zcad::ErrorStatus readVector3d(ZcGeVector3d*);
    virtual Zcad::ErrorStatus writeVector3d(const ZcGeVector3d&);

    virtual Zcad::ErrorStatus readScale3d(ZcGeScale3d*);
    virtual Zcad::ErrorStatus writeScale3d(const ZcGeScale3d&);

    virtual Zcad::ErrorStatus readBytes(void*, ZSoft::UIntPtr);
    virtual Zcad::ErrorStatus writeBytes(const void*, ZSoft::UIntPtr);

    virtual Zcad::ErrorStatus readAddress(void **);
    virtual Zcad::ErrorStatus writeAddress(const void *);

    virtual Zcad::ErrorStatus seek(ZSoft::Int64 offset, int method);
    virtual ZSoft::Int64      tell() const;

    virtual Zcad::ErrorStatus addReferences(ZcDbIdRefQueue&);
    virtual              bool usesReferences() const;
    virtual ZcDbFilerController& controller() const;

    virtual bool              getNextOwnedObject(ZcDbObjectId& id);
    virtual bool              moreOwnedObjects() const;

protected:
    ZcDbDeepCloneFiler(ZcDbSystemInternals*);
private:
    ZcDbImpDeepCloneFiler*      mpImpFiler;
};

class ZcDbWblockCloneFiler: public  ZcDbDeepCloneFiler
{
    friend class ZcDbSystemInternals;
public:
    ZCRX_DECLARE_MEMBERS(ZcDbWblockCloneFiler);

    ZcDbWblockCloneFiler();

    virtual Zcad::ErrorStatus addReferences(ZcDbIdRefQueue&);
    virtual              bool usesReferences() const;

    virtual bool              getNextHardObject(ZcDbObjectId& id);
    virtual bool              moreHardObjects() const;

    virtual ZcDb::FilerType   filerType() const;
};

#pragma pack (pop)
#endif
