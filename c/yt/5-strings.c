#include<stdio.h>
void main(){
	char *s="HI!";
	/* printf("%c", *s); */
	/* printf("%c", *(s+1)); */
	/* printf("%c\n", *(s+2)); */

	/* printf("%c\n", *s); */
	/* printf("%c\n", *(s+1)); */
	/* printf("%c\n", *(s+2)); */

	for(int i=0; i<3; i++)
		printf("%c", *(s+i));
	printf("\n");
}

