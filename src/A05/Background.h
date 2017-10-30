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
class Background
{
public:
	Background( SDL_Renderer &, std::string );
	~Background();

	SDL_Renderer &renderer;
	SDL_Texture *bgTextura;
	SDL_Rect	 bgRect;
};

