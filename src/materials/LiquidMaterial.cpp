#include "LiquidMaterial.h"

bool LiquidMaterial::blocksMotion() {
    return false;
}

bool LiquidMaterial::isLiquid() {
    return true;
}

bool LiquidMaterial::isSolid() {
    return false;
}