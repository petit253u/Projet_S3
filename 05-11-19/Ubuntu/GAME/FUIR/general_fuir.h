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

#define LARGEUR_CARTE_FUIR 100

#define HAUTEUR_CARTE_FUIR 150

#define NB_CARTE_MAX_FUIR 10

#define LARGEUR_ECRAN_FUIR 850
 
#define HAUTEUR_ECRAN_FUIR 400

///////////////////////////////////////////////////////

struct carte_fuir_s{
	int x;
	int y;
	int largeur;
	int hauteur;
	SDL_Surface* sprite;
	SDL_Surface* carte_simple;
	SDL_Surface* carte_cliquable;
	SDL_Surface* carte_retourne;
	bool bonne; //true : carte verte ; false : carte rouge
};
typedef struct carte_fuir_s carte_fuir_t;

struct fuir_s{
	int nb_carte;
	carte_fuir_t tabcarte[NB_CARTE_MAX_FUIR];
	SDL_Surface* fond_noir;
	SDL_Surface* arcade;
	souris_t souris;
	bool ouvert; //true : tj ouvert ; false : ferme 
	bool resultat; //true : bonne carte trouvée ; false : mauvaise carte 
};
typedef struct fuir_s fuir_t;
