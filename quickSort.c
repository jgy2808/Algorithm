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

	while (low <= high) {									//low�� high�� �����Ҷ����� �ݺ�
		while ((arr[low] <= pivot) && (low <= right)) {	//�ǹ����� ū ���� ���ö����� low++
			low++;
		}

		while ((arr[high] >= pivot) && (high >= left + 1)) {	//�ǹ����� ���� ���� ���ö����� high--
			high--;
		}

		if (low <= high) {	//�������� �ʾҴٸ� �� ���� ����
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
		printf(" low %d high %d ", low, high);
		Display(arr, 10);
	}

	//�ǹ� ��ġ�� high ��ġ�� ����Ű�� �� ����
	temp = arr[left];
	arr[left] = arr[high];
	arr[high] = temp;
	printf(" pivoit %d high %d ", left, high);
	Display(arr, 10);

	return high; //�ǹ��� ��ġ ��ȯ
}

void QuickSort(int arg[], int left, int right) {
	int pivot = 0;

	if (left <= right) {
		//	printf("\n>left %d pivot %d right %d ", left, pivot, right );
		pivot = QuickPartition(arg, left, right);	// �� ����
	//	printf("<left %d pivot %d right %d \n", left, pivot, right );
		QuickSort(arg, left, pivot - 1);		// �ǹ����� ���� ���� ����
		QuickSort(arg, pivot + 1, right);		// �ǹ����� ������ ���� ����
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
	Display(arr, 10);	// ���� ȣ���ϱ� �� 
	printf("=============================== \n");
	//Bubble( Data, 10 );	// ���� ���� 
	//Select( Data, 10 );	// ���� ���� 
	//Insert( Data, 10 );	// ���� ���� 
	//MergeSort(arr, 0, 9);	// ���� ����
	QuickSort( arr, 0, 9 );	// �� ���� 
	printf("===============================");
	Display(arr, 10);	// ���� �� 

}