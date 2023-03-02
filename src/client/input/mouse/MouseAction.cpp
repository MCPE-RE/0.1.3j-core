#include "MouseAction.h"

MouseAction::MouseAction(uint8_t button, uint8_t type, uint16_t x, uint16_t y, uint8_t pointerId) {
    this->button = button;
    this->type = type;
    this->x = x;
    this->y = y;
    this->pointerId = pointerId;
}

bool MouseAction::isButton() {
    return button == 1 || button == 2;
}