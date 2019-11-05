#include "../../GENERAL/general.h"

void init_data_bouton_navig(bouton_navig_t* b, int i, int ecartx, int ecarty){
	b->b1 = SDL_LoadBMP("RESSOURCES/MENU_IN_GAME/FONDMENU.bmp");
	b->b2 = SDL_LoadBMP("RESSOURCES/MENU_IN_GAME/FONDMENU.bmp");
	b->sprite = b->b1;
	b->x = ecartx;
	b->y = (ecarty * i) + (HAUTEUR_BOUTON_NAVIG * i-1);
	b->hauteur = HAUTEUR_BOUTON_NAVIG;
	b->largeur = LARGEUR_BOUTON_NAVIG;
}

void init_data_navig(navig_t* n){
	n->ouvert = true;
	n->fond =  SDL_LoadBMP("RESSOURCES/MENU_IN_GAME/FONDMENU.bmp");
	n->nb_bouton = 3;
	int ecartx = (SCREEN_WIDTH - LARGEUR_BOUTON_NAVIG) /2;
	int ecarty = (SCREEN_HEIGHT - HAUTEUR_BOUTON_NAVIG) / (n->nb_bouton +1);
	for(int i = 0; i<n->nb_bouton; i++){
		init_data_bouton_navig(&n->tabbouton[i],i+1,ecartx,ecarty);
	}
	init_data_souris(&m->souris);
}
