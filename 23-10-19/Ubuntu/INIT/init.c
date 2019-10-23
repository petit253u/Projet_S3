/**
* \file init.c
* \brief Module d'inititialisation
* \author PETIT Brian
* \version 0.1
* \date 
*/

#include "../GENERAL/general.h"

/**
* \brief La fonction initialise les données du joueur
* \param j les données du joueur
*/
void init_data_joueur(joueur_t*  j){
	j->x = 500;
	j->y = 300;
	j->largeur = SPRITE_SIZE_WIDTH;
	j->hauteur = SPRITE_SIZE_HEIGHT;
	j->cote = 1;
	printf("	IMAGE 1 :\n");
	j->sprite1 = SDL_LoadBMP("ressources/test_sprite_01.bmp");
	printf("	IMAGE 2 :\n");
	j->sprite2 = SDL_LoadBMP("ressources/test_sprite_02.bmp");
	printf("	IMAGE 3 :\n");
	j->sprite3 = SDL_LoadBMP("ressources/test_sprite_03.bmp");
	printf("	IMAGE 4 :\n");
	j->sprite4 = SDL_LoadBMP("ressources/test_sprite_04.bmp");
	printf("	AFFECTATION :\n");
	j->sprite = j->sprite1;
	j->direction = 'z';
	j->pv = 100;
}

/**
* \brief La fonction initialise les données d'un objet
* \param world les données d'un objet
*/
void init_data_objet(objet_t* o,int temp){
	if(temp ==1){
		o->largeur = SPRITE_BOUTON_WIDTH;
		o->hauteur = SPRITE_BOUTON_HEIGHT;
		o->xobj = SCREEN_WIDTH/2 - 300;
		o->yobj = SCREEN_HEIGHT/2 - 300;
	}
	else{
		o->largeur = SPRITE_TEST_WIDTH;
		o->hauteur = SPRITE_TEST_HEIGHT;
		o->xobj = 600;
		o->yobj = 340;
	}
	o->sprite = SDL_LoadBMP("ressources/sprite.bmp" );
}

/**
* \brief La fonction initialise les données du monde du jeu
* \param world les données du monde
*/
void init_data_souris(souris_t* souris){
	souris->x = -100;
	souris->y = -100;
	souris->click_x = -100;
	souris->click_y = -100;
}

/**
* \brief La fonction initialise les données du monde du jeu
* \param world les données du monde
*/
void init_data_menu(menu_t* m){
	m->ouvert = false;
	m->fond =  SDL_LoadBMP("ressources/FONDMENU.bmp");
	m->bouton1 = SDL_LoadBMP("ressources/bouton_menu_1.bmp");
	m->bouton2 = SDL_LoadBMP("ressources/bouton_menu_2.bmp");
	m->b.x = SCREEN_WIDTH/2 - 300;
	m->b.y = SCREEN_HEIGHT/2 - 300;
	m->b.largeur = SPRITE_BOUTON_WIDTH;
	m->b.hauteur = SPRITE_BOUTON_HEIGHT;
	m->bouton = m->bouton1;
	m->gameover = 0;
	init_data_souris(&m->souris);
}
//////////////////////////////////////////////////////////////////////////

void init_objet_fll(objet_paterne_t* o, int x, int y){
	o->x = x;
	o->y = y;
	o->largeur = TAILLE_COTE_SPRITE_FLL ;
	o->hauteur = TAILLE_COTE_SPRITE_FLL ;
	o->vx = 0;
	o->vy = 0;
	o->sprite = SDL_LoadBMP("ressources/duony.bmp");
}

