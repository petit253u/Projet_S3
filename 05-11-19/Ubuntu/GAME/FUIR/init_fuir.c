#include "../../GENERAL/general.h"

void init_souris_fuir(souris_t* souris){
	souris->x = -100;
	souris->y = -100;
	souris->click_x = -100;
	souris->click_y = -100;
}

/////////////////////////////////////// CARTE ///////////////////////////////////////////////

void init_carte_fuir_chaque(carte_fuir_t* carte, int x, int y, bool bonne){
	carte->x = x;
	carte->y = y;
	carte->largeur = LARGEUR_CARTE_FUIR;
	carte->hauteur = HAUTEUR_CARTE_FUIR;
	carte->carte_simple = load_image("RESSOURCES/FUIR_EPARGNER/carte_simple.bmp");
	carte->carte_cliquable = load_image("RESSOURCES/FUIR_EPARGNER/carte_cliquable.bmp");
	carte->bonne = bonne;
	if(bonne){
		carte->carte_retourne = load_image("RESSOURCES/FUIR_EPARGNER/carte_valide.bmp");
	}
	else{
		carte->carte_retourne = load_image("RESSOURCES/FUIR_EPARGNER/carte_echec.bmp");
	}
	carte->sprite = carte->carte_simple;
}

void init_carte_fuir(fuir_t* fuir){
	int x_ecart;
	int ligne;
	if(fuir->nb_carte >= 4){
		ligne = 2;
		x_ecart = LARGEUR_ECRAN_FUIR - (fuir->nb_carte/2 * LARGEUR_CARTE_FUIR);
		x_ecart = x_ecart / ((fuir->nb_carte/2)+1);
	}
	else{
		ligne = 1;
		x_ecart = LARGEUR_ECRAN_FUIR - (fuir->nb_carte * LARGEUR_CARTE_FUIR);
		x_ecart = x_ecart / (fuir->nb_carte+1);
	}
	int y_ecart = HAUTEUR_ECRAN_FUIR - (ligne * HAUTEUR_CARTE_FUIR);
	y_ecart = y_ecart / (ligne+1);

	int x_pos_act = x_ecart + 75;
	int y_pos_act = y_ecart + 75;

	int laquelle = (rand() % fuir->nb_carte);
	bool bonne = false;
	for(int i=0; i<fuir->nb_carte; i++){
		if(laquelle == i){
			bonne = true;
			init_carte_fuir_chaque(&fuir->tabcarte[i], x_pos_act, y_pos_act, bonne);
		}
		else{
			bonne = false;
			init_carte_fuir_chaque(&fuir->tabcarte[i], x_pos_act, y_pos_act, bonne);
		}
		x_pos_act = x_pos_act + x_ecart + LARGEUR_CARTE_FUIR ;
		if((fuir->nb_carte/2) == i+1){
			if(ligne == 2){
				x_pos_act = x_ecart + 75;
				y_pos_act = y_pos_act + y_ecart + HAUTEUR_CARTE_FUIR;
			}
		}
	}
}

/////////////////////////////////////// ALL ///////////////////////////////////////////////

void init_fuir(fuir_t* fuir){
	fuir->arcade = load_image("RESSOURCES/ARCADE/arcade.bmp");
	fuir->fond_noir = load_image("RESSOURCES/FUIR_EPARGNER/fond_noir.bmp");
	fuir->ouvert = true;
	int level = (rand() % 5) + 1;
	switch(level){
		case 1 :
			fuir->nb_carte = 2;
			break;
		case 2 :
			fuir->nb_carte = 4;
			break;
		case 3 :
			fuir->nb_carte = 6;
			break;
		case 4 :
			fuir->nb_carte = 8;
			break;
		case 5 :
			fuir->nb_carte = 10;
			break;
	}
	init_carte_fuir(fuir);
	init_souris_fuir(&fuir->souris);
}

