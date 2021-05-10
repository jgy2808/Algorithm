#include <stdio.h>

int main(void) {
	int a, b;
	int num;
	printf("num = ");
	scanf_s("%d", &num);

	for (a = 0; a < num; a++) {
		for (b = num; b > a; b--) { // 5, 4, 3, 2, 1
			printf("*");
		}
		printf("\n");
	}
	return 0;
}