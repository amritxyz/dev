// INFO: Program for Linear Search #Class_Work_DSA

#include <stdio.h>

static int search(int, int);

static int
search(int choice, int num)
{
	for (int i = 0; i < num; i++) {
		if (choice == num)
			return 1;
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

	int choice, found = 0;
	printf("Search num: ");
	scanf("%d", &choice);

	search(choice, num);

	if (!(search(choice, num)))
		printf("The number found: %d in %d'th term.\n", choice);
	else
		printf("The number not found: %d in %d'th term.\n", choice);

	return 0;
}
