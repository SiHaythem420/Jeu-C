#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

#include "hero.h"

void intialiser(menu *m,changeinput *inp)
{
  m->imgnewgame = NULL;
  m->imgloadgame = NULL;
  m->imgmultijoueur = NULL;
  m->imgnewgame2 = NULL;
  m->imgloadgame2 = NULL;
  m->imgmultijoueur2 = NULL;
  m->imgplay = NULL;
  m->imgoption = NULL;
 // m->imgbackground[12] = NULL;
  m->imgquit = NULL;
  m->imgcurseur = NULL;
  m->textecm = NULL;
  m->imgplay2 = NULL;
  m->imgoption2 = NULL;
  m->imgquit2 = NULL;
  m->seq = NULL;
  m->imgv100 = NULL;
  m->imgfullscreen = NULL;
  m->imgnormalscreen = NULL;
  m->imgfullscreen2 = NULL;
  m->imgnormalscreen2 = NULL;
  m->imgtxtaffichaage = NULL;
  m->imgtxtvolume = NULL;
  m->imgoption3 = NULL;
  m->imgv0 = NULL;
  m->imgv25 = NULL;
  m->imgv75 = NULL;
  m->imgv50 = NULL;
  m->imgicon = NULL;

  inp->imginput=NULL;
inp->imginput2=NULL;
inp->imginputB=NULL;
inp->imginputB2=NULL;
inp->imginputA2=NULL;
inp->imginputA=NULL;


inp->imginputAselected=NULL;
inp->imginputBselected=NULL;



  SDL_Surface *ecran = NULL;
  SDL_WM_SetCaption("", NULL);
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
  {
    printf("%s", Mix_GetError());
  }
    TTF_Font *police = NULL;
  SDL_Color couleurjaune = {255, 210, 130};
  TTF_Init();
  police = TTF_OpenFont("texxte.ttf", 20);
   m->textecm = TTF_RenderText_Blended(police, "", couleurjaune);

  m->musique = Mix_LoadMUS("BGmusic.mp3");
  Mix_PlayMusic(m->musique, -1);
  m->son = Mix_LoadWAV("clic.wav");
  m->imgplay = IMG_Load("imgplay1.png");
  m->imgoption = IMG_Load("imgoption1.png");
  m->imgquit = IMG_Load("imgquit1.png");

  m->imgplay2 = IMG_Load("imgplay2.png");
  m->imgoption2 = IMG_Load("imgoption2.png");
  m->imgquit2 = IMG_Load("imgquit2.png");

  m->imgfullscreen = IMG_Load("bouton_full_screen.png");
  m->imgnormalscreen = IMG_Load("bouton_normal.png");
  m->imgfullscreen2 = IMG_Load("bouton_full_screen_secondaire.png");
  m->imgnormalscreen2 = IMG_Load("bouton_normal_secondaire.png");

  m->imgtxtaffichaage = IMG_Load("texte_affichage.png");
  m->imgtxtvolume = IMG_Load("texte_volume.png");
 // m->imgoption3 = IMG_Load("barre_option.png");

  m->imgv0 = IMG_Load("barre_de_volume0.png");
  m->imgv25 = IMG_Load("barre_de_volume25.png");
  m->imgv50 = IMG_Load("barre_de_volume_50.png");
  m->imgv75 = IMG_Load("barre_de_volume_75.png");
  m->imgv100 = IMG_Load("barre_de_volume100.png");

  m->imgbackfull = IMG_Load("backround_full_screen.png");
  m->imgbackloading = IMG_Load("backround_loading.png");
  m->imgnewgame = IMG_Load("imgnewgame.png");
  m->imgnewgame2 = IMG_Load("imgnewgame2.png");
  m->imgloadgame = IMG_Load("imgloadgame.png");
  m->imgloadgame2 = IMG_Load("imgloadgame2.png");
  m->imgmultijoueur = IMG_Load("imgmultiplayer.png");
  m->imgmultijoueur2 = IMG_Load("imgmultiplayer2.png");
  






////////////animation////////
m->imgbackground1= NULL;
  m->imgbackground2= NULL;
  m->imgbackground3= NULL;
  m->imgbackground4= NULL;
  m->imgbackground5= NULL;
  m->imgbackground6= NULL;
  m->imgbackground7= NULL;
  m->imgbackground8= NULL;
  m->imgbackground9= NULL;
  m->imgbackground10= NULL;
  m->imgbackground11= NULL;





///////input////
inp->imginput = NULL;
  inp->imginput2 = NULL; 
  
  inp->imginputA = NULL;
  inp->imginputA2 = NULL; 

  
  inp->imginputB = NULL;
  inp->imginputB2 = NULL; 



inp->imginputAselected=NULL;
inp->imginputBselected=NULL;






m->imgbackground1 = IMG_Load("A1.jpg");
       m->imgbackground2 = IMG_Load("A2.jpg");
        m->imgbackground3 = IMG_Load("A3.jpg");
       m->imgbackground4 = IMG_Load("A4.jpg");
        m->imgbackground5 = IMG_Load("A5.jpg");
         m->imgbackground6 = IMG_Load("A6.jpg");
        m->imgbackground7 = IMG_Load("A7.jpg");
        m->imgbackground8 = IMG_Load("A8.jpg");
        m->imgbackground9 = IMG_Load("A9.jpg");
        m->imgbackground10 = IMG_Load("A10.jpg");
         m->imgbackground11 = IMG_Load("A11.jpg");




////input///
inp->imginput = IMG_Load("input.png");
  inp->imginput2 = IMG_Load("input2.png"); 
  
  inp->imginputA = IMG_Load("inputA.png");
  inp->imginputA2 = IMG_Load("inputA2.png"); 

  
  inp->imginputB = IMG_Load("inputB.png");
  inp->imginputB2 = IMG_Load("inputB2.png"); 


inp->imginputAselected=IMG_Load("inputAselected.png");
inp->imginputBselected=IMG_Load("inputBselected.png");


///////////////
  m->posbackground.x = 0;
  m->posbackground.y = 0;
  m->posbackground1.x = 0;
  m->posbackground1.y = 0;
  m->posbackground2.x = 0;
  m->posbackground2.y = 0; 
  m->posvolume.x = 100;
  m->posvolume.y = 400;
  m->posvolume2.x = 400;
  m->posvolume2.y = 400;
  m->posplay.x = 100;
  m->posplay.y = 370;
  m->posoption.x = 100;
  m->posoption.y = 500;
  m->posquit.x = 100;
  m->posquit.y = 630;
  m->posnewgame.x = 100;
  m->posnewgame.y = 370;
  m->posloadgame.x = 100;
  m->posloadgame.y = 500;
  m->posmultijoueur.x = 100;
  m->posmultijoueur.y = 630;
  //POSITION INTERFACE = 1 , MENU OPTION
  m->posaffichage.x = 290;
  m->posaffichage.y = 480;
  m->postextevolume.x = 290;
  m->postextevolume.y = 300;
  m->posfullscreen.x = 70;
  m->posfullscreen.y = 600;
  m->posnormalscreen.x = 450;
  m->posnormalscreen.y = 600;
  m->posoption2.x = 150;
  m->posoption2.y = 70;
  m->postextecm.x = 20;
   m->postextecm.y = 760;


////////input////
inp->posinput.x=900;
  inp->posinput.y=600;




  inp->posinputA.x = 100;
   inp->posinputA.y = 150;


  inp->posinputB.x = 100;
   inp->posinputB.y = 500;




  inp->posinputA2.x = 1230;
   inp->posinputA2.y = 770;


  inp->posinputB2.x = 1230;
   inp->posinputB2.y = 770;





inp->postext2.x=0;
inp->postext2.y=0;


SDL_Surface*    icon;
icon = SDL_LoadBMP("icon.bmp");
if (icon != 0)
        SDL_WM_SetIcon(icon, NULL);

}


















