#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define NUM_POINTS 10000
#define BINS 40

// Function to draw the histogram on the SDL renderer
void draw_histogram(SDL_Renderer* renderer, int win_w, int win_h, int hist[BINS][BINS], int max_count) {
    int bin_w = win_w / BINS;
    int bin_h = win_h / BINS;

    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw each bin
    for (int i = 0; i < BINS; ++i) {
        for (int j = 0; j < BINS; ++j) {
            float t = (float)hist[i][j] / max_count;
            Uint8 r = (Uint8)(255 * t);
            Uint8 g = (Uint8)(255 * pow(t, 0.3));
            Uint8 b = (Uint8)(255 * (1.0 - t));

            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_Rect rect = { i * bin_w, j * bin_h, bin_w, bin_h };
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("2D Histogram",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Initialize histogram bins
    int hist[BINS][BINS] = {0};

    // Generate random data
    srand(time(NULL));
    for (int i = 0; i < NUM_POINTS; ++i) {
        // Generate Gaussian values using Box-Muller transform
        double u1 = ((double)rand() + 1) / ((double)RAND_MAX + 1);
        double u2 = ((double)rand() + 1) / ((double)RAND_MAX + 1);
        double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        double z1 = sqrt(-2.0 * log(u1)) * sin(2.0 * M_PI * u2);

        // Normalize to [0, 1] range then map to bin indices
        int bin_x = (int)((z0 + 3) / 6.0 * BINS);
        int bin_y = (int)((z1 + 3) / 6.0 * BINS);

        if (bin_x >= 0 && bin_x < BINS && bin_y >= 0 && bin_y < BINS) {
            hist[bin_x][bin_y]++;
        }
    }

    // Get max count for color normalization
    int max_count = 1;
    for (int i = 0; i < BINS; ++i)
        for (int j = 0; j < BINS; ++j)
            if (hist[i][j] > max_count) max_count = hist[i][j];

    // Initial draw
    int win_w = WIDTH, win_h = HEIGHT;
    draw_histogram(renderer, win_w, win_h, hist, max_count);

    // Main event loop
    int running = 1;
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = 0;
            } else if (e.type == SDL_WINDOWEVENT &&
                       e.window.event == SDL_WINDOWEVENT_RESIZED) {
                SDL_GetWindowSize(window, &win_w, &win_h);
                draw_histogram(renderer, win_w, win_h, hist, max_count);
            }
        }

        SDL_Delay(16);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
