#ifndef FUIR_H
#define FUIR_H

#include "../../GENERAL/sdl-light.h"

void resultat_fuir(combat_t* combat);

void verif_pos_souris_fuir_carte(carte_fuir_t* carte, souris_t* souris);

void verif_pos_souris_fuir(fuir_t* fuir);

int verif_click_souris_fuir_carte(carte_fuir_t* carte, souris_t* souris);

int verif_click_souris_fuir(fuir_t* fuir);

void verif_souris_fuir(fuir_t* fuir);

void update_click_souris_fuir(souris_t* souris, int x, int y);

void update_pos_souris_fuir(souris_t* souris, int x, int y);

void init_graphics_carte_fuir(carte_fuir_t* c, SDL_Surface *ecran);

void init_graphics_fuir(SDL_Surface *ecran, fuir_t* fuir);

void refresh_graphics_carte_fuir(carte_fuir_t* c,SDL_Surface *ecran);

void refresh_graphics_fuir(fuir_t* fuir, SDL_Surface *ecran);

void handle_event_fuir(SDL_Event *event, world_t *world);

void boucle_fuir(world_t* world,SDL_Surface *ecran);

#endif
