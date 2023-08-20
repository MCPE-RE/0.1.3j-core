#include "MouseDevice.h"

MouseDevice::MouseDevice() {
    this->eventIndex = -1;
    this->x = 0;
    this->y = 0;
    this->oldX = 0;
    this->oldY = 0;
    for (int i = 0; i < 4; ++i) {
        this->buttonStates[i] = 0;
    }
}

void MouseDevice::feed(uint8_t button, uint8_t buttonState, uint16_t x, uint16_t y) {
    this->events.push_back(MouseAction(button, buttonState, x, y, 0));
    if (button) {
        this->buttonStates[button] = buttonState;
    }
    this->oldX = this->x;
    this->oldY = this->y;
    this->x = x;
    this->y = y;
}

uint8_t MouseDevice::getButtonState(uint32_t button) {
    if (button > 0 && button < 4) {
        return this->buttonStates[button];
    }
    return 0;
}

MouseAction *MouseDevice::getEvent() {
    return &this->events[this->eventIndex];
}

uint8_t MouseDevice::getEventButton() {
    return this->events[this->eventIndex].button;
}

bool MouseDevice::getEventButtonState() {
    return this->events[this->eventIndex].buttonState == 1;
}

uint16_t MouseDevice::getX() {
    return this->x;
}

uint16_t MouseDevice::getY() {
    return this->y;
}

bool MouseDevice::isButtonDown(uint32_t button) {
    return this->getButtonState(button) != 0;
}

bool MouseDevice::next() {
    if ((this->eventIndex + 1) >= this->events.size()) {
        return false;
    }
    ++this->eventIndex;
    return true;
}

void MouseDevice::reset() {
    this->eventIndex = -1;
    this->events.clear();
    this->buttonStates[3] = 0;
}

void MouseDevice::reset2() {
    this->oldX = this->x;
    this->oldY = this->y;
}