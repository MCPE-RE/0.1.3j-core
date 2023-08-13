#pragma once

#include <cstdint>

class IMoveInput {
public:
    int32_t x;
    int32_t y;
    uint8_t unknown1;
    uint8_t unknown2;
    uint8_t unknown3;

    IMoveInput();

    virtual void releaseAllKeys();

    virtual void render(float unknown);

    virtual void setKey(int32_t key, bool isPressed);

    virtual void setScreenSize(int32_t width, int32_t height);

    virtual void tick(void *player);
};
