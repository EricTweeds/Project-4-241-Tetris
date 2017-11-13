
#include "GLCD.h"
#include "bitmaps.h"


#define W White
#define B Blue
#define G Green

bb = {{G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G},
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
							
bs[16][16] = {{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W},
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
								
bc[16][16] = {{B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B},
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
								
board[20][15] = {{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2}, 
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
