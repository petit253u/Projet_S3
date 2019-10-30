#include "../../../GENERAL/general.h"


/////////////////////////////////////// LEVEL 1 ///////////////////////////////////////////////

void init_mur_snake_level_1(mur_snake_t* mur){
	mur->x = 500;
	mur->y = 200;
	mur->cote = TAILLE_SPRITE_CUBE;
	int random = (rand() % 2);
	if(random == 0){
		mur->sprite = load_image("RESSOURCES/SNAKE/mur_mousse_snake.bmp");
		return;
	}
	mur->sprite = load_image("RESSOURCES/SNAKE/mur_snake.bmp");
}

void init_pointfaible_snake_level_1(pointfaible_snake_t* pf){
	pf->x = 700;
	pf->y = 200;
	pf->cote = TAILLE_SPRITE_CUBE;
	pf->sprite = load_image("RESSOURCES/SNAKE/pointfaible_snake.bmp");
}

void init_corps_snake_level_1(corps_snake_t* c, int* x1, int y1){
	c->x = *x1;
	c->y = y1;
	c->cote = TAILLE_SPRITE_CUBE;
	c->sprite = load_image("RESSOURCES/SNAKE/corps_snake.bmp");
	x1 += TAILLE_SPRITE_CUBE;
}

void init_tete_snake_level_1(corps_snake_t* c, int* x1, int y1){
	c->x = *x1;
	c->y = y1;
	c->cote = TAILLE_SPRITE_CUBE;
	c->sprite = load_image("RESSOURCES/SNAKE/tete_snake.bmp");
	x1 += TAILLE_SPRITE_CUBE;
}

void init_objet_snake_level_1(objet_snake_t* o){
	o->x = 500;
	o->y = 400;
	o->cote = TAILLE_SPRITE_CUBE;
	o->sprite = load_image("RESSOURCES/SNAKE/piece_snake.bmp");
}

void init_level_1_snake(snake_t* snake){
	int x1 = BORDURE_GAUCHE + 50 ;
	int y1 = BORDURE_HAUTE + 100 ;
	snake->nb_objet = 1;
	for(int i=0; i<snake->nb_objet; i++){
		init_objet_snake_level_1(&snake->tabobjet[i]);
	}
	snake->nb_corps_actuel = 3;
	for(int j=snake->nb_corps_actuel-1; j>0; j--){
		init_corps_snake_level_1(&snake->tabcorps[j],&x1, y1);
	}
	init_tete_snake_level_1(&snake->tabcorps[0],&x1, y1);
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
			b->sprite = load_image("RESSOURCES/ARCADE/boutonrouge.bmp");
			break;
		case 2:
			b->x = 357;
			b->y = 527;
			b->sprite = load_image("RESSOURCES/ARCADE/boutonbleu.bmp");
			break;
		case 3:
			b->x = 211;
			b->y = 557;
			b->sprite = load_image("RESSOURCES/ARCADE/boutonjaune.bmp");
			break;
		case 4:
			b->x = 549;
			b->y = 527;
			b->sprite = load_image("RESSOURCES/ARCADE/boutonvert.bmp");
			break;
	}
}

void init_timer_snake(temps_t* t){
	t->temps_ancien = SDL_GetTicks();
	t->temps_actuel = SDL_GetTicks();
	t->ecart_souhait = ECART_TEMPS_SNAKE_MOUVEMENT;
}

void init_snake(snake_t* snake){
	snake->arcade = load_image("RESSOURCES/ARCADE/arcade.bmp");
	snake->herbe = load_image("RESSOURCES/SNAKE/FONDHERBE.bmp");
	for(int i=0; i<4; i++){
		init_bouton_arcade_snake(&snake->tabbouton[i],i+1);
	}
	init_timer_snake(&snake->temps);
	snake->ouvert = true;
	snake->bouge = false;
	snake->dir = 'd';
	int level = 1;//(rand() % 4) + 1;
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

