prog:background.o main.o fonction.o hero.o enigmealeatoire.o enigmealf.o enigmestat.o jeux.o ennemi.o functions.o enigme.o fichier.o
	gcc  background.o main.o fonction.o hero.o enigmealeatoire.o enigmealf.o enigmestat.o jeux.o ennemi.o functions.o enigme.o fichier.o -o prog -g  -L/usr/include/SDL -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_gfx -g
main.o:main.c	
	gcc -c main.c -g  -I/usr/include/SDL -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_gfx -g
background.o:background.c
	gcc -c background.c -g  -I/usr/include/SDL -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_gfx -g
fonction.o:fonction.c
	gcc -c fonction.c -g  -I/usr/include/SDL -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_gfx -g
hero.o:hero.c
	gcc -c hero.c -g  -I/usr/include/SDL -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_gfx -g	
enigmealeatoire.o:enigmealeatoire.c
	gcc -c enigmealeatoire.c -g  -I/usr/include/SDL -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_gfx -g
enigmealf.o:enigmealf.c
	gcc -c enigmealf.c -g  -I/usr/include/SDL -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_gfx -g	
enigmestat.o:enigmestat.c
	gcc -c enigmestat.c -g  -I/usr/include/SDL -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_gfx -g
jeux.o:jeux.c
	gcc -c jeux.c -g  -I/usr/include/SDL -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_gfx -g
ennemi.o:ennemi.c	
	gcc -c ennemi.c -g  -I/usr/include/SDL -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_gfx -g
functions.o:functions.c	
	gcc -c functions.c -g  -I/usr/include/SDL -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lSDL_gfx -g
enigme.o:enigme.c
	gcc -c enigme.c -g  -I/usr/include/SDL -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -g
fichier.o:fichier.c
	gcc -c fichier.c -g  -I/usr/include/SDL -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -g


