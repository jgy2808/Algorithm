#include <stdio.h>

void Display(int arg[], int n) {
	int a;

	printf("\n");
	for (a = 0; a < n; a++) {
		printf(" %d ", arg[a]);
	}
	printf("\n");

}
/*
int InsertSort(int arr[10], int n) {
	int a = 0, b = 0, c = 0;
	int tmp = 0;
	int flag = 0;
	printf("배열 정보 : ");
	for (a = 0; a < n; a++) printf(" %3d ", arr[a]);
	printf("\n");
	for (a = 1; a < n; a++) {
		flag = 1;
		for (b = a; b > 0; b--) {
			if (arr[b] > arr[b - 1]) {
				tmp = arr[b];
				arr[b] = arr[b - 1];
				arr[b - 1] = tmp;
				flag = 0;
				continue;
			}
			break;
		}
		if (flag == 0) {
			for (c = 0; c < n; c++) printf(" %3d ", arr[c]);
			printf("\n");
		}
	}
	for (a = 0; a < n; a++) printf(" %3d ", arr[a]);
	return 0;
}
*/


int InsertSort(int arr[], int n) {
	int last, i;
	int temp, count = 0;
	for (last = 1; last < n; last++) {
		for (i = last; i > 0; i--) {
			if (arr[i - 1] > arr[i]) {
				temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
			}
		}
	}
	return 0;
}

//int arr[10] = { 50, 23, 84, 49, 71, 15, 99, 62, 36, 7 };
//int arr[10] = { 7, 15, 23, 36, 49, 50, 62, 71, 84, 99 };
//int arr[10] = { 99, 84, 71, 62, 50, 49, 36, 23, 15, 7 };
int main() {
	int arr[10] = { 99, 84, 71, 62, 50, 49, 36, 23, 15, 7 };
	Display(arr, 10);
	InsertSort(arr, 10);
	Display(arr, 10);
	printf("\n");
	int arr2[10] = { 50, 23, 84, 49, 71, 15, 99, 62, 36, 7 };
	Display(arr2, 10);
	InsertSort(arr2, 10);
	Display(arr2, 10);
	printf("\n");
	int arr3[10] = { 7, 15, 23, 36, 49, 50, 62, 71, 84, 99 };
	Display(arr3, 10);
	InsertSort(arr3, 10);
	Display(arr3, 10);
	return 0;
}