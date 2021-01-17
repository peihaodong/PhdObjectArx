#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif
#ifndef ZFORMATCODECINCLUSIVEPROPERTYSETINTERFACE_H
#include "zFormatCodecInclusivePropertySetInterface.h"
#endif

#ifndef ZFORMATCODECEXCLUSIVEPROPERTYSETINTERFACE_H
#define ZFORMATCODECEXCLUSIVEPROPERTYSETINTERFACE_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// This class groups properties into a set of properties where 
/// only one of the properties may be selected as active. This 
/// can be used to offer "menu-like" choices such as "High, Medium, Low".
/// </summary>
///
class DllImpExp FormatCodecExclusivePropertySetInterface : public FormatCodecInclusivePropertySetInterface
{
public:    
    /// <summary>
    /// The virtual destructor.
    /// </summary>
    ///
    virtual ~FormatCodecExclusivePropertySetInterface ();

    /// <summary>
    /// The index of the default selected property in the set.
    /// </summary>
    /// 
    /// <returns>
    /// The index of the default selected property.
    /// </returns>
    ///
    virtual int getDefaultPropertyIndex () const;

    /// <summary>
    /// The index of the selected property in the set.
    /// </summary>
    /// 
    /// <returns>
    /// The index of the selected property.
    /// </returns>
    ///
    virtual int getSelectedIndex () const;

    /// <summary>
    /// This sets index of the selected property in the set.
    /// </summary>
    /// 
    /// <param name="nSelectionIndex">
    /// The index of the property to that is selected.
    /// </param>
    ///
    virtual void setSelectedIndex (int nSelectionIndex);

protected:

    /// <summary>
    /// (Protected) The simple constructor.
    /// </summary>
    ///
    FormatCodecExclusivePropertySetInterface ();

    /// <summary>
    /// (Protected) The pre-allocating constructor.
    /// </summary>
    /// 
    /// <param name="nNumProperties">
    /// The number of properties that will be in the set.
    /// </param>
    ///
    FormatCodecExclusivePropertySetInterface (int nNumProperties);

    /// <summary>
    /// (Protected) Copy constructor.
    /// </summary>
    ///
    /// <param name="from">
    /// The instance to be copied.
    /// </param>
    ///
    FormatCodecExclusivePropertySetInterface (const FormatCodecExclusivePropertySetInterface& from);

    /// <summary>
    /// (Protected) The default selected property index.
    /// </summary>
    int mnDefaultPropertyIndex;

    /// <summary>
    /// (Protected) The selected property index.
    /// </summary>
    int mnSelectedIndex;

private:
    FormatCodecExclusivePropertySetInterface& operator= (const FormatCodecExclusivePropertySetInterface& from);
};

} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
