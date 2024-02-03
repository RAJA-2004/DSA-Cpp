#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void solve(int** p){
    **p = **p + 1; // change in original value
    *p = *p + 1; // copy created -> no change in original value
    p = p + 1; // copy created -> no change in original value
}

void util(int* p){
    p = p + 1; // copy created -> no change in original value
    *p = *p + 1; // change in original value
}

int main(){
    int a = 5;
    int* ptr1 = &a;
    int** ptr2 = &ptr1;

    cout << "a     : " << a << endl;
    cout << "ptr1  : " << ptr1 << endl;
    cout << "&a    : " << &a << endl;
    cout << "&ptr1 : " << &ptr1 << endl;

    util(ptr1);
    cout << endl;

    cout << "a     : " << a << endl;
    cout << "ptr1  : " << ptr1 << endl;
    cout << "&a    : " << &a << endl;
    cout << "&ptr1 : " << &ptr1 << endl;

    cout << endl;

    cout <<"a : " << a << endl;

    solve(ptr2);

    cout << "a : " << a << endl;

    return 0;
}