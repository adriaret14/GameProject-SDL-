#include <SDL.h>		// Always needs to be included for an SDL app
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#pragma once
class Moneda
{
public:
	Moneda( SDL_Renderer &, std::string, std::vector<Moneda>, int, int, int );
	~Moneda();
	
	void respawn( std::vector<Moneda>, int, int, int );
	void draw();

	SDL_Renderer &renderer;
	SDL_Rect rect;
	SDL_Texture *textura;
};

