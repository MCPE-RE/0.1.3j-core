#ifndef RECTANGLEAREA_H_
#define RECTANGLEAREA_H_

#include "interfaces/IArea.h"

class RectangleArea : public IArea {
public:
    float x1;
    float x2;
    float y1;
    float y2;

    RectangleArea(const RectangleArea &area);

    RectangleArea(float x1, float y1, float x2, float y2);

    bool isInside(float x, float y);

    void operator=(const RectangleArea &area);
};

#endif