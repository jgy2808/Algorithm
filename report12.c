#include <stdio.h>
#include <time.h>

int main(void) {
	int a, b;
	int num;
	clock_t start, end;

	printf("num : ");
	scanf_s("%d", &num);
	start = clock();
	for (a = 0; a < 2 * num; a++) {
		if (a < num) { // a = 0, 1, 2, 3, 4
			for (b = 0; b < a + 1; b++) { // 1, 2, 3, 4, 5
				printf("*");
			}
			for (b = 0; b < num - a - 1; b++) { // 4, 3, 2, 1, 0
				printf(" ");
			}
			for (b = 0; b < num - a; b++) { // 5, 4, 3, 2, 1
				printf("*");
			}
		}
		else { // a = 5, 6, 7, 8, 9
			for (b = 0; b < 2 * num - a - 1; b++) { // 4, 3, 2, 1, 0
				printf(" ");
			}
			for (b = 0; b < a - num + 1; b++ ) { // 1, 2, 3, 4, 5
				printf("*");
			}
			for (b = 0; b < a - num; b++) { // 0, 1, 2, 3, 4
				printf(" ");
			}
			for (b = 0; b <  2 * num - a; b++) { // 5, 4, 3, 2, 1
				printf("*");
			}
		}
		printf("\n");
	}
	end = clock();
	printf("걸린시간(초) : %.3f", (float)(end - start) / CLOCKS_PER_SEC);
	return 0;
}