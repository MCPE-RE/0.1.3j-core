#ifndef IAREA_H_
#define IAREA_H_

#include <cstdint>

class IArea {
public:
    uint8_t unknown;

    IArea();

    IArea(const IArea& area);

    virtual void operator=(const IArea& area);
};

#endif