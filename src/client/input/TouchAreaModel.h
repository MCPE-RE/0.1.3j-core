#pragma once

#include "interfaces/ITouchScreenModel.h"
#include "interfaces/IArea.h"
#include <vector>
#include <cstdint>

class TouchAreaModel : public ITouchScreenModel {
public:
    struct Area {
        IArea *area;
        int32_t pointerId;
    };

    std::vector<TouchAreaModel::Area *> areas;

    void addArea(int32_t pointerId, IArea *area);

    void clear();

    int32_t getPointerId(const MouseAction *action);

    int32_t getPointerId(int32_t x, int32_t y, int32_t pointerId);
};
