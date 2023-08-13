#pragma once

#include "LevelListener.h"
#include <vector>
#include <algorithm>

class Level {
public:
	std::vector<LevelListener *> listeners; // 2564

	Level();

	void addListener(LevelListener *listener);

	void removeListener(LevelListener *listener);
};
