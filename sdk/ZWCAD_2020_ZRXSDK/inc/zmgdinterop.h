
#pragma once
#include <vcclr.h>
#include <gcroot.h>

class ZcGeVector2d;
class ZcGeVector3d;
class ZcGeMatrix2d;
class ZcGeMatrix3d;
class ZcGePoint2d;
class ZcGePoint3d;
class ZcGeScale2d;
class ZcGeScale3d;
class ZcGeTol;
class ZcDbObjectId;
class ZcDbExtents;

namespace ZwSoft
{
    namespace ZwCAD
    {
        namespace Runtime
        {
#ifdef __cplusplus_cli
            ref class DisposableWrapper;
#else
            public __gc __abstract class DisposableWrapper;
#endif
        }
    }
}

#ifdef __cplusplus_cli
 #define ZC_GCHANDLE_TO_VOIDPTR(x) ((GCHandle::operator System::IntPtr(x)).ToPointer())
 #define ZC_VOIDPTR_TO_GCHANDLE(x) (GCHandle::operator GCHandle(System::IntPtr(x)))
 #define ZC_NULLPTR nullptr
 #define ZC_GCNEW gcnew
 #define ZC_WCHAR_PINNED_GCPTR pin_ptr<const wchar_t>
 typedef ZwSoft::ZwCAD::Runtime::DisposableWrapper^ DisposableWrapper_GcPtr;
 typedef System::Type^ Type_GcPtr;
 typedef System::String^ String_GcPtr;
#else
 #define ZC_GCHANDLE_TO_VOIDPTR(x) ((GCHandle::op_Explicit(x)).ToPointer())
 #define ZC_VOIDPTR_TO_GCHANDLE(x) (GCHandle::op_Explicit(x))
 #define ZC_NULLPTR 0
 #define ZC_GCNEW new
 #define ZC_WCHAR_PINNED_GCPTR const wchar_t __pin*
 typedef ZwSoft::ZwCAD::Runtime::DisposableWrapper* DisposableWrapper_GcPtr;
 typedef System::Type* Type_GcPtr;
 typedef System::String* String_GcPtr;
#endif
class ZcMgObjectFactoryBase : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcMgObjectFactoryBase);
    virtual gcroot<DisposableWrapper_GcPtr> createRCW(ZcRxObject* unmanagedPointer, bool autoDelete) = 0;
    virtual bool isManaged()
    {
        return false;
    }
    virtual ~ZcMgObjectFactoryBase(){}
    virtual gcroot<Type_GcPtr> getType() = 0;
};
template <typename RCW, typename ImpObj>
class ZcMgObjectFactory : public ZcMgObjectFactoryBase
{

public:
    gcroot<DisposableWrapper_GcPtr> createRCW(ZcRxObject* unmanagedPointer, bool autoDelete)
    {
        gcroot<DisposableWrapper_GcPtr> temp = ZC_GCNEW RCW(System::IntPtr(static_cast<ImpObj*>(unmanagedPointer)),autoDelete);
        return temp;
    }
    ZcMgObjectFactory()
    {
        ImpObj::desc()->addX(ZcMgObjectFactoryBase::desc(),this);
    }
    ~ZcMgObjectFactory()
    {
        ImpObj::desc()->delX(ZcMgObjectFactoryBase::desc());
    }
	virtual gcroot<Type_GcPtr> getType() ZSOFT_OVERRIDE
	{
#ifdef __cplusplus_cli
		return RCW::typeid;
#else
		return __typeof(RCW);
#endif
	}
};
class StringToWchar
{
    typedef System::Runtime::InteropServices::GCHandle GCHandle;

    const wchar_t* m_ptr;
    void* m_pinner;

public:

    StringToWchar(String_GcPtr str)
    {

        m_pinner = ZC_GCHANDLE_TO_VOIDPTR(
            GCHandle::Alloc(str,System::Runtime::InteropServices::GCHandleType::Pinned)
            );
        ZC_WCHAR_PINNED_GCPTR tmp = PtrToStringChars(str);
        m_ptr = tmp;
    }
    ~StringToWchar()
    {
   		GCHandle g = ZC_VOIDPTR_TO_GCHANDLE(m_pinner);
		g.Free();
		m_pinner = 0;
    }
    operator const wchar_t*()
    {
        return m_ptr;
    }
};
inline String_GcPtr WcharToString(const wchar_t* value)
{
    return ZC_GCNEW System::String(value);
}

#undef ZC_GCHANDLE_TO_VOIDPTR
#undef ZC_VOIDPTR_TO_GCHANDLE
#undef ZC_NULLPTR
#undef ZC_GCNEW
#define StringToCIF StringToWchar
#define CIFToString WcharToString

#ifndef ZCDBMGD

