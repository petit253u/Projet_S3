/**
* \file init_snake.h
* \brief Module d'inititialisation
* \author 
* \version 0.1
* \date 
*/

#ifndef INIT_DEVINE_COULEUR_H
#define INIT_DEVINE_COULEUR_H

#include "../../../GENERAL/sdl-light.h"

void init_bouton_arcade_devine(bouton_devine_arcade_t* b,int i);

char lire_devine_random(int random);

void init_devine_level(devine_couleur_t* dc);

void init_devine_couleur(devine_couleur_t* dc);

#endif
