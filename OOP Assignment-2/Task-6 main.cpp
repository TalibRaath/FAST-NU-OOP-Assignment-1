#include<iostream>
#include<string>
#include "employee.h"
using namespace std;
int main() {
	int choice = 0;
	int id;
	cout << "Enter an ID: ";
	cin >> id;
	cin.ignore();
	employee obj1(id);
	for (; choice != 8; ) {
		cout << "0-Calculate Salary\n1-Enter Data\n2-Update Hours\n3-Change Salary\n4-Tax Deduction\n5-Health Insurance\n6-IsSenior\n7-Genreate Slip\n8-Exit\n";
		cout << "ENter YOur Choice: ";
		cin >> choice;
		if (choice == 1) {
			int id;
			cout << "ENter an ID: ";
			cin >> id;
			cin.ignore();
			employee obj1(id);
		}
		else if (choice == 2) {
			obj1.updatehours();

		}
		else if (choice == 3) {
			obj1.changesalary();

		}
		else if (choice == 4) {
			obj1.taxdeduction();

		}
		else if (choice == 5) {
			obj1.healthinsurnce();

		}
		else if (choice == 6) {
			obj1.senioremployee();

		}
		else if (choice == 0) {
			obj1.cal_monthly_sal();
		}
		else if (choice == 7) {
			obj1.generatereceipt();
		}
		else if (choice == 8) {
			exit(1);
		}
		cout << "\n";
		system("pause");
		system("cls");

	}
	return 0;
}
