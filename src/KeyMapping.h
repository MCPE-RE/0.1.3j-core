#ifndef KEYMAPPING_H_
#define KEYMAPPING_H_

#include <iostream>
#include <cstdint>

class KeyMapping {
public:
    std::string name;
    int32_t keyCode;

    KeyMapping(const std::string& name, int32_t keyCode);

    KeyMapping();

    void operator=(const KeyMapping& mapping);
};

#endif