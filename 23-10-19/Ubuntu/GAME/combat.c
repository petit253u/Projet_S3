#include "../GENERAL/general.h"

void win_or_loose(world_t *world){
	if(world->combat.victoire == true){
		return;	
	}
	//perdu(world);
}

void attaquer(world_t* world,SDL_Surface *ecran){
	int nb_alea = 1;//(rand() % 2) + 1;
	int degat;
	if((world->combat.etape == 1)||(world->combat.etape == 2)){
		printf("		ATTAQUE\n");
		printf("%d\n",nb_alea); 
		switch(nb_alea){
			case 1:
				printf("SNAKE\n");
				degat = boucle_snake(world,ecran); 
			break;
			case 2:
				printf("PONG\n"); 
				//degat = boucle_pong(world); 
			break;
			case 3:
				printf("CASSE-BRIQUE\n"); 
				//degat = boucle_casse_brique(world); 
			break;
		}
	}
	if(world->combat.etape == 3){
		printf("		ACHEVER\n");
	}
	degat = degat+1;
	return;
}

void esquiver(world_t* world, SDL_Surface *ecran){
	int nb_alea = (rand() % 2) + 1;
	int subie;
	printf("%d\n",nb_alea); 
	switch(nb_alea){
		case 1:
			printf("PAC-MAN\n"); 
			//subie = boucle_pac_man(world); 
		break;
		case 2:
			printf("FUIS-LES-LIGNES\n"); 
			//subie = boucle_fuis_les_lignes(world,ecran); 
		break;
		case 3:
			printf("BOITE PRISON\n"); 
			//subie = boucle_boite_prison(world,ecran); 
		break;

	}
	world->combat.pv_restant = world->combat.pv_restant - subie;
	return;
}

void fuir(world_t* world,SDL_Surface *ecran){
	int nb_alea = (rand() % 100);
	if(world->combat.etape == 1){
		printf("		FUITE\n");
		printf("%d\n",nb_alea);
		if(nb_alea <26){
			world->combat.ouvert = false;
		} 
	}
	if(world->combat.etape == 3){
		printf("		EPARGNER\n");
		world->combat.ouvert = false;
	}
	return;
}

void discuter(world_t* world,SDL_Surface *ecran){
	if(world->combat.etape == 1){
		printf("		DISCUSSION\n");
	}
	if(world->combat.etape == 3){
		printf("		TORTURE\n");
	}
	return;
}

//////////////////////////////////////////////////////

void init_graphics_bouton_combat(SDL_Surface *ecran,bouton_combat_t* b){
	printf("		INIT BOUTON\n");
	set_transparence(ecran, b->b1, 255, 0, 255);
	set_transparence(ecran, b->b2, 255, 0, 255);
	set_transparence(ecran, b->b3, 255, 0, 255);
	set_transparence(ecran, b->b4, 255, 0, 255);
	set_transparence(ecran, b->b5, 255, 0, 255);
}
 
void init_graphics_combat(SDL_Surface *ecran, combat_t *combat){
	for(int i =0; i < combat->nb_bouton; i++){
		printf("	BOUCLE INIT BOUTON\n");
		init_graphics_bouton_combat(ecran,&combat->tab_bouton[i]);
	}
	
}

/////////////////////////////////////////////////////

void refresh_graphics_bouton_combat(SDL_Surface *ecran,bouton_combat_t* b,int* temp){
	//printf("			REFRESH\n");
	apply_surface(b->sprite,ecran,*temp,550);
	*temp = *temp + 240;
}


void refresh_graphics_combat(SDL_Surface *ecran, combat_t *combat){
	int temp = 40;
	apply_surface(combat->fond,ecran, 0,0);

	// sprite de 50 sur 200
	for(int i =0; i < combat->nb_bouton; i++){
		//printf("		BOUCLE REFRESH\n");
		refresh_graphics_bouton_combat(ecran,&combat->tab_bouton[i],&temp);
	}
	//printf("		SORTIE\n");
	// sprite de 450 sur 900
	//apply_surface(combat->sprite_ennemi,ecran,50,50);

	refresh_surface(ecran);
}

/////////////////////////////////////////////////////

void update_click_souris_2(combat_t* combat, int x, int y){
	combat->souris.click_x = x;
	combat->souris.click_y = y;
}

