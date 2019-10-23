#include "../../../GENERAL/general.h"

void attaque_reussie(snake_t* snake){
	snake->degat = snake->nb_corps_actuel * 2;
}

void delete_objet_snake(objet_snake_t* o){
	o->x = -100;
	o->y = -100;
}

/////////////////////////////////////////////////////////////////////////////////////

void init_corps_sup_snake(snake_t* snake){
	snake->nb_corps_actuel++;
	snake->tabcorps[snake->nb_corps_actuel].x = snake->tabcorps[snake->nb_corps_actuel - 1].x;
	snake->tabcorps[snake->nb_corps_actuel].y = snake->tabcorps[snake->nb_corps_actuel - 1].y + TAILLE_SPRITE_CUBE;
	snake->tabcorps[snake->nb_corps_actuel].sprite = snake->tabcorps[snake->nb_corps_actuel - 1].sprite;
	snake->tabcorps[snake->nb_corps_actuel].cote = snake->tabcorps[snake->nb_corps_actuel - 1].cote;
}

/////////////////////////////////////////////////////////////////////////////////////

void verif_collision_bordure_snake(snake_t* snake){
	if(snake->tabcorps[0].x < BORDURE_GAUCHE){
		snake->ouvert = false;
	}
	if(snake->tabcorps[0].x > BORDURE_DROITE){
		snake->ouvert = false;
	}
	if(snake->tabcorps[0].y < BORDURE_HAUTE){
		snake->ouvert = false;
	}
	if(snake->tabcorps[0].y < BORDURE_BASSE){
		snake->ouvert = false;
	}
}

void verif_collision_mur_snake(snake_t* snake){
	for(int i=0; i<snake->nb_mur; i++){
		if(snake->tabcorps[0].x == snake->tabmur[i].x){
			if(snake->tabcorps[0].y == snake->tabmur[i].y){
				snake->ouvert = false;
			}
		}
	}
}

void verif_collision_corps_snake(snake_t* snake){
	for(int i=1; i<snake->nb_corps_actuel; i++){
		if(snake->tabcorps[0].x == snake->tabcorps[i].x){
			if(snake->tabcorps[0].y == snake->tabcorps[i].y){
				snake->ouvert = false;
			}
		}
	}
}

void verif_collision_objet_snake(snake_t* snake){
	for(int i=0; i<snake->nb_objet; i++){
		if(snake->tabcorps[0].x == snake->tabobjet[i].x){
			if(snake->tabcorps[0].y == snake->tabobjet[i].y){
				init_corps_sup_snake(snake);
				delete_objet_snake(&snake->tabobjet[i]);
			}
		}
	}
}

void verif_collision_pointfaible_ennemi(snake_t* snake){
	if(snake->ouvert == true ){
		if(snake->tabcorps[0].x == snake->pointfaible.x){
			if(snake->tabcorps[0].y == snake->pointfaible.y){
				attaque_reussie(snake);
			}
		}
	}
}

void verif_collision_snake(snake_t* snake){
	verif_collision_bordure_snake(snake);
	verif_collision_mur_snake(snake);
	verif_collision_corps_snake(snake);
	verif_collision_objet_snake(snake);
	verif_collision_pointfaible_ennemi(snake);
}

/////////////////////////////////////////////////////////////////////////////////////

void update_corps_snake(snake_t* snake){
	for(int i = snake->nb_corps_actuel-1; i>0; i--){
		snake->tabcorps[i].x = snake->tabcorps[i-1].x;
		snake->tabcorps[i].y = snake->tabcorps[i-1].y;
	}
}

void update_tete_snake(snake_t* snake){
	switch(snake->dir){
		case 'z':
			snake->tabcorps[0].y = snake->tabcorps[0].y - MOVING_SNAKE;
			break;
		case 'q':
			snake->tabcorps[0].x = snake->tabcorps[0].x - MOVING_SNAKE;
			break;
		case 's':
			snake->tabcorps[0].y = snake->tabcorps[0].y + MOVING_SNAKE;
			break;
		case 'd':
			snake->tabcorps[0].x = snake->tabcorps[0].x + MOVING_SNAKE;
			break;
	}
}

