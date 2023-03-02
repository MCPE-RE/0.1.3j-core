#include "Vec3.h"
#include <cmath>
 
Vec3::Vec3() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}
 
Vec3::Vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
 
void Vec3::set(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
 
Vec3 Vec3::normalize() {
	float dot = sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
	if (dot >= 0.0001) {
		return Vec3(this->x / dot, this->y / dot, this->z / dot);
	}
	return Vec3();
}
 
Vec3 Vec3::add(float x, float y, float z) {
	return Vec3(this->x + x, this->y + y, this->z + z);
}

float Vec3::distanceTo(const Vec3& vec) {
	float diffX = vec.x - this->x;
	float diffY = vec.y - this->y;
	float diffZ = vec.z - this->z;
	return sqrtf(diffX * diffX + diffY * diffY + diffZ * diffZ);
}

float Vec3::distanceToSqr(const Vec3& vec) {
	float diffX = vec.x - this->x;
	float diffY = vec.y - this->y;
	float diffZ = vec.z - this->z;
	return diffX * diffX + diffY * diffY + diffZ * diffZ;
}

Vec3 Vec3::scale(float multiplier) {
	return Vec3(this->x * multiplier, this->y * multiplier, this->z * multiplier);
}

bool Vec3::clipX(const Vec3& vecSrc, float clipX, Vec3& vecDst) {
	float diffX = vecSrc.x - this->x;
	float diffY = vecSrc.y - this->y;
	float diffZ = vecSrc.z - this->z;

	if ((diffX * diffX) < 0.0000001) {
		return false;
	}
	float diffClipX = clipX - this->x;
	float divr = diffClipX / diffX;
	if (divr < 0.0 || divr > 1.0) {
		return false;
	}
	vecDst.set(
		this->x + diffX * diffClipX,
		this->y + diffY * diffClipX,
		this->z + diffZ * diffClipX
	);
	return true;
}

bool Vec3::clipY(const Vec3& vecSrc, float clipY, Vec3& vecDst) {
	float diffX = vecSrc.x - this->x;
	float diffY = vecSrc.y - this->y;
	float diffZ = vecSrc.z - this->z;

	if ((diffY * diffY) < 0.0000001) {
		return false;
	}
	float diffClipY = clipY - this->y;
	float divr = diffClipY / diffY;
	if (divr < 0.0 || divr > 1.0) {
		return false;
	}
	vecDst.set(
		this->x + diffX * diffClipY,
		this->y + diffY * diffClipY,
		this->z + diffZ * diffClipY
	);
	return true;
}

bool Vec3::clipZ(const Vec3& vecSrc, float clipZ, Vec3& vecDst) {
	float diffX = vecSrc.x - this->x;
	float diffY = vecSrc.y - this->y;
	float diffZ = vecSrc.z - this->z;

	if ((diffZ * diffZ) < 0.0000001) {
		return false;
	}
	float diffClipZ = clipZ - this->z;
	float divr = diffClipZ / diffZ;
	if (divr < 0.0 || divr > 1.0) {
		return false;
	}
	vecDst.set(
		this->x + diffX * diffClipZ,
		this->y + diffY * diffClipZ,
		this->z + diffZ * diffClipZ
	);
	return true;
}

Vec3 Vec3::newTemp(float x, float y, float z) {
	return Vec3(x, y, z);
}

float Vec3::length() {
	return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}
