#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#include "hero.h"
#include "background.h"
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
/** 
* @struct Ennemi 
* @brief struct for Ennemi
*/
typedef enum STATE STATE;
enum STATE {WAITING, FOLLOWING,ATTACKING};
typedef struct
{
    //SDL_Surface *surface;
    //SDL_Rect intervalle;
    //SDL_Rect posEnnemi; /*!< position ennemi*/
    /*SDL_Rect posMax;
    SDL_Rect posMin;
    SDL_Surface *tabMar1[7];
    SDL_Surface *tabMar2[7];
    SDL_Surface *tabDeg[7];
    SDL_Surface *tabAct[7];
    int frame1;
    int frame2;
    int frameAct;
    int frameDeg;
    int direction;
    int distance;*/
    SDL_Surface *sprite1;
    SDL_Surface *sprite2;
    SDL_Surface *sprite3;
    SDL_Surface *sprite4;
    SDL_Rect posEnnemi;
    SDL_Rect posMax;
    SDL_Rect posMin;
    SDL_Rect posSprite;
    SDL_Rect posSprite2;
    /*SDL_Rect posEnnemi1[6];
    SDL_Rect posMax1[6];
    SDL_Rect posMin1[6];*/
    int direction;//0:Droite 1:Gauche;
    STATE State;
} Ennemi;
/*typedef struct
{
  SDL_Surface *baguette1;
  SDL_Rect posbaguette1;
  SDL_Rect posbaguette2;
  SDL_Rect posbaguette3;
  SDL_Rect posbaguette4;
  SDL_Rect posbaguette5;
  SDL_Rect posbaguette6;
  SDL_Rect posbaguette7;
  SDL_Rect posbaguette8;
  SDL_Rect posbaguette9;
  SDL_Rect posbaguette10;
  SDL_Rect posbaguette11;
  SDL_Rect posbaguette12;
  SDL_Rect posbaguette13;
}baguette;*/
/*typedef struct
{
    SDL_Surface *imgbackground;
    SDL_Rect posbackground;
} back;
typedef struct
{
    SDL_Rect poshero;
    SDL_Surface *imageh;
} personne;*/
void initEnnemi(Ennemi*e);
void initEnnemi2(Ennemi *en1,Ennemi *en2);
//void initbaguette(baguette *bag);
/*void initback(back *b);
void initperso(personne *p);
void afficherback(back b,SDL_Surface *ecran);*/
void afficherEnnemi(Ennemi e,SDL_Surface *ecran,int multijoueur);
//void afficherBag(baguette bag, SDL_Surface *ecran);
//void afficherperso(personne p,SDL_Surface *ecran);
void animerEnnemi(Ennemi *e,int multijoueur);
void deplacer(Ennemi *e);
int collisionBB(perso p,Ennemi e,int collision);
void deplacerIA(Ennemi *e,perso p);
void update_ennemi(Ennemi* e, perso p);
void updateEnnemiState(Ennemi* e, int distEH);


#endif
