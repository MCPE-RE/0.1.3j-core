#include "SoundSystem.h"

void SoundSystem::enable(bool enable) {}

bool SoundSystem::isAvailable() {
    return false;
}

void SoundSystem::load(const std::string& name) {}

void SoundSystem::pause(const std::string& name) {}

void SoundSystem::play(const std::string& name) {}

void SoundSystem::playAt(const SoundDesc& desc, float x, float y, float z, float volume, float pitch) {}

void SoundSystem::setListenerAngle(float angle) {}

void SoundSystem::setListenerPos(float x, float y, float z) {}

void SoundSystem::stop(const std::string& name) {}