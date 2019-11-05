#include "../../../GENERAL/general.h"

void init_data_coffre(coffre_t* c, int x, int y){
	c->x = x;
	c->y = y;
	c->largeur = LARGEUR_COFFRE;
	c->hauteur = HAUTEUR_COFFRE;
	c->ouvert = false; 
	c->c1 = load_image("RESSOURCES/OBJET/COFFRE/coffre.bmp");
	c->c2 = load_image("RESSOURCES/OBJET/COFFRE/coffre_cliquable.bmp");
	c->c3 = load_image("RESSOURCES/OBJET/COFFRE/coffre_detruit.bmp");
	c->c4 = load_image("RESSOURCES/OBJET/COFFRE/coffre_reussi.bmp");
	c->sprite = c->c1;
	// contien ?
}
