/**
* \file init_fuir.h
* \brief Module d'inititialisation
* \author 
* \version 0.1
* \date 
*/

#ifndef INIT_COMBAT_H
#define INIT_COMBAT_H

#include "../GENERAL/sdl-light.h"

void init_data_bouton_attaquer(bouton_combat_t *b);

void init_data_bouton_discuter(bouton_combat_t *b);

void init_data_bouton_objet(bouton_combat_t *b);

void init_data_bouton_fuir(bouton_combat_t *b);

void init_data_bouton_combat(bouton_combat_t *b, int* temp, int i);

void init_data_combat(combat_t *c);

#endif
