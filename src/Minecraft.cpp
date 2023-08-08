#include "Minecraft.h"
#include "client/gui/Button.h"
#include "client/gui/screens/StartMenuScreen.h"

Minecraft::Minecraft() : screenChooser(this) {
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
#include "client/input/keyboard/Keyboard.h"

void Minecraft::update() {
    this->width = this->platform()->getScreenWidth();
    this->height = this->platform()->getScreenHeight();
    float scale = (this->width <= 999) ? ((this->width <= 799) ? ((this->width <= 399) ? 1.0 : 0.5) : 0.33333) : 0.25f;

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
    glOrthof(0, this->platform()->getScreenWidth() * scale, this->platform()->getScreenHeight() * scale, 0, 2000.0, 3000.0);
    #else
    glOrtho(0, this->platform()->getScreenWidth() * scale, this->platform()->getScreenHeight() * scale, 0, 2000.0, 3000.0);
    #endif
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -2000.0);

    glClearColor(1, 1, 1, 1);

    this->screen->setSize(this->width * scale, this->height * scale);

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
                float scale = (this->width <= 999) ? ((this->width <= 799) ? ((this->width <= 399) ? 1.0 : 0.5) : 0.33333) : 0.25f;
				screen->init(this, this->width * scale, this->height * scale);
            } else {
                // this->grabMouse();
            }
        }
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
