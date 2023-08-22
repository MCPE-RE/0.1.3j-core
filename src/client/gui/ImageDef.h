#pragma once

#include <iostream>
#include "IntRectangle.h"

class ImageDef {
public:
    std::string name; // 0
    int32_t x; // 24
    int32_t y; // 28
    float width; // 32
    float height; // 36
    IntRectangle rect; // 40
    bool doRender; // 56

    ImageDef(const ImageDef& imageDef);

    ImageDef();

    void operator=(const ImageDef& imageDef);
};