void init_paterne_fll_2(paterne_t* p){
	p->nb_objet = NB_OBJET_PATERNE;
	int x = DISTANCE_CADRE_FLL + TAILLE_ECRAN_FLL_WIDTH/10;
	int y = DISTANCE_CADRE_FLL + 75;
	for(int i=0; i<8; i++){
		//tab[0] à tab[7]
		init_objet_fll(&p->tab_objet[i],x,y);
		x = x + TAILLE_ECRAN_FLL_WIDTH/10;
		y = y - 75;
	}
	x = x + TAILLE_ECRAN_FLL_WIDTH/10;
	y = y - 150;
	for(int i=8; i<17; i++){
		//tab[8] à tab[16]
		init_objet_fll(&p->tab_objet[i],x,y);
		x = x - TAILLE_ECRAN_FLL_WIDTH/10;
		y = y - 75;
	}
	x = x - TAILLE_ECRAN_FLL_WIDTH/10;
	y = y - 150;
	int temp = 0;
	for(int i=17; i<23; i++){
		//tab[17] à tab[22]
		temp++;
		init_objet_fll(&p->tab_objet[i],x,y);
		x = x + TAILLE_ECRAN_FLL_WIDTH/10;
		if(temp==2){
			x = x + TAILLE_ECRAN_FLL_WIDTH/10 *4;
		}
	}
	x = DISTANCE_CADRE_FLL + TAILLE_ECRAN_FLL_WIDTH/10*4;
	y = y - 150;
	for(int i=23; i<26; i++){
		//tab[23] à tab[25]
		init_objet_fll(&p->tab_objet[i],x,y);
		x = x + TAILLE_ECRAN_FLL_WIDTH/10;
	}
	x = DISTANCE_CADRE_FLL + TAILLE_ECRAN_FLL_WIDTH/10;
	y = y - 150;
	temp = 0;
	for(int i=26; i<32; i++){
		//tab[26] à tab[31]
		temp++;
		init_objet_fll(&p->tab_objet[i],x,y);
		x = x + TAILLE_ECRAN_FLL_WIDTH/10;
		if(temp==2){
			x = x + TAILLE_ECRAN_FLL_WIDTH/10 *4;
		}
	}
	x = DISTANCE_CADRE_FLL + TAILLE_ECRAN_FLL_WIDTH/10;
	y = y - 150;
	for(int i=32; i<37; i++){
		//tab[32] à tab[36]
		init_objet_fll(&p->tab_objet[i],x,y);
		x = x + TAILLE_ECRAN_FLL_WIDTH/10;
	}
	x = DISTANCE_CADRE_FLL + TAILLE_ECRAN_FLL_WIDTH/10*3;
	y = y - 150;
	for(int i=37; i<43; i++){
		//tab[37] à tab[42]
		init_objet_fll(&p->tab_objet[i],x,y);
		x = x + TAILLE_ECRAN_FLL_WIDTH/10;
	}
	x = TAILLE_ECRAN_FLL_WIDTH/10;
	int var = (rand() % 8)+1;
	y = DISTANCE_CADRE_FLL + 75;
	for(int i=43; i<p->nb_objet; i++){
		//tab[43] à tab[nb_objet-1]
		init_objet_fll(&p->tab_objet[i],DISTANCE_CADRE_FLL+x*var,y);
		y = y - 75 ;
		var = (rand() % 8)+1;
	}

}

void init_paterne_fll_1(paterne_t* p){
	p->nb_objet = NB_OBJET_PATERNE;
	int x = TAILLE_ECRAN_FLL_WIDTH/10;
	int var = (rand() % 8)+1;
	int y = DISTANCE_CADRE_FLL + 75;
	for(int i=43; i<p->nb_objet; i++){
		//tab[43] à tab[nb_objet-1]
		init_objet_fll(&p->tab_objet[i],DISTANCE_CADRE_FLL+x*var,y);
		y = y - 75 ;
		var = (rand() % 8)+1;
	}
}

void init_paterne_fll(paterne_t* p, int i){
	switch(i){
		case 1:
			init_paterne_fll_1(p);
		break;
		case 2:
			init_paterne_fll_2(p);
		break;
	}
}

void init_joueur_fll(joueur_fll_t* j){
	j->largeur = TAILLE_COTE_SPRITE_FLL ;
	j->hauteur = TAILLE_COTE_SPRITE_FLL ;
	j->x = DISTANCE_CADRE_FLL + TAILLE_ECRAN_FLL_WIDTH/2 - j->largeur/2;
	j->y = DISTANCE_CADRE_FLL + TAILLE_ECRAN_FLL_HEIGHT/2 - j->hauteur/2;
	j->s1 = SDL_LoadBMP("ressources/kuby.bmp");
	j->s2 = SDL_LoadBMP("ressources/gloupy.bmp");
	j->sprite = j->s1;
}

void init_data_fll(fuis_les_lignes_t* fll){
	fll->gameover = 0;
	fll->ouvert = true;
	fll->nb_paterne = NB_PATERNE;
	fll->pv_restant = 100;
	init_joueur_fll(&fll->j);
	for(int i=0; i<NB_PATERNE-1; i++){
		init_paterne_fll(&fll->tab_paterne[i],i+1);
	} 
	fll->fond_fll = SDL_LoadBMP("ressources/table.bmp");
	fll->fond_base = SDL_LoadBMP("ressources/lettre.bmp");
}

//////////////////////////////////////////////////////////////////////////

