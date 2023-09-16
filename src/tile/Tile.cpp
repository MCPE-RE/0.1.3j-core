#include "Tile.h"
#include "../I18n.h"

Tile::SoundType::SoundType(const std::string& name, float volume, float pitch) {
    this->name = name;
    this->volume = volume;
    this->pitch = pitch;
}

std::string Tile::SoundType::getBreakSound() {
    return "step." + this->name;
}

float Tile::SoundType::getPitch() {
    return this->pitch;
}

std::string Tile::SoundType::getStepSound() {
    return "step." + this->name;
}

float Tile::SoundType::getVolume() {
    return this->volume;
}

Tile *Tile::tiles[256];
bool Tile::shouldTick[256];
int32_t Tile::lightEmission[256];
int32_t Tile::lightBlock[256];
bool Tile::solid[256];
bool Tile::translucent[256];
bool Tile::isEntityTile[256];
std::string Tile::TILE_DESCRIPTION_PREFIX = "tile.";
Tile::SoundType Tile::SOUND_NORMAL = Tile::SoundType("stone", 1.0f, 1.0f);
Tile::SoundType Tile::SOUND_WOOD = Tile::SoundType("wood", 1.0f, 1.0f);
Tile::SoundType Tile::SOUND_GRAVEL = Tile::SoundType("gravel", 1.0f, 1.0f);
Tile::SoundType Tile::SOUND_GRASS = Tile::SoundType("grass", 0.5f, 1.0f);
Tile::SoundType Tile::SOUND_STONE = Tile::SoundType("stone", 1.0f, 1.0f);
Tile::SoundType Tile::SOUND_METAL = Tile::SoundType("stone", 1.0f, 1.5f);
Tile::SoundType Tile::SOUND_GLASS = Tile::SoundType("stone", 1.0f, 1.0f);
Tile::SoundType Tile::SOUND_CLOTH = Tile::SoundType("cloth", 1.0f, 1.0f);
Tile::SoundType Tile::SOUND_SAND = Tile::SoundType("sand", 0.45f, 1.0f);
Tile::SoundType Tile::SOUND_SILENT = Tile::SoundType("", 0.0f, 0.0f);
int32_t Tile::RENDERLAYER_OPAQUE = 0;
int32_t Tile::RENDERLAYER_ALPHATEST = 1;
int32_t Tile::RENDERLAYER_BLEND = 2;
Tile *Tile::wood;
Tile *Tile::water;
Tile *Tile::wood;
Tile *Tile::unbreakable;
Tile *Tile::treeTrunk;
Tile *Tile::wood;
Tile *Tile::torch;
Tile *Tile::topSnow;
Tile *Tile::tnt;
Tile *Tile::stoneSlabHalf;
Tile *Tile::stoneBrick;
Tile *Tile::stairs_wood;
Tile *Tile::stairs_stone;
Tile *Tile::sandStone;
Tile *Tile::sand;
Tile *Tile::rose;
Tile *Tile::rock;
Tile *Tile::reeds;
Tile *Tile::redStoneOre_lit;
Tile *Tile::redStoneOre;
Tile *Tile::redBrick;
Tile *Tile::obsidian;
Tile *Tile::mushroom1;
Tile *Tile::mushroom2;
Tile *Tile::leaves;
Tile *Tile::lava;
Tile *Tile::lapisOre;
Tile *Tile::ladder;
Tile *Tile::ironOre;
Tile *Tile::ironBlock;
Tile *Tile::invisible_bedrock;
Tile *Tile::info_updateGame1;
Tile *Tile::info_updateGame2;
Tile *Tile::gravel;
Tile *Tile::grass;
Tile *Tile::goldOre;
Tile *Tile::goldBlock;
Tile *Tile::glass;
Tile *Tile::flower;
Tile *Tile::fire;
Tile *Tile::farmland;
Tile *Tile::emeraldOre;
Tile *Tile::emeraldBlock;
Tile *Tile::door_wood;
Tile *Tile::door_iron;
Tile *Tile::dirt;
Tile *Tile::coalOre;
Tile *Tile::clay;
Tile *Tile::calmWater;
Tile *Tile::calmLava;
Tile *Tile::cactus;
Tile *Tile::cloth;
Tile *Tile::cloth_00;
Tile *Tile::cloth_01;
Tile *Tile::cloth_10;
Tile *Tile::cloth_11;
Tile *Tile::cloth_20;
Tile *Tile::cloth_21;
Tile *Tile::cloth_30;
Tile *Tile::cloth_31;
Tile *Tile::cloth_40;
Tile *Tile::cloth_41;
Tile *Tile::cloth_50;
Tile *Tile::cloth_51;
Tile *Tile::cloth_60;
Tile *Tile::cloth_61;
Tile *Tile::cloth_70;

