#include <stdio.h>
/*
int main(void) {
	int a, b;
	int num;
	printf("num = ");
	scanf_s("%d", &num);

	for (a = 0; a < num; a++) {
		for (b = 0; b < a; b++) { // 0, 1, 2, 3, 4
			printf(" ");
		}
		for (b = num; b > a; b--) { // 5, 4, 3, 2, 1
			printf("*");
		}
		printf("\n");
	}
	return 0;
}*/

int main(void) {
	int a, b;
	int num;

	printf("num : ");
	scanf_s("%d", &num);
	for (a = 0; a < num; a++) {
		for (b = 0; b < num; b++) {
			if (a > b) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}