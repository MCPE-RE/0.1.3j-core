#include "KeyMapping.h"

KeyMapping::KeyMapping(const std::string& name, int32_t keyCode) {
    this->name = name;
    this->keyCode = keyCode;
}

KeyMapping::KeyMapping() {}

void KeyMapping::operator=(const KeyMapping& mapping) {
    this->name = mapping.name;
    this->keyCode = mapping.keyCode;
}