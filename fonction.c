#include "background.h"
#include "hero.h"
void affichertemps(int temps, SDL_Surface *screen)
{

  TTF_Font *police = NULL;
  police = TTF_OpenFont("texxte.ttf", 28);
  SDL_Color couleur = {255, 255, 255};
  SDL_Rect postemps;
  postemps.x = 0;
  postemps.y = 0;
  char s[19];

  sprintf(s, "Time : %d", temps);
  SDL_Surface *txt;
  txt = TTF_RenderText_Blended(police, s, couleur);
  SDL_BlitSurface(txt, NULL, screen, &postemps);
}
void initmap(minimap *m)
{
  m->minimap = IMG_Load("minimap.PNG");
  m->posminimap.x = 100;
  m->posminimap.y = 40;
  m->point = IMG_Load("point.png");
  m->pospoint.x = 100;
  m->pospoint.y = 80;
}
void afficherminimap(minimap m, SDL_Surface *screen)
{
  SDL_BlitSurface(m.minimap, NULL, screen, &m.posminimap);
  SDL_BlitSurface(m.point, NULL, screen, &m.pospoint);
}
//x+imin y+tahbet

SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
  SDL_Color color;
  Uint32 col = 0;
  char *pPosition = (char *)pSurface->pixels;
  pPosition += (pSurface->pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy(&col, pPosition, pSurface->format->BytesPerPixel);
  SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
  return (color);
}
int collisionPP(perso p, SDL_Surface *Masque, Background b, Input I)
{
  SDL_Color col;
  if ((p.direction == 0) && (p.Y == 0)) //imin
  {
    col = GetPixel(Masque, p.poshero.x + (p.poshero.w - 30) + b.scroll.x, p.poshero.y + (p.tab1[5]->h / 2) + b.scroll.y);
    /* col = GetPixel(Masque, p.poshero.x + (p.poshero.w-70) + b.scroll.x, p.poshero.y + (p.tab1[5]->h * 1.2) + b.scroll.y);*/
  }

  else if ((p.direction == 1) && (p.Y == 0)) //isar
  {
    col = GetPixel(Masque, p.poshero.x + (p.poshero.w - 70) + b.scroll.x, p.poshero.y + (p.tab1[5]->h) / 2 + b.scroll.y);
    //col = GetPixel(Masque, p.poshero.x + (p.poshero.w-70) + b.scroll.x, p.poshero.y + (p.tab1[5]->h / 1.2) + b.scroll.y);
  }

  //lfou9
  //col=GetPixel(Masque,p.posperso.x+(p.perso->w/2) ,p.posperso.y);
  //louta
  else if ((p.Y != 0) && (I.jump == 1))
  {
    printf("collision veticale");
   col=GetPixel(Masque,p.poshero.x+(p.tab1[1]->w/2),p.poshero.y+p.tab1[5]->h );
  }
  if ((col.r == 0) && (col.b == 0) && (col.g == 0))
  {
    return 1;
  }

  else
    return 0;
}

int collisionPP1(perso p, SDL_Surface *Masque, Background b, Input I)
{
  SDL_Color col;
  if ((p.direction == 0) && (p.Y == 0)) //imin
  {
    col = GetPixel(Masque, p.poshero.x + (p.poshero.w - 30) + b.scroll.x, p.poshero.y + (p.tab1[5]->h / 2) + b.scroll.y);
    /* col = GetPixel(Masque, p.poshero.x + (p.poshero.w-70) + b.scroll.x, p.poshero.y + (p.tab1[5]->h * 1.2) + b.scroll.y);*/
  }

  else if ((p.direction == 1) && (p.Y == 0)) //isar
  {
    col = GetPixel(Masque, p.poshero.x + (p.poshero.w - 70) + b.scroll.x, p.poshero.y + (p.tab1[5]->h) / 2 + b.scroll.y);
    //col = GetPixel(Masque, p.poshero.x + (p.poshero.w-70) + b.scroll.x, p.poshero.y + (p.tab1[5]->h / 1.2) + b.scroll.y);
  }

  //lfou9
  //col=GetPixel(Masque,p.posperso.x+(p.perso->w/2) ,p.posperso.y);
  //louta
  else if ((p.Y != 0) && (I.jump == 1))
  {
    printf("collision veticale");
   col=GetPixel(Masque,p.poshero.x+(p.tab1[1]->w/2),p.poshero.y+p.tab1[5]->h );
  }
  if ((col.r == 0) && (col.b == 1) && (col.g == 255))
  {
    return 1;
  }

  else
    return 0;
}

