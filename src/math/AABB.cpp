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

float AABB::clipXCollide(const AABB& aabb, float x) {
    if (aabb.maxY <= this->minY || aabb.minY >= this->maxY) {
        return x;
    }
    if (aabb.maxZ <= this->minZ || aabb.minZ >= this->maxZ) {
        return x;
    }
    if (x > 0.0f && aabb.maxX <= this->minX && (this->minX - aabb.maxX) < x) {
        x = this->minX - aabb.maxX;
    }
    if (x < 0.0f && aabb.minX >= this->maxX && (this->maxX - aabb.minX) > x) {
        x = this->maxX - aabb.minX;
    }
    return x;
}

float AABB::clipYCollide(const AABB& aabb, float y) {
    if (aabb.maxX <= this->minX || aabb.minX >= this->maxX) {
        return y;
    }
    if (aabb.maxZ <= this->minZ || aabb.minZ >= this->maxZ) {
        return y;
    }
    if (y > 0.0f && aabb.maxY <= this->minY && (this->minX - aabb.maxX) < y) {
        y = this->minY - aabb.maxY;
    }
    if (y < 0.0f && aabb.minY >= this->maxY && (this->maxY - aabb.minY) > y) {
        y = this->maxY - aabb.minY;
    }
    return y;
}

float AABB::clipZCollide(const AABB& aabb, float z) {
    if (aabb.maxX <= this->minX || aabb.minX >= this->maxX) {
        return z;
    }
    if (aabb.maxY <= this->minY || aabb.minY >= this->maxY) {
        return z;
    }
    if (z > 0.0f && aabb.maxZ <= this->minZ && (this->minZ - aabb.maxZ) < z) {
        z = this->minZ - aabb.maxZ;
    }
    if (z < 0.0f && aabb.minZ >= this->maxZ && (this->maxZ - aabb.minZ) > z) {
        z = this->maxZ - aabb.minZ;
    }
    return z;
}

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
    return false;
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
    return false;
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