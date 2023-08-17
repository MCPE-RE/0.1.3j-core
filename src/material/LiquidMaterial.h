#pragma once

#include "Material.h"

class LiquidMaterial {
public:
    bool blocksMotion();

    bool isLiquid();

    bool isSolid();
};