void update_pos_souris_2(combat_t* combat, int x, int y){
	combat->souris.x = x;
	combat->souris.y = y;	
}

/////////////////////////////////////////////////////

void handle_event_combat(SDL_Event *event, combat_t *combat){
	int mouseX, mouseY;
	Uint8 *keystates;
	while( SDL_PollEvent( event ) ) {
		//Si l'utilisateur a cliqué sur le X de la fenêtre
		if( event->type == SDL_QUIT ) {
			//On quitte le programme
			combat->gameover = 1;
			combat->victoire = false;
			combat->ouvert = false;
		}
		/* Si l'utilisateur appuie sur
		la touche droite de la souris */
		if( event->type == SDL_MOUSEBUTTONDOWN){
              		SDL_GetMouseState(&mouseX, &mouseY);
			update_click_souris_2(combat, mouseX, mouseY);
		}
		if( event->type == SDL_MOUSEMOTION){
			//printf("BOUGE\n");
			SDL_GetMouseState(&mouseX, &mouseY);
			update_pos_souris_2(combat, mouseX, mouseY);
		}
		keystates = SDL_GetKeyState( NULL );
		if( keystates[ SDLK_h ] ) {
			printf("SNAKE\n");
		}
		if( keystates[ SDLK_j ] ) {
			printf("PONG\n");
		}
		if( keystates[ SDLK_k ] ) {
			printf("CASSE-BRIQUE\n");
		}
		if( keystates[ SDLK_l ] ) {
			printf("PAC-MAN\n");
		}
		if( keystates[ SDLK_m ] ) {
			printf("FUIS LES LIGNES\n");
		}
	}
} 

/////////////////////////////////////////////////////

void quel_action(int i, world_t* world,SDL_Surface *ecran){
	switch(i){
		case 1:
			printf("ATTAQUER\n");
			world->combat.nb_attaque ++;
			attaquer(world,ecran);
		break;
		case 2:
			printf("DISCUTER\n");
			discuter(world,ecran);
		break;
		case 3:
			printf("OBJET\n");
		break;
		case 4:
			printf("FUIR\n");
			fuir(world,ecran);
		break;
	}
	world->combat.tour = 1;
}

/////////////////////////////////////////////////////

void verif_click_bouton_combat(bouton_combat_t *b, souris_t* souris, int i, world_t* world,SDL_Surface *ecran){
	if(b->cliquable == true){
		if((souris->click_x >= b->x) && (souris->click_x <= b->x+b->largeur)){
			if((souris->click_y >= b->y) && (souris->click_y <= b->y+b->hauteur)){
				quel_action(i, world,ecran);
				souris->click_x = -100;
				souris->click_y = -100;
			}
		}
	}
}

void verif_click_combat(combat_t *combat, world_t* world,SDL_Surface *ecran){
	for(int i =0; i<combat->nb_bouton; i++){
		verif_click_bouton_combat(&combat->tab_bouton[i],&combat->souris,i+1,world,ecran);
	}
}

/////////////////////////////////////////////////////

void verif_pos_souris_bouton_combat(bouton_combat_t *b, souris_t* souris, SDL_Surface *image1, SDL_Surface *image2){
	if((souris->x >= b->x) && (souris->x <= b->x+b->largeur)){
		if((souris->y >= b->y) && (souris->y <= b->y+b->hauteur)){
			if(b->cliquable == true){
				b->sprite = image2;
				//printf("...................................TOUCHE\n");
				return;
			}
		}
		b->sprite = image1;
	}
	//printf("LA\n");
	b->sprite = image1;
}

