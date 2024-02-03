#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void solve(int& a){ // pass by refrence
    a = a + 1; // change in original value
}

int main(){
    int a = 5;
    int* ptr1 = &a;

    int& b = a; // refrence variable

    cout << b+2 << endl;
    cout << 2+2+b << endl;

    // b--;
    // b*=2;

    solve(b);

    // why refrence variable when we have pointers
    // refrence variable are easy to understand
    // refrence variable can't be set to NULL and will hold a valid value
    // but pointer can be pointed to NULL
    
    cout << b << endl;

    return 0;
}