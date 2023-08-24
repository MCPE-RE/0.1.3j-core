#include "Tile.h"

Tile::SoundType::SoundType(const std::string& name, float volume, float pitch) {
    this->name = name;
    this->volume = volume;
    this->pitch = pitch;
}

std::string Tile::SoundType::getBreakSound() {
    return "step." + this->name;
}

float Tile::SoundType::getPitch() {
    return this->pitch;
}

std::string Tile::SoundType::getStepSound() {
    return "step." + this->name;
}

float Tile::SoundType::getVolume() {
    return this->volume;
}

Tile *Tile::tiles[256];
std::string Tile::TILE_DESCRIPTION_PREFIX = "tile.";
Tile::SoundType Tile::SOUND_NORMAL = Tile::SoundType("stone", 1.0f, 1.0f);
Tile::SoundType Tile::SOUND_WOOD = Tile::SoundType("wood", 1.0f, 1.0f);
Tile::SoundType Tile::SOUND_GRAVEL = Tile::SoundType("gravel", 1.0f, 1.0f);
Tile::SoundType Tile::SOUND_GRASS = Tile::SoundType("grass", 0.5f, 1.0f);
Tile::SoundType Tile::SOUND_STONE = Tile::SoundType("stone", 1.0f, 1.0f);
Tile::SoundType Tile::SOUND_METAL = Tile::SoundType("stone", 1.0f, 1.5f);
Tile::SoundType Tile::SOUND_GLASS = Tile::SoundType("stone", 1.0f, 1.0f);
Tile::SoundType Tile::SOUND_CLOTH = Tile::SoundType("cloth", 1.0f, 1.0f);
Tile::SoundType Tile::SOUND_SAND = Tile::SoundType("sand", 0.45f, 1.0f);
Tile::SoundType Tile::SOUND_SILENT = Tile::SoundType("", 0.0f, 0.0f);

Tile::Tile(int32_t resource, const Material *material) : aabb(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f) {
    this->texture = 1;
    this->resource = resource;
    this->minX = 0.0f;
    this->minY = 0.0f;
    this->minZ = 0.0f;
    this->maxX = 1.0f;
    this->maxY = 1.0f;
    this->maxZ = 1.0f;
    this->soundType = &Tile::SOUND_NORMAL;
    this->particleGravity = 1.0f;
    this->material = material;
    this->friction = 0.6f;
    this->descriptionId = "";
    if (Tile::tiles[this->resource]) {
        printf(
            "Slot %d is already occupied by %p when adding %p\n",
            this->resource,
            Tile::tiles[this->resource],
            this
        );
    }
}

Tile::Tile(int32_t resource, int32_t texture, const Material *material) : aabb(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f) {
    this->texture = texture;
    this->resource = resource;
    this->minX = 0.0f;
    this->minY = 0.0f;
    this->minZ = 0.0f;
    this->maxX = 1.0f;
    this->maxY = 1.0f;
    this->maxZ = 1.0f;
    this->soundType = &Tile::SOUND_NORMAL;
    this->particleGravity = 1.0f;
    this->material = material;
    this->friction = 0.6f;
    this->descriptionId = "";
    if (Tile::tiles[this->resource]) {
        printf(
            "Slot %d is already occupied by %p when adding %p\n",
            this->resource,
            Tile::tiles[this->resource],
            this
        );
    }
}