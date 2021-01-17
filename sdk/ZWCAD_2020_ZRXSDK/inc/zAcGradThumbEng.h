

#ifndef     _ZCGRADTHUMB_H
#define     _ZCGRADTHUMB_H

#include "zdbcolor.h"

class CZcGradientThumbnailEngine
{
    public:
        virtual ~CZcGradientThumbnailEngine() {};

        virtual Zcad::ErrorStatus gradientThumbnailsSetRotation( double angle ) = 0;
        virtual Zcad::ErrorStatus gradientThumbnailsSetShift( bool bShifted ) = 0;
        virtual Zcad::ErrorStatus gradientThumbnailsSetStartColor( ZcCmEntityColor startColor ) = 0;
        virtual Zcad::ErrorStatus gradientThumbnailsSetStopColor( ZcCmEntityColor stopColor ) = 0;

        virtual Zcad::ErrorStatus gradientThumbnailsRender(void) = 0;
        virtual Zcad::ErrorStatus gradientThumbnailsDrawBitmap( int gradientNumber, HDC hDC, int xPos, int yPos ) = 0;

};

CZcGradientThumbnailEngine *createGradientThumbnailEngine();

#endif 
