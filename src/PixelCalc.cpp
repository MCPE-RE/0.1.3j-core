#include "PixelCalc.h"

PixelCalc::PixelCalc(float pixelsPerMillimeter) {
    this->setPixelsPerMillimeter(pixelsPerMillimeter);
}

float PixelCalc::millimetersToPixels(float millimeters) {
    return this->pixelsPerMillimeter * millimeters;
}

float PixelCalc::pixelsToMillimeters(float pixels) {
    return this->millimetersPerPixel * pixels;
}

void PixelCalc::setPixelsPerMillimeter(float pixelsPerMillimeter) {
    this->pixelsPerMillimeter = pixelsPerMillimeter;
    this->millimetersPerPixel = 1.0f / this->pixelsPerMillimeter;
}