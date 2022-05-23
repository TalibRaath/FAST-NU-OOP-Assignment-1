#include<iostream>
#include<string>
using namespace std;
//funtuon prototye to reverse string
void reverse(string str);
//making a global variables
int len, lastlen;
//Driver Code
int main() {

    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    lastlen = str.length() - 1;
    len = lastlen;
    cout << "The reversed string\n";
    reverse(str);
}
//writting of a function
void reverse(string str) {
    //base condition
    if (len < 0)
        return;
    else {
        if (str[len] == ' ' || len == 0)
        {
            if (len == 0)
                len = -1;
            for (int i = len + 1; i <= lastlen; i++)
                cout << str[i];
            lastlen = len - 1;
            cout << ' ';
        }
        len--;
        //recurring a funcion
        reverse(str);
    }
}