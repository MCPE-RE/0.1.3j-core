#include "RectangleArea.h"

RectangleArea::RectangleArea(const RectangleArea &area) {
    this->x1 = area.x1;
    this->x2 = area.x2;
    this->y1 = area.y1;
    this->y2 = area.y2;
}

RectangleArea::RectangleArea(float x1, float y1, float x2, float y2) {
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
}

bool RectangleArea::isInside(float x, float y) {
    return this->x1 <= x && this->x2 >= x && this->y1 <= y && this->y2 >= y;
}

void RectangleArea::operator=(const RectangleArea &area) {
    IArea::operator=(area);
    this->x1 = area.x1;
    this->x2 = area.x2;
    this->y1 = area.y1;
    this->y2 = area.y2;
}