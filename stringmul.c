//#include <stdio.h>
//#include <string.h>
//#define MAX 41
//
//void strin(char arg[MAX]) {
//	int a = 0;
//	for (a = 0; a < MAX; a++) {
//		arg[a] = '0';
//	}
//}
//
//void strmvstr(char arg[MAX], int len) {
//	int a = 0;
//	char temp[MAX] = { 0, };
//	strin(temp);
//
//	for (a = 0; a < len; a++) {
//		temp[MAX - len + a] = arg[a];
//	}
//	for (a = 0; a < MAX; a++) {
//		arg[a] = temp[a];
//	}
//}
//int main(void) {
//	int a = 0, b = 0;
//	char up[MAX] = { 0, };
//	char dn[MAX] = { 0, };
//	char re[MAX] = { 0, };
//	char re2[MAX] = { 0, };
//	char sum[MAX] = { 0, };
//
//	strin(up);
//	strin(dn);
//
//	printf(" Input up : ");
//	scanf_s("%s", up, MAX);
//
//	printf(" Input dn : ");
//	scanf_s("%s", dn, MAX);
//
//	printf("\n");
//	strmvstr(up, strlen(up));
//	for (a = 0; a < MAX; a++) printf("%c", up[a]);
//
//	printf("\n");
//	strmvstr(dn, strlen(dn));
//	for (a = 0; a < MAX; a++) printf("%c", dn[a]);
//
//	printf("\n");
//	for (a = MAX - 1; a > 0; a--) {
//		for (b = MAX - 1; b > MAX - a - 1; b--) { 
//			re[b - MAX + a] = (re[b - MAX + a + 1] + (up[b] - '0') * (dn[a] - '0')) / 10;
//			re[b - MAX + a + 1] = (re[b - MAX + a + 1] + (up[b] - '0') * (dn[a] - '0')) % 10;
//			re2[b] = sum[b];
//			sum[b] = 0;
//		}
//		/****for (b = 0; b < MAX; b++) {****
//			printf("%d", re[b]);
//		}
//		printf("\n");/**/
//
//		/**for (b = MAX - 1; b > 0; b--) {**
//			re2[b] = sum[b];
//			sum[b] = 0;
//		}/**/
//		for (b = MAX - 1; b > 0; b--) {
//			sum[b - 1] = (sum[b] + re[b] + re2[b]) / 10;
//			sum[b] = (sum[b] + re[b] + re2[b]) % 10;
//			re[b] = 0;
//		}
//		/****   ���ڿ� ���ϱ� �˰��� ****
//		re[a - 1] = (re[a] + (up[a] - '0') + (dn[a] - '0')) / 10;
//		re[a] = (re[a] + (up[a] - '0') + (dn[a] - '0')) % 10;
//		/********/
//	}
//
//	printf("\n");
//	for (a = 0; a < MAX; a++) printf("%d", sum[a]);
//	return 0;
//} 


// ���ڿ� ���� ���α׷�
// int ���� * int ������ ����� �ִ� +21�� 4õ ����..( 10���� �� 10�ڸ� )
// 10�ڸ� �̻��� ������ ������ �Է� ���ڿ�( char [] )�� �޾� ������ ó��

#include <stdio.h>
#include <string.h>
#define MAX 20		// ���ڿ��� �ִ� ũ��

// ���ڿ� ���� '0' ���� �ʱ�ȭ
void strin(char arg[MAX]) {
	int a = 0;

	for (a = 0; a < MAX; a++) {
		arg[a] = '0';				// ���ڿ� ���� '0'���� �ʱ�ȭ 
	}
}

//	�Էµ� �������� ���ڿ��� �������� ���ڿ��� ��ȯ 
void strmvstr(char arg[MAX], int len) {
	int a = 0;
	char temp[MAX] = { 0, };
	strin(temp);					// temp ���ڿ� ���� '0'���� �ʱ�ȭ 

	for (a = 0; a < len; a++) {
		temp[MAX - len + a] = arg[a];	// �������� ���ڿ��� �������� ���ڿ��� ��ġ �̵� 
	}
	for (a = 0; a < MAX; a++) {
		arg[a] = temp[a];
	}
}

int main(void) {
	int a = 0, b = 0, c = 0;			// ��ȯ�� ��� ����
	int lenup = 0, lendn = 0;		// �Է� ���ڿ� ����
	char up[MAX] = { 0, };		// 0���� MAX���� �ڸ��� 
	char dn[MAX] = { 0, };
	char re[MAX * 2] = { 0, };	// 10�ڸ� * 10�ڸ� ����� �ִ� 20�ڸ�

	strin(up);					// ���ڿ� ���� '0'���� �ʱ�ȭ
	strin(dn);

	printf(" Input UP : ");
	scanf_s("%s", up, MAX);

	printf(" Input DN : ");
	scanf_s("%s", dn, MAX);

	lenup = strlen(up);			// ���� �Էµ� ���ڿ� ����
	strmvstr(up, lenup);		// �Էµ� �������� ���ڿ��� �������� ���ڿ��� ��ȯ
	for (a = 0; a < MAX; a++) {
		printf(" %c", up[a]);
	}	printf("\n");

	lendn = strlen(dn);			// ���� �Էµ� ���ڿ� ����
	strmvstr(dn, lendn);		// �Էµ� �������� ���ڿ��� �������� ���ڿ��� ��ȯ
	for (a = 0; a < MAX; a++) {
		printf(" %c", dn[a]);
	}	printf("\n");

	// ���� ���� 
	for (b = MAX - 1; b > 0; b--) {			// dn �ڸ� ���� 
		for (a = MAX - 1; a > 0; a--) {		// up �ڸ� ���� 
			re[b + a - 2] = re[b + a - 2] + (re[b + a - 1] * 10 + re[b + a] + (up[a] - '0') * (dn[b] - '0')) / 10 / 10;
			re[b + a - 1] = (re[b + a - 1] * 10 + re[b + a] + (up[a] - '0') * (dn[b] - '0')) / 10 % 10;
			re[b + a] = (re[b + a - 1] * 10 + re[b + a] + (up[a] - '0') * (dn[b] - '0')) % 10 % 10;
		}

		printf("[ ");
		for (c = 0; c < MAX * 2 - 1; c++) {
			printf(" %d", re[c]);		// ���� �߰� ��� Ȯ��
		}	printf(" ]\n\n");
	}

	return 0;
}
