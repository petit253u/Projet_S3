#ifndef __SDL_LIGHT_H__
#define __SDL_LIGHT_H__

#include <SDL.h>

SDL_Surface* load_image(char path[]);
void apply_surface(SDL_Surface *surface, SDL_Surface *screen, int x, int y);
SDL_Surface* init_sdl();
void quit_sdl();
void apply_sub_surface(SDL_Surface *surface, SDL_Surface *screen, int subposx, int subposy, int sub_width, int sub_height, int posx, int posy);
void  set_transparence(SDL_Surface *screen, SDL_Surface *surf, int r, int g, int b);

void refresh_surface(SDL_Surface *screen);

 

#endif
