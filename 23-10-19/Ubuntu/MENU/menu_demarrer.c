#include "../GENERAL/general.h"


void update_click_souris(menu_entree_t *debut, int x, int y){
	debut->souris.click_x = x;
	debut->souris.click_y = y;
	printf("x CLICK NORMAL : %d x OBTENUE : %d \n", x, debut->souris.click_x );
	printf("y CLICK NORMAL : %d y OBTENUE : %d \n", y, debut->souris.click_y );
}

void update_pos_souris(menu_entree_t *debut, int x, int y){
	debut->souris.x = x;
	debut->souris.y = y;
	printf("x NORMAL : %d x OBTENUE : %d \n", x, debut->souris.x );
	printf("y NORMAL : %d y OBTENUE : %d \n", y, debut->souris.y );
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
		if( event->type == SDL_MOUSEBUTTONDOWN){
              		SDL_GetMouseState(&mouseX, &mouseY);
			update_click_souris(debut, mouseX, mouseY);
		}
		if( event->type == SDL_MOUSEMOTION){
			//printf("BOUGE\n");
			SDL_GetMouseState(&mouseX, &mouseY);
			update_pos_souris(debut, mouseX, mouseY);
		}
	}
}

void verif_click(menu_entree_t *debut){
	if((debut->souris.click_x >= SCREEN_WIDTH/2 - 300) && (debut->souris.click_x <= SCREEN_WIDTH/2 +300)){
		if((debut->souris.click_y >= SCREEN_HEIGHT/2 - 75) && (debut->souris.click_y <= SCREEN_HEIGHT/2 + 75)){
			debut->fermer=1;
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
	if((debut->souris.x >= SCREEN_WIDTH/2 - 300) && (debut->souris.x <= SCREEN_WIDTH/2 +300)){
		if((debut->souris.y >= SCREEN_HEIGHT/2 - 75) && (debut->souris.y <= SCREEN_HEIGHT/2 + 75)){
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

	apply_surface(debut->bouton,ecran_debut, SCREEN_WIDTH/2 - 300, SCREEN_HEIGHT/2 - 300);

	refresh_surface(ecran_debut);
}

