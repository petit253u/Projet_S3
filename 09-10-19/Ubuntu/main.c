/**
* \file main.c
* \brief Programme principal du niveau 0, à compléter
* \author Mathieu Constant
* \version 0.1
* \date 13 mars 2019
*/

#include "sdl-light.h"

/**
* \brief Largeur de l'écran de jeu
*/
#define SCREEN_WIDTH 1280

/**
* \brief Hauteur de l'écran de jeu
*/
#define SCREEN_HEIGHT 720

/**
* \brief Taille d'une bulle
*/
#define BUB_SIZE 40

/**
* \brief Taille du bonhomme (sprite)
*/
#define SPRITE_SIZE_HEIGHT 170

/**
* \brief Taille du bonhomme (sprite)
*/
#define SPRITE_SIZE_WIDTH 68

#define SPRITE_TEST_HEIGHT 32

#define SPRITE_TEST_WIDTH 32

/**
* \brief Pas de déplacement du sprite
*/

#define MOVING_STEP 10




/**
* \brief Représentation du monde du jeu
*/

struct world_s{
	SDL_Surface* background;
	SDL_Surface* sprite;
	SDL_Surface* objet;
	int xobj;
	int yobj;
	int gameover;
	int x;
	int y; 
	int cote; // 1 : haut, 2 : gauche, 3 : bas, 4 : droite
	
};

typedef struct world_s world_t;



/**
* \brief La fonction initialise les données du monde du jeu
* \param world les données du monde
*/


void init_data(world_t * world){
	world->background = load_image( "ressources/test_background.bmp" );
	world->sprite = load_image( "ressources/test_sprite_01.bmp" );
	world->objet = load_image( "ressources/sprite.bmp" );
	world->gameover = 0;
	world->x = SCREEN_WIDTH/2 - SPRITE_SIZE_WIDTH/2;
	world->y = SCREEN_HEIGHT/2 - SPRITE_SIZE_HEIGHT/2;
	world->xobj = 1000;
	world->yobj = 300;
	world->cote = 1;
	
}


/**
* \brief La fonction nettoie les données du monde
* \param world les données du monde
*/


void clean_data(world_t *world){
	SDL_FreeSurface(world->background);
	SDL_FreeSurface(world->sprite);
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

void replacement(world_t* world, int bord){
	switch(bord){
		case 1: 
			world->y = world->yobj - SPRITE_SIZE_HEIGHT ; 
			break;
		case 2: 
			world->x = world->xobj - SPRITE_SIZE_WIDTH ;
			break;
		case 3: 
			world->y = world->yobj + SPRITE_TEST_HEIGHT ;
			break;
		case 4: 
			world->x = world->xobj + SPRITE_TEST_WIDTH ;
			break;
		default: 
			printf("ERREUR!!");
			break;
	}
}

void quel_replacement(world_t* world){
	
	int bord = 0;
	/*if((world->y + SPRITE_SIZE_HEIGHT >= world->yobj) && (world->y + SPRITE_SIZE_HEIGHT < world->yobj + SPRITE_TEST_HEIGHT)){
		bord = 1 ;
	}
	else if((world->y + SPRITE_SIZE_HEIGHT >= world->yobj) && (world->y + SPRITE_SIZE_HEIGHT < world->yobj)){
		bord = 2 ;
	}*/






/*if ((world->y + SPRITE_SIZE_HEIGHT >= world->yobj) && (world->x < world->xobj)){
		bord = 1;
	}
	else if ((world->x + SPRITE_SIZE_WIDTH >= world->xobj) && (world->y < world->yobj)){
		bord = 2;
	}*/

	/*if (world->y + SPRITE_SIZE_HEIGHT >= world->yobj){
		if {
			bord = 2;
		}
		else {
			if (world->x <= world->xobj + SPRITE_TEST_WIDTH){
				bord = 4;
			}
			else {
				bord = 1;
			} 
		}
	} 		
	else if (world->y <= world->yobj + SPRITE_TEST_HEIGHT){
		bord = 3;
	}*/
	replacement(world, bord);
}

void update_sprite_joueur(world_t *world){
	switch(world->cote){
		case 1 :
			world->sprite = load_image( "ressources/test_sprite_01.bmp" );
			break;
		case 2 :
			world->sprite = load_image( "ressources/test_sprite_02.bmp" );
			break;
		case 3 :
			world->sprite = load_image( "ressources/test_sprite_03.bmp" );
			break;
		case 4 :
			world->sprite = load_image( "ressources/test_sprite_04.bmp" );
			break;
	}
}

void update_collision_bords(world_t *world){
	// BORD HAUT
	if(world->y <= 0){
		world->y = 0;
	} 
	// BORD GAUCHE
	if(world->x <= 0){
		world->x = 0;
	} 
	// BORD BAS
	if(world->y + SPRITE_SIZE_HEIGHT >= SCREEN_HEIGHT){
		world->y = SCREEN_HEIGHT - SPRITE_SIZE_HEIGHT;
	} 
	// BORD DROIT
	if(world->x + SPRITE_SIZE_WIDTH >= SCREEN_WIDTH){
		world->x = SCREEN_WIDTH - SPRITE_SIZE_WIDTH;
	} 
}

void update_collision_obj(world_t *world){
	if((world->x + SPRITE_SIZE_WIDTH >= world->xobj) && (world->x <= world->xobj + SPRITE_TEST_WIDTH)){
		if((world->y + SPRITE_SIZE_HEIGHT >= world->yobj) && (world->y <= world->yobj + SPRITE_TEST_HEIGHT)){
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
* \brief La fonction initialise les transparences des différentes surfaces
* \param screen la surface correspondant à l'écran de jeu
* \param world les données du monde
*/

void  init_graphics(SDL_Surface *screen, world_t *world){
	set_transparence(screen, world->sprite, 141, 212, 254);
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
	apply_surface(world->sprite,screen,world->x,world->y);
	apply_surface(world->objet,screen,world->xobj,world->yobj);

	refresh_surface(screen);
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
			world->y = world->y - MOVING_STEP; 
			world->cote = 1;
		}
		if( keystates[ SDLK_q ] ) {
			world->x = world->x - MOVING_STEP; 
			world->cote = 2;
		}
		if( keystates[ SDLK_s ] ) {
			world->y = world->y + MOVING_STEP; 
			world->cote = 3;
		}
		if( keystates[ SDLK_d ] ) {
			world->x = world->x + MOVING_STEP; 
			world->cote = 4;
		}

	}

}

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
