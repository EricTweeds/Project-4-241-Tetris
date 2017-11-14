
#include "GLCD.h"
#include "bitmaps.h"


#define W White //block color
#define B Black //Background color
#define G DarkGrey //Border color

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
							
unsigned short bs[16][16] = {{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,B},
								{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B}};
								
unsigned short bc[16][16] = {{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
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
								
unsigned short board[20][15] = {{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2}, 
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2},
								{2, 2, 2, 0, 0, 0, 0, 0, 0  , 0, 0, 0, 2, 2, 2},
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
								
