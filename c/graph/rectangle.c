#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int left = 100;   // left x-coordinate
    int top = 100;    // top y-coordinate
    int right = 300;  // right x-coordinate
    int bottom = 200; // bottom y-coordinate

    rectangle(left, top, right, bottom);

    getch();

    closegraph();
    return 0;
}

