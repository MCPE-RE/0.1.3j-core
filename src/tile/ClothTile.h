#include "Tile.h"

class ClothTile : public Tile {
public:
    int32_t type; // 108

    ClothTile(int32_t resource, int32_t type);

    ClothTile(int32_t type);

    int32_t getSpawnResourcesAuxValue(int32_t auxValue);

    int32_t getTexture(int32_t face, int32_t data);

    int32_t getTexture(int32_t face);
};