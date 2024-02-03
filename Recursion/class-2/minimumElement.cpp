#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;
void minimum(int arr[],int n,int i,int& maxi){
    // base case
    if(i>=n){
        return;
    }
    // processing
    maxi = min(maxi,arr[i]);
    // recursion
    minimum(arr,n,i+1,maxi);
}
int main(){
    int arr[5]={11,2,23,4,35};
    int maxi = INT_MAX;
    int i = 0;
    minimum(arr,5,i,maxi);
    cout << "min : " << maxi << endl;
    return 0;
}