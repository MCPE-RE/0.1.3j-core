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