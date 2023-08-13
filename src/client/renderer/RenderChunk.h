#pragma once

#include <cstdint>
#include "../../math/Vec3.h"

class RenderChunk {
public:
	static uint32_t runningId;
	uint32_t bufferId;
	uint32_t addedVertices;
	uint32_t id;
	Vec3 vec;
	
	RenderChunk();
	
	RenderChunk(uint32_t bufferId, uint32_t addedVertices);
};
