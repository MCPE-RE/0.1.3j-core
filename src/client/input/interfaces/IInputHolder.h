#ifndef IINPUTHOLDER_H_
#define IINPUTHOLDER_H_

#include <cstdint>
#include "ITurnInput.h"
#include "IMoveInput.h"
#include "ITurnInput.h"
#include "IBuildInput.h"

class IInputHolder {
public:
    float x;
    float y;

    IInputHolder();

    virtual bool allowPicking();

    virtual void setScreenSize(int32_t width, int32_t height);

    virtual IMoveInput *getMoveInput() = 0;

    virtual ITurnInput *getTurnInput() = 0;

    virtual IBuildInput *getBuildInput() = 0;
};

#endif