#ifndef ZTILDEFS_H
#include <ZtilDefs.h>
#endif

#ifndef ZOFFSET_H
#include "zOffset.h"
#endif

#ifndef ZSIZE_H
#define ZSIZE_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// The <c>Size</c> class holds width and height members and is used to describe
/// the pixel dimensions of an image or in other methods that need to use integral
/// values for size.
/// </summary>
///
class DllImpExp Size 
{
public:
    /// <summary> An integer count that is the width.
    /// </summary>
    Int32 width;
    /// <summary> An integer count that is the height.
    /// </summary>
    Int32 height;

    /// <summary>
    /// The default or empty constructor.
    /// </summary>
    ///
    Size ();

    /// <summary>
    /// The initialization constructor.
    /// </summary>
    ///
	/// <param name='width'>
	/// Initial value for the width.
	/// </param>
	///
	/// <param name='height'>
	/// Initial value for the height.
	/// </param>
	///
    Size (Int32 width, Int32 height);

    /// <summary>
    /// The copy constructor.
    /// </summary>
    ///
	/// <param name='rhs'>
	/// A const reference to the <c>Size</c> to be copied.
	/// </param>
	///
    Size ( const Size& rhs );

    /// <summary>
    /// The destructor.
    /// </summary>
    ///
    ~Size ();

    /// <summary>
    /// The less than or equals operator. Both the <c>width</c> and the <c>height</c> members
    /// must meet the comparison criteria.
    /// </summary>
    ///
	/// <param name='rhs'>
	/// The argument to be compared.
	/// </param>
	///
	/// <returns>
	/// Returns true if the condition is satisfied.
	/// </returns>
	///
    bool operator <= (const Size& rhs) const;

    /// <summary>
    /// The greater than or equals operator. Both the <c>width</c> and the <c>height</c> members
    /// must meet the comparison criteria.
    /// </summary>
    ///
	/// <param name='rhs'>
	/// The argument to be compared.
	/// </param>
	///
	/// <returns>
	/// Returns true if the condition is satisfied.
	/// </returns>
	///
    bool operator >= (const Size& rhs) const;

    /// <summary>
    /// The equals operator. True will be returned if the <c>width</c> and the 
    /// <c>height</c> members must meet the comparison criteria.
    /// </summary>
    ///
	/// <param name='rhs'>
	/// The argument to be compared.
	/// </param>
	///
	/// <returns>
	/// Returns true if the condition is satisfied.
	/// </returns>
	///
    bool operator == (const Size& rhs) const;

    /// <summary>
    /// The not equals operator. False will be returned if the <c>width</c> and the 
    /// <c>height</c> members must meet the comparison criteria.
    /// </summary>
    ///
	/// <param name='rhs'>
	/// The argument to be compared.
	/// </param>
	///
	/// <returns>
	/// Returns true if the condition is satisfied.
	/// </returns>
	///
    bool operator != (const Size& rhs) const;

    /// <summary>
    /// The assignment operator. 
    /// </summary>
    ///
	/// <param name='rhs'>
	/// The argument to be copied from.
	/// </param>
	///
	/// <returns>
	/// Returns a const reference to <c>*this</c>.
	/// </returns>
	///
    const Size& operator = (const Size& rhs);

    /// <summary>
    /// This method will set the <c>width</c> and the <c>height</c> members.
    /// </summary>
    ///
    /// <param name="nWidth">The value that the <c>width</c> should be set to.
    /// </param>
    ///
    /// <param name="nHeight">The value that the <c>height</c> should be set to.
    /// </param>
    ///
	/// <returns>
	/// Returns a const reference to <c>*this</c>.
	/// </returns>
	///
    const Size& set( Int32 nWidth, Int32 nHeight );

    /// <summary>
    /// This method will add the parameters to the <c>width</c> and 
    /// the <c>height</c> members respectively.
    /// </summary>
    ///
    /// <param name="width">The value that should be added to the <c>width</c>.
    /// </param>
    ///
    /// <param name="height">The value that should be added to the <c>height</c>.
    /// </param>
    ///
	/// <returns>
	/// Returns a const reference to <c>*this</c>.
	/// </returns>
	///
    const Size& grow (Int32 width, Int32 height);

