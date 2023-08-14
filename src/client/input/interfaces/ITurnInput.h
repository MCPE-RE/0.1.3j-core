#pragma once

#include <cstdint>
#include "../TurnDelta.h"

class ITurnInput {
public:
    float time;

    ITurnInput();

    virtual float getDeltaTime();

    static float linearTransform(float input_value, float threshold, float scale, float normalize);

    virtual void setScreenSize(int32_t width, int32_t height);

    virtual TurnDelta getTurnDelta() = 0;
};
