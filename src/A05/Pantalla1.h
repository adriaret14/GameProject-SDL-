#pragma once
#include "Escena.h"
class Pantalla1 :
	public Escena
{
public:


	SDL_Rect bgrect;
	SDL_Rect horizon;
	SDL_Rect tPunt1;
	SDL_Rect nPunt1R;
	SDL_Rect nPunt1L;
	SDL_Rect tPunt2;
	SDL_Rect nPunt2R;
	SDL_Rect nPunt2L;
	std::vector<SDL_Rect> monedas;

	Pantalla1(int, int);
	~Pantalla1();

	void draw();
	void eventHandler();
	void update();
};

