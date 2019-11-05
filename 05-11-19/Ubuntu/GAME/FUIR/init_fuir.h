/**
* \file init_fuir.h
* \brief Module d'inititialisation
* \author 
* \version 0.1
* \date 
*/

#ifndef INIT_FUIR_H
#define INIT_FUIR_H

#include "../../GENERAL/sdl-light.h"

void init_souris_fuir(souris_t* souris);

void init_carte_fuir_chaque(carte_fuir_t* carte, int x, int y, bool bonne);

void init_carte_fuir(fuir_t* fuir);

void init_fuir(fuir_t* fuir);

#endif
