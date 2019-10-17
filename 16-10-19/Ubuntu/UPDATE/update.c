/**
* \file update.c
* \brief Module d'update
* \author 
* \version 0.1
* \date 
*/

#include "../GENERAL/general.h"

void replacement(joueur_t* j, objet_t* o, int bord){
	switch(bord){
		case 1: 
			j->y = o->yobj - j->hauteur; 
			break;
		case 2: 
			j->x = o->xobj - j->largeur;
			break;
		case 3: 
			j->y = o->yobj + o->hauteur;
			break;
		case 4: 
			j->x = o->xobj + o->largeur;
			break;
	}
}

////////////////////////////////////////////////////////
void verif_largeur(joueur_t* j, objet_t* o, int* bord){
	bool temp = true;
	if((j->x + j->largeur + MOVING_STEP >= o->xobj) && (j->x + MOVING_STEP <= o->xobj +o->largeur)){
		temp = false;
	}
	if((j->x + j->largeur - MOVING_STEP >= o->xobj) && (j->x - MOVING_STEP <= o->xobj +o->largeur)){
		temp = false;
	}	
	if(temp == false){
		if(j->y < o->yobj+o->hauteur){
			*bord = 3;
		}
		else{
			*bord = 1;
		}
	}
}

void verif_hauteur(joueur_t* j, objet_t* o, int* bord){
	bool temp = true;
	if((j->y + j->hauteur + MOVING_STEP >= o->yobj) && (j->y + MOVING_STEP <= o->yobj +o->hauteur)){
		temp = false;
	}
	if((j->y + j->hauteur - MOVING_STEP >= o->yobj) && (j->y - MOVING_STEP <= o->yobj +o->hauteur)){
		temp = false;
	}		
	if(temp == false){
		if(j->x < o->xobj+o->largeur){
			*bord = 4;
		}
		else{
			*bord = 2;
		}
	}	
}

void quel_replacement(joueur_t* j, objet_t* o){
	int bord = 0;
	verif_largeur(j,o,&bord);
	//verif_hauteur(j,o,&bord);
	replacement(j,o,bord);
}
//////////////////////////////////////////////////////

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

void update_collision_obj(joueur_t* j, objet_t* o){
	if((j->x + j->largeur >= o->xobj) && (j->x <= o->xobj +o->largeur)){
		if((j->y + j->hauteur >= o->yobj) && (j->y <= o->yobj + o->hauteur)){
			printf("TOUCHE !\n");
			quel_replacement(j,o);
		}
	}
	printf("STOP !\n");	
}

void update_sprite_joueur(world_t *world){
	switch(world->j.cote){
		case 1 :
			world->j.sprite = world->j.sprite1;
			break;
		case 2 :
			world->j.sprite = world->j.sprite2;
			break;
		case 3 :
			world->j.sprite = world->j.sprite3;
			break;
		case 4 :
			world->j.sprite = world->j.sprite4;
			break;
	}
}

/**
* \brief La fonction met à jour les données en tenant compte de la physique du monde
* \param les données du monde
*/

void update_data(world_t *world){
	update_sprite_joueur(world);
	update_collision_bords(world);
	update_collision_obj(&world->j,&world->o);
}

/**
* \brief La fonction applique la surface de l'image de fond 
* \param screen l'écran de jeu
* \param bg l'image de fond
*/
void apply_background(SDL_Surface *bg, SDL_Surface *screen){
	apply_surface(bg,screen,0,0);
}


//////////////////////////
void refresh_graphics_joueur(SDL_Surface *screen, joueur_t j){
	//printf("		APPLY JOUEUR :\n");
	apply_surface(j.sprite,screen,j.x,j.y);
}

void refresh_graphics_objet(SDL_Surface *screen, objet_t o){
	//printf("		APPLY OBJET :\n");
	apply_surface(o.sprite,screen,o.xobj,o.yobj);
}
/////////////////////////


/**
* \brief La fonction rafrachit l'écran en fonction de l'état des données du monde
* \param screen la surface de l'écran de jeu
* \param world les données du monde
*/

void refresh_graphics(SDL_Surface *screen, world_t *world){
	//printf("		APPLY BACK :\n");
	apply_background(world->background,screen);
	refresh_graphics_joueur(screen, world->j);
	refresh_graphics_objet(screen, world->o);
	//printf("		REFRESH SURF :\n");
	refresh_surface(screen);
}







