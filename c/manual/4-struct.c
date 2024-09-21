#include<stdio.h>
/* struct point { */
/* 	int x, y; */
/* }; */

/* struct point first_point; */

/* int main(int arhc, char **argv){ */
/* 	first_point.x = 0; */
/* 	first_point.y = 5; */
/* 	printf("X: %d,\tY: %d\n", first_point.x, first_point.y); */
/* 	return 0; */
/* } */

struct fish {
	int length, weight;
};

int main(int argc, char **argv){
	struct fish salmon;
	struct fish *fish_pointer = &salmon;
	fish_pointer->length = 3;
	fish_pointer->weight = 9;
	printf("salmon.length: %d, salmon.weight: %d, fish_pointer->length: %d, fish_pointer->weight: %d\n",
           salmon.length, salmon.weight, fish_pointer->length, fish_pointer->weight);
	return 0;
}

