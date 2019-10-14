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

void init_data(world_t * world);

void init_graphics(SDL_Surface *screen, world_t *world);

#endif
