#include<iostream>
using namespace std;
//creating a function to find highest frequency index
int greatest(int *arr,int size)
{
	int *temp = new int[size], count = 0,x=0;
	int *temp2 = new int[size];
	//finding the highest frequency of numbers and storing in an array
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}	
		}
		temp[i] = count;
		temp2[i] = count;
		count = 0;
	}
	//sorting an array
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (temp[i] > temp[j]){
				count = temp[i];
				temp[i] = temp[j];
				temp[j] = count;
			}
		}
	}
	//getting the hghest frequency index
	for (int i = 0; i < size; i++){
		if (temp[0] == temp2[i])
		{
			x = i;
			break;
		}
	}
	x = arr[x];
	//deleting the dynmaically allocated memory
	if (temp[0] == 1)	{
		delete[]temp2;
		delete[]temp;
		return -1;
	}
	else	{
		delete[]temp2;
		delete[]temp;
		return x;
	}
}
int main()
{
	int* arr, size, freq;
	cout << "Enter a Size of an Array: ";
	cin >> size;
	arr = new int[size];
	for (int i = 0; i < size; i++){
		cin >> *(arr + i);
	}
	freq = greatest(arr, size);
	cout << "Greatest Frequency: " << freq;
	delete[]arr;
}