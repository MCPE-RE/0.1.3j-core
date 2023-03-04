#ifndef MOUSE_H_
#define MOUSE_H_

#include "MouseDevice.h"

class Mouse {
    static MouseDevice _instance;

    static void feed(uint8_t button, uint8_t buttonState, uint16_t x, uint16_t y);

    static uint8_t getButtonState(uint32_t button);

    static MouseAction *getEvent();

    static uint8_t getEventButton();

    static bool getEventButtonState();

    static uint16_t getX();

    static uint16_t getY();

    static bool isButtonDown(uint32_t button);

    static bool next();

    static void reset();

    static void reset2();
};

#endif