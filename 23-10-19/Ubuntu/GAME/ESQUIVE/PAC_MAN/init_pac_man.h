/**
* \file init_snake.h
* \brief Module d'inititialisation
* \author 
* \version 0.1
* \date 
*/

#ifndef INIT_SNAKE_H
#define INIT_SNAKE_H

#include "../../../GENERAL/sdl-light.h"

void init_mur_snake_level_1(mur_snake_t* mur);

void init_pointfaible_snake_level_1(pointfaible_snake_t* pf);

void init_corps_snake_level_1(corps_snake_t* c, int* x1, int y1);

void init_objet_snake_level_1(objet_snake_t* o);

void init_graphics_mur_snake(mur_snake_t* mur, SDL_Surface *ecran);

void init_level_1_snake(snake_t* snake);

void init_snake(snake_t* snake);

#endif
