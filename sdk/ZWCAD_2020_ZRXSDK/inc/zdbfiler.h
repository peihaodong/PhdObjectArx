

#ifndef ZD_DBFILER_H
#define ZD_DBFILER_H

#include <stdarg.h>
#include "zAdAChar.h"
#include "zacdb.h"
#include "zgepnt2d.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"
#include "zgescl3d.h"
#include "zadsdef.h"
#pragma pack (push, 8)

class ZcDbAuditInfo;
class ZcDbFilerController;
class ZcDbHandle;
class ZcDbIdRefQueue;
class ZcString;

class ZSOFT_NO_VTABLE ZcDbDwgFiler: public ZcRxObject
{
  public:
    ZCRX_DECLARE_MEMBERS(ZcDbDwgFiler);
    ZcDbDwgFiler();
    virtual ~ZcDbDwgFiler();

    virtual  Zcad::ErrorStatus filerStatus() const = 0;
    virtual  ZcDb::FilerType   filerType() const = 0;
    virtual void               setFilerStatus(Zcad::ErrorStatus) = 0;
    virtual void               resetFilerStatus() = 0;

    virtual  Zcad::ErrorStatus  dwgVersion(ZcDb::ZcDbDwgVersion &,
                                ZcDb::MaintenanceReleaseVersion &) const;

    virtual Zcad::ErrorStatus   readHardOwnershipId(ZcDbHardOwnershipId*) = 0;
    virtual Zcad::ErrorStatus   writeHardOwnershipId(
                                  const ZcDbHardOwnershipId&) = 0;

    virtual Zcad::ErrorStatus   readSoftOwnershipId(ZcDbSoftOwnershipId*) = 0;
    virtual Zcad::ErrorStatus   writeSoftOwnershipId(
                                  const ZcDbSoftOwnershipId&) = 0;

    virtual Zcad::ErrorStatus   readHardPointerId(ZcDbHardPointerId*) = 0;
    virtual Zcad::ErrorStatus   writeHardPointerId(const ZcDbHardPointerId&) = 0;

    virtual Zcad::ErrorStatus   readSoftPointerId(ZcDbSoftPointerId*) = 0;
    virtual Zcad::ErrorStatus   writeSoftPointerId(const ZcDbSoftPointerId&) = 0;

    virtual Zcad::ErrorStatus   readInt8(ZSoft::Int8 *) = 0;
    virtual Zcad::ErrorStatus   writeInt8(ZSoft::Int8 ) = 0;

    inline  Zcad::ErrorStatus   readChar(ZSoft::Int8 *p) {
                                        return this->readInt8(p); }
    inline  Zcad::ErrorStatus   writeChar(ZSoft::Int8 c) {
                                        return this->writeInt8(c); }

    virtual Zcad::ErrorStatus   readString(ZTCHAR**) = 0;
    virtual Zcad::ErrorStatus   writeString(const ZTCHAR*) = 0;

    virtual Zcad::ErrorStatus   readString(ZcString &) = 0;
    virtual Zcad::ErrorStatus   writeString(const ZcString &) = 0;

    virtual Zcad::ErrorStatus   readBChunk(zds_binary *) = 0;
    virtual Zcad::ErrorStatus   writeBChunk(const zds_binary&) = 0;

    virtual Zcad::ErrorStatus   readZcDbHandle(ZcDbHandle*) = 0;
    virtual Zcad::ErrorStatus   writeZcDbHandle(const ZcDbHandle&) = 0;

    virtual Zcad::ErrorStatus   readInt64(ZSoft::Int64*) = 0;
    virtual Zcad::ErrorStatus   writeInt64(ZSoft::Int64) = 0;

    virtual Zcad::ErrorStatus   readInt32(ZSoft::Int32*) = 0;
    virtual Zcad::ErrorStatus   writeInt32(ZSoft::Int32) = 0;

    virtual Zcad::ErrorStatus   readInt16(ZSoft::Int16*) = 0;
    virtual Zcad::ErrorStatus   writeInt16(ZSoft::Int16) = 0;

    virtual Zcad::ErrorStatus   readUInt64(ZSoft::UInt64*) = 0;
    virtual Zcad::ErrorStatus   writeUInt64(ZSoft::UInt64) = 0;

    virtual Zcad::ErrorStatus   readUInt32(ZSoft::UInt32*) = 0;
    virtual Zcad::ErrorStatus   writeUInt32(ZSoft::UInt32) = 0;