void affichagemenuanim (menu m, SDL_Surface *ecran,int *continuer)
{
int y,p,f, interface=0, n, z;
    int page=0;
    int fullscren=2;



   SDL_BlitSurface(m.imgbackground1, NULL, ecran, &m.posbackground); 
    SDL_BlitSurface(m.imgbackground2, NULL, m.imgbackground1, &m.posbackground);
   SDL_BlitSurface(m.imgbackground3, NULL, m.imgbackground2, &m.posbackground);
    SDL_BlitSurface(m.imgbackground4, NULL, m.imgbackground3, &m.posbackground);
    SDL_BlitSurface(m.imgbackground5, NULL, m.imgbackground4, &m.posbackground);
    SDL_BlitSurface(m.imgbackground6, NULL, m.imgbackground5, &m.posbackground);
    SDL_BlitSurface(m.imgbackground7, NULL, m.imgbackground6, &m.posbackground);
    SDL_BlitSurface(m.imgbackground8, NULL, m.imgbackground7, &m.posbackground);
    SDL_BlitSurface(m.imgbackground9, NULL, m.imgbackground8, &m.posbackground);
    SDL_BlitSurface(m.imgbackground10, NULL, m.imgbackground9, &m.posbackground);
   SDL_BlitSurface(m.imgbackground10, NULL, m.imgbackground10, &m.posbackground);
          
               //  motion(&page,continuer, m);
          
              
    
  
}






