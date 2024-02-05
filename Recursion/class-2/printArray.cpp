#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void print(int arr[],int n,int i){
    // base case
    if(i>=n){
        return;
    }
    // processing
    cout << arr[i] << " ";
    // recursion
    print(arr,n,i+1); // i+1

    cout << arr[i] << " ";
}

void printArray(int arr[],int n){
    if(n==0){
        return;
    }
    cout << *arr << " ";
    printArray(arr+1,n-1);
}
int main(){
    int arr[5]={1,2,3,4,5};
    int i = 0;
    print(arr,5,i);
    cout << endl;
    printArray(arr,5);
    return 0;
}