

#ifndef ZC_GEFILER_H
#define ZC_GEFILER_H

#include "zAdAChar.h"
#include "zAcString.h"
#include "zgegbl.h"
#include "zacdb.h"
#pragma pack (push, 8)
class ZcDbDwgFiler;
     
class 
GE_DLLEXPIMPORT ZSOFT_NO_VTABLE
ZcGeFiler
{
protected:
    ZcGeFiler();
public:

    virtual
    Zcad::ErrorStatus      readBoolean(ZSoft::Boolean*) = 0; 
    virtual
    Zcad::ErrorStatus      writeBoolean(ZSoft::Boolean) = 0;

    virtual
    Zcad::ErrorStatus      readBool(bool*) = 0; 
    virtual
    Zcad::ErrorStatus      writeBool(bool) = 0;

    virtual
    Zcad::ErrorStatus      readSignedByte(char *) = 0;
    virtual
    Zcad::ErrorStatus      writeSignedByte(char) = 0;

    virtual
    Zcad::ErrorStatus      readString(ZcString &) = 0;
    virtual
    Zcad::ErrorStatus      writeString(const ZcString &) = 0;

    virtual
    Zcad::ErrorStatus      readShort(short*) = 0; 
    virtual
    Zcad::ErrorStatus      writeShort(short) = 0;
     
    virtual
    Zcad::ErrorStatus      readLong(ZSoft::Int32*) = 0; 
    virtual
    Zcad::ErrorStatus      writeLong(ZSoft::Int32) = 0;
     
    virtual
    Zcad::ErrorStatus      readUChar(unsigned char*) = 0; 
    virtual
    Zcad::ErrorStatus      writeUChar(unsigned char) = 0;
     
    virtual
    Zcad::ErrorStatus      readUShort(unsigned short*) = 0; 
    virtual
    Zcad::ErrorStatus      writeUShort(unsigned short) = 0;
     
    virtual
    Zcad::ErrorStatus      readULong(ZSoft::UInt32*) = 0; 
    virtual
    Zcad::ErrorStatus      writeULong(ZSoft::UInt32) = 0;
          
    virtual
    Zcad::ErrorStatus      readDouble(double*) = 0; 
    virtual
    Zcad::ErrorStatus      writeDouble(double) = 0;
     
    virtual
    Zcad::ErrorStatus      readPoint2d(ZcGePoint2d*) = 0; 
    virtual
    Zcad::ErrorStatus      writePoint2d(const ZcGePoint2d&) = 0;
     
    virtual
    Zcad::ErrorStatus      readPoint3d(ZcGePoint3d*) = 0; 
    virtual
    Zcad::ErrorStatus      writePoint3d(const ZcGePoint3d&) = 0;
     
    virtual
    Zcad::ErrorStatus      readVector2d(ZcGeVector2d*) = 0; 
    virtual
    Zcad::ErrorStatus      writeVector2d(const ZcGeVector2d&) = 0;
     
    virtual
    Zcad::ErrorStatus      readVector3d(ZcGeVector3d*) = 0; 
    virtual
    Zcad::ErrorStatus      writeVector3d(const ZcGeVector3d&) = 0;

    virtual
    ZcDbDwgFiler*          dwgFiler();

    virtual
    Zcad::ErrorStatus      readBytes(void*,ZSoft::UInt32) = 0;
    virtual
    Zcad::ErrorStatus      writeBytes(const void*, ZSoft::UInt32) = 0;
};

ZSOFT_FORCE_INLINE
ZcDbDwgFiler* ZcGeFiler::dwgFiler()
{
    return NULL;
}

#pragma pack (pop)
#endif
