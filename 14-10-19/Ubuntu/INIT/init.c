/**
* \file init.c
* \brief Module d'inititialisation
* \author 
* \version 0.1
* \date 
*/

#include "../GENERAL/general.h"

/**
* \brief La fonction initialise les données du joueur
* \param j les données du joueur
*/
void init_data_joueur(joueur_t  j){
	j.x = SCREEN_WIDTH/2 - SPRITE_SIZE_WIDTH/2;
	j.y = SCREEN_HEIGHT/2 - SPRITE_SIZE_HEIGHT/2;
	j.largeur = SPRITE_SIZE_WIDTH;
	j.hauteur = SPRITE_SIZE_HEIGHT;
	j.cote = 1;
}

/**
* \brief La fonction initialise les données d'un objet
* \param world les données d'un objet
*/
void init_data_objet(objet_t o){
	o.largeur = SPRITE_TEST_WIDTH;
	o.hauteur = SPRITE_TEST_HEIGHT;
	o.xobj = 1000;
	o.yobj = 300;
}

/**
* \brief La fonction initialise les données du monde du jeu
* \param world les données du monde
*/
void init_data_souris(souris_t souris){
	souris.x = -100;
	souris.y = -100;
}

/**
* \brief La fonction initialise les données du monde du jeu
* \param world les données du monde
*/
void init_data(world_t * world){

	world->background = load_image( "ressources/test_background.bmp" );
	world->sprite1 = load_image( "ressources/test_sprite_01.bmp" );
	world->sprite2 = load_image( "ressources/test_sprite_02.bmp" );
	world->sprite3 = load_image( "ressources/test_sprite_03.bmp" );
	world->sprite4 = load_image( "ressources/test_sprite_04.bmp" );
	world->sprite = world->sprite1;

	init_data_joueur(world->j);

	world->objet = load_image( "ressources/sprite.bmp" );
	
	init_data_objet(world->o);

	world->gameover = 0;
}

/**
* \brief La fonction initialise les données du joueur
* \param j les données du joueur
*/
void init_data_debut(menu_entree_t* debut){
	debut->fermer = 0;
	debut->background = load_image( "ressources/test_background.bmp" );
	debut->bouton1 = load_image( "ressources/sprite.bmp" );
	debut->bouton2 = load_image( "ressources/test_sprite_01.bmp" );
	debut->bouton = debut->bouton1;
	debut->lequel = 1;
	debut->gameover = 0;
	init_data_objet(debut->o);
	init_data_souris(debut->souris);
}

/**
* \brief La fonction initialise les transparences des différentes surfaces
* \param screen la surface correspondant à l'écran de jeu
* \param world les données du monde
*/

void  init_graphics(SDL_Surface *screen, world_t *world){
	set_transparence(screen, world->sprite1, 255, 0, 255);
	set_transparence(screen, world->sprite2, 255, 0, 255);
	set_transparence(screen, world->sprite3, 255, 0, 255);
	set_transparence(screen, world->sprite4, 255, 0, 255);
	set_transparence(screen, world->objet, 255, 0, 255);
}
