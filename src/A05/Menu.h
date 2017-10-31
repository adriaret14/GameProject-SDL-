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
#include "Boton.h"
#include "Background.h"
class Menu
{
public:
	Menu( SDL_Renderer & , Background &, Boton &, Boton & );
	~Menu();

	void draw();

	//Renderer
	SDL_Renderer &renderer;

	//Background
	Background &background;

	//Botón play
	Boton &bPlay;

	//Botón exit
	Boton &bExit;


};

