#include <iostream>

using namespace std;

int main(void) {
	int val, sum[3] = { 0, }, sumfin = 0, j = 0;
	char c[10], k;
	cout << "value: ";
	cin >> c;
	for (int i = 0; i < strlen(c); i++) {
		val = c[i] - '0';
		k = c[i + 1];
		switch (k) {
		case 's':
			sum[j] = val;
			break;
		case 'd':
			sum[j] = pow(val, 2);
			break;
		case 't':
			sum[j] = pow(val, 3);
			break;
		}
		if (c[i + 2] == '*') {
			if (j > 0) sum[j - 1] *= 2;
			sum[j] *= 2;
			i++;
		}
		else if (c[i + 2] == '#') {
			sum[j] *= (-1);
			i++;
		}
		i++;
		j++;
	}
	for (int i = 0; i < 3; i++) sumfin += sum[i];
	cout << sumfin;
	return 0;
}