void update_data_snake(snake_t* snake, int* compteur){
	if(*compteur>10000){
		update_corps_snake(snake);
		update_tete_snake(snake);
		compteur = 0;
	}
}

/////////////////////////////////////////////////////////////////////////////////////

void init_graphics_corps_snake(corps_snake_t* corps, SDL_Surface *ecran){
	printf("		set transparence corps\n");
	set_transparence(ecran, corps->sprite, 255, 0, 255);
}

void init_graphics_objet_snake(objet_snake_t* objet, SDL_Surface *ecran){
	printf("		set transparence objet\n");
	set_transparence(ecran, objet->sprite, 255, 0, 255);
}

void init_graphics_mur_snake(mur_snake_t* mur, SDL_Surface *ecran){
	printf("		set transparence mur\n");
	set_transparence(ecran, mur->sprite, 255, 0, 255);
}

void init_graphics_pointfaible_snake(pointfaible_snake_t* pf, SDL_Surface *ecran){
	printf("		set transparence point faible\n");
	set_transparence(ecran, pf->sprite, 255, 0, 255);
}

void init_graphics_bouton_arcade_snake(bouton_snake_arcade_t* b, SDL_Surface *ecran){
	printf("		set transparence bouton arcade\n");
	set_transparence(ecran, b->sprite, 255, 0, 255);
}

void init_graphics_snake(SDL_Surface *ecran, snake_t* snake){
	//init_graphics_pointfaible_snake(&snake->pointfaible,ecran);
	for(int i=0; i<snake->nb_corps_actuel; i++){
		init_graphics_corps_snake(&snake->tabcorps[i],ecran);
	}
	for(int j=0; j<snake->nb_objet; j++){
		init_graphics_objet_snake(&snake->tabobjet[j],ecran);
	}
	for(int k=0; k<snake->nb_mur; k++){
		init_graphics_mur_snake(&snake->tabmur[k],ecran);
	}
	printf("		set transparence arcade\n");
	set_transparence(ecran, snake->arcade, 255, 0, 255);
	for(int l=0; l<4; l++){
		init_graphics_bouton_arcade_snake(&snake->tabbouton[l],ecran);
	}
}

/////////////////////////////////////////////////////////////////////////////////////

void refresh_graphics_corps_snake(corps_snake_t* corps, SDL_Surface *ecran){
	apply_surface(corps->sprite,ecran,corps->x,corps->y);
}

void refresh_graphics_objet_snake(objet_snake_t* objet, SDL_Surface *ecran){
	apply_surface(objet->sprite,ecran,objet->x,objet->y);
}

void refresh_graphics_mur_snake(mur_snake_t* mur, SDL_Surface *ecran){
	apply_surface(mur->sprite,ecran,mur->x,mur->y);
}

void refresh_graphics_pointfaible_snake(pointfaible_snake_t* pf, SDL_Surface *ecran){
	apply_surface(pf->sprite,ecran,pf->x,pf->y);
}

void refresh_z_graphics_bouton_snake_arcade(bouton_snake_arcade_t* b,SDL_Surface *ecran, int i){
	if(i == 1){
		b->x = 695;
		b->y = 557;
	}
	else{
		b->x = -100;
		b->y = -100;
	}
}

void refresh_q_graphics_bouton_snake_arcade(bouton_snake_arcade_t* b,SDL_Surface *ecran, int i){
	if(i == 2){
		b->x = 357;
		b->y = 527;
	}
	else{
		b->x = -100;
		b->y = -100;
	}
}

void refresh_s_graphics_bouton_snake_arcade(bouton_snake_arcade_t* b,SDL_Surface *ecran, int i){
	if(i == 3){
		b->x = 211;
		b->y = 557;
	}
	else{
		b->x = -100;
		b->y = -100;
	}
}

