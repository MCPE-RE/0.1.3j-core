#include "InvalidLicenseScreen.h"
#include "../../../Minecraft.h"
#include "../../../LicenseCodes.h"

InvalidLicenseScreen::InvalidLicenseScreen(int32_t licenseId, bool hasBuyButton) {
    this->licenseId = licenseId;
    this->okOrQuitButton = nullptr;
    this->buyButton = nullptr;
    this->hasBuyButton = hasBuyButton;
    this->y = 0;
}

void InvalidLicenseScreen::buttonClicked(Button *button) {
    if (this->buttonIndex == this->okOrQuitButton->buttonId) {
        this->minecraft->quit();
    } else if (this->buttonIndex == this->buyButton->buttonId) {
        this->minecraft->platform()->buyGame();
    }
}

void InvalidLicenseScreen::init() {
    if (this->minecraft->isTouchScreen()) {
        //this->okOrQuitButton = new Touch::TButton(1, "Ok");
        //this->buyButton = new Touch::TButton(2, "Quit");
        this->okOrQuitButton = new Button(1, "Ok");
        this->buyButton = new Button(2, "Buy");
    } else {
        this->okOrQuitButton = new Button(1, "Ok");
        this->buyButton = new Button(2, "Buy");
    }
    if (this->hasBuyButton) {
        this->okOrQuitButton->name = "Quit";
    }
    if (!LicenseCodes::isOk(this->licenseId)) {
        char licenseIdString[5] = {0, 0, 0, 0, 0};
        sprintf(licenseIdString, "%d", this->licenseId);
        this->errorMessage = "License verification failed (error ";
        this->errorMessage += licenseIdString;
        this->errorMessage += ")";
        this->retryMessage = "Try again later.";
        this->checkInternetConnectionMessage = "You need to be connected to the internet\n";
        this->checkInternetConnectionMessage += "once while you start the game.";
    }
    this->buttonList.push_back(this->okOrQuitButton);
    this->tabButtonList.push_back(this->okOrQuitButton);
    if (this->hasBuyButton) {
        this->buttonList.push_back(this->buyButton);
        this->tabButtonList.push_back(this->buyButton);
    }
}

void InvalidLicenseScreen::render(uint32_t x, uint32_t y, float unknown2) {
    this->renderDirtBackground(0);
    this->drawCenteredString(this->minecraft->font, this->errorMessage, this->width / 2, this->y, 0xffffff);
    this->drawCenteredString(this->minecraft->font, this->retryMessage, this->width / 2, this->y + 24, 0xffffff);
    this->drawCenteredString(this->minecraft->font, this->checkInternetConnectionMessage, this->width / 2, this->y + 60, 0xffffff);

    Screen::render(x, y, unknown2);
}

void InvalidLicenseScreen::setupPositions() {
    this->y = this->height / 5 + 6;
    this->y -= 24;
    this->buyButton->width = 200;
    this->okOrQuitButton->width = this->buyButton->width;
    this->buyButton->x = (this->width - this->buyButton->width) / 2;
    this->okOrQuitButton->x = this->buyButton->x;
    this->buyButton->y = this->y + 84;
    this->okOrQuitButton->y = this->buyButton->height + this->buyButton->y + 4;
    if (!this->hasBuyButton) {
        this->okOrQuitButton->y -= 24;
    }
}

void InvalidLicenseScreen::tick() {}