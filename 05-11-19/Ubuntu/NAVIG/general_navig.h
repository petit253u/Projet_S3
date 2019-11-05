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

#define NB_BOUTON_MAX_NAVIG 3 

#define HAUTEUR_BOUTON_NAVIG 200

#define LARGEUR_BOUTON_NAVIG 800

///////////////////////////////////////////////////////

struct bouton_navig_s{
	SDL_Surface* sprite;
	SDL_Surface* b1;
	SDL_Surface* b2;
	int x;
	int y;
	int largeur;
	int hauteur;
};
typedef struct bouton_navig_s bouton_navig_t;

struct navig_s{
	bool ouvert; //true : menu ouvert ; false : menu fermé
	SDL_Surface* fond;
	bouton_navig_t tabbouton[3];
	int nb_bouton;
	souris_t souris;
};
typedef struct navig_s navig_t;

