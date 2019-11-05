/**
* \file main.c
* \brief Programme principal du jeu
* \author 
* \version 0.1
* \date 
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <stddef.h> 

#include "GENERAL/sdl-light.h"
#include "GENERAL/general.h"

#include "UPDATE/update.h"

#include "INIT/init.h"

#include "MENU/MENU_IN_GAME/init_menu.h"
#include "MENU/MENU_IN_GAME/menu.h"

#include "MENU/MENU_DEMARRER/init_menu_demarrer.h"
#include "MENU/MENU_DEMARRER/menu_demarrer.h"

#include "JOUEUR/init_joueur.h"

#include "GAME/init_combat.h"
#include "GAME/combat.h"

#include "GAME/FUIR/init_fuir.h"
#include "GAME/FUIR/fuir.h"

#include "GAME/EPARGNER/init_epargner.h"
#include "GAME/EPARGNER/epargner.h"

#include "GAME/ATTAQUE/SNAKE/init_snake.h"
#include "GAME/ATTAQUE/SNAKE/snake.h"

#include "GAME/ATTAQUE/DEVINE_COULEUR/init_devine_couleur.h"
#include "GAME/ATTAQUE/DEVINE_COULEUR/devine_couleur.h"

#include "GAME/ESQUIVE/CUBE_PRISON/init_cube_prison.h"
#include "GAME/ESQUIVE/CUBE_PRISON/cube_prison.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
* \brief La fonction nettoie les données du monde
* \param world les données du monde
*/


void clean_data(world_t *world){
	SDL_FreeSurface(world->background);
	SDL_FreeSurface(world->j.sprite);
	SDL_FreeSurface(world->j.s1);
	SDL_FreeSurface(world->j.s2);
	SDL_FreeSurface(world->o.sprite);
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
void handle_events(SDL_Event *event,world_t *world, SDL_Surface *screen){
	Uint8 *keystates;
	while( SDL_PollEvent( event ) ) {
		//Si l'utilisateur a cliqué sur le X de la fenêtre
		if( event->type == SDL_QUIT ) {
			//On quitte le programme
			world->gameover = 1;
		}
		/* gestion des evenements clavier */
		keystates = SDL_GetKeyState( NULL );
		if( keystates[ SDLK_q ] ) {
			world->j.x = world->j.x - MOVING_STEP; 
			world->j.dir = 'q'; 
			world->j.cote = 2;
		}
		else if( keystates[ SDLK_d ] ) {
			world->j.x = world->j.x + MOVING_STEP;
			world->j.dir = 'd';  
			world->j.cote = 4;
		}
		if( keystates[ SDLK_ESCAPE ] ) {
			world->gameover = boucle_menu(world,screen);
		}
// QUITTER RAPIDEMENT : X
		if( keystates[ SDLK_p ] ) {
			world->gameover = 1;
		}
// GESTION DES COMBATS : TEST
		if( keystates[ SDLK_a ] ) {
			printf("ATTAQUE D'UN ENNEMI\n");
			world->gameover = boucle_combat(world,screen);
			printf("SORTIE\n");
		}	
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu_jeu(){
	printf("BOUCLE MENU DEPART :\n");

	SDL_Event event0;
	menu_entree_t debut;
	SDL_Surface *ecran_debut;
	ecran_debut = init_sdl(SCREEN_WIDTH, SCREEN_HEIGHT);
	int a;

	init_data_debut(&debut);
printf("	4 :\n");
	init_graphics_debut(ecran_debut, &debut);

	SDL_EnableKeyRepeat(20,20);
	while(debut.fermer != 1){
		handle_event_debut(&event0, &debut);
		verif_pos(&debut);
		refresh_graphics_debut(ecran_debut,&debut);
		verif_click(&debut);
	}
	a = debut.gameover;
	return a;
}

void boucle_jeu(world_t *world, int a){
	printf("BOUCLE JEU :\n");

	SDL_Event event;
	SDL_Surface *screen;

	screen = init_sdl(SCREEN_WIDTH, SCREEN_HEIGHT);

	printf("	INIT_WORLD :\n");
	init_data(world);
	printf("	INIT_GRAPH :\n");
	init_graphics(screen,world);

	world->gameover = a;

	//world->j.x = 500;
	//world->j.y = 300;

	SDL_EnableKeyRepeat(100,100);

	while(!is_game_over(world)){
		//printf("	HANDLE :\n");
		handle_events(&event,world,screen);
		//printf("	UP :\n");
		update_data(world);
		//printf("	REFRESH GRAPH :\n");
		refresh_graphics(screen,world);
		SDL_Delay(10);
	}
	return;
}

void libere_jeu(world_t *world){
	printf("BOUCLE VIDANGE :\n");
	clean_data(world);
	quit_sdl();
	return;
}

/**
*  \brief programme principal qui implémente la boucle du jeu
*/
int main( int argc, char* args[] )
{
	world_t world;
	int a;
	srand(time(NULL));
	
	a = menu_jeu();

	boucle_jeu(&world, a);

	libere_jeu(&world);
	return 0;
}
