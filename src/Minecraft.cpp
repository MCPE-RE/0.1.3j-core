#include "Minecraft.h"
#include "client/gui/Button.h"
#include "client/gui/screens/StartMenuScreen.h"
#include "client/gui/Gui.h"
#include "client/input/keyboard/Keyboard.h"

Minecraft::Minecraft() :
    screenChooser(this),
    guiPixelCalc(1.0f),
    invGuiPixelCalc(1.0f) {
    this->screen = NULL;
    this->screenInUse = 0;
	// First field may be "joiningNetwork"

	// Field after screen chooser is *Font
}

void Minecraft::init() {
	checkGlError();  // "Init enter"

	this->touchScreenEnabled = this->platform()->isTouchscreen();

    this->options.initDefaultValues();
    this->textures = new Textures(&this->options, this->platform());
    // TODO: class WaterTexture, WaterSideTexture
    this->levelRenderer = new LevelRenderer(this, this->textures);
    this->font = new Font(&this->options, "font/default.png", this->textures);
    this->width = this->platform()->getScreenWidth();
    this->height = this->platform()->getScreenHeight();
    this->setScreen(new StartMenuScreen());
    //this->screen.init(this, this->platform()->getScreenWidth(), this->platform()->getScreenHeight());

    // "Init complete"
}

void Minecraft::update() {
    this->setSize(this->platform()->getScreenWidth(), this->platform()->getScreenHeight());

    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, this->platform()->getScreenWidth(), this->platform()->getScreenHeight());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    #ifndef USE_DESKTOP_GL
    glOrthof(0, this->platform()->getScreenWidth() * Gui::InvGuiScale, this->platform()->getScreenHeight() * Gui::InvGuiScale, 0, 2000.0, 3000.0);
    #else
    glOrtho(0, this->platform()->getScreenWidth() * Gui::InvGuiScale, this->platform()->getScreenHeight() * Gui::InvGuiScale, 0, 2000.0, 3000.0);
    #endif
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -2000.0);

    glClearColor(1, 1, 1, 1);

    this->screenInUse = true;
    this->screen->tick();
    this->screen->render(0, 0, 0);
    this->screen->updateEvents();
    Keyboard::reset();
    this->screenInUse = false;
    if (this->hasScreenToBeSet) {
        this->hasScreenToBeSet = false;
        this->setScreen(this->screenToBeSet);
    }
}

void Minecraft::tickInput() {
    // if (this->unknown3 != NULL && this->unknown3->)
}

bool Minecraft::isTouchScreen() {
	return false; //this->touchScreenEnabled;
}

void Minecraft::reloadOptions() {
    
}

void Minecraft::onGraphicsReset() {
    this->textures->clear();
    this->font->onGraphicsReset();
    // TODO: GUI
    // TODO: Gamerenderer
    if (this->levelRenderer)
    {
        this->levelRenderer->onGraphicsReset();
    }
}

void Minecraft::setScreen(Screen *screen) {
	if (this->screenInUse) {
		this->hasScreenToBeSet = true;
		this->screenToBeSet = screen;
	} else {
        if (!screen || !screen->isErrorScreen()) {
            if (this->screen) {
                this->screen->removed();
                delete this->screen;
            }
            this->screen = screen;
            if (screen) {
                // this->releaseMouse();
				uint32_t scaledWidth = (uint32_t)((float)this->width * Gui::InvGuiScale);
                uint32_t scaledHeight = (uint32_t)((float)this->height * Gui::InvGuiScale);
                screen->init(this, scaledWidth, scaledHeight);
            } else {
                // this->grabMouse();
            }
        }
	}
}

void Minecraft::setSize(int32_t width, int32_t height) {
    this->width = width;
    this->height = height;

    if (this->width <= 999) {
        if (this->width <= 799) {
            if (this->width <= 399) {
                Gui::InvGuiScale = 1.0;
            } else {
                Gui::InvGuiScale = 0.5;
            }
        } else {
            Gui::InvGuiScale = 0.33333;
        }
    } else {
        Gui::InvGuiScale = 0.25;
    }

    AppPlatform *platform = this->platform();
    if (platform) {
        float ppm = platform->getPixelsPerMillimeter();
        this->guiPixelCalc.setPixelsPerMillimeter(ppm);
        this->invGuiPixelCalc.setPixelsPerMillimeter(ppm);
    }

    if (this->screen) {
        uint32_t scaledWidth = (uint32_t)((float)this->width * Gui::InvGuiScale);
        uint32_t scaledHeight = (uint32_t)((float)this->height * Gui::InvGuiScale);
        this->screen->setSize(scaledWidth, scaledHeight);
    }

    if (this->touchInputHolder) {
        //this->touchInputHolder->setScreenSize(this->width, this->height);
    }
}

bool Minecraft::isLevelGenerated() {
    return this->level != nullptr && this->unknown5 != 1;
}

Minecraft::~Minecraft() {
	// TODO Auto-generated destructor stub
}

/* void checkGlErrors() {
	GLenum err;
	while((err = glGetError()) != GL_NO_ERROR)
	{
		// TODO: log errors just in debug build, remove in prod
	}
} */
