#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define NUM_POINTS 10000
#define BINS 40

// Function prototypes
void draw_histogram(SDL_Renderer* renderer, int win_w, int win_h, int hist[BINS][BINS], int max_count);

#endif // HISTOGRAM_H
