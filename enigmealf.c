#include "enigmealf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "hero.h"
#include "background.h"
#include "ennemi.h"

//intialisation des outils
void initialiser_enigmealf(enigmealf *ealf)
{

    SDL_Color couleurblanche = {255, 255, 255};

    ealf->poscurseur.x = 0;
    ealf->poscurseur.y = 0;
    ealf->police = NULL;
    ealf->policef = NULL;

    ealf->passeng = NULL;
    ealf->faileng = NULL;

    ealf->noeng = NULL;
    ealf->yeseng = NULL;
    ealf->imgeng = NULL;
    ealf->texteng = NULL;

    ealf->barre = NULL;
    ealf->EXIT = NULL;            
    ealf->resume = NULL;
    ealf->Save = NULL;

    ealf->posbarre.x = 275;
    ealf->posbarre.y = 80;

    ealf->posEXIT.x = 520;
    ealf->posEXIT.y = 250;

    ealf->posresume.x = 220;
    ealf->posresume.y = 250;

    ealf->posSave.x = 370;
    ealf->posSave.y = 250;
    
    
    
    

    ealf->posimg.x = 300;
    ealf->posimg.y = 0;

    ealf->poseng.x = ealf->posimg.x + 80;
    ealf->poseng.y = 150;

    ealf->posyes.x = ealf->posimg.x + 100;
    ealf->posyes.y = 500;

    ealf->posno.x = ealf->posimg.x + 400;
    ealf->posno.y = 500;

    ealf->posfail.x = ealf->posimg.x + 300;
    ealf->posfail.y = 350;

    ealf->pospass.x = ealf->posimg.x + 200;
    ealf->pospass.y = 350;

ealf->postexteSave.x=ealf->posSave.x+20;
ealf->postexteSave.y=ealf->posSave.y+100;
ealf->postexteresume.x=ealf->posresume.x+10;
ealf->postexteresume.y=ealf->posresume.y+100;
ealf->postexteEXIT.x=ealf->posEXIT.x+30;
ealf->postexteEXIT.y=ealf->posSave.y+100;
    ealf->police = TTF_OpenFont("texxte.ttf", 70);
    ealf->policef = TTF_OpenFont("texxte.ttf", 100);
ealf->policefb = TTF_OpenFont("texxte.ttf", 30);
    ealf->yeseng = TTF_RenderText_Blended(ealf->police, "YES", couleurblanche);
    ealf->noeng = TTF_RenderText_Blended(ealf->police, "NO", couleurblanche);

    ealf->passeng = TTF_RenderText_Blended(ealf->policef, "PASS", couleurblanche);
    ealf->faileng = TTF_RenderText_Blended(ealf->policef, "FAIL", couleurblanche);
    
    ealf->texteEXIT = TTF_RenderText_Blended(ealf->policefb, "exit", couleurblanche);

    ealf->texteresume = TTF_RenderText_Blended(ealf->policefb, "resume", couleurblanche);
    ealf->textesave = TTF_RenderText_Blended(ealf->policefb, "save", couleurblanche);

    ealf->imgeng = IMG_Load("enigmealf.png");

    ealf->barre = IMG_Load("barre.png");

    ealf->EXIT = IMG_Load("EXIT.png");

    ealf->resume = IMG_Load("Resume.png");

    ealf->Save = IMG_Load("SAVe.png");
}
//Afficher enigmealf genere
void afficherenigmealf(enigmealf ealf, SDL_Surface *ecran)
{

    SDL_BlitSurface(ealf.imgeng, NULL, ecran, &(ealf.posimg));
    SDL_BlitSurface(ealf.texteng, NULL, ecran, &(ealf.poseng));
    SDL_BlitSurface(ealf.yeseng, NULL, ecran, &(ealf.posyes));
    SDL_BlitSurface(ealf.noeng, NULL, ecran, &(ealf.posno));
}
//Generer enigmealf alea de fichier
void genererenigmealf(enigmealf *ealf)

{
    SDL_Color couleurblanche = {255, 255, 255};
    int i, al, trouve = 0, j;
    srand(time(NULL));
    al = rand() % 4;
    FILE *enigmealfal = NULL;
    enigmealfal = fopen("enigmealfe.txt", "r");
    if (enigmealfal != NULL)
    {
        for (i = 0; !feof(enigmealfal) && !trouve; i++)
        {
            fscanf(enigmealfal, "%s\n%d\n%d", ealf->question, &ealf->reponse, &j);

            if (j == al)
            {

                trouve = 1;
            }
        }
        ealf->texteng = TTF_RenderText_Blended(ealf->police, ealf->question, couleurblanche);

        fclose(enigmealfal);
    }
    else
        printf("\n ERREUR : verifier le nom du enigmealfal :");
}
//Afficher True
void afficher_true(SDL_Surface *ecran, enigmealf ealf)
{
    SDL_BlitSurface(ealf.imgeng, NULL, ecran, &(ealf.posimg));
    SDL_BlitSurface(ealf.passeng, NULL, ecran, &(ealf.pospass));
}
//Afficher false
void afficher_false(SDL_Surface *ecran, enigmealf ealf)
{
    SDL_BlitSurface(ealf.imgeng, NULL, ecran, &(ealf.posimg));
    SDL_BlitSurface(ealf.faileng, NULL, ecran, &(ealf.pospass));
}
//Free memory
void free_enigmealf(enigmealf *ealf)
{
    SDL_FreeSurface(ealf->faileng);
    SDL_FreeSurface(ealf->noeng);
    SDL_FreeSurface(ealf->texteng);
    SDL_FreeSurface(ealf->yeseng);
    TTF_CloseFont(ealf->police);
    SDL_FreeSurface(ealf->texteresume);
    SDL_FreeSurface(ealf->resume);
    SDL_FreeSurface(ealf->Save);
    SDL_FreeSurface(ealf->texteEXIT);
    SDL_FreeSurface(ealf->textesave);
    SDL_FreeSurface(ealf->EXIT);
    SDL_FreeSurface(ealf->barre);
}

