#include <stdio.h>

static int search(int , int*, int);

static int
search(int choice, int arr[], int num)
{
	for (int i = 0; i < num; i++) {
		if (arr[i] == choice)
			return i + 1;
	}
	return 0;
}

int main(void)
{
	int num;

	printf("How many numbers you want to enter: ");
	scanf("%d", &num);

	int arr[num];

	printf("Enter numbers:\n");
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	int choice;
	printf("Search num: ");
	scanf("%d", &choice);

	int term = search(choice, arr, num);

	if (term != 0) {
		printf("The number %d is found at term %d.\n", choice, term);
	} else {
		printf("The number %d was not found.\n", choice);
	}

	return 0;
}
