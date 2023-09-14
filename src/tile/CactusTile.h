#include "Tile.h"

class CactusTile : public Tile {
public:
    CactusTile(int32_t resource, int32_t texture);

    bool canSurvive(Level *level, int32_t x, int32_t y, int32_t z);

    void entityInside(Level *level, int32_t x, int32_t y, int32_t z, Entity *entity);

    AABB *getAABB(Level *level, int32_t x, int32_t y, int32_t z);

    int32_t getRenderLayer();

    int32_t getRenderShape();

    int32_t getTexture(int32_t face);

    AABB getTileAABB(Level *level, int32_t x, int32_t y, int32_t z);
    
    bool isCubeShaped();
    
    bool isSolidRender();
    
    bool mayPlace(Level *level, int32_t x, int32_t y, int32_t z);
    
    void neighborChanged(Level *level, int32_t x, int32_t y, int32_t z, int32_t face);
    
    void tick(Level *level, int32_t x, int32_t y, int32_t z, Random *random);
};