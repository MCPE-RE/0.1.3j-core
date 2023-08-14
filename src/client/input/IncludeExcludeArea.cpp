#include "IncludeExcludeArea.h"
#include <cstdlib>

void IncludeExcludeArea::clear() {
    if (this->isDeletable) {
        for (size_t i = 0; i < this->includeAreas.size(); ++i) {
            delete this->includeAreas[i];
        }
        for (size_t i = 0; i < this->excludeAreas.size(); ++i) {
            delete this->excludeAreas[i];
        }
    }
    this->includeAreas.clear();
    this->excludeAreas.clear();
}

void IncludeExcludeArea::exclude(IArea *area) {
    this->excludeAreas.push_back(area);
}

void IncludeExcludeArea::include(IArea *area) {
    this->includeAreas.push_back(area);
}

bool IncludeExcludeArea::isInside(float x, float y) {
    for (size_t i = 0; i < this->includeAreas.size(); ++i) {
        if (this->includeAreas[i]->isInside(x, y)) {
            for (size_t j = 0; j < this->excludeAreas.size(); ++j) {
                if (this->excludeAreas[i]->isInside(x, y)) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}