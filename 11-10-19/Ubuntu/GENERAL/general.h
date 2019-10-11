/**
* \file general.c
* \brief Module de structure et constante
* \author 
* \version 0.1
* \date 
*/

#include "sdl-light.h"

/**
* \brief Largeur de l'écran de jeu
*/
#define SCREEN_WIDTH 1280

/**
* \brief Hauteur de l'écran de jeu
*/
#define SCREEN_HEIGHT 720

/**
* \brief Taille d'une bulle
*/
#define BUB_SIZE 40

/**
* \brief Taille du bonhomme Hauteur (sprite)
*/
#define SPRITE_SIZE_HEIGHT 100

/**
* \brief Taille du bonhomme Largeur (sprite)
*/
#define SPRITE_SIZE_WIDTH 50

/**
* \brief Taille du "coffre" Hauteur (sprite)
*/
#define SPRITE_TEST_HEIGHT 32

/**
* \brief Taille du "coffre" Largeur (sprite)
*/
#define SPRITE_TEST_WIDTH 32

/**
* \brief Pas, en pixel, de déplacement du sprite
*/
#define MOVING_STEP 5

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
* \brief Représentation du joueur
*/
struct joueur_s{
	SDL_Surface* sprite1;
	SDL_Surface* sprite2;
	SDL_Surface* sprite3;
	SDL_Surface* sprite4;
	SDL_Surface* sprite;
	int x;
	int y; 
	int largeur;
	int hauteur;
	int cote; // 1 : haut, 2 : gauche, 3 : bas, 4 : droite
};
typedef struct joueur_s joueur_t;

/**
* \brief Représentation d'un objet
*/
struct objet_s{
	SDL_Surface* sprite_objet;
	int xobj;
	int yobj;
	int largeur;
	int hauteur;
};
typedef struct objet_s objet_t;

/**
* \brief Représentation du monde du jeu
*/
struct world_s{
	SDL_Surface* background;
	joueur_t joueur;
	objet_t objet;
	int gameover;
};
typedef struct world_s world_t;