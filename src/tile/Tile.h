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
    static int32_t RENDERLAYER_OPAQUE;
    static int32_t RENDERLAYER_ALPHATEST;
    static int32_t RENDERLAYER_BLEND;
    static Tile *wood;
    static Tile *water;
    static Tile *unbreakable;
    static Tile *treeTrunk;
    static Tile *torch;
    static Tile *topSnow;
    static Tile *tnt;
    static Tile *stoneSlabHalf;
    static Tile *stoneBrick;
    static Tile *stairs_wood;
    static Tile *stairs_stone;
    static Tile *sandStone;
    static Tile *sand;
    static Tile *rose;
    static Tile *rock;
    static Tile *reeds;
    static Tile *redStoneOre_lit;
    static Tile *redStoneOre;
    static Tile *redBrick;
    static Tile *obsidian;
    static Tile *mushroom1;
    static Tile *mushroom2;
    static Tile *leaves;
    static Tile *lava;
    static Tile *lapisOre;
    static Tile *ladder;
    static Tile *ironOre;
    static Tile *ironBlock;
    static Tile *invisible_bedrock;
    static Tile *info_updateGame1;
    static Tile *info_updateGame2;
    static Tile *gravel;
    static Tile *grass;
    static Tile *goldOre;
    static Tile *goldBlock;
    static Tile *glass;
    static Tile *flower;
    static Tile *fire;
    static Tile *farmland;
    static Tile *emeraldOre;
    static Tile *emeraldBlock;
    static Tile *door_wood;
    static Tile *door_iron;
    static Tile *dirt;
    static Tile *coalOre;
    static Tile *clay;
    static Tile *calmWater;
    static Tile *calmLava;
    static Tile *cactus;
    static Tile *cloth;
    static Tile *cloth_00;
    static Tile *cloth_01;
    static Tile *cloth_10;
    static Tile *cloth_11;
    static Tile *cloth_20;
    static Tile *cloth_21;
    static Tile *cloth_30;
    static Tile *cloth_31;
    static Tile *cloth_40;
    static Tile *cloth_41;
    static Tile *cloth_50;
    static Tile *cloth_51;
    static Tile *cloth_60;
    static Tile *cloth_61;
    static Tile *cloth_70;

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

    virtual void wasExploded(Level *level, int32_t x, int32_t y, int32_t z);

    virtual int32_t use(Level *level, int32_t x, int32_t y, int32_t z, Player *player);

    virtual void updateShape(LevelSource *levelSource, int32_t x, int32_t y, int32_t z);

    virtual void updateDefaultShape();

    virtual void triggerEvent(Level *level, int32_t x, int32_t y, int32_t z, int32_t a, int32_t b);

    virtual void tick(Level *level, int32_t x, int32_t y, int32_t z, Random *random);

    void teardownTiles();

    virtual void stepOn(Level *level, int32_t x, int32_t y, int32_t z, Entity *entity);

    virtual void spawnResources(Level *level, int32_t x, int32_t y, int32_t z , int32_t data, float chance);

    virtual void spawnResources(Level *level, int32_t x, int32_t y, int32_t z , int32_t data);

    virtual int32_t spawnBurnResources(Level *level, float x, float y, float z);

    virtual bool shouldRenderFace(LevelSource *levelSource, int32_t x, int32_t y, int32_t z, int32_t face);

    virtual void setTicking(bool ticking);

    virtual void setSoundType(const Tile::SoundType& soundType);

    virtual void setShape(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);

    virtual void setPlacedOnFace(Level *level, float x, float y, float z, int32_t face);

    virtual void setPlacedBy(Level *level, int32_t x, int32_t y, int32_t z, Mob *mob);

    virtual void setLightEmission(float lightEmission);

    virtual void setLightBlock(int32_t lightBlock);

    virtual void setExplodeable(float power);

    virtual void setDestroyTime(float time);

    virtual void setDescriptionId(const std::string& name);

    virtual void prepareRender(Level *level, int32_t x, int32_t y, int32_t z);

    virtual void playerDestroy(Level *level, Player *player, int32_t x, int32_t y, int32_t z, int32_t data);

    virtual void onRemove(Level *level, int32_t x, int32_t y, int32_t z);

    virtual void onPlace(Level *level, int32_t x, int32_t y, int32_t z);

    virtual void neighborChanged(Level *level, int32_t x, int32_t y, int32_t z, int32_t face);

    virtual bool mayPlace(Level *level, int32_t x, int32_t y, int32_t z);

    virtual bool mayPick();

    virtual bool mayPick(int32_t unknown0, bool unknown1);

    virtual bool isSolidRender();

    virtual bool isSignalSource();

    static bool isFaceVisible(Level *level, int32_t x, int32_t y, int32_t z, int32_t face);

    virtual bool isCubeShaped();

    void initTiles();

    void init();

    virtual void handleEntityInside(Level *level, int32_t x, int32_t y, int32_t z, Entity *entity, Vec3 &vector);

    virtual AABB getTileAABB(Level *level, int32_t x, int32_t y, int32_t z);

    virtual int32_t getTickDelay();

    virtual int32_t getTexture(int32_t face, int32_t data);

    virtual int32_t getTexture(int32_t face);

    virtual int32_t getTexture(LevelSource *levelSource, int32_t x, int32_t y, int32_t z, int32_t face);

    virtual int32_t getSpawnResourcesAuxValue(int32_t unknown0);

    virtual int32_t getSignal(LevelSource *levelSource, int32_t x, int32_t y, int32_t z, int32_t face);

    virtual int32_t getSignal(LevelSource *levelSource, int32_t x, int32_t y, int32_t z);

    virtual int32_t getResourceCount(Random *random);

    virtual int32_t getResource(int32_t data, Random *random);

    virtual int32_t getRenderShape();

    virtual int32_t getRenderLayer();

    virtual std::string getName();

    virtual float getExplosionResistance(Entity *entity);

    virtual int32_t getDirectSignal(Level *level, int32_t x, int32_t y, int32_t z, int32_t face);

    virtual float getDestroyProgress(Player *player);

    virtual std::string getDescriptionId();

    virtual int32_t getColor(LevelSource *levelSource, int32_t x, int32_t y, int32_t z);

    virtual float getBrightness(LevelSource *levelSource, int32_t x, int32_t y, int32_t z);

    virtual AABB *getAABB(Level *level, int32_t x, int32_t y, int32_t z);

    virtual void entityInside(Level *level, int32_t x, int32_t y, int32_t z, Entity *entity);

    virtual void destroy(Level *level, int32_t x, int32_t y, int32_t z, int32_t face);

    bool containsX(const Vec3& vector);

    bool containsY(const Vec3& vector);

    bool containsZ(const Vec3& vector);

    virtual HitResult clip(Level *level, int32_t x, int32_t y, int32_t z, Vec3 vector1, Vec3 vector2);

    virtual bool canSurvive(Level *level, int32_t x, int32_t y, int32_t z);

    virtual void attack(Level *level, int32_t x, int32_t y, int32_t z, Player *player);

    virtual void animateTick(Level *level, int32_t x, int32_t y, int32_t z, Random *random);

    virtual void addLights(Level *level, int32_t x, int32_t y, int32_t z);

    virtual void addAABBs(Level *level, int32_t x, int32_t y, int32_t z, const AABB *aabb, std::vector<AABB>& aabbs);
};