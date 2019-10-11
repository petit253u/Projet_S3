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
			world->joueur.y = world->objet.yobj - world->joueur.hauteur - 4 ; 
		break;
		case 2: 
			world->joueur.x = world->objet.xobj - world->joueur.largeur - 4 ;
		break;
		case 3: 
			world->joueur.y = world->objet.yobj + world->objet.hauteur + 4 ;
		break;
		case 4: 
			world->joueur.x = world->objet.xobj + world->objet.largeur + 4 ;
		break;
		default:  
			printf("ERREUR!!");
		break;
	}
}

void quel_replacement(world_t* world){
	int bord = 0;
	switch(world->joueur.cote){
		case 1:
			bord = 3;
		break;
		case 2:
			bord = 4;
		break;
		case 3:
			bord = 1;
		break;
		case 4:
			bord = 2;
		break;
	}
	replacement(world,bord);
}

void update_sprite_joueur(world_t *world){
	switch(world->joueur.cote){
		case 1 :
			world->joueur.sprite = world->joueur.sprite1;
			break;
		case 2 :
			world->joueur.sprite = world->joueur.sprite2;
			break;
		case 3 :
			world->joueur.sprite = world->joueur.sprite3;
			break;
		case 4 :
			world->joueur.sprite = world->joueur.sprite4;
			break;
	}  
}

void update_collision_bords(world_t *world){
	// BORD HAUT
	if(world->joueur.y <= 0){
		world->joueur.y = 0;
	} 
	// BORD GAUCHE
	if(world->joueur.x <= 0){
		world->joueur.x = 0;
	} 
	// BORD BAS
	if(world->joueur.y + world->joueur.hauteur >= SCREEN_HEIGHT){
		world->joueur.y = SCREEN_HEIGHT - world->joueur.hauteur;
	} 
	// BORD DROIT
	if(world->joueur.x + world->joueur.largeur >= SCREEN_WIDTH){
		world->joueur.x = SCREEN_WIDTH - world->joueur.largeur;
	} 
}

void update_collision_obj(world_t *world){
	if((world->joueur.x + world->joueur.largeur >= world->objet.xobj) && (world->joueur.x <= world->objet.xobj + world->objet.largeur)){
		if((world->joueur.y + world->joueur.hauteur >= world->objet.yobj) && (world->joueur.y <= world->objet.yobj + world->joueur.hauteur)){
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
* \brief La fonction applique la surface de l'image de fond à quatre positions différentes sur l'écran de jeu, de sorte de complètement couvrir ce dernier
* \param screen l'écran de jeu
* \param bg la surface de l'image de fond
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
	apply_surface(world->joueur.sprite,screen,world->joueur.x,world->joueur.y);
	apply_surface(world->objet.sprite_objet,screen,world->objet.xobj,world->objet.yobj);
	refresh_surface(screen);
}
