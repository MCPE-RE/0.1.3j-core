#include "ClothTile.h"

ClothTile::ClothTile(int32_t resource, int32_t type) : Tile(resource, 64, Material::cloth) {
    this->type = type;
    this->texture = this->getTexture(0);
}

ClothTile::ClothTile(int32_t type) : Tile(35, 64, Material::cloth) {
    this->type = type;
    this->texture = this->getTexture(0);
}

int32_t ClothTile::getSpawnResourcesAuxValue(int32_t auxValue) {
    return auxValue;
}

int32_t ClothTile::getTexture(int32_t face, int32_t data) {
    return 16 * (~(this->type & 0xF) & 7) + ((~(this->type & 0xF) & 8) >> 3) + 113;
}

int32_t ClothTile::getTexture(int32_t face) {
    return this->getTexture(face, this->type);
}