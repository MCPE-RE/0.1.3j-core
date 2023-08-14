#pragma once

#include <cstdint>
#include "../interfaces/ITurnInput.h"

class MouseHandler {
public:
    float dx; // BYTE0
    float dy; // BYTE4
    uint32_t unknown2; // BYTE8
    ITurnInput *turnInput; // BYTE12

    MouseHandler();

    void grab();

    void poll();

    void release();

    void setTurnInput(ITurnInput *turnInput);
};
