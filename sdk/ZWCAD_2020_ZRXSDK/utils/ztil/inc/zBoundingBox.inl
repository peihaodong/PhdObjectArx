#ifndef ZBOUNDINGBOX_INL
#define ZBOUNDINGBOX_INL

#ifndef ZOFFSET_H
#include "zOffset.h"
#endif
#ifndef ZSIZE_H
#include "zSize.h"
#endif
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif
namespace Ztil {
///<remarks>This file is one of inlines for the BoundingBox class. The many
///simple functions inlined are as an aid to performance.</remarks>

///<summary>(Inlined) See BoundingBox.h</summary>
inline BoundingBox::BoundingBox (Offset offset, Size size) 
    : mOrigin(offset)
{
    mExtent = SizeOps::getHighOffset(offset,size);
}
///<summary>(Inlined) See BoundingBox.h</summary>
inline BoundingBox::BoundingBox (Offset origin, Offset extent)
    : mOrigin(origin), mExtent(extent)
{
}
///<summary>(Inlined) See BoundingBox.h</summary>
inline BoundingBox::BoundingBox (int nPoints, const Offset* aOffsets)
{
    set(nPoints, aOffsets );
}
///<summary>(Inlined) See BoundingBox.h</summary>
inline BoundingBox::~BoundingBox ()
{
}
///<summary>(Inlined) See BoundingBox.h</summary>
inline void BoundingBox::set (Offset offset, Size size)
{
    mOrigin = offset; mExtent = SizeOps::getHighOffset(offset,size);
}
///<summary>(Inlined) See BoundingBox.h</summary>
inline void BoundingBox::set (Offset origin, Offset extent)
{
    mOrigin = origin; mExtent = extent;
}

///<summary>(Inlined) See BoundingBox.h</summary>
inline bool BoundingBox::inBounds (const Offset& offset) const
{
    return ( offset.x >= mOrigin.x && offset.y >= mOrigin.y
        && offset.x <= mExtent.x && offset.y <= mExtent.y );
}
///<summary>(Inlined) See BoundingBox.h</summary>
inline bool BoundingBox::inBounds ( int x, int y ) const
{
    return ( x >= mOrigin.x && y >= mOrigin.y
        && x <= mExtent.x && y <= mExtent.y );
}
///<summary>(Inlined) See BoundingBox.h</summary>
inline void BoundingBox::getExtents (Offset& origin, Offset& extent) const
{
    origin = mOrigin; extent = mExtent;
}
///<summary>(Inlined) See BoundingBox.h</summary>
inline Size BoundingBox::size () const
{
    return SizeOps::getSizeOf(mExtent, mOrigin);
}
///<summary>(Inlined) See BoundingBox.h</summary>
inline Offset BoundingBox::origin () const
{
    return mOrigin;
}
///<summary>(Inlined) See BoundingBox.h</summary>
inline bool BoundingBox::contains( const BoundingBox& otherBox ) const
{
    return (inBounds(otherBox.mOrigin) && inBounds(otherBox.mExtent));
}

}
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif
#endif
