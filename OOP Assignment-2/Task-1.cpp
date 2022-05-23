// Making of a TIC TAC TOE Game
#include<iostream>
using namespace std;

void boardfilling(char** array);
void boardprinting(char** array);
bool winningcond(char** array);
void playersturn(char** array);
// Driver COde
int main() {
	
	char **array = new char* [3];

	for (int i = 0; i < 3; i++) {
		*(array + i) = new char[3];
	}
	//calling a fun to start a game
	playersturn(array);
	
}
//wrtting a fun to fill the board with corresponding number 1-9
void boardfilling(char** array) {

	int x = 49;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			*(*(array + i) + j) = x;
			x++;
		}
	}
}
//function to print the board every time
void boardprinting(char** array) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << *(*(array + i) + j) << " ";
		}
		cout << "\n";
	}
}
//function to check who win the game
bool winningcond(char** array) {
	char p1 = 'X', p2 = 'O';

	//For checking player-1
	if (
		array[0][0] == p1 && array[0][0] == array[0][1] && array[0][1] == array[0][2] ||
		array[1][0] == p1 && array[1][0] == array[1][1] && array[1][1] == array[1][2] ||
		array[2][0] == p1 && array[2][0] == array[2][1] && array[2][1] == array[2][2] ||
		array[0][0] == p1 && array[0][0] == array[1][0] && array[1][0] == array[2][0] ||
		array[0][1] == p1 && array[0][1] == array[1][1] && array[1][1] == array[2][1] ||
		array[0][2] == p1 && array[0][2] == array[1][2] && array[1][2] == array[2][2] ||
		array[0][0] == p1 && array[0][0] == array[1][1] && array[1][1] == array[2][2] ||
		array[0][2] == p1 && array[0][2] == array[1][1] && array[1][1] == array[2][0]
		)
		return 1;            //returns '1' if Player-1 Won

	//For checking player-2
	else if (

		array[0][0] == p2 && array[0][0] == array[0][1] && array[0][1] == array[0][2] ||
		array[1][0] == p2 && array[1][0] == array[1][1] && array[1][1] == array[1][2] ||
		array[2][0] == p2 && array[2][0] == array[2][1] && array[2][1] == array[2][2] ||
		array[0][0] == p2 && array[0][0] == array[1][0] && array[1][0] == array[2][0] ||
		array[0][1] == p2 && array[0][1] == array[1][1] && array[1][1] == array[2][1] ||
		array[0][2] == p2 && array[0][2] == array[1][2] && array[1][2] == array[2][2] ||
		array[0][0] == p2 && array[0][0] == array[1][1] && array[1][1] == array[2][2] ||
		array[0][2] == p2 && array[0][2] == array[1][1] && array[1][1] == array[2][0]
		)
		return 2;            //returns '2' if Player-2 Won

	else
		return 0;      //returns '0' if GAME DRAW

}

void playersturn(char** array) {
	int row, col;
	char s;
	//calling to fill the board
	boardfilling(array);
	for (int i = 0; i < 9; i++) {
		system("cls");
		//calling to print the board
		boardprinting(array);

		//switching players turn
		if (i % 2 == 0) {
			s = 'X';
			cout << "Player-1 Turn and Symbol is 'X'\n";
		}
		else {
			s = 'O';
			cout << "Player-2 Turn and Symbol is 'O'\n";
		}
		//getting the dimensions of board to writhe with 'O' or 'X'
		cout << "Row: ";
		cin >> row;
		cout << "Col: ";
		cin >> col;
		*(*(array + row - 1) + col - 1) = s;
		//calling fun to check the winnig possibilities
		bool iswin = winningcond(array);

		if (iswin == 1) {
			cout << "\nPLayer-1 Wins the Game";

			cout << "\nPLay Again (1/0): ";
			int again;
			cin >> again;
			// To play again
			if (again == 1) {
				boardfilling(array);
				playersturn(array);
			}
			else
				break;
		}
		else if (iswin == 2) {
			cout << "\nPlayer-2 Wins the Game";

			cout << "\nPLay Again (1/0): ";
			int again;
			cin >> again;
			// To play again
			if (again == 1) {
				boardfilling(array);
				playersturn(array);
			}
			else
				break;
		}
		else if (i == 8) {

			cout << "\nGame is Draw\n";

			cout << "PLay Again (1/0): ";
			int again;
			cin >> again;
			// To play again
			if (again == 1) {
				boardfilling(array);
				playersturn(array);
			}
			else
				break;
		}
	}

}
