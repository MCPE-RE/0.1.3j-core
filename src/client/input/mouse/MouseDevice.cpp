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