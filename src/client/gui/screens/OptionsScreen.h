#ifndef OPTIONSSCREEN_H_
#define OPTIONSSCREEN_H_

#include "../Screen.h"

class OptionsScreen : public Screen {
public:
    using Screen::init;

	int32_t dialogCreationStep;

	void init();

    void removed();

	void render(uint32_t x, uint32_t y, float unknown2);
};

#endif /* OPTIONSSCREEN_H_ */