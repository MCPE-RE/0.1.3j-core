#ifndef PIXELCALC_H_
#define PIXELCALC_H_

class PixelCalc {
public:
    float pixelsPerMillimeter;
    float millimetersPerPixel;

    PixelCalc(float pixelsPerMillimeter);

    float millimetersToPixels(float millimeters);

    float pixelsToMillimeters(float pixels);

    void setPixelsPerMillimeter(float pixelsPerMillimeter);
};

#endif