#pragma once
#include <iostream>

#include "../material/Material.h"
#include "../math/AABB.h"
#include "../Level.h"
#include "../math/Random.h"
#include "../entity/Entity.h"

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
    static bool shouldTick[256];
    static int32_t lightEmission[256];
    static int32_t lightBlock[256];
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
    float shapeMinX; // 12
    float shapeMinY; // 16
    float shapeMinZ; // 20
    float shapeMaxX; // 24
    float shapeMaxY; // 28;
    float shapeMaxZ; // 32;
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

    void wasExploded(Level *level, int32_t x, int32_t y, int32_t z);

    int32_t use(Level *level, int32_t x, int32_t y, int32_t z, void *player);

    void updateShape(void *levelSource, int32_t x, int32_t y, int32_t z);

    void updateDefaultShape();

    void triggerEvent(Level *level, int32_t x, int32_t y, int32_t z, int32_t a, int32_t b);

    void tick(Level *level, int32_t x, int32_t y, int32_t z, Random *random);

    void teardownTiles();

    void stepOn(Level *level, int32_t x, int32_t y, int32_t z, Entity *entity);

    void spawnResources(Level *level, int32_t x, int32_t y, int32_t z , int32_t data, float chance);

    void spawnResources(Level *level, int32_t x, int32_t y, int32_t z , int32_t data);

    int32_t spawnBurnResources(Level *level, float x, float y, float z);

    bool shouldRenderFace(void *levelSource, int32_t x, int32_t y, int32_t z, int32_t face);

    void setTicking(bool ticking);

    void setSoundType(const Tile::SoundType& soundType);

    void setShape(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);

    void setPlacedOnFace(Level *level, float x, float y, float z, int32_t face);

    void setPlacedBy(Level *level, int32_t x, int32_t y, int32_t z, void *mob);

    void setLightEmission(float lightEmission);

    void setLightBlock(int32_t lightBlock);

    void setExplodeable(float power);

    void setDestroyTime(float time);

    void setDescriptionId(const std::string& name);

    void prepareRender(Level *level, int32_t x, int32_t y, int32_t z);

    void playerDestroy(Level *level, void *player, int32_t x, int32_t y, int32_t z, int32_t data);

    void onRemove(Level *level, int32_t x, int32_t y, int32_t z);

    void onPlace(Level *level, int32_t x, int32_t y, int32_t z);
};