Tile::Tile(int32_t resource, const Material *material) : aabb(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f) {
    this->texture = 1;
    this->resource = resource;
    this->shapeMinX = 0.0f;
    this->shapeMinY = 0.0f;
    this->shapeMinZ = 0.0f;
    this->shapeMaxX = 1.0f;
    this->shapeMaxY = 1.0f;
    this->shapeMaxZ = 1.0f;
    this->soundType = &Tile::SOUND_NORMAL;
    this->particleGravity = 1.0f;
    this->material = (Material *)material;
    this->friction = 0.6f;
    this->descriptionId = "";
    if (Tile::tiles[this->resource]) {
        printf(
            "Slot %d is already occupied by %p when adding %p\n",
            this->resource,
            Tile::tiles[this->resource],
            this
        );
    }
}

Tile::Tile(int32_t resource, int32_t texture, const Material *material) : aabb(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f) {
    this->texture = texture;
    this->resource = resource;
    this->shapeMinX = 0.0f;
    this->shapeMinY = 0.0f;
    this->shapeMinZ = 0.0f;
    this->shapeMaxX = 1.0f;
    this->shapeMaxY = 1.0f;
    this->shapeMaxZ = 1.0f;
    this->soundType = &Tile::SOUND_NORMAL;
    this->particleGravity = 1.0f;
    this->material = (Material *)material;
    this->friction = 0.6f;
    this->descriptionId = "";
    if (Tile::tiles[this->resource]) {
        printf(
            "Slot %d is already occupied by %p when adding %p\n",
            this->resource,
            Tile::tiles[this->resource],
            this
        );
    }
}

void Tile::wasExploded(Level *level, int32_t x, int32_t y, int32_t z) {}

int32_t Tile::use(Level *level, int32_t x, int32_t y, int32_t z, Player *player) {
    return 0;
}

void Tile::updateShape(LevelSource *levelSource, int32_t x, int32_t y, int32_t z) {}

void Tile::updateDefaultShape() {}

void Tile::triggerEvent(Level *level, int32_t x, int32_t y, int32_t z, int32_t a, int32_t b) {}

void Tile::tick(Level *level, int32_t x, int32_t y, int32_t z, Random *random) {}

void Tile::teardownTiles() {
    for (int i = 0; i < 256; ++i) {
        if (Tile::tiles[i]) {
            delete Tile::tiles[i];
        }
    }
}

void Tile::stepOn(Level *level, int32_t x, int32_t y, int32_t z, Entity *entity) {}

void Tile::spawnResources(Level *level, int32_t x, int32_t y, int32_t z , int32_t data, float chance) {}

void Tile::spawnResources(Level *level, int32_t x, int32_t y, int32_t z , int32_t data) {
    this->spawnResources(level, x, y, z, data, 1.0f);
}

int32_t Tile::spawnBurnResources(Level *level, float x, float y, float z) {
    return 0;
}

bool Tile::shouldRenderFace(LevelSource *levelSource, int32_t x, int32_t y, int32_t z, int32_t face) {
    if (!face && y == -1) {
        return false;
    }
    if (face == 2 && z == -1) {
        return false;
    }
    if (face == 3 && z == 257) {
        return false;
    }
    if (face == 4 && x == -1) {
        return false;
    }
    if (face == 5 && x == 257) {
        return false;
    }
    if (!face && this->shapeMinY > 0.0f) {
        return true;
    }
    if (face == 1 && this->shapeMaxY < 1.0f) {
        return true;
    }
    if (face == 2 && this->shapeMinZ > 0.0f) {
        return true;
    }
    if (face == 3 && this->shapeMaxZ < 1.0f) {
        return true;
    }
    if (face == 4 && this->shapeMinX > 0.0f) {
        return true;
    }
    if (face == 5 && this->shapeMaxX < 1.0f) {
        return true;
    }
    Tile *tile = Tile::tiles[levelSource->getTile(x, y, z)];
    if (!tile) {
        return true;
    }
    if (face == 1 && tile->resource == Tile::topSnow->resource) {
        return false;
    }
    return !this->isSolidRender();
}

