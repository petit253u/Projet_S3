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
	SDL_FreeSurface(world->sprite);
	SDL_FreeSurface(world->sprite1);
	SDL_FreeSurface(world->sprite2);
	SDL_FreeSurface(world->sprite3);
	SDL_FreeSurface(world->sprite4);
	SDL_FreeSurface(world->objet);
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
		la touche h (constante SDLK_h) */
		if( keystates[ SDLK_h ] ) {
			printf("J'ai appuye sur la touche h!\n");
		}
		if( keystates[ SDLK_z ] ) {
			world->j.y = world->j.y - MOVING_STEP; 
			world->j.cote = 1;
		}
		if( keystates[ SDLK_q ] ) {
			world->j.x = world->j.x - MOVING_STEP; 
			world->j.cote = 2;
		}
		if( keystates[ SDLK_s ] ) {
			world->j.y = world->j.y + MOVING_STEP; 
			world->j.cote = 3;
		}
		if( keystates[ SDLK_d ] ) {
			world->j.x = world->j.x + MOVING_STEP; 
			world->j.cote = 4;
		}

	}

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_souris(menu_entree_t *debut, int x, int y){
	debut->souris.x = x;
	debut->souris.y = y;
}

/**
* \brief La fonction nettoie les données du monde
* \param world les données du monde
*/
void clean_data_debut(menu_entree_t *debut){
	SDL_FreeSurface(debut->background);
	SDL_FreeSurface(debut->bouton);
	SDL_FreeSurface(debut->bouton1);
	SDL_FreeSurface(debut->bouton2);
}

/**
* \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
* \param event paramètre qui contient les événements
* \param world les données du monde
*/
void handle_event_debut(SDL_Event *event, menu_entree_t *debut){
	int mouseX, mouseY;
	while( SDL_PollEvent( event ) ) {
		//Si l'utilisateur a cliqué sur le X de la fenêtre
		if( event->type == SDL_QUIT ) {
			//On quitte le programme
			debut->gameover = 1;
			debut->fermer =1;
		}
		/* Si l'utilisateur appuie sur
		la touche droite de la souris */
		if( event->type == SDL_MOUSEBUTTONUP){
              		SDL_GetMouseState(&mouseX, &mouseY);
			debut->x = mouseX;
			debut->y = mouseY;
		}
		else{
			SDL_GetMouseState(&mouseX, &mouseY);
			update_souris(debut, mouseX, mouseY);
		}
	}
}

void verif_click(menu_entree_t *debut){
	if((debut->x >= debut->o.xobj) && (debut->x <= (debut->o.xobj + debut->o.largeur))){
		if((debut->y >= debut->o.yobj) && (debut->y <= (debut->o.yobj + debut->o.hauteur))){
			debut->fermer = 1 ;
		}
	}
}

void refresh_bouton(menu_entree_t *debut){
	switch(debut->lequel){
		case 1:
			debut->bouton = debut->bouton1;
			break;
		case 2:
			debut->bouton = debut->bouton2;
			break;
	}	
}

void verif_pos(menu_entree_t *debut){
	if((debut->souris.x >= debut->o.xobj) && (debut->souris.x <= (debut->o.xobj + debut->o.largeur))){
		if((debut->souris.y >= debut->o.yobj) && (debut->souris.y <= (debut->o.yobj + debut->o.hauteur))){
			debut->lequel = 2; 
			printf("DESSUS\n");
		}
		else{
			debut->lequel = 1;
		}
	}
	else{
		debut->lequel = 1; 
	}
	refresh_bouton(debut);
}

void  init_graphics_debut(SDL_Surface *ecran_debut, menu_entree_t *debut){
	set_transparence(ecran_debut, debut->bouton1, 255, 0, 255);
	set_transparence(ecran_debut, debut->bouton2, 255, 0, 255);
}

/**
* \brief La fonction rafrachit l'écran en fonction de l'état des données du monde
* \param screen la surface de l'écran de jeu
* \param world les données du monde
*/
void refresh_graphics_debut(SDL_Surface *ecran_debut, menu_entree_t *debut){
	apply_background(debut->background,ecran_debut);

	apply_surface(debut->bouton,ecran_debut, 1000, 300);

	refresh_surface(ecran_debut);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu_jeu(){
	SDL_Event event0;
	menu_entree_t debut;
	SDL_Surface *ecran_debut;
	ecran_debut = init_sdl(SCREEN_WIDTH, SCREEN_HEIGHT);
	int a;

	init_data_debut(&debut);
	init_graphics_debut(ecran_debut, &debut);

	SDL_EnableKeyRepeat(20,20);
	while(debut.fermer != 1){
		handle_event_debut(&event0, &debut);
		verif_pos(&debut);
		refresh_graphics_debut(ecran_debut,&debut);
		verif_click(&debut);
	}
	a = debut.gameover;
	clean_data_debut(&debut);
	return a;
}

void boucle_jeu(world_t *world, int a){
	SDL_Event event;
	SDL_Surface *screen;

	screen = init_sdl(SCREEN_WIDTH, SCREEN_HEIGHT);

	init_data(world);
	init_graphics(screen,world);

	world->gameover = a;

	SDL_EnableKeyRepeat(20,20);

	while(!is_game_over(world)){
		handle_events(&event,world);
		update_data(world);
		refresh_graphics(screen,world);
		SDL_Delay(10);
	}
	return;
}

void libere_jeu(world_t *world){
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

	a = menu_jeu();
	boucle_jeu(&world, a);
	libere_jeu(&world);
	return 0;
}
