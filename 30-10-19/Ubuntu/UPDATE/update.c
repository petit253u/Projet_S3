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
			j->y = o->yobj - j->hauteur - MOVING_STEP; 
			break;
		case 2: 
			j->x = o->xobj - j->largeur - MOVING_STEP;
			break;
		case 3: 
			j->y = o->yobj + o->hauteur + MOVING_STEP;
			break;
		case 4: 
			j->x = o->xobj + o->largeur + MOVING_STEP;
			break;
	}
}

////////////////////////////////////////////////////////
void quel_replacement(joueur_t* j, objet_t* o){
	int bord = 0;
	switch(j->direction){
		case 'z':
			bord = 3;
		break;
		case 'q':
			bord = 4;
		break;
		case 's':
			bord = 1;
		break;
		case 'd':
			bord = 2;
		break;
	}
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

/*void verif_bord_cam(camera_t *cam){
	//Garde la camera sur les bords du level pour eviter de voir trop loin
	if( cam->x < 0 )
	{
		cam->x = 0;
	}
	if( cam->y < 0 )
	{
		cam->y = 0;
	}
	if( cam->x > LEVEL_WIDTH - cam->largeur )
	{
		cam->x = LEVEL_WIDTH - cam->largeur;
	}
	if( cam->y > LEVEL_HEIGHT - cam->hauteur )
	{
		cam->y = LEVEL_HEIGHT - cam->hauteur;
	}
}

void update_pos_cam(camera_t *cam, joueur_t j){
	//cam->x = (j.x + j.largeur/ 2) - SCREEN_WIDTH / 2;
	//cam->y = (j.y + j.hauteur/ 2) - SCREEN_HEIGHT / 2;
}

void update_camera(world_t *world){
	//update_pos_cam(&world->cam, world->j);
	//verif_bord_cam(&world->cam);
}*/

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







