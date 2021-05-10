#include <stdio.h>
#define MAX 5
int main() {
	int a, b, u = 0, d = 0;
	int UP[MAX], DN[MAX];

	printf("input first num of data : ");
	scanf_s("%d", &u);
	printf("input first data : ");
	for (a = 0; a < u; a++) {
		scanf_s("%d", &UP[a]);
	}
	
	printf("input second num of data: ");
	scanf_s("%d", &d);
	printf("input second data : ");
	for (b = 0; b < d; b++) {
		scanf_s("%d", &DN[b]);
	}

	for (b = 0; b < d; b++) {
		for (a = 0; a < u; a++) {
			if (UP[a] == DN[b]) {
				printf("%d 는 공통으로 있음\n", DN[b]);
			}
		}
	}
	return 0;
}