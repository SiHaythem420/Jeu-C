
/** 
* @file hero.c 
* @brief Testing Program. 
* @author C Team 
* @version 1 
* @date Apr 22, 2021 
* 
* Testing program for hero * 
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hero.h"
#define vitesse_max 40
#define G 16

/*void init(back *b)
{
    b->imgbackground = NULL;
    b->imgbackground = IMG_Load("imgbackground.png");

    b->posbackground.x = 0;
    b->posbackground.y = 0;
}
void aff(back b, SDL_Surface *ecran)
{
    SDL_BlitSurface(b.imgbackground, NULL, ecran, &b.posbackground);
    //  SDL_Flip(ecran);
}*/
void init_perso(personne *per){

per->tempsPrecedent = 0;
per->tempsActuel = 0;
per->frame=0;

per->saut=0;
per->posimg.x=100;
per->posimg.y=300;
//saut
per->img3=IMG_Load("1.png");
per->img4=IMG_Load("01.png");
//dr
per->walk[0]=IMG_Load("1.png");
per->walk[1]=IMG_Load("2.png");
per->walk[2]=IMG_Load("3.png");
per->walk[3]=IMG_Load("3.png");
//gc
per->walk[4]=IMG_Load("01.png");
per->walk[5]=IMG_Load("02.png");
per->walk[6]=IMG_Load("03.png");
per->walk[7]=IMG_Load("01.png");

per->xvelocity=0;
per->yvelocity=0;

per->direction=1;
}

void affich_perso(personne *per,SDL_Surface *ecran){



 SDL_BlitSurface(per->background, NULL,ecran , NULL);
}