    virtual Zcad::ErrorStatus   readUInt16(ZSoft::UInt16*) = 0;
    virtual Zcad::ErrorStatus   writeUInt16(ZSoft::UInt16) = 0;

    virtual Zcad::ErrorStatus   readUInt8(ZSoft::UInt8*) = 0;
    virtual Zcad::ErrorStatus   writeUInt8(ZSoft::UInt8) = 0;

    virtual Zcad::ErrorStatus   readBoolean(ZSoft::Boolean*) = 0;
    virtual Zcad::ErrorStatus   writeBoolean(ZSoft::Boolean) = 0;

    virtual Zcad::ErrorStatus   readBool(bool*) = 0;
    virtual Zcad::ErrorStatus   writeBool(bool) = 0;

    virtual Zcad::ErrorStatus   readDouble(double*) = 0;
    virtual Zcad::ErrorStatus   writeDouble(double) = 0;

    virtual Zcad::ErrorStatus   readPoint2d(ZcGePoint2d*) = 0;
    virtual Zcad::ErrorStatus   writePoint2d(const ZcGePoint2d&) = 0;

    virtual Zcad::ErrorStatus   readPoint3d(ZcGePoint3d*) = 0;
    virtual Zcad::ErrorStatus   writePoint3d(const ZcGePoint3d&) = 0;

    virtual Zcad::ErrorStatus   readVector2d(ZcGeVector2d*) = 0;
    virtual Zcad::ErrorStatus   writeVector2d(const ZcGeVector2d&) = 0;

    virtual Zcad::ErrorStatus   readVector3d(ZcGeVector3d*) = 0;
    virtual Zcad::ErrorStatus   writeVector3d(const ZcGeVector3d&) = 0;

    virtual Zcad::ErrorStatus   readScale3d(ZcGeScale3d*) = 0;
    virtual Zcad::ErrorStatus   writeScale3d(const ZcGeScale3d&) = 0;

    virtual Zcad::ErrorStatus   readBytes(void *, ZSoft::UIntPtr) = 0;
    virtual Zcad::ErrorStatus   writeBytes(const void *, ZSoft::UIntPtr) = 0;

    virtual Zcad::ErrorStatus   readAddress(void **);
    virtual Zcad::ErrorStatus   writeAddress(const void *);

            Zcad::ErrorStatus   readItem(ZcDbHardOwnershipId*);
            Zcad::ErrorStatus   writeItem(const ZcDbHardOwnershipId&);

            Zcad::ErrorStatus   readItem(ZcDbSoftOwnershipId*);
            Zcad::ErrorStatus   writeItem(const ZcDbSoftOwnershipId&);

            Zcad::ErrorStatus   readItem(ZcDbHardPointerId*);
            Zcad::ErrorStatus   writeItem(const ZcDbHardPointerId&);

            Zcad::ErrorStatus   readItem(ZcDbSoftPointerId*);
            Zcad::ErrorStatus   writeItem(const ZcDbSoftPointerId&);


            Zcad::ErrorStatus   readItem(ZTCHAR**);
            Zcad::ErrorStatus   writeItem(const ZTCHAR*);

            Zcad::ErrorStatus   readItem(zds_binary*);
            Zcad::ErrorStatus   writeItem(const zds_binary&);

            Zcad::ErrorStatus   readItem(ZcDbHandle*);
            Zcad::ErrorStatus   writeItem(const ZcDbHandle&);

            Zcad::ErrorStatus   readItem(ZSoft::Int32*);
            Zcad::ErrorStatus   writeItem(ZSoft::Int32);

            Zcad::ErrorStatus   readItem(ZSoft::Int16*);
            Zcad::ErrorStatus   writeItem(ZSoft::Int16);

            Zcad::ErrorStatus   readItem(ZSoft::Int8 *);
            Zcad::ErrorStatus   writeItem(ZSoft::Int8);

            Zcad::ErrorStatus   readItem(ZSoft::UInt32*);
            Zcad::ErrorStatus   writeItem(ZSoft::UInt32);

            Zcad::ErrorStatus   readItem(ZSoft::UInt16*);
            Zcad::ErrorStatus   writeItem(ZSoft::UInt16);

            Zcad::ErrorStatus   readItem(ZSoft::UInt8*);
            Zcad::ErrorStatus   writeItem(ZSoft::UInt8);

            Zcad::ErrorStatus   readItem(ZSoft::Boolean*);
            Zcad::ErrorStatus   writeItem(ZSoft::Boolean);

#if !defined(ZSoft_Boolean_is_bool) 
            Zcad::ErrorStatus   readItem(bool*);
            Zcad::ErrorStatus   writeItem(bool);
#endif 