void affichage(int interface, int y, int f, int k, menu m, SDL_Surface *ecran, int n,changeinput inp,int chinp)
{



   


 if (interface == 0)
  {
     printf("interface 0\n");
    if (y == 0)
    {
       printf("y=0\n");

      SDL_BlitSurface(m.imgplay, NULL, ecran, &m.posplay);
      SDL_BlitSurface(m.imgoption, NULL, ecran, &m.posoption);
      SDL_BlitSurface(m.imgquit, NULL, ecran, &m.posquit);
      SDL_BlitSurface(m.textecm, NULL, ecran, &m.postextecm);
    }
    else if (y == 1)
    {
      SDL_BlitSurface(m.imgplay2, NULL, ecran, &m.posplay);
      SDL_BlitSurface(m.imgoption, NULL, ecran, &m.posoption);
      SDL_BlitSurface(m.imgquit, NULL, ecran, &m.posquit);
      SDL_BlitSurface(m.textecm, NULL, ecran, &m.postextecm);
      Mix_PlayChannel(0, m.son, 0);
    }
    else if (y == 2)
    {
      Mix_PlayChannel(0, m.son, 0);
      SDL_BlitSurface(m.imgplay, NULL, ecran, &m.posplay);
      SDL_BlitSurface(m.imgoption2, NULL, ecran, &m.posoption);
      SDL_BlitSurface(m.imgquit, NULL, ecran, &m.posquit);
      SDL_BlitSurface(m.textecm, NULL, ecran, &m.postextecm);
    }

    else if (y == 3)
    {
      SDL_BlitSurface(m.imgplay, NULL, ecran, &m.posplay);
      SDL_BlitSurface(m.imgoption, NULL, ecran, &m.posoption);
      SDL_BlitSurface(m.imgquit2, NULL, ecran, &m.posquit);
      SDL_BlitSurface(m.textecm, NULL, ecran, &m.postextecm);
      Mix_PlayChannel(0, m.son, 0);
    }

   // SDL_Flip(ecran);
  }
  
  
  else if (interface == 1)
  {
    SDL_BlitSurface(inp.imginput, NULL, ecran, &inp.posinput);
   

    if (y == 0)
    {          

      SDL_BlitSurface(m.imgv100, NULL, ecran, &m.posvolume);
      SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
      SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
      SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
      SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
      SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
    }
    
     else if (y == 1)
    {
      switch (k)
      {
      case 0:
         SDL_BlitSurface(inp.imginput, NULL, ecran, &inp.posinput);
        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
        SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
        SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
        SDL_BlitSurface(m.imgv0, NULL, ecran, &m.posvolume);

        Mix_PauseMusic();

        break;
      case 1:
                SDL_BlitSurface(inp.imginput, NULL, ecran, &inp.posinput);

        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
        SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
        SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
        SDL_BlitSurface(m.imgv25, NULL, ecran, &m.posvolume);
        Mix_ResumeMusic();
        Mix_VolumeMusic(MIX_MAX_VOLUME / 4);

        break;
      case 2:
                SDL_BlitSurface(inp.imginput, NULL, ecran, &inp.posinput);

        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
        SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
        SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
        SDL_BlitSurface(m.imgv50, NULL, ecran, &m.posvolume);
        Mix_ResumeMusic();
        Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
        break;
      case 3:
         SDL_BlitSurface(inp.imginput, NULL, ecran, &inp.posinput);
        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
        SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
        SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
        SDL_BlitSurface(m.imgv75, NULL, ecran, &m.posvolume);
        Mix_ResumeMusic();
        Mix_VolumeMusic((MIX_MAX_VOLUME * 3) / 4);
        break;
      case 4:

         SDL_BlitSurface(inp.imginput, NULL, ecran, &inp.posinput);
        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
        SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
        SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
        SDL_BlitSurface(m.imgv100, NULL, ecran, &m.posvolume);
        Mix_ResumeMusic();
        Mix_VolumeMusic(MIX_MAX_VOLUME);
        break;
      }
    }
    
    else if (y == 2) // son
    {  
 SDL_BlitSurface(m.textecm, NULL, ecran, &m.postextecm);
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
      switch (f)
      {
      case 0:

        switch (k)
        {
        case 0:
        
     
          SDL_BlitSurface(m.imgv0, NULL, ecran, &m.posvolume);

          Mix_PauseMusic();

          break;
        case 1:
         
  
          SDL_BlitSurface(m.imgv25, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 4);

          break;
        case 2:
     
          SDL_BlitSurface(m.imgv50, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
          break;
        case 3:
       
     
          SDL_BlitSurface(m.imgv75, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic((MIX_MAX_VOLUME * 3) / 4);
          break;
        case 4:
        
    
          SDL_BlitSurface(m.imgv100, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME);
          break;
        }
        
        SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
        SDL_BlitSurface(m.imgfullscreen2 , NULL, ecran, &m.posfullscreen);
        Mix_PlayChannel(0, m.son, 0);
      
        break;
      
      case 1:

        switch (k)
        {
        case 0:
          SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
          SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv0, NULL, ecran, &m.posvolume);

          Mix_PauseMusic();

          break;
        case 1:
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv25, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 4);

          break;
        case 2:
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv50, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
          break;
        case 3:
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv75, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic((MIX_MAX_VOLUME * 3) / 4);
          break;
        case 4:
          SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
          SDL_BlitSurface(m.imgv100, NULL, ecran, &m.posvolume);
          Mix_ResumeMusic();
          Mix_VolumeMusic(MIX_MAX_VOLUME);
          break;
        }
        
        
        SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
        SDL_BlitSurface(m.imgnormalscreen2, NULL, ecran, &m.posnormalscreen);
        
        Mix_PlayChannel(0, m.son, 0);
        
        
        break;
      }


    
      switch (n)
      {
      case 1: // affichage fullscreen
  
            //ecran = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
	    SDL_WM_ToggleFullScreen(ecran);
           //SDL_BlitSurface(m.imgbackfull, NULL, ecran, &m.posbackground1);
           //ecran= SDL_SetVideoMode(1399,787,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
           //SDL_BlitSurface(m.imgbackfull, NULL, ecran, &m.posbackground1);
        break;
      
      case 2:
        
          ecran = SDL_SetVideoMode(1399, 787, 32, SDL_HWSURFACE| SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
         //ecran= SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);        
       // SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
       // SDL_BlitSurface(m.imgnormalscreen2, NULL, ecran, &m.posnormalscreen);
        break;
      }
    }
   


else if (y == 4) //input//
{  SDL_BlitSurface(inp.imginput2, NULL, ecran, &inp.posinput);
 SDL_BlitSurface(m.imgnormalscreen, NULL, ecran, &m.posnormalscreen);
          SDL_BlitSurface(m.imgfullscreen, NULL, ecran, &m.posfullscreen);
          SDL_BlitSurface(m.textecm, NULL, ecran, &m.postextecm);

           SDL_BlitSurface(m.imgtxtvolume, NULL, ecran, &m.postextevolume);
          SDL_BlitSurface(m.imgtxtaffichaage, NULL, ecran, &m.posaffichage);
          SDL_BlitSurface(m.imgoption3, NULL, ecran, &m.posoption2);
   switch (k)
        {
       
        case 0:
          
          SDL_BlitSurface(m.imgv0, NULL, ecran, &m.posvolume);


          break;
        case 1:
      
          SDL_BlitSurface(m.imgv25, NULL, ecran, &m.posvolume);
        

          break;
        case 2:
          
          SDL_BlitSurface(m.imgv50, NULL, ecran, &m.posvolume);
         
          break;
        case 3:
         
          SDL_BlitSurface(m.imgv75, NULL, ecran, &m.posvolume2);
       
          break;
        case 4:
         
          SDL_BlitSurface(m.imgv100, NULL, ecran, &m.posvolume2);
          
          break;
        }
    
 
     



                }







    //SDL_Flip(ecran);
  }
  
  
  
  ///////////////////////////////////////////////////////////////////////
  
  
  else if (interface == 2)                ///interface tee play//////////
  {
  
    if (y == 0)   //0 bouton active
    {

      SDL_BlitSurface(m.imgnewgame, NULL, ecran, &m.posnewgame); //new game Normal
      SDL_BlitSurface(m.imgloadgame, NULL, ecran, &m.posloadgame); //load game Normal
      SDL_BlitSurface(m.imgmultijoueur, NULL, ecran, &m.posmultijoueur); //multijoueurs Normal
    }
    else if (y == 1) //new game
    {
      
      SDL_BlitSurface(m.imgnewgame2, NULL, ecran, &m.posnewgame); //new game bleu
      SDL_BlitSurface(m.imgloadgame, NULL, ecran, &m.posloadgame); //load game Normal
      SDL_BlitSurface(m.imgmultijoueur, NULL, ecran, &m.posmultijoueur); //multijoueurs NaNormal
      Mix_PlayChannel(0, m.son, 0);
    }
    else if (y == 2)  //load game
    {

      
      SDL_BlitSurface(m.imgnewgame, NULL, ecran, &m.posnewgame);
      SDL_BlitSurface(m.imgloadgame2, NULL, ecran, &m.posloadgame);
      SDL_BlitSurface(m.imgmultijoueur, NULL, ecran, &m.posmultijoueur);
      Mix_PlayChannel(0, m.son, 0);
    }

    else if (y == 3) //multijoueur
    {

      SDL_BlitSurface(m.imgnewgame, NULL, ecran, &m.posnewgame);
      SDL_BlitSurface(m.imgloadgame, NULL, ecran, &m.posloadgame);
      SDL_BlitSurface(m.imgmultijoueur2, NULL, ecran, &m.posmultijoueur);
      Mix_PlayChannel(0, m.son, 0);
    }
 }
 
 






else if (interface == 3)                ///interface tee input //////////
  {
 
 

  SDL_BlitSurface(inp.imginputA, NULL, ecran, &inp.posinputA); //input A tech3l bl azrek//

                  SDL_BlitSurface(inp.imginputB, NULL, ecran, &inp.posinputB); 
  
         
 if(y==1)

  {SDL_BlitSurface(inp.imginputA2, NULL, ecran, &inp.posinputA); //input A tech3l bl azrek//

                  SDL_BlitSurface(inp.imginputB, NULL, ecran, &inp.posinputB); 
  }
                    





 else if (y==2)
                       {SDL_BlitSurface(inp.imginputB2, NULL, ecran, &inp.posinputB); //input b tech3l bl azrek//

                         SDL_BlitSurface(inp.imginputA, NULL, ecran, &inp.posinputA); 
 

                       }



    if(chinp==1) { 
              SDL_BlitSurface(inp.imginputBselected, NULL, ecran, &inp.postext2); 
                             
                              }

else if (chinp==2){

  SDL_BlitSurface(inp.imginputAselected, NULL, ecran, &inp.postext2); 
                              
                   }





  }

















}
void freemenu(menu *m)
{
    SDL_FreeSurface(m->imgplay) ;
    SDL_FreeSurface(m->imgoption);
     SDL_FreeSurface(m->imgbackground10);
   SDL_FreeSurface(m->imgbackground11);
    SDL_FreeSurface(m->imgbackground9);
   SDL_FreeSurface(m->imgbackground8);
    SDL_FreeSurface(m->imgbackground7);
   SDL_FreeSurface(m->imgbackground6);
    SDL_FreeSurface(m->imgbackground5);
   SDL_FreeSurface(m->imgbackground4);
    SDL_FreeSurface(m->imgbackground2);
    SDL_FreeSurface(m->imgbackground3);
   SDL_FreeSurface(m->imgbackground1);
    SDL_FreeSurface(m->imgquit) ;
    SDL_FreeSurface(m->imgcurseur) ;
    SDL_FreeSurface(m->textecm );
    SDL_FreeSurface(m->imgplay2 );
    SDL_FreeSurface(m->imgoption2) ;
    SDL_FreeSurface(m->imgquit2) ;
    SDL_FreeSurface(m->seq);
    SDL_FreeSurface(m->imgv100) ;
    SDL_FreeSurface(m->imgfullscreen);
    SDL_FreeSurface(m->imgnormalscreen) ;
    SDL_FreeSurface(m->imgfullscreen2) ;
    SDL_FreeSurface(m->imgnormalscreen2) ;
    SDL_FreeSurface(m->imgtxtaffichaage) ;
    SDL_FreeSurface(m->imgtxtvolume)  ;
    SDL_FreeSurface(m->imgoption3) ;
    SDL_FreeSurface(m->imgv0) ;
    SDL_FreeSurface(m->imgv25) ;
    SDL_FreeSurface(m->imgv75) ;
    SDL_FreeSurface(m->imgv50) ;
    SDL_FreeSurface(m->imgicon);
    SDL_FreeSurface(m->imgbackfull);
    SDL_FreeSurface(m->imgbackloading);
  Mix_FreeChunk(m->son);
 Mix_FreeMusic(m->musique);
  }




