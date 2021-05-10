#include <stdio.h>

int main(void) {
	int a, b;
	int num;
	printf("num = ");
	scanf_s("%d", &num);

	for (a = 0; a < num; a++) {
		for (b = 0; b < a; b++) { // 0, 1, 2, 3, 4
			printf(" ");
		}
		for (b = a * 2; b < num * 2 - 1; b++) { // 9, 7, 5, 3, 1
			printf("*");
		}
		printf("\n");
	}
	return 0;
}