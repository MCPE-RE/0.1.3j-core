#pragma once

#include "Material.h"

class DecorationMaterial : public Material {
public:
    bool blocksLight();

    bool blocksMotion();

    bool isSolid();
};