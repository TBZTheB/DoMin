#pragma once

#include "SDL.h"

#include "Box.h"

const square yesButton(210, 614, 79, 53);
const square noButton(316, 614, 79, 53);

class PlayAgain
{
public:
	static bool playAgain;

	PlayAgain();
	~PlayAgain();

	void endScreen(const int& winW,const int& winH);

private:
	SDL_Event event;
	bool wait;
};

