#ifndef ZIMAGEPIXEL_H
#define ZIMAGEPIXEL_H

#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif
#ifndef ZRGBCOLOR_H
#include "zRgbColor.h"
#endif
#ifndef ZDATAMODELATTRIBUTES_H
#include "zDataModelAttributes.h"
#endif
#ifndef ZDATAMODEL_H
#include "zDataModel.h"
#endif
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{
/// <summary>
/// This struct can hold a pixel of any "type" that is supported within ZTIL. As such
/// it is at least 64 bits wide. It is used to pass around pixel values where the code 
/// can be applied to any type of image. 
/// </summary>
///
struct DllImpExp ImagePixel 
{
    /// <summary>
    /// A union of all pixel bit sizes and the data model types.
    /// </summary>
    ///
    union {
        /// <summary> union member </summary>
        Data8  data1;
        /// <summary> union member </summary>
        Data8  data8;
        /// <summary> union member </summary>
        Data16 data16;
        /// <summary> union member </summary>
        Data32 data32;
        /// <summary> union member </summary>
        Data64 data64;
        /// <summary> union member </summary>
        Data128 data128;
        /// <summary> union member </summary>
        Data8  bitonal;
        /// <summary> union member </summary>
        Data8  gray;
        /// <summary> union member </summary>
        Data8  index;
        /// <summary> union member </summary>
        Data32 rgba;
        /// <summary> union member </summary>
        float  gray32f;
    } value;

    /// <summary>
    /// The "type" of the pixel as declared by <c>DataModelAttributes::PixelType</c> 
    /// <see cref="DataModelAttributes"/>
    /// </summary>
    ///
    DataModelAttributes::PixelType type;

    /// <summary>
    /// The constructor which set the <c>DataModelAttributes::PixelType</c> of 
    /// the pixel that will be set into the <c>value</c>.
    /// </summary>
    ///
    /// <param name='pixTpe'>The <c>DataModelAttributes::PixelType</c> of data that 
    /// the <c>ImagePixel</c> will hold.
    /// </param>
    ///
    ImagePixel (DataModelAttributes::PixelType pixTpe = DataModelAttributes::kData1);

    /// <summary>
    /// This method will set the <c>value</c> union to zero. Zero is one value that
    /// is always valid for each pixel type and so makes a safe initializer.
    /// </summary>
    ///
	/// <returns>
	/// A const reference to <c>*this</c>.
	/// </returns>
	///
    const ImagePixel& setToZero ();

    /// <summary>
    /// The equals operator will test the <c>DataModelAttributes::PixelType</c> and the
    /// <c>value</c> union and return true if they match.
    /// </summary>
    ///
	/// <param name= 'rhs'>
	/// A const reference to the pixel value to be compared.
	/// </param>
	///
	/// <returns>
	/// This will return true if the objects are equivalent.
	/// </returns>
	///
    bool operator==(const ImagePixel& rhs) const;

    /// <summary>
    /// The equals operator will test the <c>DataModelAttributes::PixelType</c> and the
    /// <c>value</c> union and return false if they match.
    /// </summary>
    ///
	/// <param name= 'rhs'>
	/// A const reference to the pixel value to be compared.
	/// </param>
	///
	/// <returns>
	/// This will return true if the objects are equivalent.
	/// </returns>
	///
    bool operator!=(const ImagePixel& rhs) const;
};

} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
