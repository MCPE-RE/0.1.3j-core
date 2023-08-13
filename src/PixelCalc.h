#pragma once

class PixelCalc {
public:
    float pixelsPerMillimeter;
    float millimetersPerPixel;

    PixelCalc(float pixelsPerMillimeter);

    float millimetersToPixels(float millimeters);

    float pixelsToMillimeters(float pixels);

    void setPixelsPerMillimeter(float pixelsPerMillimeter);
};
