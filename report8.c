#include <stdio.h>

int main(void) {
	int a, b;
	int num;
	printf("num = ");
	scanf_s("%d", &num);

	for (a = 0; a < num * 2 - 1; a++) {
		if (a < num) { // a = 0, 1, 2, 3, 4
			for (b = a; b < num - 1; b++) { // 0, 1, 2, 3, 4
				printf(" ");
			}
			for (b = a + 1; b > 0; b--) { // 1, 2, 3, 4, 5
				printf("*");
			}
		}
		else { // a = 5, 6, 7, 8
			for (b = 0; b < a - num + 1; b++) { // 1, 2, 3, 4
				printf(" ");
			}
			for (b = num; b > a - num + 1; b--) { // 4, 3, 2, 1
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}