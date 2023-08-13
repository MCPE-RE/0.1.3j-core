#pragma once

#include <cstdint>

class Textures;

class DynamicTexture {
public:
    int32_t tileSideSize;
    int32_t tileCount;
    uint8_t data[0x400];

    DynamicTexture(int32_t tileSideSize);

    virtual void tick() = 0;

    void bindTexture(Textures *textures);
};
