#include "../../GENERAL/general.h"

void init_data_menu(menu_t* m){
	m->ouvert = false;
	m->fond =  SDL_LoadBMP("RESSOURCES/MENU_IN_GAME/FONDMENU.bmp");
	m->bouton1 = SDL_LoadBMP("RESSOURCES/MENU_IN_GAME/bouton_quitter.bmp");
	m->bouton2 = SDL_LoadBMP("RESSOURCES/MENU_IN_GAME/bouton_quitter_cliquable.bmp");
	m->b.x = SCREEN_WIDTH/2 - 300;
	m->b.y = SCREEN_HEIGHT/2 - 300;
	m->b.largeur = SPRITE_BOUTON_WIDTH;
	m->b.hauteur = SPRITE_BOUTON_HEIGHT;
	m->bouton = m->bouton1;
	m->gameover = 0;
	init_data_souris(&m->souris);
}
