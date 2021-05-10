#include <stdio.h>

void Display(int arr[], int n) {
	int a = 0;
	for (a = 0; a < n; a++) {
		printf(" %d ", arr[a]);
	}
	printf("\n");
}
/*
void Merge(int arr[], int left, int mid, int right) {
	int temp[10] = { 0, };
	int index = left;
	int low = left;
	int high = mid;

	while ((low < mid) && (high <= right)) {
		if (arr[low] < arr[high]) {
			temp[index] = arr[low];
			low++;
		}
		else {
			temp[index] = arr[high];
			high++;
		}
		index++;
	}
	if (low < mid) {
		for (low = low; low < mid; low++, index++) {
			temp[index] = arr[low];
		}
	}
	if (high <= right) {
		for (mid = high; mid <= right; mid++, index++) {
			temp[index] = arr[mid];
		}
	}
	for (index = left; index <= right; index++) {
		arr[index] = temp[index];
	}
	Display(arr, 10);
}

void MergeSort(int arg[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(arg, left, mid);
		MergeSort(arg, mid + 1, right);
		Merge(arg, left, mid + 1, right);
	}
}*/


void Merge(int arr[], int left, int mid, int right) {
	int temp[10] = { 0, };
	int index = left;
	int low = left;
	int high = mid;
	while ((low < mid) && (high <= right)) {
		if (arr[low] < arr[high]) {
			temp[index] = arr[low];
			low++;
		}
		else {
			temp[index] = arr[high];
			high++;
		}
		index++;
	}
	if (low < mid) {
		for (low = low; low < mid; low++, index++) temp[index] = arr[low];
	}
	if (high <= right) {
		for (mid = high; mid <= right; mid++, index++) temp[index] = arr[mid];
	}
	for (index = left; index <= right; index++)
		arr[index] = temp[index];

}

void MergeSort(int arr[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid + 1, right);
	}
}



//int arr[10] = { 50, 23, 84, 49, 71, 15, 99, 62, 36, 7 };
//int arr[10] = { 7, 15, 23, 36, 49, 50, 62, 71, 84, 99 };
//int arr[10] = { 99, 84, 71, 62, 50, 49, 36, 23, 15, 7 };
int main() {
	int arr[10] = { 50, 23, 84, 49, 71, 15, 99, 62, 36, 7 };
	Display(arr, 10);
	printf("=============================================\n");
	MergeSort(arr, 0, 9);
	printf("=============================================\n");
	Display(arr, 10);
	return 0;
}