void initi (init *a)
{
  a->police = NULL;

    SDL_Color couleur = {52, 201, 36};   //la couleur orange
    SDL_Color couleur_r = {187, 11, 11}; //la couleur rouge
    SDL_Color couleur_n = {0, 0, 0};     //la couleur blanche
  a-> pos.x = 500;
  a->pos.y = 400; //les positions du j_g,pc_g,gameover(texte)
   a->pos_n.x = 480;                       // les positions du fond sur lequel on va afficher un message
a->pos_n.y = 400;
    a->pos_ecran.x = 150; //position de l'ecran
    a->pos_ecran.y = 0;
   a->police = TTF_OpenFont("alger.TTF", 90);
    a->j_g = TTF_RenderText_Blended(a->police, "YOU WON", couleur);
    a->pc_g = TTF_RenderText_Blended(a->police, "YOU LOST", couleur_r);
   a->gameover = TTF_RenderText_Blended(a->police, "Game Over", couleur_n);

    a->fond = IMG_Load("puissance.png");
   a->fond_n = IMG_Load("fond.png");
   a->jaune = IMG_Load("jaune.png");
    a->rouge = IMG_Load("rouge.png");

}
void afficherfond(SDL_Surface *ecran,init a)
{ 
 SDL_BlitSurface(a.fond, NULL, ecran, &a.pos_ecran);
}








