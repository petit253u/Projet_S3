#include "../../GENERAL/general.h"

void resultat_epargner(combat_t* combat){
	if (combat->epargner.resultat){
		combat->ouvert = false;
	}
}

/////////////////////////////////////////////////////////////////////////////////////

void verif_pos_souris_epargner_carte(carte_valide_t* carte, souris_t* souris){
	if((souris->x >= carte->x)&&(souris->x <= carte->x + carte->largeur)){
		if((souris->y >= carte->y)&&(souris->y <= carte->y + carte->hauteur)){
			carte->sprite = carte->carte_cliquable;
			return;
		}
	}
	carte->sprite = carte->carte_simple;
}

int verif_click_souris_epargner_carte(carte_valide_t* carte, souris_t* souris){
	if((souris->click_x >= carte->x)&&(souris->click_x <= carte->x + carte->largeur)){
		if((souris->click_y >= carte->y)&&(souris->click_y <= carte->y + carte->hauteur)){
			carte->sprite = carte->carte_valide;
			return 1;
		}
	}
	return 0;
}

void verif_souris_epargner(epargner_t* epargner){
	verif_pos_souris_epargner_carte(&epargner->carte, &epargner->souris);
	int a = verif_click_souris_epargner_carte(&epargner->carte, &epargner->souris);
	if(a==1){
		epargner->ouvert = false;
		epargner->resultat = true;
	}
}

/////////////////////////////////////////////////////////////////////////////////////

void update_click_souris_epargner(souris_t* souris, int x, int y){
	souris->click_x = x;
	souris->click_y = y;
}

void update_pos_souris_epargner(souris_t* souris, int x, int y){
	souris->x = x;
	souris->y = y;	
}


/////////////////////////////////////////////////////////////////////////////////////

void init_graphics_carte_epargner(carte_valide_t* c, SDL_Surface *ecran){
	set_transparence(ecran, c->carte_simple, 255, 0, 255);
	set_transparence(ecran, c->carte_cliquable, 255, 0, 255);
	set_transparence(ecran, c->carte_valide, 255, 0, 255);
}

void init_graphics_epargner(SDL_Surface *ecran, epargner_t* epargner){
	init_graphics_carte_epargner(&epargner->carte,ecran);
	set_transparence(ecran, epargner->arcade, 255, 0, 255);
}

/////////////////////////////////////////////////////////////////////////////////////

void refresh_graphics_carte_epargner(carte_valide_t* c,SDL_Surface *ecran){
	apply_surface(c->sprite,ecran,c->x,c->y);
}

void refresh_graphics_epargner(epargner_t* epargner, SDL_Surface *ecran){
	apply_surface(epargner->fond_noir,ecran,75,75); 
	refresh_graphics_carte_epargner(&epargner->carte,ecran);
	apply_surface(epargner->arcade,ecran,25,25);
	refresh_surface(ecran);
}

/////////////////////////////////////////////////////////////////////////////////////

void handle_event_epargner(SDL_Event *event, world_t *world){
	int mouseX, mouseY;
	Uint8 *keystates;
	while( SDL_PollEvent( event ) ) {
		//Si l'utilisateur a cliqué sur le X de la fenêtre
		if( event->type == SDL_QUIT ) {
			//On quitte le programme
			world->combat.gameover = 1;
			world->combat.victoire = false;
			world->combat.ouvert = false;
			world->gameover = 1;
		}
		/* Si l'utilisateur appuie sur
		la touche droite de la souris */
		if( event->type == SDL_MOUSEBUTTONDOWN){
              		SDL_GetMouseState(&mouseX, &mouseY);
			update_click_souris_epargner(&world->combat.epargner.souris, mouseX, mouseY);
		}
		if( event->type == SDL_MOUSEMOTION){
			//printf("BOUGE\n");
			SDL_GetMouseState(&mouseX, &mouseY);
			update_pos_souris_epargner(&world->combat.epargner.souris, mouseX, mouseY);
		}
		keystates = SDL_GetKeyState( NULL );
		if( keystates[ SDLK_p ] ) {
			world->combat.epargner.ouvert = false;
		}
	}
} 

/////////////////////////////////////////////////////////////////////////////////////

void boucle_epargner(world_t* world,SDL_Surface *ecran){
	SDL_Event event_epargner;
	init_epargner(&world->combat.epargner);
	init_graphics_epargner(ecran,&world->combat.epargner);
	printf("CONDITION BOUCLE\n");
	while(world->combat.epargner.ouvert == true){
			handle_event_epargner(&event_epargner,world);
			verif_souris_epargner(&world->combat.epargner);
			refresh_graphics_epargner(&world->combat.epargner,ecran);
	}
	resultat_epargner(&world->combat);
	SDL_Delay(250);
}
