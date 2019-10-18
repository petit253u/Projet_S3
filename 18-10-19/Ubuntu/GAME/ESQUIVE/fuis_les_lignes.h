#ifndef FUIS_LES_LIGNES_H
#define FUIS_LES_LIGNES_H

#include "../../GENERAL/sdl-light.h"

void refresh_graphics_fuis_les_lignes(SDL_Surface *ecran, fuis_les_lignes_t* fll);

void update_affichage_fll_bouton(char dir);

void verif_prochain_mouvement_fll(fuis_les_lignes_t* fll, char dir);

void verif_fll_touche_ennemi(fuis_les_lignes_t *fll);

void handle_event_fuis_les_lignes(SDL_Event *event3, fuis_les_lignes_t *fll);

void clear_fll_objet(objet_paterne_t* o);

void clear_fll_paterne(paterne_t *p);

void clear_fll_joueur(joueur_fll_t *j);

void clear_fll(fuis_les_lignes_t *fll);

void boucle_fuis_les_lignes(world_t* world, SDL_Surface *ecran);

#endif
