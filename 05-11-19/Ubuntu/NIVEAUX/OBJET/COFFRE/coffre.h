#ifndef COFFRE_H
#define COFFRE_H

#include "../../../GENERAL/sdl-light.h"

void init_graphics_coffre(coffre_t* c, SDL_Surface *ecran);

void refresh_graphics_coffre(coffre_t* c, SDL_Surface *ecran);

void coffre_reussi(coffre_t* c, world_t* world);

void coffre_echec(coffre_t* c, world_t* world);

void serrure_coffre(coffre_t* c, world_t* world, SDL_Surface *ecran);

void verif_click_coffre(coffre_t* c, souris_t* s, world_t* world, SDL_Surface *ecran);

#endif