void Tile::setTicking(bool ticking) {
    Tile::shouldTick[this->resource] = ticking;
}

void Tile::setSoundType(const Tile::SoundType& soundType) {
    this->soundType = (Tile::SoundType *)&soundType;
}

void Tile::setShape(float minX, float minY, float minZ, float maxX, float maxY, float maxZ) {
    this->shapeMinX = minX;
    this->shapeMinY = minY;
    this->shapeMinZ = minZ;
    this->shapeMaxX = maxX;
    this->shapeMaxY = maxY;
    this->shapeMaxZ = maxZ;
}

void Tile::setPlacedOnFace(Level *level, float x, float y, float z, int32_t face) {}

void Tile::setPlacedBy(Level *level, int32_t x, int32_t y, int32_t z, Mob *mob) {}

void Tile::setLightEmission(float lightEmission) {
    Tile::lightEmission[this->resource] = (int32_t)(lightEmission * 15.0f);
}

void Tile::setLightBlock(int32_t lightBlock) {
    Tile::lightBlock[this->resource] = lightBlock;
}

void Tile::setExplodeable(float power) {
    this->blastResistance = power * 3.0f;
}

void Tile::setDestroyTime(float time) {
    this->hardness = time;
    if (this->blastResistance < time * 5.0f) {
        this->blastResistance = time * 5.0f;
    }
}

void Tile::setDescriptionId(const std::string& name) {
    this->descriptionId = Tile::TILE_DESCRIPTION_PREFIX + name;
}

void Tile::prepareRender(Level *level, int32_t x, int32_t y, int32_t z) {}

void Tile::playerDestroy(Level *level, Player *player, int32_t x, int32_t y, int32_t z, int32_t data) {
    this->spawnResources(level, x, y, z, data);
}

void Tile::onRemove(Level *level, int32_t x, int32_t y, int32_t z) {}

void Tile::onPlace(Level *level, int32_t x, int32_t y, int32_t z) {}

void Tile::neighborChanged(Level *level, int32_t x, int32_t y, int32_t z, int32_t face) {}

bool Tile::mayPlace(Level *level, int32_t x, int32_t y, int32_t z) {
    uint8_t tile = level->getTile(x, y, z);
    return !tile || Tile::tiles[tile]->material->isLiquid();
}

bool Tile::mayPick() {
    return true;
}

bool Tile::mayPick(int32_t unknown0, bool unknown1) {
    return this->mayPick();
}

bool Tile::isSolidRender() {
    return true;
}

bool Tile::isSignalSource() {
    return false;
}

bool Tile::isFaceVisible(Level *level, int32_t x, int32_t y, int32_t z, int32_t face) {
    if (face == 0) {
        --y;
    } else if (face == 1) {
        ++y;
    } else if (face == 2) {
        --z;
    } else if (face == 3) {
        ++z;
    } else if (face == 4) {
        --x;
    } else if (face == 5) {
        ++x;
    }
    return level->isSolidTile(x, y, z);
}

bool Tile::isCubeShaped() {
    return true;
}

void Tile::initTiles() {
    // TODO LAST
}

void Tile::init() {
    Tile::tiles[this->resource] = this;
    this->setShape(
        this->shapeMinX,
        this->shapeMinY,
        this->shapeMinZ,
        this->shapeMaxX,
        this->shapeMaxY,
        this->shapeMaxZ
    ); // hmm, why this?
    Tile::solid[this->resource] = this->isSolidRender();
    Tile::lightBlock[this->resource] = Tile::solid[this->resource] ? 255 : 0;
    Tile::translucent[this->resource] = !this->material->blocksLight();
    Tile::isEntityTile[this->resource] = false;
}

void Tile::handleEntityInside(Level *level, int32_t x, int32_t y, int32_t z, Entity *entity, Vec3 &vector) {}

