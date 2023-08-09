#ifndef ITOUCHSCREENMODEL_H_
#define ITOUCHSCREENMODEL_H_

#include <cstdint>
#include "../mouse/MouseAction.h"

class ITouchScreenModel {
public:
    virtual uint8_t getPointerId(const MouseAction *action);

    virtual uint8_t getPointerId(int32_t x, int32_t y, int32_t id);
};

#endif
