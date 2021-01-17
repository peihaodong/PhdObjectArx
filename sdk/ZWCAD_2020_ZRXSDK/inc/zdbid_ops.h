

#ifndef _ZD_DBID_OPS_H
#define _ZD_DBID_OPS_H 1

#include "zadesk.h"

class ZcDbStub;

bool
c5ObjIdIsLessThan(const ZcDbStub * lhs, const ZcDbStub * rhs); 

bool
c5ObjIdIsGreaterThan(const ZcDbStub * lhs, const ZcDbStub * rhs); 

bool
c5ObjIdLessThanOrEqual(const ZcDbStub * lhs, const ZcDbStub * rhs); 

bool
c5ObjIdGreaterThanOrEqual(const ZcDbStub * lhs, const ZcDbStub * rhs); 

bool
c5ObjIdIsEqualTo(const ZcDbStub * lhs, const ZcDbStub * rhs); 

bool
c4ObjIdIsLessThan(ZSoft::ULongPtr lhs, ZSoft::ULongPtr rhs);

bool
c4ObjIdIsGreaterThan(ZSoft::ULongPtr lhs, ZSoft::ULongPtr rhs);

bool
c4ObjIdLessThanOrEqual(ZSoft::ULongPtr lhs, ZSoft::ULongPtr rhs);

bool
c4ObjIdGreaterThanOrEqual(ZSoft::ULongPtr lhs, ZSoft::ULongPtr rhs);

bool
c4ObjIdIsEqualTo(ZSoft::ULongPtr lhs, ZSoft::ULongPtr rhs);

bool
c4ObjIdNotEqualTo(ZSoft::ULongPtr lhs, ZSoft::ULongPtr rhs);

#endif

