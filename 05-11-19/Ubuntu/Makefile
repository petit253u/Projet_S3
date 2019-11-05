######################################################################################################################
######################################################################################################################
######################################################################################################################

HEADER = $(GENERAL_HEADER) $(GAME_HEADER) $(MENU_HEADER) $(UPDATE_HEADER) $(INIT_HEADER) $(JOUEUR_HEADER)       

CODE = main.c $(GENERAL_CODE) $(GAME_CODE) $(MENU_CODE) $(UPDATE_CODE) $(INIT_CODE) $(JOUEUR_CODE)     

######################################################################################################################

jeu: $(HEADER) $(CODE) 
	clear
	clear
	gcc -Wall -g $(CODE) -std=c99  -lm `sdl-config --cflags --libs` -o jeu

clean:
	rm -f jeu
	
######################################################################################################################
######################################################################################################################
######################################################################################################################

GENERAL_HEADER = GENERAL/sdl-light.h 
GENERAL_CODE = GENERAL/sdl-light.c

######################################################################################################################

JOUEUR_HEADER = JOUEUR/init_joueur.h
JOUEUR_CODE = JOUEUR/init_joueur.c

######################################################################################################################

GAME_HEADER = $(COMBAT_HEADER) $(FUIR_HEADER) $(EPARGNER_HEADER)
GAME_CODE = $(COMBAT_CODE) $(FUIR_CODE) $(EPARGNER_CODE)

	FUIR_HEADER = GAME/FUIR/fuir.h GAME/FUIR/init_fuir.h
	FUIR_CODE = GAME/FUIR/fuir.c GAME/FUIR/init_fuir.c

	EPARGNER_HEADER = GAME/EPARGNER/epargner.h GAME/EPARGNER/init_epargner.h
	EPARGNER_CODE = GAME/EPARGNER/epargner.c GAME/EPARGNER/init_epargner.c
	
	COMBAT_HEADER = GAME/init_combat.h GAME/combat.h $(ATTAQUE_HEADER) $(ESQUIVE_HEADER) 
	COMBAT_CODE = GAME/init_combat.c GAME/combat.c $(ATTAQUE_CODE) $(ESQUIVE_CODE)
	
		ESQUIVE_HEADER = $(CUBE_PRISON_HEADER)
		ESQUIVE_CODE = $(CUBE_PRISON_CODE)

			CUBE_PRISON_HEADER = GAME/ESQUIVE/CUBE_PRISON/cube_prison.h GAME/ESQUIVE/CUBE_PRISON/init_cube_prison.h
			CUBE_PRISON_CODE = GAME/ESQUIVE/CUBE_PRISON/cube_prison.c GAME/ESQUIVE/CUBE_PRISON/init_cube_prison.c

		ATTAQUE_HEADER = $(SNAKE_HEADER) $(DEVINE_COULEUR_HEADER)
		ATTAQUE_CODE = $(SNAKE_CODE) $(DEVINE_COULEUR_CODE)

			SNAKE_HEADER = GAME/ATTAQUE/SNAKE/snake.h GAME/ATTAQUE/SNAKE/init_snake.h
			SNAKE_CODE = GAME/ATTAQUE/SNAKE/snake.c GAME/ATTAQUE/SNAKE/init_snake.c

			DEVINE_COULEUR_HEADER = GAME/ATTAQUE/DEVINE_COULEUR/init_devine_couleur.h GAME/ATTAQUE/DEVINE_COULEUR/devine_couleur.h
			DEVINE_COULEUR_CODE = GAME/ATTAQUE/DEVINE_COULEUR/init_devine_couleur.c GAME/ATTAQUE/DEVINE_COULEUR/devine_couleur.c

######################################################################################################################

MENU_HEADER = $(MENU_DEMARRER_HEADER) $(MENU_IN_GAME_HEADER)
MENU_CODE = $(MENU_DEMARRER_CODE) $(MENU_IN_GAME_CODE)

	MENU_DEMARRER_HEADER = MENU/MENU_DEMARRER/menu_demarrer.h MENU/MENU_DEMARRER/init_menu_demarrer.h
	MENU_DEMARRER_CODE = MENU/MENU_DEMARRER/menu_demarrer.c MENU/MENU_DEMARRER/init_menu_demarrer.c
	
	MENU_IN_GAME_HEADER = MENU/MENU_IN_GAME/menu.h  MENU/MENU_IN_GAME/init_menu.h
	MENU_IN_GAME_CODE = MENU/MENU_IN_GAME/menu.c  MENU/MENU_IN_GAME/init_menu.c

######################################################################################################################

UPDATE_HEADER = UPDATE/update.h
UPDATE_CODE = UPDATE/update.c

######################################################################################################################

INIT_HEADER = INIT/init.h
INIT_CODE = INIT/init.c

######################################################################################################################
######################################################################################################################
######################################################################################################################



	


