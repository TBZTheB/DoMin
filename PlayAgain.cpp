#include "PlayAgain.h"

#include "SDL.h"

#include "Texture.h"
#include "Game.h"
#include "Box.h"
using namespace std;
bool PlayAgain::playAgain = false;

PlayAgain::PlayAgain()
{
}


PlayAgain::~PlayAgain()
{
}

void PlayAgain::endScreen(const int& winW, const int& winH)
{
	if (!Game::quit)
	{
		wait = true;

		SDL_SetWindowSize(Game::window, winW, winH);
		SDL_SetWindowPosition(Game::window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

		if (Game::win)
		{
			Texture::drawTexture("image/winScreen.png");
		}
		else
		{
			Texture::drawTexture("image/loseScreen.png");
		}
		while (wait)
		{
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					playAgain = false;
					wait = false;
					break;
				case SDL_MOUSEBUTTONDOWN:
					if (yesButton.insquare(event.button.x, event.button.y))
					{
						playAgain = true;
						wait = false;
					}
					else if (noButton.insquare(event.button.x, event.button.y))
					{
						playAgain = false;
						wait = false;
					}
				default:
					break;
				}
			}
		}
	}
	else
	{
		playAgain = false;
	}
}
