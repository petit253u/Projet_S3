/**
* \file init.c
* \brief Module d'inititialisation
* \author 
* \version 0.1
* \date 
*/

#ifndef INIT_H
#define INIT_H

#include "../GENERAL/sdl-light.h"

void init_data_souris(souris_t souris);

void init_data_debut(menu_entree_t* debut);

void init_data_objet(objet_t * objet);

void init_data_joueur(joueur_t * joueur);

void init_objet_fll(objet_paterne_t* o, int x, int y);

void init_paterne_fll_2(paterne_t* p);

void init_paterne_fll_1(paterne_t* p);

void init_paterne_fll(paterne_t* p, int i);

void init_joueur_fll(joueur_fll_t* j);

void init_data_fll(fuis_les_lignes_t* fll);

void init_data_bouton_combat(bouton_combat_t *b, int* temp, int i);

void init_data_combat(combat_t *c);

void init_data(world_t * world);

void init_graphics(SDL_Surface *screen, world_t *world);

#endif
