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
#define LEVEL_HEIGHT 1530

/**
* \brief Largeur de l'écran de jeu
*/
#define SCREEN_WIDTH 1000

/**
* \brief Hauteur de l'écran de jeu
*/
#define SCREEN_HEIGHT 650

/**
* \brief Taille d'une bulle
*/
#define BUB_SIZE 40

/**
* \brief Taille du bonhomme (sprite)
*/
#define SPRITE_SIZE_HEIGHT 100

/**
* \brief Taille du bonhomme (sprite)
*/
#define SPRITE_SIZE_WIDTH 50

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
#define SPRITE_BOUTON_HEIGHT 150

/**
* \brief Pas de déplacement du sprite
*/
#define MOVING_STEP 10

/**
* \brief Pas de déplacement du sprite
*/
#define NB_BOUTON_COMBAT 4

/**
* \brief Nombre paterne dans fuis les lignes
*/
#define NB_PATERNE 2

/**
* \brief Nombre objet max par paterne dans fuis les lignes
*/
#define NB_OBJET_PATERNE 70

#define TAILLE_ECRAN_FLL_WIDTH 850

#define TAILLE_ECRAN_FLL_HEIGHT 400

#define DISTANCE_CADRE_FLL 75

#define TAILLE_COTE_SPRITE_FLL 50

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

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

/**
* \brief Représentation du menu
*/
struct menu_s{
	bool ouvert; //true : menu ouvert ; false : menu fermé
	SDL_Surface* fond;
	SDL_Surface* bouton1;
	SDL_Surface* bouton2;
	bouton_t b;
	int lequel;
	int gameover;
	SDL_Surface* bouton;
	souris_t souris;
};
typedef struct menu_s menu_t;

/**
* \brief Représentation du joueur
*/
struct joueur_s{
	int x;
	int y; 
	int largeur;
	int hauteur;
	int cote; // 1 : haut, 2 : gauche, 3 : bas, 4 : droite
	SDL_Surface* sprite;
	SDL_Surface* sprite1;
	SDL_Surface* sprite2;
	SDL_Surface* sprite3;
	SDL_Surface* sprite4;
	char direction;
	int pv;
};
typedef struct joueur_s joueur_t;

//////////////////////////////////////////////////////////////////////////

struct objet_paterne_s{
	int x;
	int y; 
	int largeur;
	int hauteur;
	double vx;
	double vy;
	SDL_Surface* sprite;
};
typedef struct objet_paterne_s objet_paterne_t;

struct paterne_s{
	objet_paterne_t tab_objet[NB_OBJET_PATERNE];
	int nb_objet;
};
typedef struct paterne_s paterne_t;

struct joueur_fll_s{
	int x;
	int y; 
	int largeur;
	int hauteur;
	SDL_Surface* sprite;
	SDL_Surface* s1;
	SDL_Surface* s2;
};
typedef struct joueur_fll_s joueur_fll_t;

struct fuis_les_lignes_s{
	int gameover;
	bool ouvert;//true : fll ouvert ; false : fll fermé
	paterne_t tab_paterne[NB_PATERNE];
	int nb_paterne;
	int choix_paterne; //1 : paterne 1 ; 2 : paterne 2
	joueur_fll_t j;
	int pv_restant;
	SDL_Surface* fond_base;
	SDL_Surface* fond_fll;
};
typedef struct fuis_les_lignes_s fuis_les_lignes_t;

//////////////////////////////////////////////////////////////////////////

struct bouton_combat_s{
	int x;
	int y;
	int largeur;
	int hauteur;
	bool cliquable;//true : on peut cliquer dessus, false : on ne peut pas
	SDL_Surface* sprite;
	SDL_Surface* b1;
	SDL_Surface* b2;
	SDL_Surface* b3;
	SDL_Surface* b4;
	SDL_Surface* b5;
};
typedef struct bouton_combat_s bouton_combat_t;


struct combat_s{
	SDL_Surface* fond;
	
	bouton_combat_t tab_bouton[NB_BOUTON_COMBAT];
	int nb_bouton;
	int nb_attaque;
	int tour; // 1 : tour ennemi, 2 : tour Joueur
	int etape;// 1 = etape 1 ; 2 = etape 2 ; 3 = etape 3

	/*SDL_Surface* sprite_ennemi;
	SDL_Surface* se1;
	SDL_Surface* se2;*/

	int pv_restant;
	//ennemi_t ennemi;
	souris_t souris;

	/*snake_t snake;
	pong_t pong;
	casse_brique_t casse_brique;
	pac_man_t pac_man;*/
	fuis_les_lignes_t fuis_les_lignes;
	
	bool ouvert;
	bool victoire; // true : victoire, false : perdu
	int gameover;
};
typedef struct combat_s combat_t;

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


