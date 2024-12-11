/** 
* @file main.c 
* @brief Testing Program. 
* @author C Team 
* @version 0.1 
* @date Apr 01, 2015 
* 
* Testing program for background scrollilng 
* 
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<time.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
#define TEMPS       30
#include "enigme.h"


void afficher_enigme2 ()
{
enigme3 e3;
score c;
   SDL_Surface *screen2=NULL;
 

SDL_Event event;
  
  int y;

  //Constantes
  const int fps=60;
  Uint32 start;

  //Init

  //Police_Init
  TTF_Init();
  if( TTF_Init() == -1 ) //police
  {
      printf( "Can't TTF:  %s\n", SDL_GetError( ) );
      
  }

  //Video_Init
  if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
  {
      printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
      
  }
  SDL_Surface * screen;
  screen = SDL_SetVideoMode( 1400, 800, 32, SDL_HWSURFACE | SDL_RESIZABLE);
  if( screen == NULL )
  {
      printf( "Can't set video mode: %s\n", SDL_GetError( ) );
      
  }

  //Enigme_Init
  enigme2 e2;
  initEnigme(&e2, "enigme.txt");

  //Images
  SDL_Surface * bg, *text_Resultat, *quitter , *continuer;
  bg = IMG_Load("Ressources/bg.png");
  SDL_Rect pos, boutons , boutons1;
  pos.x = 0;
  pos.y = 0;

  SDL_Color black = {0, 0, 0};
  SDL_Color white = {255, 255, 255};
  SDL_Color red = {187, 0, 0};
  TTF_Font *font;
  font = TTF_OpenFont("souls_font.ttf", 90);
  quitter = TTF_RenderText_Blended(font, "ESC - Quitter", black);
  continuer = TTF_RenderText_Blended(font,"Continuer ?", black);
  e2.font = font;


  //Controlleurs des boucles
  int quit;
  int jeu;
  int resultat;
  int exec = 1;

  

  int index = 0;
  int timeIndex = 0;
  int timer = 30;
  char conv[2];
  SDL_Surface *timing;
  SDL_Rect timePos;
  timePos.x = 1100;
  timePos.y = 250;
  int win;
  int i = 0;

  while(exec){

    quit = 0;
    jeu = 1;
    resultat = 1;
    win = 0;

    while((!quit)&&(jeu)){
      start=SDL_GetTicks();

      SDL_BlitSurface(bg, NULL, screen, &pos); //affichage
      e2.index = index;
      afficherEnigme(e2, screen);
      SDL_BlitSurface(e2.clock, &(e2.cadreClock), screen, &(e2.posClock));
      animer(&e2);

      if(SDL_GetTicks() >= 2500 + i * 2500){
        i++;
      }
      if(timer > 0){
        timer = 30-i;
      }
      if(timer <= 0){
        win = 0;
        jeu = 0;
      }
      sprintf(conv, "%d", timer); //Conversion entier -> chaine de caractère
      timing = TTF_RenderText_Blended(font, conv, white);
      SDL_BlitSurface(timing, NULL, screen, &timePos);

      while(SDL_PollEvent(&event)){ //input clavier + souris
        switch(event.type){
          case SDL_KEYUP:
            if(event.key.keysym.sym == SDLK_ESCAPE){ //échappe
              quit = 1;
              exec = 0;
            }
            if(event.key.keysym.sym == SDLK_UP){
              index--;
              if(index <= -1){
                index = 2;
              }
            }
            else if(event.key.keysym.sym == SDLK_DOWN){
              index++;
              if(index >= 3){
                index = 0;
              }
            }
            else if(event.key.keysym.sym == SDLK_RETURN){ //entrer
              if(index == e2.reponse){ //indice correcte?
                win = 1;
              }
              jeu = 0;
            }
            break;
          default:
            break;
        }
      }
      SDL_Flip(screen); //rafrichissement de l'ecran

      if(1000/fps>SDL_GetTicks()-start)
      {
      SDL_Delay( 1000/fps-(SDL_GetTicks()-start) );
      }
    }

    if(win){
      text_Resultat = TTF_RenderText_Blended(font, "Bonne reponse!", black);
    }
    else{
      text_Resultat = TTF_RenderText_Blended(font, "Mauvaise reponse :c", black);
    }

    while((!quit)&&(resultat)){
      start=SDL_GetTicks();

      SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); //fenetre blanche
      SDL_BlitSurface(text_Resultat, NULL, screen, &e2.posText);
      boutons.x = 300; //Coorodonnées quitter
      boutons.y = 450;
      boutons1.x = 300;
      boutons1.y = 600;
      SDL_BlitSurface(quitter, NULL, screen, &boutons);
       SDL_BlitSurface(continuer, NULL, screen, &boutons1);
      while(SDL_PollEvent(&event)){ //input clavier + souris
        switch(event.type){
          case SDL_KEYUP:
            if(event.key.keysym.sym == SDLK_ESCAPE){
              exec = 0;
              quit = 1;
              resultat = 0;
            }
		if(event.key.keysym.sym == SDLK_UP){
		generer2(&e3,"riddle.txt");
		afficher_menu(c,e3);	
		}
		
	    
            break;
          default:
            break;
        }
      }
      SDL_Flip(screen);

      if(1000/fps>SDL_GetTicks()-start)
      {
      SDL_Delay( 1000/fps-(SDL_GetTicks()-start) );
      }
    }
  }

  TTF_Quit();
  SDL_FreeSurface(screen);
  SDL_FreeSurface(bg);
  SDL_FreeSurface(text_Resultat);
  SDL_FreeSurface(quitter);
  SDL_FreeSurface(e2.option[0]);
  SDL_FreeSurface(e2.option[1]);
  SDL_FreeSurface(e2.option[2]);
  SDL_FreeSurface(e2.q);
  SDL_FreeSurface(e2.clock);
  SDL_QUIT;
  
}
