#include "Level.h"

Level::Level() {}

void Level::addListener(LevelListener *listener) {
	this->listeners.push_back(listener);
}

void Level::removeListener(LevelListener *listener) {
	std::vector<LevelListener *>::iterator it = std::find(this->listeners.begin(), this->listeners.end(), listener);
	this->listeners.erase(it);
}
