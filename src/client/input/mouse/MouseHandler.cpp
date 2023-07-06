#include "MouseHandler.h"
#include <cstddef>

MouseHandler::MouseHandler() {
    this->turnInput = NULL;
}

void MouseHandler::grab() {
    this->turnDelta = 0.0f;
    this->unknown1 = 0;
}

void MouseHandler::poll() {
    if (this->turnInput) {
        this->turnDelta = this->turnInput->getTurnDelta();
        this->unknown1 = 0;
    }
}

void MouseHandler::release() {}

void MouseHandler::setTurnInput(ITurnInput *turnInput) {
    this->turnInput = turnInput;
}