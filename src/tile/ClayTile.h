#include "Tile.h"

class ClayTile : public Tile {
public:
    ClayTile(int32_t resource, int32_t texture);

    int32_t getResourceCount(Random *random);

    int32_t getResource(int32_t data, Random *random);
};