            Zcad::ErrorStatus   readItem(double*);
            Zcad::ErrorStatus   writeItem(double);

            Zcad::ErrorStatus   readItem(ZcGePoint2d*);
            Zcad::ErrorStatus   writeItem(const ZcGePoint2d&);

            Zcad::ErrorStatus   readItem(ZcGePoint3d*);
            Zcad::ErrorStatus   writeItem(const ZcGePoint3d&);

            Zcad::ErrorStatus   readItem(ZcGeVector2d*);
            Zcad::ErrorStatus   writeItem(const ZcGeVector2d&);

            Zcad::ErrorStatus   readItem(ZcGeVector3d*);
            Zcad::ErrorStatus   writeItem(const ZcGeVector3d&);

            Zcad::ErrorStatus   readItem(ZcGeScale3d*);
            Zcad::ErrorStatus   writeItem(const ZcGeScale3d&);

            Zcad::ErrorStatus   readItem(void *, ZSoft::UIntPtr);
            Zcad::ErrorStatus   writeItem(const void *, ZSoft::UIntPtr);

            Zcad::ErrorStatus   readItem(void **);
            Zcad::ErrorStatus   writeItem(const void *);

    virtual Zcad::ErrorStatus   seek(ZSoft::Int64 offset, int method) = 0;
    virtual              ZSoft::Int64   tell() const = 0;
    virtual Zcad::ErrorStatus   addReferences(ZcDbIdRefQueue& );
    virtual              bool   usesReferences() const;
    virtual ZcDbAuditInfo *     getAuditInfo() const;

    virtual ZcDbFilerController& controller() const;

private:
            ZcDbFilerController& mController;
};

