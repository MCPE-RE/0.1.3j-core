#pragma once

#include <string>

class LevelListener {
public:
	LevelListener();

	virtual void tileChanged(uint32_t x, uint32_t y, uint32_t z);

	void tileBrightnessChanged(uint32_t x, uint32_t y, uint32_t z);

	virtual void setTilesDirty(uint32_t unknown0, uint32_t unknown1, uint32_t unknown2, uint32_t unknown3, uint32_t unknown4, uint32_t unknown5);

	virtual void allChanged();

	virtual void playSound(const std::string& name, float unknown0, float unknown1, float unknown2, float unknown3, float unknown4);

	// TODO: class TripodCamera, Entity
	virtual void takePicture(void *camera, void *entity);

	virtual void addParticle(const std::string& name, float unknown0, float unknown1, float unknown2, float unknown3, float unknown4, float unknown5);

	void playMusic(const std::string& name, float unknown0, float unknown1, float unknown2, float unknown3);

	// TODO: class Entity
	virtual void entityAdded(void *entity);
	// TODO: class Entity
	void entityRemoved(void *entity);

	void skyColorChanged();

	void playStreamingMusic(const std::string& name, uint32_t unknown0, uint32_t unknown1, uint32_t unknown2);
};
