#ifndef ENIGMESTAT_H_INCLUDED
#define ENIGMESTAT_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>

#define NUMBER_OF_TILES 3
#define HEIGHT_CELL 128
#define WIDTH_CELL 128

typedef short bool;
#define true 1
#define false 0

enum {FREE = 0, PLAYER1 = 1, PLAYER2 = 2};

typedef struct
{
    SDL_Surface *image;
    SDL_Rect pos[NUMBER_OF_TILES];
}
tileset_t;

typedef struct
{
    int board[3][3];
    SDL_Surface *screen;
    tileset_t tileset;
}
grille;

void InitGrille(grille *g);
void FreeGrille(grille *g);

bool complete(const int board[3][3]);
bool ligneOK(const int board[3][3], int row);
bool coloneOK(const int board[3][3], int column);
bool diagonaleOK(const int board[3][3]);
bool perdu(const int board[3][3], bool *exaequo);

void Play(grille *g, int *v);
void Player1(grille *g);
void Player2(grille *g);

void BlitAll(grille *g);

typedef struct
{
    
    SDL_Surface *image,*dev;
    SDL_Surface *texte1,*texte2,*texte3,*repvrai,*repfausse;
    TTF_Font *police;
    SDL_Rect posim,post1,post2,post3,posdev,posrep;
}enigme;

void init_enigme(enigme *enig);


void afficher_enigme(SDL_Surface *ecran,enigme enig);

void rep_vrai(SDL_Surface *ecran, enigme enig);

void rep_fausse(SDL_Surface *ecran, enigme enig);

void free_enigmestat(enigme *enig);
#endif // ENIGMESTAT_H_INCLUDED

