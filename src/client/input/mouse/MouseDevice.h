#ifndef MOUSEDEVICE_H_
#define MOUSEDEVICE_H_

#include <cstdint>
#include "MouseAction.h"

class MouseDevice {
public:
    MouseDevice();

    void feed(uint8_t button, uint8_t type, uint16_t x, uint16_t y);

    uint8_t getButtonState(uint32_t button) {}

    MouseAction *getEvent();

    
};

#endif