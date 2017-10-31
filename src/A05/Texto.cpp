#include "Texto.h"



Texto::Texto(SDL_Renderer &r, std::string p, std::string t, int s, std::vector<int> pos, SDL_Color col) :
	path(p),
	texto(t),
	size(s),
	renderer(r),
	posicion(pos),
	color(col)
{
	TTF_Font *font{ TTF_OpenFont(path.c_str(), size) };
	if (font == nullptr) throw "No se puedde inicializar SDL_ttf en font";
	SDL_Surface *tmpSurf{ TTF_RenderText_Blended(font, texto.c_str(), color) };
	if (tmpSurf == nullptr) TTF_CloseFont(font), throw "No se puede crear la superficie de texto";
	SDL_Texture *tmpTexture{ SDL_CreateTextureFromSurface(&renderer, tmpSurf) };
	textura = tmpTexture;
	SDL_Rect tmpRect{ posicion[0], posicion[1], tmpSurf->w, tmpSurf->h };
	rect = tmpRect;
	SDL_FreeSurface(tmpSurf);
	TTF_CloseFont(font);
}

Texto::~Texto()
{
	SDL_DestroyTexture(textura);
}

void Texto::draw()
{
	SDL_RenderCopy(&renderer, textura, nullptr, &rect);
}
