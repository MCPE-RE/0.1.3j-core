#include "SmoothFloat.h"

SmoothFloat::SmoothFloat() {
    this->value = 0.0f;
    this->previousValue = 0.0f;
    this->averageChange = 0.0f;
}

float SmoothFloat::getNewDeltaValue(float change, float factor) {
    this->value += change;
    float delta = (this->value - this->previousValue) * factor;
    this->averageChange += (delta - this->averageChange) * 0.5;
    if ((delta > 0.0f && this->averageChange < delta) || (delta < 0.0f && this->averageChange > delta)) {
        delta = this->averageChange;
    }
    this->previousValue += delta;
    return delta;
}