#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
//making a structure of three differrnt data types
struct data
{
	double price;
	int quantity;
	char name[20];
};
//making a function to find max price
int max_price(const struct data rec[])
{
	double max_price = rec->price;
	int index = 0;
	//finding the max price
	for (int i = 0; i < 10; i++)
	{
		if (max_price < (rec + i)->price)
		{
			max_price = (rec + i)->price;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (max_price == (rec + i)->price)
		{
			index = i;
		}
	}

	return index;
}
int max_quant(const struct  data rec[])
{
	double max_quant = (rec)->quantity;
	int index = 0;
	for (int i = 0; i < 10; i++)
	{
		if (max_quant < (rec + i)->quantity)
		{
			max_quant = (rec + i)->quantity;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (max_quant == (rec + i)->quantity)
		{
			index = i;
			
		}
	}

	return index;

}
int main()
{
	int index_quant = 0, index_price=0;
	// making an array of struct to access the all data 10 times.
	struct data rec[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "Name of Product-"<<i<<": ";
		cin >> (rec + i)->name;
		cout << "Price = ";
		cin >> (rec + i)->price;
		cout << "Quantity = ";
		cin >> (rec + i)->quantity;
		
	}
	//printing the complete data of array
	cout << "Product Name" << setw(10) << " ";
	cout << "Product Price" << setw(10) << " ";
	cout << "Product Quantity" << setw(10) << " ";
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << (rec + i)->name<<setw(20)<<" ";
		cout<< (rec + i)->price<<setw(20)<<" ";
	    cout << (rec + i)->quantity;
		cout << endl;
	}

	index_price = max_price(rec);
	cout << "\nProduct Detail with Maximum Price\n";
	cout << "Product Name" << setw(10) << " " << "Product Price" << setw(10) << " " << "Product Quantity" << setw(10) << "\n";
	cout << (rec + index_quant)->name<<setw(20)<< (rec + index_quant)->price<<setw(20)<< (rec + index_quant)->quantity;
	index_quant = max_quant(rec);

	cout << "\n\nProduct Detail with Maximum Quantity\n";
	cout << "Product Name" << setw(10) << " " << "Product Price" << setw(10) << " " << "Product Quantity" << setw(10) << "\n";
	cout << (rec+index_quant)->name << setw(20) << (rec + index_quant)->price << setw(20) << (rec + index_quant)->quantity;




}