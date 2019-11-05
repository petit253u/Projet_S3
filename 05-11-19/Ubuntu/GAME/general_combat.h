/**
* \file general_fuir.h
* \brief Module de structure et constante
* \author 
* \version 0.1
* \date 
*/

#include "../GENERAL/sdl-light.h"
#include <stdbool.h> 

///////////////////////////////////////////////////////

#define NB_BOUTON_COMBAT 4

///////////////////////////////////////////////////////

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
	SDL_Surface* f1;
	SDL_Surface* f2;
	SDL_Surface* f3;
	
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

	snake_t snake;
	devine_couleur_t devine;
	/*casse_brique_t casse_brique;
	pac_man_t pac_man;*/
	//fuis_les_lignes_t fuis_les_lignes;
	fuir_t fuir;
	epargner_t epargner;
	cube_prison_t cube;
	
	bool ouvert;
	bool victoire; // true : victoire, false : perdu
	int gameover;
};
typedef struct combat_s combat_t;