void initPerso(perso *p)
{
    p->gravity = 400;
    p->jumpspeed = 40;
    p->jumpheight = 7;
    p->X = 0;
    p->Y = 0;
    p->Y2 = 0;
    p->tab1[7] = NULL;
    p->tab2[7] = NULL;
    p->tab3[7] = NULL;
    p->tab4[7] = NULL;
    p->tab5[7] = NULL;
    p->tab6[7] = NULL;
    p->tab7[7] = NULL;
    p->tab8[7] = NULL;
    p->direction = 0;
    p->num1 = 8;
    p->num2 = 8;
    p->num3 = 8;
    p->num4 = 8;
    p->num5 = 8;
    p->num6 = 8;
    p->num7 = 8;
    p->num8 = 8;
    p->numvie = 8;
    p->frame = 1;
    p->frame1 = 1;
    p->frame2 = 1;
    p->frame3 = 1;
    p->frame4 = 1;
    p->frame5 = 1;
    p->frame6 = 1;
    p->frame7 = 1;
    p->poshero.x = 150;
    p->poshero.y = 400;
    p->poshero.w = 100;
    p->poshero.h = 100;
    p->posimgvie.x = 1160;
    p->posimgvie.y = 10;
    p->posimgscore.x = 1200;
    p->posimgscore.y = 70;
    p->posimgscore.w = 200;
    p->posimgscore.h = 500;
    p->imgscore = NULL;
    char char1[20], char2[20], char3[20], char4[20], char5[20], char6[20], char7[20], char8[20], char9[20]; // char pour stocker les no;s des images
    int t;
    for (t = 1; t < p->num1; t++)
    {
        sprintf(char1, "1%d.png", t);
        p->tab1[t] = IMG_Load(char1);
    }

    for (t = 1; t < p->num2; t++)
    {
        sprintf(char2, "2%d.png", t);
        p->tab2[t] = IMG_Load(char2);
    }
    for (t = 1; t < p->num4; t++)
    {
        sprintf(char4, "4%d.png", t);
        p->tab4[t] = IMG_Load(char4);
    }
    for (t = 1; t < p->num3; t++)
    {
        sprintf(char5, "3%d.png", t);
        p->tab3[t] = IMG_Load(char5);
    }
    for (t = 1; t < p->num5; t++)
    {
        sprintf(char6, "5%d.png", t);
        p->tab5[t] = IMG_Load(char6);
    }
    for (t = 1; t < p->num6; t++)
    {
        sprintf(char7, "6%d.png", t);
        p->tab6[t] = IMG_Load(char7);
    }
    for (t = 1; t < p->num7; t++)
    {
        sprintf(char8, "7%d.png", t);
        p->tab7[t] = IMG_Load(char8);
    }
    for (t = 1; t < p->num8; t++)
    {
        sprintf(char9, "8%d.png", t);
        p->tab8[t] = IMG_Load(char9);
    }

    for (t = 1; t < p->numvie; t++)
    {
        sprintf(char3, "vie%d.png", t);
        p->tabvie[t] = IMG_Load(char3);
    }
   /* //victory
    p->victory = IMG_Load("victory.png");
    p->posgagnant.x = 20;
    p->posgagnant.y = 20;

    //defeat
    p->defeat = IMG_Load("defeat.png");
    p->posgagnant.x = 20;
    p->posgagnant.y = 20;*/
}
void initPerso2(perso *p)
{
    p->gravity = 400;
    p->jumpspeed = 40;
    p->jumpheight = 7;
    p->X = 0;
    p->Y = 0;
    p->Y2 = 0;
    p->tab1[7] = NULL;
    p->tab2[7] = NULL;
    p->tab3[7] = NULL;
    p->tab4[7] = NULL;
    p->tab5[7] = NULL;
    p->tab6[7] = NULL;
    p->tab7[7] = NULL;
    p->tab8[7] = NULL;
    p->direction = 0;
    p->num1 = 8;
    p->num2 = 8;
    p->num3 = 8;
    p->num4 = 8;
    p->num5 = 8;
    p->num6 = 8;
    p->num7 = 8;
    p->num8 = 8;
    p->numvie = 8;
    p->frame = 1;
    p->frame1 = 1;
    p->frame2 = 1;
    p->frame3 = 1;
    p->frame4 = 1;
    p->frame5 = 1;
    p->frame6 = 1;
    p->frame7 = 1;
    p->poshero.x = 150;
    p->poshero.y = 400;
    p->poshero.w = 100;
    p->poshero.h = 100;
    p->posimgvie.x = 1160;
    p->posimgvie.y = 10;
    p->posimgscore.x = 1200;
    p->posimgscore.y = 70;
    p->posimgscore.w = 200;
    p->posimgscore.h = 500;
    p->imgscore = NULL;
    char char1[20], char2[20], char3[20], char4[20], char5[20], char6[20], char7[20], char8[20], char9[20]; // char pour stocker les no;s des images
    int t;
    for (t = 1; t < p->num1; t++)
    {
        sprintf(char1, "1%dm.png", t);
        p->tab1[t] = IMG_Load(char1);
    }

    for (t = 1; t < p->num2; t++)
    {

        sprintf(char2, "2%dm.png", t);
        p->tab2[t] = IMG_Load(char2);
    }
    for (t = 1; t < p->num4; t++)
    {
        sprintf(char4, "4%dm.png", t);
        p->tab4[t] = IMG_Load(char4);
    }
    for (t = 1; t < p->num3; t++)
    {
        sprintf(char5, "3%dm.png", t);
        p->tab3[t] = IMG_Load(char5);
    }
    for (t = 1; t < p->num5; t++)
    {

        sprintf(char6, "5%dm.png", t);
        p->tab5[t] = IMG_Load(char6);
    }
    for (t = 1; t < p->num6; t++)
    {

        sprintf(char7, "6%dm.png", t);
        p->tab6[t] = IMG_Load(char7);
    }
    for (t = 1; t < p->num7; t++)
    {
        sprintf(char8, "7%dm.png", t);
        p->tab7[t] = IMG_Load(char8);
    }
    for (t = 1; t < p->num8; t++)
    {
        sprintf(char9, "8%dm.png", t);
        p->tab8[t] = IMG_Load(char9);
    }

    for (t = 1; t < p->numvie; t++)
    {
        sprintf(char3, "vie%dm.png", t);
        p->tabvie[t] = IMG_Load(char3);
    }
}
void afficherPerso(perso p, SDL_Surface *ecran, int ts, int v, Input I, int multijoueur)
{

    char char1[100], char2[100], char5[100], char3[100], char4[100];
    TTF_Init();
    /*persostop*/
    if ((p.direction == 0) && (I.fight == 0) && (v != p.numvie - 1) && (I.right == 0) && (I.jump == 0)) //stop
    {
        SDL_BlitSurface(p.tab1[1], NULL, ecran, &p.poshero);
    }

    else if ((p.direction == 1) && (I.fight == 0) && (v != p.numvie - 1) && (I.left == 0) && (I.jump == 0)) //stop1
    {
        SDL_BlitSurface(p.tab2[1], NULL, ecran, &p.poshero);
    }
    else if ((p.direction == 0) && (I.right == 1) && (I.jump == 0)) //marcher0
    {
       SDL_Delay(20);
        SDL_BlitSurface(p.tab1[p.frame], NULL, ecran, &p.poshero);
    }

    else if ((p.direction == 1) && (I.left == 1) && (I.jump == 0)) //marcher1
    {
       SDL_Delay(20);
        SDL_BlitSurface(p.tab2[p.frame1], NULL, ecran, &p.poshero);
    }
    else if ((p.direction == 0) && (v == p.numvie - 1)) //mort0
    {
        SDL_BlitSurface(p.tab3[p.frame2], NULL, ecran, &p.poshero);
        if (p.frame2 == p.num3)
            SDL_BlitSurface(p.tab3[7], NULL, ecran, &p.poshero);
    }

    else if ((p.direction == 1) && (v == p.numvie - 1)) //mort1
    {
        SDL_BlitSurface(p.tab4[p.frame3], NULL, ecran, &p.poshero);
        if (p.frame3 == p.num4)
            SDL_BlitSurface(p.tab4[7], NULL, ecran, &p.poshero);
    }
    else if ((p.direction == 0) && (I.fight == 1)) //frapper0
    {
       SDL_Delay(20);
        SDL_BlitSurface(p.tab5[p.frame4], NULL, ecran, &p.poshero);
    }
    else if ((p.direction == 1) && (I.fight == 1)) //frapper1
    {
        if (multijoueur == 1) 
            p.poshero.x -= 50;
        else
            p.poshero.x -= 105;

        SDL_BlitSurface(p.tab6[p.frame5], NULL, ecran, &p.poshero);
        SDL_Delay(15);
    }
    else if ((p.direction == 0) && (v != p.numvie) && (I.jump == 1)) // saut0up
    {
        SDL_Delay(15);
        SDL_BlitSurface(p.tab7[p.frame6], NULL, ecran, &p.poshero);
    }

    else if ((p.direction == 1) && (v != p.numvie) && (I.jump == 1)) //saut1up
    {
        SDL_Delay(15);
        SDL_BlitSurface(p.tab8[p.frame7], NULL, ecran, &p.poshero);
    }

    /*vie*/
    SDL_BlitSurface(p.tabvie[v], NULL, ecran, &p.posimgvie);

    /*score*/
    TTF_Font *police = NULL;
    SDL_Color couleurnoire = {0, 0, 0};
    if (multijoueur == 0)
        police = TTF_OpenFont("texxte.ttf", 90);
    else if (multijoueur == 1)
        police = TTF_OpenFont("texxte.ttf", 40);
    if (0 < ts < 10)
    {
        sprintf(char1, "%d", ts);
        p.imgscore = TTF_RenderText_Blended(police, char1, couleurnoire);
        SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);
    }
    else if (10 < ts < 100)
    {
        sprintf(char2, "%d", ts);
        p.imgscore = TTF_RenderText_Blended(police, char2, couleurnoire);
        SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);
    }
    else if (100 < ts < 1000)
    {
        sprintf(char3, "%d", ts);
        p.imgscore = TTF_RenderText_Blended(police, char3, couleurnoire);
        SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);
    }
    else if (1000 < ts < 10000)
    {
        sprintf(char4, "%d", ts);
        p.imgscore = TTF_RenderText_Blended(police, char4, couleurnoire);
        SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);
    }
    else if (ts < -1)
    {
        printf("si\n");
        sprintf(char5, "0%d", ts);
        p.imgscore = TTF_RenderText_Blended(police, char5, couleurnoire);
        SDL_BlitSurface(p.imgscore, NULL, ecran, &p.posimgscore);
    }
    TTF_CloseFont(police);
}

