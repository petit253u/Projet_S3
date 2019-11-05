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

#define LARGEUR_COFFRE 200

#define HAUTEUR_COFFRE 200

///////////////////////////////////////////////////////

struct coffre_s{
	SDL_Surface* sprite;
	SDL_Surface* c1; //coffre normal
	SDL_Surface* c2; //coffre cliquable
	SDL_Surface* c3; //coffre detruit
	SDL_Surface* c4; //coffre reussi
	int x;
	int y;
	int largeur;
	int hauteur;
	int ouvert; //true : coffre deja ouvert; false : coffre en attente
};
typedef struct coffre_s coffre_t;