void verif_pos_souris_combat(combat_t *combat){
	for(int i =0; i<combat->nb_bouton; i++){
		switch(combat->etape){
			case 1:
				verif_pos_souris_bouton_combat(&combat->tab_bouton[i],&combat->souris,combat->tab_bouton[i].b1,combat->tab_bouton[i].b2);
				combat->fond = combat->f1;
			break;
			case 2:
				if(i == 0){
					verif_pos_souris_bouton_combat(&combat->tab_bouton[i],&combat->souris,combat->tab_bouton[i].b1,combat->tab_bouton[i].b2);
					break;
				}
				if(i != 2){
					verif_pos_souris_bouton_combat(&combat->tab_bouton[i],&combat->souris,combat->tab_bouton[i].b3,combat->tab_bouton[i].b4);
					break;
				}
				verif_pos_souris_bouton_combat(&combat->tab_bouton[i],&combat->souris,combat->tab_bouton[i].b1,combat->tab_bouton[i].b2);
				combat->fond = combat->f2;
			break;
			case 3:
				if(i == 0){
					verif_pos_souris_bouton_combat(&combat->tab_bouton[i],&combat->souris,combat->tab_bouton[i].b3,combat->tab_bouton[i].b4);
					break;
				}
				if(i != 2){
					verif_pos_souris_bouton_combat(&combat->tab_bouton[i],&combat->souris,combat->tab_bouton[i].b4,combat->tab_bouton[i].b5);
					break;
				}
				verif_pos_souris_bouton_combat(&combat->tab_bouton[i],&combat->souris,combat->tab_bouton[i].b1,combat->tab_bouton[i].b2);
				combat->fond = combat->f3;
			break;
		}
		
	}
}
/////////////////////////////////////////////////////

void verif_nb_attaque(combat_t *combat){
	if(combat->nb_attaque == 2){
		combat->tab_bouton[1].cliquable = false;
		combat->tab_bouton[3].cliquable = false;
		combat->etape = 2;
		return;
	}
	else if (combat->nb_attaque == 5) {
		combat->tab_bouton[1].cliquable = true;
		combat->tab_bouton[3].cliquable = true;
		combat->etape = 3;
		return;
	}
}
/////////////////////////////////////////////////////

void boucle_attaque_joueur(SDL_Event *event2, world_t *world, SDL_Surface *ecran){
	while(world->combat.tour == 2 ){
		//printf("BOUCLE\n");
		//printf("	HANDLE\n");
		handle_event_combat(event2, &world->combat);
		//printf("	VERIF POS SOURIS\n");
		verif_pos_souris_combat(&world->combat);
		//printf("	VERIF CLICK SOURIS\n");
		verif_click_combat(&world->combat, world,ecran);
		//printf("	VERIF NB ATTAQUE\n");
		verif_nb_attaque(&world->combat);
		//printf("	REFRESH\n");
		refresh_graphics_combat(ecran, &world->combat);
	}
}

void boucle_attaque_ennemi(SDL_Event *event2, world_t *world, SDL_Surface *ecran){
	esquiver(world,ecran);
	world->combat.tour = 2;
}
/////////////////////////////////////////////////////

void clear_combat_bouton(bouton_combat_t *b){
	SDL_FreeSurface(b->b1);
	SDL_FreeSurface(b->b2);
	SDL_FreeSurface(b->b3);
	SDL_FreeSurface(b->b4);
	SDL_FreeSurface(b->b5);
	printf("			sprite :\n");
	SDL_FreeSurface(b->sprite);
}

void clear_combat(combat_t* combat){
		printf("	CLEAR COMBAT :\n");
	SDL_FreeSurface(combat->fond);
		printf("	CLEAR COMBAT :\n");
	SDL_FreeSurface(combat->f1);
		printf("	CLEAR COMBAT :\n");
	SDL_FreeSurface(combat->f2);
		printf("	CLEAR COMBAT :\n");
	SDL_FreeSurface(combat->f3);
		printf("	CLEAR COMBAT :\n");
	for( int i = 0; i<4; i++){
		printf("		%d :\n",i);
		clear_combat_bouton(&combat->tab_bouton[i]);
	}
	printf("	sortie:\n");
}

/////////////////////////////////////////////////////

int boucle_combat(world_t *world, SDL_Surface *ecran){
	SDL_Event event2;
	int a = 0;
	printf("	INIT_COMBAT :\n");
	init_data_combat(&world->combat);
	//init_ennemi();
	//printf("PV\n");
	world->combat.pv_restant = world->j.pv;
	//printf("INIT GRAPH\n");
	init_graphics_combat(ecran,&world->combat);
	//printf("CONDITION BOUCLE\n");
	while(world->combat.ouvert == true){
		if(world->combat.tour == 2){
			boucle_attaque_joueur(&event2,world,ecran);
		}
		if(world->combat.tour == 1){
			boucle_attaque_ennemi(&event2,world,ecran);
		}
	}
	win_or_loose(world); // gere la victoire, ou l'interface de perte
	//clear_combat(&world->combat);
	a = world->combat.gameover;
	return a;
}
