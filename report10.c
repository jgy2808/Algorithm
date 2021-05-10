#include <stdio.h>

int main(void) {
	int a, b;
	int num;
	printf("num : ");
	scanf_s("%d", &num);

	for (a = 0; a < 2 * num - 1; a++) {
		if (a < num) { // a = 0, 1, 2, 3, 4
			for (b = 0; b < a; b++) { // 0, 1, 2, 3, 4
				printf(" ");
			}
			for (b = 0; b < (2 * num - 1) - 2 * a; b++) { //9, 7, 5, 3, 1 / b = 2 * a; b < (2 * num - 1); ¿Í °°´Ù
				printf("*");
			}
		}
		else { // a = 5, 6, 7, 8
			for (b = 0; b < 2 * num - a - 2; b++) { // 3, 2, 1, 0
				printf(" ");
			}
			for (b = 0; b < 2 * a - 2 * num + 3; b++) { //3, 5, 7, 9
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}