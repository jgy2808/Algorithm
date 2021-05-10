#include <stdio.h>
#include <string.h>
#define MAX 10	// ���ڿ� �ִ� ũ�� 

// �Էµ� ���� ���� ���ڿ� ���� ���� ���ڿ��� �� 
void strmvstr(char arg[MAX], int len) {
	int a;
	char temp[MAX] = { 0, };

	memset(temp, '0', MAX);	// temp ���ڿ� �ʱ�ȭ

	for (a = 0; a < len; a++) {
		temp[(MAX - len) + a] = arg[a];	// ���� ���� ���ڿ� ���� ���� ���ڿ��� ��ġ �̵� 
	}
	for (a = 0; a < MAX; a++) {
		arg[a] = temp[a];
	}
}

int main(void) {
	int a = 0, b = 0;				// ��ȯ�� ���� 
	char up[MAX] = { 0, };		// ���� �Է� 
	char dn[MAX] = { 0, };		// �Ʒ��� �Է� 
	char re[MAX] = { 0, };		// ��� ���� 
	int lenup = 0, lendn = 0;		// lenup ���� �Է� ����, lendn �Ʒ��� �Է� ����
	int flag = 1;					// ���� ǥ�� 

	memset(up, '0', MAX);		// up ���ڿ� �ʱ�ȭ
	memset(dn, '0', MAX);		// dn ���ڿ� �ʱ�ȭ

	printf(" Input UP : ");
	scanf_s("%s", up, MAX);
	lenup = strlen(up);			// ���� �Է� ������ ���� 

	printf(" Input DN : ");
	scanf_s("%s", dn, MAX);
	lendn = strlen(dn);			// �Ʒ��� �Է� ������ ����

	printf("\n   ");
	strmvstr(up, lenup);		// �Էµ� ���� ���� ���ڿ� ���� ���� ���ڿ���
	for (a = 0; a < MAX; a++) {
		printf(" %c ", up[a]);
	}

	printf("\n - ");
	strmvstr(dn, lendn);		// �Էµ� ���� ���� ���ڿ� ���� ���� ���ڿ���
	for (a = 0; a < MAX; a++) {
		printf(" %c ", dn[a]);
	}

	printf("\n=================================\n");

	// ���� ���̰� �Ʒ��� ���̺��� ��
	// �׳� ���� - �Ʒ��� �ϸ� ��.

	// ���� ���̰� �Ʒ��� ���̺��� ����
	// �Ʒ��� - ���ٷ� �ϰ� ���̳ʽ�(-) ǥ�� 
	if (lenup < lendn) {
		strcpy_s(re, up, MAX); memset(up, 0, MAX);
		strcpy_s(up, dn, MAX); memset(dn, 0, MAX);
		strcpy_s(dn, re, MAX); memset(re, 0, MAX);
		flag = 0;		// ���� ǥ�� 
	}

	// ���� ���̿� �Ʒ��� ���̰� ����. ���� �ڸ� ũ�� ��
	if (lenup == lendn) {
		for (a = MAX - lenup; a < MAX; a++) {
			// ������ ������ �Ʒ����� ū��.
			// �Ʒ��� - ���ٷ� �ϰ� ���̳ʽ�(-) ǥ�� 
			if ((up[a] < dn[a])) {		// ������ ���� �� �Ʒ����� ū �� 
				strcpy_s(re, up, MAX); memset(up, 0, MAX);
				strcpy_s(up, dn, MAX); memset(dn, 0, MAX);
				strcpy_s(dn, re, MAX); memset(re, 0, MAX);
				flag = 0;		// ���� ǥ�� 
				break;			// ��ȯ�� ���� 
			}
		}
	}

	// ���ڿ� ���� 
//	printf(" lenup %d  lendn %d \n", lenup, lendn );
	for (a = MAX - 1; a > 0; a--) {
		//	for( a=MAX-1 ; a > ( ( lenup > lendn ) ? ( MAX-lenup-1 ) : ( MAX-lendn-1 ) ) ; a-- ) {
		if (up[a] < dn[a]) {
			up[a - 1]--;		// ������ ó�� 
			re[a] = 10 - ((dn[a] - '0') - (up[a] - '0'));
		}
		else {
			re[a] = ((up[a] - '0') - (dn[a] - '0'));
		}

		if (flag == 1) {
			printf("(+)");
		}
		else {		// ���� ó�� 
			printf("(-)");
		}

		for (b = 0; b < MAX; b++) {		// �߰� ���� ��� 
			printf(" %d ", re[b]);
		}   printf("\n");
	}
	return 0;
}
