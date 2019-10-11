/**
* \file init.c
* \brief Module d'inititialisation
* \author 
* \version 0.1
* \date 
*/

#include "../GENERAL/general.h"

void init_data_objet(objet_t * objet){
	objet->sprite_objet = load_image( "ressources/sprite.bmp" );
	objet->largeur = SPRITE_TEST_WIDTH;
	objet->hauteur = SPRITE_TEST_HEIGHT;
	objet->xobj = 1000;
	objet->yobj = 300;
}

void init_data_joueur(joueur_t * joueur){
	joueur->sprite1 = load_image( "ressources/test_sprite_01.bmp" );
	joueur->sprite2 = load_image( "ressources/test_sprite_02.bmp" );
	joueur->sprite3 = load_image( "ressources/test_sprite_03.bmp" );
	joueur->sprite4 = load_image( "ressources/test_sprite_04.bmp" );
	joueur->sprite = joueur->sprite1;
	joueur->x = SCREEN_WIDTH/2 - SPRITE_SIZE_WIDTH/2;
	joueur->y = SCREEN_HEIGHT/2 - SPRITE_SIZE_HEIGHT/2;
	joueur->largeur = SPRITE_SIZE_WIDTH;
	joueur->hauteur = SPRITE_SIZE_HEIGHT;
	joueur->cote = 1;
}

/**
* \brief La fonction initialise les données du monde du jeu
* \param world les données du monde
*/
void init_data(world_t * world){
	world->background = load_image( "ressources/test_background.bmp" );
	init_data_joueur(&world->joueur);
	init_data_objet(&world->objet);
}

/**
* \brief La fonction initialise les transparences des différentes surfaces
* \param screen la surface correspondant à l'écran de jeu
* \param world les données du monde
*/

void  init_graphics(SDL_Surface *screen, world_t *world){
	set_transparence(screen, world->joueur.sprite1, 255, 0, 255);
	set_transparence(screen, world->joueur.sprite2, 255, 0, 255);
	set_transparence(screen, world->joueur.sprite3, 255, 0, 255);
	set_transparence(screen, world->joueur.sprite4, 255, 0, 255);
	set_transparence(screen, world->objet.sprite_objet, 255, 0, 255);
}