/**
* \brief La fonction initialise les données du monde du jeu
* \param world les données du monde
*/
void init_data_bouton_combat(bouton_combat_t *b, int* temp, int i){
	printf("BOUTON :\n");
	b->x = *temp;
	b->y = 550;
	*temp = *temp + 240;
	b->largeur = 200;
	b->hauteur = 50;
	b->cliquable = true;
	printf("SWITCH :\n");
	switch(i){
		case 1:
			printf("	IMAGE 1 :\n");
			b->b1 = SDL_LoadBMP("ressources/bouton_attaquer.bmp");
			b->b2 = SDL_LoadBMP("ressources/bouton_cliquable_attaquer.bmp");
			b->b3 = SDL_LoadBMP("ressources/demon_bouton_achever.bmp");
			b->b4 = SDL_LoadBMP("ressources/demon_bouton_achever_cliquable.bmp");
			//VIDE
			b->b5 = SDL_LoadBMP("ressources/bouton_combat.bmp");
			b->sprite = b->b1;
		break;
		case 2:
			printf("	IMAGE 2 :\n");
			b->b1 = SDL_LoadBMP("ressources/bouton_discuter.bmp");
			b->b2 = SDL_LoadBMP("ressources/bouton_cliquable_discuter.bmp");
			b->b3 = SDL_LoadBMP("ressources/bouton_discuter_bloquer.bmp");
			b->b4 = SDL_LoadBMP("ressources/demon_bouton_torturer.bmp");
			b->b5 = SDL_LoadBMP("ressources/demon_bouton_torturer_cliquable.bmp");
			b->sprite = b->b1;
		break;
		case 3:
			printf("	IMAGE 3 :\n");
			b->b1 = SDL_LoadBMP("ressources/bouton_objet.bmp");
			b->b2 = SDL_LoadBMP("ressources/bouton_cliquable_objet.bmp");
			//VIDE
			b->b3 = SDL_LoadBMP("ressources/bouton_combat.bmp");
			b->b4 = SDL_LoadBMP("ressources/bouton_combat.bmp");
			b->b5 = SDL_LoadBMP("ressources/bouton_combat.bmp");
			b->sprite = b->b1;
		break;
		case 4:
			printf("	IMAGE 4 :\n");
			b->b1 = SDL_LoadBMP("ressources/bouton_fuir.bmp");
			b->b2 = SDL_LoadBMP("ressources/bouton_cliquable_fuir.bmp");
			b->b3 = SDL_LoadBMP("ressources/bouton_fuir_bloquer.bmp");
			b->b4 = SDL_LoadBMP("ressources/demon_bouton_epargner.bmp");
			b->b5 = SDL_LoadBMP("ressources/demon_bouton_epargner_cliquable.bmp");
			b->sprite = b->b1;
		break;
	}
}

/**
* \brief La fonction initialise les données du monde du jeu
* \param world les données du monde
*/
void init_data_combat(combat_t *c){
	int temp = 40;
	c->nb_attaque = 0;
	printf("FOND:\n");
	c->f1 = SDL_LoadBMP("ressources/etape1.bmp");
	c->f2 = SDL_LoadBMP("ressources/etape2.bmp");
	c->f3 = SDL_LoadBMP("ressources/etape3.bmp");
	c->fond = c->f1;
	c->nb_bouton = NB_BOUTON_COMBAT;
	c->etape = 1;
	c->tour = 2;
	for(int i = 0; i < c->nb_bouton ; i++){
		printf("%d\n", i);
		init_data_bouton_combat(&c->tab_bouton[i],&temp,i+1);
	}
	c->pv_restant = 100;
	init_data_souris(&c->souris);
	c->ouvert = true;
	c->gameover = 0;
	//init_data_fll(&c->fuis_les_lignes);
}

/**
* \brief La fonction initialise les données du monde du jeu
* \param world les données du monde
*/
void init_data(world_t * world){

	printf("	BACKGROUND :\n");
	world->background = SDL_LoadBMP("ressources/salle_test.bmp");

	printf("	INIT_JOUEUR :\n");
	init_data_joueur(&world->j);
	
	printf("	INIT_OBJET :\n");
	init_data_objet(&world->o,0);

	printf("	INIT_MENU :\n");
	init_data_menu(&world->menu);

	world->gameover = 0;
}

/**
* \brief La fonction initialise les données du joueur
* \param j les données du joueur
*/
void init_data_debut(menu_entree_t* debut){
	debut->fermer = 0;
	printf("	1 :\n");
	debut->bouton1 = SDL_LoadBMP("ressources/bouton_menu_1.bmp");
	debut->bouton2 = SDL_LoadBMP( "ressources/bouton_menu_2.bmp" );
	debut->bouton = debut->bouton1;
	debut->background = SDL_LoadBMP("ressources/FONDTITRE.bmp");
	debut->bouton = debut->bouton1;
	debut->lequel = 1;
	debut->gameover = 0;
	init_data_objet(&debut->o,1);
	init_data_souris(&debut->souris);
}

/**
* \brief La fonction initialise les transparences des différentes surfaces
* \param screen la surface correspondant à l'écran de jeu
* \param world les données du monde
*/

void  init_graphics(SDL_Surface *screen, world_t *world){
	set_transparence(screen, world->j.sprite1, 255, 0, 255);
	set_transparence(screen, world->j.sprite2, 255, 0, 255);
	set_transparence(screen, world->j.sprite3, 255, 0, 255);
	set_transparence(screen, world->j.sprite4, 255, 0, 255);
	set_transparence(screen, world->o.sprite, 255, 0, 255);
}
