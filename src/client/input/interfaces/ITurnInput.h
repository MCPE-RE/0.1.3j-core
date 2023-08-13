#pragma once

#include <cstdint>

class ITurnInput {
public:
    float time;

    ITurnInput();

    virtual float getDeltaTime();

    static float linearTransform(float x, float y, float z, bool dbas);

    virtual void setScreenSize(int32_t width, int32_t height);

    virtual float getTurnDelta() = 0;
};