    /// <summary>
    /// This method will add the value to both the <c>width</c> and 
    /// the <c>height</c> members.
    /// </summary>
    ///
    /// <param name="toEach">The value that should be added to the <c>width</c>
    /// and the <c>height</c>.
    /// </param>
    ///
	/// <returns>
	/// Returns a const reference to <c>*this</c>.
	/// </returns>
	///
    const Size& grow (Int32 toEach);

    /// <summary>
    /// This method will subtracted from parameters the <c>width</c> and 
    /// the <c>height</c> members respectively.
    /// </summary>
    ///
    /// <param name="width">The value that should be subtracted from the <c>width</c>.
    /// </param>
    ///
    /// <param name="height">The value that should be subtracted from the <c>height</c>.
    /// </param>
    ///
	/// <returns>
	/// Returns a const reference to <c>*this</c>.
	/// </returns>
	///
    const Size& shrink (Int32 width, Int32 height);

    /// <summary>
    /// This method will subtract the value from both the <c>width</c> and 
    /// the <c>height</c> members.
    /// </summary>
    ///
    /// <param name="eachBy">The value that should be subtracted from the <c>width</c>
    /// and the <c>height</c>.
    /// </param>
    ///
	/// <returns>
	/// Returns a const reference to <c>*this</c>.
	/// </returns>
	///
    const Size& shrink (Int32 eachBy);
};


/// <summary>
/// A grouping of methods that interact between <c>Size</c> and <c>Offset</c>.
/// The methods are inlined as they are small.
/// </summary>
///
namespace SizeOps
{
/// <summary>
/// This method will return the number of pixels that lie between the two
/// offsets.
/// </summary>
///
/// <param name="oHigh">The greater of the two offsets that specify the rectangular region.
/// </param>
///
/// <param name="oLow">The lower of the two offsets that specify the rectangular region.
/// </param>
///
/// <returns>
/// This method returns a <c>Size</c> instance that holds the width
/// and height in pixels of the region specified in the arguments.
/// </returns>
///
inline Size getSizeOf( const Offset& oHigh, const Offset& oLow )
{
    return Size(oHigh.x - oLow.x + 1, oHigh.y - oLow.y + 1);
}
/// <summary>
/// This method will return the <c>Offset</c> of the lower right pixel in the
/// the region described by the argument.
/// </summary>
///
/// <param name="extents">The <c>Size</c> region that extends from (0,0) up to
/// but not including <c>Size::width</c> and <c>Size::height</c>.
/// </param>
///
/// <returns>
/// This method returns the <c>Offset</c> set to the most extreme pixel (Lower Right)
/// within the region.
/// </returns>
///
inline Offset getHighOffset( const Size& extents )
{
    return Offset(extents.width - 1, extents.height - 1);
}

/// <summary>
/// This method will return the <c>Offset</c> of the lower right pixel in the
/// the region described by the arguments.
/// </summary>
///
/// <param name="oOrigin">The <c>Offset</c> for the region that extends up to
/// and but not including the offset plus the <c>Size::width</c> and <c>Size::height</c>.
/// </param>
///
/// <param name="extents">The <c>Size</c> region that extends from (0,0) up to
/// but not including <c>Size::width</c> and <c>Size::height</c>.
/// </param>
///
/// <returns>
/// This method returns the <c>Offset</c> set to the most extreme pixel (Lower Right)
/// within the region.
/// </returns>
///
inline Offset getHighOffset( const Offset& oOrigin, const Size& extents )
{
    return Offset( oOrigin.x + extents.width - 1, oOrigin.y + extents.height - 1 );
}

} // end of namespace SizeOps

} //end of namespace
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#ifndef ZSIZE_INL
#include <zSize.inl>
#endif

#endif
