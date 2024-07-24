#include<stdio.h>
int main(){
	int i, j, k;
    const char n='*';
	for (i=1; i<=5; i++){
        for(k=1; k<=5; k++){
		    for (j=1; j>=i; j--){
			    printf("%c ", n);
                //n+=1;
		    }
        }
		printf("\n");
	}
	return 0;
}

