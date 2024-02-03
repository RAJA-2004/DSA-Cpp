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
int main(){
    int arr[5]={1,2,3,4,5};
    int i = 0;
    print(arr,5,i);
    return 0;
}