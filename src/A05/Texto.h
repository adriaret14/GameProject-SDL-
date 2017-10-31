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
class Texto
{
public:
	Texto(SDL_Renderer &, std::string , std::string, int, std::vector<int>, SDL_Color);
	~Texto();

	void draw();

	std::string texto;
	std::string path;
	int size;
	std::vector<int> posicion;

	SDL_Texture *textura;
	SDL_Rect rect;
	SDL_Renderer &renderer;
	SDL_Color color;
};

