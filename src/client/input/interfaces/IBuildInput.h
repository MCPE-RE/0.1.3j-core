#pragma once

#include <cstdint>
#include "../../../entity/Player.h"

class IBuildInput {
public:
    virtual void setScreenSize(int32_t width, int32_t height);

    virtual bool tickBuild(Player *player, void *buildActionIntention);
};
