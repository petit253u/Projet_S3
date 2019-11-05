/**
* \file general_fuir.h
* \brief Module de structure et constante
* \author 
* \version 0.1
* \date 
*/

#include "../../GENERAL/sdl-light.h"
#include <stdbool.h> 

///////////////////////////////////////////////////////



///////////////////////////////////////////////////////

struct menu_entree_s{
	int fermer; // 0 -> en attente ; 1 -> lance le jeu
	SDL_Surface* background;
	SDL_Surface* bouton;
	SDL_Surface* bouton1;
	SDL_Surface* bouton2;
	int lequel; // 1 -> bouton 1 ; 2 -> bouton 2
	int gameover;
	double x;
	double y;
	souris_t souris;
	objet_t o;
};
typedef struct menu_entree_s menu_entree_t;
