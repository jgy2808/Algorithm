#include <stdio.h>

void Display(int arg[], int n) {
	int a;

	printf("\n");
	for (a = 0; a < n; a++) {
		printf(" %d ", arg[a]);
	}
	printf("\n");

}

/*int BubbleSort(int arr[10], int n) {
	int a = 0, b = 0, c = 0;
	int tmp = 0, flag = 0;
	printf("배열 정보 : ");
	for (a = 0; a < n; a++) printf(" %3d ", arr[a]);
	printf("\n");
	for (a = 0; a < n - 1; a++) {
		flag = 1;
		for (b = 0; b < n - 1 - a; b++) {
			if (arr[b] < arr[b + 1]) {
				tmp = arr[b];
				arr[b] = arr[b + 1];
				arr[b + 1] = tmp;
				flag = 0;
			}
		}
		for (c = 0; c < n; c++) printf(" %3d ", arr[c]);
		printf("\n");
		if (flag == 1) {
			return 1;
		}
	}
	return 0;
}
*/

int BubbleSort(int arr[], int n) {
	int last, i;
	int temp, count = 0;
	int flag;
	for (last = n; last > 1; last--) {
		flag = 0;
		for (i = 0; i < last - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) return 0;
	}
	
	return 0;
}


//int arr[10] = { 50, 23, 84, 49, 71, 15, 99, 62, 36, 7 };
//int arr[10] = { 7, 15, 23, 36, 49, 50, 62, 71, 84, 99 };
//int arr[10] = { 99, 84, 71, 62, 50, 49, 36, 23, 15, 7 };
int main() {
	int arr[10] = { 99, 84, 71, 62, 50, 49, 36, 23, 15, 7 };
	Display(arr, 10);
	BubbleSort(arr, 10);
	Display(arr, 10);
	printf("\n");
	int arr2[10] = { 50, 23, 84, 49, 71, 15, 99, 62, 36, 7 };
	Display(arr2, 10);
	BubbleSort(arr2, 10);
	Display(arr2, 10);
	printf("\n");
	int arr3[10] = { 7, 15, 23, 36, 49, 50, 62, 71, 84, 99 };
	Display(arr3, 10);
	BubbleSort(arr3, 10);
	Display(arr3, 10);

	return 0;
}