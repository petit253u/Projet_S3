#include "../../GENERAL/general.h"

/////////////////////////////////////////////////////

void refresh_graphics_fuis_les_lignes(SDL_Surface *ecran, fuis_les_lignes_t* fll){
	return;
}

/////////////////////////////////////////////////////

void update_affichage_fll_bouton(fuis_les_lignes_t* fll, char dir){
	switch(dir){
		case 'q':
			//bouton gauche
		break;
		case 'd':
			//bouton droit
		break;
	}
}

/////////////////////////////////////////////////////

void verif_fll_touche_ennemi(fuis_les_lignes_t *fll){
	return;
}

/////////////////////////////////////////////////////

void verif_prochain_mouvement_fll(fuis_les_lignes_t* fll, char dir){
	switch(dir){
		case 'q':
			if(fll->j.x != DISTANCE_CADRE_FLL + TAILLE_ECRAN_FLL_WIDTH/10){
				fll->j.x = fll->j.x - TAILLE_ECRAN_FLL_WIDTH/10;
			}
		break;
		case 'd':
			if(fll->j.x != DISTANCE_CADRE_FLL + TAILLE_ECRAN_FLL_WIDTH/10*9){
				fll->j.x = fll->j.x + TAILLE_ECRAN_FLL_WIDTH/10;
			}
		break;
	}
}
/////////////////////////////////////////////////////

void init_graphics_objet_fll(SDL_Surface *ecran, objet_paterne_t* o){
	printf("	OBJET\n");
	set_transparence(ecran, o->sprite, 255, 0, 255);
}

void init_graphics_paterne_fll(SDL_Surface *ecran, paterne_t *p){
	for(int i=0; i<p->nb_objet; i++){
		printf("TRANSPARENCE OBJET\n");
		init_graphics_objet_fll(ecran, &p->tab_objet[i]);
	}
}

void init_graphics_joueur_fll(SDL_Surface *ecran, joueur_fll_t *j){
	printf("TRANSPARENCE JOUEUR\n");
	set_transparence(ecran, j->s1, 255, 0, 255);
	set_transparence(ecran, j->s2, 255, 0, 255);
}

void init_graphics_fll(SDL_Surface *ecran, fuis_les_lignes_t *fll){
	printf("TRANSPARENCE BASE\n");
	set_transparence(ecran, fll->fond_base, 255, 0, 255);
	set_transparence(ecran, fll->fond_fll, 255, 0, 255);
	init_graphics_joueur_fll(ecran,&fll->j);
	init_graphics_paterne_fll(ecran,&fll->tab_paterne[fll->choix_paterne]);
}

/////////////////////////////////////////////////////

void handle_event_fuis_les_lignes(SDL_Event *event3, fuis_les_lignes_t *fll){
	Uint8 *keystates;
	while( SDL_PollEvent( event3 ) ) {
		//Si l'utilisateur a cliqué sur le X de la fenêtre
		if( event3->type == SDL_QUIT ) {
			//On quitte le programme
			fll->gameover = 1;
			fll->ouvert = false;
		}
		keystates = SDL_GetKeyState( NULL );
		if( keystates[ SDLK_q ] ) {
			update_affichage_fll_bouton(fll,'q');
			verif_prochain_mouvement_fll(fll,'q');
		}
		if( keystates[ SDLK_d ] ) {
			update_affichage_fll_bouton(fll,'d');
			verif_prochain_mouvement_fll(fll,'q');
		}
		if( keystates[ SDLK_h ] ) {
			fll->ouvert = false;
		}
	}
}

/////////////////////////////////////////////////////

void clear_fll_objet(objet_paterne_t* o){
	SDL_FreeSurface(o->sprite);
}

void clear_fll_paterne(paterne_t *p){
	for(int i=0; i<p->nb_objet; i++){
		clear_fll_objet(&p->tab_objet[i]);
	}	
}

void clear_fll_joueur(joueur_fll_t *j){
	SDL_FreeSurface(j->sprite);
	SDL_FreeSurface(j->s1);
	SDL_FreeSurface(j->s2);
}

void clear_fll(fuis_les_lignes_t *fll){
	SDL_FreeSurface(fll->fond_base);
	SDL_FreeSurface(fll->fond_fll);
	clear_fll_joueur(&fll->j);
	for(int i=0; i<fll->nb_paterne; i++){
		clear_fll_paterne(&fll->tab_paterne[i]);
	}
}

/////////////////////////////////////////////////////

void boucle_fuis_les_lignes(world_t* world, SDL_Surface *ecran){
	SDL_Event event3;
	printf("PV RESTANT\n");
	world->combat.fuis_les_lignes.pv_restant = world->j.pv;
	printf("CHOIX PATERNE\n");
	world->combat.fuis_les_lignes.choix_paterne = 2;//(rand() % NB_PATERNE)+1;
	printf("INIT GRAPH\n");
	init_graphics_fll(ecran,&world->combat.fuis_les_lignes);
	printf("CONDITION BOUCLE\n");
	while(world->combat.fuis_les_lignes.ouvert == true){
		printf("BOUCLE\n");
		printf("	HANDLE\n");
		handle_event_fuis_les_lignes(&event3, &world->combat.fuis_les_lignes);
		printf("	VERIF TOUCHER\n");
		verif_fll_touche_ennemi(&world->combat.fuis_les_lignes);
		printf("	REFRESH\n");
		refresh_graphics_fuis_les_lignes(ecran, &world->combat.fuis_les_lignes);
	}
	clear_fll(&world->combat.fuis_les_lignes);
	printf("SORTIE BOUCLE\n");
	return;
}

