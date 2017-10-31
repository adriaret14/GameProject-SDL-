#include "Menu.h"



Menu::Menu( SDL_Renderer &r, Background &bg, Boton &b1, Boton &b2 ) :
	renderer(r),
	background(bg),
	bPlay(b1),
	bExit(b2)
{
}


Menu::~Menu()
{
}

void Menu::draw()
{
	background.draw();
	bPlay.draw();
	bExit.draw();
}
