#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<time.h>
#include<string.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
#define TEMPS       30
#include <math.h>

#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
/** 
* @struct enigme 
* @brief struct for enigme 
*/
typedef struct {
  char question[500];

  char text[3][50]; //reponses
  SDL_Surface *q; //image qui va stocké la question

  //Les options
	SDL_Surface *option[3];

  //Les Images
  SDL_Surface *clock;

  SDL_Rect posClock; //Coorodonnées
  SDL_Rect cadreClock; //cadrage
  int frameh; //5
  int framev; //29


  SDL_Color white;
  SDL_Color red;
  TTF_Font * font; //Police

  //Coorodonnées
  SDL_Rect Pos[3]; //Coorodonnées réponses

  SDL_Rect posText; //Position de la question

  int reponse;
  int index;
}enigme2;

typedef struct 
{
	SDL_Surface *image[6],*anim[3],*sprite;   
	SDL_Surface *b;/*!< Surface. */
	SDL_Surface *answer,*answer1 ;
	SDL_Rect  posanswer, posscore, posimage1,posimage2,posimage3,posimage4, posbackground,posanim,posq;
	char solution1,solution2,solution3;
	int num_quest;
	int num_joueur;
	int score;
	SDL_Rect posq1;
	SDL_Colour color_txt;
	TTF_Font *police;
	SDL_Surface *quest;
	
}enigme3;
/**
* @struct Score
* @brief struct for score
*/
 typedef struct
{
	SDL_Surface *b;
	SDL_Surface *image[2];
	SDL_Rect posbackground,posnum,posscore;
}score;
/**
* @struct Texte
* @brief struct for texte
*/
typedef struct
{
    SDL_Surface *txt;
    SDL_Rect pos_txt;
    SDL_Colour color_txt;
    TTF_Font *police;
} texte;


void initEnigme(enigme2 * e2, char * nomfichier);
void afficherEnigme(enigme2 e2, SDL_Surface * screen);
void animer(enigme2 * e2);
void rotation_victoire(enigme3 e3);
void rotation_defeat (enigme3 e3);
void affich_enigme1(enigme3 e3,char *nomficher, score c);
void affich_enigme2(enigme3 e3,char *nomficher);
void affich_enigme3(enigme3 e3,char *nomficher);
void generer2(enigme3 *e3,char *nomfichier);

void afficher_menu(score c,enigme3 e3);
void sauvegarde (enigme3 e3);
void init_texte(enigme3 *e3);

void liberer_texte(enigme3 e3);
void afficher_score(enigme3 e3,score c);

#endif
