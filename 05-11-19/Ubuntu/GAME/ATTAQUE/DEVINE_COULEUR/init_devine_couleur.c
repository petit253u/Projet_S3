#include "../../../GENERAL/general.h"

void init_bouton_arcade_devine(bouton_devine_arcade_t* b,int i){
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

char lire_devine_random(int random){
	char res;
	switch(random){
		case 1:
			res = 'z';
			break;
		case 2:
			res = 'q';
			break;
		case 3:
			res = 's';
			break;
		case 4:
			res = 'd';
			break;
	}
	return res;
}

///////////////////////////////////////////////// LEVEL //////////////////////////////////////////////////////

void init_devine_level(devine_couleur_t* dc){
	dc->nb_attendu = (rand() % 8) + 1;
	dc->nb_remplis = 0;
	int random;
	for(int i=0; i<dc->nb_attendu; i++){
		random = (rand() % 4) + 1;
		dc->tabattendu[i] = lire_devine_random(random);
	}
}

///////////////////////////////////////////////// ALL //////////////////////////////////////////////////////

void init_devine_couleur(devine_couleur_t* dc){
	for(int i=0; i<4; i++){
		init_bouton_arcade_devine(&dc->tabbouton[i],i+1);
	}
	dc->arcade = load_image("RESSOURCES/ARCADE/arcade.bmp");

	dc->c1 = load_image("RESSOURCES/DEVINE/fond_c1.bmp");
	dc->c2 = load_image("RESSOURCES/DEVINE/fond_c2.bmp");
	dc->c3 = load_image("RESSOURCES/DEVINE/fond_c3.bmp");
	dc->a_toi = load_image("RESSOURCES/DEVINE/fond_a_toi.bmp");

	dc->fond_simple = load_image("RESSOURCES/DEVINE/fond_devine_simple.bmp");
	dc->fond_jaune = load_image("RESSOURCES/DEVINE/fond_devine_jaune.bmp");  
	dc->fond_bleu = load_image("RESSOURCES/DEVINE/fond_devine_bleu.bmp"); 
	dc->fond_vert = load_image("RESSOURCES/DEVINE/fond_devine_vert.bmp");  
	dc->fond_rouge = load_image("RESSOURCES/DEVINE/fond_devine_rouge.bmp");

	dc->fond_valide = load_image("RESSOURCES/DEVINE/fond_valide.bmp"); 
	dc->fond_echec = load_image("RESSOURCES/DEVINE/fond_echec.bmp");

	dc->fond = dc->fond_simple;  

	dc->dir = 'a';
	dc->ouvert = true;
	dc->res = false;
	init_devine_level(dc);
}
