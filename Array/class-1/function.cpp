#include <iostream>
using namespace std;
void fun1(int a){
    a++;
    cout << "fun1() a : " << a << endl;   
}

// inside function array alwasys passed with refrence and size
void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void fun2(int arr[],int size){
    arr[0]+=10;
    print(arr,size);
}

int main(){
    int a = 5;
    int arr[] = {12,13};
    int size = 2;
    // pass by value
    fun1(a);
    cout << "main() a : " << a << endl;

    // pass by refrence
    fun2(arr,size);
    print(arr,size);
    return 0;
}