#include<iostream>
using namespace std;

void fab(int);
int main(){
    int num;
    cout<<"Enter number to print fabonacci series: ";
    cin>>num;
    fab(num);
}
void fab(int num){
    static int fnum = 0;
    static int snum = 1;
    int sum;

    if (fnum == 0){
        cout << fnum << ' ' << snum << ' ';
    }

    if (num == 0){
        return;
    }
    else{
        sum = fnum + snum;
        cout<<sum<<' ';
        fnum = snum;
        snum = sum;
        return fab(num - 1);
    }
}