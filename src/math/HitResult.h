#pragma once

#include <cstdint>
#include "Vec3.h"

class Entity;

class HitResult {
public:
    int32_t type;
    int32_t x;
    int32_t y;
    int32_t z;
    int32_t side;
    Vec3 hitPos;
    Entity *entity;
    bool unknown;

    HitResult(int32_t x, int32_t y, int32_t z, int32_t side, const Vec3& hitPos);

    HitResult(Entity *entity);

    HitResult();

    float distanceTo(Entity *entity);

    bool isHit();
};