/**
* \file general.c
* \brief Module de structure et constante
* \author 
* \version 0.1
* \date 
*/

///////////////////////////////////////////////////////

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
* \brief Taille du bonhomme (sprite)
*/
#define SPRITE_SIZE_HEIGHT 170

/**
* \brief Taille du bonhomme (sprite)
*/
#define SPRITE_SIZE_WIDTH 68

/**
* \brief Taille de l'objet (sprite)
*/
#define SPRITE_TEST_HEIGHT 32

/**
* \brief Taille de l'objet (sprite)
*/
#define SPRITE_TEST_WIDTH 32

/**
* \brief Largeur du sprite bouton
*/
#define SPRITE_BOUTON_WIDTH 600

/**
* \brief Largeur du sprite bouton
*/
#define SPRITE_BOUTON_HEIGHT 450

/**
* \brief Pas de déplacement du sprite
*/
#define MOVING_STEP 10

///////////////////////////////////////////////////////

/**
* \brief Représentation la souris 
*/
struct souris_s{
	int x;
	int y;
};
typedef struct souris_s souris_t;

/**
* \brief Représentation d'un objet
*/
struct objet_s{
	int xobj;
	int yobj;
	int largeur;
	int hauteur;
};
typedef struct objet_s objet_t;

/**
* \brief Représentation du joueur
*/
struct joueur_s{
	int x;
	int y; 
	int largeur;
	int hauteur;
	int cote; // 1 : haut, 2 : gauche, 3 : bas, 4 : droite
};
typedef struct joueur_s joueur_t;


/**
* \brief Représentation du monde du jeu
*/
struct world_s{
	SDL_Surface* background;
	SDL_Surface* sprite1;
	SDL_Surface* sprite2;
	SDL_Surface* sprite3;
	SDL_Surface* sprite4;
	SDL_Surface* sprite;
	SDL_Surface* objet;
	joueur_t j;
	objet_t o;
	int gameover;
};
typedef struct world_s world_t;

/**
* \brief Représentation du menu de départ
*/
struct menu_entree_s{
	int fermer; // 0 -> en attente ; 1 -> lance le jeu
	SDL_Surface* background;
	SDL_Surface* bouton;
	SDL_Surface* bouton1;
	SDL_Surface* bouton2;
	int lequel; // 1 -> bouton 1 ; 2 -> bouton 2
	int gameover;
	double x;
	double y;
	souris_t souris;
	objet_t o;
};
typedef struct menu_entree_s menu_entree_t;


