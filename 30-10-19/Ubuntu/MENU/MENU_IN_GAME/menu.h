#ifndef MENU_H
#define MENU_H

#include "../../GENERAL/sdl-light.h"

void update_click_souris_1(menu_t *debut, int x, int y);

void update_pos_souris_1(menu_t *debut, int x, int y);

void handle_event_menu(SDL_Event *event, menu_t *menu, int *b);

void  init_graphics_menu(SDL_Surface *ecran_menu, menu_t *menu);

void refresh_graphics_debut_1(SDL_Surface *ecran_menu, menu_t *menu);

void refresh_bouton_1(menu_t *debut);

void verif_pos_1(menu_t *debut);

int boucle_menu(world_t *world,SDL_Surface *ecran_menu);

#endif
