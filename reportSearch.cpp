#include<stdio.h>
#include<string.h>
#define MAX 31

int main() {
	int u = 0, d = 0, i, j, k;
	int cnt[MAX] = { 0, };
	char up[MAX][MAX] = { 0, }, dn[MAX][MAX] = { 0, };
	scanf_s("%d", &u);
	for (i = 0; i < u; i++) {
		scanf_s("%s", up[i], MAX);
	}

	scanf_s("%d", &d);
	for (i = 0; i < d; i++) {
		scanf_s("%s", dn[i], MAX);
	}

	for (i = 0; i < d; i++) {
		for (j = 0; j < u; j++) {
			for (k = 0; k < strlen(dn[i]) + 1; k++) {
				cnt[i]++;
				if (dn[i][k] != up[j][k]) break; // up�� dn�� �� ���ھ� ���ϰ� �ٸ��� ����������
			}
			if (k == strlen(dn[i]) + 1) break; //�񱳹��� ���̸� dn[i]�� ��+1���� ���ߴٴ� ������ ���� �ܾ ã�� up�� ������ �ܾ��� ���� �ʿ� X
		}
	}
	for (i = 0; i < d; i++) {
		printf("%d\n", cnt[i]);
	}
	return 0;
}