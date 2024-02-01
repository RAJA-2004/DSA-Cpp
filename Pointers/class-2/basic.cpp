#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    cout << "    arr  : " << arr << endl;
    cout << "& arr[0] : " << &arr[0] << endl;
    cout << "   & arr : " << &arr << endl;
    cout << "    *arr : " << *arr << endl;
    cout << "  *arr+1 : " << *arr+1 << endl;
    cout << "*(arr+1) : " << *(arr+1) << endl;

    cout << endl;

    int* ptr = arr;

    cout << "size of arr : " << sizeof(arr) << endl;
    cout << "size of ptr : " << sizeof(ptr) << endl;

    cout << endl;
    
    for(int i=0; i<10;i++){
        cout << "i[arr]    : " << i[arr] << endl;
        cout << "address " << i << " : " << &arr[i] << endl;
        cout << "    value : " << arr[i] << endl;
    }
    return 0;
}