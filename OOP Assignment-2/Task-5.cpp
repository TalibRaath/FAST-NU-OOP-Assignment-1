#include<iostream>
#include<string>
using namespace std;
//making a class of students
class student {
public:
	string name{}, address{};
	int id{};
	 long int CNIC{};
	int n{};
	string regcourses[5];
	void	stu(int id);
	void regcourse(string c, int n);
	void drop();
	void search();
};

//Witting of functions 
void student::stu(int id) {
	this->id = id;
	cout << "Enter a Name: ";
	getline(cin, name);
	//cin>>name;
	cout << "Enetr a CNIC: ";
	cin >> CNIC;
	cin.ignore();
	cout << "Enter a Address: ";
	getline(cin, address);
	//cin >> address;
}

void student::regcourse(string c, int n) {
	this->n = n;
	static int i = 0;
	this->regcourses[i] = c;
	i++;
}

void student::drop() {
	int choice;
	cout << "List of Registered Courses\n";
	for (int i = 0; i < n; i++) {
		cout << i << "-" << regcourses[i] << "\n";
	}
	cout << "CHoose a course to Drop: ";
	cin >> choice;
	regcourses[choice] = "Already Dropped";
}

void student::search() {
	int s;
	cout << "Enter a Student Id: ";
	cin >> s;
	cout << this->name << "\n" << id << "\n" << CNIC << "\n" << this->address << "\nCourses\n";
	for (int i = 0; i < this->n; i++) {
		cout << regcourses[i] << "\n";
	}
}

class cours {
public:
	int n;
	string cour[5]{};
	void set();
	void get();
};

void cours::set() {
	cout << "Enetr a no of courses : ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "Enter a Course" << i + 1 << " Name: ";
		getline(cin, cour[i]);
		//cin >> cour[i];
	}
}
void cours::get() {
	cout << "LIst of COurses Offered\n";
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "-" << cour[i] << endl;
	}
}

int main() {
	int id, choice = 0;
	cours c;
	student obj1;
	for (; choice != 6;) {

		cout << "1-Register Stuent\n2-Offer Courses\n3-Drop Courses\n4-Update Record\n5-Search Student\n6-Exit\nEnter Your Choice: ";
		cin >> choice;
		cin.ignore();
		if (choice == 2) {
			c.set();
		}

		else if (choice == 1) {
			cout << "Enter a Student Id: ";
			cin >> id;
			cin.ignore();
			obj1.stu(id);
			int n = 0;
			cout << "Enetr a no of courses : ";
			cin >> n;
			cin.ignore();
			c.get();
			int temp;
			for (int i = 0; i < n; i++) {
				cout << "Enter Course: ";
				cin >> temp;
				string str;
				str = c.cour[temp - 1];
				obj1.regcourse(str, n);
			}
		}
		else if (choice == 3) {
			obj1.drop();
		}
		else if (choice == 4) {
			cout << "Enter a Student Id: ";
			cin >> id;
			obj1.stu(id);
		}
		else if (choice == 5) {
			cin.ignore();
			obj1.search();
		}
		else if (choice == 6) {
			exit(1);
		}
		cout << "\n";
		system("pause");
		system("cls");

	}
}