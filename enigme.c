/** 
* @file main.c 
* @brief Testing Program. 
* @author C Team 
* @version 0.1 
* @date Apr 01, 2015 
* 
* Testing program for enigme scrollilng 
* 
*/
/** 
* @file enigme.c 
*/ 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<time.h>
#include<string.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
#define TEMPS       30
#include<time.h>
#include "enigme.h"
/** 
* @brief To initialize the enigme b . 
* @param b the enigme
* @param url the url of the image 
* @return Nothing 
*/ 

void initEnigme(enigme2 * e2, char * nomfichier){

  char tmp[500];
  int random;
  FILE * file;
  file = NULL;
  file = fopen(nomfichier, "r"); // r->read


  if(file != NULL){
    e2->white.r = 255;
    e2->white.g = 255;
    e2->white.b = 255;
    e2->red.r = 212;
    e2->red.g = 212;
    e2->red.b = 0;

    srand(time(0));
    random = rand() % 3; //Aleatoire [0-2]

    int i = -1;
    do{
      if(i == random - 1){
        fgets(e2->question, 200, file);
      }
      else{
        fgets(tmp, 200, file);
      }
      i++;
    }while(i < 2);

    i = -1;

    do{
      fscanf(file, "%s %s %s %d", e2->text[0], e2->text[1], e2->text[2], &(e2->reponse));
      i++;
    }while(i < random);

    e2->clock = IMG_Load("Ressources/clock.png");
    e2->frameh = 0;
    e2->framev = 0;
    e2->posClock.x = 1200;
    e2->posClock.y = 200;
    e2->cadreClock.x = 0;
    e2->cadreClock.y = 0;
    e2->cadreClock.h = 145; //hauteur
    e2->cadreClock.w = 145; //largeur

    e2->Pos[0].x = 300;
    e2->Pos[0].y = 200;
    e2->Pos[1].x = 300;
    e2->Pos[1].y = 400;
    e2->Pos[2].x = 300;
    e2->Pos[2].y = 600;

    e2->posText.x = 300;
    e2->posText.y = 50;
  }
  else{
    printf("%s\n", SDL_GetError( ));
  }
}
/** 
* @brief To show the enigme b . 
* @param scren the screen 
* @param b the enigme 
* @return Nothing 
*/ 
void afficherEnigme(enigme2 e2, SDL_Surface * screen){

  e2.q = TTF_RenderText_Blended(e2.font, e2.question, e2.white); //Conversion chaine -> image
  SDL_BlitSurface(e2.q, NULL, screen, &e2.posText); //Affichage (image, cadrage, fenetre, Coorodonnées)

  for(int i = 0; i < 3; i++){
    if(e2.index == i){
        e2.option[i] = TTF_RenderText_Blended(e2.font, e2.text[i], e2.red);
    }
    else{
      e2.option[i] = TTF_RenderText_Blended(e2.font, e2.text[i], e2.white);
    }
    SDL_BlitSurface(e2.option[i], NULL, screen, &e2.Pos[i]);
  }
}
/** 
* @brief To scroll the enigme to the left . 
* @param b the enigme 
* @return Nothing 
*/

void animer(enigme2 * e2){
  e2->frameh++;
  if((e2->framev == 28)&&(e2->frameh >= 3)){
    e2->frameh = 0;
    e2->framev = 0;
  }
  if(e2->frameh >= 5){
    e2->frameh = 0;
    e2->framev++;
  }

  if(e2->framev >= 29){
    e2->framev = 0;
  }

  e2->cadreClock.x = e2->frameh * 145;
  e2->cadreClock.y = e2->framev * 145;
}
/** 
* @brief To scroll the enigme to the right . 
* @param b the enigme 
* @return Nothing 
*/ 


void rotation_victoire(enigme3 e3)
{

Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,2,1024);
Mix_Music *music2 = Mix_LoadMUS("win.mp3");
	Mix_PlayMusic(music2,-1);
