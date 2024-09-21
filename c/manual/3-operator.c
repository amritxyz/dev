#include<stdio.h>
int main(){
	int x, y;
	for(x=1, y=10; x<=10 && y>=1; x++, y--)
		printf("X: %d,\tY: %d\n", x, y);
	return 0;
}

