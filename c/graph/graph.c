#include <stdio.h>
#include <math.h>

#define WIDTH 70
#define HEIGHT 20

void printGraph() {
    char graph[HEIGHT][WIDTH];
    // Initialize graph
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            graph[i][j] = ' ';

    // Plotting sin(x)
    for (double x = -10; x <= 10; x += 0.1) {
        int y = (int)(sin(x) * (HEIGHT / 2) + (HEIGHT / 2)); // Scale and shift
        if (y >= 0 && y < HEIGHT) {
            int x_pos = (int)((x + 10) * (WIDTH / 20)); // Scale x
            if (x_pos >= 0 && x_pos < WIDTH) {
                graph[y][x_pos] = '*';
            }
        }
    }

    // Print graph
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(graph[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    printGraph();
    return 0;
}

