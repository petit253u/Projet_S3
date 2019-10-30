/**
* \file init.c
* \brief Module d'inititialisation
* \author PETIT Brian
* \version 0.1
* \date 
*/

#include "../GENERAL/general.h"

/**
* \brief La fonction initialise les données du joueur
* \param j les données du joueur
*/
void init_data_joueur(joueur_t*  j){
	j->x = 500;
	j->y = 300;
	j->largeur = SPRITE_SIZE_WIDTH;
	j->hauteur = SPRITE_SIZE_HEIGHT;
	j->cote = 1;
	printf("	IMAGE 1 :\n");
	j->sprite1 = SDL_LoadBMP("RESSOURCES/test_sprite_01.bmp");
	printf("	IMAGE 2 :\n");
	j->sprite2 = SDL_LoadBMP("RESSOURCES/test_sprite_02.bmp");
	printf("	IMAGE 3 :\n");
	j->sprite3 = SDL_LoadBMP("RESSOURCES/test_sprite_03.bmp");
	printf("	IMAGE 4 :\n");
	j->sprite4 = SDL_LoadBMP("RESSOURCES/test_sprite_04.bmp");
	printf("	AFFECTATION :\n");
	j->sprite = j->sprite1;
	j->direction = 'z';
	j->pv = 100;
}

/**
* \brief La fonction initialise les données d'un objet
* \param world les données d'un objet
*/
void init_data_objet(objet_t* o,int temp){
	if(temp ==1){
		o->largeur = SPRITE_BOUTON_WIDTH;
		o->hauteur = SPRITE_BOUTON_HEIGHT;
		o->xobj = SCREEN_WIDTH/2 - 300;
		o->yobj = SCREEN_HEIGHT/2 - 300;
	}
	else{
		o->largeur = SPRITE_TEST_WIDTH;
		o->hauteur = SPRITE_TEST_HEIGHT;
		o->xobj = 600;
		o->yobj = 340;
	}
	o->sprite = SDL_LoadBMP("RESSOURCES/sprite.bmp" );
}

/**
* \brief La fonction initialise les données du monde du jeu
* \param world les données du monde
*/
void init_data_souris(souris_t* souris){
	souris->x = -100;
	souris->y = -100;
	souris->click_x = -100;
	souris->click_y = -100;
}


//////////////////////////////////////////////////////////////////////////

/**
* \brief La fonction initialise les données du monde du jeu
* \param world les données du monde
*/
void init_data(world_t * world){

	printf("	BACKGROUND :\n");
	world->background = SDL_LoadBMP("RESSOURCES/salle_test.bmp");

	printf("	INIT_JOUEUR :\n");
	init_data_joueur(&world->j);
	
	printf("	INIT_OBJET :\n");
	init_data_objet(&world->o,0);

	printf("	INIT_MENU :\n");
	init_data_menu(&world->menu);

	world->gameover = 0;
}

/**
* \brief La fonction initialise les transparences des différentes surfaces
* \param screen la surface correspondant à l'écran de jeu
* \param world les données du monde
*/

void  init_graphics(SDL_Surface *screen, world_t *world){
	set_transparence(screen, world->j.sprite1, 255, 0, 255);
	set_transparence(screen, world->j.sprite2, 255, 0, 255);
	set_transparence(screen, world->j.sprite3, 255, 0, 255);
	set_transparence(screen, world->j.sprite4, 255, 0, 255);
	set_transparence(screen, world->o.sprite, 255, 0, 255);
}
