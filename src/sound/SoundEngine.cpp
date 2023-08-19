#include "SoundEngine.h"
#include "../math/Mth.h"
#include "SoundDesc.h"
#include "../Minecraft.h"

/*
SoundDesc SA_cloth1 = SoundDesc(PCM_cloth1);
SoundDesc SA_cloth2 = SoundDesc(PCM_cloth2);
SoundDesc SA_cloth3 = SoundDesc(PCM_cloth3);
SoundDesc SA_cloth4 = SoundDesc(PCM_cloth4);
SoundDesc SA_grass1 = SoundDesc(PCM_grass1);
SoundDesc SA_grass2 = SoundDesc(PCM_grass2);
SoundDesc SA_grass3 = SoundDesc(PCM_grass3);
SoundDesc SA_grass4 = SoundDesc(PCM_grass4);
SoundDesc SA_gravel1 = SoundDesc(PCM_gravel1);
SoundDesc SA_gravel2 = SoundDesc(PCM_gravel2);
SoundDesc SA_gravel3 = SoundDesc(PCM_gravel3);
SoundDesc SA_gravel4 = SoundDesc(PCM_gravel4);
SoundDesc SA_sand1 = SoundDesc(PCM_sand1);
SoundDesc SA_sand2 = SoundDesc(PCM_sand2);
SoundDesc SA_sand3 = SoundDesc(PCM_sand3);
SoundDesc SA_sand4 = SoundDesc(PCM_sand4);
SoundDesc SA_stone1 = SoundDesc(PCM_stone1);
SoundDesc SA_stone2 = SoundDesc(PCM_stone2);
SoundDesc SA_stone3 = SoundDesc(PCM_stone3);
SoundDesc SA_stone4 = SoundDesc(PCM_stone4);
SoundDesc SA_wood1 = SoundDesc(PCM_wood1);
SoundDesc SA_wood2 = SoundDesc(PCM_wood2);
SoundDesc SA_wood3 = SoundDesc(PCM_wood3);
SoundDesc SA_wood4 = SoundDesc(PCM_wood4);
SoundDesc SA_splash = SoundDesc(PCM_splash);
SoundDesc SA_explode = SoundDesc(PCM_explode);
SoundDesc SA_click = SoundDesc(PCM_click);
*/

SoundEngine::SoundEngine(float volumeStepCount) {
    this->unknown_4 = 0;
    this->posX = 0.0f;
    this->posY = 0.0f;
    this->posZ = 0.0f;
    this->rotationPitch = 0.0f;
    this->volumeStep = 1.0f / volumeStepCount;
    this->minecraft = nullptr;
}

float SoundEngine::_getVolumeMult(float x, float y, float z) {
    float xx = (x - this->posX) * (x - this->posX);
    float yy = (y - this->posY) * (y - this->posY);
    float zz = (z - this->posZ) * (z - this->posZ);
    float s = Mth::sqrt(xx + yy + zz);
    return Mth::clamp(1.1f - (this->volumeStep * s), -1.0f, 1.0);
}

void SoundEngine::enable(bool state) {}

void SoundEngine::init(Minecraft *minecraft, Options *options) {
    this->minecraft = minecraft;
    this->options = options;
    if (!options || options->soundVolume != 0.0f || options->musicVolume != 0.0f) {
        this->loadLibrary();
    }
    /*
    this->repository.add("step.cloth", SA_cloth1);
    this->repository.add("step.cloth", SA_cloth2);
    this->repository.add("step.cloth", SA_cloth3);
    this->repository.add("step.cloth", SA_cloth4);
    this->repository.add("step.grass", SA_grass1);
    this->repository.add("step.grass", SA_grass2);
    this->repository.add("step.grass", SA_grass3);
    this->repository.add("step.grass", SA_grass4);
    this->repository.add("step.gravel", SA_gravel1);
    this->repository.add("step.gravel", SA_gravel2);
    this->repository.add("step.gravel", SA_gravel3);
    this->repository.add("step.gravel", SA_gravel4);
    this->repository.add("step.sand", SA_sand1);
    this->repository.add("step.sand", SA_sand2);
    this->repository.add("step.sand", SA_sand3);
    this->repository.add("step.sand", SA_sand4);
    this->repository.add("step.stone", SA_stone1);
    this->repository.add("step.stone", SA_stone2);
    this->repository.add("step.stone", SA_stone3);
    this->repository.add("step.stone", SA_stone4);
    this->repository.add("step.wood", SA_wood1);
    this->repository.add("step.wood", SA_wood2);
    this->repository.add("step.wood", SA_wood3);
    this->repository.add("step.wood", SA_wood4);
    this->repository.add("random.splash", SA_splash);
    this->repository.add("random.explode", SA_explode);
    this->repository.add("random.click", SA_click);
    */
}

void SoundEngine::loadLibrary() {}

void SoundEngine::play(const std::string& name, float x, float y, float z, float volume, float pitch) {
    float v = volume * this->options->soundVolume;
    if (v > 0.0f) {
        this->minecraft->platform()->playSound(name, v, pitch);
    }
}

void SoundEngine::playUI(const std::string& name, float volume, float pitch) {
    float v = volume * this->options->soundVolume;
    if (v > 0.0f) {
        this->minecraft->platform()->playSound(name, v, pitch);
    }
}

void SoundEngine::update(Entity *mob, float angle) {
    if (this->options->soundVolume != 0.0f) {
        if (mob) {
            this->posX = mob->prevPosX + ((mob->posX - mob->prevPosX) * angle);
            this->posY = mob->prevPosY + ((mob->posY - mob->prevPosY) * angle);
            this->posZ = mob->prevPosZ + ((mob->posZ - mob->prevPosZ) * angle);
            this->rotationPitch = mob->prevRotationPitch + ((mob->rotationPitch - mob->prevRotationPitch) * angle);
            this->setListenerAngle(angle);
        }
    }
}