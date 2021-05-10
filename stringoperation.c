#include <stdio.h>
#include <string.h>
#define MAX 41

void strin(char arg[MAX]) {
	int a = 0;
	for (a = 0; a < MAX; a++) {
		arg[a] = '0';
	}
}

void strmvstr(char arg[MAX], int len) {
	int a = 0;
	char temp[MAX] = { 0, };
	strin(temp);

	for (a = 0; a < len; a++) {
		temp[MAX - len + a] = arg[a];
	}
	for (a = 0; a < MAX; a++) {
		arg[a] = temp[a];
	}
}
int main(void) {
	int a = 0;
	char up[MAX] = { 0, };
	char dn[MAX] = { 0, };
	char re[MAX] = { 0, };

	strin(up);
	strin(dn);

	printf(" Input up : ");
	scanf_s("%s", up, MAX);

	printf(" Input dn : ");
	scanf_s("%s", dn, MAX);

	printf("\n");
	strmvstr(up, strlen(up));
	for (a = 0; a < MAX; a++) printf("%c", up[a]);

	printf("\n");
	strmvstr(dn, strlen(dn));
	for (a = 0; a < MAX; a++) printf("%c", dn[a]);

	printf("\n");
	for (a = MAX - 1; a > 0; a--) {
		re[a-1] = (re[a] + (up[a] - '0') + (dn[a] - '0')) / 10;
		re[a]   = (re[a] + (up[a] - '0') + (dn[a] - '0')) % 10;
	}

	printf("\n");
	for (a = 0; a < MAX; a++) printf("%d", re[a]);
	return 0;
}