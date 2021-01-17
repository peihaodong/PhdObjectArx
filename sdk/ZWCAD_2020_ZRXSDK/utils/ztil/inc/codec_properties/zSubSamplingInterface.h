#ifndef ZREADIMAGEFILEFRAMEINTERFACE_H
#include "zReadImageFileFrameInterface.h"
#endif
#ifndef ZSIZE_H
#include "zSize.h"
#endif

#ifndef ZSUBSAMPLINGINTERFACE_H
#define ZSUBSAMPLINGINTERFACE_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// This class specifies an aggregate of the <c>ReadImagFileFrameInterface</c>.
/// It specifies that the <c>ReadImagFileFrameInterface</c> can return scaled 
/// versions of the data.
/// </summary>
///
/// <remarks>
/// To be used the <c>ReadImagFileFrameInterface</c> derivant must also derive from
/// this class. This is multiple derivation however the parents are both pure abstract
/// API specification classes. RTTI will be used to identify if your class implements
/// this Interface.
/// </remarks>
///
class DllImpExp SubSamplingInterface
{
public:
    /// <summary>
    /// This is a trivial destructor.
    /// </summary>
    virtual ~SubSamplingInterface ();

    /// <summary>
    /// This is a negotiation. It attempts to get a specific scale for the data and
    /// the method returns the bracket of what is available for return. 
    /// </summary>
    /// 
    /// <param name="srcSize"> 
    /// A const reference to a <c>Size</c> object that holds the size in unscaled pixels.
    /// </param>
    ///
    /// <param name="outputSize"> 
    /// A const reference to a <c>Size</c> object that holds the desired output size in pixels.
    /// </param>
    ///
    /// <param name="lowerResSize"> 
    /// A reference to a <c>Size</c> object that will be set to the nearest resolution available
    /// that is lower than or equal to the desired scale.
    /// </param>
    ///
    /// <param name="higherResSize"> 
    /// A reference to a <c>Size</c> object that will be set to the nearest resolution available
    /// that is higher than or equal to the desired scale.
    /// </param>
    /// 
    /// <returns>
    /// This will return true if the lowerResSize and higherResSize have been correctly set.
    /// </returns>
    virtual bool getAvailableResolution (const Size& srcSize,
        const Size& outputSize, Size& lowerResSize, Size& higherResSize) = 0;
    
    /// <summary>
    /// A trivial constructor.
    /// </summary>
    SubSamplingInterface ();
};

} //end of namespace
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
