#ifndef MOUSEHANDLER_H_
#define MOUSEHANDLER_H_

#include <cstdint>
#include "../ITurnInput.h"

class MouseHandler {
public:
    float turnDelta; // BYTE0
    uint32_t unknown1; // BYTE4
    uint32_t unknown2; // BYTE8
    ITurnInput *turnInput; // BYTE12

    MouseHandler();

    void grab();

    void poll();

    void release();

    void setTurnInput(ITurnInput *turnInput);
};

#endif