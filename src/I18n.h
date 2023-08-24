#pragma once

#include <iostream>

class I18n {
public:
    static std::string get(const std::string& translationId);
};