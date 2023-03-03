#include "MouseDevice.h"

MouseDevice::MouseDevice() {
    this->eventIndex = -1;
    this->x = 0;
    this->y = 0;
    this->oldX = 0;
    this->oldY = 0;
    for (int i = 0; i < 4; ++i) {
        this->states[i] = false;
    }
}

void MouseDevice::feed(uint8_t button, bool state, uint16_t x, uint16_t y) {
    this->events.push_back(MouseAction(button, state, x, y, 0));
    if (button) {
        this->states[button] = state;
    }
    this->oldX = this->x;
    this->oldY = this->y;
    this->x = x;
    this->y = y;
}