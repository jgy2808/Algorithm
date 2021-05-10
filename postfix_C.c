#include <stdio.h>
#include <string.h>
#define MAX 100

char op[MAX] = { 0, };
int top = -1;

int isFull(int *top) {
	if (*top == MAX - 1)
		return 1;
	else
		return 0;
}

int isEmpty(int *top) {
	if (*top == -1)
		return 1;
	else
		return 0;
}

char Top(int *top) {
	return op[*top];
}

void Push(int *top, char c) {
	if (!isFull(&top))
		op[++(*top)] = c;
}

char Pop(int *top) {
	if (!isEmpty(&top))
		return op[(*top)--];
}

int Priority(char c) {
	if (c == '*' || c == '/') {
		return 3;
	}
	else if (c == '+' || c == '-') {
		return 2;
	}
	else if (c == '(') {
		return 1;
	}
}

int main() {
	char med[MAX] = { 0, }; // jung wii string
	char postfix[MAX] = { 0, }; // hoo wii string

	int i, flag;
	int k = 0;

	while (1) {
		flag = 1;
		scanf_s("%s", med, MAX);
		if (med[0] == '-') { // if start minus
			printf("can't start to '-'\n");
			continue;
		}
		else if (strlen(med) > 100) { // if length more 100
			printf("under the 100\n");
			continue;
		}
		for (i = 0; i < strlen(med); i++) {
			if ((med[i] - 'a' >= 0 && med[i] - 'a' <= 25)) { // if enter a ~ z
				printf("can't enter a ~ z\n");
				flag = 0;
				break;
			}
			else if ((med[i] - 'A' >= 0 && med[i] - 'A' <= 25) && (med[i + 1] - 'A' >= 0 && med[i + 1] - 'A' <= 25)) { // if A * B -> AB
				printf("can't go on char char\n");
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
	}

	for (i = 0; i < strlen(med); i++) {
		if (med[i] - 'A' >= 0 && med[i] - 'A' <= 25) { // med[i] == A~Z
			printf("case 1 ( A ~ Z ): %c\n", med[i]);
			postfix[k++] = med[i];
		}
		else if (med[i] == ')') {
			printf("case 2 ( -)- ): %c\n", med[i]);
			while (Top(&top) != '(') {
				postfix[k++] = Pop(&top);
			}
			Pop(&top);
		}
		else if (isEmpty(&top) || med[i] == '(' || (!isEmpty(&top) && Priority(med[i]) > Priority(Top(&top)))) {
			printf("case 3 ( empty || -(- || med > op ): %c\n", med[i]);
			Push(&top, med[i]);
		}
		else /*if (Priority(med[i]) <= Priority(op.back()))*/ {
			printf("case 4 ( med <= op ): %c\n", med[i]);
			postfix[k++] = Pop(&top);
			Push(&top, med[i]);
		}
		printf("op : %s, postfix : %s, top : %d\n\n", op, postfix, top);
	}
	while (!isEmpty(&top)) {
		postfix[k++] += Pop(&top);
	}
	printf("%s", postfix);

	return 0;
}