#pragma once

class SmoothFloat {
public:
    float value;
    float previousValue;
    float averageChange;

    SmoothFloat();

    float getNewDeltaValue(float change, float factor);
};
