#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void size(int arr[]){
    cout << "size inside function : " << sizeof(arr) << endl;
}

void update(int* p){
    cout << "size of inside update function : " << sizeof(p) << endl;
    cout << *p+5 << endl;
}

void values(int* p,int* q){
    *p = 100;
    *q = 200;
}

int main(){
    int a = 5;
    int* ptr = &a;
    int** p = &ptr;
    int arr[10] = {1,2,3,4};

    cout << "actual size of arr : " << sizeof(arr) << endl;
    size(arr);
    update(&a);

    int* p1 = &arr[1];
    int* p2 = &arr[2];

    values(p1,p2);

    for(auto values : arr){
        cout << values << " ";
    }
    cout << endl;

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