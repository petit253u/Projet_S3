#include "../GENERAL/general.h"


void update_click_souris_1(menu_t *debut, int x, int y){
	debut->souris.click_x = x;
	debut->souris.click_y = y;
}

void update_pos_souris_1(menu_t *debut, int x, int y){
	debut->souris.x = x;
	debut->souris.y = y;	
}


void handle_event_menu(SDL_Event *event, menu_t *menu, int *b){
	int mouseX, mouseY;
	Uint8 *keystates;
	while( SDL_PollEvent( event ) ) {
		//Si l'utilisateur a cliqué sur le X de la fenêtre
		if( event->type == SDL_QUIT ) {
			//On quitte le programme
			menu->gameover = 1;
			menu->ouvert = false;
		}
		/* Si l'utilisateur appuie sur
		la touche droite de la souris */
		if( event->type == SDL_MOUSEBUTTONDOWN){
              		SDL_GetMouseState(&mouseX, &mouseY);
			update_click_souris_1(menu, mouseX, mouseY);
		}
		if( event->type == SDL_MOUSEMOTION){
			//printf("BOUGE\n");
			SDL_GetMouseState(&mouseX, &mouseY);
			update_pos_souris_1(menu, mouseX, mouseY);
		}
		keystates = SDL_GetKeyState( NULL );

		if( keystates[ SDLK_ESCAPE ] ) {
			if(*b >= 45){
				*b=0;
				menu->ouvert = false;
			}
		}
	}
} 

void  init_graphics_menu(SDL_Surface *ecran_menu, menu_t *menu){
	set_transparence(ecran_menu, menu->bouton1, 255, 0, 255);
	set_transparence(ecran_menu, menu->bouton2, 255, 0, 255);
}

void refresh_graphics_debut_1(SDL_Surface *ecran_menu, menu_t *menu){
	apply_surface(menu->fond,ecran_menu, 0,0);
	apply_surface(menu->bouton,ecran_menu, SCREEN_WIDTH/2 - 300, SCREEN_HEIGHT/2 - 300);

	refresh_surface(ecran_menu);
}

void refresh_bouton_1(menu_t *debut){
	switch(debut->lequel){
		case 1:
			debut->bouton = debut->bouton1;
			break;
		case 2:
			debut->bouton = debut->bouton2;
			break;
	}	
}

void verif_pos_1(menu_t *debut){
	if((debut->souris.x >= SCREEN_WIDTH/2 - 300) && (debut->souris.x <= SCREEN_WIDTH/2 +300)){
		if((debut->souris.y >= SCREEN_HEIGHT/2 - 75) && (debut->souris.y <= SCREEN_HEIGHT/2 + 75)){
			debut->lequel = 2; 
		}
		else{
			debut->lequel = 1;
		}
	}
	else{
		debut->lequel = 1; 
	}
	refresh_bouton_1(debut);
}

void verif_click_1(menu_t *debut){
	if((debut->souris.click_x >= SCREEN_WIDTH/2 - 300) && (debut->souris.click_x <= SCREEN_WIDTH/2 +300)){
		if((debut->souris.click_y >= SCREEN_HEIGHT/2 - 75) && (debut->souris.click_y <= SCREEN_HEIGHT/2 + 75)){
			debut->ouvert=false;
			debut->gameover=1;
		}
	}
}


int boucle_menu(world_t *world,SDL_Surface *ecran_menu){
	SDL_Event event1;
	int a = 0;
	int b = 0;
	world->menu.ouvert = true;
	init_graphics_menu(ecran_menu,&world->menu);	
	while(world->menu.ouvert == true){
		handle_event_menu(&event1, &world->menu,&b);
		verif_pos_1(&world->menu);
		refresh_graphics_debut_1(ecran_menu,&world->menu);
		verif_click_1(&world->menu);
		b++;
	}
	a = world->menu.gameover;
	return a;
}