Casee afficher_jeton(SDL_Surface *screen, init a, SDL_Event event, int t[6][7]) //sert a afficher le contenu du tableau
{
    int i = 5; // les lignes
    Casee c;
    SDL_Rect pos;
    if ((event.motion.x > 175) && (event.motion.x < 276))//intervalle de col1 
    {
        pos.x = 175 - 300+a.pos_ecran.x ;//pos e lkoura
        c.c = 0;
    } //la case de la colonne (c.c)
    if ((event.motion.x > 306) && (event.motion.x < 399))
    {
        pos.x = 306 - 300+a.pos_ecran.x;
        c.c = 1;
    }
    if ((event.motion.x > 439) && (event.motion.x < 533))
    {
        pos.x = 439 - 300+a.pos_ecran.x;
        c.c = 2;
    }
    if ((event.motion.x > 571) && (event.motion.x < 667))
    {
        c.c = 3;
        pos.x = 571 - 300+a.pos_ecran.x;
    }
    if ((event.motion.x > 706) && (event.motion.x < 800))
    {
        c.c = 4;
        pos.x = 706 - 300+a.pos_ecran.x;
    }
    if ((event.motion.x > 838) && (event.motion.x < 934))
    {
        c.c = 5;
        pos.x = 838 - 300+a.pos_ecran.x;
    }
    if ((event.motion.x > 972) && (event.motion.x < 1068))
    {
        c.c = 6;
        pos.x = 972 - 300+a.pos_ecran.x;
    }
    while ((t[i][c.c] != 0) && (i > 0))
        i--;
    if (i == 0)
    {
        c.l = 0;
        pos.y = 22 - 5-a.pos_ecran.y;
    }
    if (i == 1)
    {
        pos.y = 154 - 5-a.pos_ecran.y;
        c.l = 1; //la premiere ligne
    }
    if (i == 2)
    {
        pos.y = 287 - 5-a.pos_ecran.y;
        c.l = 2;
    }
    if (i == 3)
    {
        c.l = 3;
        pos.y = 422 - 5-a.pos_ecran.y;
    }
    if (i == 4)
    {
        c.l = 4;
        pos.y = 554 - 5-a.pos_ecran.y;
    }
    if (i == 5)
    {
        c.l = 5;
        pos.y = 686 - 5-a.pos_ecran.y;
    }
    SDL_BlitSurface(a.rouge, NULL, screen, &pos);
    return c;
}
Casee IA(int t[6][7])
{
    Casee c;
    int i, j = 0, test = 0, test_i = 0;
    while ((j < 7) && (test == 0))
    {
        i = 5;
        while ((i > 2) && (test == 0))
        {
            if (((t[i][j] == 2) && (t[i - 1][j] == 2) && (t[i - 2][j] == 2)) && ((t[i - 3][j] == 0)))
            {
                test = 1;
           c.l = i - 3; //jaune gagne 
               c.c = j;
            }
            i--;
        }
        j++;
    }
    i = 5;
    while ((i > 0) && (test == 0))
    {
        j = 0;
        while ((j < 4) && (test == 0))
        {
            if (((t[i][j] == 2) && (t[i][j + 1] == 2) && (t[i][j + 2] == 2)) && ((t[i][j - 1] == 0) || (t[i][j + 3] == 0)) && ((t[i - 1][j + 3] != 0) || (t[i - 1][j - 1] != 0)))//nefhemhaaaa
            {
                if ((t[i][j - 1] == 0) && (j != 0) && (t[i - 1][j - 1] != 0))
                {
                    c.l = i; //jaune gagne h
                    c.c = j - 1;
                    test = 1;
                }
                if ((t[i][j + 3] == 0) && (t[i - 1][j + 3] != 0))
                {
                    c.l = i;
                    c.c = j + 3;
                    test = 1;
                }
            }
            j++;
        }
        i--;
    }
    j = 0;
//bloc a7mer 
    while ((j < 7) && (test == 0))
    {
        i = 5;
        while ((i > 2) && (test == 0))
        {
            if (((t[i][j] == 1) && (t[i - 1][j] == 1) && (t[i - 2][j] == 1)) && ((t[i - 3][j] == 0)))
            {
                test = 1;
                c.l = i - 3;
                c.c = j;
            } //bloc rouge 3
            i--;
        }
        j++;
    }
    i = 5;
    while ((i > 0) && (test == 0))
    {
        j = 0;
        while ((j < 5) && (test == 0))
        {
            if (((t[i][j] == 1) && (t[i][j + 1] == 1) && (t[i][j + 2] == 1)) && ((t[i][j - 1] == 0) || (t[i][j + 3] == 0)))
            {
                if ((t[i][j + 3] == 0) && ((t[i - 1][j + 3] != 0) || (i == 5)))
                {
                    test = 1;
                    c.l = i;
                    c.c = j + 3;//imin
                }
                if ((t[i][j - 1] == 0) && (j != 0) && ((t[i - 1][j - 1] != 0) || (i == 5))) //bloc rouge 3 h
                {
                    test = 1;
                    c.l = i;
                    c.c = j - 1;//essar
                }
            }
            j++;
        }
        i--;
    }
    j = 0;
//dim chance de victoire
    while ((j < 7) && (test == 0))
    {
        i = 5;
        while ((i > 1) && (test == 0))
        {

            if (((t[i][j] == 2) && (t[i - 1][j] == 2)) && ((t[i - 2][j] == 0)))
            {
                test = 1;
                c.l = i - 2;
                c.c = j;
            }
            i--;
        }
        j++;
    }
    i = 5;
    while ((i > 0) && (test == 0))
    {
        j = 0;
        while ((j < 5) && (test == 0))
        {
            if (((t[i][j] == 2) && (t[i][j + 1] == 2)) && ((t[i][j - 1] == 0) || (t[i][j + 2] == 0)))
            {
                if ((t[i][j - 1] == 0) && (j != 0) && ((t[i - 1][j - 1] != 0) || (i == 5)))
                {
                    test = 1;
                    c.l = i;
                    c.c = j - 1;
                }
                if ((t[i][j + 2] == 0) && ((t[i - 1][j + 2] != 0) || (i == 5)))
                {
                    test = 1;
                    c.l = i;
                    c.c = j + 2;
                }
            }
            j++;
        }
        i--;
    }
    j = 0;
    while ((j < 7) && (test == 0))
    {
        i = 5;
        while ((i > 0) && (test == 0))
        {
            if (((t[i][j] == 2)) && ((t[i - 1][j] == 0)))
            {
                test = 1;
                c.l = i - 1;
                c.c = j;
            }
            i--;
        }
        j++;
    }
    i = 5;
    while ((i > 0) && (test == 0))
    {
        j = 0;
        while ((j < 6) && (test == 0))
        {
            if ((t[i][j] == 2) && (((t[i][j - 1] == 0) || (t[i][j + 1] == 0))))   
            {

                if ((t[i][j - 1] == 0) && (j != 0) && ((t[i - 1][j - 1] != 0) || (i == 5)))
                {
                    test = 1;
                    c.l = i;
                    c.c = j - 1;
                }
                if ((t[i][j + 1] == 0) && ((t[i - 1][j + 1] != 0) || (i == 5)))
                {
                    test = 1;
                    c.l = i;
                    c.c = j + 1;
                }
            }
            j++;
        }
        i--;
    }
    j = rand() % 7;//<7
    while ((test == 0))
    {
        i = 5;
        while ((i > 0) && (test == 0))
        {
            if (t[i][j] == 0)
            {
                test = 1;
                c.c = j;
                c.l = i;
            }
            i--;
        }
        j++;
    }
    return c;
}
void afficher_jaune(SDL_Surface *screen, init a, Casee c)
{
    SDL_Rect pos;
    if (c.c == 0)
    {
        pos.x = 175 - 300+a.pos_ecran.x;
    }
    if (c.c == 1)
    {
        pos.x = 306 - 300+a.pos_ecran.x;
    }
    if (c.c == 2)
    {
        pos.x = 439 - 300+a.pos_ecran.x;
    }
    if (c.c == 3)
    {
        pos.x = 571 - 300+a.pos_ecran.x;
    }
    if (c.c == 4)
    {
        pos.x = 706 - 300+a.pos_ecran.x;
    }
    if (c.c == 5)
    {
        pos.x = 838 - 300+a.pos_ecran.x;
    }
    if (c.c == 6)
    {
        pos.x = 972 - 300+a.pos_ecran.x;
    }
    if (c.l == 0)
    {
        pos.y = 22 - 5-a.pos_ecran.y;
    }
    if (c.l == 1)
    {
        pos.y = 154 - 5-a.pos_ecran.y;
    }
    if (c.l == 2)
    {
        pos.y = 287 - 5-a.pos_ecran.y;
    }
    if (c.l == 3)
    {
        pos.y = 422 - 5-a.pos_ecran.y;
    }
    if (c.l == 4)
    {
        pos.y = 554 - 5-a.pos_ecran.y;
    }
    if (c.l == 5)
    {
        pos.y = 686 - 5-a.pos_ecran.y;
    }
    SDL_BlitSurface(a.jaune, NULL, screen, &pos);
}
int checkk(int t[7][7])
{
    int j_g = 0, pc_g = 0, test = 0, j = 0, i;
//horizontale
    while ((j_g == 0) && (pc_g == 0) && (j < 7))
    {
        i = 5;
        while ((i > 2) && (j_g == 0) && (pc_g == 0))
        {
            if ((t[i][j] == 1) && (t[i - 1][j] == 1) && (t[i - 2][j] == 1) && (t[i - 3][j] == 1))
                j_g = 1;
            if ((t[i][j] == 2) && (t[i - 1][j] == 2) && (t[i - 2][j] == 2) && (t[i - 3][j] == 2))
                pc_g = 1;
            i--;
        }
        j++;
    }
    i = 5;
//verticale
    while ((j_g == 0) && (pc_g == 0) && (i > 0))
    {
        j = 0;
        while ((j < 4) && (j_g == 0) && (pc_g == 0))
        {
            if ((t[i][j] == 1) && (t[i][j + 1] == 1) && (t[i][j + 2] == 1) && (t[i][j + 3] == 1))
                j_g = 1;
            if ((t[i][j] == 2) && (t[i][j + 1] == 2) && (t[i][j + 2] == 2) && (t[i][j + 3] == 2))
                pc_g = 1;
            j++;
        }
        i--;
    }
    j = 0;
//diagonale
    while ((j_g == 0) && (pc_g == 0) && (j < 4))
    {
        i = 5;
        while ((i > 2) && (j_g == 0) && (pc_g == 0))
        {
            if ((t[i][j] == 1) && (t[i - 1][j + 1] == 1) && (t[i - 2][j + 2] == 1) && (t[i - 3][j + 3] == 1))
                j_g = 1;
            if ((t[i][j] == 2) && (t[i - 1][j + 1] == 2) && (t[i - 2][j + 2] == 2) && (t[i - 3][j + 3] == 2))
                pc_g = 1;
            i--;
        }
        j++;
    }
    j = 3;
    while ((j_g == 0) && (pc_g == 0) && (j < 7))
    {
        i = 5;
        while ((i > 2) && (j_g == 0) && (pc_g == 0))
        {
            if ((t[i][j] == 1) && (t[i - 1][j - 1] == 1) && (t[i - 2][j - 2] == 1) && (t[i - 3][j - 3] == 1))
                j_g = 1;
            if ((t[i][j] == 2) && (t[i - 1][j - 1] == 2) && (t[i - 2][j - 2] == 2) && (t[i - 3][j - 3] == 2))
                pc_g = 1;
            i--;
        }
        j++;
    }
    if (j_g == 1)
        test = 1;
    if (pc_g == 1)
        test = 2;
    return test;
}

