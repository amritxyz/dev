// INFO: Binary Search program #Class_Work_DSA

#include <stdio.h>

// Function for performing binary search
int binarySearch(int arr[], int size, int target) {
	int left = 0, right = size - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2; // Find the middle index

		// Check if target is at mid
		if (arr[mid] == target) {
			return mid;  // Target found, return index
		}

		// If target is smaller than mid, it can only be in the left half
		if (arr[mid] > target) {
			right = mid - 1;
		}
		// If target is greater than mid, it can only be in the right half
		else {
			left = mid + 1;
		}
	}

	// Target not found
	return -1;
}

int main() {
	int arr[] = {2, 5, 8, 10, 12, 15, 18, 20, 25};
	int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array
	int target = 10;  // Element to be searched for

	int result = binarySearch(arr, size, target);

	if (result != -1) {
		printf("Element found at index %d\n", result);
	} else {
		printf("Element not found\n");
	}

	return 0;
}
