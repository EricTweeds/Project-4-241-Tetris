
#include "GLCD.h"
#include "bitmaps.h"


#define W Green //block color
#define B Black //Background color
#define G DarkGrey //Border color
#define R Red //End background

unsigned short bb[16][16] = {{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
							{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G}};
							
unsigned short bs[16][16] =    {{B,B,B,W,W,W,W,W,W,W,W,W,B,B,B,B},
								{B,B,W,W,W,W,W,W,W,W,W,W,W,B,B,B},
								{B,W,W,W,W,W,W,W,W,W,W,W,W,W,B,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{B,W,W,W,W,W,W,W,W,W,W,W,W,W,B,B},
								{B,B,W,W,W,W,W,W,W,W,W,W,W,B,B,B},
								{B,B,B,W,W,W,W,W,W,W,W,W,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B}};
								
unsigned short bc[16][16] =    {{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B}};
								
unsigned short red[16][16] =    {{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R},
								{R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R}};
								
unsigned short board[20][15] = {{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2}, 
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2}};
								
unsigned short end[20][15] =   {{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, 
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, 
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, 
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, 
								{4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 2, 2, 4, 4, 4},
								{4, 4, 4, 2, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4}, 
								{4, 4, 4, 2, 4, 2, 2, 4, 2, 4, 2, 2, 4, 4, 4},
								{4, 4, 4, 2, 4, 4, 2, 4, 2, 4, 4, 2, 4, 4, 4}, 
								{4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 2, 2, 4, 4, 4},
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, 
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, 
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, 
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, 
								{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},};
								
