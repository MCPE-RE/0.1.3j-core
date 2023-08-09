#include "IMoveInput.h"

IMoveInput::IMoveInput() {
    this->x = 0;
    this->y = 0;
    this->unknown0 = 0;
    this->unknown1 = 0;
    this->unknown2 = 0;
}

void IMoveInput::releaseAllKeys() {}

void IMoveInput::render(float unknown) {}

void IMoveInput::setKey(int32_t key, bool isPressed) {}

void IMoveInput::setScreenSize(int32_t width, int32_t height) {}

void IMoveInput::tick(void *player) {}