#pragma once

#include <cstdint>

class DecorationMaterial;
class GasMaterial;
class LiquidMaterial;

class Material {
public:
    static GasMaterial *air;
    static Material *dirt;
    static Material *wood;
    static Material *stone;
    static Material *metal;
    static LiquidMaterial *water;
    static LiquidMaterial *lava;
    static Material *leaves;
    static DecorationMaterial *plant;
    static Material *sponge;
    static Material *cloth;
    static GasMaterial *fire;
    static Material *sand;
    static DecorationMaterial *decoration;
    static Material *glass;
    static Material *explosive;
    static Material *coral;
    static Material *ice;
    static DecorationMaterial *topSnow;
    static Material *snow;
    static Material *cactus;
    static Material *clay;
    static Material *vegetable;
    static Material *portal;
    static Material *cake;

    bool burnable;

    Material();

    virtual bool blocksLight();

    virtual bool blocksMotion();

    Material *flammable();

    static void initMaterials();

    virtual bool isFlammable();

    virtual bool isLiquid();

    virtual bool isSolid();

    virtual bool letsWaterThrough();

    static void teardownMaterials();
};