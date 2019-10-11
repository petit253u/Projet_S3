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
* \brief Taille du bonhomme Hauteur (sprite)
*/
#define SPRITE_SIZE_HEIGHT 100

/**
* \brief Taille du bonhomme Largeur (sprite)
*/
#define SPRITE_SIZE_WIDTH 50

/**
* \brief Taille du "coffre" Hauteur (sprite)
*/
#define SPRITE_TEST_HEIGHT 32

/**
* \brief Taille du "coffre" Largeur (sprite)
*/
#define SPRITE_TEST_WIDTH 32

/**
* \brief Pas, en pixel, de déplacement du sprite
*/
#define MOVING_STEP 5

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct joueur_s{
	int x;
	int y; 
	int largeur;
	int hauteur;
	int cote; // 1 : haut, 2 : gauche, 3 : bas, 4 : droite
};

typedef struct joueur_s joueur_t;

struct objet_s{
	int xobj;
	int yobj;
	int largeur;
	int hauteur;
};

typedef struct objet_s objet_t;

/**
* \brief Représentation du monde du jeu
*/

struct world_s{
	SDL_Surface* background;
	SDL_Surface* sprite1;
	SDL_Surface* sprite2;
	SDL_Surface* sprite3;
	SDL_Surface* sprite4;
	SDL_Surface* sprite;
	SDL_Surface* sprite_objet;
	joueur_t joueur;
	objet_t objet;
	int gameover;
};

typedef struct world_s world_t;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void init_data_objet(objet_t objet){
	objet.largeur = SPRITE_TEST_WIDTH;
	objet.hauteur = SPRITE_TEST_HEIGHT;
	objet.xobj = 1000;
	objet.yobj = 300;
}

void init_data_joueur(joueur_t joueur){
	joueur.x = SCREEN_WIDTH/2 - SPRITE_SIZE_WIDTH/2;
	joueur.y = SCREEN_HEIGHT/2 - SPRITE_SIZE_HEIGHT/2;
	joueur.largeur = SPRITE_SIZE_WIDTH;
	joueur.hauteur = SPRITE_SIZE_HEIGHT;
	joueur.cote = 1;
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
	world->sprite_objet = load_image( "ressources/sprite.bmp" );
	world->sprite = world->sprite1;
	init_data_joueur(world->joueur);
	init_data_objet(world->objet);
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
	set_transparence(screen, world->sprite_objet, 255, 0, 255);
}


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
	SDL_FreeSurface(world->sprite_objet);
}




/**
* \brief La fonction indique si le jeu est fini en fonction des données du monde
* \param world les données du monde
* \return 1 si le jeu est fini, 0 sinon
*/

int is_game_over(world_t *world){
	return world->gameover;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	apply_surface(world->sprite,screen,world->joueur.x,world->joueur.y);
	apply_surface(world->sprite_objet,screen,world->objet.xobj,world->objet.yobj);
	refresh_surface(screen);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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
		la touche z (constante SDLK_z) */
		if( keystates[ SDLK_z ] ) {
			world->joueur.y = world->joueur.y - MOVING_STEP; 
			world->joueur.cote = 1;
		}
		if( keystates[ SDLK_q ] ) {
			world->joueur.x = world->joueur.x - MOVING_STEP; 
			world->joueur.cote = 2;
		}
		if( keystates[ SDLK_s ] ) {
			world->joueur.y = world->joueur.y + MOVING_STEP; 
			world->joueur.cote = 3;
		}
		if( keystates[ SDLK_d ] ) {
			world->joueur.x = world->joueur.x + MOVING_STEP; 
			world->joueur.cote = 4;
		}
		/*if( keystates[ SDLK_e ] ) {
			//inventaire
		}
		if( keystates[ SDLK_r] ) {
			//ramasser
		}
		if( keystates[ SDLK_ ] ) {
		}
		if( keystates[ SDLK_ ] ) {
		}*/
	}

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
