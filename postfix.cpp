#include <iostream>
#include <string>
#define MAX 100
using namespace std;

char* CreateStack() {
	char s[MAX] = { 0, };
	return s;
}

bool IsEmpty(string s) {
	if (s.empty()) return 1;
	else return 0;
}

bool IsFull(string s) {
	if (s.size() > 100) return 1;
	else return 0;
}

void StackPush(string *s, char c) {
	if (!IsFull(*s)) {
		*s += c;
	}
}

char StackPop(string *s) {
	if (IsEmpty(*s)) {
		return '\0';
	}
	else {
		char pop;
		pop = s->back();
		s->resize(s->size() - 1);
		return pop;
	}
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
	string med; // jung wii string
	string postfix; // hoo wii string
	string op; // operation string
	int i, flag;

	while (1) {
		flag = 1;
		cin >> med;
		if (med[0] == '-') { // if start minus
			cout << "can't start to '-'" << endl;
			continue;
		}
		else if (med.size() > 100) { // if length more 100
			cout << "under the 100" << endl;
			continue;
		}
		for (i = 0; i < med.size()-1; i++) { 
			if ((med[i] - 'a' >= 0 && med[i] - 'a' <= 25)) { // if enter a ~ z
				cout << "can't enter a ~ z" << endl;
				flag = 0;
				break;
			}
			else if ((med[i] - 'A' >= 0 && med[i] - 'A' <= 25) && (med[i + 1] - 'A' >= 0 && med[i + 1] - 'A' <= 25)) { // if A * B -> AB
				cout << "can't go on char char" << endl;
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
	}
	
	for (i = 0; i < med.size(); i++) {
		if (med[i] - 'A' >= 0 && med[i] - 'A' <= 25) { // med[i] == A~Z
			cout << "case 1 ( A ~ Z ): " << med[i] << endl;
			postfix += med[i];
		}
		else if (med[i] == ')'){ 
			cout << "case 2 ( -)- ): " << med[i] << endl;
			while (op.back() != '(') { 
				postfix += StackPop(&op);
			}
			StackPop(&op);
		}
		else if ( IsEmpty(op) || med[i] == '(' || (!IsEmpty(op) && Priority(med[i]) > Priority(op.back()))) {
			cout << "case 3 ( empty || -(- || med > op ): " << med[i] << endl;
			StackPush(&op, med[i]);
		}
		else /*if (Priority(med[i]) <= Priority(op.back()))*/ {
			cout << "case 4 ( med <= op ): " << med[i] << endl;
			postfix += StackPop(&op);
			StackPush(&op, med[i]);
		}
	}
	while (op.size() > 0) {
		postfix += StackPop(&op);
	}
	cout << postfix;

	return 0;
}