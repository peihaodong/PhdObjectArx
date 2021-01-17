#ifndef ZSUBREGIONROWITERATORINTERFACE_H
#include "zSubRegionRowIteratorInterface.h"
#endif
#ifndef ZSIZE_H
#include "zSize.h"
#endif

#ifndef ZSUBSAMPLINGROWITERATORINTERFACE_H
#define ZSUBSAMPLINGROWITERATORINTERFACE_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// This class specifies an aggregate of the <c>SubRegionRowIteratorInterface</c>.
/// It specifies that the <c>SubRegionRowIteratorInterface</c> can return scaled 
/// versions of the data.
/// </summary>
///
/// <remarks>
/// To be used the <c>RowIteratorInterface</c> derivant must derive from
/// this class. This is multiple derivation however the parents are both pure abstract
/// API specification classes. RTTI will be used to identify if your class implements
/// this Interface.
/// </remarks>
///
class DllImpExp SubSamplingRowIteratorInterface : public SubRegionRowIteratorInterface
{
public:
    /// <summary>
    /// This is a trivial destructor.
    /// </summary>
    virtual ~SubSamplingRowIteratorInterface ();

    /// <summary>
    /// This sets the desired output size.
    /// </summary>
    /// 
    /// <param name="scaledSize"> The size of the area at scale to be returned.
    /// </param>
    ///
    virtual void setScaledSize (const Size& scaledSize)  = 0;

    /// <summary>
    /// This sets the scale to 1:1 (unscaled).
    /// </summary>
    virtual void resetScaleFactor () = 0;

    /// <summary>
    /// A trivial constructor.
    /// </summary>
    SubSamplingRowIteratorInterface ();
};

} //end of namespace
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
