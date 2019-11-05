#ifndef CUBE_PRISON_H
#define CUBE_PRISON_H

#include "../../../GENERAL/sdl-light.h"

void init_graphics_cube_prison_attaque(attaque_cube_t* a,SDL_Surface *ecran);

void init_graphics_cube_prison_joueur(joueur_cube_t* j,SDL_Surface *ecran);

void init_graphics_cube_prison(cube_prison_t* cube , SDL_Surface *ecran);

void update_pv_joueur_cube(world_t* world,attaque_cube_t* a);

void verif_collision_cube_attaque(world_t* world,attaque_cube_t* a,joueur_cube_t* j,temps_t* t);

void verif_pv_joueur_cube(world_t* world);

void verif_collision_cube(world_t* world);

void update_data_cube_attaque(attaque_cube_t* a);

void update_data_cube_joueur(joueur_cube_t* j, souris_t* s);

void update_date_cube_temps(temps_t* t);

void update_data_cube(cube_prison_t* cube);

void update_pos_souris_cube(souris_t* souris, int x, int y);

void handle_event_cube(SDL_Event *event, world_t *world);

void boucle_cube_prison(world_t* world, SDL_Surface *ecran);

#endif
