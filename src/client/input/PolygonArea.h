#pragma once

#include "interfaces/IArea.h"

class PolygonArea : public IArea {
public:
    float *vertexArrayX;
    float *vertexArrayY;
    int32_t vertexCount;

    PolygonArea(int32_t vertexCount, const float *vertexArrayX, const float *vertexArrayY);

    bool isInside(float x, float y);
};
