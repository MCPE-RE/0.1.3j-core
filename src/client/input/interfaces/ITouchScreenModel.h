#pragma once

#include <cstdint>
#include "../mouse/MouseAction.h"

class ITouchScreenModel {
public:
    virtual int32_t getPointerId(const MouseAction *action);

    virtual int32_t getPointerId(int32_t x, int32_t y, int32_t pointerId);
};
