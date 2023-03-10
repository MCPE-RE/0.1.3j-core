#ifndef ITURNINPUT_H_
#define ITURNINPUT_H_

#include <cstdint>

class ITurnInput {
public:
    float time;

    ITurnInput();

    float getDeltaTime();

    static float linearTransform(float x, float y, float z, bool dbas);

    virtual void setScreenSize(int32_t width, int32_t height);

    virtual float getTurnDelta() = 0;
};

#endif