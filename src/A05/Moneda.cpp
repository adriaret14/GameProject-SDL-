#include "Moneda.h"



Moneda::Moneda( SDL_Renderer & r, std::string path, std::vector<Moneda> v, int screenWidth, int screenHeight, int horizon ) :
	renderer(r)
{
	rect.h = 32;
	rect.w = 32;
	SDL_Texture *moneda(IMG_LoadTexture(&renderer, "../../res/img/gold.png"));
	textura = moneda;
	bool flag;
	do
	{
		int x = 32 * (rand() % 24);
		int tmp = floor((screenHeight - horizon) / 32);
		int y = horizon + ((screenHeight - horizon) - tmp * 32) / 2 + 32 * (rand() % tmp);

		flag = true;
		for (int i = 0; i < v.size(); i++)
		{
			if (x == v[i].rect.x && y == v[i].rect.y)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			rect.x = x;
			rect.y = y;
		}
	} while (!flag);
	
}


Moneda::~Moneda()
{
}

void Moneda::respawn(std::vector<Moneda> v, int screenWidth, int screenHeight, int horizon)
{
	rect.h = 32;
	rect.w = 32;
	bool flag;
	do
	{
		int x = 32 * (rand() % 24);
		int tmp = floor((screenHeight - horizon) / 32);
		int y = horizon + ((screenHeight - horizon) - tmp * 32) / 2 + 32 * (rand() % tmp);

		flag = true;
		for (int i = 0; i < v.size(); i++)
		{
			if (x == v[i].rect.x && y == v[i].rect.y && i)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			rect.x = x;
			rect.y = y;
		}
	} while (!flag);
}
