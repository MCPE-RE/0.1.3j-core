#pragma once

#include "Material.h"

class GasMaterial : public Material {
public:
    bool blocksLight();

    bool blocksMotion();

    bool isSolid();
};