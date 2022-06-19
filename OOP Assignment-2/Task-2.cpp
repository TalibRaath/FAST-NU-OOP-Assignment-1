#include<iostream>
using namespace std;
int main() {
	int row, ** array;
	int* col;
	cout << "Enter a Number of Rows: ";
	cin >> row;
	//making a array of coloums for jagged array
	col = new int[row];
	array = new int* [row];
	//dynamacally making  2-d array

	for (int i = 0; i < row; i++) {
		cout << "Enter a Col-"<<i+1<<" Size\n";
		cin >> col[i];
		*(array + i) = new int[col[i]];
	}
	// Getting elements from user
	cout << "Enter Elements\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col[i]; j++) {
			cout << "Enter col-"<<i+1<<" Elements\n";
			cin >> *(*(array + i) + j);
		}
	}
	//printing elements of an array
	cout << "Elements Of array are\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col[i]; j++) {
			cout << *(*(array + i) + j) << " ";
		}
		cout << "\n";
	}
	//deletion of array
	for (int i = 0; i < row; i++) {
		delete* (array + i);
	}
	delete[]array;

}
//New comment added

