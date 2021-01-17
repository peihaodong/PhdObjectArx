#ifndef ZC_BRMESH2D_H
#define ZC_BRMESH2D_H 1

#include "zadesk.h"
#include "zrxobject.h"
#include "zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrmesh.h"
#include "zcbrm2dctl.h"


// forward class declarations
class ZcBrEntity;
class ZcBrMesh2dControl;
class ZcBrMesh;
class ZcBrMesh2dData;


// these will come from STL in next release
static ZcBrMesh2dControl ZcBrMesh2dControlDefault;

struct pair {
    ZcBrEntity*			first;
    ZcBrMesh2dControl	second;
    pair() : first((ZcBrEntity*)NULL), second(ZcBrMesh2dControlDefault) {}
	pair(const ZcBrEntity*& a, const ZcBrMesh2dControl& b) : first((ZcBrEntity*)a), second(b) {}
};

inline pair
make_pair(const ZcBrEntity*& entity, const ZcBrMesh2dControl& control)
{ return pair(entity, control); }


// these are temporary typedefs until STL is available
typedef pair value_type;
typedef void iterator;


class DllImpExp ZcBrMesh2dFilter
{
public:
	ZcBrMesh2dFilter();
    ~ZcBrMesh2dFilter();
    
    // Insert
    iterator			insert			(const value_type& x);

private:
    // this is all temporary until STL is available
	friend class ZcBrImpMesh2d;

    ZcBrMesh2dFilter(const ZcBrMesh2dFilter& src);
    ZcBrMesh2dFilter&	operator =      (const ZcBrMesh2dFilter& src);

    value_type			mKeyValuePair;
};


class DllImpExp ZcBrMesh2d : public ZcBrMesh
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrMesh2d);
    ZcBrMesh2d();
    ZcBrMesh2d(const ZcBrMesh2d& src);
    ~ZcBrMesh2d();
    
    // Assignment operator
    ZcBrMesh2d&         operator =      (const ZcBrMesh2d& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   set				(ZcBrMesh2dData* mesh2d);
	ZcBr::ErrorStatus	get				(ZcBrMesh2dData*& mesh2d) const;

    // Mesh generation
    ZcBr::ErrorStatus   generate		(const ZcBrMesh2dFilter& meshFilter);
};


// Inline methods

inline
ZcBrMesh2dFilter::ZcBrMesh2dFilter() {}

inline
ZcBrMesh2dFilter::~ZcBrMesh2dFilter() {}

inline iterator
ZcBrMesh2dFilter::insert(const value_type& x)
{ mKeyValuePair.first = x.first; mKeyValuePair.second = x.second; }


#endif
