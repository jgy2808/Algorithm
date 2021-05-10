#include <stdio.h>

int main(void) {
	int a, b;
	int num;
	printf("num = ");
	scanf_s("%d", &num);

	for (a = 0; a < num * 2 - 1; a++) {
		if (a < num) { // a = 0, 1, 2, 3, 4
			for (b = 0; b < num - a - 1; b++) { // 4, 3, 2, 1, 0
				printf(" ");
			}
			for (b = 0; b < a * 2 + 1; b++) { // 1, 3, 5, 7, 9
				printf("*");
			}
		}
		else { // a = 5, 6, 7, 8
			/*for (b = num; b > num * 2 - a - 1; b--) {
				printf(" ");
			}*/
			for (b = 0; b < a - num + 1; b++) { // 1, 2, 3, 4
				printf(" ");
			}
			for (b = 0; b < 2 * ( num * 2 - a - 1 ) - 1; b++) { // 7, 5, 3, 1
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}