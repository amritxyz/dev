#include"stdio.h"
int main(){
	int search, a[5], size, flag;
	printf("Enter the number is size: ");
	scanf("%d", &size);
	for (int i=0; i<size; i++){
		scanf("%d", &a[5]);
	}
	printf("Enter which number to search: ");
	scanf("%d", &search);
	for (int i=0; i<size; i++){
		if(a[i]==search){
			flag=1;
			break;
		}
	}
	if (flag==1){
		printf("The number is available");
	} else {
		printf("The number is not available");
	}
	return 0;
}