void mouvementright(perso *p)
{

    if (p->X >= vitesse_max)
        p->X = vitesse_max;
    if (p->poshero.x < 1399)
    {

        p->poshero.x = p->poshero.x + p->X;
        p->direction = 0;
    }
}

void mouvementleft(perso *p)
{
    if (p->X >= vitesse_max)
        p->X = vitesse_max;
    if (p->poshero.x > 0)
    {
        p->poshero.x = p->poshero.x - p->X;
        p->direction = 1;
    }
}

void initialiser_input(Input *I)
{
    I->left = 0;
    I->right = 0;
    I->fight = 0;
}

void animerperso(perso *p, SDL_Surface *ecran, int v, Input *I)
{

    if ((p->direction == 0) && (I->right == 1) && (I->jump == 0)) //marcher0
    {
       SDL_Delay(20);
        if (p->frame == p->num1 - 1)
            (p->frame) = 1;
        else
            (p->frame)++;
    }

    else if ((p->direction == 1) && (I->left == 1) && (I->jump == 0)) //marcher1
    {

        SDL_Delay(15);
        if (p->frame1 == p->num2 - 1)
            (p->frame1) = 1;
        else

            (p->frame1)++;
    }
    else if ((p->direction == 0) && (v == p->numvie - 1)) //mort0
    {
       SDL_Delay(20);
        if (p->frame2 < p->num3 - 1)
            (p->frame2)++;
    }

    else if ((p->direction == 1) && (v == p->numvie - 1)) //mort1
    {

       SDL_Delay(20);
        if (p->frame3 < p->num4 - 1)
            (p->frame3)++;
    }
    else if ((p->direction == 0) && (I->fight == 1)) //frapper0
    {

        SDL_Delay(15);
        if (p->frame4 == p->num5 - 1)
            (p->frame4) = 1;
        else

            (p->frame4)++;
    }
    else if ((p->direction == 1) && (I->fight == 1)) //frapper1
    {

        if (p->frame5 == p->num6 - 1)
            (p->frame5) = 1;
        else
            (p->frame5)++;

        SDL_Delay(15);
    }
    else if ((p->direction == 0) && (v != p->numvie) && (I->jump == 1)) // saut0
    {
        if (p->frame6 == p->num7 - 2)
            (p->frame6) = 1;
        else
        {
            (p->frame6)++;
        }
    }
    else if ((p->direction == 1) && (v != p->numvie) && (I->jump == 1)) //saut1
    {
        if (p->frame7 == p->num8 - 2)
            (p->frame7) = 1;
        else
            (p->frame7)++;
    }
}

