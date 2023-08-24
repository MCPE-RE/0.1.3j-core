#pragma once
#include <iostream>

#include "../material/Material.h"
#include "../math/AABB.h"

class Tile {
public:
    class SoundType {
    public:
        std::string name;
        float volume;
        float pitch;

        SoundType(const std::string& name, float volume, float pitch);

        std::string getBreakSound();

        float getPitch();

        std::string getStepSound();

        float getVolume();
    };

    static Tile *tiles[256];
    static std::string TILE_DESCRIPTION_PREFIX;
    static SoundType SOUND_NORMAL;
    static SoundType SOUND_WOOD;
    static SoundType SOUND_GRAVEL;
    static SoundType SOUND_GRASS;
    static SoundType SOUND_STONE;
    static SoundType SOUND_METAL;
    static SoundType SOUND_GLASS;
    static SoundType SOUND_CLOTH;
    static SoundType SOUND_SAND;
    static SoundType SOUND_SILENT;

    int32_t texture; // 4
    int32_t resource; // 8
    float minX; // 12
    float minY; // 16
    float minZ; // 20
    float maxX; // 24
    float maxY; // 28;
    float maxZ; // 32;
    SoundType *soundType; // 36
    float particleGravity; // 40
    const Material *material; // 44
    float friction; // 48
    float hardness; // 52
    float blastResistance; // 56
    AABB aabb; // 60
    std::string descriptionId; // 84

    Tile(int32_t resource, const Material *material);

    Tile(int32_t resource, int32_t texture, const Material *material);
};