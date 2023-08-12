#include "PolygonArea.h"

PolygonArea::PolygonArea(int32_t vertexCount, const float *vertexArrayX, const float *vertexArrayY) {
    this->vertexCount = vertexCount;
    this->vertexArrayX = new float[vertexCount];
    this->vertexArrayY = new float[vertexCount];
    for (int32_t i = 0; i < vertexCount; ++i) {
        this->vertexArrayX[i] = vertexArrayX[i];
        this->vertexArrayY[i] = vertexArrayY[i];
    }
}

bool PolygonArea::isInside(float x, float y) {
    uint8_t result = 0;
    for (int32_t i = 0, j = this->vertexCount - 1; i < this->vertexCount; j=i++) {
        if ( ((this->vertexArrayY[i]) <= y && (this->vertexArrayY[j]) > y
            || this->vertexArrayY[j] <= y && this->vertexArrayY[i] > y)
            && ((((this->vertexArrayX[j]
                - this->vertexArrayX[i])
                * (y - this->vertexArrayY[i]))
                / (this->vertexArrayY[j] - this->vertexArrayY[i]))
                + this->vertexArrayX[i]) > x ) {
            result ^= 1u;
        }
    }
    return result;
}