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

float ITurnInput::linearTransform(float input_value, float threshold, float scale, float normalize) {
    if (input_value < 0.0) {
        threshold *= -1;
    }
    if (std::abs(threshold) >= std::abs(input_value)) {
        return 0.0f;
    }
    float result = (input_value - threshold) * scale;
    if (normalize && std::abs(result) > 1.0) {
        result /= std::abs(result);
    }
    return result;
}

void ITurnInput::setScreenSize(int32_t width, int32_t height) {}
