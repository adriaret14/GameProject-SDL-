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

enum COLOR { VERDE, ROJO, NARANJA, AZUL, GRIS, ROSA, ORO, MARRON };
enum DIREC { DOWN, LEFT, RIGHT, UP };

class Jugador
{
public:
	Jugador( SDL_Renderer &, std::string, COLOR, int, int, DIREC, int, int );
	~Jugador();

	int score;

	void update();
	void draw();

	SDL_Renderer &renderer;
	SDL_Rect rect, pos;
	SDL_Texture *textura;

	int xmult;
	int ymult;

	int fw;
	int fh;

	int sentido;
	int step;

	bool moving;

	DIREC dir;
};