#define GETVECTOR3D(vec3d)  (*reinterpret_cast<ZcGeVector3d*>(&(vec3d)))
#define GETVECTOR2D(vec2d)  (*reinterpret_cast<ZcGeVector2d*>(&(vec2d)))
#define GETMATRIX3D(mat3d)  (*reinterpret_cast<ZcGeMatrix3d*>(&(mat3d)))
#define GETMATRIX2D(mat2d)  (*reinterpret_cast<ZcGeMatrix2d*>(&(mat2d)))
#define GETPOINT3D(point3d) (*reinterpret_cast<ZcGePoint3d*>(&(point3d)))
#define GETPOINT2D(point2d) (*reinterpret_cast<ZcGePoint2d*>(&(point2d)))
#define GETSCALE2D(scale2d) (*reinterpret_cast<ZcGeScale2d*>(&(scale2d)))
#define GETSCALE3D(scale3d) (*reinterpret_cast<ZcGeScale3d*>(&(scale3d)))
#define GETTOL(tol)         (*reinterpret_cast<ZcGeTol*>(&(tol)))
#define GETOBJECTID(id)     (*reinterpret_cast<ZcDbObjectId*>(&(id)))
#define GETEXTENTS3D(ext3d) (*reinterpret_cast<ZcDbExtents*>(&(ext3d)))
#define GETSUBENTITYID(subentityId) (*reinterpret_cast<ZcDbSubentId*>(&(subentityId)))

#ifdef ZC_GEVEC3D_H
inline ZwSoft::ZwCAD::Geometry::Vector3d ToVector3d(const ZcGeVector3d& pt)
{
    ZwSoft::ZwCAD::Geometry::Vector3d ret;
    GETVECTOR3D(ret) = pt;
    return ret;
}
#endif

#ifdef ZC_GEVEC2D_H
inline ZwSoft::ZwCAD::Geometry::Vector2d ToVector2d(const ZcGeVector2d& pt)
{
    ZwSoft::ZwCAD::Geometry::Vector2d ret;
    GETVECTOR2D(ret) = pt;
    return ret;
}
#endif

#ifdef ZC_GEMAT2D_H
inline ZwSoft::ZwCAD::Geometry::Matrix3d ToMatrix3d(const ZcGeMatrix3d& pt)
{
    ZwSoft::ZwCAD::Geometry::Matrix3d ret;
    GETMATRIX3D(ret) = pt;
    return ret;
}
#endif

#ifdef ZC_GEMAT3D_H
inline ZwSoft::ZwCAD::Geometry::Matrix2d ToMatrix2d(const ZcGeMatrix2d& pt)
{
    ZwSoft::ZwCAD::Geometry::Matrix2d ret;
    GETMATRIX2D(ret) = pt;
    return ret;
}
#endif

#ifdef ZC_GEPNT3D_H
inline ZwSoft::ZwCAD::Geometry::Point3d ToPoint3d(const ZcGePoint3d& pt)
{
    ZwSoft::ZwCAD::Geometry::Point3d ret;
    GETPOINT3D(ret) = pt;
    return ret;
}
#endif

#ifdef ZC_GEPNT2D_H
inline ZwSoft::ZwCAD::Geometry::Point2d ToPoint2d(const ZcGePoint2d& pt)
{
    ZwSoft::ZwCAD::Geometry::Point2d ret;
    GETPOINT2D(ret) = pt;
    return ret;
}
#endif

#ifdef ZC_GESCL2D_H
inline ZwSoft::ZwCAD::Geometry::Scale2d ToScale2d(const ZcGeScale2d& pt)
{
    ZwSoft::ZwCAD::Geometry::Scale2d ret;
    GETSCALE2D(ret) = pt;
    return ret;
}
#endif

#ifdef ZC_GESCL3D_H
inline ZwSoft::ZwCAD::Geometry::Scale3d ToScale3d(const ZcGeScale3d& pt)
{
    ZwSoft::ZwCAD::Geometry::Scale3d ret;
    GETSCALE3D(ret) = pt;
    return ret;
}
#endif

#ifdef ZC_GETOL_H
inline ZwSoft::ZwCAD::Geometry::Tolerance ToTolerance(const ZcGeTol& pt)
{
    ZwSoft::ZwCAD::Geometry::Tolerance ret;
    GETTOL(ret) = pt;
    return ret;
}
#endif

#ifdef _ZD_DBID_H
inline ZwSoft::ZwCAD::DatabaseServices::ObjectId ToObjectId(const ZcDbObjectId& pt)
{
    ZwSoft::ZwCAD::DatabaseServices::ObjectId ret;
    GETOBJECTID(ret) = pt;
    return ret;
}
#endif

#ifdef ZD_DBMAIN_H
inline ZwSoft::ZwCAD::DatabaseServices::Extents3d ToExtents3d(const ZcDbExtents& pt)
{
    ZwSoft::ZwCAD::DatabaseServices::Extents3d ret;
    GETEXTENTS3D(ret) = pt;
    return ret;
}
#endif

#endif 
