#include "IInputHolder.h"
#include "../mouse/Mouse.h"

IInputHolder::IInputHolder() {
    this->x = 0;
    this->y = 0;
}

bool IInputHolder::allowPicking() {
    this->x = (float)Mouse::getX();
    this->y = (float)Mouse::getY();
    return Mouse::getButtonState(1) == 1;
}

void IInputHolder::setScreenSize(int32_t width, int32_t height) {
    this->getMoveInput()->setScreenSize(width, height);
    this->getTurnInput()->setScreenSize(width, height);
    this->getBuildInput()->setScreenSize(width, height);
}