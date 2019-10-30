/**
* \file init_snake.h
* \brief Module d'inititialisation
* \author 
* \version 0.1
* \date 
*/

#ifndef INIT_CUBE_PRISON_H
#define INIT_CUBE_PRSION_H

#include "../../../GENERAL/sdl-light.h"

void init_temps_cube(temps_t* t);

void init_souris_cube(souris_t* s);

void init_joueur_cube(joueur_cube_t* j);

//////////////////////////////////////////// ATTAQUES //////////////////////////////////////////////

void init_attaque_cube_type_1(attaque_cube_t* a, int x, int y, char zqsd);

void init_attaque_cube_type_n(attaque_cube_t* a, int x, int y, int n, char zqsd);

//////////////////////////////////////////// PATERNES //////////////////////////////////////////////

void init_attaque_paterne_1_cube(paterne_t* p);

void init_paterne_1_cube(paterne_t* p);

void init_paterne_cube(cube_prison_t* cube);

//////////////////////////////////////////// ALL //////////////////////////////////////////////

void init_cube_prison(cube_prison_t* cube);

#endif
