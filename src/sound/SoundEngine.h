#pragma once

#include "SoundSystem.h"
#include "../math/Random.h"
#include "../Options.h"
#include <cstdint>
#include "SoundRepository.h"
#include "../Options.h"
#include "../entity/Entity.h"

class Minecraft;

class SoundEngine : public SoundSystem {
public:
    Options *options;
    uint32_t unknown_4;
    Random random;
    float posX;
    float posY;
    float posZ;
    float rotationPitch;
    float volumeStep;
    SoundRepository repository;
    Minecraft *minecraft;

    SoundEngine(float volumeStepCount);

    float _getVolumeMult(float x, float y, float z);

    void enable(bool state);

    void init(Minecraft *minecraft, Options *options);

    void loadLibrary();

    void play(const std::string& name, float x, float y, float z, float volume, float pitch);

    void playUI(const std::string& name, float volume, float pitch);

    void update(Entity *mob, float angle);
};