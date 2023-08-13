#pragma once

#include <cstdint>

class MouseAction {
public:
    uint16_t x;
    uint16_t y;
    uint8_t button;
    uint8_t buttonState;
    uint8_t pointerId;

    MouseAction(uint8_t button, uint8_t buttonState, uint16_t x, uint16_t y, uint8_t pointerId);

    bool isButton();
};
