#include "../../../GENERAL/general.h"


void init_graphics_lettre(lettre_t* l, SDL_Surface *ecran){
	set_transparence(ecran, l->l1, 255, 0, 255);
	set_transparence(ecran, l->l2, 255, 0, 255);
}

void refresh_graphics_lettre(lettre_t* l, SDL_Surface *ecran){
	apply_surface(l->sprite,ecran,l->x,l->y); 
}

//////////////////////////////////////////////////////////////

void lire_lettre(lettre_t* l, world_t* world, SDL_Surface *ecran){
	return;
}

void verif_click_lettre(lettre_t* l, souris_t* s, world_t* world, SDL_Surface *ecran){
	if((s->click_x >= l->x) && (s->click_x <= l->x + l->largeur)){
		if((s->click_y >= l->y) && (s->click_y <= l->y + l->hauteur)){
			lire_lettre(l,world,ecran);
			s->click_x = -100;
			s->click_y = -100;
		}
	}
}

