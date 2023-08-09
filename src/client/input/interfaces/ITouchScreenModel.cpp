#include "ITouchScreenModel.h"

int32_t ITouchScreenModel::getPointerId(const MouseAction *action) {
    return action->pointerId;
}

int32_t ITouchScreenModel::getPointerId(int32_t x, int32_t y, int32_t pointerId) {
    return pointerId;
}