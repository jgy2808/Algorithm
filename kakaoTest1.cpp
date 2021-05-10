#include <iostream>
#include <bitset>

using namespace std;

int main(void) {
	int n, val;
	int* arr1, * arr2;
	cout << "n:";
	cin >> n;
	arr1 = new int[n];
	arr2 = new int[n];
	for (int i = 0; i < n; i++) cin >> arr1[i];
	for (int i = 0; i < n; i++) cin >> arr2[i];

	cout << '[';
	for (int i = 0; i < n; i++) {
		val = (arr1[i] | arr2[i]);
		for (int j = n - 1; j >= 0; j--) {
			if (val >= pow(2, j)) { val -= pow(2, j); cout << '#'; }
			else cout << ' ';
		}
		if (i < 4) cout << ", ";
	}
	cout << ']';
	delete []arr1;
	delete []arr2;
	return 0;
}

/*int main(void) {
	int n;
	int* arr1, *arr2;
	cout << "n: ";
	cin >> n;
	arr1 = new int[n];
	arr2 = new int[n];
	cout << "arr1: ";
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	cout << "arr2: ";
	for (int i = 0; i < n; i++)
		cin >> arr2[i];

	char **arr_bin1;
	arr_bin1 = new char* [n];
	for (int i = 0; i < n; i++) arr_bin1[i] = new char[n];

	char **arr_bin2;
	arr_bin2 = new char* [n];
	for (int i = 0; i < n; i++) arr_bin2[i] = new char[n];

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (arr1[i] >= pow(2, j)) {
				arr1[i] -= pow(2, j);
				arr_bin1[i][n - 1 - j] = '#';
				continue;
			}
			arr_bin1[i][n - 1 - j] = ' ';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (arr2[i] >= pow(2, j)) {
				arr2[i] -= pow(2, j);
				arr_bin2[i][n - 1 - j] = '#';
				continue;
			}
			arr_bin2[i][n - 1 - j] = ' ';
		}
	}
	
	char** map;
	map = new char* [n];
	for (int i = 0; i < n; i++) map[i] = new char[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr_bin1[i][j] == '#' || arr_bin2[i][j] == '#') map[i][j] = '#';
			else map[i][j] = ' ';
		}
	}
	cout << '[';
	for (int i = 0; i < n; i++) {
		cout << '"';
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << '"';
		if (i < 4) cout << ',';
	}
	cout << ']';
	delete []arr1;
	delete []arr2;
	for (int i = 0; i < n; i++) {
		delete arr_bin1[i];
		delete arr_bin2[i];
		delete map[i];
	}
	delete []arr_bin1;
	delete []arr_bin2;
	delete []map;
	return 0;
}*/