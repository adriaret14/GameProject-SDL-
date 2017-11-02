#include "Menu.h"



Menu::Menu(int width, int height) : Escena (Renderer::Instance())
{
	/*SDL_Texture *bgTexture0{ IMG_LoadTexture(renderer, "../../res/img/bg.jpg") };

	if (bgTexture0 == nullptr) throw "No se han podido cargar as texturas";
	SDL_Rect bgRect0{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };*/
	Escena::renderer->LoadTexture(MENU_BG, PATH_IMG + "bg.jpg");
	Font f;
	f.id = SAIYAN_80;
	f.path = PATH_FONT + "saiyan.ttf";
	f.size = 80;
	Escena::renderer->LoadFont(f);
	bgrect = SDL_Rect{0, 0, width, height};

	Text textplay;
	textplay.color = Color{0, 255, 0, 255};
	textplay.id = MENU_TEXT_BUTTON_PLAY;
	textplay.text = "PLAY";
	Escena::renderer->LoadTextureText(f.id, textplay);
	Vector2 aux = Escena::renderer->GetTextureSize(textplay.id);
	textplay.w = aux.x;
	textplay.h = aux.y;
	playrect = SDL_Rect{width/2-(textplay.w/2), height/3-(textplay.h/2), textplay.w, textplay.h};

	Text textexit;
	textexit.color = Color{ 255, 0, 0, 255 };
	textexit.id = MENU_TEXT_BUTTON_EXIT;
	textexit.text = "EXIT";
	Escena::renderer->LoadTextureText(f.id, textexit);
	Vector2 aux2 = Escena::renderer->GetTextureSize(textexit.id);
	textexit.w = aux2.x;
	textexit.h = aux2.y;
	exitrect= SDL_Rect{ width / 2 - (textexit.w / 2), 2*height / 3 - (textexit.h / 2), textexit.w, textexit.h };


}

void Menu::draw()
{
	Escena::renderer->PushImage(MENU_BG, bgrect);
	Escena::renderer->PushImage(MENU_TEXT_BUTTON_PLAY, playrect);
	Escena::renderer->PushImage(MENU_TEXT_BUTTON_EXIT, exitrect);
}

Menu::~Menu()
{
}


