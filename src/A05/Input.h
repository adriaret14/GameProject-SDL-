#include <SDL.h>		// Always needs to be included for an SDL app
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#pragma once
class Input
{
public:
	Input();
	~Input();

	void update();
	std::vector<int> getMousePos();
	SDL_Event event;

	int escena;

	bool w;
	bool a;
	bool s;
	bool d;

	bool up;
	bool left;
	bool down;
	bool right;

	bool mouse;
	bool esc;
	bool quit;
};

