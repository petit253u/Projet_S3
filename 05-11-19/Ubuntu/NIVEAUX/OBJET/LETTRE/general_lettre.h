/**
* \file general_fuir.h
* \brief Module de structure et constante
* \author 
* \version 0.1
* \date 
*/

#include "../../../GENERAL/sdl-light.h"
#include <stdbool.h> 

///////////////////////////////////////////////////////

#define LARGEUR_LETTRE 200

#define HAUTEUR_LETTRE 200

///////////////////////////////////////////////////////

struct lettre_s{
	SDL_Surface* sprite;
	SDL_Surface* l1; //lettre normal
	SDL_Surface* l2; //lettre cliquable
	int x;
	int y;
	int largeur;
	int hauteur;
};
typedef struct lettre_s lettre_t;

