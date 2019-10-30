#ifndef SNAKE_H
#define SNAKE_H

#include "../../../GENERAL/sdl-light.h"

void attaque_reussie(snake_t* snake);

void delete_objet_snake(snake_t* snake);

void init_corps_sup_snake(snake_t* snake);

void verif_collision_bordure_snake(snake_t* snake);

void verif_collision_mur_snake(snake_t* snake);

void verif_collision_corps_snake(snake_t* snake);

void verif_collision_objet_snake(snake_t* snake);

void verif_collision_pointfaible_ennemi(snake_t* snake);

void verif_collision_snake(snake_t* snake);

void update_corps_snake(snake_t* snake);

void update_tete_snake(snake_t* snake);

void update_timer_snake(snake_t* snake);

void update_data_snake(snake_t* snake);

void init_graphics_corps_snake(corps_snake_t* corps, SDL_Surface *ecran);

void init_graphics_objet_snake(objet_snake_t* objet, SDL_Surface *ecran);

void init_graphics_mur_snake(mur_snake_t* mur, SDL_Surface *ecran);

void init_graphics_pointfaible_snake(pointfaible_snake_t* pf, SDL_Surface *ecran);

void init_graphics_snake(SDL_Surface *ecran, snake_t* snake);

void refresh_graphics_corps_snake(corps_snake_t* corps, SDL_Surface *ecran);

void refresh_graphics_objet_snake(objet_snake_t* objet, SDL_Surface *ecran);

void refresh_graphics_mur_snake(mur_snake_t* mur, SDL_Surface *ecran);

void refresh_graphics_pointfaible_snake(pointfaible_snake_t* pf, SDL_Surface *ecran);

void refresh_graphics_snake(snake_t* snake, SDL_Surface *ecran);

void handle_event_snake(SDL_Event *event, world_t *world);

int boucle_snake(world_t* world,SDL_Surface *ecran);

#endif
