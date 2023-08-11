#ifndef MULTITOUCH_H_
#define MULTITOUCH_H_

#include <vector>
#include <cstdint>
#include "mouse/MouseAction.h"
#include "mouse/MouseDevice.h"

class Multitouch {
public:
    static int32_t _activePointerCount;
    static int32_t *_activePointerList;
    static int32_t _index;
    static std::vector<MouseAction> _inputs;
    static MouseDevice _pointers[12];
    static bool _wasPressed[12];
    static bool _wasPressedThisUpdate[12];
    static bool _wasReleased[12];
    static bool _wasReleasedThisUpdate[12];

    int32_t _clampPointerId(int32_t pointerId);

    void commit();

    void feed(uint8_t button, uint8_t buttonState, uint16_t x, uint16_t y, uint8_t pointerId);
    
    MouseDevice *g(int32_t pointerId);

    int32_t getActivePointerIds(int32_t **pPointers);

    MouseAction *getEvent();

    int32_t getFirstActivePointerIdEx();

    int32_t getFirstActivePointerIdExThisUpdate();

    int16_t getX(int32_t pointerId);

    int16_t getY(int32_t pointerId);

    bool isPressed(int32_t pointerId);

    bool next();

    void reset();

    void resetThisUpdate();

    void rewind();
};

#endif