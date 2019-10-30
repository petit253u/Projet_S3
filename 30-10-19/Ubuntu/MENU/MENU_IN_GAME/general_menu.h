/**
* \file general_fuir.h
* \brief Module de structure et constante
* \author 
* \version 0.1
* \date 
*/

#include "../../GENERAL/sdl-light.h"
#include <stdbool.h> 

///////////////////////////////////////////////////////

#define SPRITE_BOUTON_WIDTH 600

#define SPRITE_BOUTON_HEIGHT 150

///////////////////////////////////////////////////////

struct menu_s{
	bool ouvert; //true : menu ouvert ; false : menu fermé
	SDL_Surface* fond;
	SDL_Surface* bouton1;
	SDL_Surface* bouton2;
	bouton_t b;
	int lequel;
	int gameover;
	SDL_Surface* bouton;
	souris_t souris;
};
typedef struct menu_s menu_t;