void load(perso *p, Background *b,Ennemi *e, minimap *m, int *ts, int *v,int *reponsejuste,int *r,int *reponsevraie)
{
    FILE *saveF = NULL;
    saveF = fopen("sauvegarde.txt", "r"); // Ouverture du fichier sauvegarde en lecture

    if (saveF != NULL)
    { // Recuperation des positions du joueur
        fscanf(saveF, "%d", v);
        //printf("%d\n", *v);
        fscanf(saveF, "%hd", &b->scroll.x);
       // printf("%hd\n", b->scroll.x);
        fscanf(saveF, "%hd", &b->scroll.y);
        fscanf(saveF, "%d", ts);
        //printf("%d\n", *ts);
        fscanf(saveF, "%hd", &p->poshero.x);
        fscanf(saveF, "%hd", &p->poshero.x);
        fscanf(saveF, "%hd", &m->pospoint.x);
        fscanf(saveF, "%hd", &m->pospoint.y);
        fscanf(saveF, "%d", &p->X);
        fscanf(saveF, "%hd",&e->posEnnemi.x);
        fscanf(saveF, "%hd",&e->posEnnemi.y);
        fscanf(saveF, "%hd",&e->posMax.x);
        fscanf(saveF, "%hd",&e->posMax.y);
        fscanf(saveF, "%hd",&e->posMin.x);
        fscanf(saveF, "%hd",&e->posMin.y);

                fscanf(saveF, "%d",reponsejuste);
                fscanf(saveF, "%d",r);
               fscanf(saveF, "%d",reponsevraie);



    }

    fclose(saveF); // Fermeture du fichier
}
void save(perso p, Background b,Ennemi e, minimap m, int ts, int v,int reponsejuste,int r,int reponsevraie)
{
    FILE *saveF = NULL;
    saveF = fopen("sauvegarde.txt", "w"); // Ouverture en écriture du fichier sauvegarde.txt

    if (saveF != NULL)
    { // Ecriture dans le fichier des positions du joueur et score

        // b.scroll.x+=300;
        p.X += 300;
        fprintf(saveF, "%d\n", v);
        fprintf(saveF, "%d\n", b.scroll.x);
        fprintf(saveF, "%d\n", b.scroll.y);
        fprintf(saveF, "%d\n", ts);
        fprintf(saveF, "%d\n", p.poshero.x);
        fprintf(saveF, "%d\n", p.poshero.y);
        fprintf(saveF, "%d\n", m.pospoint.x);
        fprintf(saveF, "%d\n", m.pospoint.y);
        fprintf(saveF, "%d\n", p.X);
        fprintf(saveF, "%d\n", e.posEnnemi.x);
        fprintf(saveF, "%d\n", e.posEnnemi.y);
        fprintf(saveF, "%d\n", e.posMax.x);
        fprintf(saveF, "%d\n", e.posMax.y);
        fprintf(saveF, "%d\n", e.posMin.x);
        fprintf(saveF, "%d\n", e.posMin.y);
          fprintf(saveF, "%d\n",reponsejuste);
                fprintf(saveF, "%d\n",r);
               fprintf(saveF, "%d\n",reponsevraie);
    }

    fclose(saveF); // Fermeture du fichier
}

void afficher_sousmenu(enigmealf ealf,SDL_Surface *ecran)
{
    SDL_BlitSurface(ealf.barre, NULL, ecran, &(ealf.posbarre));
    SDL_BlitSurface(ealf.Save, NULL, ealf.barre, &(ealf.posSave));
    SDL_BlitSurface(ealf.EXIT, NULL, ealf.barre, &(ealf.posEXIT));
    SDL_BlitSurface(ealf.resume, NULL, ealf.barre, &(ealf.posresume));
    SDL_BlitSurface(ealf.textesave, NULL, ealf.barre, &(ealf.postexteSave));
    SDL_BlitSurface(ealf.texteEXIT, NULL, ealf.barre, &(ealf.postexteEXIT));
    SDL_BlitSurface(ealf.texteresume, NULL, ealf.barre, &(ealf.postexteresume));

}
