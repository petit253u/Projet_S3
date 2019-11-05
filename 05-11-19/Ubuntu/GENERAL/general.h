/**
* \file general.c
* \brief Module de structure et constante
* \author 
* \version 0.1
* \date 
*/

///////////////////////////////////////////////////////

#include "sdl-light.h"
#include <stdbool.h> 

/**
* \brief Largeur de la salle de test
*/
#define LEVEL_WIDTH 2098

/**
* \brief Hauteur de la salle de test
*/
#define LEVEL_HEIGHT 1000

/**
* \brief Largeur de l'écran de jeu
*/
#define SCREEN_WIDTH 1000

/**
* \brief Hauteur de l'écran de jeu
*/
#define SCREEN_HEIGHT 650

/**
* \brief Taille de l'objet (sprite)
*/
#define SPRITE_TEST_HEIGHT 32

/**
* \brief Taille de l'objet (sprite)
*/
#define SPRITE_TEST_WIDTH 32

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

/**
* \brief Représentation du timer
*/
struct temps_s{
	int temps_ancien;
	int temps_actuel;
	int ecart_souhait;
};
typedef struct temps_s temps_t;

/**
* \brief Représentation de la souris 
*/
struct souris_s{
	int x;
	int y;
	int click_x;
	int click_y;	
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
	SDL_Surface* sprite;
};
typedef struct objet_s objet_t;

/**
* \brief Représentation d'un bouton
*/
struct bouton_s{
	int x;
	int y;
	int largeur;
	int hauteur;
};
typedef struct bouton_s bouton_t;


//////////////////////////////////////////////////////////////////////////

#include "../MENU/MENU_DEMARRER/general_menu_demarrer.h"
#include "../MENU/MENU_IN_GAME/general_menu.h"

#include "../JOUEUR/general_joueur.h"

#include "../GAME/ATTAQUE/SNAKE/general_snake.h"
#include "../GAME/ATTAQUE/DEVINE_COULEUR/general_devine_couleur.h"
#include "../GAME/FUIR/general_fuir.h"
#include "../GAME/EPARGNER/general_epargner.h"
#include "../GAME/ESQUIVE/CUBE_PRISON/general_cube_prison.h"

#include "../GAME/general_combat.h"

/**
* \brief Représentation du monde du jeu
*/
struct world_s{
	SDL_Surface* background;
	joueur_t j;
	objet_t o;
	menu_t menu;
	combat_t combat;
	int gameover;
};
typedef struct world_s world_t;


