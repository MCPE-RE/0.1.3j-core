#include "ITouchScreenModel.h"

uint8_t ITouchScreenModel::getPointerId(const MouseAction *action) {
    return action->pointerId;
}

uint8_t ITouchScreenModel::getPointerId(int32_t x, int32_t y, int32_t id) {
    return id;
}