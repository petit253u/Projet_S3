/**
* \file general_joueur.h
* \brief Module de structure et constante
* \author 
* \version 0.1
* \date 
*/

#include "../GENERAL/sdl-light.h"
#include <stdbool.h> 

///////////////////////////////////////////////////////

#define PV_JOUEUR 100

#define HAUTEUR_JOUEUR 300

#define LARGEUR_JOUEUR 100

#define MOVING_STEP 30

///////////////////////////////////////////////////////

/**
* \brief Représentation du joueur
*/
struct joueur_s{
	int x;
	int y; 
	int largeur;
	int hauteur;
	SDL_Surface* sprite;
	SDL_Surface* s1;
	SDL_Surface* s2;
	char dir;
	int pv;
	int cote;
};
typedef struct joueur_s joueur_t;
