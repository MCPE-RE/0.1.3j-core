#pragma once

#include "Level.h"

class Entity {
public:
	uint32_t entityId; // 44
	Level *level; // 56

	Entity(Level *level);
};
