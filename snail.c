#include <stdio.h>
#include <stdlib.h>

int main() {
	int val = 1, i = 0, j = 0, row = 0, col = -1, inc = 1, size = 0;

	printf("size : ");
	scanf_s("%d", &size);
	int** arr = malloc(sizeof(int*) * size);
	for (i = 0; i < size; i++) {
		arr[i] = malloc(sizeof(int) * size);
	}
	int n = size;
	while (n > 0) {
		for (i = 0; i < n; i++) {
			col += inc;
			arr[row][col] = val;
			val++;
		}
		n--;
		if (n == 0) break;
		for (i = 0; i < n; i++) {
			row += inc;
			arr[row][col] = val;
			val++;
		}
		inc *= -1;
	}

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < size; i++) free(arr[i]);
	free(arr);

	return 0;
}