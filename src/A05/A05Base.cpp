#include <SDL.h>		// Always needs to be included for an SDL app
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

//Game general information
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FPS 60

bool crearMoneda(SDL_Rect &moneda1, SDL_Rect &moneda2, SDL_Rect &moneda3, SDL_Rect &moneda4, SDL_Rect &moneda5, int num)
{
	int x = 32 * (rand() % 24);
	int y = 160 + 12 + 32 * (rand() % 13);

	if ((moneda1.x != x  && moneda1.y != y) || (moneda2.x != x && moneda2.y != y) || (moneda3.x != x && moneda3.x != y) || (moneda4.x != x && moneda4.x != y) || (moneda5.x != x && moneda5.y != y))
	{
		switch (num)
		{
		case 0:
			moneda1.x = x;
			moneda1.y = y;
			break;
		case 1:
			moneda2.x = x;
			moneda2.y = y;
			break;
		case 2:
			moneda3.x = x;
			moneda3.y = y;
			break;
		case 3:
			moneda4.x = x;
			moneda4.y = y;
			break;
		case 4:
			moneda5.x = x;
			moneda5.y = y;
			break;
		}
		//cont++;
		return true;
	}
	return false;
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
	SDL_Texture *bgTexture{ IMG_LoadTexture(renderer, "../../res/img/bgCastle.jpg") };

	if (bgTexture == nullptr) throw "No se han podido cargar as texturas";
	SDL_Rect bgRect{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	/*SDL_Texture *playerTexture(IMG_LoadTexture(renderer, "../../res/img/kintoun.png"));
	if (playerTexture == nullptr) throw "No se han podido cargar as texturas";
	SDL_Rect playerRect{ 0, 0, 350, 189 };*/

	int ScoreP1 = 0;
	int ScoreP2 = 0;
	int cont = 0;
	SDL_Texture *moneda(IMG_LoadTexture(renderer, "../../res/img/gold.png"));
	if (moneda == nullptr) throw "No se ha podido cargar la textura de la moneda";
	SDL_Rect moneda1{0, 0, 32, 32};
	SDL_Rect moneda2{0, 0, 32, 32};
	SDL_Rect moneda3{0, 0, 32, 32};
	SDL_Rect moneda4{0, 0, 32, 32};
	SDL_Rect moneda5{0, 0, 32, 32};
	srand (time(NULL));
	//Bucle para generar monedas de forma aleatoria
	while (cont<5)
	{
		if (crearMoneda(moneda1, moneda2, moneda3, moneda4, moneda5, cont)) cont++;
			
	}

	/*std::cout << "Moneda 1: " << moneda1.x << ", " << moneda1.y << std::endl;
	std::cout << "Moneda 2: " << moneda2.x << ", " << moneda2.y << std::endl;
	std::cout << "Moneda 3: " << moneda3.x << ", " << moneda3.y << std::endl;
	std::cout << "Moneda 4: " << moneda4.x << ", " << moneda4.y << std::endl;
	std::cout << "Moneda 5: " << moneda5.x << ", " << moneda5.y << std::endl;*/

	SDL_Rect playerTarget{ 0, 0, 100, 100 };

	SDL_Texture *jugador1(IMG_LoadTexture(renderer, "../../res/img/spCastle.png"));
	if (jugador1 == nullptr) throw "No se han podido cargar las texturas del jugador 1";
	SDL_Rect Rjugador1, jugador1Pos;
	int textWidth1, textHeight1, frameWidth1, frameHeight1;
	SDL_QueryTexture(jugador1, NULL, NULL, &textWidth1, &textHeight1);
	frameWidth1 = 32;
	frameHeight1 = 32;
	jugador1Pos.x = 20;
	jugador1Pos.y = 200;
	Rjugador1.x = 128;
	Rjugador1.y = 0;
	jugador1Pos.h = Rjugador1.h = frameHeight1;
	jugador1Pos.w = Rjugador1.w = frameWidth1;

	int frameTime1 = 0;
	int frameTime2 = 0;
	int dir1 = 1;
	int dir2 = 1;
	bool move1 = false;
	bool move2 = false;


	SDL_Texture *jugador2(IMG_LoadTexture(renderer, "../../res/img/spCastle.png"));
	if (jugador2 == nullptr) throw "No se han podido cargar las exturas del jugador 2";
	SDL_Rect Rjugador2, jugador2Pos;
	int textWidth2, textHeight2, framewidth2, frameHeight2;
	SDL_QueryTexture(jugador2, NULL, NULL, &textWidth2, &textHeight2);
	framewidth2 = 32;
	frameHeight2 = 32;
	jugador2Pos.x = 748;
	jugador2Pos.y = 548;
	Rjugador2.x = 320;
	Rjugador2.y = 96;
	jugador2Pos.w = Rjugador2.w = framewidth2;
	jugador2Pos.h = Rjugador2.h = frameHeight2;




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
	//int numWidth, numHeight, numFrameWidth, numFrameHeight;
	//SDL_QueryTexture(numeros, NULL, NULL, &numWidth, &numHeight);
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

	


		// --- Animated Sprite ---

	/*SDL_Texture *playerTexture2{ IMG_LoadTexture(renderer, "../../res/img/sp01.png") };
	SDL_Rect playerRect2, playerPosition;
	int textWidth, textHeight, frameWidth, frameHeight;
	SDL_QueryTexture(playerTexture2, NULL, NULL, &textWidth, &textHeight);
	frameWidth = textWidth / 6;
	frameHeight = textHeight / 1;
	playerPosition.x = playerPosition.y = 0;
	playerRect2.x = playerRect2.y = 0;
	playerPosition.h = playerRect2.h = frameHeight;
	playerPosition.w = playerRect2.w = frameWidth;
	int frameTime = 0;*/


	// --- TEXT ---
	/*TTF_Font *font{ TTF_OpenFont("../../res/ttf/saiyan.ttf", 80) };
	if (font == nullptr) throw "No se puee inicilaicar SD_ttf";
	SDL_Surface *tmpSurf{ TTF_RenderText_Blended(font, "My first SDL game", SDL_Color{ 255, 150, 0, 255}) };
	if (tmpSurf == nullptr) TTF_CloseFont(font), throw "Unable to create the SDL text surface";
	SDL_Texture *textTexture{ SDL_CreateTextureFromSurface(renderer, tmpSurf) };
	SDL_Rect textRect{ 100, 50, tmpSurf->w, tmpSurf->h };
	SDL_FreeSurface(tmpSurf);
	TTF_CloseFont(font);*/

	TTF_Font *font{ TTF_OpenFont("../../res/ttf/MarioLuigi2.ttf", 80) };
	if (font == nullptr) throw "No se puede inicializar SDL_ttf";
	SDL_Surface *tmpSurf{ TTF_RenderText_Blended(font, "-----------------------------", SDL_Color{0, 0, 0, 255}) };
	if (tmpSurf == nullptr) TTF_CloseFont(font), throw "No se puede crear la superficie de texto";
	SDL_Texture *textTexture{ SDL_CreateTextureFromSurface(renderer, tmpSurf) };
	SDL_Rect textRect{ 5, 140, tmpSurf->w, tmpSurf->h };
	SDL_FreeSurface(tmpSurf);
	TTF_CloseFont(font);

	TTF_Font *font2{ TTF_OpenFont("../../res/ttf/MarioLuigi2.ttf", 45) };
	if (font2 == nullptr) throw "No se puede inicializar SDL_ttf";
	SDL_Surface *tmpSurfPunt1{ TTF_RenderText_Blended(font2, "P1:", SDL_Color{ 0, 0, 0, 255 }) };
	if (tmpSurfPunt1 == nullptr) TTF_CloseFont(font2), throw "No se puede crear la superficie de texto";
	SDL_Texture *textTexture2{ SDL_CreateTextureFromSurface(renderer, tmpSurfPunt1) };
	SDL_Rect textRect2{ 20, 50, tmpSurfPunt1->w, tmpSurfPunt1->h };
	SDL_FreeSurface(tmpSurfPunt1);
	std::cout << tmpSurfPunt1->h << std::endl;
	//TTF_CloseFont(font);

	//TTF_Font *font{ TTF_OpenFont("../../res/ttf/MarioLuigi2.ttf", 80) };
	//if (font == nullptr) throw "No se puede inicializar SDL_ttf";
	SDL_Surface *tmpSurfPunt2{ TTF_RenderText_Blended(font2, "P2:", SDL_Color{ 0, 0, 0, 255 }) };
	if (tmpSurfPunt2 == nullptr) TTF_CloseFont(font2), throw "No se puede crear la superficie de texto";
	SDL_Texture *textTexture3{ SDL_CreateTextureFromSurface(renderer, tmpSurfPunt2) };
	SDL_Rect textRect3{ 20, 100, tmpSurfPunt2->w, tmpSurfPunt2->h };
	SDL_FreeSurface(tmpSurfPunt2);
	TTF_CloseFont(font2);

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
	SDL_Event event;
	bool isRunning = true;
	while (isRunning) {
		// HANDLE EVENTS

		//Colisiones con monedas jugador1
		if (jugador1Pos.x >= moneda1.x-25 && jugador1Pos.x <= moneda1.x + 25)
		{
			if (jugador1Pos.y >= moneda1.y-25 && jugador1Pos.y <= moneda1.y + 25)
			{
				//P1 colisiona con moneda1
				while (!crearMoneda(moneda1, moneda2, moneda3, moneda4, moneda5, 0));
				ScoreP1++;
			}
		}
		if (jugador1Pos.x >= moneda2.x-25 && jugador1Pos.x <= moneda2.x + 25)
		{
			if (jugador1Pos.y >= moneda2.y-25 && jugador1Pos.y <= moneda2.y + 25)
			{
				//P1 colisiona con moneda2
				while (!crearMoneda(moneda1, moneda2, moneda3, moneda4, moneda5, 1));
				ScoreP1++;
			}
		}
		if (jugador1Pos.x >= moneda3.x-25 && jugador1Pos.x <= moneda3.x + 25)
		{
			if (jugador1Pos.y >= moneda3.y-25 && jugador1Pos.y <= moneda3.y + 25)
			{
				//P1 colisiona con moneda3
				while (!crearMoneda(moneda1, moneda2, moneda3, moneda4, moneda5, 2));
				ScoreP1++;
			}
		}
		if (jugador1Pos.x >= moneda4.x-25 && jugador1Pos.x <= moneda4.x + 25)
		{
			if (jugador1Pos.y >= moneda4.y-25 && jugador1Pos.y <= moneda4.y + 25)
			{
				//P1 colisiona con moneda4
				while (!crearMoneda(moneda1, moneda2, moneda3, moneda4, moneda5, 3));
				ScoreP1++;
			}
		}
		if (jugador1Pos.x >= moneda5.x-25 && jugador1Pos.x <= moneda5.x + 25)
		{
			if (jugador1Pos.y >= moneda5.y-25 && jugador1Pos.y <= moneda5.y + 25)
			{
				//P1 colisiona con moneda5
				while (!crearMoneda(moneda1, moneda2, moneda3, moneda4, moneda5, 4));
				ScoreP1++;
			}
		}

		//Colisiones con monedas jugador2
		if (jugador2Pos.x >= moneda1.x - 25 && jugador2Pos.x <= moneda1.x + 25)
		{
			if (jugador2Pos.y >= moneda1.y - 25 && jugador2Pos.y <= moneda1.y + 25)
			{
				//P1 colisiona con moneda1
				while (!crearMoneda(moneda1, moneda2, moneda3, moneda4, moneda5, 0));
				ScoreP2++;
			}
		}
		if (jugador2Pos.x >= moneda2.x - 25 && jugador2Pos.x <= moneda2.x + 25)
		{
			if (jugador2Pos.y >= moneda2.y - 25 && jugador2Pos.y <= moneda2.y + 25)
			{
				//P1 colisiona con moneda2
				while (!crearMoneda(moneda1, moneda2, moneda3, moneda4, moneda5, 1));
				ScoreP2++;
			}
		}
		if (jugador2Pos.x >= moneda3.x - 25 && jugador2Pos.x <= moneda3.x + 25)
		{
			if (jugador2Pos.y >= moneda3.y - 25 && jugador2Pos.y <= moneda3.y + 25)
			{
				//P1 colisiona con moneda3
				while (!crearMoneda(moneda1, moneda2, moneda3, moneda4, moneda5, 2));
				ScoreP2++;
			}
		}
		if (jugador2Pos.x >= moneda4.x - 25 && jugador2Pos.x <= moneda4.x + 25)
		{
			if (jugador2Pos.y >= moneda4.y - 25 && jugador2Pos.y <= moneda4.y + 25)
			{
				//P1 colisiona con moneda4
				while (!crearMoneda(moneda1, moneda2, moneda3, moneda4, moneda5, 3));
				ScoreP2++;
			}
		}
		if (jugador2Pos.x >= moneda5.x - 25 && jugador2Pos.x <= moneda5.x + 25)
		{
			if (jugador2Pos.y >= moneda5.y - 25 && jugador2Pos.y <= moneda5.y + 25)
			{
				//P1 colisiona con moneda5
				while (!crearMoneda(moneda1, moneda2, moneda3, moneda4, moneda5, 4));
				ScoreP2++;
			}
		}
		const Uint8 *state = SDL_GetKeyboardState(NULL);

		//Controles jugador 1
		if (state[SDL_SCANCODE_W])
		{
			if (jugador1Pos.y >= 140 + 20)
			{
				jugador1Pos.y = jugador1Pos.y - 5;
				//Rjugador1.x = 128;
				Rjugador1.y = 96;
				move1 = true;
			}

		}
		if (state[SDL_SCANCODE_S])
		{
			if (jugador1Pos.y <= 600 - 32)
			{
				jugador1Pos.y = jugador1Pos.y + 5;
				//Rjugador1.x = 128;
				Rjugador1.y = 0;
				move1 = true;
			}

		}
		if (state[SDL_SCANCODE_A])
		{
			if (jugador1Pos.x >= -32)
			{
				jugador1Pos.x = jugador1Pos.x - 5;
				//Rjugador1.x = 128;
				Rjugador1.y = 32;
				move1 = true;
			}
			else
			{
				jugador1Pos.x = 800;
			}

		}
		if (state[SDL_SCANCODE_D])
		{
			if (jugador1Pos.x <= 800)
			{
				jugador1Pos.x = jugador1Pos.x + 5;
				//Rjugador1.x = 128;
				Rjugador1.y = 64;
				move1 = true;
			}
			else
			{
				jugador1Pos.x = -32;
			}

		}
		if (state[SDL_SCANCODE_UP])
		{
			if (jugador2Pos.y >= 140 + 20)
			{
				jugador2Pos.y = jugador2Pos.y - 5;
				//Rjugador1.x = 128;
				Rjugador2.y = 96;
				move2 = true;
			}
		}
		if (state[SDL_SCANCODE_DOWN])
		{
			if (jugador2Pos.y <= 600 - 32)
			{
				jugador2Pos.y = jugador2Pos.y + 5;
				//Rjugador1.x = 128;
				Rjugador2.y = 0;
				move2 = true;
			}
		}
		if (state[SDL_SCANCODE_LEFT])
		{
			if (jugador2Pos.x >= -32)
			{
				jugador2Pos.x = jugador2Pos.x - 5;
				//Rjugador1.x = 128;
				Rjugador2.y = 32;
				move2 = true;
			}
			else
			{
				jugador2Pos.x = 800;
			}
		}
		if (state[SDL_SCANCODE_RIGHT])
		{
			if (jugador2Pos.x <= 800)
			{
				jugador2Pos.x = jugador2Pos.x + 5;
				//Rjugador1.x = 128;
				Rjugador2.y = 64;
				move2 = true;
			}
			else
			{
				jugador2Pos.x = -32;
			}
		}
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:		isRunning = false; break;
			case SDL_KEYDOWN:	
				if (event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;

				////Controles jugador 1
				//if(event.key.keysym.sym == SDLK_w)
				//{
				//	if (jugador1Pos.y >= 140+20)
				//	{
				//		jugador1Pos.y = jugador1Pos.y - 5;
				//		//Rjugador1.x = 128;
				//		Rjugador1.y = 96;
				//		move1 = true;
				//	}
				//	
				//}
				//if (event.key.keysym.sym == SDLK_s)
				//{
				//	if (jugador1Pos.y <= 600 - 32)
				//	{
				//		jugador1Pos.y = jugador1Pos.y + 5;
				//		//Rjugador1.x = 128;
				//		Rjugador1.y = 0;
				//		move1 = true;
				//	}
				//	
				//}
				//if (event.key.keysym.sym == SDLK_a)
				//{
				//	if (jugador1Pos.x >= -32)
				//	{
				//		jugador1Pos.x = jugador1Pos.x - 5;
				//		//Rjugador1.x = 128;
				//		Rjugador1.y = 32;
				//		move1 = true;
				//	}
				//	else
				//	{
				//		jugador1Pos.x = 800;
				//	}
				//	
				//}
				//if (event.key.keysym.sym == SDLK_d)
				//{
				//	if (jugador1Pos.x <= 800)
				//	{
				//		jugador1Pos.x = jugador1Pos.x + 5;
				//		//Rjugador1.x = 128;
				//		Rjugador1.y = 64;
				//		move1 = true;
				//	}
				//	else
				//	{
				//		jugador1Pos.x = -32;
				//	}
				//	
				//}
				/*
				//Controles jugador 2
				if (event.key.keysym.sym ==SDLK_UP)
				{
					if (jugador2Pos.y >= 140 + 20)
					{
						jugador2Pos.y = jugador2Pos.y - 5;
						//Rjugador1.x = 128;
						Rjugador2.y = 96;
						move2 = true;
					}

				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					if (jugador2Pos.y <= 600 - 32)
					{
						jugador2Pos.y = jugador2Pos.y + 5;
						//Rjugador1.x = 128;
						Rjugador2.y = 0;
						move2 = true;
					}

				}
				if (event.key.keysym.sym == SDLK_LEFT)
				{
					if (jugador2Pos.x >= -32)
					{
						jugador2Pos.x = jugador2Pos.x - 5;
						//Rjugador1.x = 128;
						Rjugador2.y = 32;
						move2 = true;
					}
					else
					{
						jugador2Pos.x = 800;
					}

				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					if (jugador2Pos.x <= 800)
					{
						jugador2Pos.x = jugador2Pos.x + 5;
						//Rjugador1.x = 128;
						Rjugador2.y = 64;
						move2 = true;
					}
					else
					{
						jugador2Pos.x = -32;
					}

				}

				if(event.type==SDL_KEYUP)
				{
					move = false;
				}*/
				break;
			case SDL_KEYUP:	
				
				break;
			default:;
			}
		}

		// UPDATE
		//Rjugador1.x += (playerTarget.x - Rjugador1.x) / 4;
		//Rjugador1.y += (playerTarget.y - Rjugador1.y) / 4;


		RRnum1.x = (ScoreP1 % 10) * 72;
		RLnum1.x = (floor(ScoreP1 / 10) * 72);

		RRnum2.x = (ScoreP2 % 10) * 72;
		RLnum2.x = (floor(ScoreP2 / 10) * 72);

		if (move1)
		{
			frameTime1++;
			if (FPS / frameTime1 <= 9)
			{
				frameTime1 = 0;
				Rjugador1.x = Rjugador1.x + dir1*frameWidth1;
				if (Rjugador1.x >= 160 || Rjugador1.x <= 96)
				{
					dir1 *= -1;
				}
			}
		}
		else {
			Rjugador1.x = 128;
			//Rjugador1.y = 32;
		}

		if (move2)
		{
			frameTime2++;
			if (FPS / frameTime2 <= 9)
			{
				frameTime2 = 0;
				Rjugador2.x = Rjugador2.x + dir2*framewidth2;
				if (Rjugador2.x >= 352 || Rjugador2.x <= 288)
				{
					dir2 *= -1;
				}
			}
		}
		else {
			Rjugador2.x = 320;
			//Rjugador1.y = 32;
		}




		// DRAW
			//Background
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, bgTexture, nullptr, &bgRect);

			//Animated Sprite
		
		/*SDL_RenderCopy(renderer, playerTexture, nullptr, &playerRect);*/

		SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
		SDL_RenderCopy(renderer, textTexture2, nullptr, &textRect2);
		SDL_RenderCopy(renderer, textTexture3, nullptr, &textRect3);
		SDL_RenderCopy(renderer, numeros, &RLnum1, &LnumPos1);
		SDL_RenderCopy(renderer, numeros, &RRnum1, &RnumPos1);
		SDL_RenderCopy(renderer, numeros, &RLnum2, &LnumPos2);
		SDL_RenderCopy(renderer, numeros, &RRnum2, &RnumPos2);
		SDL_RenderCopy(renderer, moneda, nullptr, &moneda1);
		SDL_RenderCopy(renderer, moneda, nullptr, &moneda2);
		SDL_RenderCopy(renderer, moneda, nullptr, &moneda3);
		SDL_RenderCopy(renderer, moneda, nullptr, &moneda4);
		SDL_RenderCopy(renderer, moneda, nullptr, &moneda5);
		SDL_RenderCopy(renderer, jugador1, &Rjugador1, &jugador1Pos);
		SDL_RenderCopy(renderer, jugador2, &Rjugador2, &jugador2Pos);




		SDL_RenderPresent(renderer);

	}

	// --- DESTROY ---
	SDL_DestroyTexture(textTexture);
	SDL_DestroyTexture(textTexture2);
	SDL_DestroyTexture(textTexture3);
	/*SDL_DestroyTexture(playerTexture);*/
	SDL_DestroyTexture(bgTexture);
	SDL_DestroyTexture(moneda);
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


