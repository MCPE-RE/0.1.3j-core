#include "AABB.h"

AABB::AABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ) {
    this->minX = minX;
    this->minY = minY;
    this->minZ = minZ;
    this->maxX = maxX;
    this->maxY = maxY;
    this->maxZ = maxZ;
}

HitResult AABB::clip(const Vec3& vector1, const Vec3& vector2) {
    HitResult result;
    return result;
}

void AABB::clipXCollide(const AABB& aabb, float x) {}

void AABB::clipYCollide(const AABB& aabb, float y) {}

void AABB::clipZCollide(const AABB& aabb, float z) {}

void AABB::cloneMove(float x, float y, float z) {}

void AABB::contains(const Vec3& vector) {}
    
void AABB::containsX(Vec3 *vector) {}

void AABB::containsY(Vec3 *vector) {}

void AABB::containsZ(Vec3 *vector) {}

void AABB::expand(float x, float y, float z) {}

float AABB::getSize() {}

void AABB::grow(float x, float y, float z) {}

void AABB::intersects(const AABB& aabb) {}

void AABB::move(float x, float y, float z) {}

void AABB::set(const AABB& aabb) {}

void AABB::set(float x1, float y1, float z1, float x2, float y2, float z2) {}