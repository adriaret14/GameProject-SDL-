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

#include "Texto.h"
class Boton
{
public:
	Boton( Texto );
	~Boton();

	void play();
	void exit();
	void draw();

	Texto texto;
};

