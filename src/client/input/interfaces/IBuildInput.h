#pragma once

#include <cstdint>

class IBuildInput {
public:
    virtual void setScreenSize(int32_t width, int32_t height);

    virtual bool tickBuild(void *player, void *buildActionIntention);
};
