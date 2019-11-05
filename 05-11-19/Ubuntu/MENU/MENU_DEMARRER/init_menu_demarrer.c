#include "../../GENERAL/general.h"

void init_data_debut(menu_entree_t* debut){
	debut->fermer = 0;
	printf("	1 :\n");
	debut->bouton1 = SDL_LoadBMP("RESSOURCES/MENU_DEPART/bouton_jouer.bmp");
	debut->bouton2 = SDL_LoadBMP( "RESSOURCES/MENU_DEPART/bouton_jouer_cliquable.bmp" );
	debut->bouton = debut->bouton1;
	debut->background = SDL_LoadBMP("RESSOURCES/MENU_DEPART/FONDTITRE.bmp");
	debut->bouton = debut->bouton1;
	debut->lequel = 1;
	debut->gameover = 0;
	init_data_objet(&debut->o,1);
	init_data_souris(&debut->souris);
}

