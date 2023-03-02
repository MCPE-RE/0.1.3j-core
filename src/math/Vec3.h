#ifndef VEC3_H_
#define VEC3_H_

#include <cstdint>

class Vec3 {
public:
	float x;
	float y;
	float z;
	
	Vec3();
	
	Vec3(float x, float y, float z);
	
	void set(float x, float y, float z);
	
	Vec3 normalize();
	
	Vec3 add(float x, float y, float z);
	
	float distanceTo(const Vec3& vec);
	
	float distanceToSqr(const Vec3& vec);
	
	Vec3 scale(float multiplier);
	
	bool clipX(const Vec3& vecSrc, float clipX, Vec3& vecDst);
	
	bool clipY(const Vec3& vecSrc, float clipY, Vec3& vecDst);
	
	bool clipZ(const Vec3& vecSrc, float clipZ, Vec3& vecDst);
	
	static Vec3 newTemp(float x, float y, float z);
	
	float length();
};

#endif
