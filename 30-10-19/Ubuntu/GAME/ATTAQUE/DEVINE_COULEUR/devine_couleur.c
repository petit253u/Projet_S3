#include "../../../GENERAL/general.h"

bool compare_devine(devine_couleur_t* dc){
	for(int i=0; i<dc->nb_attendu; i++){
		if(dc->tabattendu[i] != dc->tabserie[i]){
			return false;
		}
	}
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void refresh_z_graphics_bouton_devine_arcade(bouton_devine_arcade_t* b,SDL_Surface *ecran, int i){
	if(i == 1){
		b->x = 695;
		b->y = 557;
	}
	else{
		b->x = -100;
		b->y = -100;
	}
}

void refresh_q_graphics_bouton_devine_arcade(bouton_devine_arcade_t* b,SDL_Surface *ecran, int i){
	if(i == 2){
		b->x = 357;
		b->y = 527;
	}
	else{
		b->x = -100;
		b->y = -100;
	}
}

void refresh_s_graphics_bouton_devine_arcade(bouton_devine_arcade_t* b,SDL_Surface *ecran, int i){
	if(i == 3){
		b->x = 211;
		b->y = 557;
	}
	else{
		b->x = -100;
		b->y = -100;
	}
}

void refresh_d_graphics_bouton_devine_arcade(bouton_devine_arcade_t* b,SDL_Surface *ecran, int i){
	if(i == 4){
		b->x = 549;
		b->y = 527;
	}
	else{
		b->x = -100;
		b->y = -100;
	}
}

void refresh_a_graphics_bouton_devine_arcade(bouton_devine_arcade_t* b,SDL_Surface *ecran){
	b->x = -100;
	b->y = -100;
}

void refresh_graphics_bouton_devine_arcade(bouton_devine_arcade_t* b,SDL_Surface *ecran,int i,char zqsd){
	switch(zqsd){
		case 'z':
			refresh_z_graphics_bouton_devine_arcade(b,ecran,i);
			break;
		case 'q':
			refresh_q_graphics_bouton_devine_arcade(b,ecran,i);
			break;
		case 's':
			refresh_s_graphics_bouton_devine_arcade(b,ecran,i);
			break;
		case 'd':
			refresh_d_graphics_bouton_devine_arcade(b,ecran,i);
			break;
		default:
			refresh_a_graphics_bouton_devine_arcade(b,ecran);
			break;
	}
	apply_surface(b->sprite,ecran,b->x,b->y);
}

void refresh_graphics_devine(devine_couleur_t* dc,SDL_Surface *ecran){
	apply_surface(dc->fond,ecran,75,75); 
	apply_surface(dc->arcade,ecran,25,25); 
	for(int l=0; l<4; l++){
		refresh_graphics_bouton_devine_arcade(&dc->tabbouton[l],ecran,l+1,dc->dir);
	}
	refresh_surface(ecran);
}

//////////

void refresh_graphics_devine_affichache_debut(devine_couleur_t* dc,SDL_Surface *ecran){
	apply_surface(dc->fond,ecran,75,75); 
	apply_surface(dc->arcade,ecran,25,25); 
	refresh_surface(ecran);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void resultat_devine(devine_couleur_t* dc,SDL_Surface *ecran){
	bool res = compare_devine(dc);
	if(res == true){
		dc->fond = dc->fond_valide;
		printf("REUSSI\n");
	}
	else{
		dc->fond = dc->fond_echec;
		printf("ECHEC\n");
	}
	refresh_graphics_devine_affichache_debut(dc,ecran);
	SDL_Delay(1000);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void affichage_devine_tab_attendu_z(devine_couleur_t* dc,SDL_Surface *ecran){
	dc->fond = dc->fond_rouge;
	refresh_graphics_devine_affichache_debut(dc,ecran);
	SDL_Delay(500);
}

void affichage_devine_tab_attendu_q(devine_couleur_t* dc,SDL_Surface *ecran){
	dc->fond = dc->fond_bleu;
	refresh_graphics_devine_affichache_debut(dc,ecran);
	SDL_Delay(500);
}

void affichage_devine_tab_attendu_s(devine_couleur_t* dc,SDL_Surface *ecran){
	dc->fond = dc->fond_jaune;
	refresh_graphics_devine_affichache_debut(dc,ecran);
	SDL_Delay(500);
}

void affichage_devine_tab_attendu_d(devine_couleur_t* dc,SDL_Surface *ecran){
	dc->fond = dc->fond_vert;
	refresh_graphics_devine_affichache_debut(dc,ecran);
	SDL_Delay(500);
}

void affichage_devine_tab_attendu_i(char zqsd, devine_couleur_t* dc,SDL_Surface *ecran){
	switch(zqsd){
		case 'z':
			affichage_devine_tab_attendu_z(dc,ecran);
			break;
		case 'q':
			affichage_devine_tab_attendu_q(dc,ecran);
			break;
		case 's':
			affichage_devine_tab_attendu_s(dc,ecran);
			break;
		case 'd':
			affichage_devine_tab_attendu_d(dc,ecran);
			break;
	}
}

void affichage_devine_a_recopier(devine_couleur_t* dc,SDL_Surface *ecran){
	dc->fond = dc->c3;
	refresh_graphics_devine_affichache_debut(dc,ecran);
	SDL_Delay(1000);
	dc->fond = dc->c2;
	refresh_graphics_devine_affichache_debut(dc,ecran);
	SDL_Delay(1000);
	dc->fond = dc->c1;
	refresh_graphics_devine_affichache_debut(dc,ecran);
	SDL_Delay(1000);
	dc->fond = dc->fond_simple;
	refresh_graphics_devine_affichache_debut(dc,ecran);
	SDL_Delay(1000);
	for(int i=0; i<dc->nb_attendu; i++){
		affichage_devine_tab_attendu_i(dc->tabattendu[i], dc,ecran);
		dc->fond = dc->fond_simple;
		refresh_graphics_devine_affichache_debut(dc,ecran);
		SDL_Delay(500);
	}
	SDL_Delay(200);
	dc->fond = dc->c3;
	refresh_graphics_devine_affichache_debut(dc,ecran);
	SDL_Delay(1000);
	dc->fond = dc->c2;
	refresh_graphics_devine_affichache_debut(dc,ecran);
	SDL_Delay(1000);
	dc->fond = dc->c1;
	refresh_graphics_devine_affichache_debut(dc,ecran);
	SDL_Delay(1000);
	dc->fond = dc->a_toi;
	refresh_graphics_devine_affichache_debut(dc,ecran);
	SDL_Delay(1000);
	dc->fond = dc->fond_simple;
	refresh_graphics_devine_affichache_debut(dc,ecran);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void init_graphics_devine_bouton_arcade(bouton_devine_arcade_t* b, SDL_Surface *ecran){
	set_transparence(ecran, b->sprite, 255, 0, 255);
}

void init_graphics_devine(devine_couleur_t* dc, SDL_Surface *ecran){
	set_transparence(ecran, dc->arcade, 255, 0, 255);
	for(int i=0; i<4; i++){
		init_graphics_devine_bouton_arcade(&dc->tabbouton[i],ecran);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void boucle_enregistrement_choix_devine(devine_couleur_t* dc){
	dc->tabserie[dc->nb_remplis] = dc->dir;
	dc->nb_remplis ++;
	SDL_Delay(500);
	if(dc->nb_remplis == dc->nb_attendu){
		dc->ouvert = false;
	}
	dc->fond = dc->fond_simple;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void handle_event_devine(SDL_Event *event, world_t *world,SDL_Surface *ecran){
	Uint8 *keystates;
	while( SDL_PollEvent( event ) ) {
		//Si l'utilisateur a cliqué sur le X de la fenêtre
		if( event->type == SDL_QUIT ) {
			//On quitte le programme
			world->combat.devine.ouvert = false;
			world->gameover = 1;
		}
		/* Si l'utilisateur appuie sur
		la touche droite de la souris */
		keystates = SDL_GetKeyState( NULL );
		if( keystates[ SDLK_p ] ) {
			world->combat.devine.ouvert = false;
		}
		else if( keystates[ SDLK_z ] ) {
			world->combat.devine.dir = 'z';
			world->combat.devine.fond = world->combat.devine.fond_rouge;
			refresh_graphics_devine(&world->combat.devine,ecran);
			boucle_enregistrement_choix_devine(&world->combat.devine);
		}
		else if( keystates[ SDLK_q ] ) {
			world->combat.devine.dir = 'q';
			world->combat.devine.fond = world->combat.devine.fond_bleu;
			refresh_graphics_devine(&world->combat.devine,ecran);
			boucle_enregistrement_choix_devine(&world->combat.devine);
		}
		else if( keystates[ SDLK_s ] ) {
			world->combat.devine.dir = 's';
			world->combat.devine.fond = world->combat.devine.fond_jaune;
			refresh_graphics_devine(&world->combat.devine,ecran);
			boucle_enregistrement_choix_devine(&world->combat.devine);
		}
		else if( keystates[ SDLK_d ] ) {
			world->combat.devine.dir = 'd';
			world->combat.devine.fond = world->combat.devine.fond_vert;
			refresh_graphics_devine(&world->combat.devine,ecran);
			boucle_enregistrement_choix_devine(&world->combat.devine);
		}
		else{
			world->combat.devine.dir = 'a';
			world->combat.devine.fond = world->combat.devine.fond_simple;
		}
	}
} 

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void boucle_devine_couleur(world_t* world, SDL_Surface *ecran){
	SDL_Event event_devine;
	init_devine_couleur(&world->combat.devine);
	init_graphics_devine(&world->combat.devine,ecran);
	refresh_graphics_devine_affichache_debut(&world->combat.devine,ecran);
	affichage_devine_a_recopier(&world->combat.devine,ecran);
	while(world->combat.devine.ouvert == true){
		handle_event_devine(&event_devine,world,ecran);
		refresh_graphics_devine(&world->combat.devine,ecran);
	}
	resultat_devine(&world->combat.devine,ecran);
}


