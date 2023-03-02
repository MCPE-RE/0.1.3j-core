#ifndef MOUSEACTION_H_
#define MOUSEACTION_H_

#include <cstdint>

class MouseAction {
public:
    uint16_t x;
    uint16_t y;
    uint8_t button;
    uint8_t type;
    uint8_t pointerId;

    MouseAction(uint8_t button, uint8_t type, uint16_t x, uint16_t y, uint8_t pointerId);

    bool isButton();
};

#endif