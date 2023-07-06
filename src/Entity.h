#ifndef ENTITY_H_
#define ENTITY_H_

#include "Level.h"

class Entity {
public:
	uint32_t entityId; // 44
	Level *level; // 56

	Entity(Level *level);
};

#endif