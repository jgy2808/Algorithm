#include <stdio.h>

int main(void) {
	int a, b;
	int num;
	printf("num = ");
	scanf_s("%d", &num);

	for (a = 0; a < num; a++) {
		for (b = num; b > a + 1; b--) { // 4, 3, 2, 1, 0
			printf(" ");
		}
		for (b = 0; b < 2 * a + 1; b++) { // 1, 3, 5, 7, 9
			printf("*");
		}
		printf("\n");
	}
	return 0;
}