AABB Tile::getTileAABB(Level *level, int32_t x, int32_t y, int32_t z) {
    return AABB(
        (float)x + this->shapeMinX,
        (float)y + this->shapeMinY,
        (float)z + this->shapeMinZ,
        (float)x + this->shapeMaxX,
        (float)y + this->shapeMaxY,
        (float)z + this->shapeMaxZ
    );
}

int32_t Tile::getTickDelay() {
    return 10;
}

int32_t Tile::getTexture(int32_t face, int32_t data) {
    return this->getTexture(face);
}

int32_t Tile::getTexture(int32_t face) {
    return this->texture;
}

int32_t Tile::getTexture(LevelSource *levelSource, int32_t x, int32_t y, int32_t z, int32_t face) {
    int32_t data = levelSource->getData(x, y, z);
    return this->getTexture(face, data);
}

int32_t Tile::getSpawnResourcesAuxValue(int32_t unknown0) {
    return 0;
}

int32_t Tile::getSignal(LevelSource *levelSource, int32_t x, int32_t y, int32_t z, int32_t face) {
    return 0;
}

int32_t Tile::getSignal(LevelSource *levelSource, int32_t x, int32_t y, int32_t z) {
    return 0;
}

int32_t Tile::getResourceCount(Random *random) {
    return 1;
}

int32_t Tile::getResource(int32_t data, Random *random) {
    return this->resource;
}

int32_t Tile::getRenderShape() {
    return 0;
}

int32_t Tile::getRenderLayer() {
    return 0;
}

std::string Tile::getName() {
    return I18n::get(this->getDescriptionId() + ".name");
}

float Tile::getExplosionResistance(Entity *entity) {
    return this->blastResistance / 5.0f;
}

int32_t Tile::getDirectSignal(Level *level, int32_t x, int32_t y, int32_t z, int32_t face) {
    return 0;
}

float Tile::getDestroyProgress(Player *player) {
    if (this->hardness >= 0.0f) {
        /*if (player->canDestroy(this) != 1) {
            return (1.0f / this->hardness) / 100.0f;
        }
        return (player->getDestroySpeed(this) / this->hardness) / 30.0f;*/
    }
    return 0.0f;
}

std::string Tile::getDescriptionId() {
    return this->descriptionId;
}

int32_t Tile::getColor(LevelSource *levelSource, int32_t x, int32_t y, int32_t z) {
    return 0xFFFFFF;
}

float Tile::getBrightness(LevelSource *levelSource, int32_t x, int32_t y, int32_t z) {
    return levelSource->getBrightness(x, y, z);
}

AABB *Tile::getAABB(Level *level, int32_t x, int32_t y, int32_t z) {
    this->aabb.minX = (float)x + this->shapeMinX;
    this->aabb.minY = (float)y + this->shapeMinY;
    this->aabb.minZ = (float)z + this->shapeMinZ;
    this->aabb.maxX = (float)x + this->shapeMaxX;
    this->aabb.maxY = (float)y + this->shapeMaxY;
    this->aabb.maxZ = (float)z + this->shapeMaxZ;
    return &this->aabb;
}

void Tile::entityInside(Level *level, int32_t x, int32_t y, int32_t z, Entity *entity) {}

void Tile::destroy(Level *level, int32_t x, int32_t y, int32_t z, int32_t face) {}

bool Tile::containsX(const Vec3& vector) {
    return
        vector.y >= this->shapeMinY &&
        vector.y <= this->shapeMaxY &&
        vector.z >= this->shapeMinZ &&
        vector.z <= this->shapeMaxZ;
}

bool Tile::containsY(const Vec3& vector) {
    return
        vector.x >= this->shapeMinX &&
        vector.x <= this->shapeMaxX &&
        vector.z >= this->shapeMinZ &&
        vector.z <= this->shapeMaxZ;
}

bool Tile::containsZ(const Vec3& vector) {
    return
        vector.x >= this->shapeMinX &&
        vector.x <= this->shapeMaxX &&
        vector.y >= this->shapeMinY &&
        vector.y <= this->shapeMaxY;
}

