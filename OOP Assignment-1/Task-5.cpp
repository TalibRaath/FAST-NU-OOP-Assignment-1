#include<iostream>
using namespace std;
void print(int** mat,int row,int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}
void input(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*(*(arr + i) + j) = rand() % 10;
		}
	}
}
int** addition(int** mat_1,int **mat_2, int row,int col)
{
	int** res = NULL;
	res = new int* [row];
	for (int i = 0; i < row; i++)
	{
		*(res + i) = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*(*(res + i) + j) = *(*(mat_1 + i) + j) + *(*(mat_2 + i) + j);
		}
	}
	return res;
}


int** subtration(int** mat_1, int** mat_2, int row, int col)
{
	int** res = NULL;
	res = new int* [row];
	for (int i = 0; i < row; i++)
	{
		*(res + i) = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*(*(res + i) + j) =  *(*(mat_2 + i) + j) - *(*(mat_1 + i) + j);
		}
	}
	return res;
}

int** multy(int** mat_1, int row1, int col1, int** mat_2, int row2, int col2)
{
	int** res = NULL;
	res = new int* [col1];
	for (int i = 0; i < row1; i++)
	{
		*(res + i) = new int[row2];
	}
	int sum = 0;
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			for (int k = 0; k < col1; k++ )
			{
				sum += *(*(mat_1 + i) + k) * *(*(mat_2 + k) + j);
			}
			*(*(res + i) + j) = sum;
			sum = 0;
		}
	}
	return res;
}

int main()
{
	int** mat_1,**mat_2,row1,col1,row2,col2;
	int** ptr = NULL;
	cout << "Enter Row of Matrix-1: ";
	cin >> row1;
	cout << "Enter Col of Matrix-1: ";
	cin >> col1;
	mat_1 = new int*[row1];
	for (int i = 0; i < row1; i++)
	{
		*(mat_1+i) = new int[col1];
	}
	input(mat_1, row1, col1);
	cout << "Enter Row of Matrix-2: ";
	cin >> row2;
	cout << "Enter Col of Matrix-2:";
	cin >> col2;
	mat_2 = new int* [row2];
	for (int i = 0; i < row2; i++)
	{
		*(mat_2 + i) = new int[col2];
	}
	input(mat_2, row2, col2);
	cout << "Matrix A\n";
	print(mat_1, row1, col1);
	cout << endl;
	cout << "Matrix B\n";
	print(mat_2, row2, col2);
	cout << endl;
	if (row1 == row2 && col1 == col2)
	{
		ptr = addition(mat_1, mat_2, row1, col1);
		cout << "Addition of Two Matrix\n";
		print(ptr, row1, col1);
	}
	else
	{
		cout << "Matrix can't be added of different Dimeniosn\n";
	}
	
	if (row1 == row2 && col1 == col2)
	{
		ptr = subtration(mat_1, mat_2, row1, col1);
		cout << "Subtration of Two Matrix\n";
		print(ptr, row1, col1);
	}
	else
	{
		cout << "Matrix can't be subtracted of different Dimeniosn\n";
	}

	if (col1 != row1)
	{
		cout << "Matrix can't be Multuply of worong Dimeniosn\n";
	}
	else
	{
		cout << "Multipliaction of Two Matrix\n";

		ptr = multy(mat_1, row1, col1, mat_2, row2, col2);
		print(ptr, row1, col2);
	}
	

}