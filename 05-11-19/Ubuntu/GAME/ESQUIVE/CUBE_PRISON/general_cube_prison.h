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

#define BORDURE_HAUTE_CUBE 200

#define BORDURE_GAUCHE_CUBE 400

#define BORDURE_BASSE_CUBE 300

#define BORDURE_DROITE_CUBE 500

#define MOVING_CUBE_ATTAQUE 10

#define NB_MAX_ATTAQUE_CUBE 50

#define LARGEUR_SPRITE_JOUEUR_CUBE 32

#define HAUTEUR_SPRITE_JOUEUR_CUBE 32

#define LARGEUR_TYPE_1_ATTAQUE_CUBE 50

#define HAUTEUR_TYPE_1_ATTAQUE_CUBE 50

///////////////////////////////////////////////////////

struct attaque_cube_s{
	SDL_Surface* sprite;
	int x;
	int y;
	int hauteur;
	int largeur;
	int degat;
	char dir; //z : vers le haut, q : vers la gauche, ...
};
typedef struct attaque_cube_s attaque_cube_t;

struct paterne_s{
	int nb_attaque;
	attaque_cube_t tabattaque[NB_MAX_ATTAQUE_CUBE];
};
typedef struct paterne_s paterne_t;

struct joueur_cube_s{
	SDL_Surface* sprite;
	SDL_Surface* s1;
	SDL_Surface* s2;
	int x;
	int y;
	int hauteur;
	int largeur;
};
typedef struct joueur_cube_s joueur_cube_t;

struct cube_prison_s{
	SDL_Surface* arcade;
	SDL_Surface* fond_cube;

	paterne_t paterne;
	temps_t temps;
	souris_t souris;
	joueur_cube_t joueur;

	bool ouvert; // true : tj ouvert ; false : se ferme
};
typedef struct cube_prison_s cube_prison_t;
