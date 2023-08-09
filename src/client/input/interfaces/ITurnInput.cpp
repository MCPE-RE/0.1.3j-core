#include "ITurnInput.h"
#include "../../../MCTime.h"
#include <iostream>

ITurnInput::ITurnInput() {
    this->time = -1.0f;
}

float ITurnInput::getDeltaTime() {
    if (this->time == -1.0) {
        this->time = getTimeS();
    }
    float timeNow = getTimeS();
    float deltaTime = timeNow - this->time;
    this->time = timeNow;
    return deltaTime;
}

float ITurnInput::linearTransform(float x, float y, float z, bool dbas) {
    if (x < 0.0) {
        y *= -1;
    }
    if (std::abs(y) >= std::abs(x)) {
        return 0.0f;
    }
    float result = (x - y) * z;
    if (dbas && std::abs(result) > 1.0) {
        result /= std::abs(result);
    }
    return result;
}

void ITurnInput::setScreenSize(int32_t width, int32_t height) {}
