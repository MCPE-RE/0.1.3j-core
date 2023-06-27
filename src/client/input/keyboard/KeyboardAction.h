#ifndef KEYBOARDACTION_H_
#define KEYBOARDACTION_H_

#include <cstdint>

class KeyboardAction {
public:
    int32_t state;
    uint8_t key;

    KeyboardAction(uint8_t key, int32_t state);
};

#endif