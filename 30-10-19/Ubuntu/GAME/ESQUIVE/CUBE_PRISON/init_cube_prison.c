#include "../../../GENERAL/general.h"

void init_temps_cube(temps_t* t){
	t->temps_ancien = 0;
	t->temps_actuel = SDL_GetTicks();
	t->ecart_souhait = 1;
}

void init_souris_cube(souris_t* s){
	s->x = BORDURE_GAUCHE_CUBE + ((BORDURE_DROITE_CUBE - BORDURE_GAUCHE_CUBE) / 2 );
	s->y = BORDURE_HAUTE_CUBE + ((BORDURE_BASSE_CUBE - BORDURE_HAUTE_CUBE) / 2 );
}

void init_joueur_cube(joueur_cube_t* j){
	j->x = BORDURE_GAUCHE_CUBE + ((BORDURE_DROITE_CUBE - BORDURE_GAUCHE_CUBE) / 2 );
	j->y = BORDURE_HAUTE_CUBE + ((BORDURE_BASSE_CUBE - BORDURE_HAUTE_CUBE) / 2 );
	j->hauteur = HAUTEUR_SPRITE_JOUEUR_CUBE;
	j->largeur = LARGEUR_SPRITE_JOUEUR_CUBE;
	j->s1 = load_image("RESSOURCES/sprite.bmp");
	j->s2 = load_image("RESSOURCES/lettre.bmp");
	j->sprite = j->s1;
}

/////////////////////////////////////// ATTAQUE ///////////////////////////////////////////////

void init_attaque_cube_type_1(attaque_cube_t* a, int x, int y, char zqsd){
	a->x = x;
	a->y = y;
	a->largeur = LARGEUR_TYPE_1_ATTAQUE_CUBE;
	a->hauteur = HAUTEUR_TYPE_1_ATTAQUE_CUBE;
	a->dir = zqsd;
	a->degat = 10;
	a->sprite = load_image("RESSOURCES/sprite.bmp");
}

void init_attaque_cube_type_n(attaque_cube_t* a, int x, int y, int n, char zqsd){
	switch(n){
		case 1 :
			init_attaque_cube_type_1(a, x, y, zqsd);
			break;
		case 2 :
			//init_attaque_cube_type_2(a, x, y, zqsd);
			break;
		case 3 :
			//init_attaque_cube_type_3(a, x, y, zqsd);
			break;
		case 4 :
			//init_attaque_cube_type_4(a, x, y, zqsd);
			break;
	}
}

/////////////////////////////////////// PATERNE ///////////////////////////////////////////////

void init_attaque_paterne_1_cube(paterne_t* p){
	int x = 100, y = 200, n = 1;
	char dir = 'd';
	for(int i=0; i<p->nb_attaque; i++){
		init_attaque_cube_type_n(&p->tabattaque[i],x,y,n,dir);
		y = y-55;
	}
}

void init_paterne_1_cube(paterne_t* p){
	p->nb_attaque = 20;
	init_attaque_paterne_1_cube(p);
}

void init_paterne_cube(cube_prison_t* cube){
	int random = 1;//(rand() % 4) + 1;
	switch(random){
		case 1 :
			init_paterne_1_cube(&cube->paterne); 
			break;
		case 2 :
			//init_paterne_2_cube(&cube->paterne); 
			break;
		case 3 :
			//init_paterne_3_cube(&cube->paterne);  
			break;
		case 4 :
			//init_paterne_4_cube(&cube->paterne);  
			break;
	}
}

/////////////////////////////////////// ALL ///////////////////////////////////////////////

void init_cube_prison(cube_prison_t* cube){
	cube->arcade = load_image("RESSOURCES/ARCADE/arcade.bmp");
	cube->fond_cube = load_image("RESSOURCES/CUBE_PRISON/fond_cube.bmp");
	cube->ouvert = true;
	init_joueur_cube(&cube->joueur);
	init_souris_cube(&cube->souris);
	init_temps_cube(&cube->temps);
	init_paterne_cube(cube);
}
