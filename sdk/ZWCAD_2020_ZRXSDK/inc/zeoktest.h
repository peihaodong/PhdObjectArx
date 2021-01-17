
#ifndef _ZEOKTEST_H_
#define _ZEOKTEST_H_

#pragma pack (push, 8)


#include "zacadstrc.h"
#include "zacestext.h"
#include "zacutasrt.h"

#if defined(_ZSOFT_WINDOWS_)
#include <tchar.h>
#endif

#ifdef NDEBUG


#define eOkTest(x) ((x) == Zcad::eOk)
#define eOkCheck(x) (x)
#define eOkVerify(x) ((x) == Zcad::eOk)


#else


inline Zcad::ErrorStatus eOkCheck_imp(
    const ZTCHAR *condition,
    const ZTCHAR *fname,
    int         lineno,
    Zcad::ErrorStatus es)
{
    if (es != Zcad::eOk) {
        zcutAssertMessage(condition, fname, lineno,
                          zcadErrorStatusText(es));
    }
    return es;
}

#define eOkTest(x) ((x) == Zcad::eOk)

#define eOkCheck(x) eOkCheck_imp(_T(# x), _T(__FILE__), __LINE__, (x))

#define eOkVerify(x) (eOkCheck(x) == Zcad::eOk)


#endif //NDEBUG


#pragma pack (pop)

#endif //_ZEOKTEST_H_
