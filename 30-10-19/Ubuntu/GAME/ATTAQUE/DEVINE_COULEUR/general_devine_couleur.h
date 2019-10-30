/**
* \file general_devine_couleur.h
* \brief Module de structure et constante
* \author 
* \version 0.1
* \date 
*/

#include "../../../GENERAL/sdl-light.h"
#include <stdbool.h> 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define NB_MAX_SERIE_BOUTON 10

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct bouton_devine_arcade_s{
	int x;
	int y;
	SDL_Surface* sprite;
};
typedef struct bouton_devine_arcade_s bouton_devine_arcade_t;
	
struct devine_couleur_s{
	int nb_attendu;
	int nb_remplis;
	char tabserie[NB_MAX_SERIE_BOUTON];
	char tabattendu[NB_MAX_SERIE_BOUTON];

	SDL_Surface* arcade;
	SDL_Surface* fond;
	
	SDL_Surface* c1;
	SDL_Surface* c2;
	SDL_Surface* c3;
	SDL_Surface* a_toi;

	SDL_Surface* fond_simple;
	SDL_Surface* fond_jaune;  
	SDL_Surface* fond_bleu;  
	SDL_Surface* fond_vert;  
	SDL_Surface* fond_rouge; 

	SDL_Surface* fond_valide; 
	SDL_Surface* fond_echec; 


	bouton_devine_arcade_t tabbouton[4];
	char dir;
	bool ouvert; //true : tj ouvert ; false : ferme 
};
typedef struct devine_couleur_s devine_couleur_t;
