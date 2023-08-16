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

float AABB::clipXCollide(const AABB& aabb, float x) {}

float AABB::clipYCollide(const AABB& aabb, float y) {}

float AABB::clipZCollide(const AABB& aabb, float z) {}

AABB AABB::cloneMove(float x, float y, float z) {
    return AABB::newTemp(
        this->minX + x,
        this->minY + y,
        this->minZ + z,
        this->maxX + x,
        this->maxY + y,
        this->maxZ + z
    );
}

bool AABB::contains(const Vec3& vector) {
    if (vector.x <= this->minX || vector.x >= this->maxX) {
        return false;
    }
    if (vector.y > this->minY && vector.y < this->maxY) {
        if (vector.z > this->minZ && vector.z < this->maxZ) {
            return true;
        }
    }
    return false;
}
    
bool AABB::containsX(Vec3 *vector) {
    return (
        vector->y >= this->minY &&
        vector->y <= this->maxY &&
        vector->z >= this->minZ &&
        vector->z <= this->maxZ
    );
}

bool AABB::containsY(Vec3 *vector) {
    return (
        vector->x >= this->minX &&
        vector->x <= this->maxX &&
        vector->z >= this->minZ &&
        vector->z <= this->maxZ
    );
}

bool AABB::containsZ(Vec3 *vector) {
    return (
        vector->x >= this->minX &&
        vector->x <= this->maxX &&
        vector->y >= this->minY &&
        vector->y <= this->maxY
    );
}

AABB AABB::expand(float x, float y, float z) {
    return AABB::newTemp(
        x < 0.0f ? (this->minX + x) : this->minX,
        x > 0.0f ? (this->maxX + x) : this->maxX,
        x < 0.0f ? (this->minY + y) : this->minY,
        x > 0.0f ? (this->maxY + y) : this->maxY,
        x < 0.0f ? (this->minZ + z) : this->minZ,
        x > 0.0f ? (this->maxZ + z) : this->maxZ
    );
}

float AABB::getSize() {
    float dx = this->maxX - this->minX;
    float dy = this->maxY - this->minY;
    float dz = this->maxZ - this->minZ;
    return (dx + dy + dz) / 3.0f;
}

AABB AABB::grow(float x, float y, float z) {
    return AABB(
        this->minX - x,
        this->minY - y,
        this->minZ - z,
        this->maxX + x,
        this->maxY + y,
        this->maxZ + z
    );
}

bool AABB::intersects(const AABB& aabb) {
    if (this->minX >= aabb.maxX || this->maxX <= aabb.minX) {
        return false;
    }
    if (this->minY < aabb.maxY && this->maxY > aabb.minY) {
        if (this->minZ < aabb.maxZ && this->maxZ > aabb.minZ) {
            return true;
        }
    }
}

bool AABB::intersects(float minX, float minY, float minZ, float maxX, float maxY, float maxZ) {
    if (this->minX >= maxX || this->maxX <= minX) {
        return false;
    }
    if (this->minY < maxY && this->maxY > minY) {
        if (this->minZ < maxZ && this->maxZ > minZ) {
            return true;
        }
    }
}

void AABB::move(float x, float y, float z) {
    this->minX += x;
    this->minY += y;
    this->minZ += z;
    this->maxX += x;
    this->maxY += y;
    this->maxZ += z;
}

AABB AABB::newTemp(float minX, float minY, float minZ, float maxX, float maxY, float maxZ) {
    return AABB(minX, minY, minZ, maxX, maxY, maxZ);
}

void AABB::set(const AABB& aabb) {
    this->minX = aabb.minX;
    this->minY = aabb.minY;
    this->minZ = aabb.minZ;
    this->maxX = aabb.maxX;
    this->maxY = aabb.maxY;
    this->maxZ = aabb.maxZ;
}

void AABB::set(float minX, float minY, float minZ, float maxX, float maxY, float maxZ) {
    this->minX = minX;
    this->minY = minY;
    this->minZ = minZ;
    this->maxX = maxX;
    this->maxY = maxY;
    this->maxZ = maxZ;
}