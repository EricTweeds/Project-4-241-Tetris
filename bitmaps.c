
#include "GLCD.h"
#include "bitmaps.h"


#define W White
#define B Blue
#define G Green

unsigned short bb = {{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
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
							
unsigned short bs[16][16] = {{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
								{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W}};
								
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
