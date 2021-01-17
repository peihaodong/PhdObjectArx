#ifndef ZPOLYGONALCLIP_H
#define ZPOLYGONALCLIP_H

#ifndef ZTILDEFS_H
#include "ZtilDefs.h"
#endif
#ifndef ZPOINT2D_H
#include "zPoint2d.h"
#endif
#ifndef ZSPANPROVIDERINTERFACE_H
#include "zSpanProviderInterface.h"
#endif

#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace ZtilFilters
{

class PolyList;
class Edge;

/// <summary>
/// This class implements the <c>SpanProviderInterface</c> and provide self-intersecting polygonal
/// clipping and cropping spans for <c>RowProviderInterface</c> image pipes.
/// </summary>
class DllImpExp PolygonalClip : public SpanProviderInterface
{
public:
	/// <summary>
	/// This enum describes how the polygon region is to be applied.
	/// </summary>
    enum Operation 
	{
		/// <summary> This entry dictates that the operation is a clip or a crop. <summary>
		///
		kClipCrop,
		/// <summary> This entry dictates that the operation is a window. <summary>
		///
		/// <remarks> This is not commonly used and may exhibit undesirable effects. </remarks>
		///
		kWindow 
	};

public:
	/// <summary>
	/// The constructor.
	/// </summary>
	///
	/// <param name='nPoints'> The integer count of points in the polygon. </param>
	/// 
	/// <param name='cpaPolygon'> A const pointer to an array of <c>Ztil::Point2d</c> objects
	/// describing the polygon. The pointer is not held by the object.
	/// </param>
	///
    /// <param name='op'> A member of the <c>Operation</c> enum. </param>
    ///
    PolygonalClip (int nPoints, const Ztil::Point2d* cpaPolygon, Operation op);

    /// <summary>
    /// The destructor.
    /// </summary>
    ///
    ~PolygonalClip ();

    /// <summary>
    /// This method returns the <c>Operation</c> usage of the instance. </summary>
    ///
    /// <returns> Returns the <c>Operation</c> enum entry held by the instance. </returns>
    ///
    Operation operation () const;

    /// <summary>
    /// This returns a correctly constructed <c>PolygonalClip</c> instance.
    /// </summary>
    ///
    /// <returns>
    /// This returns a new <c>PolygonalClip</c> instance as a <c>SpanProviderInterface</c>.
    /// </returns>
    ///
    virtual SpanProviderInterface* clone () const;

    /// <summary> This starts the return of spans with the first row. </summary>
    /// 
    virtual void begin ();

    /// <summary> This returns the <c>Mode</c> of operation of the span provider. </summary>
    /// 
    /// <returns> Returns a member of the <c>Mode</c> enum. </returns>
    ///
    virtual Mode mode ();

    /// <summary> This ends the return of rows of spans. </summary>
    /// 
    virtual void end ();

    /// <summary>
    /// This method increments the row pointer to the next row. </summary>
    ///
    /// <returns>
    /// This will return true if there is data on the row being incremented to.
    /// </returns>
    ///
    virtual bool nextRow ();

    /// <summary> This method will return the number of rows of span information. </summary>
    ///
    /// <returns> Returns the integer number of rows of span information. </returns>
    ///
    virtual int numRows ();

    /// <summary>
    /// This method returns the spans of data within the row returned. If no spans remain
    /// on the row, it will return false. 
    /// </summary>
    ///
    /// <param name="nStart">An integer reference that will be set to the offset of the first
    /// pixel of the current span.
    /// </param>
    /// 
    /// <param name="nCount">An integer reference that will be set to the number of pixels
    /// in the current span that are valid and should be copied.
    /// </param>
    ///
    /// <returns>
    /// This will return true if there are more spans to be returned.
    /// </returns>
    ///
    virtual bool getNextSpan (int& nStart, int& nCount);

    /// <summary> This method will return the number of spans on the current row. </summary>
    ///
    /// <returns> Returns the integer number of spans on the current row. </returns>
    ///
    virtual int numSpans ();

    /// <summary>
    /// This method will return the pixel bound box of the spans in the provider.
    /// </summary>
    ///
    /// <returns> Returns a const <c>BoundingBox</c> reference. </returns>
    ///
    virtual const Ztil::BoundingBox& bounds () const;

private:
    void preUpdateActiveEdgeTable ( int nCurrentY );
    void postUpdateActiveEdgeTable ();
    int roundAndClipToInt( const double& dValue ) const;

    // Kept for clone
    int mnPoints;
    Ztil::Point2d* mpPolygon;

    int mnRows;
    int mnOnRow;
    int mnSpans;

    // Polygon members
    PolyList** mapEdgeBucketSortList;
    PolyList* mpActiveEdgeSortList;
    Edge* mpCurEdge;

    Ztil::BoundingBox mBounds;
    Operation mOp;

    bool mbValidRegion;
};

}
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
