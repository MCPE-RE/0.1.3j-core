#pragma once
#include <iostream>

class Tile {
public:
    class SoundType {
        std::string name;
        float volume;
        float pitch;

        SoundType(const std::string& name, float volume, float pitch);

        std::string getBreakSound();

        float getPitch();

        std::string getStepSound();

        float getVolume();
    };
};