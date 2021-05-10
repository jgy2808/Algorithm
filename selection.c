#include <stdio.h>

void Display(int arg[], int n) {
	int a;

	printf("\n");
	for (a = 0; a < n; a++) {
		printf(" %d ", arg[a]);
	}
	printf("\n");

}

/*int SelectionSort(int arr[10], int n) {
	int a, b, c;
	int index = 0, temp = 0, flag = 0;
	printf("배열 정보 : ");
	for (a = 0; a < n; a++) printf(" %3d ", arr[a]);
	printf("\n");
	for (a = 0; a < n - 1; a++) {
		index = a;
		flag = 1;
		for (b = a; b < n; b++) {
			if (arr[index] < arr[b]) {
				index = b;
				flag = 0;
			}
		}
		temp = arr[a];
		arr[a] = arr[index];
		arr[index] = temp;

		for (c = 0; c < n; c++) printf(" %3d ", arr[c]);
		printf("\n");

		if (flag == 1) return 1;
	}
	return 0;
}*/

int SelectionSort(int arr[], int n) {
	int last, i;
	int max;
	int temp, count = 0;
	for (last = n - 1; last >= 0; last--) {
		max = 0;
		for (i = 1; i <= last; i++) {
			if (arr[max] < arr[i]) {
				max = i;
			}
		}
		temp = arr[max];
		arr[max] = arr[last];
		arr[last] = temp;
	}
	return 0;
}



//int arr[10] = { 50, 23, 84, 49, 71, 15, 99, 62, 36, 7 };
//int arr[10] = { 7, 15, 23, 36, 49, 50, 62, 71, 84, 99 };
//int arr[10] = { 99, 84, 71, 62, 50, 49, 36, 23, 15, 7 };
int main() {
	int arr[10] = { 99, 84, 71, 62, 50, 49, 36, 23, 15, 7 };
	Display(arr, 10);
	SelectionSort(arr, 10);
	Display(arr, 10);
	printf("\n");
	int arr2[10] = { 50, 23, 84, 49, 71, 15, 99, 62, 36, 7 };
	Display(arr2, 10);
	SelectionSort(arr2, 10);
	Display(arr2, 10);
	printf("\n");
	int arr3[10] = { 7, 15, 23, 36, 49, 50, 62, 71, 84, 99 };
	Display(arr3, 10);
	SelectionSort(arr3, 10);
	Display(arr3, 10);
	return 0;
}