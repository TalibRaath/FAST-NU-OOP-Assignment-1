#include<iostream>
#include<string>
using namespace std;

class bankAccount{
    string name;
    long long int acNumber;
    string acType;
    int balance;
    string bName;
    int bcode;
    string city;
    
public:
    bankAccount();
    bankAccount(string na, long long int acn, string acT, int ba, string bna, int bco, string ci);
    void BankDetails(long long int, string, int, string, int, string);
    void Withdraw(int*, int);
    void Deposit(int*, int);
};
void bankAccount:: BankDetails(long long int acn, string acT, int ba, string bna, int bco, string ci){
    this->acNumber=acn;
    this->acType=acT;
    this->balance=ba;
    this->bName=bna;
    this->bcode=bco;
    this->city=ci;
}
void bankAccount::Withdraw (int* balance, int withdraw){
    if (*balance >= withdraw){
        *balance -= withdraw;
        cout<<"Your current amount = "<<*balance<<endl;
    }
    else{
        cout<<"You cannot withdraw amount because you dont have enough balance"<<endl;
    }
}
void bankAccount::Deposit (int* balance, int deposit){
    *balance += deposit;
    cout<<"Your current amount = "<<*balance<<endl;
}
bankAccount::bankAccount(string na, long long int acn, string acT, int ba, string bna, int bco, string ci){
    this->name=na;
    BankDetails(acn, acT, ba, bna, bco, ci);
}
bankAccount::bankAccount(){
    this->name = "Bilal";
    this->acNumber = 233413;
    this->acType = "Saving";
    this->balance = 80000;
    this->bName = "Lahore";
    this->bcode = 411;
    this->city = "Lahore";
}
int main(){
    string name;
    long long int acNumber;
    string acType;
    int balance;
    string bName;
    int bcode;
    string city;
    cout<<"Enter Name: ";
    getline(cin,name);
    cout<<"Enter account number: ";
    cin>>acNumber;
    cout<<"Enter account type: ";
    cin.ignore();
    getline(cin,acType);
    cout<<"Enter balance: ";
    cin>>balance;
    cout<<"Enter baranch name: ";
    cin.ignore();
    getline(cin,bName);
    cout<<"Enter baranch code: ";
    cin>>bcode;
    cout<<"Enter City: ";
    cin.ignore();
    getline(cin,city);
    bankAccount customer(name, acNumber, acType, balance, bName, bcode, city);
    int withdraw;
    int* bal = &balance;
    cout<<"Enter withdraw amount: ";
    cin>>withdraw;
    customer.Withdraw(bal, withdraw);
    int deposit;
    cout<<"Enter amout to deposit: ";
    cin>>deposit;
    customer.Deposit(bal, deposit);
}