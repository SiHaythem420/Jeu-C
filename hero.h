#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <math.h>
/** 
* @struct hero
* @brief struct for perso 
*/ 

typedef struct
{int jumpspeed;
int jumpheight;
int gravity;
/*SDL_Rect posgagnant;
 SDL_Surface *victory;
    SDL_Surface *defeat;*/
    int X;
    int Y;
    int Y2; 
    SDL_Surface *tab1[7];
    SDL_Surface *tab2[7];
    SDL_Surface *tab3[7];
    SDL_Surface *tab4[7];
    SDL_Surface *tab5[7];
    SDL_Surface *tab6[7];
    SDL_Surface *tab7[7];
    SDL_Surface *tab8[7];
    SDL_Surface *imgscore;
    SDL_Surface *tabvie[8];
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int num6;
    int num7;
    int num8;
    int numvie;
    int frame;
    int frame1;
    int frame2;
    int frame3;
    int frame4;
    int frame5;
    int frame6;
    int frame7;
    int direction;
    SDL_Rect poshero;
    SDL_Rect posimgvie;
    SDL_Rect posimgscore;
} perso;

typedef struct
{
    SDL_Surface *imgbackground;
    SDL_Rect posbackground;
} back;

/** 
* @struct hero
* @brief struct for Input 
*/ 
	
typedef struct
{
    int left;
    int right;
    int jump;
    int fight;
    int fall;
} Input;

typedef struct{


SDL_Surface *background;

SDL_Surface *img3;
SDL_Surface *img4;
SDL_Surface *walk[8];



SDL_Rect posback;
SDL_Rect posimg;

float xvelocity,yvelocity; 
int frame,saut;
int direction; 
int tempsPrecedent ;
int tempsActuel ;
}personne;

void init_perso(personne *per);
void affich_perso(personne *per,SDL_Surface *ecran);
void initPerso(perso *p);
void initPerso2(perso *p);
//void init(back *b);
//void aff(back b, SDL_Surface *ecran);
void afficherPerso(perso p, SDL_Surface *ecran, int ts, int v, Input I,int multijoueur);
void mouvementright(perso *p);
void mouvementleft(perso *p);
void initialiser_input(Input *I);
void animerperso(perso *p, SDL_Surface *ecran, int v, Input *I);
void freesurface(perso *p);
//void saut(perso *p);
 




typedef struct
{    



  SDL_Surface *imgnewgame;
  SDL_Surface *imgloadgame;
  SDL_Surface *imgmultijoueur;
  SDL_Surface *imgnewgame2;
  SDL_Surface *imgloadgame2;
  SDL_Surface *imgmultijoueur2;
  SDL_Surface *ecran;
  SDL_Surface *imgplay;
  SDL_Surface *imgoption;
  SDL_Surface *imgbackground1;
  SDL_Surface *imgbackground2;
  SDL_Surface *imgbackground3;
  SDL_Surface *imgbackground4;
  SDL_Surface *imgbackground5;
  SDL_Surface *imgbackground6;
  SDL_Surface *imgbackground7;
  SDL_Surface *imgbackground8;
  SDL_Surface *imgbackground9;
  SDL_Surface *imgbackground10;
  SDL_Surface *imgbackground11;
  SDL_Surface *imgquit;
  SDL_Surface *imgcurseur;
  SDL_Surface *textecm;
  SDL_Surface *imgplay2;
  SDL_Surface *imgoption2;
  SDL_Surface *imgquit2;
  SDL_Surface *seq;
  SDL_Surface *imgv100;
  SDL_Surface *imgfullscreen;
  SDL_Surface *imgnormalscreen;
  SDL_Surface *imgfullscreen2;
  SDL_Surface *imgnormalscreen2;
  SDL_Surface *imgtxtaffichaage;
  SDL_Surface *imgtxtvolume;
  SDL_Surface *imgoption3;
  SDL_Surface *imgv0;
  SDL_Surface *imgv25;
  SDL_Surface *imgv75;
  SDL_Surface *imgv50;
  SDL_Surface *imgicon;
  SDL_Surface *imgbackfull;
  SDL_Surface *imgbackloading;
  SDL_Rect posplay;
  SDL_Rect posoption;
  SDL_Rect posbackground;
  SDL_Rect posbackground1;
  SDL_Rect posbackground2;
  SDL_Rect posquit;
  SDL_Rect poscurseur;
  SDL_Rect postextecm;
  SDL_Rect posvolume;
  SDL_Rect posvolume2;
  SDL_Rect posfullscreen;
  SDL_Rect posnormalscreen;
  SDL_Rect postextevolume;
  SDL_Rect posaffichage;
  SDL_Rect posoption2;
  SDL_Rect posnewgame;
  SDL_Rect posloadgame;
  SDL_Rect posmultijoueur;
  Mix_Music *musique;
  Mix_Chunk *son;
  int frame;
} menu;


typedef struct{
   SDL_Surface *victory;
    SDL_Surface *defeat;
    SDL_Rect posvictory;
    SDL_Rect posdefeat;
  SDL_Surface *victory2;
    SDL_Surface *defeat2;
    SDL_Rect posvictory2;
    SDL_Rect posdefeat2;
    SDL_Rect posvictory3;
    SDL_Rect posdefeat3;

}vod;
void init_vod(vod *vicde);
void affichervictory_defeat0(vod vicde,int ts,int v,int temps,perso p,SDL_Surface *ecran);
void affichervictory_defeat1(vod vicde,int ts,int v,int ts1,int v1,int ts2,int v2,int temps,SDL_Surface *ecran,perso p1,perso p2);



/////khedmet mahmoudd////
typedef struct 

{




  SDL_Rect posinput;
  SDL_Rect posinput2;
  SDL_Rect posinputA;
  SDL_Rect posinputA2;
 SDL_Rect posinputB;
  SDL_Rect posinputB2;

 SDL_Surface *imginput;
  SDL_Surface *imginput2;
  SDL_Surface *imginputA;
  SDL_Surface *imginputA2;
 SDL_Surface *imginputB;
  SDL_Surface *imginputB2;

 SDL_Surface *imginputAselected;
  SDL_Surface *imginputBselected;




SDL_Rect postext1;
 SDL_Rect postext2;




}changeinput;

void intialiser(menu *m,changeinput *inp);
void affichage(int interface, int y, int f, int k, menu m, SDL_Surface *ecran, int n,changeinput inp,int chinp);
void animation(menu m);
void affichagemenuanim (menu m, SDL_Surface *ecran,int *continuer);
void initanim(SDL_Surface *imgbackground[]);
void motion(int *page,int *continuer, menu m);
void afficherdefeat(perso p, SDL_Surface *ecran, int ts, int v, Input I, int multijoueur);
void affichervictory(perso p, SDL_Surface *ecran, int ts, int v, Input I, int multijoueur);
void freemenu(menu *m);



#endif
