#include "HitResult.h"
#include "../entity/Entity.h"

HitResult::HitResult(int32_t x, int32_t y, int32_t z, int32_t side, const Vec3& hitPos){
    this->type = 0;
    this->x = x;
    this->y = y;
    this->z = z;
    this->side = side;
    this->hitPos = Vec3::newTemp(hitPos.x, hitPos.y, hitPos.z);
    this->unknown = false;
}

HitResult::HitResult(Entity *entity) {
    this->type = 1;
    this->entity = entity;
    this->hitPos = Vec3::newTemp(entity->posX, entity->posY, entity->posZ);
    this->unknown = false;
}

HitResult::HitResult() {
    this->type = 2;
}

float HitResult::distanceTo(Entity *entity) {
    float dx = this->hitPos.x - entity->posX;
    float dy = this->hitPos.y - entity->posY;
    float dz = this->hitPos.z - entity->posZ;
    return (dx * dx) + (dy * dy) + (dz * dz);
}

bool HitResult::isHit() {
    return this->type != 2;
}