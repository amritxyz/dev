#include <stdio.h>

int main(void)
{
    int num[5];
    int i, even=0, odd=0;
    float avg;

    printf("Enter 5 Numbers :\n");
    for (i = 0; i < 5; ++i) {
        printf("Number %d: ", i + 1);
        scanf("%d", &num[i]);
	if(num[i]%2==0){
		//printf("The number is even\n");
		even+=1;
	}
	else {
		//printf("The number is odd\n");
		odd+=1;
	}
    }
    printf("There are %d even numbers\n", even);
    printf("There are %d odd numbers\n", odd);
}

