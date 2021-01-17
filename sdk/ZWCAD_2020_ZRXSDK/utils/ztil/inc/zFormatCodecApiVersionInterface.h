#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif

#ifndef ZFORMATCODECAPIVERSIONINTERFACE_H
#define ZFORMATCODECAPIVERSIONINTERFACE_H

#ifndef ZTILVERSIONS_H
#include "ZTILVersions.h"
#endif
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// This class references the 'define'd API version of ZTIL and encodes it returning
/// the version in its member methods. When Image File Format Codecs are compiled against
/// a version of the ZTIL library, they refer to this class which then returns the
/// the API version that the Codecs "talk". 
/// </summary>
///
/// <remarks>
/// ZTIL has versions for the API that it exports as well as the library itself.
/// </remarks>
///
class DllImpExp FormatCodecApiVersionInterface
{
public:

    /// <summary>
    /// The virtual destructor.
    /// </summary>
    ///
	virtual ~FormatCodecApiVersionInterface();

    /// <summary>
    /// This returns the major revision of the ZTIL Format Codec API.
    /// </summary>
    ///
    /// <returns>
    /// The integral revision number.
    /// </returns>
    ///
    virtual int majorVersion () const;

    /// <summary>
    /// This returns the minor revision of the ZTIL Format Codec API.
    /// </summary>
    ///
    /// <returns>
    /// The integral revision number.
    /// </returns>
    ///
    virtual int minorVersion () const;
};

}
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
