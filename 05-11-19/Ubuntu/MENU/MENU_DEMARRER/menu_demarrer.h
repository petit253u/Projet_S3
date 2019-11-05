/**
* \file init_fuir.h
* \brief Module d'inititialisation
* \author 
* \version 0.1
* \date 
*/

#ifndef MENU_DEMARRER_H
#define MENU_DEMARRER_H

#include "../../GENERAL/sdl-light.h"

void update_click_souris(menu_entree_t* debut, int x, int y);

void update_pos_souris(menu_entree_t* debut, int x, int y);

void handle_event_debut(SDL_Event *event, menu_entree_t* debut);

void verif_click(menu_entree_t* debut);

void refresh_bouton(menu_entree_t* debut);

void verif_pos(menu_entree_t* debut);

void init_graphics_debut(SDL_Surface *ecran_debut, menu_entree_t* debut);

void refresh_graphics_debut(SDL_Surface *ecran_debut, menu_entree_t* debut);

#endif