void afficherpuis1(init a)
{ 

 SDL_BlitSurface(a.fond_n, NULL, a.fond, &a.pos_n);
  SDL_BlitSurface(a.gameover, NULL, a.fond, &a.pos);
}
void afficherpuis2(init a)
{ 
  SDL_BlitSurface(a.fond_n, NULL, a.fond, &a.pos_n);
  SDL_BlitSurface(a.j_g, NULL, a.fond, &a.pos);
}
void afficherpuis3(init a)
{ 
                        SDL_BlitSurface(a.fond_n, NULL, a.fond, &a.pos_n);

                        SDL_BlitSurface(a.pc_g, NULL,a.fond, &a.pos);
}

void afficherpuis4(init a)
{ 

                            SDL_BlitSurface(a.fond_n, NULL, a.fond, &a.pos_n);

                            SDL_BlitSurface(a.gameover, NULL, a.fond, &a.pos);
}
void afficherpuis5(init a)
{ 

                            SDL_BlitSurface(a.fond_n, NULL, a.fond, &a.pos_n);

                            SDL_BlitSurface(a.j_g, NULL, a.fond, &a.pos);
}
void afficherpuis6(init a)
{ 

                            SDL_BlitSurface(a.fond_n, NULL, a.fond, &a.pos_n);
                             SDL_BlitSurface(a.pc_g, NULL, a.fond, &a.pos);
}

