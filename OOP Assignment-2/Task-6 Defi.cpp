#include"employee.h"
#include<iostream>
#include<string>
using namespace std;


employee::employee(int id) : id(id) {
	cout << "ENter a Name: ";
	cin.get(name, 20);
	cin.ignore();
	cout << "ENter a Salary Hour: ";
	cin >> salaryperhour;
	cout << "ENter a Monthly Worked Hour: ";
	cin >> monthlyworkedhours;
	cout << "ENter Year of joining: ";
	cin >> yearofjoining;
	taxpaid = 0;


}

void employee::updatehours() {
	cout << "Enter Hours";
	cin >> monthlyworkedhours;
}

void employee::cal_monthly_sal() {
	this->monthlysalary = monthlyworkedhours * salaryperhour;
}

void employee::changesalary() {
	cout << "Enter Salary";
	cin >> salaryperhour;
}

void employee::taxdeduction() {
	this->taxpaid = (0.1) * this->monthlysalary;
	this->monthlysalary -= taxpaid;

}

void employee::healthinsurnce() {
	this->monthlysalary -= 1000;
}

void employee::senioremployee() {
	if (2022 - yearofjoining >= 8) {
		this->monthlysalary += (0.1) * monthlysalary;
	}
}
void employee::generatereceipt() {
	cout << "Name: " << this->name << "\nID: " << this->id << "\nSalary: " << monthlysalary;
	cout << "\nTaxPaid: " << taxpaid;
}