#pragma once

#include <cstdint>

class IBuildInput {
public:
    virtual void setScreenSize(int32_t width, int32_t height);

    virtual int32_t tickBuild(void *player, void *buildActionIntention);
};
