#pragma once
 
#include <map>
#include <vector>
#include <iostream>
#include "SoundDesc.h"

class SoundRepository {
public:
    std::map<std::string, std::vector<SoundDesc>> repository;

    void add(const std::string &name, SoundDesc &desc);
};
