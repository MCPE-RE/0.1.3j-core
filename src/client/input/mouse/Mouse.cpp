#include "Mouse.h"

void Mouse::feed(uint8_t button, uint8_t buttonState, uint16_t x, uint16_t y) {
    Mouse::_instance.feed(button, buttonState, x, y);
}

uint8_t Mouse::getButtonState(uint32_t button) {
    return Mouse::_instance.getButtonState(button);
}

MouseAction *Mouse::getEvent() {
    return Mouse::_instance.getEvent();
}

uint8_t Mouse::getEventButton() {
    return Mouse::_instance.getEventButton();
}

bool Mouse::getEventButtonState() {
    return Mouse::_instance.getEventButtonState();
}

uint16_t Mouse::getX() {
    return Mouse::_instance.getX();
}

uint16_t Mouse::getY() {
    return Mouse::_instance.getY();
}

bool Mouse::isButtonDown(uint32_t button) {
    return Mouse::_instance.isButtonDown(button);
}

bool Mouse::next() {
    return Mouse::_instance.next();
}

void Mouse::reset() {
    Mouse::_instance.reset();
}

void Mouse::reset2() {
    Mouse::_instance..reset2();
}