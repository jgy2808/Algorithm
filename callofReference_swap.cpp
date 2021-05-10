#include <iostream>

void swap(int *n1, int *n2) {
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void swap(char* c1, char* c2) {
	char ch_temp;
	ch_temp = *c1;
	*c1 = *c2;
	*c2 = ch_temp;
}

void swap(double* dou1, double* dou2) {
	double dou_temp;
	dou_temp = *dou1;
	*dou1 = *dou2;
	*dou2 = dou_temp;
}

int main() {
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	std::cout << num1 << ' ' << num2 << std::endl;

	char ch1 = 'A', ch2 = 'B';
	swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;

	double d1 = 1.111, d2 = 2.222;
	swap(&d1, &d2);
	std::cout << d1 << ' ' << d2 << std::endl;

	return 0;
}