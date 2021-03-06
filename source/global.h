#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <wiisprite.h>
#include <fat.h>
#include <asndlib.h>
#include <mp3player.h>

#define NUM_ALIENS 		 	 6
#define NUM_ALIEN_TYPES  	 1
#define NUM_PLAYERS 	 	 2
#define NUM_SHOTS_PLAYERS	12
#define NUM_SHOTS_ALIENS	 6
#define NUM_SPACE_BGS		 4

typedef struct {
    wsp::Quad left;
    wsp::Quad top;
    wsp::Quad right;
    wsp::Quad bottom;
} bounds_t;

extern s32  my_reader(void *fp,void *dat, s32 size);

extern wsp::GameWindow     	gwd;
extern wsp::Image          	imgPlayers[NUM_PLAYERS];
extern wsp::Image          	imgAliens[NUM_ALIEN_TYPES];
extern wsp::Image		   	imgBgs[NUM_SPACE_BGS];
extern wsp::Image		   	imgPlayerBullet;
extern wsp::Image		   	imgAlienBullet;
extern wsp::Image			imgFont;
extern wsp::Sprite			font;
extern wsp::LayerManager   	manager;
extern wsp::LayerManager   	bgManager;
extern bounds_t	    	   	bounds;
extern int					score;
extern int					lifes;
extern int					numPlayers;

#endif
