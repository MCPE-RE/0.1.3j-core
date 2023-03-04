#ifndef MOUSEDEVICE_H_
#define MOUSEDEVICE_H_

#include <cstdint>
#include <vector>
#include "MouseAction.h"

class MouseDevice {
public:
    int32_t eventIndex; // BYTE0
    uint16_t x; // BYTE4
    uint16_t y; // BYTE6
    uint16_t oldX; // BYTE8
    uint16_t oldY; // BYTE10
    uint8_t buttonStates[4]; // BYTE12
    std::vector<MouseAction> events; // BYTE16

    MouseDevice();

    void feed(uint8_t button, uint8_t buttonState, uint16_t x, uint16_t y);

    uint8_t getButtonState(uint32_t button);

    MouseAction *getEvent();

    uint8_t getEventButton();

    bool getEventButtonState();

    uint16_t getX();

    uint16_t getY();

    bool isButtonDown(uint32_t button);

    bool next();

    void reset();

    void reset2();
};

#endif