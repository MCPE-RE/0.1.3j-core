#include "Multitouch.h"
#include <cmath>

int32_t Multitouch::_clampPointerId(int32_t pointerId) {
    if ((-1 < pointerId) && (0xb < pointerId)) {
        return 11;
    }
    return pointerId;
}

void Multitouch::commit() {
    Multitouch::_activePointerCount = 0;
    for (int32_t i = 0; i < 12; ++i ) {
        if (Multitouch::_pointers[i].isButtonDown(1)) {
            Multitouch::_activePointerList[Multitouch::_activePointerCount++] = i;
        }
    }
}

void Multitouch::feed(uint8_t button, uint8_t buttonState, uint16_t x, uint16_t y, uint8_t pointerId) {
    int32_t clampedPointerId = Multitouch::_clampPointerId(pointerId);
    Multitouch::_inputs.push_back(MouseAction(button, buttonState, x, y, clampedPointerId));
    Multitouch::g(clampedPointerId)->feed(button, buttonState, x, y);
    if (button) {
        if (buttonState == 1) {
            Multitouch::_wasPressed[clampedPointerId] = 1;
            Multitouch::_wasPressedThisUpdate[clampedPointerId] = 1;
        } else if (buttonState == 0) {
            Multitouch::_wasReleased[clampedPointerId] = 1;
            Multitouch::_wasReleasedThisUpdate[clampedPointerId] = 1;
        }
    }
}
    
MouseDevice *Multitouch::g(int32_t pointerId) {
    return &Multitouch::_pointers[Multitouch::_clampPointerId(pointerId)];
}

int32_t Multitouch::getActivePointerIds(int32_t **pPointers) {
    *pPointers = Multitouch::_activePointerList;
    return Multitouch::_activePointerCount;
}

MouseAction *Multitouch::getEvent() {
    return &Multitouch::_inputs[Multitouch::_index];
}

int32_t Multitouch::getFirstActivePointerIdEx() {
    for (int32_t i = 0; i < 12; ++i ) {
        if (Multitouch::_pointers[i].isButtonDown(1)) {
            return i;
        }
    }
    for (int32_t i = 0; i < 12; ++i ) {
        if (Multitouch::_wasReleased[i]) {
            return i;
        }
    }
    return -1;
}

int32_t Multitouch::getFirstActivePointerIdExThisUpdate() {
    for (int32_t i = 0; i < 12; ++i ) {
        if (Multitouch::_pointers[i].isButtonDown(1)) {
            return i;
        }
    }
    for (int32_t i = 0; i < 12; ++i ) {
        if (Multitouch::_wasReleasedThisUpdate[i]) {
            return i;
        }
    }
    return -1;
}

int16_t Multitouch::getX(int32_t pointerId) {
    return Multitouch::g(pointerId)->getX();
}

int16_t Multitouch::getY(int32_t pointerId) {
    return Multitouch::g(pointerId)->getY();
}

bool Multitouch::isPressed(int32_t pointerId) {
    return Multitouch::_wasPressed[Multitouch::_clampPointerId(pointerId)];
}

bool Multitouch::next() {
    if (Multitouch::_index + 1 >= Multitouch::_inputs.size()) {
        return false;
    }
    ++Multitouch::_index;
    return true;
}

void Multitouch::reset() {
    Multitouch::_inputs.clear();
    Multitouch::_index = -1;

    for (int32_t i = 0; i < 12; ++i) {
        Multitouch::g(i)->reset();
        Multitouch::_wasPressed[i] = 0;
        Multitouch::_wasReleased[i] = 0;
    }
}

void Multitouch::resetThisUpdate() {
    for (int32_t i = 0; i < 12; ++i) {
        Multitouch::_wasPressedThisUpdate[i] = 0;
        Multitouch::_wasReleasedThisUpdate[i] = 0;
    }
}

void Multitouch::rewind() {
    Multitouch::_index = -1;
}