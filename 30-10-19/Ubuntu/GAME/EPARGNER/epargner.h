#ifndef FUIR_H
#define FUIR_H

#include "../../GENERAL/sdl-light.h"

void resultat_epargner(combat_t* combat);

void verif_pos_souris_epargner_carte(carte_valide_t* carte, souris_t* souris);

int verif_click_souris_epargner_carte(carte_valide_t* carte, souris_t* souris);

void verif_souris_epargner(epargner_t* epargner);

void update_click_souris_epargner(souris_t* souris, int x, int y);

void update_pos_souris_epargner(souris_t* souris, int x, int y);

void init_graphics_carte_epargner(carte_valide_t* c, SDL_Surface *ecran);

void init_graphics_epargner(SDL_Surface *ecran, epargner_t* epargner);

void refresh_graphics_carte_epargner(carte_valide_t* c,SDL_Surface *ecran);

void refresh_graphics_epargner(epargner_t* epargner, SDL_Surface *ecran);

void handle_event_epargner(SDL_Event *event, world_t *world);

void boucle_epargner(world_t* world,SDL_Surface *ecran);

#endif
