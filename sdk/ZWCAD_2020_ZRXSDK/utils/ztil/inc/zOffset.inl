#ifndef ZOFFSET_INL
#define ZOFFSET_INL
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{
// The methods of the Offset class have been inlined for performance.
// Refer to the Offset.h header file for documentation of the methods.
//
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset::Offset () : x(0), y(0)
{
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset::Offset ( int nX, int nY ) : x(nX), y(nY)
{
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset::~Offset ()
{
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline const Offset& Offset::set( Int32 nX, Int32 nY)
{
    x = nX; y = nY;
    return *this;
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset& Offset::operator=( const Offset& rhs )
{
    x = rhs.x; y = rhs.y;
    return *this;
}   
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset Offset::operator+( Int32 nOffset ) const
{
    return Offset( x + nOffset, y + nOffset );
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset& Offset::operator+=( Int32 nOffset )
{
    x += nOffset; y += nOffset;
    return *this;
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset Offset::operator-( Int32 nOffset ) const
{
    return Offset( x - nOffset, y - nOffset );
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset& Offset::operator-=( Int32 nOffset )
{
    x -= nOffset; y -= nOffset;
    return *this;
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset Offset::operator*( Int32 nValue ) const
{
    return Offset(x*nValue, y*nValue);
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset& Offset::operator*=( Int32 nValue )
{
    x *= nValue; y *= nValue;
    return *this;
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset Offset::operator+( const Offset& rhs ) const
{
    return Offset(x+rhs.x, y+rhs.y);
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset& Offset::operator+=( const Offset& rhs )
{
    x += rhs.x; y += rhs.y;
    return *this;
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset Offset::operator-( const Offset& rhs ) const
{
    return Offset(x-rhs.x, y-rhs.y);
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline Offset& Offset::operator-=( const Offset& rhs )
{
    x -= rhs.x; y -= rhs.y;
    return *this;
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline bool Offset::operator==( const Offset& rhs ) const
{
    return (x == rhs.x && y == rhs.y);
}
/// <summary>
/// This inlined method is defined in Offset.h. <see cref="Offset">
/// </summary>
///
inline bool Offset::operator!=( const Offset& rhs ) const
{
    return (x != rhs.x || y != rhs.y);
}

} //end of namespace
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
