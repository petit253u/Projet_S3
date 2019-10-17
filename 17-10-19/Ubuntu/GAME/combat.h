#ifndef COMBAT_H
#define COMBAT_H

#include "../GENERAL/sdl-light.h"

void attaquer(world_t* world);

void win_or_loose(world_t *world);

void init_graphics_bouton_combat(SDL_Surface *ecran,bouton_combat_t* b);

void init_graphics_combat(SDL_Surface *ecran, combat_t *combat);

void refresh_graphics_bouton_combat(SDL_Surface *ecran,bouton_combat_t* b,int* temp);

void refresh_graphics_combat(SDL_Surface *ecran, combat_t *combat);

void update_click_souris_2(combat_t* combat, int x, int y);

void update_pos_souris_2(combat_t* combat, int x, int y);

void handle_event_combat(SDL_Event *event, combat_t *combat);

void quel_action(int i, world_t* world);

void verif_click_bouton_combat(bouton_combat_t *b, souris_t* souris, int i, world_t* world);

void verif_click_combat(combat_t *combat, world_t* world);

int boucle_combat(world_t *world, SDL_Surface *ecran);

#endif
