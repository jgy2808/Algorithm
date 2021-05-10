#include <stdio.h>

int* q;
int front = -1;
int rear = -1;


int isFull(int rear, int front, int max) {
	if ((rear + 1) % max == front % max)
		return 1;
	else
		return 0;
}

int isEmpty(int rear, int front) {
	if (rear == front)
		return 1;
	else
		return 0;
}

int AddQ(int *rear, int front, int n, int max) {
	if (!isFull(*rear, front, max)) {
		*rear = (*rear + 1) % max;
		return q[*rear] = n;
	}
	else
		printf("full Q fail %d\n", n);
}

int DeQ(int *front, int rear, int max) {
	if (!isEmpty(rear, *front)) {
		*front = (*front + 1) % max;
		return q[*front];
	}
	else
		printf("empty Q\n");
}

int main() {
	int max, i;
	while(1){
		scanf_s("%d", &max);
		if (max >= 1 && max <= 500000)
			break;
		printf("re try (1 ~ 500,000)\n");
	}
	q = (int*)malloc(sizeof(int) * max);

	for (i = 1; i <= max; i++)
		AddQ(&rear, front, i, max);

	int num = 0;
	while (1) {
		DeQ(&front, rear, max);
		if (isEmpty(rear, front)) break;
		num = AddQ(&rear, front, DeQ(&front, rear, max), max);
	}
	printf("%d", num);

	free(q);
	return 0;
}