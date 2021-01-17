#ifndef AECMODELER_INC_DEVIAT_H
#define AECMODELER_INC_DEVIAT_H

#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN


// Minimum and maximum approximation which the deviationToApprox() function
// may return.
//
const int kMinApprox = 4;
const int kMaxApprox = 128;

// Returns circle approximation (positive integer number) from a relative 
// deviation (0 < relDev < 1). The approximation is rounded up to the nearest 
// multiple of 4.
//
// The relative deviation is the maximum distance of the sides of a regular 
// n-sided polygon, inscribed into a unit circle, from the circle. The function
// deviationToApprox() returns the number "n" for which this distance is equal
// or smaller than the required "relDev".
//
DllImpExp int ZwDeviationToApprox(double relDev);


AECMODELER_NAMESPACE_END
#endif

