#include "MouseHandler.h"
#include <cstddef>
#include "../TurnDelta.h"

MouseHandler::MouseHandler() {
    this->turnInput = NULL;
}

void MouseHandler::grab() {
    this->dx = 0.0f;
    this->dy = 0.0f;
}

void MouseHandler::poll() {
    if (this->turnInput) {
        TurnDelta turnDelta = this->turnInput->getTurnDelta();
        this->dx = turnDelta.dx;
        this->dy = turnDelta.dy;
    }
}

void MouseHandler::release() {}

void MouseHandler::setTurnInput(ITurnInput *turnInput) {
    this->turnInput = turnInput;
}