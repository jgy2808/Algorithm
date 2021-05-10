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
//		/****   문자열 더하기 알고리즘 ****
//		re[a - 1] = (re[a] + (up[a] - '0') + (dn[a] - '0')) / 10;
//		re[a] = (re[a] + (up[a] - '0') + (dn[a] - '0')) % 10;
//		/********/
//	}
//
//	printf("\n");
//	for (a = 0; a < MAX; a++) printf("%d", sum[a]);
//	return 0;
//} 


// 문자열 곱셈 프로그램
// int 변수 * int 변수의 결과는 최대 +21억 4천 까지..( 10진수 약 10자리 )
// 10자리 이상의 정수형 변수를 입력 문자열( char [] )로 받아 곱셈을 처리

#include <stdio.h>
#include <string.h>
#define MAX 20		// 문자열은 최대 크기

// 문자열 글자 '0' 으로 초기화
void strin(char arg[MAX]) {
	int a = 0;

	for (a = 0; a < MAX; a++) {
		arg[a] = '0';				// 문자열 글자 '0'으로 초기화 
	}
}

//	입력된 좌측정렬 문자열을 우측정렬 문자열로 변환 
void strmvstr(char arg[MAX], int len) {
	int a = 0;
	char temp[MAX] = { 0, };
	strin(temp);					// temp 문자열 글자 '0'으로 초기화 

	for (a = 0; a < len; a++) {
		temp[MAX - len + a] = arg[a];	// 좌측정렬 문자열을 우축정렬 문자열로 위치 이동 
	}
	for (a = 0; a < MAX; a++) {
		arg[a] = temp[a];
	}
}

int main(void) {
	int a = 0, b = 0, c = 0;			// 순환문 사용 변수
	int lenup = 0, lendn = 0;		// 입력 문자열 길이
	char up[MAX] = { 0, };		// 0에서 MAX까지 자리수 
	char dn[MAX] = { 0, };
	char re[MAX * 2] = { 0, };	// 10자리 * 10자리 결과는 최대 20자리

	strin(up);					// 문자열 글자 '0'으로 초기화
	strin(dn);

	printf(" Input UP : ");
	scanf_s("%s", up, MAX);

	printf(" Input DN : ");
	scanf_s("%s", dn, MAX);

	lenup = strlen(up);			// 실제 입력된 문자열 길이
	strmvstr(up, lenup);		// 입력된 좌측정렬 문자열을 우측정렬 문자열로 변환
	for (a = 0; a < MAX; a++) {
		printf(" %c", up[a]);
	}	printf("\n");

	lendn = strlen(dn);			// 실제 입력된 문자열 길이
	strmvstr(dn, lendn);		// 입력된 좌측정렬 문자열을 우측정렬 문자열로 변환
	for (a = 0; a < MAX; a++) {
		printf(" %c", dn[a]);
	}	printf("\n");

	// 곱셈 과정 
	for (b = MAX - 1; b > 0; b--) {			// dn 자리 변경 
		for (a = MAX - 1; a > 0; a--) {		// up 자리 변경 
			re[b + a - 2] = re[b + a - 2] + (re[b + a - 1] * 10 + re[b + a] + (up[a] - '0') * (dn[b] - '0')) / 10 / 10;
			re[b + a - 1] = (re[b + a - 1] * 10 + re[b + a] + (up[a] - '0') * (dn[b] - '0')) / 10 % 10;
			re[b + a] = (re[b + a - 1] * 10 + re[b + a] + (up[a] - '0') * (dn[b] - '0')) % 10 % 10;
		}

		printf("[ ");
		for (c = 0; c < MAX * 2 - 1; c++) {
			printf(" %d", re[c]);		// 곱셈 중간 결과 확인
		}	printf(" ]\n\n");
	}

	return 0;
}
