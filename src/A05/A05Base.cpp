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
		int x = 32*(rand() % 24);
		int y = 160 + 12 + 32*(rand() % 13);
		if (cont == 0)
		{
			moneda1.x = x;
			moneda1.y = y;
			cont++;
		}
		else 
		{
			if ((moneda1.x != x  && moneda1.y != y) || (moneda2.x != x && moneda2.y != y) || (moneda3.x != x && moneda3.x != y) || (moneda4.x != x && moneda4.x != y) || (moneda5.x != x && moneda5.y != y))
			{
				switch (cont)
				{
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
				cont++;
			}
		}
	}

	std::cout << "Moneda 1: " << moneda1.x << ", " << moneda1.y << std::endl;
	std::cout << "Moneda 2: " << moneda2.x << ", " << moneda2.y << std::endl;
	std::cout << "Moneda 3: " << moneda3.x << ", " << moneda3.y << std::endl;
	std::cout << "Moneda 4: " << moneda4.x << ", " << moneda4.y << std::endl;
	std::cout << "Moneda 5: " << moneda5.x << ", " << moneda5.y << std::endl;

	SDL_Rect playerTarget{ 0, 0, 100, 100 };

	SDL_Texture *jugador1(IMG_LoadTexture(renderer, "../../res/img/spCastle.png"));
	if (jugador1 == nullptr) throw "No se han podido cargar las texturas del jugador 1";
	SDL_Texture *jugador2(IMG_LoadTexture(renderer, "../../res/img/spCastle.png"));
	if (jugador2 == nullptr) throw "No se han podido cargar las texturas del jugador 2";
	SDL_Rect Rjugador1, jugador1Pos, Rjugador2, jugador2Pos;
	int textWidth1, textHeight1, textWidth2, textHeight2, frameWidth, frameHeight;
	SDL_QueryTexture(jugador1, NULL, NULL, &textWidth1, &textHeight1);
	frameWidth = 32;
	frameHeight = 32;
	jugador1Pos.x = 20;
	jugador1Pos.y = 200;
	Rjugador1.x = 128;
	Rjugador1.y = 0;
	jugador1Pos.h = Rjugador1.h = frameHeight;
	jugador1Pos.w = Rjugador1.w = frameWidth;
	int frameTime = 0;
	int dir = 1;
	bool move = false;

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
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:		isRunning = false; break;
			case SDL_KEYDOWN:	
				if (event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
				else if(event.key.keysym.sym == SDLK_w)
				{
					if (jugador1Pos.y >= 140+20)
					{
						jugador1Pos.y = jugador1Pos.y - 5;
						//Rjugador1.x = 128;
						Rjugador1.y = 96;
						move = true;
					}
					
				}
				else if (event.key.keysym.sym == SDLK_s)
				{
					if (jugador1Pos.y <= 600 - 32)
					{
						jugador1Pos.y = jugador1Pos.y + 5;
						//Rjugador1.x = 128;
						Rjugador1.y = 0;
						move = true;
					}
					
				}
				else if (event.key.keysym.sym == SDLK_a)
				{
					if (jugador1Pos.x >= -32)
					{
						jugador1Pos.x = jugador1Pos.x - 5;
						//Rjugador1.x = 128;
						Rjugador1.y = 32;
						move = true;
					}
					else
					{
						jugador1Pos.x = 800;
					}
					
				}
				else if (event.key.keysym.sym == SDLK_d)
				{
					if (jugador1Pos.x <= 800)
					{
						jugador1Pos.x = jugador1Pos.x + 5;
						//Rjugador1.x = 128;
						Rjugador1.y = 64;
						move = true;
					}
					else
					{
						jugador1Pos.x = -32;
					}
					
				}
				if(event.type==SDL_KEYUP)
				{
					move = false;
				}
				break;
			case SDL_MOUSEMOTION:	
				/*playerRect.x = event.motion.x; 
				playerRect.y = event.motion.y;*/

				/*playerTarget.x = event.motion.x - 50;
				playerTarget.y = event.motion.y - 50;*/
				break;
			default:;
			}
		}

		// UPDATE
		//Rjugador1.x += (playerTarget.x - Rjugador1.x) / 4;
		//Rjugador1.y += (playerTarget.y - Rjugador1.y) / 4;

		if (move)
		{
			frameTime++;
			if (FPS / frameTime <= 9)
			{
				frameTime = 0;
				Rjugador1.x = Rjugador1.x + dir*frameWidth;
				if (Rjugador1.x >= 160 || Rjugador1.x <= 96)
				{
					dir *= -1;
				}
			}
		}
		else {
			Rjugador1.x = 128;
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
		SDL_RenderCopy(renderer, jugador1, &Rjugador1, &jugador1Pos);
		SDL_RenderCopy(renderer, moneda, nullptr, &moneda1);
		SDL_RenderCopy(renderer, moneda, nullptr, &moneda2);
		SDL_RenderCopy(renderer, moneda, nullptr, &moneda3);
		SDL_RenderCopy(renderer, moneda, nullptr, &moneda4);
		SDL_RenderCopy(renderer, moneda, nullptr, &moneda5);




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