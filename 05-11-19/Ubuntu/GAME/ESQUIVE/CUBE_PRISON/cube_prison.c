#include "../../../GENERAL/general.h"

void init_graphics_cube_prison_attaque(attaque_cube_t* a,SDL_Surface *ecran){
	set_transparence(ecran, a->sprite, 255, 0, 255);
}

void init_graphics_cube_prison_joueur(joueur_cube_t* j,SDL_Surface *ecran){
	set_transparence(ecran, j->sprite, 255, 0, 255);
}

void init_graphics_cube_prison(cube_prison_t* cube , SDL_Surface *ecran){
	set_transparence(ecran, cube->arcade, 255, 0, 255);
	for(int i=0; i<cube->paterne.nb_attaque; i++){
		init_graphics_cube_prison_attaque(&cube->paterne.tabattaque[i],ecran);
	}
	init_graphics_cube_prison_joueur(&cube->joueur,ecran);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void refresh_graphics_cube_joueur(joueur_cube_t* j,SDL_Surface *ecran){
	apply_surface(j->sprite,ecran,j->x,j->y);
}

void refresh_graphics_cube_attaque(attaque_cube_t* a,SDL_Surface *ecran){
	apply_surface(a->sprite,ecran,a->x,a->y);
}

void refresh_graphics_cube(cube_prison_t* cube , SDL_Surface *ecran){
	apply_surface(cube->fond_cube,ecran, 75,75);
	for(int i =0; i<cube->paterne.nb_attaque ; i++){
		refresh_graphics_cube_attaque(&cube->paterne.tabattaque[i],ecran);
	}
	refresh_graphics_cube_joueur(&cube->joueur,ecran);
	apply_surface(cube->arcade,ecran, 25,25);
	refresh_surface(ecran);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_pv_joueur_cube(world_t* world,attaque_cube_t* a){
	world->j.pv = world->j.pv - a->degat;
}

void verif_collision_cube_attaque(world_t* world,attaque_cube_t* a,joueur_cube_t* j,temps_t* t){
	if((t->temps_actuel - t->temps_ancien) >= t->ecart_souhait){
		j->sprite = j->s1;
		if((j->x + j->largeur >= a->x) && (j->x <= a->x +a->largeur)){
			if((j->y + j->hauteur >= a->y) && (j->y <= a->y + a->hauteur)){
				t->temps_ancien = SDL_GetTicks();
				t->temps_actuel = SDL_GetTicks();
				j->sprite = j->s2;
				update_pv_joueur_cube(world,a);
			}
		}
	}
}

void verif_pv_joueur_cube(world_t* world){
	if(world->j.pv <= 0){
		world->combat.cube.ouvert = false;
		world->combat.ouvert = false;
		world->gameover = 1;
	}
}

void verif_collision_cube(world_t* world){
	for(int i=0; i<world->combat.cube.paterne.nb_attaque; i++){
		verif_collision_cube_attaque(world,&world->combat.cube.paterne.tabattaque[i],&world->combat.cube.joueur,&world->combat.cube.temps);
	}
	verif_pv_joueur_cube(world);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_data_cube_attaque(attaque_cube_t* a){
	switch(a->dir){
		case 'z':
			a->y = a->y - MOVING_CUBE_ATTAQUE;
			break;
		case 'q':
			a->x = a->x - MOVING_CUBE_ATTAQUE;
			break;
		case 's':
			a->y = a->y + MOVING_CUBE_ATTAQUE;
			break;
		case 'd':
			a->x = a->x + MOVING_CUBE_ATTAQUE;
			break;
	}
}

void update_data_cube_joueur(joueur_cube_t* j, souris_t* s){
	j->x = s->x;
	j->y = s->y;
}

void update_date_cube_temps(temps_t* t){
	t->temps_actuel = SDL_GetTicks();
}

void update_data_cube(cube_prison_t* cube){
	update_data_cube_joueur(&cube->joueur, &cube->souris);
	for(int i=0; i<cube->paterne.nb_attaque; i++){
		update_data_cube_attaque(&cube->paterne.tabattaque[i]);
	}
	update_date_cube_temps(&cube->temps);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_pos_souris_cube(souris_t* souris, int x, int y){
	if((x>=BORDURE_GAUCHE_CUBE)&&(x<=BORDURE_DROITE_CUBE + LARGEUR_SPRITE_JOUEUR_CUBE)){
		souris->x = x;
	}
	if((x>=BORDURE_HAUTE_CUBE)&&(x<=BORDURE_BASSE_CUBE + HAUTEUR_SPRITE_JOUEUR_CUBE)){
		souris->y = y;
	}
}

void handle_event_cube(SDL_Event *event, world_t *world){
	int mouseX, mouseY;
	Uint8 *keystates;
	while( SDL_PollEvent( event ) ) {
		//Si l'utilisateur a cliqué sur le X de la fenêtre
		if( event->type == SDL_QUIT ) {
			//On quitte le programme
			world->combat.gameover = 1;
			world->combat.ouvert = false;
			world->combat.cube.ouvert = false;
			world->gameover = 1;
		}
		if( event->type == SDL_MOUSEMOTION){
			//printf("BOUGE\n");
			SDL_GetMouseState(&mouseX, &mouseY);
			update_pos_souris_cube(&world->combat.cube.souris, mouseX, mouseY);
		}
		keystates = SDL_GetKeyState( NULL );
		if( keystates[ SDLK_p ] ) {
			world->combat.cube.ouvert = false;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void boucle_cube_prison(world_t* world, SDL_Surface *ecran){
	SDL_Event event_cube;
	init_cube_prison(&world->combat.cube);
	init_graphics_cube_prison(&world->combat.cube,ecran);
	while(world->combat.cube.ouvert == true){
		handle_event_cube(&event_cube,world);
		update_data_cube(&world->combat.cube);
		verif_collision_cube(world);
		refresh_graphics_cube(&world->combat.cube,ecran);
	}
}
