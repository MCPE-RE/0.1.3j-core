#include "LevelListener.h"

LevelListener::LevelListener() {}

void LevelListener::tileChanged(uint32_t x, uint32_t y, uint32_t z) {}

void LevelListener::tileBrightnessChanged(uint32_t x, uint32_t y, uint32_t z) {
	this->tileChanged(x, y, z);
}

void LevelListener::setTilesDirty(uint32_t unknown0, uint32_t unknown1, uint32_t unknown2, uint32_t unknown3, uint32_t unknown4, uint32_t unknown5) {}

void LevelListener::allChanged() {}

void LevelListener::playSound(const std::string& name, float unknown0, float unknown1, float unknown2, float unknown3, float unknown4) {}

void LevelListener::takePicture(void *camera, void *entity) {}

void LevelListener::addParticle(const std::string& name, float unknown0, float unknown1, float unknown2, float unknown3, float unknown4, float unknown5) {}

void LevelListener::playMusic(const std::string& name, float unknown0, float unknown1, float unknown2, float unknown3) {}

void LevelListener::entityAdded(void *entity) {}

void LevelListener::skyColorChanged() {}

void LevelListener::playStreamingMusic(const std::string& name, uint32_t unknown0, uint32_t unknown1, uint32_t unknown2) {}
