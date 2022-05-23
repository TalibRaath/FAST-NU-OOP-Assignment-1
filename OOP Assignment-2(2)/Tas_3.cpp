#include<iostream>
using namespace std;

class HotDogStand{
    int stands_id;
    int sold_hotDogs;
    static int totalSold;
public:
    HotDogStand(int, int);
    void justSold();
    int getSoldHotDog();
    static int getTotalSold();
};
int HotDogStand::totalSold = 0;
HotDogStand::HotDogStand(int stands_id, int sold_hotDogs){
    this->stands_id = stands_id;
    this->sold_hotDogs = sold_hotDogs;
    this->HotDogStand::totalSold += sold_hotDogs;
    justSold();
}
void HotDogStand::justSold(){
    this->sold_hotDogs++;
    this->HotDogStand::totalSold ++;
}
int HotDogStand::getSoldHotDog(){
    return this->sold_hotDogs;
};
int HotDogStand::getTotalSold(){
    return HotDogStand::totalSold;
}
int main(){
    int stands_id;
    int sold_hotDogs;
    cout<<"Enter hot dog stand id: ";
    cin>>stands_id;
    cout<<"Enter sold hot dogs: ";
    cin>>sold_hotDogs;
    HotDogStand s1(stands_id, sold_hotDogs);
    cout<<"Enter hot dog stand id: ";
    cin>>stands_id;
    cout<<"Enter sold hot dogs: ";
    cin>>sold_hotDogs;
    HotDogStand s2(stands_id, sold_hotDogs);
    cout<<"Enter hot dog stand id: ";
    cin>>stands_id;
    cout<<"Enter sold hot dogs: ";
    cin>>sold_hotDogs;
    HotDogStand s3(stands_id, sold_hotDogs);
    cout<<endl;
    cout<<"Hot Dogs sold by stand 1: "<<s1.getSoldHotDog()<<endl;
    cout<<"Hot Dogs sold by stand 2: "<<s2.getSoldHotDog()<<endl;
    cout<<"Hot Dogs sold by stand 3: "<<s3.getSoldHotDog()<<endl;
    cout<<"Total sold hot dogs: "<<s3.getTotalSold()<<endl;
}