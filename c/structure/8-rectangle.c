/* WAP to calculate Area and perimeter using struct */

#include <stdio.h>

/* store rectangle properties */
struct Rectangle {
    int length;
    int width;
};

/* calculate area */
int calculateArea(struct Rectangle rect) {
    return rect.length * rect.width;
}

/* calculate perimeter */
int calculatePerimeter(struct Rectangle rect) {
    return 2 * (rect.length + rect.width);
}

int main() {
    struct Rectangle rect;
    printf("Enter length and width of the rectangle:\n");
    scanf("%d %d", &rect.length, &rect.width);
    printf("Area: %d\n", calculateArea(rect));
    printf("Perimeter: %d\n", calculatePerimeter(rect));
    return 0;
}

