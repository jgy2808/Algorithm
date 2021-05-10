#include <iostream>
#include <cstring>
using namespace std;

enum RISK_LEVEL {RISK_A = 30, RISK_B = 20, RISK_C = 10};

class Employee {
private:
	char name[50];
public:
	Employee(const char* emp_name) {
		strcpy_s(name, strlen(emp_name) + 1, emp_name);
	}
	void ShowYourName() const {
		cout << "name: " << name << endl;
	}
	virtual int getPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentEmployee : public Employee{
private:
	int salary;
public:
	PermanentEmployee(const char* name, int salary) : Employee(name), salary(salary) {}
	int getPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << getPay() << endl << endl;
	}
};

class SalesWorker : public PermanentEmployee {
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char* name, int money, double ratio) : PermanentEmployee(name, money), salesResult(0), bonusRatio(ratio) { }
	void AddSalesResult(int sales) {
		salesResult += sales;
	}
	int getPay() const {
		return (PermanentEmployee::getPay() + (int)(salesResult * bonusRatio));
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << getPay() << endl << endl;
	}
};

class ForeignSalesEmployee : public SalesWorker {
private:
	const int risk;
public:
	ForeignSalesEmployee(const char* name, int money, double ratio, const int riskVal) : SalesWorker(name, money, ratio), risk(riskVal) { }
	int getRiskPay() const {
		return (int)(SalesWorker::getPay() * risk / 100);
	}
	int getPay() const {
		return SalesWorker::getPay() + getRiskPay();
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << SalesWorker::getPay() << endl;
		cout << "risk pay: " << getRiskPay() << endl;
		cout << "sum: " << getPay() << endl << endl;
	}
};

class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() :empNum(0) {}
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->getPay();
		}
		cout << "salary num : " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void) {
	EmployeeHandler handler;

	ForeignSalesEmployee* fseller1 = new ForeignSalesEmployee("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesEmployee* fseller2 = new ForeignSalesEmployee("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesEmployee* fseller3 = new ForeignSalesEmployee("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
	return 0;
}