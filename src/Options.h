#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <iostream>
#include <cstdint>
#include <vector>
#include "KeyMapping.h"

class Options {
public:
    class Option {
    public:
        static Option THIRD_PERSON;
        static Option LIMIT_FRAMERATE;
        static Option SOUND;
        static Option MUSIC;
        static Option GUI_SCALE;
        static Option DIFFICULTY;
        static Option ANAGLYPH;
        static Option GRAPHICS;
        static Option AMBIENT_OCCLUSION;
        static Option VIEW_BOBBING;
        static Option RENDER_DISTANCE;
        static Option SENSITIVITY;
        static Option INVERT_MOUSE;

        bool isProgressValue;
        bool isBooleanValue;
        std::string name;
        int32_t id;

        Option(int32_t id, const std::string& name, bool isProgressValue, bool isBooleanValue);
    };

    float musicVolume; // *(_DWORD *)this
    float soundVolume; // *((_DWORD *)this + 1)
    float sensitivity; // *((_DWORD *)this + 2)
    bool invertMouse; // *((_BYTE *)this + 12)
    uint32_t renderDistance; // *((_DWORD *)this + 4)
    bool viewBobbing; // *((_BYTE *)this + 20)
    bool anaglyphEnabled; // *((_BYTE *)this + 21)
    bool limitFramerate; // *((_BYTE *)this + 22)
    bool fancyGraphics; // *((_BYTE *)this + 23)
    bool ambientOcclusion; // *((_BYTE *)this + 24)
    uint8_t unknown9; // *((_BYTE *)this + 25)
    bool isLeftHanded; // *((_BYTE *)this + 26)
    bool feedbackVibration; // *((_BYTE *)this + 27)
    std::string unknown12; // (char *)this + 28
    KeyMapping keyForward; // (int)v1 + 52
    KeyMapping keyLeft; // (int)v1 + 80
    KeyMapping keyBack; // (int)v1 + 108
    KeyMapping keyRight; // (int)v1 + 136
    KeyMapping keyJump; // (int)v1 + 164
    KeyMapping keyInventory; // (int)v1 + 192
    KeyMapping keyDrop; // (int)v1 + 220
    KeyMapping keyChat; // (int)v1 + 248
    KeyMapping keyFog; // (int)v1 + 276
    KeyMapping keySneak; // (int)v1 + 304
    KeyMapping keyDestory; // (int)v1 + 332
    KeyMapping keyUse; // (int)v1 + 360
    KeyMapping keyMenuNext; // (int)v1 + 388
    KeyMapping keyMenuPrevious; // (int)v1 + 416
    KeyMapping keyMenuOk; // (int)v1 + 444
    KeyMapping keyMenuCancel; // (int)v1 + 472
    KeyMapping *keyForwardPointer; // *((_DWORD *)v1 + 125)
    KeyMapping *keyLeftPointer; // *((_DWORD *)v1 + 126)
    KeyMapping *keyBackPointer; // *((_DWORD *)v1 + 127)
    KeyMapping *keyRightPointer; // *((_DWORD *)v1 + 128)
    KeyMapping *keyJumpPointer; // *((_DWORD *)v1 + 129)
    KeyMapping *keySneakPointer; // *((_DWORD *)v1 + 130)
    KeyMapping *keyDropPointer; // *((_DWORD *)v1 + 131)
    KeyMapping *keyInventoryPointer; // *((_DWORD *)v1 + 132)
    KeyMapping *keyChatPointer; // *((_DWORD *)v1 + 133)
    KeyMapping *keyFogPointer; // *((_DWORD *)v1 + 134)
    KeyMapping *keyDestoryPointer; // *((_DWORD *)v1 + 135)
    KeyMapping *keyUsePointer; // *((_DWORD *)v1 + 136)
    KeyMapping *keyMenuNextPointer; // *((_DWORD *)v1 + 137)
    KeyMapping *keyMenuPreviousPointer; // *((_DWORD *)v1 + 138)
    KeyMapping *keyMenuOkPointer; // *((_DWORD *)v1 + 139)
    KeyMapping *keyMenuCancelPointer; // *((_DWORD *)v1 + 140)
    uint32_t unknown45; // *((_DWORD *)v1 + 141)
    uint32_t difficulty; // *((_DWORD *)this + 142)
    uint8_t unknown47; // *((_BYTE *)this + 572)
    bool thirdPerson; // *((_BYTE *)this + 573)
    uint8_t unknown49; // *((_BYTE *)this + 574)
    uint8_t unknown50; // *((_BYTE *)this + 575)
    uint8_t unknown51; // *((_BYTE *)this + 576)
    uint8_t unknown52; // *((_BYTE *)this + 577)
    float unknown53; // *((_DWORD *)this + 145)
    float unknown54; // *((_DWORD *)this + 146)
    uint32_t guiScale; // *((_DWORD *)this + 147)
    std::string username; // (char *)v1 + 592
    bool serverVisible; // *((_BYTE *)v1 + 616)

    Options();
    
    bool getBooleanValue(const Option *option);

    std::string getMessage(const Option *option);

    float getProgressValue(const Option *option);

    void initDefaultValues();

    void load();

    static bool readBool(const std::string& input, bool& output);

    static bool readFloat(const std::string& input, float& output);

    static bool readInt(const std::string& input, int32_t& output);

    void save();

    void set(const Options::Option *option, float value);

    void toggle(const Options::Option *option, int32_t value);

    void update(std::vector<std::string>& optionStrings);
};

#endif