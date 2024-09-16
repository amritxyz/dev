#include<stdio.h>
int main(){
	int *ptr, a[10], i, n;
	printf("Enter a number");
	fflush(stdout);
	scanf("%d", &n);
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
	ptr = &a[0];
	for (i=0; i<n; i++)
		printf("%d", *(ptr+i));
	return 0;
}

