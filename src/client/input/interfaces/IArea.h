#pragma once

#include <cstdint>

class IArea {
public:
    bool isDeletable;

    IArea();

    IArea(const IArea& area);

    virtual bool isInside(float x, float y) = 0;

    void operator=(const IArea& area);
};