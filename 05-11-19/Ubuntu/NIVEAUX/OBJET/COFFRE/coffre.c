#include "../../../GENERAL/general.h"

void init_graphics_coffre(coffre_t* c, SDL_Surface *ecran){
	set_transparence(ecran, c->c1, 255, 0, 255);
	set_transparence(ecran, c->c2, 255, 0, 255);
	set_transparence(ecran, c->c3, 255, 0, 255);
	set_transparence(ecran, c->c4, 255, 0, 255);
}

void refresh_graphics_coffre(coffre_t* c, SDL_Surface *ecran){
	apply_surface(c->sprite,ecran,c->x,c->y); 
}

//////////////////////////////////////////////////////////////

void coffre_reussi(coffre_t* c, world_t* world){
	c->sprite = c->c4;
}

void coffre_echec(coffre_t* c, world_t* world){
	world->j.pv = world->j.pv - 10;
	c->sprite = c->c3;
}

void serrure_coffre(coffre_t* c, world_t* world, SDL_Surface *ecran){
	boucle_devine_couleur(world,ecran);
	switch(world->devine.res){
		case true:
			coffre_reussi(c,world);
			break;
		case false:
			coffre_echec(c,world);
			break;
	}
}

void verif_click_coffre(coffre_t* c, souris_t* s, world_t* world, SDL_Surface *ecran){
	if((s->click_x >= c->x) && (s->click_x <= c->x + c->largeur)){
		if((s->click_y >= c->y) && (s->click_y <= c->y + c->hauteur)){
			serrure_coffre(c,world,ecran);
			s->click_x = -100;
			s->click_y = -100;
		}
	}
}


