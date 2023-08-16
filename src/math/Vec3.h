#pragma once

#include <cstdint>

class Vec3 {
public:
	float x;
	float y;
	float z;
	
	Vec3();
	
	Vec3(float x, float y, float z);
	
	void set(float x, float y, float z);
	
	Vec3 normalize() const;
	
	Vec3 add(float x, float y, float z) const;
	
	float distanceTo(const Vec3& vec) const;
	
	float distanceToSqr(const Vec3& vec) const;
	
	Vec3 scale(float multiplier) const;
	
	bool clipX(const Vec3& vecSrc, float clipX, Vec3& vecDst) const;
	
	bool clipY(const Vec3& vecSrc, float clipY, Vec3& vecDst) const;
	
	bool clipZ(const Vec3& vecSrc, float clipZ, Vec3& vecDst) const;
	
	static Vec3 newTemp(float x, float y, float z);
	
	float length() const;
};
