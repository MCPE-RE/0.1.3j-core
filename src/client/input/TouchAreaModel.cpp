#include "TouchAreaModel.h"
#include <cstdlib>

void TouchAreaModel::addArea(int32_t pointerId, IArea *area) {
    TouchAreaModel::Area *areaStruct = new TouchAreaModel::Area();
    areaStruct->area = area;
    areaStruct->pointerId = pointerId;
    this->areas.push_back(areaStruct);
}

void TouchAreaModel::clear() {
    for (size_t i = 0; i < this->areas.size(); ++i) {
        TouchAreaModel::Area *area = this->areas[i];
        if (area && area->area && area->area->isDeletable) {
            delete area->area;
        }
        delete area;
    }
    this->areas.clear();
}

int32_t TouchAreaModel::getPointerId(const MouseAction *action) {
    return this->getPointerId(action->x, action->y, action->pointerId);
}

int32_t TouchAreaModel::getPointerId(int32_t x, int32_t y, int32_t pointerId) {
    for (size_t i = 0; i < this->areas.size(); ++i) {
        TouchAreaModel::Area *area = this->areas[i];
        if (area->area->isInside((float)x, (float)y)) {
            return area->pointerId;
        }
    }
    return pointerId;
}