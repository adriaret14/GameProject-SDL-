#include <SDL.h>		// Always needs to be included for an SDL app
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "Texto.h"
#include "Background.h"
#include "Input.h"
#include "Boton.h"
#include "Menu.h"
#include "Jugador.h"
#include "Moneda.h"

//Game general information
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FPS 60

bool colision(SDL_Rect r1, SDL_Rect r2)
{
	return (((r2.x > r1.x && r2.x < r1.x + r1.w) && (r2.y > r1.y && r2.y < r1.y + r1.h)) ||
		((r2.x + r2.w > r1.x && r2.x + r2.w < r1.x + r1.w) && (r2.y > r1.y && r2.y < r1.y + r1.h)) ||
		((r2.x > r1.x && r2.x < r1.x + r1.w) && (r2.y + r2.h > r1.y && r2.y + r2.h < r1.y + r1.h)) ||
		(((r2.x + r2.w > r1.x && r2.x + r2.w < r1.x + r1.w) && (r2.y + r2.h > r1.y && r2.y + r2.h < r1.y + r1.h))));
}

bool coorEnRect(std::vector<int> pos, SDL_Rect r)
{
	return ((pos[0] > r.x && pos[0] < r.x + r.w) && (pos[1] > r.y && pos[1] < r.y + r.h));
}

