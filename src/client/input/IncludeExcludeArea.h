#ifndef INCLUDEEXCLUDEAREA_H_
#define INCLUDEEXCLUDEAREA_H_

#include "interfaces/IArea.h"
#include <vector>

class IncludeExcludeArea : public IArea {
public:
    std::vector<IArea *> includeAreas;
    std::vector<IArea *> excludeAreas;

    void clear();

    void exclude(IArea *area);

    void include(IArea *area);

    bool isInside(float x, float y);
};

#endif