class ZSOFT_NO_VTABLE ZcDbDxfFiler: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDxfFiler);

    virtual int               rewindFiler() = 0;

    virtual Zcad::ErrorStatus filerStatus() const = 0;
    virtual void              resetFilerStatus() = 0;

    virtual Zcad::ErrorStatus setError(Zcad::ErrorStatus, const ZTCHAR*, ...);
    virtual Zcad::ErrorStatus setError(const ZTCHAR*, ...);
    virtual const ZTCHAR* errorMessage() const;

    virtual  ZcDb::FilerType filerType() const = 0;

    virtual  ZcDbDatabase*      database() const = 0;

    virtual  Zcad::ErrorStatus  dwgVersion(ZcDb::ZcDbDwgVersion &,
                                ZcDb::MaintenanceReleaseVersion &) const;

    virtual int                 precision() const;
    virtual void                setPrecision(int prec);

    enum { kDfltPrec = -1, kMaxPrec  = 16 };

    virtual Zcad::ErrorStatus readResBuf   (resbuf*);
    virtual Zcad::ErrorStatus writeResBuf  (const resbuf&);
    virtual Zcad::ErrorStatus writeObjectId(ZcDb::DxfCode,
                                            const ZcDbObjectId&) = 0;
    virtual Zcad::ErrorStatus writeInt8    (ZcDb::DxfCode, ZSoft::Int8) = 0;
    inline  Zcad::ErrorStatus writeChar    (ZcDb::DxfCode c, ZSoft::Int8 n) {
                                return this->writeInt8(c, n); }
    virtual Zcad::ErrorStatus writeString  (ZcDb::DxfCode, const ZTCHAR*) = 0;
    virtual Zcad::ErrorStatus writeString  (ZcDb::DxfCode, const ZcString &) = 0;
    virtual Zcad::ErrorStatus writeBChunk  (ZcDb::DxfCode, const zds_binary&) = 0;
    virtual Zcad::ErrorStatus writeZcDbHandle(ZcDb::DxfCode,
                                              const ZcDbHandle&) = 0;
	virtual Zcad::ErrorStatus writeInt64   (ZcDb::DxfCode, ZSoft::Int64) = 0;
    virtual Zcad::ErrorStatus writeInt32   (ZcDb::DxfCode, ZSoft::Int32) = 0;
    virtual Zcad::ErrorStatus writeInt16   (ZcDb::DxfCode, ZSoft::Int16) = 0;
	virtual Zcad::ErrorStatus writeUInt64  (ZcDb::DxfCode, ZSoft::UInt64) = 0;
    virtual Zcad::ErrorStatus writeUInt32  (ZcDb::DxfCode, ZSoft::UInt32) = 0;
    virtual Zcad::ErrorStatus writeUInt16  (ZcDb::DxfCode, ZSoft::UInt16) = 0;
    virtual Zcad::ErrorStatus writeUInt8   (ZcDb::DxfCode, ZSoft::UInt8) = 0;
    virtual Zcad::ErrorStatus writeBoolean (ZcDb::DxfCode, ZSoft::Boolean) = 0;
    virtual Zcad::ErrorStatus writeBool    (ZcDb::DxfCode, bool) = 0;
    virtual Zcad::ErrorStatus writeDouble  (ZcDb::DxfCode, double,
                                            int = kDfltPrec) = 0;
    virtual Zcad::ErrorStatus writePoint2d (ZcDb::DxfCode, const ZcGePoint2d&,
                                            int = kDfltPrec) = 0;
    virtual Zcad::ErrorStatus writePoint3d (ZcDb::DxfCode, const ZcGePoint3d&,
                                               int = kDfltPrec) = 0;
    virtual Zcad::ErrorStatus writeVector2d(ZcDb::DxfCode, const ZcGeVector2d&,
                                            int = kDfltPrec) = 0;
    virtual Zcad::ErrorStatus writeVector3d(ZcDb::DxfCode, const ZcGeVector3d&,
                                            int = kDfltPrec) = 0;
    virtual Zcad::ErrorStatus writeScale3d (ZcDb::DxfCode, const ZcGeScale3d&,
                                            int = kDfltPrec) = 0;

    Zcad::ErrorStatus readItem        (resbuf* pItem);
    Zcad::ErrorStatus writeItem (const resbuf& pItem);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcDbObjectId&);

    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZTCHAR*);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const zds_binary&);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcDbHandle&);

	Zcad::ErrorStatus writeItem (ZcDb::DxfCode, ZSoft::Int64) { return Zcad::eOk; }
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, ZSoft::Int32);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, ZSoft::Int16);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, ZSoft::Int8);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, ZSoft::UInt32);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, ZSoft::UInt16);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, ZSoft::UInt8);
#ifndef ZSoft_Boolean_is_bool
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, ZSoft::Boolean);
#endif
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, bool);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, double, int = kDfltPrec);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcGePoint2d&,
                                 int = kDfltPrec);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcGePoint3d&,
                                 int = kDfltPrec);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcGeVector2d&,
                                 int = kDfltPrec);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcGeVector3d&,
                                 int = kDfltPrec);
    Zcad::ErrorStatus writeItem (ZcDb::DxfCode, const ZcGeScale3d&,
                                 int = kDfltPrec);

    virtual Zcad::ErrorStatus writeXDataStart ();
    virtual bool              includesDefaultValues() const = 0;

    virtual Zcad::ErrorStatus pushBackItem();
    virtual bool              atEOF();
    virtual bool              atSubclassData(const ZTCHAR *);
    virtual bool              atExtendedData();
    virtual bool              atEndOfObject();
    virtual void              haltAtClassBoundries(bool);

    virtual Zcad::ErrorStatus writeEmbeddedObjectStart();
    virtual bool              atEmbeddedObjectStart();

    virtual double elevation() const;
    virtual double thickness() const;

    virtual bool              isModifyingExistingObject() const;

    ZcDbDxfFiler();
    virtual ~ZcDbDxfFiler();
    ZcDbFilerController& controller() const;

