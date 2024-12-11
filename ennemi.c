/**
* @file ennemi.c
* @brief code

*/
#include "hero.h"
#include "background.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "ennemi.h"
/** 
* @brief pour initialiser l'ennemi . 
* @param e Ennemi  
* @return Nothing 
*/
void initEnnemi(Ennemi *e)
{
    /*SDL_Surface *ecran = NULL;
    e->tabMar1[7] = NULL;
    e->tabMar2[7] = NULL;
    e->tabDeg[7] = NULL;
    e->tabAct[7] = NULL;
    e->frame1=0;
    e->frame2=0;
    e->frameAct=0;
    e->frameDeg=0;
    e->direction=1;*/
    e->posEnnemi.x=1500;
    e->posEnnemi.y=450;
    e->posEnnemi.w = 89;
    e->posEnnemi.h = 150;
    e->posMax.x = 1800;
    e->posMax.y = 450;
    e->posMin.x = 1300;
    e->posMin.y = 450;
    /*e->posEnnemi1[1].x=3300;
    e->posEnnemi1[1].y=490;
    e->posEnnemi2[2].x=5050;
    e->posEnnemi2[2].y=490;
    e->posEnnemi3[3].x=7500;
    e->posEnnemi3[3].y=490;
    e->posEnnemi4[4].x=9500;
    e->posEnnemi4[4].y=490;
    e->posEnnemi5[5].x=11500;
    e->posEnnemi5[5].y=490;*/
    /*e->surface->w=300;
    e->surface->h=600;*/
    //char char1[10];// char pour stocker les no;s des images
    //int t;
    /*for (t = 0; t < 5; t++)
    {
        sprintf(char1, "10%d.png",t);
        e->tabMar1[t] = IMG_Load(char1);
    }

    for (t= 0; t< 5; t++)
    {
        sprintf(char2, "11%d.png",t);
        e->tabMar2[t] = IMG_Load(char2);
    }
    for (t = 1; t < 6; t++)
    {
        sprintf(char3, "2%d.png",t);
        e->tabDeg[t] = IMG_Load(char3);
    }
    for (t = 1; t < 6; t++)
    {
        sprintf(char1, "3%d.png",t);
        e->tabAct[t] = IMG_Load(char1);
    }*/
  /*e->posEnnemi.x = 11602;
  e->posEnnemi.y = 500;
  e->posEnnemi.w = 89;
  e->posEnnemi.h = 150;
  e->posMax.x = 11760;
  e->posMax.y = 500;
  e->posMin.x = 11520;
  e->posMin.y = 500;*/
  e->posSprite.x=0;
  e->posSprite.y=0;
  e->posSprite.w=445/5;
  e->posSprite.h=300/2;
  e->sprite1=IMG_Load("sprite sheet_marche.png");
  e->posSprite2.x=0;
  e->posSprite2.y=0;
  e->posSprite2.w=534/6;
  e->posSprite2.h=300/2;
  e->sprite2=IMG_Load("sprite sheet_action.png");
  e->direction=0;
  e->State = WAITING;
}
void initEnnemi2(Ennemi *en1,Ennemi *en2)
{
   en1->posEnnemi.x = 400;
    en1->posEnnemi.y = 500;
    en1->posMax.x= 500;
    en1->posMax.y = 530;
    en1->posMin.x= 380;
    en1->posMin.y = 730;
    en2->posEnnemi.x = 400;
    en2->posEnnemi.y = 750;
    en2->posMax.x = 500;
    en2->posMax.y = 750;
    en2->posMin.x= 380;
    en2->posMin.y = 750;
    en1->posEnnemi.w = 45;
    en1->posEnnemi.h = 75;
    en2->posEnnemi.w = 45;
    en2->posEnnemi.h = 75;
    en1->posSprite.x=0;
    en1->posSprite.y=0;
    en1->posSprite.w=225/5;
    en1->posSprite.h=150/2;
    en1->sprite3=IMG_Load("sprite sheet_marche2.png");
    en1->posSprite2.x=0;
    en1->posSprite2.y=0;
    en1->posSprite2.w=270/6;
    en1->posSprite2.h=150/2;
    en1->sprite4=IMG_Load("sprite sheet_action2.png");
    en1->direction=0;
    en1->State = WAITING;
    en2->posSprite.x=0;
    en2->posSprite.y=0;
    en2->posSprite.w=225/5;
    en2->posSprite.h=150/2;
    en2->sprite3=IMG_Load("sprite sheet_marche2.png");
    en2->posSprite2.x=0;
    en2->posSprite2.y=0;
    en2->posSprite2.w=270/6;
    en2->posSprite2.h=150/2;
    en2->sprite4=IMG_Load("sprite sheet_action2.png");
    en2->direction=0;
    en2->State = WAITING;
}
/*void initbaguette(baguette *bag)
{
  bag->posbaguette1.x=1378.5;
  bag->posbaguette1.y=745;
  bag->posbaguette2.x=1543.3;
  bag->posbaguette2.y=745;
  bag->posbaguette3.x=1708.5;
  bag->posbaguette3.y=745;
  bag->posbaguette4.x=1960.5;
  bag->posbaguette4.y=535.5;
  bag->posbaguette5.x=2187;
  bag->posbaguette5.y=470;
  bag->posbaguette6.x=2411;
  bag->posbaguette6.y=535.5;
  bag->posbaguette7.x=3227;
  bag->posbaguette7.y=745;
  bag->posbaguette8.x=3391;
  bag->posbaguette8.y=745;
  bag->posbaguette9.x=3376;
  bag->posbaguette9.y=535.5;
  bag->posbaguette10.x=3903.5;
  bag->posbaguette10.y=470;
  bag->posbaguette11.x=4945.5;
  bag->posbaguette11.y=745;
  bag->posbaguette12.x=5109.7;
  bag->posbaguette12.y=745;
  bag->posbaguette13.x=6112.5;
  bag->posbaguette13.y=535.5;
  bag->baguette1= IMG_Load("baguette.png");
}
void afficherBag(baguette bag, SDL_Surface *ecran)
{
  SDL_BlitSurface(bag.baguette1, NULL, bag.imgBack1, &(bag.posbaguette1));
  SDL_BlitSurface(bag.baguette1, NULL, bag.imgBack1,&(bag.posbaguette2));
  SDL_BlitSurface(bag.baguette1, NULL, bag.imgBack1, &(bag.posbaguette3));
  SDL_BlitSurface(bag.baguette1, NULL, bag.imgBack1, &(bag.posbaguette4));
  SDL_BlitSurface(bag.baguette1, NULL, bag.imgBack1, &(bag.posbaguette5));
  SDL_BlitSurface(bag.baguette1, NULL, bag.imgBack1, &(bag.posbaguette6));
  SDL_BlitSurface(bag.baguette1, NULL, bag.imgBack1, &(bag.posbaguette7));
  SDL_BlitSurface(bag.baguette1, NULL, bag.imgBack1, &(bag.posbaguette8));
  SDL_BlitSurface(bag.baguette1, NULL, bag.imgBack1, &(bag.posbaguette9));
  SDL_BlitSurface(bag.baguette1, NULL, bag.imgBack1, &(bag.posbaguette10));
  SDL_BlitSurface(bag.baguette1, NULL, bag.imgBack1, &(bag.posbaguette11));
  SDL_BlitSurface(bag.baguette1, NULL, bag.imgBack1, &(bag.posbaguette12));
  SDL_BlitSurface(bag.baguette1, NULL, bag.imgBack1, &(bag.posbaguette13));
}*/
/*void initback(back *b)
{
    b->imgbackground= NULL;
    b->imgbackground= IMG_Load("imgbackground.png");

    b->posbackground.x=0;
    b->posbackground.y=0;
}
void initperso(personne *p)
{
    p->poshero.x = 20;
    p->poshero.y = 500;
    p->poshero.w = 170;
    p->poshero.h = 250;
    p->imageh= IMG_Load("djapa.png");
}
void afficherperso(perso p,SDL_Surface *ecran)
{
    SDL_BlitSurface(p.imageh, NULL, ecran, &p.poshero);
}
void afficherback(back b,SDL_Surface *ecran)
{
    SDL_BlitSurface(b.imgbackground, NULL, ecran, &b.posbackground);
}*/
/** 
* @brief pour Afficher l'ennemi . 
* @param e Ennemi
* @param ecran la surface
* @param b l'image de background  
* @return Nothing 
*/
void afficherEnnemi(Ennemi e,SDL_Surface *ecran,int multijoueur)
{  
    /*SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    win = SDL_CreateWindow("ennemi", 750, 450, 900, 800, 0);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    bitmapTex = SDL_CreateTextureFromSurface(renderer, e.tabMar1[e.frame1]);*/
   /*SDL_Surface *surface = NULL;
   SDL_Rect possurface;
   surface = SDL_CreateRGBSurface(0, 900, 800, 32, 0, 0, 0, 0);
   SDL_SetColorKey(surface, SDL_SRCCOLORKEY, SDL_MapRGB(surface->format, 0, 0, 0));
   possurface.x=600;
   possurface.y=400;*/
   /*SDL_Renderer *renderer = NULL;
   SDL_Texture *texture = NULL;
   SDL_Surface *tmp = NULL;
   texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET, 900, 800);*/
    /*if ((e.direction==1))
    {
         
         //SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
            //SDL_BlitSurface(surface,NULL,b.imgBack1, &possurface); 
         SDL_BlitSurface(e.tabMar1[e.frame1],NULL,ecran, &e.posEnnemi);
         
         
    }
    else if ((e.direction==0))
    {
        //SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
        //SDL_BlitSurface(surface,NULL,b.imgBack1, &possurface);
        SDL_BlitSurface(e.tabMar2[e.frame2],NULL,ecran, &e.posEnnemi);
        
        
        
    }*/
   if(multijoueur==0)
   {
    switch(e.State)
     {
      case WAITING:
      SDL_BlitSurface(e.sprite1,&e.posSprite,ecran, &e.posEnnemi);
      break;
      case FOLLOWING :
      
      SDL_BlitSurface(e.sprite1,&e.posSprite,ecran, &e.posEnnemi);
      break;
      case ATTACKING:
      SDL_BlitSurface(e.sprite2,&e.posSprite2,ecran, &e.posEnnemi);
      break;
    //SDL_BlitSurface(e.tabAct[e.frameAct], NULL, ecran, &e.posEnnemi);
    //SDL_BlitSurface(b.imgBack1, &(b.scroll), ecran, NULL);
    }
    }
       if(multijoueur==1)
   {
    switch(e.State)
     {
      case WAITING:
      SDL_BlitSurface(e.sprite3,&e.posSprite,ecran, &e.posEnnemi);
      break;
      case FOLLOWING :
      
      SDL_BlitSurface(e.sprite3,&e.posSprite,ecran, &e.posEnnemi);
      break;
      case ATTACKING:
      SDL_BlitSurface(e.sprite4,&e.posSprite2,ecran, &e.posEnnemi);
      break;
    //SDL_BlitSurface(e.tabAct[e.frameAct], NULL, ecran, &e.posEnnemi);
    //SDL_BlitSurface(b.imgBack1, &(b.scroll), ecran, NULL);
    }
    }
}
void afficherEnnemi2(Ennemi e,SDL_Surface *ecran,int multijoueur)
{  
   if(multijoueur==0)
   {
    switch(e.State)
     {
      case WAITING:
      SDL_BlitSurface(e.sprite1,&e.posSprite,ecran, &e.posEnnemi);
      break;
      case FOLLOWING :
      
      SDL_BlitSurface(e.sprite1,&e.posSprite,ecran, &e.posEnnemi);
      break;
      case ATTACKING:
      SDL_BlitSurface(e.sprite2,&e.posSprite2,ecran, &e.posEnnemi);
      break;
    //SDL_BlitSurface(e.tabAct[e.frameAct], NULL, ecran, &e.posEnnemi);
    //SDL_BlitSurface(b.imgBack1, &(b.scroll), ecran, NULL);
    }
    }
       if(multijoueur==1)
   {
    switch(e.State)
     {
      case WAITING:
      SDL_BlitSurface(e.sprite3,&e.posSprite,ecran, &e.posEnnemi);
      break;
      case FOLLOWING :
      
      SDL_BlitSurface(e.sprite3,&e.posSprite,ecran, &e.posEnnemi);
      break;
      case ATTACKING:
      SDL_BlitSurface(e.sprite4,&e.posSprite2,ecran, &e.posEnnemi);
      break;
    //SDL_BlitSurface(e.tabAct[e.frameAct], NULL, ecran, &e.posEnnemi);
    //SDL_BlitSurface(b.imgBack1, &(b.scroll), ecran, NULL);
    }
    }
}
/** 
* @brief pour Animer l'ennemi . 
* @param e Ennemi
* @param ecran la surface 
* @return Nothing 
*/
void animerEnnemi(Ennemi *e,int multijoueur)
{

    /*if ((e->direction==1))
    {
        
        (e->frame1)++;
        if ( e->frame1== 5)
            (e->frame1) = 0;
    }

    else if ((e->direction==0))
    {
       
        (e->frame2)++;
        if (e->frame2== 5)
            (e->frame2) = 0;
    }*/
    if(multijoueur==0)
    {
    switch (e->State)
    {
    case WAITING:
    if(e->direction==0)//droite
  {
   //printf("\n imin*****");
  e->posSprite.y=e->direction * e->posSprite.h;
  if(e->posSprite.x==445-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
else if(e->direction==1)//gauche
{
  printf("dour aal issar \n");
   e->posSprite.y=e->direction * e->posSprite.h;
   if(e->posSprite.x==445-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
 break;
 case FOLLOWING :
   if(e->direction==0)//droite
  {
   //printf("\n imin*****");
  e->posSprite.y=e->direction * e->posSprite.h;
  if(e->posSprite.x==445-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
else if(e->direction==1)//gauche
{
  printf("dour aal issar \n");
   e->posSprite.y=e->direction * e->posSprite.h;
   if(e->posSprite.x==445-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
 break;
 case ATTACKING:
  if(e->direction==0)//droite
  {
   //printf("\n imin*****");
  e->posSprite.y=e->direction * e->posSprite2.h;
  if(e->posSprite2.x==534-e->posSprite2.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite2.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite2.x=e->posSprite2.x+e->posSprite2.w;
  }
 }
else if(e->direction==1)//gauche
{
  printf("dour aal issar \n");
   e->posSprite2.y=e->direction * e->posSprite2.h;
   if(e->posSprite2.x==534-e->posSprite2.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite2.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite2.x=e->posSprite2.x+e->posSprite2.w;
  }
 }
 break; 
 }
 }
 if(multijoueur==1)
 {
   switch (e->State)
    {
    case WAITING:
    if(e->direction==0)//droite
  {
   //printf("\n imin*****");
  e->posSprite.y=e->direction * e->posSprite.h;
  if(e->posSprite.x==225-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
else if(e->direction==1)//gauche
{
  printf("dour aal issar \n");
   e->posSprite.y=e->direction * e->posSprite.h;
   if(e->posSprite.x==225-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
 break;
 case FOLLOWING :
   if(e->direction==0)//droite
  {
   //printf("\n imin*****");
  e->posSprite.y=e->direction * e->posSprite.h;
  if(e->posSprite.x==225-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
else if(e->direction==1)//gauche
{
  printf("dour aal issar \n");
   e->posSprite.y=e->direction * e->posSprite.h;
   if(e->posSprite.x==225-e->posSprite.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite.x=e->posSprite.x+e->posSprite.w;
  }
 }
 break;
 case ATTACKING:
  if(e->direction==0)//droite
  {
   //printf("\n imin*****");
  e->posSprite.y=e->direction * e->posSprite2.h;
  if(e->posSprite2.x==270-e->posSprite2.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite2.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite2.x=e->posSprite2.x+e->posSprite2.w;
  }
 }
else if(e->direction==1)//gauche
{
  printf("dour aal issar \n");
   e->posSprite2.y=e->direction * e->posSprite2.h;
   if(e->posSprite2.x==270-e->posSprite2.w)
  {
    //printf("erjaa mil lowel \n ");
    e->posSprite2.x=0;
  }
  else
  {
    //printf("kamel aala rohek\n");
   e->posSprite2.x=e->posSprite2.x+e->posSprite2.w;
  }
 }
 break; 
 }
 }
}
/** 
* @brief pour Deplacer l'ennemi . 
* @param e Ennemi  
* @return Nothing 
*/
void deplacer(Ennemi *e)
{
   if((e->direction==0))//droite
    {

        if((e->posEnnemi.x<e->posMax.x)&&(e->posEnnemi.x>=e->posMin.x))
        {
            e->posEnnemi.x+=5;
        }
        else if((e->posEnnemi.x==e->posMax.x))
        {
            e->direction=1;
        }
    }
   else if(e->direction==1)//gauche
    {

        if((e->posEnnemi.x<=e->posMax.x)&&(e->posEnnemi.x>e->posMin.x))
        {
            e->posEnnemi.x-=5;
        }
        else if((e->posEnnemi.x==e->posMin.x))
        {
            e->direction=0;

        }
    }
   
}
   
/** 
* @brief pour la collision entre hero et ennemi .
* @param p personnage 
* @param e Ennemi
* @param collision entier de collision  
* @return 1 si il y a une collision
* @return 0 si il n'y a pas de collision 
*/
int collisionBB(perso p,Ennemi e,int collision)
{
    if((p.poshero.x + p.poshero.w<e.posEnnemi.x)||(p.poshero.x>e.posEnnemi.x+e.posEnnemi.w)||(p.poshero.y+p.poshero.h<e.posEnnemi.y)||(p.poshero.y>e.posEnnemi.y+e.posEnnemi.h))
    {
        collision=0;
    }
    else
    {
        collision=1;
    }
    return collision;
}
void deplacerIA(Ennemi *e,perso p)
{
	if (p.poshero.x<e->posEnnemi.x) //hero à gauche de l'ennemi
	{
		e->direction=1;
		deplacer(e);
	}

	if (p.poshero.x>e->posEnnemi.x) // hero a droite
	{
		e->direction=0;
		deplacer(e);
	}
}
void update_ennemi(Ennemi* e, perso p)
{
	int distEH,multijoueur;
	if(e->posEnnemi.x>=p.poshero.x)
         distEH=e->posEnnemi.x-(p.poshero.x + p.poshero.w);
       else
         distEH=(p.poshero.x + p.poshero.w)-e->posEnnemi.x;
	//printf("Mabin l Ennemi w el hero  = %d\t E->State = %d\n", distEH,E->State);
    	switch(e->State)
    	{
        	case WAITING :
        	{
            		animerEnnemi(e,multijoueur);
            		deplacer(e);
            		break;
        	}

        	case FOLLOWING :
        	{
            		animerEnnemi(e,multijoueur);
            		deplacerIA(e,p);
            		//deplacer(e);
            		break;
        	}

        	case ATTACKING :
        	{
		    	animerEnnemi(e,multijoueur);
		    	//deplacerIA(e,p);
			//deplacer(e);
			break;
        	}       
    	}

	updateEnnemiState(e, distEH);	
}
void updateEnnemiState(Ennemi* e, int distEH)
{
     printf("distance=%d\n",distEH);
	if (distEH>160)
	{
		e->State=0;

	}

	if (distEH>100 && distEH<=150)
	{
		e->State=1;
	}

	if (distEH>0 && distEH<=50 )
	{
		e->State=2;
	}
}

