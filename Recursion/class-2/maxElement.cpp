#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;
void maximum(int arr[],int n,int i,int& maxi){
    // base case
    if(i>=n){
        return;
    }
    // processing
    maxi = max(maxi,arr[i]);
    // recursion
    maximum(arr,n,i+1,maxi);
}
int main(){
    int arr[5]={11,290,23,4,35};
    int maxi = INT_MIN;
    int i = 0;
    maximum(arr,5,i,maxi);
    cout << "max : " << maxi << endl;
    return 0;
}