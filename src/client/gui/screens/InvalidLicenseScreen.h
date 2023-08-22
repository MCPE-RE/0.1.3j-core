#pragma once

#include "../Screen.h"

class InvalidLicenseScreen : public Screen {
public:
    int32_t licenseId; // 60
    std::string errorMessage; // 64
    std::string retryMessage; // 88
    std::string checkInternetConnectionMessage; // 112
    Button *okOrQuitButton; // 136
    Button *buyButton; // 140
    bool hasBuyButton; // 144
    int32_t y; // 148

    InvalidLicenseScreen(int32_t licenseId, bool hasBuyButton);

    void buttonClicked(Button *button);

    void init();

    void render(uint32_t x, uint32_t y, float unknown2);

    void setupPositions();

    void tick();
};