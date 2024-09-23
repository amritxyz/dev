#include <stdio.h>
#include <math.h>

#define POINTS 100

int main() {
    // Create a data file for the circle
    FILE *fp = fopen("circle_data.txt", "w");
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // Generate circle data
    for (int i = 0; i < POINTS; i++) {
        double theta = 2.0 * M_PI * i / POINTS; // Angle in radians
        double x = cos(theta); // X coordinate
        double y = sin(theta); // Y coordinate
        fprintf(fp, "%lf %lf\n", x, y);
    }

    fclose(fp);

    // Create a gnuplot command to plot the data
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot == NULL) {
        perror("Failed to open gnuplot");
        return 1;
    }

    fprintf(gnuplot, "set title 'Circle'\n");
    fprintf(gnuplot, "set size ratio -1\n");
    fprintf(gnuplot, "set xrange [-1.5:1.5]\n");
    fprintf(gnuplot, "set yrange [-1.5:1.5]\n");
    fprintf(gnuplot, "plot 'circle_data.txt' with lines title 'Circle'\n");

    pclose(gnuplot);
    return 0;
}

