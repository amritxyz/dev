#include <stdio.h>

// Function to merge two subarrays into a sorted array
void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int L[n1], R[n2];  // Temporary arrays for left and right halves

	// Copy data to temporary arrays
	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0, k = left;

	// Merge the temp arrays back into arr[left..right]
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		} else {
			arr[k++] = R[j++];
		}
	}

	// Copy remaining elements of L[], if any
	while (i < n1) {
		arr[k++] = L[i++];
	}

	// Copy remaining elements of R[], if any
	while (j < n2) {
		arr[k++] = R[j++];
	}
}

// Recursive function to perform merge sort
void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;  // Find the middle point

		// Sort first and second halves
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		// Merge the sorted halves
		merge(arr, left, mid, right);
	}
}

int main() {
	int arr[] = {12, 11, 13, 5, 6, 7};
	int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

	mergeSort(arr, 0, size - 1);

	// Print the sorted array
	printf("Sorted array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
