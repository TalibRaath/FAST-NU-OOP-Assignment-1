/*Write a program that calculates sum of statically declared array’s elements where array
elements must be accessed using a pointer to an array.*/
#include<iostream>
using namespace std;
int main()
{
	int array[10] = { 10,77,4,0,8,4,9,77,4,0 };
	int *ptr=NULL,sum=0;
	ptr = array;
	for (int i = 0; i < 10; i++)
	{
		sum += *ptr + i;
	}
	cout << "Sum of array: " << sum;




}