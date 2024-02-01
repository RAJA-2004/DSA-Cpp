#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int main(){
    int a = 5;
    int* ptr = &a;
    int** p = &ptr;

    cout << "value of a    : " << a << endl;
    cout << "value of ptr  : " << ptr << endl;
    cout << "vaule of &a   : " << &a << endl;
    cout << "value of &p   : " << &p << endl;
    cout << "value of *ptr : " << *ptr << endl;
    cout << "size of ptr   : " << sizeof(ptr) << endl;

    cout << "ptr + 1       : " << ptr+1 << endl;

    int* c = NULL;
    cout << "null pointer  : " << c << endl;

    int* b;
    cout << "value of not initialised pointer : " << b << endl;
    return 0;
}