void refresh_d_graphics_bouton_snake_arcade(bouton_snake_arcade_t* b,SDL_Surface *ecran, int i){
	if(i == 4){
		b->x = 549;
		b->y = 527;
	}
	else{
		b->x = -100;
		b->y = -100;
	}
}

void refresh_graphics_bouton_snake_arcade(bouton_snake_arcade_t* b,SDL_Surface *ecran, int i,char zqsd){
	switch(zqsd){
		case 'z':
			refresh_z_graphics_bouton_snake_arcade(b,ecran,i);
			break;
		case 'q':
			refresh_q_graphics_bouton_snake_arcade(b,ecran,i);
			break;
		case 's':
			refresh_s_graphics_bouton_snake_arcade(b,ecran,i);
			break;
		case 'd':
			refresh_d_graphics_bouton_snake_arcade(b,ecran,i);
			break;
	}
	apply_surface(b->sprite,ecran,b->x,b->y);
}

void refresh_graphics_snake(snake_t* snake, SDL_Surface *ecran){
	apply_surface(snake->herbe,ecran,75,75);
	refresh_graphics_pointfaible_snake(&snake->pointfaible,ecran); 
	//printf("		refresh surface\n");
	for(int i=0; i<snake->nb_corps_actuel; i++){
		refresh_graphics_corps_snake(&snake->tabcorps[i],ecran);
	}
	for(int j=0; j<snake->nb_objet; j++){
		refresh_graphics_objet_snake(&snake->tabobjet[j],ecran);
	}
	for(int k=0; k<snake->nb_mur; k++){
		refresh_graphics_mur_snake(&snake->tabmur[k],ecran);
	}
	apply_surface(snake->arcade,ecran,25,25);
	for(int l=0; l<4; l++){
		refresh_graphics_bouton_snake_arcade(&snake->tabbouton[l],ecran,l+1,snake->dir);
	}
	refresh_surface(ecran);
}

/////////////////////////////////////////////////////////////////////////////////////

void handle_event_snake(SDL_Event *event, world_t *world){
	Uint8 *keystates;
	while( SDL_PollEvent( event ) ) {
		//Si l'utilisateur a cliqué sur le X de la fenêtre
		if( event->type == SDL_QUIT ) {
			//On quitte le programme
			world->combat.snake.ouvert = false;
			world->gameover = 1;
		}
		/* Si l'utilisateur appuie sur
		la touche droite de la souris */
		keystates = SDL_GetKeyState( NULL );
		if( keystates[ SDLK_p ] ) {
			world->combat.snake.ouvert = false;
		}
		if( keystates[ SDLK_z ] ) {
			world->combat.snake.dir = 'z';
		}
		else if( keystates[ SDLK_q ] ) {
			world->combat.snake.dir = 'q';
		}
		else if( keystates[ SDLK_s ] ) {
			world->combat.snake.dir = 's';
		}
		else if( keystates[ SDLK_d ] ) {
			world->combat.snake.dir = 'd';
		}
	}
} 

/////////////////////////////////////////////////////////////////////////////////////

int boucle_snake(world_t* world,SDL_Surface *ecran){
	printf("EVENT\n");
	int compteur = 0;
	SDL_Event event_snake;
	printf("INIT SNAKE\n");
	init_snake(&world->combat.snake);
	printf("INIT GRAPHICS SNAKE\n");
	init_graphics_snake(ecran,&world->combat.snake);
	printf("CONDITION BOUCLE\n");
	while(world->combat.snake.ouvert == true){
			//printf("	BOUCLE\n");
			handle_event_snake(&event_snake,world);
			update_data_snake(&world->combat.snake, &compteur);
			//verif_collision_snake(&world->combat.snake);
			refresh_graphics_snake(&world->combat.snake,ecran);
			compteur++;
	}
	//clean_data_snake(&world->combat.snake);
	return world->combat.snake.degat;
}
