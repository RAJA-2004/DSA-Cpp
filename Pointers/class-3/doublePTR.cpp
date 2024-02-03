#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int main(){
    int a = 5;
    int* ptr1 = &a;
    int** ptr2 = &ptr1;

    cout << "value of a     : " <<  a << endl;
    cout << "address of a   : " << &a << endl;
    cout << "value of ptr1  : "<< ptr1 << endl;
    cout << "address of ptr1 : " <<  &ptr1 << endl;
    cout << "value of ptr2   : " << ptr2 << endl;
    cout << "address of ptr2 : " << &ptr2 << endl;
    cout << "value at *ptr1  : "<< *ptr1 << endl;
    cout << "value at **ptr2 : " << **ptr2 << endl;
    return 0;
}