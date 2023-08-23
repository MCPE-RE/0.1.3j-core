#include "StartMenuScreen.h"
#include "../OptionsScreen.h"
#include "../InvalidLicenseScreen.h"
#include "../../../../Minecraft.h"
#include "../../../../math/Mth.h"
#include "../../../../LicenseCodes.h"

Touch::StartMenuScreen::StartMenuScreen() :
    startGameButton(2, "Start Game"),
    joinGameButton(3, "Join Game"),
    optionsButton(4, "Options"),
    createButton(999, 0, 0, 78, 22, "Create"),
    buyButton(5) {
    ImageDef imageDef;
    this->startGameButton.width = 75;
    imageDef.height = 75.0f;
    imageDef.width = 75.0f;
    imageDef.doRender = true;
    imageDef.rect.minX = 0;
    imageDef.rect.maxY = 75;
    imageDef.rect.maxX = 75;
    imageDef.rect.minY = 26;
    imageDef.name = "gui/touchgui.png";
    this->optionsButton.setImageDef(imageDef, true);
    imageDef.rect.minY += imageDef.rect.maxY;
    this->startGameButton.setImageDef(imageDef, true);
    imageDef.rect.minY += imageDef.rect.maxY;
    this->joinGameButton.setImageDef(imageDef, true);
}

void Touch::StartMenuScreen::init() {
	this->buttonList.push_back(&this->startGameButton);
	this->buttonList.push_back(&this->joinGameButton);
    this->buttonList.push_back(&this->optionsButton);
    this->buttonList.push_back(&this->buyButton);
    this->tabButtonList.push_back(&this->startGameButton);
	this->tabButtonList.push_back(&this->joinGameButton);
    this->tabButtonList.push_back(&this->optionsButton);
    this->tabButtonList.push_back(&this->buyButton);
    this->copyright = "\xffMojang AB";
    this->gameVersion = "v0.1.3j alpha";
    this->optionsButton.isUsable = false;
    this->startGameButton.isUsable = false;
    this->joinGameButton.isUsable = false;
}

void Touch::StartMenuScreen::render(uint32_t x, uint32_t y, float unknown2) {
	this->renderBackground();
	GLuint textureId = this->minecraft->textures->loadTexture("gui/title.png", true);
	TextureData *data = this->minecraft->textures->getTemporaryTextureData(textureId);
	if (data) {
		this->minecraft->textures->bind(textureId);
        float halfWidth = (float)this->width / 2.0f;
        float halfTextureWidth = (float)data->width / 2.0f;
        float minWidth = Mth::Min(halfWidth, halfTextureWidth) * 0.5;
        float yy = (float)data->height * ((minWidth * 2) / (float)data->width);

        glColor4f(1.0, 1.0, 1.0, 1.0);
		Tesselator::instance.begin();
        Tesselator::instance.vertexUV(halfWidth - minWidth, yy + 4.0f, this->zCoord, 0.0f, 1.0f);
        Tesselator::instance.vertexUV(halfWidth + minWidth, yy + 4.0f, this->zCoord, 1.0f, 1.0f);
        Tesselator::instance.vertexUV(halfWidth + minWidth, 4.0f, this->zCoord, 1.0f, 0.0f);
        Tesselator::instance.vertexUV(halfWidth - minWidth, 4.0f, this->zCoord, 0.0f, 0.0f);
        Tesselator::instance.draw();
        GuiComponent::drawString(this->font, this->gameVersion, this->gameVersionX, (int32_t)(yy + 4.0f) + 2, 0xffcccccc);
        GuiComponent::drawString(this->font, this->copyright, this->copyrightX, this->height - 10, 0xFFFFFF);
	}
    Screen::render(x, y, unknown2);
}

void Touch::StartMenuScreen::buttonClicked(Button *button) {
    if (button->buttonId == this->startGameButton.buttonId) {
        this->minecraft->screenChooser.setScreen(SELECT_WORLD);
    } else if (button->buttonId == this->joinGameButton.buttonId) {
        //this->minecraft->locateMultiplayer();
        this->minecraft->screenChooser.setScreen(JOIN_GAME);
    } else if (button->buttonId == this->optionsButton.buttonId) {
        this->minecraft->setScreen(new OptionsScreen());
    } else if (button->buttonId == this->buyButton.buttonId) {
        this->minecraft->platform()->buyGame();
    }
}

void Touch::StartMenuScreen::StartMenuScreen::setupPositions() {
    this->startGameButton.y = this->height / 3 + 2;
    this->joinGameButton.y = this->height / 3 + 2;
    this->optionsButton.y = this->height / 3 + 2;
    this->joinGameButton.x = ((float)this->width + ((float)this->startGameButton.width * -3.0f)) / 4.0;
    this->startGameButton.x = this->startGameButton.width + (int32_t)(this->joinGameButton.x * 2.0f);
    this->optionsButton.x = 2 * this->startGameButton.width + (int32_t)(this->joinGameButton.x * 3.0f);

    this->buyButton.y = this->height - this->buyButton.height - 3;
    this->buyButton.x = (this->width - this->buyButton.width) / 2;

    this->createButton.x = 4;
    this->createButton.y = this->height - this->createButton.height - 4;

    this->copyrightX = this->width - this->font->width(this->copyright) - 1;
    this->gameVersionX = (this->width - this->font->width(this->gameVersion)) / 2;
}

bool Touch::StartMenuScreen::StartMenuScreen::isInGameScreen() {
    return false;
}

void Touch::StartMenuScreen::StartMenuScreen::_updateLicense() {
    int32_t licenseId = this->minecraft->getLicenseId();
    if (LicenseCodes::isReady(licenseId)) {
        if (LicenseCodes::isOk(licenseId)) {
            this->optionsButton.isUsable = true;
            this->startGameButton.isUsable = true;
            this->joinGameButton.isUsable = true;
        } else {
            bool hasBuyButton = this->minecraft->platform()->hasBuyButtonWhenInvalidLicense();
            this->minecraft->setScreen(new InvalidLicenseScreen(licenseId, hasBuyButton));
        }
    } else {
        this->optionsButton.isUsable = false;
        this->startGameButton.isUsable = false;
        this->joinGameButton.isUsable = false;
    }
}

void Touch::StartMenuScreen::StartMenuScreen::tick() {
    this->_updateLicense();
}