SDL_Surface *ecran = NULL, *image = NULL, *rotation = NULL;
    SDL_Rect rect;
    SDL_Event event;
    double angle = 0;
 
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(400, 400, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Faire des rotations avec SDL_gfx", NULL);
 
    image = IMG_Load("wp.jpeg");
 
    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
 
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > TEMPS)
        {
            angle += 2; 
 
            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));
        }
 
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 
        rotation = rotozoomSurface(image, angle, 1.0, 1); 
 
        
        rect.x =  200 - rotation->w / 2;
        rect.y =  200 - rotation->h / 2;
 
        SDL_BlitSurface(rotation , NULL, ecran, &rect); 
        SDL_FreeSurface(rotation);  
 
        SDL_Flip(ecran);
    }
 
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(image);
Mix_FreeMusic(music2);
Mix_CloseAudio();
    SDL_Quit();
    sauvegarde (e3);
}

/**
* @brief To initialise and show the animation of defeat .
* @param e the enigme
* @return Nothing
*/
void rotation_defeat (enigme3 e3)
{
SDL_Surface *ecran = NULL, *image = NULL, *rotation = NULL;
    SDL_Rect rect;
    SDL_Event event;
    double angle = 0;
 
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(400, 400, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Faire des rotations avec SDL_gfx", NULL);
 
    image = IMG_Load("ulost.png");
 
    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
 
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > TEMPS)
        {
            angle += 2; 
 
            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));
        }
 
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 
        rotation = rotozoomSurface(image, angle, 1.0, 1); 
 
       
        rect.x =  200 - rotation->w / 2;
        rect.y =  200 - rotation->h / 2;
 
        SDL_BlitSurface(rotation , NULL, ecran, &rect); 
        SDL_FreeSurface(rotation);  
 
        SDL_Flip(ecran);
    }
 
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(image);
    SDL_Quit();
    sauvegarde (e3);
}

/**
* @brief To initialise and show the first enigme .
* @param e the enigme
* @param nomfichier the file
* @param c the score
* @return Nothing
*/
void affich_enigme1(enigme3 e3,char *nomficher , score c)
{

int score1;
Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,2,1024);
Mix_Music *music1 = Mix_LoadMUS("question.mp3");
Mix_PlayMusic(music1, -1);
SDL_Surface *screen=NULL;
SDL_Surface *ecran=NULL;

int x1 = 2;
int score = 20;

