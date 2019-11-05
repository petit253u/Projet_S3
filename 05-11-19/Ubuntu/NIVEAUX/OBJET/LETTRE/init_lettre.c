#include "../../../GENERAL/general.h"

void init_data_lettre(lettre_t* l, int x, int y){
	l->x = x;
	l->y = y;
	l->largeur = LARGEUR_LETTRE;
	l->hauteur = HAUTEUR_LETTRE;
	l->l1 = load_image("RESSOURCES/OBJET/LETTRE/lettre.bmp");
	l->l2 = load_image("RESSOURCES/OBJET/LETTRE/lettre_cliquable.bmp");
	l->sprite = l->l1;
	// contien ?
}
