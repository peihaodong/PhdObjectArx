#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif
#ifndef ZFORMATCODECPROPERTYINTERFACE_H
#include "zFormatCodecPropertyInterface.h"
#endif

#ifndef ZFORMATCODECBOOLEANPROPERTY_H
#define ZFORMATCODECBOOLEANPROPERTY_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// This class holds a boolean value. 
/// </summary>
///
/// <remarks>
/// The boolean value is most often used in conjunction with other simple
/// data type properties in a set grouping that forms something analogous to
/// a structure in 'c'.
///
/// An example may be a format that has compression that may or may not be
/// lossy. A boolean together with an integer may be a way to expose the
/// option of lossy vs lossless compression.
/// </remarks>
///
class DllImpExp FormatCodecBooleanProperty : public FormatCodecPropertyInterface
{
public:
    /// <summary>
    /// The constructor for the class.
    /// </summary>
    ///
    /// <param name="bDefault">
    /// A boolean which will set the initial state of the class.
    /// </param>
    ///
    FormatCodecBooleanProperty (bool bDefault);

    /// <summary>
    /// The virtual destructor.
    /// </summary>
    ///
    virtual ~FormatCodecBooleanProperty ();

    /// <summary>
    /// This method is an artificial copy constructor. It will make a complete
    /// and accurate copy of the class.
    /// </summary>
    ///
    /// <returns>
    /// This method returns the new <c>FormatCodecBooleanProperty</c> instance as a 
    /// <c>FormatCodecPropertyInterface</c> pointer.
    /// </returns>
    ///
    virtual FormatCodecPropertyInterface* clone () const;

    /// <summary>
    /// This method will return the default value of the property.
    /// </summary>
    ///
    /// <param name="bDefault">
    /// A boolean reference which will be set to the default state of the class.
    /// </param>
    ///
    /// <returns>
    /// The boolean return indicates whether the class has a valid default.
    /// </returns>
    ///
    bool getDefaultValue (bool& bDefault) const;

    /// <summary>
    /// This method will set the state of the boolean.
    /// </summary>
    ///
    /// <param name="bState">
    /// A boolean which will be used to set the state of the class.
    /// </param>
    ///
    void setValue (bool bState);

    /// <summary>
    /// This method will get the state of the boolean.
    /// </summary>
    ///
    /// <param name="bState">
    /// A boolean reference which will set to set the state of the class.
    /// </param>
    ///
    void getValue (bool& bState) const;

protected:

    /// <summary>
    /// (Protected) The default value.
    /// </summary>
    bool mbDefault;

    /// <summary>
    /// (Protected) The value of the class.
    /// </summary>
    bool mbValue;
};

} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
