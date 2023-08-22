#pragma once

#include <cstdint>

class IntRectangle {
public:
    int32_t minX;
    int32_t minY;
    int32_t maxX;
    int32_t maxY;

    IntRectangle(int32_t minX, int32_t minY, int32_t maxX, int32_t maxY);

    IntRectangle();
};