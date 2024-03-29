#pragma once

#include "../math/AABB.h"
#include "../Level.h"

enum EntityRenderType {
    ENTITY_RENDER_NONE,
    ENTITY_RENDER_TNT,
    ENTITY_RENDER_HUMANOID,
    ENTITY_RENDER_ITEM,
    ENTITY_RENDER_CAMERA
};

class Entity {
public:
    float posX; // 4
    float posY; // 8
    float posZ; // 12
    uint8_t unknown_16;
    uint32_t unknown_20;
    uint32_t unknown_24;
    uint32_t unknown_28;
    uint32_t unknown_32;
    uint32_t unknown_36;
    uint32_t unknown_40;
    uint32_t entityId;
    float renderDistanceWeight; // 48
    uint8_t unknown_52;
    Level *level; // 56
    float prevPosX; // 60
    float prevPosY; //64
    float prevPosZ; // 68
    float motionX; // 72
    float motionY; // 76
    float motionZ; // 80
    float rotationPitch; // 84
    float rotationYaw; // 88
    float prevRotationPitch; // 92
    float prevRotationYaw; // 96
    AABB boundingBox; // 100
    bool onGround; // 124
    bool isCollidedHorizontally; // 125
    bool isCollidedVertically; // 126
    bool isCollided; // 127
    bool isHurt; // 128
    uint8_t unknown_129;
    bool isDead; // 130
    uint32_t unknown_132;
    float width; // 136
    float height; // 140
    float prevDistanceWalkedModified; // 144
    float distanceWalkedModified; // 148
    uint32_t unknown_152;
    uint32_t unknown_156;
    uint32_t unknown_160;
    float ySize; // 164
    float stepHeight; // 168
    bool noClip; // 172
    uint32_t unknown_176;
    uint32_t ticksExisted;
    uint32_t unknown_184;
    uint32_t unknown_188;
    uint32_t fire; // 192
    uint32_t unknown_196;
    EntityRenderType renderType; // 200
    float fallDistance; // 204
    uint32_t unknown_208;
    bool inWater; // 212
    bool isImmuneToFire; // 213
    bool firstUpdate; // 214
    uint32_t unknown_216;
};