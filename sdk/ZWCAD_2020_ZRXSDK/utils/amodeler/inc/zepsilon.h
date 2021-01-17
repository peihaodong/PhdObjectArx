#ifndef AECMODELER_INC_EPSILON_H
#define AECMODELER_INC_EPSILON_H

AECMODELER_NAMESPACE_BEGIN

class ZwInterval3d;

inline double ZwEpsAbs    () { return 1e-6;     }
inline double ZwEpsAbsSqrd() { return 1e-6; }

inline double ZwEpsNor    () { return 1e-6;     }
inline double ZwEpsNorSqrd() { return 1e-6; }

AECMODELER_NAMESPACE_END
#endif
