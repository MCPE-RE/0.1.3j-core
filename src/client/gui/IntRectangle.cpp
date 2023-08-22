#include "IntRectangle.h"

IntRectangle::IntRectangle(int32_t minX, int32_t minY, int32_t maxX, int32_t maxY) {
    this->minX = minX;
    this->minY = minY;
    this->maxX = maxX;
    this->maxY = maxY;
}

IntRectangle::IntRectangle() {
    this->minX = 0;
    this->minY = 0;
    this->maxX = 1;
    this->maxY = 1;
}