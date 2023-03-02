#ifndef LEVEL_H_
#define LEVEL_H_

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

#endif /* LEVEL_H_ */
