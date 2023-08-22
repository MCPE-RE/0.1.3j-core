#include "SoundRepository.h"

void SoundRepository::add(const std::string &name, SoundDesc &desc) {
    std::map<std::string, std::vector<SoundDesc> >::iterator it = this->repository.find(name);
    desc.name = name;
    if (it == this->repository.end()) {
        std::vector<SoundDesc> descs;
        descs.push_back(desc);
        this->repository.insert(std::pair<std::string, std::vector<SoundDesc> >(name, descs));
    } else {
        it->second.push_back(desc);
    }
}