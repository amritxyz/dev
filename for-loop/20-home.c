#include<stdio.h>
int main(){
	int i, j, k;
	const char s=' ';
    	const char n='*';
	for (i=1; i<=5; i++){
        for(k=i; k<=5; k++){
		printf("%c", s);
		    for (j=1; j<i; j++){
                //n+=1;
		    }
			    printf("%c ", n);
        }
		printf("\n");
	}
	return 0;
}

