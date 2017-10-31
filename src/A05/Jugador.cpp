#include "Jugador.h"

Jugador::Jugador(SDL_Renderer & r, std::string path, COLOR c, int x, int y, DIREC d, int frameWidth, int frameHeight) :
	renderer(r),
	dir(d),
	step(1),
	sentido(1),
	moving(false),
	score(0)
{
	SDL_Texture *jugador(IMG_LoadTexture(&renderer, path.c_str()));
	if (jugador == nullptr) throw "No se han podido cargar las texturas del jugador 1";
	textura = jugador;
	pos.x = x;
	pos.y = y;
	switch (c)
	{
	case VERDE:
		xmult = 0;
		ymult = 0;
		break;
	case ROJO:
		xmult = 1;
		ymult = 0;
		break;
	case NARANJA:
		xmult = 2;
		ymult = 0;
		break;
	case AZUL:
		xmult = 3;
		ymult = 0;
		break;
	case GRIS:
		xmult = 0;
		ymult = 1;
		break;
	case ROSA:
		xmult = 1;
		ymult = 1;
		break;
	case ORO:
		xmult = 2;
		ymult = 1;
		break;
	case MARRON:
		xmult = 3;
		ymult = 1;
		break;
	}
	rect.x = 3*frameWidth*xmult + step*frameWidth;
	rect.y = 4*frameHeight*ymult + dir*frameHeight;
	pos.h = rect.h = frameHeight;
	pos.w = rect.w = frameWidth;
}

Jugador::~Jugador()
{
	SDL_DestroyTexture(textura);
}

void Jugador::update()
{
	if (moving)
	{
		if (step != 1)
			sentido = -sentido;
		step += sentido;
	}

	rect.x = 3 * fw*xmult + step*fw;
	rect.y = 4 * fh*ymult + dir*fh;
}

void Jugador::draw()
{
	SDL_RenderCopy(&renderer, textura, &rect, &pos);
}
