#pragma once
#include <iostream>

#include "../material/Material.h"
#include "../math/AABB.h"
#include "../Level.h"
#include "../math/Random.h"
#include "../entity/Entity.h"
#include "../entity/Mob.h"
#include "../entity/Player.h"
#include "../LevelSource.h"

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
    static bool solid[256];
    static bool translucent[256];
    static bool isEntityTile[256];
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
    Material *material; // 44
    float friction; // 48
    float hardness; // 52
    float blastResistance; // 56
    AABB aabb; // 60
    std::string descriptionId; // 84

    Tile(int32_t resource, const Material *material);

    Tile(int32_t resource, int32_t texture, const Material *material);

    void wasExploded(Level *level, int32_t x, int32_t y, int32_t z);

    int32_t use(Level *level, int32_t x, int32_t y, int32_t z, Player *player);

    void updateShape(LevelSource *levelSource, int32_t x, int32_t y, int32_t z);

    void updateDefaultShape();

    void triggerEvent(Level *level, int32_t x, int32_t y, int32_t z, int32_t a, int32_t b);

    void tick(Level *level, int32_t x, int32_t y, int32_t z, Random *random);

    void teardownTiles();

    void stepOn(Level *level, int32_t x, int32_t y, int32_t z, Entity *entity);

    void spawnResources(Level *level, int32_t x, int32_t y, int32_t z , int32_t data, float chance);

    void spawnResources(Level *level, int32_t x, int32_t y, int32_t z , int32_t data);

    int32_t spawnBurnResources(Level *level, float x, float y, float z);

    bool shouldRenderFace(LevelSource *levelSource, int32_t x, int32_t y, int32_t z, int32_t face);

    void setTicking(bool ticking);

    void setSoundType(const Tile::SoundType& soundType);

    void setShape(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);

    void setPlacedOnFace(Level *level, float x, float y, float z, int32_t face);

    void setPlacedBy(Level *level, int32_t x, int32_t y, int32_t z, Mob *mob);

    void setLightEmission(float lightEmission);

    void setLightBlock(int32_t lightBlock);

    void setExplodeable(float power);

    void setDestroyTime(float time);

    void setDescriptionId(const std::string& name);

    void prepareRender(Level *level, int32_t x, int32_t y, int32_t z);

    void playerDestroy(Level *level, Player *player, int32_t x, int32_t y, int32_t z, int32_t data);

    void onRemove(Level *level, int32_t x, int32_t y, int32_t z);

    void onPlace(Level *level, int32_t x, int32_t y, int32_t z);

    void neighborChanged(Level *level, int32_t x, int32_t y, int32_t z, int32_t face);

    bool mayPlace(Level *level, int32_t x, int32_t y, int32_t z);

    bool mayPick();

    bool mayPick(int32_t unknown0, bool unknown1);

    bool isSolidRender();

    bool isSignalSource();

    static bool isFaceVisible(Level *level, int32_t x, int32_t y, int32_t z, int32_t face);

    bool isCubeShaped();

    void initTiles();

    void init();

    void handleEntityInside(Level *level, int32_t x, int32_t y, int32_t z, Entity *entity, Vec3 &vector);

    AABB getTileAABB(Level *level, int32_t x, int32_t y, int32_t z);

    int32_t getTickDelay();

    int32_t getTexture(int32_t face, int32_t data);

    int32_t getTexture(int32_t face);

    int32_t getTexture(LevelSource *levelSource, int32_t x, int32_t y, int32_t z, int32_t face);

    int32_t getSpawnResourcesAuxValue(int32_t unknown0);

    int32_t getSignal(LevelSource *levelSource, int32_t x, int32_t y, int32_t z, int32_t face);

    int32_t getSignal(LevelSource *levelSource, int32_t x, int32_t y, int32_t z);

    int32_t getResourceCount(Random *random);

    int32_t getResource(int32_t data, Random *random);

    int32_t getRenderShape();

    int32_t getRenderLayer();

    std::string getName();

    float getExplosionResistance(Entity *entity);

    int32_t getDirectSignal(Level *level, int32_t x, int32_t y, int32_t z, int32_t face);

    float getDestroyProgress(Player *player);

    std::string getDescriptionId();

    int32_t getColor(LevelSource *levelSource, int32_t x, int32_t y, int32_t z);

    float getBrightness(LevelSource *levelSource, int32_t x, int32_t y, int32_t z);

    AABB *getAABB(Level *level, int32_t x, int32_t y, int32_t z);

    void entityInside(Level *level, int32_t x, int32_t y, int32_t z, Entity *entity);

    void destroy(Level *level, int32_t x, int32_t y, int32_t z, int32_t face);

    bool containsX(const Vec3& vector);

    bool containsY(const Vec3& vector);

    bool containsZ(const Vec3& vector);

    HitResult clip(Level *level, int32_t x, int32_t y, int32_t z, Vec3& vector1, Vec3& vector2);

    bool canSurvive(Level *level, int32_t x, int32_t y, int32_t z);

    void attack(Level *level, int32_t x, int32_t y, int32_t z, Player *player);

    void animateTick(Level *level, int32_t x, int32_t y, int32_t z, Random *random);

    void addLights(Level *level, int32_t x, int32_t y, int32_t z);

    void addAABBs(Level *level, int32_t x, int32_t y, int32_t z, const AABB *aabb, std::vector<AABB>& aabbs);
};