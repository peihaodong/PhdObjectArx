#ifndef ZDATAMODELATTRIBUTES_H
#include "zDataModelAttributes.h"
#endif
#ifndef ZRGBGRAYMODEL_H
#include "zRgbGrayModel.h"
#endif

#ifndef ZTILEXCEPTION_H
#include "ZTILException.h"
#endif

#ifndef ZBITONALMODEL_H
#define ZBITONALMODEL_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{
/// <summary>
/// The data model for 1-bit images that are part of the RgbModel space. 
/// This datamodel is derived from RgbGrayModel. The foreground "on" or "1" pixels 
/// are considered to be white(255), and the background "off" or "0" pixels are considered 
/// to be black(0).
/// </summary>
///
class DllImpExp BitonalModel : public RgbGrayModel
{
public:

    /// <summary>
    /// The class constructor will create an instance of the class.
    /// </summary>
    ///
    BitonalModel ();

    /// <summary>
    /// Virtual destructor.
    /// </summary>
    ///
    virtual ~BitonalModel ();

    /// <summary>
    /// The implementation of the clone method used which is the safest way to
    /// make a copy of an existing <c>BitonalModel</c> instance.
    /// </summary>
    ///
    /// <returns>
    /// This will return a copy of the instance.
    /// </returns>
    ///
    virtual DataModel* clone () const;

    /// <summary>
    /// This query returns an entry of the DataModelType enum. It will always
    /// return <c>kBitonalModel</c>.
    /// </summary>
    ///
    /// <returns>
    /// An entry of the DataModelType enum that is <c>kBitonalModel</c>.
    /// </returns>
    ///
    DataModelAttributes::DataModelType dataModelType () const;

    /// <summary>
    /// Query the pixel type of the data represented which is always kBitonal.
    /// </summary>
    ///
    /// <returns>
    /// This method returns PixelType::kBitonal.
    /// </returns>
    ///
    virtual DataModelAttributes::PixelType pixelType () const;

    /// <summary>
    /// This method test for convertibility to a given <c>ColorModelInterface</c>.
    /// </summary>
    ///
    /// <param name='colorModel'> A constant instance of a another <c>ColorModelInterface</c>
    /// that is to be tested to see if this instance can convert into it.
    /// </param>
    /// 
    /// <returns>
    /// This should return if this class can supply a conversion filter.
    /// </returns>
    ///
    virtual bool canConvertTo (const ColorModelInterface* colorModel) const;

    /// <summary>
    /// This method asks for the conversion. The <c>canConvertTo</c> method will
    /// be called first to confirm that at a conversion is available.
    /// </summary>
    ///
    /// <param name='colorModel'> A constant instance of a another <c>ColorModelInterface</c>
    /// that is to be convert into it.
    /// </param>
    ///
    /// <param name='pConvert'> An instance of a <c>RowProviderInterface</c>
    /// that represents the source of the data to be converted.
    /// </param>
    ///
    /// <returns>
    /// This returns a new filter that has the conversion hooked into it. See the
    /// <c>ImageFilter</c> base class for more information on creating and linking
    /// together filters.
    /// </returns>
    ///
    virtual RowProviderInterface* getModelConversionTo (
        const ColorModelInterface* colorModel, RowProviderInterface* pConvert) const;

    /// <summary>
    /// This method test for convertibility into a given <c>ColorModelInterface</c>.
    /// </summary>
    ///
    /// <param name='colorModel'> A constant instance of a another <c>ColorModelInterface</c>
    /// that is to be tested to see if this instance can convert from it.
    /// </param>
    /// 
    /// <returns>
    /// This should return if this class can supply a conversion filter that will
    /// change the data into this instances color model.
    /// </returns>
    ///
    virtual bool canConvertFrom (const ColorModelInterface* colorModel) const;

    /// <summary>
    /// This method asks for the conversion. The <c>canConvertTo</c> method will
    /// be called first to confirm that at a conversion is available.
    /// </summary>
    ///
    /// <param name='colorModel'> A constant instance of a another <c>ColorModelInterface</c>
    /// that is to be converted from.
    /// </param>
    ///
    /// <param name='pConvert'> An instance of a <c>RowProviderInterface</c>
    /// that represents the source of the data to be converted.
    /// </param>
    ///
    /// <returns>
    /// This returns a new filter that has the conversion hooked into it. See the
    /// <c>ImageFilter</c> base class for more information on creating and linking
    /// together filters.
    /// </returns>
    ///
    virtual RowProviderInterface* getModelConversionFrom (
        const ColorModelInterface* colorModel, RowProviderInterface* pConvert) const;

    /// <summary>
    /// The equals operator.
    /// </summary>
    ///
    /// <param name= 'dm'>
    /// A const reference to the <c>DataModel</c> to be tested.
    /// </param>
    ///
    /// <returns>
    /// This method returns true if two DataModel objects are equivalent.
    /// </returns>
    ///
    /// <remarks>
    /// Each internal ZTIL derived <c>DataModel</c> will implement its own operators to 
    /// implement the correct and meaningful comparison.
    /// </remarks>
    ///
    virtual bool operator==(const DataModel& dm) const;

    /// <summary>
    /// The not equals operator.
    /// </summary>
    ///
    /// <param name= 'dm'>
    /// A const reference to the <c>DataModel</c> to be tested.
    /// </param>
    ///
    /// <returns>
    /// This method returns true if two DataModel objects are not equivalent.
    /// </returns>
    ///
    /// <remarks>
    /// Each internal ZTIL derived <c>DataModel</c> will implement its own operators to 
    /// implement the correct and meaningful comparison.
    /// </remarks>
    ///
    virtual bool operator!=(const DataModel& dm) const;
};
}//namespace

#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
