/**
* \file general_epargner.h
* \brief Module de structure et constante
* \author 
* \version 0.1
* \date 
*/

#include "../../GENERAL/sdl-light.h"
#include <stdbool.h> 

///////////////////////////////////////////////////////

#define LARGEUR_CARTE_EPARGNER 100

#define HAUTEUR_CARTE_EPARGNER 150

#define LARGEUR_ECRAN_EPARGNER 850
 
#define HAUTEUR_ECRAN_EPARGNER 400

///////////////////////////////////////////////////////

struct carte_valide_s{
	int x;
	int y;
	int largeur;
	int hauteur;
	SDL_Surface* sprite;
	SDL_Surface* carte_valide;
	SDL_Surface* carte_simple;
	SDL_Surface* carte_cliquable;
};
typedef struct carte_valide_s carte_valide_t;

struct epargner_s{
	carte_valide_t carte;
	SDL_Surface* fond_noir;
	SDL_Surface* arcade;
	souris_t souris;
	bool ouvert; //true : tj ouvert ; false : ferme 
	bool resultat;
};
typedef struct epargner_s epargner_t;
