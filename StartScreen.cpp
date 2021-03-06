#include "StartScreen.h"

#include <string>
#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "Texture.h"
#include "Box.h"
using namespace std;
StartScreen::StartScreen()
{
	wait = true;
	width = "";
	height = "";
	mine = "";
	wBox = false;
	hBox = false;
	mBox = false;
	choosedLine = Texture::loadTexture("image/choosedLine.png");
	unchoosedLine = Texture::loadTexture("image/unchoosedLine.png");
	emptyLine = Texture::loadTexture("image/emptyLine.png");
}
StartScreen::~StartScreen()
{
	SDL_DestroyTexture(choosedLine);
	SDL_DestroyTexture(unchoosedLine);
	SDL_DestroyTexture(emptyLine);
}
void StartScreen::pressStart()
{
	bool _wait = true;

	Texture::drawTexture("image/startScreen1.png");
	while (_wait)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				SDL_Quit();
				Game::isRunning = false;
				Game::quit = true;
				wait = false;
				_wait = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button = SDL_BUTTON_LEFT && startButton.insquare(event.button.x, event.button.y))
				{
					_wait = false;
				}
			default:
				break;

			}
		}
	}
}

void StartScreen::loadInputScreen()
{
	Texture::drawTexture("image/startScreen2.png");
}
bool StartScreen::inputingSize()
{
	return wait;
}

void StartScreen::handleInput()
{
	while (SDL_PollEvent(&event))
	{
		updateInput();
	}
}

void StartScreen::updateInput()
{
	switch (event.type)
	{
	case SDL_QUIT:
		Game::isRunning = false;
		Game::quit = true;
		wait = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			if (widthBox.insquare(event.button.x, event.button.y))
			{
				wBox = true;
				hBox = false;
				mBox = false;
			}
			else if (heightBox.insquare(event.button.x, event.button.y))
			{
				wBox = false;
				hBox = true;
				mBox = false;
			}
			else if (mineBox.insquare(event.button.x, event.button.y))
			{
				wBox = false;
				hBox = false;
				mBox = true;
			}
			else if (playButton.insquare(event.button.x, event.button.y))
			{
				if (Game::width == 0 || Game::height == 0 || Game::numMines == 0)
				{
					cout << "Input all and diverse 0.\n";

				}
				else if (Game::width > MAX_WIDTH || Game::height > MAX_HEIGHT)
				{
					cout << "The map is too large.___\n";

				}
				else if (Game::width * Game::height < Game::numMines)
				{
					cout << "Has too many mines.____ \n";
				}
				else
				{
					wait = false;
				}
			}
			else
			{
				wBox = false;
				hBox = false;
				mBox = false;
			}
		}
		break;
	case SDL_TEXTINPUT:
		inputChar = event.text.text[0];
		if (inputChar >= '0' && inputChar <= '9')
		{
			if (wBox && width.length() < MAX_INPUT_LENGTH)
			{
				width += event.text.text;
				Game::width *= 10;
				Game::width += (int)(inputChar - 48);
			}
			else if (hBox && height.length() < MAX_INPUT_LENGTH)
			{
				height += event.text.text;
				Game::height *= 10;
				Game::height += (int)(inputChar - 48);

			}
			else if (mBox && mine.length() < MAX_INPUT_LENGTH)
			{
				mine += event.text.text;
				Game::numMines*=10;
				Game::numMines+=(int)(inputChar-48);

			}
		}
		break;
	case SDL_KEYDOWN:
		if (wBox && event.key.keysym.sym == SDLK_BACKSPACE && width.length() > 0)
		{
			width.pop_back();
			Game::width /= 10;

		}
		else if (hBox && event.key.keysym.sym == SDLK_BACKSPACE && height.length() > 0)
		{
			height.pop_back();
			Game::height /= 10;
		}
		else if (mBox && event.key.keysym.sym == SDLK_BACKSPACE && mine.length() > 0)
		{
			mine.pop_back();
			Game::numMines /= 10;
		}
		else if (event.key.keysym.sym == SDLK_TAB || event.key.keysym.sym == SDLK_DOWN)
		{
			if (wBox)
			{
				wBox = false;
				hBox = true;
				mBox = false;
			}
			else if (hBox)
			{
				wBox = false;
				hBox = false;
				mBox = true;
			}
			else if (mBox)
			{
				wBox = true;
				hBox = false;
				mBox = false;
			}
		}
		else if (event.key.keysym.sym == SDLK_UP)
		{
			if (wBox)
			{
				wBox = false;
				hBox = false;
				mBox = true;
			}
			else if (hBox)
			{
				wBox = true;
				hBox = false;
				mBox = false;
			}
			else if (mBox)
			{
				wBox = false;
				hBox = true;
				mBox = false;
			}
		}
		break;
	default:
		break;
	}
}

void StartScreen::renderInput()
{
	if (wBox)
	{
		Texture::drawTexture(choosedLine, widthBox.x - 1, widthBox.y - 1);
		Texture::drawText(width, widthBox.createDesRect());
	}
	else
	{
		Texture::drawTexture(unchoosedLine, widthBox.x - 1, widthBox.y - 1);
	}
	if (hBox)
	{
		Texture::drawTexture(choosedLine, heightBox.x - 1, heightBox.y - 1);
		Texture::drawText(height, heightBox.createDesRect());
	}
	else
	{
		Texture::drawTexture(unchoosedLine, heightBox.x - 1, heightBox.y - 1);
	}
	if (mBox)
	{
		Texture::drawTexture(choosedLine, mineBox.x - 1, mineBox.y - 1);
		Texture::drawText(mine, mineBox.createDesRect());
	}
	else
	{
		Texture::drawTexture(unchoosedLine, mineBox.x - 1, mineBox.y - 1);
	}
}

void StartScreen::cleanInput()
{
	wait = true;
	width = "";
	height = "";
	mine = "";
	wBox = false;
	hBox = false;
	mBox = false;
}
