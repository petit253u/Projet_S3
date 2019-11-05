#include "../GENERAL/general.h"

void init_data_joueur(joueur_t* j){
	j->largeur = LARGEUR_JOUEUR;
	j->hauteur = HAUTEUR_JOUEUR;
	j->x = 100;
	j->y = SCREEN_HEIGHT  - 100 - j->hauteur;
	j->s1 = SDL_LoadBMP("RESSOURCES/JOUEUR/test_sprite_01.bmp");
	j->s2 = SDL_LoadBMP("RESSOURCES/JOUEUR/test_sprite_02.bmp");
	j->sprite = j->s1;
	j->dir = 'd';
	j->pv = PV_JOUEUR;
	j->cote = 2;
}
