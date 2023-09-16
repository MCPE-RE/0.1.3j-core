#include "CactusTile.h"

CactusTile::CactusTile(int32_t resource, int32_t texture) : Tile(resource, texture, Material::cactus) {
    this->setTicking(true);
}

bool CactusTile::canSurvive(Level *level, int32_t x, int32_t y, int32_t z) {
    if (level->getMaterial(x - 1, y, z)->isLiquid()) {
        return false;
    }
    if (level->getMaterial(x + 1, y, z)->isLiquid()) {
        return false;
    }
    if (level->getMaterial(x, y, z - 1)->isLiquid()) {
        return false;
    }
    if (level->getMaterial(x, y, z + 1)->isLiquid()) {
        return false;
    }
    int32_t lowerBlockResource = level->getTile(x, y - 1, z);
    return Tile::cactus->resource == lowerBlockResource || Tile::sand->resource == lowerBlockResource;
}

void CactusTile::entityInside(Level *level, int32_t x, int32_t y, int32_t z, Entity *entity) {
    //entity->hurt(nullptr, 1);
}

AABB *CactusTile::getAABB(Level *level, int32_t x, int32_t y, int32_t z) {
    this->aabb.minX = (float)x + 0.0625f;
    this->aabb.minY = (float)y;
    this->aabb.minZ = (float)z + 0.0625f;
    this->aabb.maxX = (float)(x + 1) - 0.0625f;
    this->aabb.maxY = (float)(y + 1) - 0.0625f;
    this->aabb.maxZ = (float)(z + 1) - 0.0625f;
    return &this->aabb;
}

int32_t CactusTile::getRenderLayer() {
    return 1;
}

int32_t CactusTile::getRenderShape() {
    return 13;
}

int32_t CactusTile::getTexture(int32_t face) {
    if (face == 1) {
        return this->texture - 1;
    }
    if (face) {
        return this->texture;
    }
    return this->texture + 1;
}

AABB CactusTile::getTileAABB(Level *level, int32_t x, int32_t y, int32_t z) {
    return AABB::AABB(
        (float)x + 0.0625f,
        (float)y,
        (float)z + 0.0625f,
        (float)(x + 1) - 0.0625f,
        (float)(y + 1),
        (float)(z + 1) - 0.0625f
    );
}

bool CactusTile::isCubeShaped() {
    return false;
}

bool CactusTile::isSolidRender() {
    return false;
}

bool CactusTile::mayPlace(Level *level, int32_t x, int32_t y, int32_t z) {
    if (!Tile::mayPlace(level, x, y, z)) {
        return false;
    }
    return this->canSurvive(level, x, y, z);
}

void CactusTile::neighborChanged(Level *level, int32_t x, int32_t y, int32_t z, int32_t face) {
    if (!this->canSurvive(level, x, y, z)) {
        this->spawnResources(level, x, y, z, level->getData(x, y, z), 0.0f);
        //level->setTile(x, y, z, 0);
    }
}

void CactusTile::tick(Level *level, int32_t x, int32_t y, int32_t z, Random *random) {
    //if (level->isEmptyTile(x, y + 1, z)) {
        int32_t i = 1;
        while (level->getTile(x, y - i, z) == this->resource) {
            ++i;
        }
        if (i <= 2) {
            int32_t data = level->getData(x, y, z);
            if (data == 15) {
                //level->setTile(x, y + 1, z, this->resource);
                //level->setData(x, y, z, 0);
            } else {
                //level->setData(x, y, z, data + 1);
            }
        }
    //}
}