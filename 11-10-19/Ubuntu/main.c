/**
* \file main.c
* \brief Programme principal du jeu
* \author 
* \version 0.1
* \date 
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <stddef.h> 

#include "GENERAL/sdl-light.h"
#include "GENERAL/general.h"
#include "UPDATE/update.h"
#include "INIT/init.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
* \brief La fonction nettoie les données du monde
* \param world les données du monde
*/


void clean_data(world_t *world){
	SDL_FreeSurface(world->background);
	SDL_FreeSurface(world->joueur.sprite);
	SDL_FreeSurface(world->joueur.sprite1);
	SDL_FreeSurface(world->joueur.sprite2);
	SDL_FreeSurface(world->joueur.sprite3);
	SDL_FreeSurface(world->joueur.sprite4);
	SDL_FreeSurface(world->objet.sprite_objet);
}

/**
* \brief La fonction indique si le jeu est fini en fonction des données du monde
* \param world les données du monde
* \return 1 si le jeu est fini, 0 sinon
*/

int is_game_over(world_t *world){
	return world->gameover;
}

/**
* \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
* \param event paramètre qui contient les événements
* \param world les données du monde
*/


void handle_events(SDL_Event *event,world_t *world){
	Uint8 *keystates;
	while( SDL_PollEvent( event ) ) {
		//Si l'utilisateur a cliqué sur le X de la fenêtre
		if( event->type == SDL_QUIT ) {
			//On quitte le programme
			world->gameover = 1;
		}
		/* gestion des evenements clavier */
		keystates = SDL_GetKeyState( NULL );
		/* Si l'utilisateur appuie sur
		la touche z (constante SDLK_z) */
		if( keystates[ SDLK_z ] ) {
			world->joueur.y = world->joueur.y - MOVING_STEP; 
			world->joueur.cote = 1;
		}
		if( keystates[ SDLK_q ] ) {
			world->joueur.x = world->joueur.x - MOVING_STEP; 
			world->joueur.cote = 2;
		}
		if( keystates[ SDLK_s ] ) {
			world->joueur.y = world->joueur.y + MOVING_STEP; 
			world->joueur.cote = 3;
		}
		if( keystates[ SDLK_d ] ) {
			world->joueur.x = world->joueur.x + MOVING_STEP; 
			world->joueur.cote = 4;
		}
		/*if( keystates[ SDLK_e ] ) {
			//inventaire
		}
		if( keystates[ SDLK_r] ) {
			//ramasser
		}
		if( keystates[ SDLK_ ] ) {
		}
		if( keystates[ SDLK_ ] ) {
		}*/
	}

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** 
*  \brief programme principal qui implémente la boucle du jeu
*/

int main( int argc, char* args[] )
{
	SDL_Event event;
	world_t world;
	SDL_Surface *screen;
	screen = init_sdl(SCREEN_WIDTH, SCREEN_HEIGHT);
	init_data(&world);
	init_graphics(screen,&world);
	SDL_EnableKeyRepeat(20,20);
	while(!is_game_over(&world)){
		handle_events(&event,&world);
		update_data(&world);
		refresh_graphics(screen,&world);
		SDL_Delay(10);
	}
	clean_data(&world);
	quit_sdl();
	return 0;
}
