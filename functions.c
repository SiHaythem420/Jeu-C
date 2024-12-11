#include "enigmestat.h"
#include <stdio.h>

void InitGrille(grille *g)
{
    const char *lTilesets[] = {"Tileset2.bmp"};
    int i, j;
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Unable to load SDL ! %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    atexit(SDL_Quit);
    for(i = 0; i < 3; ++i)
        for(j = 0; j < 3; ++j)
            g->board[i][j] = FREE;
    g->screen = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    
  /*  if(g->screen == NULL)
    {
        fprintf(stderr, "Unable to create the main surface : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    } */
  g->tileset.image = SDL_LoadBMP(lTilesets[0]);
    /*if(g->tileset.image == NULL)
    {
        fprintf(stderr, "Unable to load the tileset image ! %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    } */
    for(i = 0; i < NUMBER_OF_TILES; ++i)
    {
        g->tileset.pos[i].h = HEIGHT_CELL;
        g->tileset.pos[i].w = WIDTH_CELL;
        g->tileset.pos[i].x = i*WIDTH_CELL;
        g->tileset.pos[i].y = 0;
    }
}

void FreeGrille(grille *g)
{
    SDL_FreeSurface(g->tileset.image);
    g->tileset.image = NULL;
}

bool complete(const int board[3][3])
{
    int i, j;
    for(i = 0; i < 3; ++i)
        for(j = 0; j < 3; ++j)
            if(board[i][j] == FREE)
                return false;
    return true;
}

bool ligneOK(const int board[3][3], int row)
{
    int i;
    int test = board[row][0];
    if(test == FREE)
        return false;
    for(i = 0; i < 3; ++i)
        if(board[row][i] != test)
            return false;
    return true;
}

bool coloneOK(const int board[3][3], int col)
{
    int i;
    int test = board[0][col];
    if(test == FREE)
        return false;
    for(i = 0; i < 3; ++i)
        if(board[i][col] != test)
            return false;
    return true;
}

bool diagonaleOK(const int board[3][3])
{
    bool ret = true;
    int i;
    int test = board[0][0];
    if(test == FREE)
        ret = false;
    if(ret)
    {
        for(i = 0; i < 3; ++i)
            if(board[i][i] != test)
                    ret = false;
    }
    if(ret)
        return true;
    test = board[0][2];
    if(test == FREE)
        return false;
    for(i = 0; i < 3; ++i)
        if(board[i][2-i] != test)
                return false;
    return true;
}

bool perdu(const int board[3][3], bool *exaequo)
{
    int i;
    *exaequo = false;
    for(i = 0; i < 3; ++i)
        if(ligneOK(board, i) || coloneOK(board, i))
            return true;
    if(diagonaleOK(board))
        return true;
    *exaequo = true;
    if(complete(board))
        return true;
    return false;
}

void Player1(grille *g)
{
    SDL_Event e;
    do
        SDL_WaitEvent(&e);
    while(e.type != SDL_MOUSEBUTTONDOWN || e.button.button != SDL_BUTTON_LEFT || g->board[e.button.y/HEIGHT_CELL][e.button.x/WIDTH_CELL] != FREE);
    g->board[e.button.y/HEIGHT_CELL][e.button.x/WIDTH_CELL] = PLAYER1;
}

void Player2(grille *g)
{
    int board_tmp[3][3];
    int x, y;
    bool exaequo;
    for(y = 0; y < 3; ++y)
        for(x = 0; x < 3; ++x)
            board_tmp[y][x] = g->board[y][x];
    for(y = 0; y < 3; ++y)
    {
        for(x = 0; x < 3; ++x)
        {
            if(board_tmp[y][x] == FREE)
            {
                board_tmp[y][x] = PLAYER1;
                if(perdu((const int(*)[3])board_tmp, &exaequo))
                {
                    g->board[y][x] = PLAYER2;
                    return;
                }
                board_tmp[y][x] = PLAYER2;
               if(perdu((const int(*)[3])board_tmp, &exaequo))
                {
                    g->board[y][x] = PLAYER1;
                    return;
                }   
                board_tmp[y][x] = FREE;
            }
        }
    }
    do
    {
        x = rand()%3;
        y = rand()%3;
    }
    while(g->board[y][x] != FREE);
    g->board[y][x] = PLAYER2;
}

void Play(grille *g, int *v)
{
    int lastplayer;
    bool exaequo;
    static char title[] = "Player 0 gagne !";
    while(!perdu((const int(*)[3])g->board, &exaequo))
    {
        BlitAll(g);
        SDL_Flip(g->screen);
        Player1(g);
        lastplayer = 1;
       
        if(!perdu((const int(*)[3])g->board, &exaequo))
        {
            
            BlitAll(g);
          // SDL_Flip(g->screen);
           // SDL_Delay(500);
            Player2(g);
            lastplayer = 2;
        }
       else 
          break;
        
            
    }
    BlitAll(g);
    //SDL_Flip(g->screen);
    if(!exaequo)
    {
        title[7] = lastplayer + '0';
    }
   

 switch(lastplayer)
  {
     case 1:
        *v-=2;
     break;
     case 2:
        *v+=1;
     break;
     default:
         *v+=1;
      break;
   } 
     
}

void BlitAll(grille *g)
{
    int i, j;
    SDL_Rect dst;
    for(i = 0; i < 3; ++i)
    {
        dst.x = i*WIDTH_CELL;
        for(j = 0; j < 3; ++j)
        {
            dst.y = j*HEIGHT_CELL;
            SDL_BlitSurface(g->tileset.image, &g->tileset.pos[g->board[j][i]], g->screen, &dst);
        }
    }
}
