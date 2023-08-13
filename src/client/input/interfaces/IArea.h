#pragma once

#include <cstdint>

class IArea {
public:
    uint8_t unknown;

    IArea();

    IArea(const IArea& area);

    virtual bool isInside(float x, float y) = 0;

    void operator=(const IArea& area);
};