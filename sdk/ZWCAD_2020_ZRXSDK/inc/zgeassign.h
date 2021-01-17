

#ifndef ZC_GEASSIGN_H
#define ZC_GEASSIGN_H

#pragma pack (push, 8)
class ZcGePoint2d;
class ZcGeVector2d;
class ZcGePoint3d;
class ZcGeVector3d;

inline ZcGePoint2d&
asPnt2d(const double* pnt)
{
    return *((ZcGePoint2d*)pnt);
}

inline ZcGeVector2d&
asVec2d(const double* vec)
{
    return *((ZcGeVector2d*)vec);
}

inline double*
asDblArray(const ZcGePoint2d& pnt)
{
    return (double*)&pnt;
}

inline double*
asDblArray(const ZcGeVector2d& vec)
{
    return (double*)&vec;
}

inline ZcGePoint3d&
asPnt3d(const double* pnt)
{
    return *((ZcGePoint3d*)pnt);
}

inline ZcGeVector3d&
asVec3d(const double* vec)
{
    return *((ZcGeVector3d*)vec);
}

inline double*
asDblArray(const ZcGePoint3d& pnt)
{
    return (double*)&pnt;
}

inline double*
asDblArray(const ZcGeVector3d& vec)
{
    return (double*)&vec;
}

#pragma pack (pop)
#endif
