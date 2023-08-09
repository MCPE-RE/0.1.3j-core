#include "IArea.h"

IArea::IArea() {
    this->unknown = 1;
}

IArea::IArea(const IArea& area) {
    this->unknown = area.unknown;
}

void IArea::operator=(const IArea& area) {
    this->unknown = area.unknown;
}