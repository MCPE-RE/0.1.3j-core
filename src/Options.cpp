#include "Options.h"
#include "OptionStrings.h"
#include <cmath>

Options::Option Options::Option::THIRD_PERSON = Options::Option(12, "options.thirdperson", false, true);
Options::Option Options::Option::LIMIT_FRAMERATE = Options::Option(7, "options.limitFramerate", false, true);
Options::Option Options::Option::SOUND = Options::Option(1, "options.sound", true, false);
Options::Option Options::Option::MUSIC = Options::Option(0, "options.music", true, false);
Options::Option Options::Option::GUI_SCALE = Options::Option(11, "options.guiScale", false, false);
Options::Option Options::Option::DIFFICULTY = Options::Option(8, "options.difficulty", false, false);
Options::Option Options::Option::ANAGLYPH = Options::Option(6, "options.anaglyph", false, true);
Options::Option Options::Option::GRAPHICS = Options::Option(9, "options.graphics", false, false);
Options::Option Options::Option::AMBIENT_OCCLUSION = Options::Option(10, "options.ao", false, true);
Options::Option Options::Option::VIEW_BOBBING = Options::Option(5, "options.viewBobbing", false, true);
Options::Option Options::Option::RENDER_DISTANCE = Options::Option(4, "options.renderDistance", false, false);
Options::Option Options::Option::SENSITIVITY = Options::Option(3, "options.sensitivity", true, false);
Options::Option Options::Option::INVERT_MOUSE = Options::Option(2, "options.invertMouse", false, true);

Options::Option::Option(int32_t id, const std::string& name, bool isProgressValue, bool isBooleanValue) {
    this->isProgressValue = isProgressValue;
    this->isBooleanValue = isBooleanValue;
    this->name = std::string(name);
    this->id = id;
}

Options::Options() {
    this->unknown45 = 0;
    this->initDefaultValues();
}

bool Options::getBooleanValue(const Option *option) {
    if (option == (const Options::Option *)&Options::Option::INVERT_MOUSE) {
        return this->invertMouse;
    }
    if (option == (const Options::Option *)&Options::Option::VIEW_BOBBING) {
        return this->viewBobbing;
    }
    if (option == (const Options::Option *)&Options::Option::ANAGLYPH) {
        return this->anaglyphEnabled;
    }
    if (option == (const Options::Option *)&Options::Option::LIMIT_FRAMERATE) {
        return this->limitFramerate;
    }
    if (option == (const Options::Option *)&Options::Option::AMBIENT_OCCLUSION) {
        return this->ambientOcclusion;
    }
    if (option == (const Options::Option *)&Options::Option::THIRD_PERSON) {
        return this->thirdPerson;
    }
    return false;
}

std::string Options::getMessage(const Options::Option *option) {
    return "Options::getMessage - Not implemented";
}

float Options::getProgressValue(const Options::Option *option) {
    if (option == (const Options::Option *)&Options::Option::MUSIC) {
        return this->musicVolume;
    }
    if (option == (const Options::Option *)&Options::Option::SOUND) {
        return this->soundVolume;
    }
    if (option == (const Options::Option *)&Options::Option::SENSITIVITY) {
        return this->sensitivity;
    }
    return 0.0f;
}

void Options::initDefaultValues() {
    this->difficulty = 2;
    this->unknown47 = 0;
    this->thirdPerson = false;
    this->unknown49 = 0;
    this->unknown50 = 0;
    this->unknown51 = 1;
    this->unknown52 = 0;
    this->unknown53 = 1.0f;
    this->unknown54 = 1.0f;
    this->guiScale = 0;
    this->unknown9 = 0;
    this->feedbackVibration = true;
    this->isLeftHanded = false;
    this->musicVolume = 1.0f;
    this->soundVolume = 1.0f;
    this->sensitivity = 0.5f;
    this->invertMouse = false;
    this->renderDistance = 2;
    this->viewBobbing = true;
    this->anaglyphEnabled = false;
    this->limitFramerate = false;
    this->fancyGraphics = false;
    this->ambientOcclusion = false;
    this->unknown12 = "Default";
    this->username = "Steve";
    this->serverVisible = true;

    this->keyForward = KeyMapping("key.forward", 87);
    this->keyLeft = KeyMapping("key.left", 65);
    this->keyBack = KeyMapping("key.back", 83);
    this->keyRight = KeyMapping("key.right", 68);
    this->keyJump = KeyMapping("key.jump", 32);
    this->keyInventory = KeyMapping("key.inventory", 69);
    this->keyDrop = KeyMapping("key.drop", 81);
    this->keyChat = KeyMapping("key.chat", 84);
    this->keyFog = KeyMapping("key.fog", 70);
    this->keySneak = KeyMapping("key.sneak", 10);
    this->keyDestory = KeyMapping("key.destroy", 88);
    this->keyUse = KeyMapping("key.use", 67);
    this->keyMenuNext = KeyMapping("key.menu.next", 40);
    this->keyMenuPrevious = KeyMapping("key.menu.previous", 38);
    this->keyMenuOk = KeyMapping("key.menu.ok", 13);
    this->keyMenuCancel = KeyMapping("key.menu.cancel", 8);

    this->keyForwardPointer = &this->keyForward;
    this->keyLeftPointer = &this->keyLeft;
    this->keyBackPointer = &this->keyBack;
    this->keyRightPointer = &this->keyRight;
    this->keyJumpPointer = &this->keyJump;
    this->keySneakPointer = &this->keySneak;
    this->keyDropPointer = &this->keyDrop;
    this->keyInventoryPointer = &this->keyInventory;
    this->keyChatPointer = &this->keyChat;
    this->keyFogPointer = &this->keyFog;
    this->keyDestoryPointer = &this->keyDestory;
    this->keyUsePointer = &this->keyUse;
    this->keyMenuNextPointer = &this->keyMenuNext;
    this->keyMenuPreviousPointer = &this->keyMenuPrevious;
    this->keyMenuOkPointer = &this->keyMenuOk;
    this->keyMenuCancelPointer = &this->keyMenuCancel;

    this->keyForward.keyCode = 19;
    this->keyBack.keyCode = 20;
    this->keyLeft.keyCode = 21;
    this->keyRight.keyCode = 22;
    this->keyJump.keyCode = 23;
    this->keyUse.keyCode = 103;
    this->keyDestory.keyCode = 102;
    this->keyMenuNext.keyCode = 20;
    this->keyMenuPrevious.keyCode = 19;
    this->keyMenuOk.keyCode = 23;
    this->keyMenuCancel.keyCode = 4;
}

