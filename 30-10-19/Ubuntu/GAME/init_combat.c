#include "../GENERAL/general.h"

void init_data_bouton_attaquer(bouton_combat_t *b){
	b->b1 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_attaquer.bmp");
	b->b2 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_cliquable_attaquer.bmp");
	b->b3 = SDL_LoadBMP("RESSOURCES/COMBAT/demon_bouton_achever.bmp");
	b->b4 = SDL_LoadBMP("RESSOURCES/COMBAT/demon_bouton_achever_cliquable.bmp");
	//VIDE
	b->b5 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_combat.bmp");
	b->sprite = b->b1;
}

void init_data_bouton_discuter(bouton_combat_t *b){
	b->b1 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_discuter.bmp");
	b->b2 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_cliquable_discuter.bmp");
	b->b3 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_discuter_bloquer.bmp");
	b->b4 = SDL_LoadBMP("RESSOURCES/COMBAT/demon_bouton_torturer.bmp");
	b->b5 = SDL_LoadBMP("RESSOURCES/COMBAT/demon_bouton_torturer_cliquable.bmp");
	b->sprite = b->b1;
}

void init_data_bouton_objet(bouton_combat_t *b){
	b->b1 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_objet.bmp");
	b->b2 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_cliquable_objet.bmp");
	//VIDE
	b->b3 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_combat.bmp");
	b->b4 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_combat.bmp");
	b->b5 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_combat.bmp");
	b->sprite = b->b1;
}

void init_data_bouton_fuir(bouton_combat_t *b){
	b->b1 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_fuir.bmp");
	b->b2 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_cliquable_fuir.bmp");
	b->b3 = SDL_LoadBMP("RESSOURCES/COMBAT/bouton_fuir_bloquer.bmp");
	b->b4 = SDL_LoadBMP("RESSOURCES/COMBAT/demon_bouton_epargner.bmp");
	b->b5 = SDL_LoadBMP("RESSOURCES/COMBAT/demon_bouton_epargner_cliquable.bmp");
	b->sprite = b->b1;
}

//////////////////////////////////////////////// ALL BOUTON ///////////////////////////////////////

void init_data_bouton_combat(bouton_combat_t *b, int* temp, int i){
	printf("BOUTON :\n");
	b->x = *temp;
	b->y = 550;
	*temp = *temp + 240;
	b->largeur = 200;
	b->hauteur = 50;
	b->cliquable = true;
	printf("SWITCH :\n");
	switch(i){
		case 1:
			printf("	IMAGE 1 :\n");
			init_data_bouton_attaquer(b);
		break;
		case 2:
			printf("	IMAGE 2 :\n");
			init_data_bouton_discuter(b);
		break;
		case 3:
			printf("	IMAGE 3 :\n");
			init_data_bouton_objet(b);
		break;
		case 4:
			printf("	IMAGE 4 :\n");
			init_data_bouton_fuir(b);
		break;
	}
}

//////////////////////////////////////////////// ALL ///////////////////////////////////////

void init_data_combat(combat_t *c){
	int temp = 40;
	c->nb_attaque = 0;
	printf("FOND:\n");
	c->f1 = SDL_LoadBMP("RESSOURCES/COMBAT/etape1.bmp");
	c->f2 = SDL_LoadBMP("RESSOURCES/COMBAT/etape2.bmp");
	c->f3 = SDL_LoadBMP("RESSOURCES/COMBAT/etape3.bmp");
	c->fond = c->f1;
	c->nb_bouton = NB_BOUTON_COMBAT;
	c->etape = 1;
	c->tour = 2;
	for(int i = 0; i < c->nb_bouton ; i++){
		printf("%d\n", i);
		init_data_bouton_combat(&c->tab_bouton[i],&temp,i+1);
	}
	c->pv_restant = 100;
	init_data_souris(&c->souris);
	c->ouvert = true;
	c->gameover = 0;
}

