#include <stdio.h>

int main(void) {
	int a, b;
	int num;
	printf("num = ");
	scanf_s("%d", &num);
	
	for (a = 0; a < num; a++) {
		for (b = num - 1; b > a; b--) { // 4, 3, 2, 1, 0
			printf(" ");
		}
		for (b = 0; b < a + 1; b++) { // 1, 2, 3, 4, 5
			printf("*");
		}
		printf("\n");
	}
	return 0;
}