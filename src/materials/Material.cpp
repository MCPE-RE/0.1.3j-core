#include "Material.h"
#include "DecorationMaterial.h"
#include "GasMaterial.h"
#include "LiquidMaterial.h"

GasMaterial *Material::air = nullptr;
Material *Material::dirt = nullptr;
Material *Material::wood = nullptr;
Material *Material::stone = nullptr;
Material *Material::metal = nullptr;
LiquidMaterial *Material::water = nullptr;
LiquidMaterial *Material::lava = nullptr;
Material *Material::leaves = nullptr;
DecorationMaterial *Material::plant = nullptr;
Material *Material::sponge = nullptr;
Material *Material::cloth = nullptr;
GasMaterial *Material::fire = nullptr;
Material *Material::sand = nullptr;
DecorationMaterial *Material::decoration = nullptr;
Material *Material::glass = nullptr;
Material *Material::explosive = nullptr;
Material *Material::coral = nullptr;
Material *Material::ice = nullptr;
DecorationMaterial *Material::topSnow = nullptr;
Material *Material::snow = nullptr;
Material *Material::cactus = nullptr;
Material *Material::clay = nullptr;
Material *Material::vegetable = nullptr;
Material *Material::portal = nullptr;
Material *Material::cake = nullptr;

Material::Material() {
    this->burnable = false;
}

bool Material::blocksLight() {
    return true;
}

bool Material::blocksMotion() {
    return true;
}

Material *Material::flammable() {
    this->burnable = true;
    return this;
}

void Material::initMaterials() {
    Material::air = new GasMaterial();
    Material::dirt = new Material();
    Material::wood = (new Material())->flammable();
    Material::stone = new Material();
    Material::metal = new Material();
    Material::water = new LiquidMaterial();
    Material::lava = new LiquidMaterial();
    Material::leaves = (new Material())->flammable();
    Material::plant = new DecorationMaterial();
    Material::sponge = new Material();
    Material::cloth = (new Material())->flammable();
    Material::fire = new GasMaterial();
    Material::sand = new Material();
    Material::decoration = new DecorationMaterial();
    Material::glass = new Material();
    Material::explosive = (new Material())->flammable();
    Material::coral = new Material();
    Material::ice = new Material();
    Material::topSnow = new DecorationMaterial();
    Material::snow = new Material();
    Material::cactus = new Material();
    Material::clay = new Material();
    Material::vegetable = new Material();
    Material::portal = new Material();
    Material::cake = new Material();
}

bool Material::isFlammable() {
    return this->burnable;
}

bool Material::isLiquid() {
    return false;
}

bool Material::isSolid() {
    return true;
}

bool Material::letsWaterThrough() {
    return !this->isLiquid() && !this->isSolid();
}

void Material::teardownMaterials() {
    if (Material::air) {
        delete Material::air;
    }
    if (Material::dirt) {
        delete Material::dirt;
    }
    if (Material::wood) {
        delete Material::wood;
    }
    if (Material::stone) {
        delete Material::stone;
    }
    if (Material::metal) {
        delete Material::metal;
    }
    if (Material::water) {
        delete Material::water;
    }
    if (Material::lava) {
        delete Material::lava;
    }
    if (Material::leaves) {
        delete Material::leaves;
    }
    if (Material::plant) {
        delete Material::plant;
    }
    if (Material::sponge) {
        delete Material::sponge;
    }
    if (Material::cloth) {
        delete Material::cloth;
    }
    if (Material::fire) {
        delete Material::fire;
    }
    if (Material::sand) {
        delete Material::sand;
    }
    if (Material::decoration) {
        delete Material::decoration;
    }
    if (Material::glass) {
        delete Material::glass;
    }
    if (Material::explosive) {
        delete Material::explosive;
    }
    if (Material::coral) {
        delete Material::coral;
    }
    if (Material::ice) {
        delete Material::ice;
    }
    if (Material::topSnow) {
        delete Material::topSnow;
    }
    if (Material::snow) {
        delete Material::snow;
    }
    if (Material::cactus) {
        delete Material::cactus;
    }
    if (Material::clay) {
        delete Material::clay;
    }
    if (Material::vegetable) {
        delete Material::vegetable;
    }
    if (Material::portal) {
        delete Material::portal;
    }
    if (Material::cake) {
        delete Material::cake;
    }
}