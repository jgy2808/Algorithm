#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* tit, const char* isb, int pri) : price(pri) {
		title = new char[strlen(tit) + 1];
		strcpy_s(title, strlen(tit) + 1, tit);

		isbn = new char[strlen(isb) + 1];
		strcpy_s(isbn, strlen(isb) + 1, isb);
	}
	~Book() {
		delete[]title;
		delete[]isbn;
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
};

class EBook : public Book {
private:
	char* DRMKey;
public:
	EBook(const char* tit, const char* isb, int pri, const char* drmKey) : Book(tit, isb, pri) {
		DRMKey = new char[strlen(drmKey) + 1];
		strcpy_s(DRMKey, strlen(drmKey) + 1, drmKey);
	}
	~EBook() {
		delete[]DRMKey;
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "보안키: " << DRMKey << endl;
	}
};

int main(void) {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "ASDJKGOIERJ");
	ebook.ShowEBookInfo();
	return 0;
}