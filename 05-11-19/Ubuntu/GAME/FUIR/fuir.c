#include "../../GENERAL/general.h"

void resultat_fuir(combat_t* combat){
	if (combat->fuir.resultat){
		combat->ouvert = false;
	}
}

/////////////////////////////////////////////////////////////////////////////////////

void verif_pos_souris_fuir_carte(carte_fuir_t* carte, souris_t* souris){
	if((souris->x >= carte->x)&&(souris->x <= carte->x + carte->largeur)){
		if((souris->y >= carte->y)&&(souris->y <= carte->y + carte->hauteur)){
			carte->sprite = carte->carte_cliquable;
			return;
		}
	}
	carte->sprite = carte->carte_simple;
}

void verif_pos_souris_fuir(fuir_t* fuir){
	for(int i = 0; i<fuir->nb_carte; i++){
		verif_pos_souris_fuir_carte(&fuir->tabcarte[i], &fuir->souris);
	}
}

int verif_click_souris_fuir_carte(carte_fuir_t* carte, souris_t* souris){
	if((souris->click_x >= carte->x)&&(souris->click_x <= carte->x + carte->largeur)){
		if((souris->click_y >= carte->y)&&(souris->click_y <= carte->y + carte->hauteur)){
			carte->sprite = carte->carte_retourne;
			if(carte->bonne){
				return 2;// carte cliquée verte
			}
			return 1;// carte cliquée rouge
		}
	}
	return 0;// carte non cliquée
}

void verif_click_souris_fuir(fuir_t* fuir){
	int res;
	for(int i = 0; i<fuir->nb_carte; i++){
		res = verif_click_souris_fuir_carte(&fuir->tabcarte[i], &fuir->souris);
		if (res == 1){ // carte cliquée rouge
			fuir->ouvert = false;
			fuir->resultat = false;
			return;
		}
		if (res == 2){ // carte cliquée verte
			fuir->ouvert = false;
			fuir->resultat = true;
			return;
		}
	}
}

void verif_souris_fuir(fuir_t* fuir){
	verif_pos_souris_fuir(fuir);
	verif_click_souris_fuir(fuir);
}

/////////////////////////////////////////////////////////////////////////////////////

void update_click_souris_fuir(souris_t* souris, int x, int y){
	souris->click_x = x;
	souris->click_y = y;
}

void update_pos_souris_fuir(souris_t* souris, int x, int y){
	souris->x = x;
	souris->y = y;	
}


/////////////////////////////////////////////////////////////////////////////////////

void init_graphics_carte_fuir(carte_fuir_t* c, SDL_Surface *ecran){
	set_transparence(ecran, c->carte_simple, 255, 0, 255);
	set_transparence(ecran, c->carte_cliquable, 255, 0, 255);
	set_transparence(ecran, c->carte_retourne, 255, 0, 255);
}

void init_graphics_fuir(SDL_Surface *ecran, fuir_t* fuir){
	for(int i=0; i<fuir->nb_carte; i++){
		init_graphics_carte_fuir(&fuir->tabcarte[i],ecran);
	}
	set_transparence(ecran, fuir->arcade, 255, 0, 255);
}

/////////////////////////////////////////////////////////////////////////////////////

void refresh_graphics_carte_fuir(carte_fuir_t* c,SDL_Surface *ecran){
	apply_surface(c->sprite,ecran,c->x,c->y);
}

void refresh_graphics_fuir(fuir_t* fuir, SDL_Surface *ecran){
	apply_surface(fuir->fond_noir,ecran,75,75); 
	for(int i=0; i<fuir->nb_carte; i++){
		refresh_graphics_carte_fuir(&fuir->tabcarte[i],ecran);
	}
	apply_surface(fuir->arcade,ecran,25,25);
	refresh_surface(ecran);
}

/////////////////////////////////////////////////////////////////////////////////////

void handle_event_fuir(SDL_Event *event, world_t *world){
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
			update_click_souris_fuir(&world->combat.fuir.souris, mouseX, mouseY);
		}
		if( event->type == SDL_MOUSEMOTION){
			//printf("BOUGE\n");
			SDL_GetMouseState(&mouseX, &mouseY);
			update_pos_souris_fuir(&world->combat.fuir.souris, mouseX, mouseY);
		}
		keystates = SDL_GetKeyState( NULL );
		if( keystates[ SDLK_p ] ) {
			world->combat.fuir.ouvert = false;
		}
	}
} 

/////////////////////////////////////////////////////////////////////////////////////

void boucle_fuir(world_t* world,SDL_Surface *ecran){
	SDL_Event event_fuir;
	printf("INIT fuir\n");
	init_fuir(&world->combat.fuir);
	printf("INIT GRAPHICS SNAKE\n");
	init_graphics_fuir(ecran,&world->combat.fuir);
	printf("CONDITION BOUCLE\n");
	while(world->combat.fuir.ouvert == true){
			handle_event_fuir(&event_fuir,world);
			verif_souris_fuir(&world->combat.fuir);
			refresh_graphics_fuir(&world->combat.fuir,ecran);
	}
	resultat_fuir(&world->combat);
	SDL_Delay(350);
}