private:
    ZcDbFilerController& mController;
    virtual Zcad::ErrorStatus setVAError(Zcad::ErrorStatus, const ZTCHAR*, va_list);
};

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZcDbHardOwnershipId* pId)
{   return readHardOwnershipId(pId); }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(const ZcDbHardOwnershipId& pId)
{   return writeHardOwnershipId(pId); }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZcDbSoftOwnershipId* pId)
{   return readSoftOwnershipId(pId); }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(const ZcDbSoftOwnershipId& pId)
{   return writeSoftOwnershipId(pId); }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZcDbHardPointerId* pId)
{   return readHardPointerId(pId); }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(const ZcDbHardPointerId& pId)
{   return writeHardPointerId(pId); }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZcDbSoftPointerId* pId)
{   return readSoftPointerId(pId); }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(const ZcDbSoftPointerId& pId)
{   return writeSoftPointerId(pId); }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZTCHAR** pVal)
{   return readString(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(const ZTCHAR* val)
{   return writeString(val);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(zds_binary* pVal)
{   return readBChunk(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(const zds_binary& val)
{   return writeBChunk(val);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZcDbHandle* pVal)
{   return readZcDbHandle(pVal);    }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(const ZcDbHandle& val)
{   return writeZcDbHandle(val);    }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZSoft::Int32* pVal)
{   return readInt32(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(ZSoft::Int32 val)
{   return writeInt32(val);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZSoft::Int16* pVal)
{   return readInt16(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(ZSoft::Int16 val)
{   return writeInt16(val);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZSoft::Int8 * pVal)
{   return this->readInt8(pVal);       }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(ZSoft::Int8 val)
{   return this->writeInt8(val);       }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZSoft::UInt32* pVal)
{   return readUInt32(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(ZSoft::UInt32 val)
{   return writeUInt32(val);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZSoft::UInt16* pVal)
{   return readUInt16(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(ZSoft::UInt16 val)
{   return writeUInt16(val);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZSoft::UInt8* pVal)
{   return readUInt8(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(ZSoft::UInt8 val)
{   return writeUInt8(val);            }

#ifndef ZSoft_Boolean_is_bool
inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZSoft::Boolean* pVal)
{   return readBoolean(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(ZSoft::Boolean val)
{   return writeBoolean(val);            }
#endif

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(bool* pVal)
{   return readBool(pVal);              }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(bool val)
{   return writeBool(val);              }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(double* pVal)
{   return readDouble(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(double val)
{   return writeDouble(val);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZcGePoint2d* pVal)
{   return readPoint2d(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(const ZcGePoint2d& val)
{   return writePoint2d(val);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZcGePoint3d* pVal)
{   return readPoint3d(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(const ZcGePoint3d& val)
{   return writePoint3d(val);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZcGeVector2d* pVal)
{   return readVector2d(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(const ZcGeVector2d& val)
{   return writeVector2d(val);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZcGeVector3d* pVal)
{   return readVector3d(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(const ZcGeVector3d& val)
{   return writeVector3d(val);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(ZcGeScale3d* pVal)
{   return readScale3d(pVal);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::writeItem(const ZcGeScale3d& val)
{   return writeScale3d(val);            }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(void *buf, ZSoft::UIntPtr cnt)
{   return readBytes(buf, cnt);     }

inline Zcad::ErrorStatus 
ZcDbDwgFiler::writeItem(const void *buf, ZSoft::UIntPtr cnt)
{   return writeBytes(buf, cnt);    }

inline Zcad::ErrorStatus ZcDbDwgFiler::readItem(void **pp)
{   return readAddress(pp);            }

inline Zcad::ErrorStatus 
ZcDbDwgFiler::writeItem(const void *p)
{   return writeAddress(p);            }

inline Zcad::ErrorStatus
ZcDbDxfFiler::readItem(resbuf* pVal)
{   return readResBuf(pVal);         }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(const resbuf& val)
{   return writeResBuf(val);            }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, const ZcDbObjectId& id)
{   return writeObjectId(dc, id); }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, const ZTCHAR* val)
{   return writeString(dc, val);        }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, const zds_binary& val)
{   return writeBChunk(dc, val);        }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, const ZcDbHandle& val)
{   return writeZcDbHandle(dc, val);        }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, ZSoft::Int32 val)
{   return writeInt32(dc, val);         }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, ZSoft::Int16 val)
{   return writeInt16(dc, val);         }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, ZSoft::Int8 val)
{   return this->writeInt8(dc, val);    }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, ZSoft::UInt32 val)
{   return writeUInt32(dc, val);        }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, ZSoft::UInt16 val)
{   return writeUInt16(dc, val);        }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, ZSoft::UInt8 val)
{   return writeUInt8(dc, val);         }

#ifndef ZSoft_Boolean_is_bool
inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, ZSoft::Boolean val)
{   return writeBoolean(dc, val);        }
#endif

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, bool val)
{   return writeBool(dc, val);        }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, double val, int prec)
{   return writeDouble(dc, val, prec);        }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, const ZcGePoint2d& val, int prec)
{   return writePoint2d(dc, val, prec); }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, const ZcGePoint3d& val, int prec)
{   return writePoint3d(dc, val, prec); }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, const ZcGeVector2d& val, int prec)
{   return writeVector2d(dc, val, prec);        }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, const ZcGeVector3d& val, int prec)
{   return writeVector3d(dc, val, prec);        }

inline Zcad::ErrorStatus
ZcDbDxfFiler::writeItem(ZcDb::DxfCode dc, const ZcGeScale3d& val, int prec)
{   return writeScale3d(dc, val, prec); }

#pragma pack (pop)

#endif