SDL_Event event;

 if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
  {
    printf("unable to set Initialize SDL : %s/n", SDL_GetError());
    
  }

  screen = SDL_SetVideoMode(1920, 950, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (screen == NULL)
  {
    printf("unable to set  video mode : %s/n", SDL_GetError());
    
  } 

  e3.b = IMG_Load("riddle.png");
  e3.image[1] = IMG_Load("caesar.png");

  e3.image[2] = IMG_Load("100.png");
  e3.image[4] = IMG_Load("30.png");
  e3.image[5] = IMG_Load("0.png");
  e3.image[6] = IMG_Load("hannibal.png");
  e3.image[7] = IMG_Load("diogenes.png");
  e3.image[8] = IMG_Load("question1.png");
  


e3.posbackground.x = 0;
  e3.posbackground.y = 0;
  e3.posscore.x = 0;
  e3.posscore.y = 0;
 
  e3.posimage1.x = 1400;
  e3.posimage1.y =300;
  e3.posimage2.x = 800;
  e3.posimage2.y =300;
  e3.posimage3.x = 200;
  e3.posimage3.y =300;
  e3.posimage4.x = 750;
  e3.posimage4.y = 800;
SDL_BlitSurface(e3.b, NULL, screen, &e3.posbackground);
SDL_Flip(screen);
SDL_BlitSurface(e3.image[1], NULL, screen, &e3.posimage1);
SDL_Flip(screen);
SDL_BlitSurface(e3.image[6], NULL, screen, &e3.posimage2);
SDL_Flip(screen);
SDL_BlitSurface(e3.image[7], NULL, screen, &e3.posimage3);
SDL_Flip(screen);
SDL_BlitSurface(e3.image[8], NULL, screen, &e3.posimage4);
SDL_Flip(screen);

    
   int done = 1; 


FILE* correct;
correct =  fopen("correct", "r");

if (correct == NULL)
    {
       printf("le fichier n'exister pas");
       
    }


if (correct !=NULL)
{
char juste[5];

fscanf(correct,"%s",juste);


do{


while (SDL_WaitEvent(&event)&& (done==1))
	
  {


switch (event.type)
    {
    case SDL_QUIT:
    {
    done=0;
    SDL_Quit();
    break;
    } 
						
    case SDL_MOUSEBUTTONUP:
    {
    	if((event.motion.x>1400)&&(event.motion.x<1800)&&(event.motion.y>300)&&(event.motion.y<750))
    	{
    		
    	  
   	e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	x1 = x1 - 1;
	score = score - 10;
    	}
    	
    	
    	
    	if((event.motion.x>200)&&(event.motion.x<600)&&(event.motion.y>300)&&(event.motion.y<750))
    	{
    	
     		e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
        x1 = x1 - 1;
	score = score - 10;
    	}
    	if((event.motion.x>800)&&(event.motion.x<1200)&&(event.motion.y>300)&&(event.motion.y<750))
    	{
	 e3.score=100;
    	Mix_HaltMusic();
	Mix_Music *music2 = Mix_LoadMUS("win.mp3");
	Mix_PlayMusic(music2,-1);
	rotation_victoire(e3);
	
        SDL_Flip(screen);
       
	SDL_Delay(1000);
	SDL_Quit();
    	}
    	
    }

    case SDL_KEYDOWN:
    {

      if ((event.key.keysym.sym == SDLK_a))
      {
      
      
	  if (juste[0]!='A'){
        e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
        
	x1 = x1 - 1;
	score = score - 10;
	SDL_Delay(500);   
	SDL_FreeSurface(e3.answer);
	  }

	 else {
	 e3.score=100;
	Mix_HaltMusic();
Mix_Music *music2 = Mix_LoadMUS("win.mp3");
Mix_PlayMusic(music2,-1);
	rotation_victoire(e3);
        e3.answer = IMG_Load("correct.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	score = score + 100;
	
	SDL_Delay(1500);   
	SDL_FreeSurface(e3.answer);
	
	SDL_Quit();
	  }
	

     
        
       
      }

      if ((event.key.keysym.sym == SDLK_b))
      {

        if (juste[0]!='B'){
        e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	x1 = x1 - 1;
	score = score - 10;
	SDL_Delay(500);   
	SDL_FreeSurface(e3.answer);
	  }
	 else {
	 e3.score=100;
	Mix_HaltMusic();
Mix_Music *music2 = Mix_LoadMUS("win.mp3");
Mix_PlayMusic(music2,-1);
	rotation_victoire(e3);
        e3.answer = IMG_Load("correct.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	score = score + 100;
	
	SDL_Delay(1500);   
	SDL_FreeSurface(e3.answer);
	SDL_Quit();
	  }
	
        
        
      }

      if ((event.key.keysym.sym == SDLK_c))
      {

        if (juste[0]!='C'){
        e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	x1 = x1 - 1;
	score = score - 10;
	SDL_Delay(500);   
	SDL_FreeSurface(e3.answer);
	  }
	  
	 else {
	 e3.score=100;
	rotation_victoire(e3);
	Mix_HaltMusic();
Mix_Music *music2 = Mix_LoadMUS("win.mp3");
Mix_PlayMusic(music2,-1);
        e3.answer = IMG_Load("correct.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	score = score + 100;
	
	SDL_Delay(1500);   
	SDL_FreeSurface(e3.answer);
	SDL_Quit();
	  }
	
        
      }
     

      if (event.key.keysym.sym == SDLK_ESCAPE)
      {
        done = 0;
	SDL_Quit();

      }
	if (event.key.keysym.sym == SDLK_d)
	{

	SDL_Quit();
	
	
	}
      break;
    }
    }

    if (x1 == 2)
    {
	
      SDL_BlitSurface(e3.image[2], NULL, screen, &e3.posscore);
      SDL_Flip(screen);
    }
    if (x1 == 1)
    {
      SDL_BlitSurface(e3.image[4], NULL, screen, &e3.posscore);
      SDL_Flip(screen);
    }
    if (x1 == 0)
    {
Mix_HaltMusic();
	Mix_Music *music3 = Mix_LoadMUS("lose.mp3");
	Mix_PlayMusic(music3,-1);
    	e3.posanswer.x = 190;
        e3.posanswer.y = 0;
      SDL_BlitSurface(e3.image[5], NULL, screen, &e3.posscore);
      SDL_Flip(screen);
	e3.score=0;
      rotation_defeat (e3);

	
	

    }

  }
}  while (done==1);}

fclose(correct);

  
  SDL_FreeSurface(e3.image[1]);
	SDL_FreeSurface(e3.image[2]);
	SDL_FreeSurface(e3.image[3]);
	SDL_FreeSurface(e3.image[4]);
	SDL_FreeSurface(e3.image[5]);
	SDL_FreeSurface(e3.image[0]);
  SDL_FreeSurface(e3.b);
SDL_FreeSurface(c.b);
SDL_FreeSurface(e3.answer);
Mix_CloseAudio();
  
}



/**
* @brief To initialise and show the second enigme .
* @param e the enigme
* @param nomfichier the file
* @return Nothing
*/

void affich_enigme2(enigme3 e3,char *nomficher)
{
Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,2,1024);
Mix_Music *music1 = Mix_LoadMUS("question.mp3");
Mix_PlayMusic(music1, -1);
SDL_Surface *screen=NULL;
 
int x1 = 2;
  

SDL_Event event;

 if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
  {
    printf("unable to set Initialize SDL : %s/n", SDL_GetError());
    
  }

  screen = SDL_SetVideoMode(1920, 950, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (screen == NULL)
  {
    printf("unable to set  video mode : %s/n", SDL_GetError());
    
  } 

  e3.b = IMG_Load("riddle.png");
  e3.image[1] = IMG_Load("rome.png");

  e3.image[2] = IMG_Load("100.png");
  e3.image[4] = IMG_Load("30.png");
  e3.image[5] = IMG_Load("0.png");
  e3.image[6] = IMG_Load("carthage.png");
  e3.image[7] = IMG_Load("greece.png");
  e3.image[8] = IMG_Load("question2.png");
  


e3.posbackground.x = 0;
  e3.posbackground.y = 0;
  e3.posscore.x = 0;
  e3.posscore.y = 0;
 
  e3.posimage1.x = 1400;
  e3.posimage1.y =300;
  e3.posimage2.x = 800;
  e3.posimage2.y =300;
  e3.posimage3.x = 200;
  e3.posimage3.y =300;
  e3.posimage4.x = 750;
  e3.posimage4.y = 800;
SDL_BlitSurface(e3.b, NULL, screen, &e3.posbackground);
SDL_Flip(screen);
SDL_BlitSurface(e3.image[1], NULL, screen, &e3.posimage1);
SDL_Flip(screen);
SDL_BlitSurface(e3.image[6], NULL, screen, &e3.posimage2);
SDL_Flip(screen);
SDL_BlitSurface(e3.image[7], NULL, screen, &e3.posimage3);
SDL_Flip(screen);
SDL_BlitSurface(e3.image[8], NULL, screen, &e3.posimage4);
SDL_Flip(screen);

    
   int done = 1; 


FILE* correct;
correct =  fopen("correct", "r");

if (correct == NULL)
    {
       printf("le fichier n'exister pas");
       
    }


if (correct !=NULL)
{
char juste[5];

fscanf(correct,"%s",juste);


do{


while (SDL_WaitEvent(&event)&& (done==1))
	
  {


switch (event.type)
    {
    case SDL_QUIT:
    {
    done=0;
    SDL_Quit();
    break;
    } 
						
    case SDL_MOUSEBUTTONUP:
    {
    	if((event.motion.x>1400)&&(event.motion.x<1800)&&(event.motion.y>300)&&(event.motion.y<750))
    	{
    		
    	  
   	e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	x1 = x1 - 1;
	
    	}
    	
    	
    	
    	if((event.motion.x>200)&&(event.motion.x<600)&&(event.motion.y>300)&&(event.motion.y<750))
    	{
    	
     		e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
        x1 = x1 - 1;
    	}
    	if((event.motion.x>800)&&(event.motion.x<1200)&&(event.motion.y>300)&&(event.motion.y<750))
    	{
	e3.score=100;
    	Mix_HaltMusic();
Mix_Music *music2 = Mix_LoadMUS("win.mp3");
Mix_PlayMusic(music2,-1);
rotation_victoire(e3);
	e3.answer = IMG_Load("correct.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
        
	SDL_Delay(1000);
	SDL_Quit();
    	}
    	
    }

    case SDL_KEYDOWN:
    {

      if ((event.key.keysym.sym == SDLK_a))
      {
      
      
	  if (juste[0]!='A'){
        e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
        
	x1 = x1 - 1;
	SDL_Delay(500);   
	SDL_FreeSurface(e3.answer);
	  }

	 else {
	e3.score=100;
	Mix_HaltMusic();
Mix_Music *music2 = Mix_LoadMUS("win.mp3");
Mix_PlayMusic(music2,-1);
rotation_victoire(e3);
        e3.answer = IMG_Load("correct.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	
	SDL_Delay(1500);   
	SDL_FreeSurface(e3.answer);
	
	SDL_Quit();
	  }
	

     
        
       
      }

      if ((event.key.keysym.sym == SDLK_b))
      {

        if (juste[0]!='B'){
        e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	x1 = x1 - 1;
	SDL_Delay(500);   
	SDL_FreeSurface(e3.answer);
	  }
	 else {
	Mix_HaltMusic();
e3.score=100;
Mix_Music *music2 = Mix_LoadMUS("win.mp3");
Mix_PlayMusic(music2,-1);
rotation_victoire(e3);
        e3.answer = IMG_Load("correct.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	
	SDL_Delay(1500);   
	SDL_FreeSurface(e3.answer);
	SDL_Quit();
	  }
	
        
        
      }

      if ((event.key.keysym.sym == SDLK_c))
      {

        if (juste[0]!='C'){
        e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	x1 = x1 - 1;
	SDL_Delay(500);   
	SDL_FreeSurface(e3.answer);
	  }
	  
	 else {
e3.score=100;
	Mix_HaltMusic();
Mix_Music *music2 = Mix_LoadMUS("win.mp3");
Mix_PlayMusic(music2,-1);
rotation_victoire(e3);
        e3.answer = IMG_Load("correct.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	
	SDL_Delay(1500);   
	SDL_FreeSurface(e3.answer);
	SDL_Quit();
	  }
	
        
      }
      

      if (event.key.keysym.sym == SDLK_ESCAPE)
      {
        done = 0;
	SDL_Quit();

      }
      break;
    }
    }

    if (x1 == 2)
    {
      SDL_BlitSurface(e3.image[2], NULL, screen, &e3.posscore);
      SDL_Flip(screen);
    }
    if (x1 == 1)
    {
      SDL_BlitSurface(e3.image[4], NULL, screen, &e3.posscore);
      SDL_Flip(screen);
    }
    if (x1 == 0)
    {
e3.score=0;
Mix_HaltMusic();
	Mix_Music *music3 = Mix_LoadMUS("lose.mp3");
	Mix_PlayMusic(music3,-1);
    	e3.posanswer.x = 190;
        e3.posanswer.y = 0;
      SDL_BlitSurface(e3.image[5], NULL, screen, &e3.posscore);
      SDL_Flip(screen);
rotation_defeat (e3);

    }

  }
}  while (done==1);}

fclose(correct);

    
  
  SDL_FreeSurface(e3.image[1]);
	SDL_FreeSurface(e3.image[2]);
	SDL_FreeSurface(e3.image[3]);
	SDL_FreeSurface(e3.image[4]);
	SDL_FreeSurface(e3.image[5]);
	SDL_FreeSurface(e3.image[0]);
  SDL_FreeSurface(e3.b);
SDL_FreeSurface(e3.answer);

  
}


/**
* @brief To initialise and show the third enigme .
* @param e the enigme
* @param nomfichier the file
* @return Nothing
*/

void affich_enigme3(enigme3 e3,char *nomficher)
{
 Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,2,1024);
Mix_Music *music1 = Mix_LoadMUS("question.mp3");
Mix_PlayMusic(music1, -1);
SDL_Surface *screen=NULL;
 
int x1 = 2;
  

SDL_Event event;

 if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
  {
    printf("unable to set Initialize SDL : %s/n", SDL_GetError());
    
  }

  screen = SDL_SetVideoMode(1920, 950, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (screen == NULL)
  {
    printf("unable to set  video mode : %s/n", SDL_GetError());
    
  } 

  e3.b = IMG_Load("riddle.png");
  e3.image[1] = IMG_Load("notredame.png");

  e3.image[2] = IMG_Load("100.png");
  e3.image[4] = IMG_Load("30.png");
  e3.image[5] = IMG_Load("0.png");
  e3.image[6] = IMG_Load("pyramids.png");
  e3.image[7] = IMG_Load("maya.png");
  e3.image[8] = IMG_Load("question3.png");
  


e3.posbackground.x = 0;
  e3.posbackground.y = 0;
  e3.posscore.x = 0;
  e3.posscore.y = 0;
 
  e3.posimage1.x = 1400;
  e3.posimage1.y =300;
  e3.posimage2.x = 800;
  e3.posimage2.y =300;
  e3.posimage3.x = 200;
  e3.posimage3.y =300;
  e3.posimage4.x = 750;
  e3.posimage4.y = 800;
SDL_BlitSurface(e3.b, NULL, screen, &e3.posbackground);
SDL_Flip(screen);
SDL_BlitSurface(e3.image[1], NULL, screen, &e3.posimage1);
SDL_Flip(screen);
SDL_BlitSurface(e3.image[6], NULL, screen, &e3.posimage2);
SDL_Flip(screen);
SDL_BlitSurface(e3.image[7], NULL, screen, &e3.posimage3);
SDL_Flip(screen);
SDL_BlitSurface(e3.image[8], NULL, screen, &e3.posimage4);
SDL_Flip(screen);

    
   int done = 1; 


FILE* correct;
correct =  fopen("correct", "r");

if (correct == NULL)
    {
       printf("le fichier n'exister pas");
       
    }


if (correct !=NULL)
{
char juste[5];

fscanf(correct,"%s",juste);


do{


while (SDL_WaitEvent(&event)&& (done==1))
	
  {


switch (event.type)
    {
    case SDL_QUIT:
    {
    done=0;
    SDL_Quit();
    break;
    } 
						
    case SDL_MOUSEBUTTONUP:
    {
    	if((event.motion.x>1400)&&(event.motion.x<1800)&&(event.motion.y>300)&&(event.motion.y<750))
    	{
    		
    	  
   	e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	x1 = x1 - 1;
	
    	}
    	
    	
    	
    	if((event.motion.x>200)&&(event.motion.x<600)&&(event.motion.y>300)&&(event.motion.y<750))
    	{
    	
     		e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
        x1 = x1 - 1;
    	}
    	if((event.motion.x>800)&&(event.motion.x<1200)&&(event.motion.y>300)&&(event.motion.y<750))
    	{
e3.score=100;
    	Mix_HaltMusic();
Mix_Music *music2 = Mix_LoadMUS("win.mp3");
Mix_PlayMusic(music2,-1);
rotation_victoire(e3);
	e3.answer = IMG_Load("correct.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
        
	SDL_Delay(1000);
	SDL_Quit();
    	}
    	
    }

    case SDL_KEYDOWN:
    {

      if ((event.key.keysym.sym == SDLK_a))
      {
      
      
	  if (juste[0]!='A'){
        e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
        
	x1 = x1 - 1;
	SDL_Delay(500);   
	SDL_FreeSurface(e3.answer);
	  }

	 else {
e3.score=100;
	Mix_HaltMusic();
Mix_Music *music2 = Mix_LoadMUS("win.mp3");
Mix_PlayMusic(music2,-1);
rotation_victoire(e3);
        e3.answer = IMG_Load("correct.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	
	SDL_Delay(1500);   
	SDL_FreeSurface(e3.answer);
	
	SDL_Quit();
	  }
	

     
        
       
      }

      if ((event.key.keysym.sym == SDLK_b))
      {

        if (juste[0]!='B'){
        e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	x1 = x1 - 1;
	SDL_Delay(500);   
	SDL_FreeSurface(e3.answer);
	  }
	 else {
e3.score=100;
	Mix_HaltMusic();
Mix_Music *music2 = Mix_LoadMUS("win.mp3");
Mix_PlayMusic(music2,-1);
rotation_victoire(e3);
        e3.answer = IMG_Load("correct.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	
	SDL_Delay(1500);   
	SDL_FreeSurface(e3.answer);
	SDL_Quit();
	  }
	
        
        
      }

      if ((event.key.keysym.sym == SDLK_c))
      {

        if (juste[0]!='C'){
        e3.answer = IMG_Load("wrong.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	x1 = x1 - 1;
	SDL_Delay(500);   
	SDL_FreeSurface(e3.answer);
	  }
	  
	 else {
e3.score=100;
	Mix_HaltMusic();
Mix_Music *music2 = Mix_LoadMUS("win.mp3");
Mix_PlayMusic(music2,-1);
rotation_victoire(e3);
        e3.answer = IMG_Load("correct.png");
        e3.posanswer.x = 750;
        e3.posanswer.y = 0;
        SDL_BlitSurface(e3.answer, NULL, screen, &e3.posanswer);
        SDL_Flip(screen);
	
	SDL_Delay(1500);   
	SDL_FreeSurface(e3.answer);
	SDL_Quit();
	  }
	
        
      }
     

      if (event.key.keysym.sym == SDLK_ESCAPE)
      {
        done = 0;
	SDL_Quit();

      }
      break;
    }
    }

    if (x1 == 2)
    {
      SDL_BlitSurface(e3.image[2], NULL, screen, &e3.posscore);
      SDL_Flip(screen);
    }
    if (x1 == 1)
    {
      SDL_BlitSurface(e3.image[4], NULL, screen, &e3.posscore);
      SDL_Flip(screen);
    }
    if (x1 == 0)
    {
	e3.score=0;
    	Mix_HaltMusic();
	Mix_Music *music3 = Mix_LoadMUS("lose.mp3");
	Mix_PlayMusic(music3,-1);
    	e3.posanswer.x = 190;
        e3.posanswer.y = 0;
      SDL_BlitSurface(e3.image[5], NULL, screen, &e3.posscore);
      SDL_Flip(screen);
rotation_defeat (e3);
    }
  }
}  while (done==1);}

fclose(correct);

    
  
  SDL_FreeSurface(e3.image[1]);
	SDL_FreeSurface(e3.image[2]);
	SDL_FreeSurface(e3.image[3]);
	SDL_FreeSurface(e3.image[4]);
	SDL_FreeSurface(e3.image[5]);
	SDL_FreeSurface(e3.image[0]);
  SDL_FreeSurface(e3.b);
SDL_FreeSurface(e3.answer);




 
}

/**
* @brief To generate a random enigme .
* @param e the enigme
* @param nomfichier the file
* @return Nothing
*/

void generer2(enigme3 *e3,char *nomfichier)
{
FILE *fichier=NULL;
fichier = fopen(nomfichier,"r");
if (fichier == NULL)
{
printf("Erreur : impossible d'ouvrir le fichier \n");
exit(1);
}
int alea;
srand(time(NULL));
alea = rand() % 3 + 1;
e3->num_quest = alea;
fclose(fichier);
}





/**
* @brief To initialise and show the menu .
* @param e the enigme
* @param c the score
* @return Nothing
*/
void afficher_menu(score c,enigme3 e3)
{
SDL_Event event;
texte txte;
Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,2,1024);
Mix_Music *music1 = Mix_LoadMUS("home.mp3");
Mix_PlayMusic(music1, -1);
SDL_Surface *ecran=NULL;
SDL_Init(SDL_INIT_VIDEO);

ecran = SDL_SetVideoMode(1920, 950, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	c.b = IMG_Load("theatre.png");
	c.posbackground.x=0;
	c.posbackground.y=0;
	SDL_BlitSurface(c.b, NULL, ecran, &c.posbackground);
   	c.image[1] = IMG_Load("number.png");
	c.image[2] = IMG_Load ("score.png");
	c.posnum.x=800;
	c.posnum.y=100;
	c.posscore.x=800;
	c.posscore.y=300;
	SDL_BlitSurface(c.image[1], NULL, ecran, &c.posnum);
	SDL_BlitSurface(c.image[2], NULL, ecran, &c.posscore);
	
	SDL_Flip(ecran);

 generer2(&e3,"riddle.txt");

while (SDL_WaitEvent(&event))
{
switch(event.type)
{
case SDL_MOUSEBUTTONDOWN:
if (event.motion.x>=800 && event.motion.x<=1100 && event.motion.y>= 300 && event.motion.y<=413)
{
afficher_score(e3, c);
}
case SDL_KEYDOWN:
if (event.key.keysym.sym == SDLK_ESCAPE)
      {
        
	SDL_Quit();

      }
if (event.key.keysym.sym == SDLK_d)
  {
	afficher_score(e3, c);
	
  }
if (event.key.keysym.sym == SDLK_r)
{
afficher_menu(c,e3);
}

if (event.key.keysym.sym == SDLK_a)
{
  e3.num_joueur=1;
  switch(e3.num_quest)
  {
  case 1: 
	affich_enigme1(e3,"correct",c);
	
  break;
  case 2: 
		
	affich_enigme2(e3,"correct");
  break;
  case 3:
	affich_enigme3(e3,"correct");
  break;

  }
}
if (event.key.keysym.sym == SDLK_b)
{
e3.num_joueur=2;
switch(e3.num_quest)
  {
  case 1: 
	affich_enigme1(e3,"correct",c);
  break;
  case 2: 
		
	affich_enigme2(e3,"correct");
  break;
  case 3:
	affich_enigme3(e3,"correct");
  break;

  }
}
if (event.key.keysym.sym == SDLK_c)
{
e3.num_joueur=3;
switch(e3.num_quest)
  {
  case 1: 
	affich_enigme1(e3,"correct",c);
  break;
  case 2: 
		
	affich_enigme2(e3,"correct");
  break;
  case 3:
	affich_enigme3(e3,"correct");
  break;

  }
}
}
}

	
	
	

}
/**
* @brief To save the score .
* @param e the enigme
* @return Nothing
*/
void sauvegarde (enigme3 e3)
{
FILE *fichier = NULL;
fichier=fopen("score","a");
if(fichier!=NULL)
{
fprintf(fichier,"joueur numero %d a un score%d\n",e3.num_joueur,e3.score);
}
fclose(fichier);
}

void init_texte(enigme3 *e3)
{
TTF_Init();
e3->police = TTF_OpenFont("ff.ttf", 50);
    if (e3->police == NULL)
    {
        printf("error loading son bref%s \n", SDL_GetError());
        
    }
    e3->color_txt.r = 192;
    e3->color_txt.g = 192;
    e3->color_txt.b = 192;

}


/**
* @brief To liberate the text .
* @param e the enigme
* @return Nothing
*/
void liberer_texte(enigme3 e3)
{
    TTF_CloseFont(e3.police);
    TTF_Quit();
}

/**
* @brief To show the score .
* @param e the enigme
* @param c the score
* @return Nothing
*/
void afficher_score(enigme3 e3,score c)
{
SDL_Event event;
texte txte;
Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,2,1024);
Mix_Music *music1 = Mix_LoadMUS("home.mp3");
Mix_PlayMusic(music1, -1);
SDL_Surface *ecran=NULL;
SDL_Init(SDL_INIT_VIDEO);

ecran = SDL_SetVideoMode(1920, 950, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	c.b = IMG_Load("score(1).png");
	c.posbackground.x=0;
	c.posbackground.y=0;
	SDL_BlitSurface(c.b, NULL, ecran, &c.posbackground);
   	
	init_texte(&e3);
	char ligne[100];
    FILE *fichier=NULL;
    fichier=fopen("score","r");
	int y=100;
    while (fgets(ligne,sizeof(ligne),fichier)!= NULL){ 
    e3.quest = TTF_RenderText_Blended(e3.police, ligne, e3.color_txt);
    e3.posq1.x=40;
    e3.posq1.y=y;
    SDL_BlitSurface(e3.quest, NULL, ecran, &e3.posq1);
    SDL_Flip(ecran);
    y += TTF_FontHeight(e3.police);
    }
    fclose(fichier);
	liberer_texte(e3);
	SDL_Flip(ecran);
	while (SDL_WaitEvent(&event))
{
switch(event.type)
{
case SDL_KEYDOWN:
if (event.key.keysym.sym == SDLK_ESCAPE)
  {
	SDL_Quit();
  }
if (event.key.keysym.sym == SDLK_r)
{
afficher_menu(c,e3);
}
}
}
}
