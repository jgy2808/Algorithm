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
int QuickPartition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;
	int temp;

	while (low <= high) {									//low와 high가 교차할때까지 반복
		while ((arr[low] <= pivot) && (low <= right)) {	//피벗보다 큰 값이 나올때까지 low++
			low++;
		}

		while ((arr[high] >= pivot) && (high >= left + 1)) {	//피벗보다 작은 값이 나올때까지 high--
			high--;
		}

		if (low <= high) {	//교차되지 않았다면 두 값을 스왑
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
		printf(" low %d high %d ", low, high);
		Display(arr, 10);
	}

	//피벗 위치와 high 위치가 가르키는 값 스왑
	temp = arr[left];
	arr[left] = arr[high];
	arr[high] = temp;
	printf(" pivoit %d high %d ", left, high);
	Display(arr, 10);

	return high; //피벗값 위치 반환
}

void QuickSort(int arg[], int left, int right) {
	int pivot = 0;

	if (left <= right) {
		//	printf("\n>left %d pivot %d right %d ", left, pivot, right );
		pivot = QuickPartition(arg, left, right);	// 퀵 분할
	//	printf("<left %d pivot %d right %d \n", left, pivot, right );
		QuickSort(arg, left, pivot - 1);		// 피벗보다 왼쪽 영역 정렬
		QuickSort(arg, pivot + 1, right);		// 피벗보다 오른쪽 영역 정렬
	}
}
*/


int QuickPartition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;
	int temp;
	while (low <= high) {
		while ((arr[low] <= pivot) && (low <= right)) {
			low++;
		}
		while ((arr[high] >= pivot) && (high >= left + 1)) {
			high--;
		}
		if (low <= high) {
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
	temp = arr[left];
	arr[left] = arr[high];
	arr[high] = temp;

	return high;
}

void QuickSort(int arr[], int left, int right) {
	int pivot;
	if (left <= right) {
		pivot = QuickPartition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}


//int arr[10] = { 50, 23, 84, 49, 71, 15, 99, 62, 36, 7 };
//int arr[10] = { 7, 15, 23, 36, 49, 50, 62, 71, 84, 99 };
//int arr[10] = { 99, 84, 71, 62, 50, 49, 36, 23, 15, 7 };
int main(void) {
	int arr[10] = { 50, 23, 84, 49, 71, 15, 99, 62, 36, 7 };
	Display(arr, 10);	// 정렬 호출하기 전 
	printf("=============================== \n");
	//Bubble( Data, 10 );	// 버블 정렬 
	//Select( Data, 10 );	// 선택 정렬 
	//Insert( Data, 10 );	// 삽입 정렬 
	//MergeSort(arr, 0, 9);	// 병합 정렬
	QuickSort( arr, 0, 9 );	// 퀵 정렬 
	printf("===============================");
	Display(arr, 10);	// 정렬 후 

}