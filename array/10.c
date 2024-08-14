//input the 10 number find the total sum of those numbers

#include"stdio.h"
int main(){
	int abc[10];
	printf("Enter any 10 numbers :\n");
	for (int i=0; i<10; i++){
		scanf("%d", &abc[10]);
	}
	int sum=0;
	for (int i=0; i<10; i++){
		sum+=abc[i];
	}
	printf("%d", sum);
	return 0;
}

