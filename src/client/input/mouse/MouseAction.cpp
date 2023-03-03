#include "MouseAction.h"

MouseAction::MouseAction(uint8_t button, uint8_t buttonState, uint16_t x, uint16_t y, uint8_t pointerId) {
    this->button = button;
    this->buttonState = buttonState;
    this->x = x;
    this->y = y;
    this->pointerId = pointerId;
}

bool MouseAction::isButton() {
    return this->button == 1 || this->button == 2;
}