HitResult Tile::clip(Level *level, int32_t x, int32_t y, int32_t z, Vec3 vector1, Vec3 vector2) {
    Vec3 clipMinX;
    Vec3 clipMinY;
    Vec3 clipMinZ;
    Vec3 clipMaxX;
    Vec3 clipMaxY;
    Vec3 clipMaxZ;

    this->updateShape(level, x, y, z);

    vector1 = vector1.add(-x, -y, -z);
    vector2 = vector2.add(-x, -y, -z);
    
    bool hasClipMinX = vector1.clipX(vector2, this->shapeMinX, clipMinX);
    bool hasClipMaxX = vector1.clipX(vector2, this->shapeMaxX, clipMaxX);
    bool hasClipMinY = vector1.clipY(vector2, this->shapeMinY, clipMinY);
    bool hasClipMaxY = vector1.clipY(vector2, this->shapeMaxY, clipMaxY);
    bool hasClipMinZ = vector1.clipZ(vector2, this->shapeMinZ, clipMinZ);
    bool hasClipMaxZ = vector1.clipZ(vector2, this->shapeMaxZ, clipMaxZ);

    if (!hasClipMinX || !this->containsX(clipMinX)) {
        hasClipMinX = false;
    }
    if (!hasClipMinY || !this->containsX(clipMinY)) {
        hasClipMinY = false;
    }
    if (!hasClipMinY || !this->containsY(clipMinY)) {
        hasClipMinY = false;
    }
    if (!hasClipMinY || !this->containsY(clipMinY)) {
        hasClipMinY = false;
    }
    if (!hasClipMinZ || !this->containsZ(clipMinZ)) {
        hasClipMinZ = false;
    }
    if (!hasClipMinZ || !this->containsZ(clipMinZ)) {
        hasClipMinZ = false;
    }

    Vec3 *vector = nullptr;

    if (hasClipMinX) {
        if (!vector || vector1.distanceToSqr(clipMinX) < vector1.distanceToSqr(*vector)) {
            vector = &clipMinX;
        }
    }
    if (hasClipMaxX) {
        if (!vector || vector1.distanceToSqr(clipMaxX) < vector1.distanceToSqr(*vector)) {
            vector = &clipMaxX;
        }
    }
    if (hasClipMinY) {
        if (!vector || vector1.distanceToSqr(clipMinY) < vector1.distanceToSqr(*vector)) {
            vector = &clipMinY;
        }
    }
    if (hasClipMaxY) {
        if (!vector || vector1.distanceToSqr(clipMaxY) < vector1.distanceToSqr(*vector)) {
            vector = &clipMaxY;
        }
    }
    if (hasClipMinZ) {
        if (!vector || vector1.distanceToSqr(clipMinZ) < vector1.distanceToSqr(*vector)) {
            vector = &clipMinZ;
        }
    }
    if (hasClipMaxZ) {
        if (!vector || vector1.distanceToSqr(clipMaxZ) < vector1.distanceToSqr(*vector)) {
            vector = &clipMaxZ;
        }
    }

    if (vector) {
        int32_t side = -1;
        if (vector == &clipMinX) {
            side = 4;
        }
        if (vector == &clipMaxX) {
            side = 5;
        }
        if (vector == &clipMinY) {
            side = 0;
        }
        if (vector == &clipMaxY) {
            side = 1;
        }
        if (vector == &clipMinZ) {
            side = 2;
        }
        if (vector == &clipMaxZ) {
            side = 3;
        }
        return HitResult(x, y, z, side, vector->add(x, y, z));
    }
    return HitResult();
}

bool Tile::canSurvive(Level *level, int32_t x, int32_t y, int32_t z) {
    return true;
}

void Tile::attack(Level *level, int32_t x, int32_t y, int32_t z, Player *player) {}

void Tile::animateTick(Level *level, int32_t x, int32_t y, int32_t z, Random *random) {}

void Tile::addLights(Level *level, int32_t x, int32_t y, int32_t z) {}

void Tile::addAABBs(Level *level, int32_t x, int32_t y, int32_t z, const AABB *aabb, std::vector<AABB>& aabbs) {
    AABB *boundingBox = this->getAABB(level, x, y, z);
    if (boundingBox && aabb->intersects(*boundingBox)) {
        aabbs.push_back(*boundingBox);
    }
}