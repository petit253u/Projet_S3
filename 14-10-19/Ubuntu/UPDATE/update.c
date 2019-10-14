/**
* \file update.c
* \brief Module d'update
* \author 
* \version 0.1
* \date 
*/

#include "../GENERAL/general.h"

void replacement(world_t* world, int bord){
	switch(bord){
		case 1: 
			world->j.y = world->o.yobj - SPRITE_SIZE_HEIGHT ; 
			break;
		case 2: 
			world->j.x = world->o.xobj - SPRITE_SIZE_WIDTH ;
			break;
		case 3: 
			world->j.y = world->o.yobj + SPRITE_TEST_HEIGHT ;
			break;
		case 4: 
			world->j.x = world->o.xobj + SPRITE_TEST_WIDTH ;
			break;
	}
}

void quel_replacement(world_t* world){
	int bord = 0;
	replacement(world, bord);
}

void update_sprite_joueur(world_t *world){
	switch(world->j.cote){
		case 1 :
			world->sprite = world->sprite1;
			break;
		case 2 :
			world->sprite = world->sprite2;
			break;
		case 3 :
			world->sprite = world->sprite3;
			break;
		case 4 :
			world->sprite = world->sprite4;
			break;
	}
}

void update_collision_bords(world_t *world){
	// BORD HAUT
	if(world->j.y <= 0){
		world->j.y = 0;
	} 
	// BORD GAUCHE
	if(world->j.x <= 0){
		world->j.x = 0;
	} 
	// BORD BAS
	if(world->j.y + SPRITE_SIZE_HEIGHT >= SCREEN_HEIGHT){
		world->j.y = SCREEN_HEIGHT - SPRITE_SIZE_HEIGHT;
	} 
	// BORD DROIT
	if(world->j.x + SPRITE_SIZE_WIDTH >= SCREEN_WIDTH){
		world->j.x = SCREEN_WIDTH - SPRITE_SIZE_WIDTH;
	} 
}

void update_collision_obj(world_t *world){
	if((world->j.x + SPRITE_SIZE_WIDTH >= world->o.xobj) && (world->j.x <= world->o.xobj + SPRITE_TEST_WIDTH)){
		if((world->j.y + SPRITE_SIZE_HEIGHT >= world->o.yobj) && (world->j.y <= world->o.yobj + SPRITE_TEST_HEIGHT)){
			quel_replacement(world);
		}
	}	
}


/**
* \brief La fonction met à jour les données en tenant compte de la physique du monde
* \param les données du monde
*/

void update_data(world_t *world){
	update_sprite_joueur(world);
	update_collision_bords(world);
	update_collision_obj(world);
}

/**
* \brief La fonction applique la surface de l'image de fond 
* \param screen l'écran de jeu
* \param bg l'image de fond
*/
void apply_background(SDL_Surface *bg, SDL_Surface *screen){
	apply_surface(bg,screen,0,0);
}

/**
* \brief La fonction rafrachit l'écran en fonction de l'état des données du monde
* \param screen la surface de l'écran de jeu
* \param world les données du monde
*/

void refresh_graphics(SDL_Surface *screen, world_t *world){
	apply_background(world->background,screen);
	apply_surface(world->sprite,screen,world->j.x,world->j.y);
	apply_surface(world->objet,screen,world->o.xobj,world->o.yobj);

	refresh_surface(screen);
}
