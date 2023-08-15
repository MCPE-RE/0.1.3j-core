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

    void clipXCollide(const AABB& aabb, float x);

    void clipYCollide(const AABB& aabb, float y);

    void clipZCollide(const AABB& aabb, float z);

    void cloneMove(float x, float y, float z);

    void contains(const Vec3& vector);
    
    void containsX(Vec3 *vector);

    void containsY(Vec3 *vector);

    void containsZ(Vec3 *vector);

    void expand(float x, float y, float z);

    float getSize();

    void grow(float x, float y, float z);

    void intersects(const AABB& aabb);

    void move(float x, float y, float z);

    void set(const AABB& aabb);

    void set(float x1, float y1, float z1, float x2, float y2, float z2);
};