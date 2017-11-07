#include "Pantalla1.h"



Pantalla1::Pantalla1(int sWidth, int sHeight) : Escena(PLAY_BG, sWidth, sHeight)
{
	//Background
	//Escena::renderer->LoadTexture(PLAY_BG, PATH_IMG + "bgCastle.jpg");
	//bgrect = SDL_Rect{ 0, 0, sWidth, sHeight };	

	//Fuentes
	Font f;
	f.id = LUIGI_80;
	f.path = PATH_FONT + "MarioLuigi2.ttf";
	f.size = 80;
	Renderer::Instance()->LoadFont(f);
	f.id = LUIGI_45;
	f.path = PATH_FONT + "MarioLuigi2.ttf";
	f.size = 45;
	Renderer::Instance()->LoadFont(f);
	
	//Texto P1:
	Text punt1;
	punt1.color = Color{ 0, 0, 0, 255 };
	punt1.id = PLAY_TEXT_SCORE_PLAYER1;
	punt1.text = "P1:";
	Renderer::Instance()->LoadTextureText(LUIGI_45, punt1);
	Vector2 aux = Renderer::Instance()->GetTextureSize(punt1.id);
	punt1.w = aux.x;
	punt1.h = aux.y;
	tPunt1 = SDL_Rect{ 20, 50, punt1.w, punt1.h };

	//Texto P2:
	Text punt2;
	punt2.color = Color{ 0, 0, 0, 255 };
	punt2.id = PLAY_TEXT_SCORE_PLAYER2;
	punt2.text = "P2:";
	Renderer::Instance()->LoadTextureText(LUIGI_45, punt2);
	aux = Renderer::Instance()->GetTextureSize(punt2.id);
	punt2.w = aux.x;
	punt2.h = aux.y;
	tPunt2 = SDL_Rect{ 20, 100, punt2.w, punt2.h };

	//Horizonte
	Text thor;
	thor.color = Color{ 0, 0, 0, 255 };
	thor.id = PLAY_TEXT_HORIZON;
	thor.text = "-----------------------------";
	Renderer::Instance()->LoadTextureText(LUIGI_80, thor);
	aux = Renderer::Instance()->GetTextureSize(thor.id);
	thor.w = aux.x;
	thor.h = aux.y;
	horizon = SDL_Rect{ 10, 140, thor.w, thor.h };
}


Pantalla1::~Pantalla1()
{
}

void Pantalla1::draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(PLAY_BG, Escena::bg);
	Renderer::Instance()->PushImage(PLAY_TEXT_HORIZON, horizon);
	Renderer::Instance()->PushImage(PLAY_TEXT_SCORE_PLAYER1, tPunt1);
	Renderer::Instance()->PushImage(PLAY_TEXT_SCORE_PLAYER2, tPunt2);
	Renderer::Instance()->Render();
}
