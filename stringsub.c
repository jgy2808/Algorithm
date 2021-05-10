#include <stdio.h>
#include <string.h>
#define MAX 10	// 문자열 최대 크기 

// 입력된 촤즉 정렬 문자열 우측 정렬 문자열로 변 
void strmvstr(char arg[MAX], int len) {
	int a;
	char temp[MAX] = { 0, };

	memset(temp, '0', MAX);	// temp 문자열 초기화

	for (a = 0; a < len; a++) {
		temp[(MAX - len) + a] = arg[a];	// 좌측 정렬 문자열 우측 정렬 문자열로 위치 이동 
	}
	for (a = 0; a < MAX; a++) {
		arg[a] = temp[a];
	}
}

int main(void) {
	int a = 0, b = 0;				// 순환문 변수 
	char up[MAX] = { 0, };		// 윗줄 입력 
	char dn[MAX] = { 0, };		// 아랫줄 입력 
	char re[MAX] = { 0, };		// 결과 저장 
	int lenup = 0, lendn = 0;		// lenup 윗줄 입력 길이, lendn 아랫줄 입력 길이
	int flag = 1;					// 음수 표시 

	memset(up, '0', MAX);		// up 문자열 초기화
	memset(dn, '0', MAX);		// dn 문자열 초기화

	printf(" Input UP : ");
	scanf_s("%s", up, MAX);
	lenup = strlen(up);			// 윗줄 입력 데이터 길이 

	printf(" Input DN : ");
	scanf_s("%s", dn, MAX);
	lendn = strlen(dn);			// 아랫줄 입력 데이터 길이

	printf("\n   ");
	strmvstr(up, lenup);		// 입력된 좌측 정렬 문자열 우측 정렬 문자열로
	for (a = 0; a < MAX; a++) {
		printf(" %c ", up[a]);
	}

	printf("\n - ");
	strmvstr(dn, lendn);		// 입력된 좌측 정렬 문자열 우측 정렬 문자열로
	for (a = 0; a < MAX; a++) {
		printf(" %c ", dn[a]);
	}

	printf("\n=================================\n");

	// 윗줄 길이가 아랫줄 길이보다 김
	// 그냥 윗줄 - 아랫줄 하면 됨.

	// 윗줄 길이가 아랫줄 길이보다 잛음
	// 아랫줄 - 윗줄로 하고 마이너스(-) 표시 
	if (lenup < lendn) {
		strcpy_s(re, up, MAX); memset(up, 0, MAX);
		strcpy_s(up, dn, MAX); memset(dn, 0, MAX);
		strcpy_s(dn, re, MAX); memset(re, 0, MAX);
		flag = 0;		// 음수 표시 
	}

	// 윗줄 길이와 아랫줄 길이가 같음. 같은 자리 크기 비교
	if (lenup == lendn) {
		for (a = MAX - lenup; a < MAX; a++) {
			// 윗줄이 작은수 아랫줄이 큰수.
			// 아랫줄 - 윗줄로 하고 마이너스(-) 표시 
			if ((up[a] < dn[a])) {		// 윗줄이 작은 수 아랫줄이 큰 수 
				strcpy_s(re, up, MAX); memset(up, 0, MAX);
				strcpy_s(up, dn, MAX); memset(dn, 0, MAX);
				strcpy_s(dn, re, MAX); memset(re, 0, MAX);
				flag = 0;		// 음수 표시 
				break;			// 순환문 멈춤 
			}
		}
	}

	// 문자열 뺄셈 
//	printf(" lenup %d  lendn %d \n", lenup, lendn );
	for (a = MAX - 1; a > 0; a--) {
		//	for( a=MAX-1 ; a > ( ( lenup > lendn ) ? ( MAX-lenup-1 ) : ( MAX-lendn-1 ) ) ; a-- ) {
		if (up[a] < dn[a]) {
			up[a - 1]--;		// 내림수 처리 
			re[a] = 10 - ((dn[a] - '0') - (up[a] - '0'));
		}
		else {
			re[a] = ((up[a] - '0') - (dn[a] - '0'));
		}

		if (flag == 1) {
			printf("(+)");
		}
		else {		// 음수 처리 
			printf("(-)");
		}

		for (b = 0; b < MAX; b++) {		// 중간 과정 출력 
			printf(" %d ", re[b]);
		}   printf("\n");
	}
	return 0;
}
