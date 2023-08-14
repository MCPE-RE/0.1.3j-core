#include "IArea.h"

IArea::IArea() {
    this->isDeletable = true;
}

IArea::IArea(const IArea& area) {
    this->isDeletable = area.isDeletable;
}

void IArea::operator=(const IArea& area) {
    this->isDeletable = area.isDeletable;
}