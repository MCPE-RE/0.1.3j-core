#pragma once

#include <cstdint>
#include "material/Material.h"

class LevelSource {
public:
    virtual uint8_t getTile(int32_t x, int32_t y, int32_t z) = 0;

    virtual float getBrightness(int32_t x, int32_t y, int32_t z) = 0;

    virtual int32_t getData(int32_t x, int32_t y, int32_t z) = 0;

    virtual Material *getMaterial(int32_t x, int32_t y, int32_t z) = 0;

    virtual bool isSolidTile(int32_t x, int32_t y, int32_t z) = 0;
};