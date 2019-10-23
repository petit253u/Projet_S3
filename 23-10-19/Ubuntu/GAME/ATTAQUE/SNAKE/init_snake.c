#include "../../../GENERAL/general.h"


/////////////////////////////////////// LEVEL 1 ///////////////////////////////////////////////

void init_mur_snake_level_1(mur_snake_t* mur){
	mur->x = 500;
	mur->y = 200;
	mur->cote = TAILLE_SPRITE_CUBE;
	mur->sprite = load_image("ressources/sprite.bmp");
}

void init_pointfaible_snake_level_1(pointfaible_snake_t* pf){
	pf->x = 700;
	pf->y = 200;
	pf->cote = TAILLE_SPRITE_CUBE;
	pf->sprite = load_image("ressources/sprite.bmp");
}

void init_corps_snake_level_1(corps_snake_t* c, int* x1, int y1){
	c->x = *x1;
	c->y = y1;
	c->cote = TAILLE_SPRITE_CUBE;
	c->sprite = load_image("ressources/sprite.bmp");
	x1 += TAILLE_SPRITE_CUBE;
}

void init_objet_snake_level_1(objet_snake_t* o){
	o->x = 500;
	o->y = 400;
	o->cote = TAILLE_SPRITE_CUBE;
	o->sprite = load_image("ressources/sprite.bmp");
}

void init_level_1_snake(snake_t* snake){
	int x1 = BORDURE_GAUCHE;
	int y1 = 82 + BORDURE_GAUCHE/2 - TAILLE_SPRITE_CUBE/2;
	snake->nb_objet = 1;
	for(int i=0; i<snake->nb_objet; i++){
		init_objet_snake_level_1(&snake->tabobjet[i]);
	}
	snake->nb_corps_actuel = 3;
	for(int j=snake->nb_corps_actuel-1; j>=0; j--){
		init_corps_snake_level_1(&snake->tabcorps[j],&x1, y1);
	}
	snake->nb_mur = 1;
	for(int k=0; k<snake->nb_mur; k++){
		init_mur_snake_level_1(&snake->tabmur[k]);
	}
	init_pointfaible_snake_level_1(&snake->pointfaible);
}

/////////////////////////////////////// ALL ///////////////////////////////////////////////

void init_bouton_arcade_snake(bouton_snake_arcade_t* b,int i){
	switch(i){
		case 1:
			b->x = 695;
			b->y = 557;
			b->sprite = load_image("ressources/boutonrouge.bmp");
			break;
		case 2:
			b->x = 357;
			b->y = 527;
			b->sprite = load_image("ressources/boutonbleu.bmp");
			break;
		case 3:
			b->x = 211;
			b->y = 557;
			b->sprite = load_image("ressources/boutonjaune.bmp");
			break;
		case 4:
			b->x = 549;
			b->y = 527;
			b->sprite = load_image("ressources/boutonvert.bmp");
			break;
	}
}

void init_snake(snake_t* snake){
	snake->arcade = load_image("ressources/arcade.bmp");
	snake->herbe = load_image("ressources/FONDHERBE.bmp");
	for(int i=0; i<4; i++){
		init_bouton_arcade_snake(&snake->tabbouton[i],i+1);
	}
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

