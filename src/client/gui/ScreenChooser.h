#ifndef SCREENCHOOSER_H_
#define SCREENCHOOSER_H_

class Minecraft;

// May not have sense to declare a separate header
enum ScreenId {
	START_MENU = 1,
	JOIN_GAME,
	PAUSE_0,  // TODO
	PAUSE_1,  // TODO
	SELECT_WORLD,
	INGAME_BLOCK_SELECTION
};

class ScreenChooser {
public:
	ScreenChooser(Minecraft *mc);

	void setScreen(ScreenId id);
private:
	Minecraft *minecraft;
};

#endif /* SCREENCHOOSER_H_ */
