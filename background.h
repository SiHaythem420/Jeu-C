#ifndef BACKGROUNG_H_INCLUDED
#define BACKGROUNG_H_INCLUDED
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include "hero.h"
#include "ennemi.h"

typedef struct
{
  SDL_Surface *imgBack1;
  SDL_Rect posBack1;
  SDL_Rect scroll;
  SDL_Surface *imageM;
} Background;
void initBack(Background *b);
void afficherBack(Background b, SDL_Surface *ecran);
void afficherBack1(Background b, SDL_Surface *ecran);
void scrollingBack(Background *b, perso p,Input I);
void jumpin(perso *p,Input *I,Background *b,int multijoueur);
void gravity(perso *p,Input *I,Background *b,int multijoueur,Ennemi e);

typedef struct
{
SDL_Surface *minimap;
SDL_Surface *point;
SDL_Rect posminimap;
SDL_Rect pospoint;
}minimap;
void initmap( minimap * m); 
void afficherminimap (minimap m, SDL_Surface * screen);
void affichertemps (int temps, SDL_Surface * screen);
int collisionPP( perso p, SDL_Surface * Masque,Background b,Input I);
int collisionPP1( perso p, SDL_Surface * Masque,Background b,Input I);
//Tache blanche 
typedef struct 
{
int c;
int l;

}Casee ;
typedef struct 
{
    SDL_Surface *fond;
    SDL_Surface *jaune;
    SDL_Surface *rouge;
    SDL_Rect pos_rouge;

    SDL_Surface *j_g; 
    SDL_Surface *pc_g;
    SDL_Surface *gameover;
    SDL_Surface *fond_n;                 
   SDL_Rect pos;
    SDL_Rect pos_n; 
   SDL_Rect pos_ecran;


    TTF_Font *police;
}init;

Casee afficher_jeton(SDL_Surface *screen,init a,SDL_Event event,int t[6][7]);
Casee IA (int t [6][7]);
void afficher_jaune (SDL_Surface *screen,init a,Casee c);
int checkk (int t[7][7]);
void initi (init *a);
void afficherfond(SDL_Surface *ecran,init a);
void afficherpuis1(init a);
void afficherpuis2(init a);
void afficherpuis3(init a);
void afficherpuis4(init a);
void afficherpuis5(init a);
void afficherpuis6(init a);
void initBack1(Background *b);
void initBack2(Background *b);
#endif
