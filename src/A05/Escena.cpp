#include "Escena.h"


Escena::Escena(std::string bgid, int width, int height)
{
	if (bgid == "MENU_BG")
		Renderer::Instance()->LoadTexture(MENU_BG, PATH_IMG + "bg.jpg");
	else
		Renderer::Instance()->LoadTexture(PLAY_BG, PATH_IMG + "bgCastle.jpg");

	bg = SDL_Rect{ 0, 0, width, height };
}

Escena::~Escena()
{
}