void Options::load() {}

bool Options::readBool(const std::string &input, bool &output) {
    // Util::stringTrim
    if (input == "true" || input == "1" || input == "YES") {
        output = true;
        return true;
    }
    if (input == "false" || input == "0" || input == "NO") {
        output = false;
        return true;
    }
    return false;
}

bool Options::readFloat(const std::string &input, float &output) {
    if (input == "true" || input == "YES") {
        output = 1.0f;
        return true;
    }
    if (input == "false" || input == "NO") {
        output = 0.0f;
        return true;
    }
    return sscanf(input.c_str(), "%f", output);
}

bool Options::readInt(const std::string &input, int32_t &output) {
    if (input == "true" || input == "YES") {
        output = 1;
        return true;
    }
    if (input == "false" || input == "NO") {
        output = 0;
        return true;
    }
    return sscanf(input.c_str(), "%d", output);
}

void Options::save() {}

void Options::set(const Options::Option *option, float value) {
    if (option == (const Options::Option *)&Options::Option::MUSIC) {
        this->musicVolume = value;
    }
    if (option == (const Options::Option *)&Options::Option::SOUND) {
        this->soundVolume = value;
    }
    if (option == (const Options::Option *)&Options::Option::SENSITIVITY) {
        this->sensitivity = value;
    }
}

void Options::toggle(const Options::Option *option, int32_t value) {
    if (option == (const Options::Option *)&Options::Option::INVERT_MOUSE) {
        this->invertMouse ^= 1u;
    }
    if (option == (const Options::Option *)&Options::Option::RENDER_DISTANCE) {
        this->renderDistance = ((uint8_t)value + (uint8_t)this->renderDistance) & 3;
    }
    if (option == (const Options::Option *)&Options::Option::GUI_SCALE) {
        this->guiScale = ((uint8_t)value + (uint8_t)this->guiScale) & 3;
    }
    if (option == (const Options::Option *)&Options::Option::VIEW_BOBBING) {
        this->viewBobbing ^= 1u;
    }
    if (option == (const Options::Option *)&Options::Option::THIRD_PERSON) {
        this->thirdPerson ^= 1u;
    }
    if (option == (const Options::Option *)&Options::Option::ANAGLYPH) {
        this->anaglyphEnabled ^= 1u;
    }
    if (option == (const Options::Option *)&Options::Option::LIMIT_FRAMERATE) {
        this->limitFramerate ^= 1u;
    }
    if (option == (const Options::Option *)&Options::Option::DIFFICULTY) {
        this->difficulty = ((uint8_t)value + (uint8_t)this->difficulty) & 3;
    }
    if (option == (const Options::Option *)&Options::Option::GRAPHICS) {
        this->fancyGraphics ^= 1u;
    }
    if (option == (const Options::Option *)&Options::Option::AMBIENT_OCCLUSION) {
        this->ambientOcclusion ^= 1u;
    }
    this->save();
}

void Options::update(std::vector<std::string>& optionStrings) {
    for (int i = 0; i < optionStrings.size() - 1; i += 2) {
        std::string key = optionStrings[i];
        std::string value = optionStrings[i + 1];
        if (key == OptionStrings::Multiplayer_Username) {
            this->username = value;
        }
        if (key == OptionStrings::Multiplayer_ServerVisible) {
            Options::readBool(value, this->serverVisible);
        }
        if (key == OptionStrings::Controls_Sensitivity) {
            float sensitivityValue;
            if (Options::readFloat(value, sensitivityValue)) {
                this->sensitivity = (powf(sensitivityValue * 1.1f, 1.3f) * 0.42f) + 0.3f;
            }
        }
        if (key == OptionStrings::Controls_InvertMouse) {
            Options::readBool(value, this->invertMouse);
        }
        if (key == OptionStrings::Controls_IsLefthanded) {
            Options::readBool(value, this->isLeftHanded);
        }
        if (key == OptionStrings::Controls_FeedbackVibration) {
            Options::readBool(value, this->feedbackVibration);
        }
        if (key == OptionStrings::Graphics_Fancy) {
            Options::readBool(value, this->fancyGraphics);
        }
        if (key == OptionStrings::Graphics_LowQuality) {
            bool enabled;
            if (Options::readBool(value, enabled)) {
                if (enabled) {
                    this->renderDistance = 3;
                    this->fancyGraphics = false;
                }
            }
        }
    }
}