#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "KeyboardAction.h"
#include <cstdint>
#include <vector>

class Keyboard {
public:
    static int32_t _states[256];
    static std::vector<KeyboardAction> _inputs;
    static int32_t _index;

    static void feed(uint8_t key, int32_t state);

    static uint8_t getEventKey();

    static int32_t getEventKeyState();

    static bool isKeyDown(int32_t key);

    static bool next();
    
    static void reset();
};

#endif