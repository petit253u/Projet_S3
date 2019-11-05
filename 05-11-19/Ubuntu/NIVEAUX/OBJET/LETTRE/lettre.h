#ifndef LETTRE_H
#define LETTRE_H

#include "../../../GENERAL/sdl-light.h"

void init_graphics_lettre(lettre_t* l, SDL_Surface *ecran);

void refresh_graphics_lettre(lettre_t* l, SDL_Surface *ecran);

void lire_lettre(lettre_t* l, world_t* world, SDL_Surface *ecran);

void verif_click_lettre(lettre_t* l, souris_t* s, world_t* world, SDL_Surface *ecran);

#endif