int main(int, char*[]) {

	// --- INIT ---
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw "No es pot inicialitzar SDL subsystems";

	if (TTF_Init() != 0) throw "No se puede inciiar SDL_ttf";

	const Uint8 mixFlags{ MIX_INIT_MP3 | MIX_INIT_OGG };
	if (!(Mix_Init(mixFlags) & mixFlags)) throw "Error: SDL_mixer init";


	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };
	if (!(IMG_Init(imgFlags) & imgFlags)) throw "Error: SDL_image init";

	// --- WINDOW ---
	SDL_Window *window{ SDL_CreateWindow("SDL...", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN) };
	if (window == nullptr) throw "No es pot inicialitzar SDL_Window";

	// --- RENDERER ---
	SDL_Renderer *renderer{ SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) };
	if (renderer == nullptr) throw "No es pot inicialitzar SDL_Renderer";

	// --- SPRITES ---
	Background bg0(*renderer, std::string("../../res/img/bg.jpg"), SCREEN_WIDTH, SCREEN_HEIGHT);
	Boton play(Texto(*renderer, "../../res/ttf/MarioLuigi2.ttf", "PLAY", 80, std::vector<int>{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3}, SDL_Color{ 0, 255, 0, 255 }));
	Boton exit(Texto(*renderer, "../../res/ttf/MarioLuigi2.ttf", "EXIT", 80, std::vector<int>{SCREEN_WIDTH / 2, 2*SCREEN_HEIGHT / 3}, SDL_Color{ 255, 0, 0, 255 }));
	Menu menu(*renderer, bg0, play, exit);

	Background bg1(*renderer, std::string("../../res/img/bgCastle.jpg"), SCREEN_WIDTH, SCREEN_HEIGHT);
	Jugador jugador1(*renderer, std::string("../../res/img/spCastle.png"), ROJO, 20, 200, DOWN, 32, 32);
	Jugador jugador2(*renderer, std::string("../../res/img/spCastle.png"), AZUL, 20, 200, UP, 32, 32);
	Texto horizon(*renderer, "../../res/ttf/MarioLuigi2.ttf", "---------------------------- - ", 80, std::vector<int>{5, 140}, SDL_Color{ 0, 0, 0, 255 });
	std::vector<Moneda> monedas;
	for (int i = 0; i < 5; i++)
	{
		monedas.push_back( Moneda( *renderer, "../../res/img/gold.png", monedas, SCREEN_WIDTH, SCREEN_HEIGHT, 140 ) );
	}

	Input control;

	control.escena = 0;
	srand (time(NULL));

	/*
	SDL_Texture *numeros(IMG_LoadTexture(renderer, "../../res/img/num.png"));
	if (numeros == nullptr) throw "No se han pudido cargar las texturas de los numericos";
	SDL_Rect RLnum1, LnumPos1, RRnum1, RnumPos1;
	int numWidth, numHeight, numFrameWidth, numFrameHeight;
	SDL_QueryTexture(numeros, NULL, NULL, &numWidth, &numHeight);
	numFrameWidth = 72;
	numFrameHeight = 77;
	LnumPos1.x = 100;
	LnumPos1.y = 45;
	RnumPos1.x = 148;
	RnumPos1.y = 45;
	RLnum1.x = 0;
	RLnum1.y = 0;
	RRnum1.x = 0;
	RRnum1.y = 0;
	RLnum1.h = RRnum1.h = numFrameHeight;
	LnumPos1.h = 51;
	RnumPos1.h = 51;
	RLnum1.w = RRnum1.w = numFrameWidth;
	LnumPos1.w = 48;
	RnumPos1.w = 48;

	SDL_Rect RLnum2, LnumPos2, RRnum2, RnumPos2;
	numFrameWidth = 72;
	numFrameHeight = 77;
	LnumPos2.x = 100;
	LnumPos2.y = 96;
	RnumPos2.x = 148;
	RnumPos2.y = 96;
	RLnum2.x = 0;
	RLnum2.y = 0;
	RRnum2.x = 0;
	RRnum2.y = 0;
	RLnum2.h = RRnum2.h = numFrameHeight;
	LnumPos2.h = 51;
	RnumPos2.h = 51;
	RLnum2.w = RRnum2.w = numFrameWidth;
	LnumPos2.w = 48;
	RnumPos2.w = 48;
	*/
	


		// --- Animated Sprite ---

	


	// --- AUDIO ---
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		throw "Unable to initialize SDL_mixer audio systems";
	}
	Mix_Music *soundtrack{ Mix_LoadMUS("../../res/au/mainTheme.mp3") };
	if (!soundtrack) throw "Unable to load the Mix_Music sountrack";
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	Mix_PlayMusic(soundtrack, -1);

	// --- GAME LOOP ---
	bool isRunning = true;
	while (isRunning) {
		// HANDLE EVENTS

		//Colisiones con monedas jugador1
		
		for each (Moneda m in monedas)
		{
			if (colision(jugador1.rect, m.rect))
			{
				m.respawn(monedas, SCREEN_WIDTH, SCREEN_HEIGHT, 140);
				jugador1.score++;
			}
		}

		//Colisiones con monedas jugador2
		for each (Moneda m in monedas)
		{
			if (colision(jugador2.rect, m.rect))
			{
				m.respawn(monedas, SCREEN_WIDTH, SCREEN_HEIGHT, 140);
				jugador2.score++;
			}
		}

		control.update();

		if (control.escena == 1)
		{

			//Controles jugador 1
			if (control.w)
			{
				if (jugador1.pos.y >= 140 + 20)
				{
					jugador1.pos.y = jugador1.pos.y - 5;
					jugador1.dir = UP;
					jugador1.moving = true;
				}

			}
			if (control.s)
			{
				if (jugador1.pos.y <= 600 - 32)
				{
					jugador1.pos.y = jugador1.pos.y + 5;
					jugador1.dir = DOWN;
					jugador1.moving = true;
				}

			}
			if (control.a)
			{
				if (jugador1.pos.x >= -32)
				{
					jugador1.pos.x = jugador1.pos.x - 5;
					jugador1.dir = LEFT;
					jugador1.moving = true;
				}
				else
				{
					jugador1.pos.x = 800;
				}

			}
			if (control.d)
			{
				if (jugador1.pos.x <= 800)
				{
					jugador1.pos.x = jugador1.pos.x + 5;
					jugador1.dir = RIGHT;
					jugador1.moving = true;
				}
				else
				{
					jugador1.pos.x = -32;
				}
			}
			if (!control.w && !control.a && !control.s && !control.d)
			{
				jugador1.moving = false;
			}

			//Controles jugador 2
			if (control.up)
			{
				if (jugador2.pos.y >= 140 + 20)
				{
					jugador2.pos.y = jugador2.pos.y - 5;
					jugador2.dir = UP;
					jugador2.moving = true;
				}

			}
			if (control.down)
			{
				if (jugador2.pos.y <= 600 - 32)
				{
					jugador2.pos.y = jugador2.pos.y + 5;
					jugador2.dir = DOWN;
					jugador2.moving = true;
				}

			}
			if (control.left)
			{
				if (jugador2.pos.x >= -32)
				{
					jugador2.pos.x = jugador2.pos.x - 5;
					jugador2.dir = LEFT;
					jugador2.moving = true;
				}
				else
				{
					jugador2.pos.x = 800;
				}

			}
			if (control.right)
			{
				if (jugador2.pos.x <= 800)
				{
					jugador2.pos.x = jugador2.pos.x + 5;
					jugador2.dir = RIGHT;
					jugador2.moving = true;
				}
				else
				{
					jugador2.pos.x = -32;
				}
			}
			if (!control.up && !control.left && !control.down && !control.right)
			{
				jugador2.moving = false;
			}

			//Otros
			if (control.esc)
			{
				control.escena = 0;
			}
		}
		else if (control.escena == 0)
		{
			if (control.esc)
			{
				isRunning = false;
			}
			if (control.mouse)
			{
				if (coorEnRect(control.getMousePos(), play.texto.rect))
				{
					control.escena = 1;
				}
				if (coorEnRect(control.getMousePos(), exit.texto.rect))
				{
					isRunning = false;
				}
			}
		}
		if (control.quit)
		{
			isRunning = false;
		}

		// UPDATE

		//RRnum1.x = (ScoreP1 % 10) * 72;
		//RLnum1.x = (floor(ScoreP1 / 10) * 72);

		//RRnum2.x = (ScoreP2 % 10) * 72;
		//RLnum2.x = (floor(ScoreP2 / 10) * 72);

		jugador1.update();
		jugador2.update();


		// DRAW
		SDL_RenderClear(renderer);
			//Background
		if (control.escena == 1) 
		{
			bg1.draw();
			horizon.draw();
			for each (Moneda m in monedas)
			{
				m.draw();
			}
			jugador1.draw();
			jugador2.draw();
		}
		else if (control.escena == 0)
		{
			menu.draw();
		}

		SDL_RenderPresent(renderer);

	}

	// --- DESTROY ---
	bg0.~Background();
	bg1.~Background();
	horizon.~Texto();
	for each (Moneda m in monedas)
	{
		m.~Moneda();
	}
	jugador1.~Jugador();
	jugador2.~Jugador();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	// --- QUIT ---
	Mix_CloseAudio();
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	return 0;
}


