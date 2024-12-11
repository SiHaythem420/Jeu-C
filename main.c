///////
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "background.h"
#include "hero.h"
#include "enigmestat.h"
#include "enigmealeatoire.h"
#include "enigmealf.h"
#include "ennemi.h"
#include "enigme.h"
#include "fichier.h"
#define vitesse_max 40
#define G 10

int main(int argc, char *argv[])
{
  /*------------------------declaration ----------*/
  SDL_Event event;

  SDL_Surface *ecran = NULL;
  int direction, continuer = 1, frame = 0;
  const int FPS = 40;           //frame per second
  Background b;                 //variable pour structure background
  Ennemi e, en1, en2;           //variables pour la structure ennemi
  Background b1;                //variable pour structure background multijoueur
  Background b2;                //variable pour structure background multijoueur
  perso p, p1, p2;              //variable pour structure personnage
  int ts = 0, ts1 = 0, ts2 = 0; //variable score
  int v = 1, v1 = 1, v2 = 1;    //variable vie
  int y = 0;                    //variable input pour main menu (verticale)
  Input I, I1, I2;              //variable input
  Uint32 start;                 //temps
  int dt;                       //temps
  Uint32 t_prev;
  minimap m;                             //variable pour structure minimap
  int ysm = 0;                           //variable pour le sous-menu horizontal
  int loadd = 0;                         //0:pas du load 1:load
  int multijoueur = 0;                   //0;jouer en mode solo 1:jouer en mode multijoueur
  int temps = 60;                        // variable temps
  int f, k, n, interface = 0, ym = 0, z; //variables pour le main menu , interface==0:main-menu ,interface==1:options,interface==2:newgame
  int page = 0;                          // 1:6 c'est le jeu  de stage 1->6, 7 enigme 1, 8 enigme 2, 9 enigme 3 , 0 menu principale
  int input = 0;                         //1 fleche right, 2 fleche left
  menu men;                              //variable pour structure menu
  vod vicde;                             //variable pour structure victoire ou defeat

  //tout ce qui concerne enigme statique//
  enigme enig;
  int reponsevraie = 0; //variable reponse pour enigme statique
  int teststat = 0;

  int collision; //collision bouding box

  changeinput inp; //variable pour structure changer input
  int chinput = 1; //variable mode input A ou B

  // tout ce qui concerne enigme alea sans fichier//
  enigme1 e1; //variable pour structure
  int reponsejuste = -1;
  int test1 = 0;
  grille g; //variable pour structure pour jeu puissance 2 XO

  //*********************dec puissance 4
  int p4 = 0;             //variable affichage
  int p5 = 0;             //variable arret du mouvement du joueur
  int check = 0;          //variable pour verfication : gain ou perte
  Casee c, c_o;           ////variable pour structure jeu puissance 4
  int T[6][7];            //matrice de 6colognes et 7lignes
  int j, i, nb_coups = 0; //j=colonne i=ligne ,nombre de coups
  init a;                 //variable pour structure d'initialisation jeu puissance 4

  //***************enigme al aavec fichier
  int enigmeelf = 0;    // 0:initialisation 1:bloquer le mouvement du joueur lors de l'affichage de l'enigme
  enigmealf ealf;       //variable pour structure
  int r = 3;            // 1 si resolu , 0 si non resolu
  int ye = 0;           // pos of mouse , 1 on yms ,  or 2 on no or  0 none
  int enigmealfalf = 0; // 1 si enigmealf commence 0 si il  n y a pas dengime
  int somenu = 0;       //0:affiche sous menu 1:affiche sous-menu

  /****************************************************************************************************************/

  /*--------------------initialisation SDL*********/
  TTF_Init();
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) != 0)
  {
    printf("unable to set video mode:%s \n", SDL_GetError());
    return 1;
  }
  ecran = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (ecran == NULL)
  {
    printf("unable to set video mode:%s \n", SDL_GetError());
    return 1;
  }
  SDL_EnableKeyRepeat(100, 100);
  /*******initialisation des erntités*************/
  initBack(&b);
  //initBack(&b1);
  initEnnemi(&e);
