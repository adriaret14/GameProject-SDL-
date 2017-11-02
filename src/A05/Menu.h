#include "Escena.h"
#include "Constants.h"
#include <string>

#pragma once
class Menu : public Escena
{
public:
	Menu(int, int);
	~Menu();

	void draw();

	SDL_Rect bgrect;
	SDL_Rect playrect;
	SDL_Rect exitrect;
};

