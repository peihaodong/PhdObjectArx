#ifndef ZROWITERATORINTERFACE_H
#include "zRowIteratorInterface.h"
#endif

#ifndef ZSUBREGIONROWITERATORINTERFACE_H
#define ZSUBREGIONROWITERATORINTERFACE_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// This class extends the <c>RowIteratorInterface</c> class adding
/// the ability to specify a sub area of the total pixel area of the 
/// the image in the file. 
/// </summary>
/// 
/// <remarks>
/// Developers should not base their <c>RowIteratorInterface</c> on this
/// super class unless their codec can support reading a sub region (rectangle).
/// This is most often the case when the data in the file is not compressed.
/// </remarks>
///
class DllImpExp SubRegionRowIteratorInterface : public RowIteratorInterface
{
public:
    /// <summary>
    /// This is a trivial destructor.
    /// </summary>
    virtual ~SubRegionRowIteratorInterface ();

    /// <summary>
    /// This will reset equivalent sub region currently set to (0,0) (xsize, ysize).
    /// This makes it equivalent to the return of <c>RowIteratorInterface</c>.
    /// </summary>
    virtual void setRegionToExtents () = 0;

    /// <summary>
    /// This will set the upper left corner of the requested subregion.
    /// </summary>
    ///
    /// <param name="nRow">
    /// The integer index of the desired row to start on.
    /// </param>
    ///
    /// <param name="nCol">
    /// The integer index of the desired column to start with.    
    /// </param>
    ///
    virtual void setStart (int nRow, int nCol) = 0;

    /// <summary>
    /// This will get the upper left corner of the requested subregion.
    /// </summary>
    ///
    /// <param name="nRow">
    /// The reference to an integer that will be set to the index of the desired row to start on.
    /// </param>
    ///
    /// <param name="nCol">
    /// The reference to an integer that will be set to the index of the desired column to start with.    
    /// </param>
    ///
    virtual void getStart (int& nRow, int& nCol) = 0;

    /// <summary>
    /// This will set the lower right corner of the requested subregion.
    /// </summary>
    ///
    /// <param name="nRow">
    /// The integer index of the desired row to end on.
    /// </param>
    ///
    /// <param name="nCol">
    /// The integer index of the desired column to end with.    
    /// </param>
    ///
    virtual void setEnd (int nRow, int nCol) = 0;

    /// <summary>
    /// This will get the lower right corner of the requested subregion.
    /// </summary>
    ///
    /// <param name="nRow">
    /// The reference to an integer that will be set to the index of the desired row to end on.
    /// </param>
    ///
    /// <param name="nCol">
    /// The reference to an integer that will be set to the index of the desired column to end with.    
    /// </param>
    ///
    virtual void getEnd (int& nRow, int& nCol) = 0;
};

} //end of namespace
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
