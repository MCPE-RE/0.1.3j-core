#ifndef MINECRAFT_H_
#define MINECRAFT_H_

#include "App.h"
#include "client/renderer/gles.h"
#include "client/renderer/Textures.h"
#include "client/renderer/LevelRenderer.h"
#include "client/gui/Font.h"
#include "client/gui/Screen.h"
#include "client/gui/ScreenChooser.h"
#include "Level.h"
#include "PixelCalc.h"
#include "client/input/mouse/MouseHandler.h"

class Minecraft : public App {
public:
    using App::init;

    uint8_t isLocatingMultiplayer; // 28
    uint32_t width; // 32
    uint32_t height; // 36
    Options options; // 40

    uint8_t unknown17; // 65

    uint8_t unknown7; // 660
    void *unknown26; // 604
    LevelRenderer *levelRenderer; // 664
    void *gameRenderer; // 668
    void *particleEngine; // 672
    // TODO: class SoundEngine
    void *soundEngine; // 676
    // TODO: class SurvivalMode
    void *survivalMode;  // 680
    Textures *textures; // 684
    ScreenChooser screenChooser; // 688
    Font *font; // 692
    void *raknetInstance; // 696
    // TODO: class ClientSideNetworkHandler
    void *clientNetwork; // 700
    uint32_t unknown20; // 704
    uint32_t unknown13; // 708
    uint32_t unknown21; // 712
    // TODO: class User
    void *user; // 716
    Level *level; // 720
    // TODO: class LocalPlayer
    void *localPlayer; // 724
    // TODO: class TouchInputHolder
    void *touchInputHolder; // 728
    uint32_t unknown15; // 732
    // TODO: class Gui
    void *gui; // 736

    // TODO: class CThread
    void *thread; // 3368
    Screen *screen; // 3372
    // TODO: class MouseHandler
    MouseHandler mouseHandler; // 3376
    bool isMouseGrabbed; // 3392
    // TODO: class PixelCalc
    PixelCalc guiPixelCalc; // 3396
    // TODO: class PixelCalc
    PixelCalc invGuiPixelCalc; // 3404
    // TODO: class HitResult
    void *hitResult; // 3412
    void *unknown28; // 3444
    uint32_t unknown22; // 3452

    // TODO: class Timer
    void *timer; // 3480
    float unknown19; // 3496
    uint8_t unknown5; // 3516
    uint32_t unknown27; // 3520
    uint32_t unknown14; // 3524
    uint32_t unknown24; // 3528
    uint8_t powerVR; // 3525
    uint32_t unknown4; // 3532
    uint32_t unknown9; // 3536
    uint32_t unknown18; // 3540
    uint8_t screenInUse; // 3544
    uint8_t hasScreenToBeSet; // 3545
    Screen *screenToBeSet; // 3548
    uint32_t unknown25; // 3552
    bool touchScreenEnabled; // 3556

    static bool useAmbientOcclusion;

	Minecraft();

    void init();

    void update();

    void reloadOptions();

    void onGraphicsReset();

    bool isTouchScreen();

    void tickInput();

    // void generateLevel(const std::string &name);

    void setScreen(Screen *screen);

    void setSize(int32_t width, int32_t height);

    bool isLevelGenerated();

    void releaseMouse();

    void grabMouse();
};

#endif /* MINECRAFT_H_ */
