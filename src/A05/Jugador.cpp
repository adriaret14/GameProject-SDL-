#include "Jugador.h"

Jugador::Jugador(SDL_Renderer & r, std::string path, COLOR c, int x, int y, DIREC d, int frameWidth, int frameHeight) :
	renderer(r),
	dir(d)
{
	SDL_Texture *jugador(IMG_LoadTexture(&renderer, path.c_str()));
	if (jugador == nullptr) throw "No se han podido cargar las texturas del jugador 1";
	textura = jugador;
	pos.x = x;
	pos.y = y;
	switch (c)
	{

	}
	rect.x = frameWidth*xmult;;
	rect.y = frameHeight*ymult;
	pos.h = rect.h = frameHeight;
	pos.w = rect.w = frameWidth;
}

Jugador::~Jugador()
{
}
