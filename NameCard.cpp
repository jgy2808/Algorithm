#include <iostream>
#include <cstring>
using namespace std;

enum COMP_POS { CLERK, SENIOR, ASSIST, MANAGER };

class NameCard {
private:
	char* name;
	char* company;
	char* phone;
	int position;
public:
	NameCard(const char* mem_name, const char* mem_comp, const char* mem_phone, const int pos) {
		name = new char[strlen(mem_name) + 1];
		strcpy_s(name, strlen(mem_name)+1, mem_name);

		company = new char[strlen(mem_comp) + 1];
		strcpy_s(company, strlen(mem_comp)+1, mem_comp);

		phone = new char[strlen(mem_phone) + 1];
		strcpy_s(phone, strlen(mem_phone)+1, mem_phone);
		position = pos;
	}
	NameCard(const NameCard& copy_namecard) {
		name = new char[strlen(copy_namecard.name) + 1];
		strcpy_s(name, strlen(copy_namecard.name) + 1, copy_namecard.name);
		
		company = new char[strlen(copy_namecard.company) + 1];
		strcpy_s(company, strlen(copy_namecard.company) + 1, copy_namecard.company);

		phone = new char[strlen(copy_namecard.phone) + 1];
		strcpy_s(phone, strlen(copy_namecard.phone) + 1, copy_namecard.phone);
		
		position = copy_namecard.position;
	}
	void ShowNameCardInfo() {
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phone << endl;
		cout << "직급: ";
		switch (position) {
		case COMP_POS::CLERK:
			cout << "사원" << endl << endl;
			break;

		case COMP_POS::SENIOR:
			cout << "주임" << endl << endl;
			break;
		case COMP_POS::ASSIST:
			cout << "대리" << endl << endl;
			break;
		case COMP_POS::MANAGER:
			cout << "과장" << endl << endl;
			break;
		}
	}

	~NameCard() {
		delete[] name;
		delete[] company;
		delete[] phone;
	}
};

int main() {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;

	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}