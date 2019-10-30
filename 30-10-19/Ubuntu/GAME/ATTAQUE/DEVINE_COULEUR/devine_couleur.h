#ifndef DEVINE_COULEUR_H
#define DEVINE_COULEUR_H

#include "../../../GENERAL/sdl-light.h"

bool compare_devine(devine_couleur_t* dc);

void refresh_z_graphics_bouton_devine_arcade(bouton_devine_arcade_t* b,SDL_Surface *ecran, int i);

void refresh_q_graphics_bouton_devine_arcade(bouton_devine_arcade_t* b,SDL_Surface *ecran, int i);

void refresh_s_graphics_bouton_devine_arcade(bouton_devine_arcade_t* b,SDL_Surface *ecran, int i);

void refresh_d_graphics_bouton_devine_arcade(bouton_devine_arcade_t* b,SDL_Surface *ecran, int i);

void refresh_graphics_bouton_devine_arcade(bouton_devine_arcade_t* b,SDL_Surface *ecran,int i,char zqsd);

void refresh_graphics_devine(devine_couleur_t* dc,SDL_Surface *ecran);

void refresh_graphics_devine_affichache_debut(devine_couleur_t* dc,SDL_Surface *ecran);

void resultat_devine(devine_couleur_t* dc,SDL_Surface *ecran);

void affichage_devine_tab_attendu_z(devine_couleur_t* dc,SDL_Surface *ecran);

void affichage_devine_tab_attendu_q(devine_couleur_t* dc,SDL_Surface *ecran);

void affichage_devine_tab_attendu_s(devine_couleur_t* dc,SDL_Surface *ecran);

void affichage_devine_tab_attendu_d(devine_couleur_t* dc,SDL_Surface *ecran);

void affichage_devine_tab_attendu_i(char zqsd, devine_couleur_t* dc,SDL_Surface *ecran);

void affichage_devine_a_recopier(devine_couleur_t* dc,SDL_Surface *ecran);

void init_graphics_devine_bouton_arcade(bouton_devine_arcade_t* b, SDL_Surface *ecran);

void init_graphics_devine(devine_couleur_t* dc, SDL_Surface *ecran);

void boucle_enregistrement_choix_devine(devine_couleur_t* dc);

void handle_event_devine(SDL_Event *event, world_t *world,SDL_Surface *ecran);

void boucle_devine_couleur(world_t* world, SDL_Surface *ecran);


#endif
