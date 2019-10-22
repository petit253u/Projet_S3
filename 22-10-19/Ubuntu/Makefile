niveau0: main.c GENERAL/sdl-light.c GENERAL/sdl-light.h GAME/ESQUIVE/fuis_les_lignes.c  GAME/ESQUIVE/fuis_les_lignes.h GAME/combat.c GAME/combat.h GAME/ATTAQUE/SNAKE/init_snake.c GAME/ATTAQUE/SNAKE/init_snake.h GAME/ATTAQUE/SNAKE/snake.c GAME/ATTAQUE/SNAKE/init_snake.h  MENU/menu.c MENU/menu.h MENU/menu_demarrer.c MENU/menu_demarrer.h UPDATE/update.c UPDATE/update.h INIT/init.c INIT/init.h GENERAL/general.h
	clear
	clear
	gcc -Wall -g  -std=c99 main.c GENERAL/sdl-light.c GAME/ESQUIVE/fuis_les_lignes.c GAME/combat.c GAME/ATTAQUE/SNAKE/snake.c GAME/ATTAQUE/SNAKE/init_snake.c MENU/menu.c MENU/menu_demarrer.c  UPDATE/update.c INIT/init.c -lm `sdl-config --cflags --libs` -o niveau0

clean:
	rm -f niveau0
