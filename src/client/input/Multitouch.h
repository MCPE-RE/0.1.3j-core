#ifndef MULTITOUCH_H_
#define MULTITOUCH_H_

#include <vector>
#include <cstdint>
#include "mouse/MouseAction.h"
#include "mouse/MouseDevice.h"

class Multitouch {
public:
    static int32_t _activePointerCount;
    static int32_t _activePointerList[12];
    static int32_t _index;
    static std::vector<MouseAction> _inputs;
    static MouseDevice _pointers[12];
    static bool _wasPressed[12];
    static bool _wasPressedThisUpdate[12];
    static bool _wasReleased[12];
    static bool _wasReleasedThisUpdate[12];

    static int32_t _clampPointerId(int32_t pointerId);

    static void commit();

    static void feed(uint8_t button, uint8_t buttonState, uint16_t x, uint16_t y, uint8_t pointerId);
    
    static MouseDevice *g(int32_t pointerId);

    static int32_t getActivePointerIds(int32_t **pPointers);

    static MouseAction *getEvent();

    static int32_t getFirstActivePointerIdEx();

    static int32_t getFirstActivePointerIdExThisUpdate();

    static int16_t getX(int32_t pointerId);

    static int16_t getY(int32_t pointerId);

    static bool isPressed(int32_t pointerId);

    static bool next();

    static void reset();

    static void resetThisUpdate();

    static void rewind();
};

#endif