#include "../../GENERAL/general.h"

void init_souris_epargner(souris_t* souris){
	souris->x = -100;
	souris->y = -100;
	souris->click_x = -100;
	souris->click_y = -100;
}

/////////////////////////////////////// CARTES ///////////////////////////////////////////////

void init_carte_epargner(carte_valide_t* carte){
	carte->x = 75 + (LARGEUR_ECRAN_EPARGNER/2) - (LARGEUR_CARTE_EPARGNER/2);
	carte->y = 75 + (HAUTEUR_ECRAN_EPARGNER/2) - (HAUTEUR_CARTE_EPARGNER/2);
	carte->largeur = LARGEUR_CARTE_EPARGNER;
	carte->hauteur = HAUTEUR_CARTE_EPARGNER;
	carte->carte_simple = load_image("RESSOURCES/FUIR_EPARGNER/carte_simple.bmp");
	carte->carte_cliquable = load_image("RESSOURCES/FUIR_EPARGNER/carte_cliquable.bmp");
	carte->carte_valide = load_image("RESSOURCES/FUIR_EPARGNER/carte_valide.bmp");
	carte->sprite = carte->carte_simple;
}


/////////////////////////////////////// ALL ///////////////////////////////////////////////

void init_epargner(epargner_t* epargner){
	epargner->arcade = load_image("RESSOURCES/ARCADE/arcade.bmp");
	epargner->fond_noir = load_image("RESSOURCES/FUIR_EPARGNER/fond_epargner.bmp");
	epargner->ouvert = true;
	init_carte_epargner(&epargner->carte);
	init_souris_epargner(&epargner->souris);
}

