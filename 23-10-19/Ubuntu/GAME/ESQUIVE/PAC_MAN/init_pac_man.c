#include "../../../GENERAL/general.h"


/////////////////////////////////////// LEVEL 1 ///////////////////////////////////////////////

void init_mur_snake_level_1(mur_snake_t* mur){
	mur->x = 500;
	mur->y = 400;
	mur->cote = TAILLE_SPRITE_CUBE;
	mur->sprite = SDL_LoadBMP("ressources/sprite.bmp");
}

void init_pointfaible_snake_level_1(pointfaible_snake_t* pf){
	pf->x = 700;
	pf->y = 200;
	pf->cote = TAILLE_SPRITE_CUBE;
	pf->sprite = SDL_LoadBMP("ressources/sprite.bmp");
}

void init_corps_snake_level_1(corps_snake_t* c, int* x1, int y1){
	c->x = *x1;
	c->y = y1;
	c->cote = TAILLE_SPRITE_CUBE;
	c->sprite = SDL_LoadBMP("ressources/sprite.bmp");
	x1 += TAILLE_SPRITE_CUBE;
}

void init_objet_snake_level_1(objet_snake_t* o){
	o->x = 500;
	o->y = 200;
	o->cote = TAILLE_SPRITE_CUBE;
	o->sprite = SDL_LoadBMP("ressources/sprite.bmp");
}

void init_level_1_snake(snake_t* snake){
	int x1 = 82;
	int y1 = 82 + BORDURE_GAUCHE/2 - TAILLE_SPRITE_CUBE/2;
	snake->nb_objet = 1;
	for(int i=0; i<snake->nb_objet; i++){
		init_objet_snake_level_1(&snake->tabobjet[i]);
	}
	snake->nb_corps_actuel = 3;
	for(int j=0; j<snake->nb_corps_actuel; j++){
		init_corps_snake_level_1(&snake->tabcorps[j],&x1, y1);
	}
	snake->nb_mur = 1;
	for(int k=0; k<snake->nb_mur; k++){
		init_mur_snake_level_1(&snake->tabmur[k]);
	}
	init_pointfaible_snake_level_1(&snake->pointfaible);
}

/////////////////////////////////////// ALL ///////////////////////////////////////////////

void init_snake(snake_t* snake){
	snake->arcade = load_image("ressources/arcade.bmp");
	/*while(snake->arcade == NULL){
		printf("ECHEC");
	}*/
	snake->herbe = SDL_LoadBMP("ressources/FONDHERBE.bmp");
	snake->ouvert = true;
	snake->dir = 'd';
	int level = (rand() % 4) + 1;
	switch(level){
		case 1 :
			init_level_1_snake(snake); 
			break;
		case 2 :
			//init_level_2_snake(snake); 
			break;
		case 3 :
			//init_level_3_snake(snake); 
			break;
		case 4 :
			//init_level_4_snake(snake); 
			break;
	}
}

