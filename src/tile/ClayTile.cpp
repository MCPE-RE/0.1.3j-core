#include "ClayTile.h"

ClayTile::ClayTile(int32_t resource, int32_t texture) : Tile(resource, texture, Material::clay) {}

int32_t ClayTile::getResourceCount(Random *random) {
    return 4;
}

int32_t ClayTile::getResource(int32_t data, Random *random) {
    return 0;
}