#ifndef SMOOTHFLOAT_H_
#define SMOOTHFLOAT_H_

class SmoothFloat {
public:
    float value;
    float previousValue;
    float averageChange;

    SmoothFloat();

    float getNewDeltaValue(float change, float factor);
};

#endif