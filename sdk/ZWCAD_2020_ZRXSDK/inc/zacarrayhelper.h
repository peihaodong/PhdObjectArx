


#if defined(ZSOFT_ZCGEVECTOR2D_DEFINED) && defined(_ZCARRAY_H)
#undef ZSOFT_ZCGEVECTOR2D_DEFINED
template<>
struct AllocatorSelector<ZcGeVector2d, false>
{
	typedef ZcArrayMemCopyReallocator<ZcGeVector2d> allocator;
};
#endif

#if defined(ZSOFT_ZCGEVECTOR3D_DEFINED) && defined(_ZCARRAY_H)
#undef ZSOFT_ZCGEVECTOR3D_DEFINED
template<>
struct AllocatorSelector<ZcGeVector3d, false>
{
	typedef ZcArrayMemCopyReallocator<ZcGeVector3d> allocator;
};
#endif

#if defined(ZSOFT_ZCGEPOINT3D_DEFINED) && defined(_ZCARRAY_H)
#undef ZSOFT_ZCGEPOINT3D_DEFINED
template<>
struct AllocatorSelector<ZcGePoint3d, false>
{
	typedef ZcArrayMemCopyReallocator<ZcGePoint3d> allocator;
};
#endif

#if defined(ZSOFT_ZCGEPOINT2D_DEFINED) && defined(_ZCARRAY_H)
#undef ZSOFT_ZCGEPOINT2D_DEFINED
template<>
struct AllocatorSelector<ZcGePoint2d, false>
{
	typedef ZcArrayMemCopyReallocator<ZcGePoint2d> allocator;
};
#endif

#if defined(ZSOFT_ZCDBOBJECTID_DEFINED) && defined(_ZCARRAY_H)
#undef ZSOFT_ZCDBOBJECTID_DEFINED
template<>
struct AllocatorSelector<ZcDbObjectId, false>
{
	typedef ZcArrayMemCopyReallocator<ZcDbObjectId> allocator;
};
#endif

#if defined(ZSOFT_ZCCMENTITYCOLOR_DEFINED) && defined(_ZCARRAY_H)
#undef ZSOFT_ZCCMENTITYCOLOR_DEFINED
template<>
struct AllocatorSelector<ZcCmEntityColor, false>
{
	typedef ZcArrayMemCopyReallocator<ZcCmEntityColor> allocator;
};
#endif


