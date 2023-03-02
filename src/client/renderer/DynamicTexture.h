#ifndef DYNAMICTEXTURE_H_
#define DYNAMICTEXTURE_H_

#include <cstdint>

class Textures;

class DynamicTexture {
public:
    int32_t tileSideSize;
    int32_t tileCount;
    uint8_t data[0x400];

    DynamicTexture(int32_t tileSideSize);

    virtual void tick();

    void bindTexture(Textures *textures);
};

#endif