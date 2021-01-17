#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif

#ifndef ZPIXELSELECTORINTERFACE_H
#define ZPIXELSELECTORINTERFACE_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

/// <summary>
/// The namespace for the ZTILFilters.lib exported classes.
/// </summary>
///
namespace ZtilFilters
{

/// <summary>
/// This abstract base class is to be derived and implemented by the developer.
/// This interface is used by the <c>ExplodeSelect</c> class to determine whether
/// a given pixel is a member of a selected set. This allows the developer to 
/// determine and implement the selection criteria.
/// </summary>
///
class DllImpExp PixelSelectorInterface 
{
public:
    /// <summary>
    /// Trivial virtual destructor.
    /// </summary>
    virtual ~PixelSelectorInterface () {};

    /// <summary>
    /// Abstract selection method called by the <c>ExplodeSelect</c> class
    /// to determine if a pixel in an image could be included in the set of 
    /// selected pixels.
    /// </summary>
    ///
    /// <param name='x'>The index of the pixel along the x-axis to be tested
    /// for selection.
    /// </param>
    ///
    /// <param name='y'>The index of the pixel along the y-axis to be tested
    /// for selection.
    /// </param>
    ///
    /// <returns>
    /// A return of 'true' indicates that the pixel in question meets the
    /// selection criteria.
    /// </returns>
    ///
    virtual bool isSelected (Ztil::Int32 x, Ztil::Int32 y) = 0;

    /// <summary>
    /// Abstract selection method called by the <c>ExplodeSelect</c> class
    /// to set a pixel in an image as included in the set of selected pixels.
    /// </summary>
    ///
    /// <param name='y'>The index of the pixel along the y-axis to be selected.
    /// </param>
    ///
    /// <param name='x'>The index of the pixel along the x-axis that is the
    /// start of the selected pixels.
    /// </param>
    ///
    /// <param name='nCount'>The count of pixels along the x-axis from the 
    /// start to be selected.
    /// </param>
    ///
    virtual void setSelected (Ztil::Int32 y, Ztil::Int32 x, int nCount ) = 0;

    /// <summary>
    /// This method is called as a service to allow the selector class to 
    /// reset and write out any data it may be caching. What is needed to be 
    /// done is up to the developer.
    /// </summary>
    ///
    virtual void flush () = 0;
};

} //end of namespace
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
