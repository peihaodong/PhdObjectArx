#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif

#ifndef ZROWPROVIDERINTERFACE_H
namespace Ztil { class RowProviderInterface; }
#endif

#ifndef ZCOLORMODELINTERFACE_H
#define ZCOLORMODELINTERFACE_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// This abstract base class is used as part of the <c>DataModel</c> classes
/// and allow the conversion of color types (rgb->gray) when connecting filters
/// derived from the <c>ImageFilter</c> base class.
/// </summary>
///
class DllImpExp ColorModelInterface 
{
public:
    /// <summary>
    /// Trivial virtual destructor.
    /// </summary>
    virtual ~ColorModelInterface ();
   
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
    virtual bool canConvertTo (const ColorModelInterface* colorModel) const = 0;

    /// <summary>
    /// This method asks for the conversion. The <c>canConvertTo</c> method will
    /// be called first to confirm that at a conversion is available.
    /// </summary>
    ///
    /// <param name='colorModel'> A constant instance of a another <c>ColorModelInterface</c>
    /// that is to be convert into it.
    /// </param>
    ///
    /// <param name='pInput'> An instance of a <c>RowProviderInterface</c>
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
        const ColorModelInterface* colorModel, RowProviderInterface* pInput ) const = 0;

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
    virtual bool canConvertFrom (const ColorModelInterface* colorModel) const = 0;

    /// <summary>
    /// This method asks for the conversion. The <c>canConvertTo</c> method will
    /// be called first to confirm that at a conversion is available.
    /// </summary>
    ///
    /// <param name='colorModel'> A constant instance of a another <c>ColorModelInterface</c>
    /// that is to be converted from.
    /// </param>
    ///
    /// <param name='pInput'> An instance of a <c>RowProviderInterface</c>
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
        const ColorModelInterface* colorModel, RowProviderInterface* pInput ) const = 0;
};

} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif

