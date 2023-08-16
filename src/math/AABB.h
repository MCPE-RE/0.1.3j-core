#pragma once
#include "Vec3.h"
#include "HitResult.h"

class AABB {
public:
    float minX;
    float minY;
    float minZ;
    float maxX;
    float maxY;
    float maxZ;

    AABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);

    HitResult clip(const Vec3& vector1, const Vec3& vector2);

    float clipXCollide(const AABB& aabb, float x);

    float clipYCollide(const AABB& aabb, float y);

    float clipZCollide(const AABB& aabb, float z);

    AABB cloneMove(float x, float y, float z);

    bool contains(const Vec3& vector);
    
    bool containsX(Vec3 *vector);

    bool containsY(Vec3 *vector);

    bool containsZ(Vec3 *vector);

    AABB expand(float x, float y, float z);

    float getSize();

    AABB grow(float x, float y, float z);

    bool intersects(const AABB& aabb);

    bool intersects(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);

    void move(float x, float y, float z);

    static AABB newTemp(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);

    void set(const AABB& aabb);

    void set(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);
};