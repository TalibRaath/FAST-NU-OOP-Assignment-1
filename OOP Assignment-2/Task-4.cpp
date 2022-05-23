#include<iostream>
#include<string>
using namespace std;
// making a struct
struct book {
	string author{}, title{};
	string bookid{};
	int quantity;
};
//function proto types
void addBook(book* b, int n);
void search(book* b);
void display(book* b, int n);
void update(book* b);
void issue(book* b);
book* resizeArray(book* b, int n);


//Driver code
int main() {
	book* rec = new book[3];
	int ch;
	int n = 0;
	do {
		cout << "1-Add a Book\n2-Search a Book\n3-Dislpay Info of all Books\n";
		cout << "4-Update Data\n5-Issue a Book\n6-Exit\nChoose an Option: ";
		cin >> ch;
		cin.ignore();
		switch (ch) {
		case 1:
			if (n >= 3) {
				rec = resizeArray(rec, n);
			}
			addBook(rec,n);
			n++;
			break;
		case 2:
			search(rec);
			break;
		case 3:
			display(rec, n);
			break;
		case 4:
			update(rec);
			break;
		case 5:
			issue(rec);
			break;
		case 6:
			exit(1);
			break;
		}
		cout << "\n";
		system("pause");
		system("cls");
	} while ( ch!=6);

}

//for the adding of a data
void addBook(book* b, int n) {

	cout << "Enter a Book Title: ";
	getline(cin, b[n].title);
	cout << "Enter a Author Name: ";
	getline(cin, b[n].author);
	cout << "Enter a Book ID: ";
	getline(cin, b[n].bookid);
	cout << "Enter a Quantiy of Book: ";
	cin >> b[n].quantity;
	cin.ignore();
}
//functiojn to search a specific data
void search(book* b) {
	string str;
	cout << "Enter a Book Title/Id/Author Name\n";
	getline(cin, str);
	for (int i = 0; i < 3; i++) {
		//finding the specific searched book
		if (str == b[i].author || str == b[i].bookid || str == b[i].title) {
			cout << "Book Title: " << b[i].title << "\nAuthor Name: " << b[i].author << "\n";
			cout << "Book ID: " << b[i].bookid << "\nQuantiy: " << b[i].quantity;
			continue;
		}
	}

}
//displaying all data
void display(book* b, int n) {

	for (int i = 0; i < n; i++) {
		cout << "Book-" << i + 1 << endl;
		cout << "Book Title: " << b[i].title << "\nAuthor Name: " << b[i].author << "\n";
		cout << "Book ID: " << b[i].bookid << "\nQuantiy: " << b[i].quantity << endl;
	}
}
// function to update the data
void update(book* b) {
	string id;
	cout << "Enter a Book ID: ";
	getline(cin, id);

	for (int i = 0; i < 3; i++) {
		//prinitng the matched books
		if (id == b[i].bookid) {
			cout << "The Book Found in Libraray\n";
			addBook(b, i);
		}
	}
}
// issuing a book
void issue(book* b) {
	string id;
	cout << "Enter a Book ID: ";
	getline(cin, id);
	for (int i = 0; i < 3; i++) {
		//finding a book
		if (id == b[i].bookid) {
			if (b[i].quantity == 0) {
				cout << "This Book is out of Stock\n";
				break;
			}
			b[i].quantity--;
		}
	}
}
// Function for resising of an array
book* resizeArray(book* b, int n) {
	book* temp = new book[n + 1];
	//assigning a values to resized array
	for (int i = 0; i < n; i++) {
		temp[i].author = b[i].author;
		temp[i].title = b[i].title;
		temp[i].bookid = b[i].bookid;
		temp[i].quantity = b[i].quantity;
	}
	b = temp;
	return temp;
}