void freesurface(perso *p)
{
    int i;
    for (i = 1; i < 7; i++)
    {
        SDL_FreeSurface(p->tab1[i]);
        SDL_FreeSurface(p->tab2[i]);
        SDL_FreeSurface(p->tab3[i]);
        SDL_FreeSurface(p->tab4[i]);
        SDL_FreeSurface(p->tab5[i]);
        SDL_FreeSurface(p->tab6[i]);
        SDL_FreeSurface(p->tab7[i]);
        SDL_FreeSurface(p->tab8[i]);
        SDL_FreeSurface(p->tabvie[i]);
    }

}
void init_vod(vod *vicde){
  vicde->posvictory.x = 275;
     vicde->posvictory.y = 80;
     vicde->posdefeat.y = 80;
    vicde-> posdefeat.x = 275;
     vicde->victory = IMG_Load("victory.png");
    vicde-> defeat = IMG_Load("defeat.png");

 
     vicde->posvictory2.x = 500;
     vicde->posvictory2.y = 20;
     vicde->posdefeat2.y = 20;
     vicde->posdefeat2.x = 500;

     vicde->posvictory3.x = 400;
     vicde->posvictory3.y = 470;
     vicde->posdefeat3.y = 400;
     vicde->posdefeat3.x = 500;
    vicde-> victory2 = IMG_Load("victorymultijoueur.png");
     vicde->defeat2 = IMG_Load("defeatmultijoueur.png");

}
void affichervictory_defeat0(vod vicde,int ts,int v,int temps,perso p,SDL_Surface *ecran)
{   if ((p.poshero.x >= 1210) && (p.poshero.x <= 1350) && (v != 7) && (temps != 0))
        {
          if (ts >0)
          {  SDL_BlitSurface(vicde.victory, NULL, ecran, &vicde.posvictory);}
          else if (ts<=0)
            {SDL_BlitSurface(vicde.defeat, NULL, ecran, &vicde.posdefeat);}
        }
        else if ((v == 7) || (temps == 0))
        {
          SDL_BlitSurface(vicde.defeat, NULL, ecran, &vicde.posdefeat);}
}
void affichervictory_defeat1(vod vicde,int ts,int v,int ts1,int v1,int ts2,int v2,int temps,SDL_Surface *ecran,perso p1,perso p2){
     if ((p1.poshero.x >= 1210) && (p1.poshero.x <= 1350) && (p2.poshero.x >= 1210) && (p2.poshero.x <= 1350) && (v1 != 7) && (v2 != 7) && (temps != 0))
        {
          {
            if (ts1 > ts2)
            {
              SDL_BlitSurface(vicde.victory2, NULL, ecran, &vicde.posvictory2);
              SDL_BlitSurface(vicde.defeat2, NULL, ecran, &vicde.posdefeat3);
            }
            else if (ts1 > ts2)
            {
              SDL_BlitSurface(vicde.victory2, NULL, ecran, &vicde.posvictory3);
              SDL_BlitSurface(vicde.defeat2, NULL, ecran, &vicde.posdefeat2);
            }
          }
        }
        else if ((v1 == 7) && (temps != 0) && (v2 != 7))
        {
          
          SDL_BlitSurface(vicde.victory2, NULL, ecran, &vicde.posvictory3);
          SDL_BlitSurface(vicde.defeat2, NULL, ecran, &vicde.posdefeat2);
        }
        else if ((v2 == 7) && (temps != 0) && (v1 != 7))
        {
          SDL_BlitSurface(vicde.victory2, NULL, ecran, &vicde.posvictory2);
          SDL_BlitSurface(vicde.defeat2, NULL, ecran, &vicde.posdefeat3);
        }
        else if ((temps == 0) && (v1 != 7) && (v2 != 7) && (p1.poshero.x == 1200) && (p2.poshero.x != 1200))
        {
          SDL_BlitSurface(vicde.victory2, NULL, ecran, &vicde.posvictory2);
          SDL_BlitSurface(vicde.defeat2, NULL, ecran, &vicde.posdefeat3);
        }
        else if ((temps == 0) && (v1 != 7) && (v2 != 7) && (p2.poshero.x == 1200) && (p1.poshero.x != 1200))
        {
          SDL_BlitSurface(vicde.victory2, NULL, ecran, &vicde.posvictory3);
          SDL_BlitSurface(vicde.defeat2, NULL, ecran, &vicde.posdefeat2);
        }
}
