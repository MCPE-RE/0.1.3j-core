#pragma once

#include <iostream>
#include "SoundDesc.h"

class SoundSystem {
public:
    virtual void enable(bool enable);

    virtual bool isAvailable();

    virtual void load(const std::string& name);

    virtual void pause(const std::string& name);

    virtual void play(const std::string& name);

    virtual void playAt(const SoundDesc& desc, float x, float y, float z, float volume, float pitch);

    virtual void setListenerAngle(float angle);

    virtual void setListenerPos(float x, float y, float z);

    virtual void stop(const std::string& name);
};