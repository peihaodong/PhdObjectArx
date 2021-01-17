#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif
#ifndef ZREADIMAGEFILEFRAMEINTERFACE_H
#include "zReadImageFileFrameInterface.h"
#endif

#ifndef ZDIRECTTILEREADINTERFACE_H
#define ZDIRECTTILEREADINTERFACE_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{

/// <summary>
/// This class specifies an aggregate of the <c>ReadImagFileFrameInterface</c>.
/// It specifies that the <c>ReadImagFileFrameInterface</c> can return tiles of data.
/// </summary>
///
/// <remarks>
/// To be used the <c>ReadImagFileFrameInterface</c> derivant must also derive from
/// this class. This is multiple derivation however the parents are both pure abstract
/// API specification classes. RTTI will be used to identify if your class implements
/// this Interface.
/// </remarks>
///
class DllImpExp DirectTileReadInterface
{
public:
    /// <summary>
    /// This is a trivial destructor.
    /// </summary>
    virtual ~DirectTileReadInterface ();

    /// <summary>
    /// This returns the size of a square tile. Tiles are always square.
    /// </summary>
    ///
    /// <param name="nLookingFor">
    /// The desired number of pixels for each side of a tile.
    /// </param>
    ///
    /// <returns>
    /// The integer size of either dimension of a square tile in pixels.
    /// </returns>
    virtual int getTileSize (int nLookingFor) = 0;

    /// <summary>
    /// This will set the upper left corner of the requested subregion.
    /// </summary>
    ///
    /// <param name="nRow">
    /// The integer index of the row for the desired tile.
    /// </param>
    ///
    /// <param name="nColumn">
    /// The integer index of the column of the desired tile.    
    /// </param>
    ///
    /// <param name="pBuffer">
    /// The address (pointer to) a buffer to receive the tile data.
    /// </param>
    /// 
    /// <returns>
    /// This will return true if the <c>pBuffer</c> was filled with the tiles data.
    /// </returns>
    /// 
    /// <remarks>
    /// Every tile is complete. Partial tiles on the right or bottom should be 
    /// padded with initialized data.
    /// </remarks>
    ///
    virtual bool getTileData (UInt32 nRow, UInt32 nColumn, UInt8* pBuffer) = 0;
};

} // end of namespace Ztil
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif

