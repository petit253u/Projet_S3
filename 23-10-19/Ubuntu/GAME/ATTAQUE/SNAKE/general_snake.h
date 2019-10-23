/**
* \file general_snake.h
* \brief Module de structure et constante
* \author 
* \version 0.1
* \date 
*/

#include "../../../GENERAL/sdl-light.h"
#include <stdbool.h> 

///////////////////////////////////////////////////////

#define BORDURE_HAUTE 82

#define BORDURE_GAUCHE 82

#define BORDURE_BASSE 476

#define BORDURE_DROITE 928

#define TAILLE_SPRITE_CUBE 32

#define MOVING_SNAKE 2

#define NB_CORPS_MAX_SNAKE 10

#define NB_MUR_MAX_SNAKE 10

#define NB_OBJET_SNAKE_MAX 10

///////////////////////////////////////////////////////

struct mur_snake_s{
	int x;
	int y;
	SDL_Surface* sprite;
	int cote;
};
typedef struct mur_snake_s mur_snake_t;


struct pointfaible_snake_s{
	int x;
	int y;
	SDL_Surface* sprite;
	int cote;
};
typedef struct pointfaible_snake_s pointfaible_snake_t;

struct corps_snake_s{
	int x;
	int y;
	SDL_Surface* sprite;
	int cote;	
};
typedef struct corps_snake_s corps_snake_t;

struct objet_snake_s{
	int x;
	int y;
	SDL_Surface* sprite;
	int cote;	
};
typedef struct objet_snake_s objet_snake_t;

struct bouton_snake_arcade_s{
	int x;
	int y;
	SDL_Surface* sprite;
};
typedef struct bouton_snake_arcade_s bouton_snake_arcade_t;

struct snake_s{
	SDL_Surface* arcade;
	SDL_Surface* herbe;
	bouton_snake_arcade_t tabbouton[4];
	objet_snake_t tabobjet[NB_OBJET_SNAKE_MAX];
	int nb_objet;
	corps_snake_t tabcorps[NB_CORPS_MAX_SNAKE];
	int nb_corps_actuel;
	mur_snake_t tabmur[NB_MUR_MAX_SNAKE];
	int nb_mur;
	pointfaible_snake_t pointfaible;

	int degat;
	bool ouvert; // true : tj ouvert ; false : se ferme
	char dir; //zqsd
};
typedef struct snake_s snake_t;
