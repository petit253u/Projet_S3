/**
* \file update.c
* \brief Module d'update
* \author 
* \version 0.1
* \date 
*/

#ifndef UPDATE_H
#define UPDATE_H

#include "../GENERAL/sdl-light.h"

void replacement(world_t* world, int bord);

void quel_replacement(world_t* world);

void update_sprite_joueur(world_t *world);

void update_collision_bords(world_t *world);

void update_collision_obj(world_t *world);

void update_data(world_t *world);

void apply_background(SDL_Surface *bg, SDL_Surface *screen);

void refresh_graphics(SDL_Surface *screen, world_t *world);

void refresh_graphics_joueur(SDL_Surface *screen, joueur_t j);

void refresh_graphics_objet(SDL_Surface *screen, objet_t o);



#endif


