#include "Input.h"



Input::Input()
{
	quit = false;
	escena = 0;
	update();
	
}


Input::~Input()
{
}

void Input::update()
{
	
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
				esc = true;
			if (event.key.keysym.sym == SDLK_w)
				w = true;
			if (event.key.keysym.sym == SDLK_s)
				s = true;
			if (event.key.keysym.sym == SDLK_d)
				d = true;
			if (event.key.keysym.sym == SDLK_a)
				a = true;
			if (event.key.keysym.sym == SDLK_UP)
				up = true;
			if (event.key.keysym.sym == SDLK_DOWN)
				down = true;
			if (event.key.keysym.sym == SDLK_RIGHT)
				right = true;
			if (event.key.keysym.sym == SDLK_LEFT)
				left = true;
			break;
		case SDL_KEYUP:
			if (event.key.keysym.sym == SDLK_ESCAPE)
				esc = false;
			if (event.key.keysym.sym == SDLK_w)
				w = false;
			if (event.key.keysym.sym == SDLK_s)
				s = false;
			if (event.key.keysym.sym == SDLK_d)
				d = false;
			if (event.key.keysym.sym == SDLK_a)
				a = false;
			if (event.key.keysym.sym == SDLK_UP)
				up = false;
			if (event.key.keysym.sym == SDLK_DOWN)
				down = false;
			if (event.key.keysym.sym == SDLK_RIGHT)
				right = false;
			if (event.key.keysym.sym == SDLK_LEFT)
				left = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			mouse = true;
			break;
		case SDL_MOUSEBUTTONUP:
			mouse = false;
			break;
		default:;
		}
	}
}

std::vector<int> Input::getMousePos()
{
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	return std::vector<int>(mouseX, mouseY);
}