initBack1(&b2);
initBack2(&b1);

  initialiser_input(&I);
  initPerso(&p);
  initmap(&m);
  I.jump = 0;
  I.fall = 1;
  //init enigstat//
  
  //init grille
  InitGrille(&g);

  //init e1//
  e1 = generer();
  init_enigme1(&e1);

  //*********INIT enigme al avec fichier***********
  initialiser_enigmealf(&ealf);
  genererenigmealf(&ealf);

  initPerso2(&p1);
  initPerso2(&p2);
  p1.poshero.y = 230;
  p2.poshero.y = 630;
  I1.jump = 0;
  I1.fall = 1;
  I2.jump = 0;
  I2.fall = 1;
  initEnnemi2(&en1,&en2);
  ////////init menu
  intialiser(&men, &inp);
  ///////init puissance 4
  initi(&a);
  for (i = 0; i < 6; i++)
  {
    for (j = 0; j < 7; j++) //on va parcourir la matrice
      T[i][j] = 0;
  }
  /**********boucle du jeu*******************/
  while (continuer)
  {
    start = SDL_GetTicks();
    input = 0;

    //init victory defeat//

    init_vod(&vicde);
    /******* Module d'affichage****/
    if (page == 1)
    {
      if (multijoueur == 0)
      {
        afficherBack(b, ecran);
        afficherminimap(m, ecran);
        affichertemps(temps, ecran);
        afficherPerso(p, ecran, ts, v, I, multijoueur);
        afficherEnnemi(e, ecran, multijoueur);

        if (v == 6)
        {
          Play(&g, &v);
        }
        animerEnnemi(&e, multijoueur);
        collision = collisionBB(p, e, collision);
        if (collision)
        {
          v++;
          ts--;
          if ((v == 7) || (ts < 0))
          {
            p.poshero.x -= 100;
            //continuer=0;
          }
        }
        else
        {
          continuer = 1;
        }

        /**tache blanche**/

        /** enigme stat**/
        

        ////***initilisation des enigmes ****////////
	/*if ((b.scroll.x >= 2150) && (b.scroll.x <= 2200) && (page == 1))
        {
          teststat = 1;
          afficher_enigme(ecran, enig);

          if (reponsevraie == 1)
          {

            rep_vrai(ecran, enig);
            teststat = 0;
          }
          else if (reponsevraie == -1)
          {
            rep_fausse(ecran, enig);
            teststat = 0;
          }
        }*/
       

        /** mtaa Adam****/
	if ((b.scroll.x >= 10250) && (b.scroll.x <= 10300) && (page == 1))
        {
	
	afficher_enigme2 ();

	}
	
        
      }
      if (somenu == 1)
      {
        afficher_sousmenu(ealf, ecran);
      }
      else if (multijoueur == 1)
      {
        afficherBack(b1, ecran);
        afficherBack1(b2, ecran);
        affichertemps(temps, ecran);
        afficherPerso(p1, ecran, ts1, v1, I1, multijoueur);
        afficherEnnemi(en1, ecran, multijoueur);
        animerEnnemi(&en1, multijoueur);
        deplacer(&en1);
        p2.posimgscore.y = 440;
        p1.posimgscore.y = 50;
        p1.posimgvie.x = 1250;
        p2.posimgvie.x = 1250;
        p2.posimgscore.x = 1330;
        p1.posimgscore.x = 1330;
        p2.posimgvie.y = 400;
        afficherPerso(p2, ecran, ts2, v2, I2, multijoueur);
        afficherEnnemi(en2, ecran, multijoueur);
        animerEnnemi(&en2, multijoueur);
        deplacer(&en2);
        affichervictory_defeat1(vicde, ts, v, ts1, v1, ts2, v2, temps, ecran, p1, p2);
      }
      if ((check == 0) && (nb_coups < 21) && (b.scroll.x >= 7200) && (b.scroll.x <= 7300) && (page == 1))

      {
        p4 = 1;
      }
      if ((b.scroll.x >= 7200) && (b.scroll.x <= 7300) && (page == 1))
        p5 = 1;
      else
        p5 = 0;
      if (p5 == 1)
      {
        afficherfond(ecran, a);
      }
    }
    else if (page == 0)
    {

      affichagemenuanim(men, ecran, &continuer);
      affichage(interface, y, f, k, men, ecran, n, inp, chinput);
    }
    // udpate

    /****** Module input****/

    while (SDL_PollEvent(&event))
    {
      if (page == 0)
      {
        switch (event.type)
        {
        case SDL_QUIT:
          continuer = 0;
          break;

        case SDL_MOUSEMOTION:
          men.poscurseur.x = event.motion.x;
          men.poscurseur.y = event.motion.y;

          if (interface == 0)
          { //curseur dans les intervals des images play/options/quit//
            if ((event.motion.x <= 428 && event.motion.x >= 100) && (event.motion.y <= 479 && event.motion.y >= 370))
            {
              y = 1;
            }
            else if ((event.motion.x < 429 && event.motion.x >= 100) && (event.motion.y <= 586 && event.motion.y > 500))
            {

              y = 2;
            }
            else if ((event.motion.x <= 450 && event.motion.x >= 90) && (event.motion.y <= 680 && event.motion.y >= 600))
            {

              y = 3;
            }
            else
              y = 0;
          }

          else if (interface == 1)
          {
            y = 0;
            //curseur dans interval de la barre du  son//
            if ((event.motion.x <= 260 && event.motion.x >= 100) && (event.motion.y <= 420 && event.motion.y >= 380))
            {

              y = 1;
              z = 0;
            }
            else if ((event.motion.x < 420 && event.motion.x >= 260) && (event.motion.y <= 420 && event.motion.y > 380))
            {

              y = 1;
              z = 1;
            }
            else if ((event.motion.x <= 580 && event.motion.x >= 420) && (event.motion.y <= 420 && event.motion.y >= 380))
            {

              y = 1;
              z = 2;
            }
            if ((event.motion.x <= 740 && event.motion.x >= 580) && (event.motion.y <= 420 && event.motion.y >= 380))
            {

              y = 1;
              z = 3;
            }
            else if ((event.motion.x < 860 && event.motion.x >= 740) && (event.motion.y < 420 && event.motion.y > 380))
            {

              y = 1;
              z = 4;
            }

            //curseur dans interval des images "fullscreen"/"fenetre"//
            else if ((event.motion.x <= 415 && event.motion.x >= 94) && (event.motion.y <= 687 && event.motion.y >= 613))
            {
              y = 2;
              f = 0;
            }
            else if ((event.motion.x < 804 && event.motion.x >= 471) && (event.motion.y <= 687 && event.motion.y > 613))
            {
              y = 2;
              f = 1;
            }
            ////////////////////curseur dans interval des images "input"//

            else if ((event.motion.x <= 1234 && event.motion.x >= 900) && (event.motion.y <= 683 && event.motion.y >= 610))
            {

              y = 4;
            }
          }

          else if (interface == 2)
          {
            if ((event.motion.x <= 428 && event.motion.x >= 100) && (event.motion.y <= 479 && event.motion.y >= 370))
            {

              y = 1;
            }
            else if ((event.motion.x < 429 && event.motion.x >= 100) && (event.motion.y <= 586 && event.motion.y > 500))
            {
              y = 2;
            }
            else if ((event.motion.x <= 450 && event.motion.x >= 90) && (event.motion.y <= 680 && event.motion.y >= 600))
            {
              //quit
              y = 3;
            }
            else
              y = 0;
          }
          break;

          //comportement du bouton
        case SDL_MOUSEBUTTONDOWN:
          switch (event.button.button)
          {
          case SDL_BUTTON_LEFT:
            //Mix_PlayChannel(-1, son, 0);
            if (interface == 0)
            {
              if (y == 1)
                interface = 2;
              else if (y == 2)
              {
                interface = 1;
                y = 1;
              }
              else if (y == 3)
                continuer = 0;
            }
            else if (interface == 1)
            {
              if (z == 0)
              {
                k = 0;
                y = 1;
              }
              else if (z == 1)
              {
                k = 1;
                y = 1;
              }
              else if (z == 2)
              {
                k = 2;
                y = 1;
              }
              else if (z == 3)
              {
                k = 3;
                y = 1;
              }
              else if (z == 4)
              {
                k = 4;
                y = 1;
              }

              else if (y == 2)
                switch (f)
                {
                case 0:
                  n = 1;
                  break;
                case 1:
                  n = 2;
                  break;
                }

              else if (y == 4) //nzel aal buton input///
              {
                interface = 3;
              }
              break;
            }

            else if (interface == 2) //new game
            {
              if (y == 1)
              {temps=60;
                v = 1;
                ts = 0;
                initBack(&b);
                 reponsevraie = 0;
                 reponsejuste = -1;
                 enigmealfalf = 0;
 
          initi(&a);
           check = 0;         
  nb_coups = 0; 
p4=0;
p5=0;
 for (i = 0; i < 6; i++)
  {
    for (j = 0; j < 7; j++)
      T[i][j] = 0;
  }  
                InitGrille(&g);
                initEnnemi(&e);
                initmap(&m);
                init_enigme(&enig);
                e1 = generer();
                init_enigme1(&e1);
                initialiser_enigmealf(&ealf);
                genererenigmealf(&ealf);
                initPerso(&p);
                multijoueur = 0;
                page = 1;
                r=3;
              }
              else if (y == 2)
              {
                multijoueur = 0;
                page = 1;
                load(&p, &b, &e, &m, &ts, &v,&reponsejuste,&r,&reponsevraie);
              }
              else if (y == 3)
              {
                multijoueur = 1;
                temps=60;
                page = 1;
              }
            }
          }

          break;

        case SDL_KEYDOWN:
          switch (event.key.keysym.sym)
          {
          case SDLK_ESCAPE:
            if (interface == 0)
            {
              continuer = 0;
            }
            else if (interface == 1)
              interface = 0;
            else if (interface == 2)
              interface = 0;
            else if (interface == 3)
              interface = 1;
            break;

          case SDLK_RETURN:

            if (interface == 0)
            {
              if (y == 1)
                interface = 2;
              else if (y == 2)
              {
                interface = 1;
                y = 1;
              }
              else if (y == 3)
                continuer = 0;
            }
            else if (interface == 1)
            {
              if (y == 2)
                switch (f)
                {
                case 0:
                  n = 1;
                  break;
                case 1:
                  n = 2;
                  break;
                }
              else if (y == 4)
              {
                interface = 3;
              }
            }
            else if (interface == 2)
            {
              if (y == 1)
                page = 1;
              else if (y == 2)
                page = 2;
              else if (y == 3)
                page = 3;
            }

            else if (interface == 3) //interface input//
            {
              if (y == 1)
              {
                chinput = 1;
              }

              else if (y == 2)
              {
                chinput = 2;
              }
            }

          case SDLK_UP:
            if (y == 0)
            {
              y = 3;
              break;
            }
            if (y == 3)
            {
              y = 2;
              break;
            }
            if (y == 2)
            {
              y = 1;
              break;
            }
            if (y == 1)
            {
              y = 1;
              break;
            }

            if (y == 4)
            {
              y = 3;
            }
            break;

          case SDLK_DOWN:
            if (y == 0)
            {
              y = 1;
              break;
            }
            if (y == 1)
            {
              y = 2;
              break;
            }
            if (y == 2)
            {
              y = 1;
              break;
            }
            if (y == 3)
            {
              y = 1;
              break;
            }

          case SDLK_RIGHT:
            if (y == 1)
            {
              if (k == 0)
              {
                k = 1;
                break;
              }
              if (k == 1)
              {
                k = 2;
                break;
              }
              if (k == 2)
              {
                k = 3;
                break;
              }
              if (k == 3)
              {
                k = 4;
                break;
              }
              if (k == 4)
              {
                k = 4;
                break;
              }
            }

            if (f == 0)
            {
              f = 1;
              break;
            }

            if (f == 1) //fenetre normale/
            {
              y = 4;
              break;
            }

          case SDLK_LEFT:
            if (y == 1)
            {
              if (k == 4)
              {
                k = 3;
                break;
              }
              if (k == 3)
              {
                k = 2;
                break;
              }
              if (k == 2)
              {
                k = 1;
                break;
              }
              if (k == 1)
              {
                k = 0;
                break;
              }
              if (k == 0)
              {
                k = 0;
                break;
              }
            }
            if (f == 0)
            {
              f = 0;
              break;
            }
            if (f == 1)
            {
              f = 0;
              break;
            }

            if (y == 4)
            {
              f = 1;
              break;
            }
            ///fermuture if(n==2)//
          } //fermuture switch(key event)//
        }
      }

      if (page == 1)
      {
        initialiser_input(&I);
        initialiser_input(&I1);
        initialiser_input(&I2);

        switch (event.type)
        {

        case SDL_MOUSEBUTTONUP:
          if ((check == 0) && (nb_coups < 21) && (b.scroll.x >= 7200) && (b.scroll.x <= 7300) && (page == 1))
          {
            c = afficher_jeton(a.fond, a, event, T); //T est la matrice
            T[c.l][c.c] = 1;
            nb_coups++;
            check = checkk(T);
            if (nb_coups == 21)
            {
              afficherpuis1(a);
            }
            if (check == 1)
            {
              afficherpuis2(a);
            }
            if (check == 2)
            {
              afficherpuis3(a);
            }
            if ((nb_coups < 22) && (check == 0))
            {
              c_o = IA(T);
              T[c_o.l][c_o.c] = 2;
              afficher_jaune(a.fond, a, c_o);
              check = checkk(T);
              if (nb_coups == 21)
              {
                afficherpuis4(a);
              }
              if (check == 1)
              {
                afficherpuis5(a);
              }
              if (check == 2)
              {
                afficherpuis6(a);
              }
            }
            p4 = 0;
          }

          break;

        case SDL_QUIT:
          continuer = 0;
          break;
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym)
          {
          case SDLK_ESCAPE:
            if (somenu == 0)
              somenu = 1;
            else if (somenu == 1)
              somenu = 0;
            break;
          case SDLK_RIGHT:
            if ((v != 7) && (chinput == 1))
            {
              I.right = 1;
              p.direction = 0;
            }
            if ((v1 != 7) && (multijoueur == 1))
            {
              I1.right = 1;
              p1.direction = 0;
            }

            break;
          case SDLK_LEFT:
            if ((v != 7) && (chinput == 1))
            {
              I.left = 1;
              p.direction = 1;
            }
            if ((v1 != 7) && (multijoueur == 1))
            {
              I1.left = 1;
              p1.direction = 1;
            }
            break;
          case SDLK_UP:

            if ((v != 7) && (chinput == 1))
            {

              I.jump = 1;
            }
            if ((v1 != 7) && (multijoueur == 1))
            {
              I1.jump = 1;
            }
            break;
          case SDLK_SPACE:
            if ((v != 7) && (chinput == 1))
            {
              I.fight = 1;
            }
            if ((v2 != 7) && (multijoueur == 1))
            {
              I1.fight = 1;
            }
            break;

            ///////**** si il y a changement d'input//////

          case SDLK_m:
            if ((v != 7) && (chinput == 2))
            {
              I.right = 1;
              p.direction = 0;
            }

            break;
          case SDLK_k:
            if ((v != 7) && (chinput == 2))
            {
              I.left = 1;
              p.direction = 1;
            }

            break;
          case SDLK_o:

            if ((v != 7) && (chinput == 2))
            {

              I.jump = 1;
            }

            break;
          case SDLK_KP0:
            if ((v != 7) && (chinput == 2))
            {
              I.fight = 1;
            }

            break;

          case SDLK_d:
            if ((v2 != 7) && (multijoueur == 1) && (page == 1))
            {
              I2.right = 1;
              p2.direction = 0;
            }

            break;
          case SDLK_q:
            if ((v2 != 7) && (multijoueur == 1) && (page == 1))
            {
              I2.left = 1;
              p2.direction = 1;
            }
            break;
          case SDLK_z:
            if ((v2 != 7) && (multijoueur == 1) && (page == 1))
            {
              I2.jump = 1;
            }
            break;
          case SDLK_x:
            if ((v2 != 7) && (multijoueur == 1) && (page == 1))
            {
              I2.fight = 1;
            }
            break;
            ///input enigme alea sans fichiers//
          case SDLK_i:
            if ((e1.numrepjuste == 0) && (test1 == 1))
            {
              reponsejuste = 1;
              ts += 50;
            }
            else if (test1 == 1)
            {
              reponsejuste = 0;
              ts -= 50;
              v++;
            }
            break;

          case SDLK_u:
            if ((e1.numrepjuste == 1) && (test1 == 1))
            {
              reponsejuste = 1;
              ts += 50;
            }

            else if (test1 == 1)
            {

              reponsejuste = 0;
              ts -= 50;
              v++;
            }

            break;

          case SDLK_KP3:
            if ((e1.numrepjuste == 2) && (test1 == 1))
            {
              reponsejuste = 1;
              ts += 50;
            }
            else if (test1 == 1)
            {
              if (reponsejuste = 0)
              {
                ts -= 50;
                v++;
              }
            }
            break;
            //****input enigstat****//
          case SDLK_a:
            if ((reponsevraie = -1) && (teststat == 1))
            {
              ts -= 50;
              v++;
            }

            break;
          case SDLK_b:
            if ((reponsevraie = 1) && (teststat == 1))
              ts += 50;

            break;
          case SDLK_c:
            if ((reponsevraie = -1) && (teststat == 1))
            {
              ts -= 50;
              v++;
            }

            break;

          //******input enigme alea avec fichiers**********
          case SDLK_v:
            if (enigmealfalf = 1)
            {

              if (ealf.reponse == 0)
              {
                SDL_Delay(2000);
                r = 0;
              }

              else
              {
                SDL_Delay(2000);
                r = 1;
              }

              break;
            }

          case SDLK_f:
            if (enigmealfalf = 1)
            {
              if (ealf.reponse == 0)
              {
                SDL_Delay(2000);
                r = 1;
              }

              else
              {
                SDL_Delay(2000);
                r = 0;
              }
            }

            break;
          }
          break;
        case SDL_MOUSEMOTION:
          ealf.poscurseur.x = event.motion.x;
          ealf.poscurseur.y = event.motion.y;
          if (enigmealfalf == 1)
          {
            if ((event.motion.x <= 490 && event.motion.x >= 400) && (event.motion.y <= 560 && event.motion.y >= 500))
            {
              ye = 1;
            }
            else if ((event.motion.x < 770 && event.motion.x >= 700) && (event.motion.y < 560 && event.motion.y > 500))
            {
              ye = 2;
            }
          }
          if (somenu == 1)
          {
            if ((event.motion.x <= 576 && event.motion.x >= 509) && (event.motion.y <= 415 && event.motion.y >= 335))
            {

              ysm = 1;
            }
            if ((event.motion.x <= 730 && event.motion.x >= 651) && (event.motion.y <= 415 && event.motion.y >= 335))
            {
              ysm = 2;
            }
            if ((event.motion.x <= 879 && event.motion.x >= 812) && (event.motion.y <= 415 && event.motion.y >= 335))
            {
              ysm = 3;
            }
          }
        case SDL_MOUSEBUTTONDOWN:
          switch (event.button.button)
          {
          case SDL_BUTTON_LEFT:
            if (somenu == 1)
            {
              if (ysm == 1)
              {
                somenu = 0;
              }
              else if (ysm == 2)
              {
                save(p, b, e, m, ts, v,reponsejuste,r,reponsevraie);
              }
              else if (ysm == 3)
              {
                page = 0;
                interface = 0;
                somenu = 0;
              }
            }
            if (enigmealfalf == 1)
            {
              if ((ye == 1) && (ealf.reponse == 0))
              {
                r = 0;
                ts -= 50;
                v++;
              }
              else if ((ye == 1) && (ealf.reponse == 1))
              {
                r = 1;
                ts += 50;
              }
              else if ((ye == 2) && (ealf.reponse == 0))
              {
                r = 1;
                ts += 50;
              }
              else if ((ye == 2) && (ealf.reponse == 1))
              {
                r = 0;
                ts -= 50;
                v++;
              }
            }

            break;
          }
        }
      }
    }
    /****Module update *******/

    if (page == 1)
    {
      if (multijoueur == 0)
      {

        if ((I.right == 1) && (v != 7) && (test1 == 0) && (enigmeelf == 0) && (teststat == 0) && (somenu == 0) && (p4 == 0)) // fleche right
        {
          if (p.poshero.x < (ecran->w / 2) || b.scroll.x >= (b.scroll.w - ecran->w)) // deplacement
          {
            if (collisionPP(p, b.imageM, b, I) == 0) // pas de collision avec background
            {
              /**** update personage *****/
              p.X++;
              mouvementright(&p);
              p.direction = 0;
              /** update mini map***/
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x += p.poshero.x / 172;
            }
          }
          else
          {
            if (collisionPP(p, b.imageM, b, I) == 0) // pas de collision
            {
              e.posEnnemi.x-=p.X;
              e.posMax.x-=p.X;
              e.posMin.x-=p.X;
              /*for(w=2;w<7;w++)
             {
              e.posEnnemi[w].x-=p.X;
              e.posMax[w].x-=p.X;
              e.posMin[w].x-=p.X;
              }*/
              p.direction = 0;
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x += p.poshero.x / 172;

              scrollingBack(&b, p, I);
            }
          }
        }

        else if ((v != 7) && (I.left == 1) && (test1 == 0) && (enigmeelf == 0) && (teststat == 0) && (somenu == 0) && (p4 == 0))
        {
          if ((b.scroll.x >= 50 && b.scroll.x < (b.scroll.w - ecran->w)) || (b.scroll.x == (b.scroll.w - ecran->w) && p.poshero.x <= 760))
          {
            e.posEnnemi.x += p.X;
            e.posMax.x += p.X;
            e.posMin.x += p.X;
           /* for(w=2;w<7;w++)
             {
              e.posEnnemi[w].x+=p.X;
              e.posMax[w].x+=p.X;
              e.posMin[w].x+=p.X;
              }*/
            if (collisionPP(p, b.imageM, b, I) == 0)
            {
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x -= p.poshero.x / 172;
              p.direction = 1;
              scrollingBack(&b, p, I);
            }
          }
          else if (b.scroll.x < 50 || b.scroll.x >= (b.scroll.w - ecran->w))
          {
            if (collisionPP(p, b.imageM, b, I) == 0)
            {
              p.X++;
              mouvementleft(&p);
              p.direction = 1;
              if (m.pospoint.x >= m.posminimap.x)
                m.pospoint.x -= p.poshero.x / 172;
              if (p.poshero.x <= 60)
              {
                p.poshero.x = 60;
                m.pospoint.x = 100;
              }
            }
          }
        }
      }

      else if (multijoueur == 1)
      {

        if ((I1.right == 1) && (v1 != 7) && (test1 == 0) && (enigmeelf == 0) && (teststat == 0) && (somenu == 0) && (p4 == 0)) // fleche right
        {
          if (p1.poshero.x < (ecran->w / 2) || b1.scroll.x >= (b1.scroll.w - ecran->w)) // deplacement
          {
            if (collisionPP(p1, b1.imageM, b1, I1) == 0) // pas de collision avec background
            {
              /**** update personage *****/
              p1.X++;
              mouvementright(&p1);
              p1.direction = 0;
              /** update mini map***/
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x += p1.poshero.x / 172;
            }
            //  if( collision bouding box)// collision avec enemie
            if (collision)
            {
              v++;
              ts--;
              if ((v == 7) || (ts < 0))
              {
                p.poshero.x -= 100;
              }
            }
            else
            {
              continuer = 1;
            }
          }
          else
          {
            if (collisionPP(p1, b1.imageM, b1, I1) == 0) // pas de collision
            {
              en1.posEnnemi.x -= p1.X;
              en1.posMax.x -= p1.X;
              en1.posMin.x -= p1.X;
              /*for(w=2;w<7;w++)
             {
              en1.posEnnemi[w].x-=p1.X;
              en1.posMax[w].x-=p1.X;
              en1.posMin[w].x-=p1.X;
              }*/
              printf("scrolling joueur1\n");
              p1.direction = 0;
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x += p1.poshero.x / 172;

              scrollingBack(&b1, p1, I1);
            }
          }
        }
        else if ((v1 != 7) && (I1.left == 1) && (test1 == 0) && (enigmeelf == 0) && (teststat == 0) && (somenu == 0) && (p4 == 0))
        {
          if ((b1.scroll.x >= 50 && b1.scroll.x < (b1.scroll.w - ecran->w)) || (b1.scroll.x == (b1.scroll.w - ecran->w) && p1.poshero.x <= 760))
          {
            if (collisionPP(p1, b1.imageM, b1, I1) == 0)
            {
              en1.posEnnemi.x += p1.X;
              en1.posMax.x += p1.X;
              en1.posMin.x += p1.X;
              /*for(w=2;w<7;w++)
              {
               en1.posEnnemi[w].x+=p1.X;
              en1.posMax[w].x+=p1.X;
              en1.posMin[w].x+=p1.X;
              }*/
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x -= p1.poshero.x / 172;
              p1.direction = 1;
              scrollingBack(&b1, p1, I1);
            }
          }
          else if (b1.scroll.x < 50 || b1.scroll.x >= (b1.scroll.w - ecran->w))
          {
            if (collisionPP(p1, b1.imageM, b1, I1) == 0)
            {
                 
              p1.X++;
              mouvementleft(&p1);
              p1.direction = 1;
              if (m.pospoint.x >= m.posminimap.x)
                m.pospoint.x -= p1.poshero.x / 172;
              if (p1.poshero.x <= 60)
              {
                p1.poshero.x = 60;
                m.pospoint.x = 100;
              }
            }
          }
        }
        //////////joueurrrrr2222222/////////
        if ((I2.right == 1) && (v2 != 7) && (test1 == 0) && (enigmeelf == 0) && (teststat == 0) && (p4 == 0)) // fleche right
        {
          if (p2.poshero.x < (ecran->w / 2) || b2.scroll.x >= (b2.scroll.w - ecran->w)) // deplacement
          {
            if (collisionPP(p2, b2.imageM, b2, I2) == 0) // pas de collision avec background
            {
              /**** update personage *****/
              p2.X++;
              mouvementright(&p2);
              p2.direction = 0;
              /** update mini map***/
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x += p2.poshero.x / 172;
            }
          }
          else
          {
            if (collisionPP(p2, b2.imageM, b2, I2) == 0) // pas de collision
            {
              en2.posEnnemi.x -= p2.X;
              en2.posMax.x -= p2.X;
              en2.posMin.x -= p2.X;
              /*for(w=2;w<7;w++)
              {
              en2.posEnnemi[w].x-=p2.X;
              en2.posMax[w].x-=p2.X;
              en2.posMin[w].x-=p2.X;
              }*/
              p2.direction = 0;
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x += p2.poshero.x / 172;
              scrollingBack(&b2, p2, I2);
            }
          }
        }
        else if ((v2 != 7) && (I2.left == 1) && (test1 == 0) && (enigmeelf == 0) && (teststat == 0) && (somenu == 0) && (p4 == 0))
        {
          if ((b2.scroll.x >= 50 && b2.scroll.x < (b2.scroll.w - ecran->w)) || (b2.scroll.x == (b2.scroll.w - ecran->w) && p2.poshero.x <= 760))
          {

            if (collisionPP(p2, b2.imageM, b2, I2) == 0)
            {
              en2.posEnnemi.x += p2.X;
              en2.posMax.x += p2.X;
              en2.posMin.x += p2.X;
              /*for(w=2;w<7;w++)
             {
              en2.posEnnemi[w].x+=p2.X;
              en2.posMax[w].x+=p2.X;
              en2.posMin[w].x+=p2.X;
              }*/
              if (m.pospoint.x <= m.posminimap.x + 1240)
                m.pospoint.x -= p2.poshero.x / 172;
              p2.direction = 1;
              scrollingBack(&b2, p2, I2);
            }
          }
          else if (b2.scroll.x < 50 || b2.scroll.x >= (b2.scroll.w - ecran->w))
          {
            if (collisionPP(p2, b2.imageM, b2, I2) == 0)
            {

              p2.X++;
              mouvementleft(&p2);
              p2.direction = 1;
              if (m.pospoint.x >= m.posminimap.x)
                m.pospoint.x -= p2.poshero.x / 172;
              if (p2.poshero.x <= 60)
              {
                p2.poshero.x = 60;
                m.pospoint.x = 100;
              }
            }
          }
        }
      }
    }
    if (multijoueur == 0)
    {
      if ((collisionPP(p, b.imageM, b, I) == 0))
      {
        if (I.jump == 1)
        {
          e.posEnnemi.y = 500;
        }
        else if (I.jump == 0)
        {
          e.posEnnemi.y = 500;
        }
        p.gravity = 400;
        p.jumpspeed = 35;
        jumpin(&p, &I, &b, multijoueur);

        gravity(&p, &I, &b, multijoueur, e);
      }
      else
      {
        p.gravity = 100;
        p.jumpspeed = 1;
        jumpin(&p, &I, &b, multijoueur);
        gravity(&p, &I, &b, multijoueur, e);
      }
      if ((p.direction == 0) && (collisionPP1(p, b.imageM, b, I) == 1))
      {

        v++;
        p.poshero.x -= 100;
        ts -= 10;
      }
      else if ((p.direction == 1) && (collisionPP1(p, b.imageM, b, I) == 1))
      {

        v++;
        p.poshero.x += 100;
        ts -= 10;
      }
    }
    if (multijoueur == 1)
    {
      if ((collisionPP(p1, b1.imageM, b1, I1) == 0))
      {
        p1.gravity = 230;
        p1.jumpspeed = 15;
        jumpin(&p1, &I1, &b1, multijoueur);
        gravity(&p1, &I1, &b1, multijoueur, e);
      }
      else
      {
        p1.gravity = 100;
        p1.jumpspeed = 1;
        jumpin(&p1, &I1, &b1, multijoueur);
        gravity(&p1, &I1, &b1, multijoueur, e);
      }

      if ((p1.direction == 0) && (collisionPP1(p1, b1.imageM, b1, I1) == 1))
      {

        v1++;
        p1.poshero.x -= 100;
        ts1 -= 10;
      }
      else if ((p1.direction == 1) && (collisionPP1(p1, b1.imageM, b1, I1) == 1))
      {

        v1++;
        p1.poshero.x += 100;
        ts1 -= 10;
      }
      if ((collisionPP(p2, b2.imageM, b2, I2) == 0))
      {
        p2.gravity = 630;
        p2.jumpspeed = 15;
        jumpin(&p2, &I2, &b2, multijoueur);
        gravity(&p2, &I2, &b2, multijoueur, e);
      }
      else
      {
        p2.gravity = 100;
        p2.jumpspeed = 1;
        jumpin(&p2, &I2, &b2, multijoueur);
        gravity(&p2, &I2, &b2, multijoueur, e);
      }
      if ((p2.direction == 0) && (collisionPP1(p2, b2.imageM, b2, I2) == 1))
      {

        v2++;
        p2.poshero.x -= 100;
        ts2 -= 10;
      }
      else if ((p2.direction == 1) && (collisionPP1(p2, b2.imageM, b2, I2) == 1))
      {

        v2++;
        p2.poshero.x += 100;
        ts2 -= 10;
      }
    }
    animerperso(&p, ecran, v, &I);
    animerperso(&p1, ecran, v1, &I1);
    animerperso(&p2, ecran, v2, &I2);
    update_ennemi(&e, p);

    dt = SDL_GetTicks() - t_prev;

    SDL_Flip(ecran);
    frame++;
    if (frame == 30)
    {
      if (temps > 0)
        temps--;
      frame = 0;
    }
    if (1000 / FPS > SDL_GetTicks() - start)
      SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
  }

  Mix_CloseAudio();
  SDL_FreeSurface(b.imgBack1);
  SDL_FreeSurface(b1.imgBack1);
  SDL_FreeSurface(b2.imgBack1);
  TTF_CloseFont(a.police);
  SDL_FreeSurface(a.fond_n);
  SDL_FreeSurface(a.fond);
  SDL_FreeSurface(a.jaune);
  SDL_FreeSurface(a.rouge);
  freesurface(&p);
  freesurface(&p1);
  freesurface(&p2);
  SDL_FreeSurface(vicde.victory);
  SDL_FreeSurface(vicde.defeat);
  SDL_FreeSurface(vicde.victory2);
  SDL_FreeSurface(vicde.defeat2);
  SDL_FreeSurface(m.minimap);
  SDL_FreeSurface(m.point);
  freemenu(&men);
  /*SDL_FreeSurface(e.sprite1);
	SDL_FreeSurface(e.sprite2);
	SDL_FreeSurface(e.sprite3);
	SDL_FreeSurface(e.sprite4);*/
  free_enigmealf(&ealf);
  free_enigmestat(&enig);
  free_enigmealea(&e1);
  FreeGrille(&g);
  TTF_Quit();
  SDL_Quit();
}
