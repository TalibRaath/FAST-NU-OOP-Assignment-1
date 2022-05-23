/*We use pointer funtions to store address of a function. So, instead by directly using the function we use function by
a pointer who has tha address of that function. e.g*/


#include<iostream>
using namespace std;
int sum(int a ,int b){
return a + b;
}
int fun(int(*p[])(int ,int )){
	int i=0;
	for(i=0; i < 5; i++){
		cout << p[i](i+1,i+2);
		cout << endl;
	}
	cout<<"Fun is Displied";
	return 0;
	
}
int main(){
	int (*funPtr[])(int,int) = {sum,sum,sum,sum,sum};
	fun(funPtr);
	
}

/*we ca do this in array as well to store multiple addresses.*/