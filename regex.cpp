#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	//vector<string> filename = { "db-123-log.txt", "db-124-log.txt", "not-db-log.txt", "db-12-log.txt", "db-12-log.jpg" };
	string str = "db-123-log.txt";
	regex reg("db-\\d*-log\\.txt");
	
	for (const auto& file_name : str) {
		cout << file_name << ": " << boolalpha << regex_match(str, reg) << endl;
	}
	
	return 0;
}