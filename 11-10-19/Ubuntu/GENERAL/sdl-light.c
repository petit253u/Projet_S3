/**
 * \file sdl-light.c
 * \brief sur-couche de SDL pour simplifier son utilisation pour le projet
 * \author Mathieu Constant
 * \version 0.1
 * \date 13 mars 2019
 */

#include "sdl-light.h"
#include <stdio.h>




/**
 * \brief La fonction initialise la SDL.
 * Elle crée et renvoie la surface correspondant à l'écran du jeu
 * \param width largeur de l'écran de jeu
 * \param height hauteur de l'écran de jeu
 * \return la surface SDL correspondant à l'écran de jeu
 */

SDL_Surface* init_sdl(int width, int height){
    SDL_Surface* screen = NULL;
    
    SDL_Init( SDL_INIT_VIDEO );
    
    //Set up screen
    screen = SDL_SetVideoMode( width, height, 16, SDL_SWSURFACE| SDL_DOUBLEBUF | SDL_ANYFORMAT );
    
    return screen;
}


/** 
 * \brief La fonction permet de quitter la SDL
 * en supprimant notamment la surface correspondant à l'écran de jeu
 */

void quit_sdl(){
    SDL_Quit();
}



/**
 * \brief La fonction charge une image  et renvoie la surface SDL optimisée correspondante
 * \param path est le chemin du fichier image. Le fichier doit être obligatoirement du BMP.
 * \return la surface SDL contenant l'image. Elle renvoie NULL si le chargement a échoué
 * (ex. le fichier path n'existe pas)
 */


SDL_Surface* load_image(char path[]){
    SDL_Surface* loadedImage = NULL;
    
    SDL_Surface* optimizedImage = NULL;
    loadedImage = SDL_LoadBMP( path);
    
    if( loadedImage != NULL ) {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
    }
    else{
        fprintf(stderr,"Image %s cannot be loaded!\n",path);
    }
    return optimizedImage;
    
}


/**
 * \brief La fonction permet d'appliquer une surface SDL sur une autre surface à une position donnée
 * \param surf la surface que l'on va appliquer
 * \param screen la surface (souvent l'écran de jeu) qui va recevoir l'autre surface
 * \param x l'abscisse sur screen de l'endroit où est appliquée surf (point en haut à gauche de la surface)
 * \param y l'ordonnée sur screen de l'endroit où est appliquée surf (point en haut à gauche de la surface)
 *
 */

void apply_surface(SDL_Surface* surf, SDL_Surface *screen, int x, int y){
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    
    
    SDL_BlitSurface( surf, NULL, screen, &pos );
    
}


/**
 * \brief  La fonction applique une zone d'une surface sur une autre surface à une position donnée. La zone à appliquer est définie par un rectangle sur la surface au moyen des coordonnées du point en haut à gauche du rectangle, de la largeur et de la hauteur du rectangle.
 * \param surf la surface SDL dont on va appliquer une zone sur l'autre surface
 * \param screen la surface qui va recevoir une zone de l'autre surface
 * \param subposx l'absisse sur la surface surf du point en haut à gauche du rectangle définissant la zone à appliquer
 * \param subposy l'ordonnée sur la surface surf du point en haut à gauche du rectangle définissant la zone à appliquer
 * \param subwidth la largeur de la zone à appliquer
 * \param subheight la hauteur de la zone à appliquer
 * \param posx l'abscisse sur screen de l'endroit où appliquer la zone
 * \param posy l'ordonnée sur screen de l'endroit où appliquer la zone
 */


void apply_sub_surface(SDL_Surface* surf, SDL_Surface *screen, int subposx, int subposy, int subwidth, int subheight, int posx, int posy){
    
    //Apply image to screen
    SDL_Rect pos;
    pos.x = posx;
    pos.y = posy;
    
    SDL_Rect internal;
    internal.x = subposx;
    internal.y = subposy;
    internal.w = subwidth;
    internal.h = subheight;
    
    
    SDL_BlitSurface( surf, &internal, screen, &pos );
}


/**
 * \brief La fonction rafraichit une surface SDL
 * \param surf la surface SDL à rafraichir
 */

void refresh_surface(SDL_Surface *surf){
    SDL_UpdateRect(surf, 0, 0, 0, 0);
}


/**
 * \brief La fonction applique la transparence à une surface SDL pour une certaine couleur codée en RGB
 * \param screen surface correspondant à l'écran de jeu
 * \param surf surface sur laquelle on va appliquer la transparence
 * \param r la valeur RED du code RGB correspondant à la couleur que l'on veut rendre transparente sur la surface surf
 * \param g la valeur GREEN du code RGB correspondant à la couleur que l'on veut rendre transparente sur la surface surf
 * \param b la valeur BLUE du code RGB correspondant à la couleur que l'on veut rendre transparente sur la surface surf
 */

void  set_transparence(SDL_Surface *screen, SDL_Surface *surf, int r, int g, int b){
    SDL_SetColorKey(surf, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(screen->format, r, g, b)) ;
}








