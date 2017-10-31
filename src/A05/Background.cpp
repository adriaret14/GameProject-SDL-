#include "Background.h"



Background::Background(SDL_Renderer &r, std::string p, int screenWidth, int screenHeight) :
	renderer(r)
{
	SDL_Texture *tmpTexture{ IMG_LoadTexture(&renderer, p.c_str()) };
	if (tmpTexture == nullptr) throw "No se han podido cargar as texturas";
	bgTextura = tmpTexture;
	SDL_Rect tmpRect{ 0, 0, screenWidth, screenHeight };
	bgRect = tmpRect;
}


Background::~Background()
{
	SDL_DestroyTexture(bgTextura);
}

void Background::draw()
{
	SDL_RenderCopy(&renderer, bgTextura, nullptr, &bgRect);
}
