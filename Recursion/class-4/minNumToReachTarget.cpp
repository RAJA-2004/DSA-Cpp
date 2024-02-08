
// COIN CHANGE without DP but TLE

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int solveMinusMethod(vector<int>& arr,int target){
    // base case
    if(target==0){
        return 0;
    }
    if(target<0){
        return INT_MAX;
    }

    // processing
    int mini = INT_MAX;
    for(int i=0;i<arr.size();i++){
        int ans = solveMinusMethod(arr,target-arr[i]);
        if(ans != INT_MAX){
            // update mini
            mini = min(mini,ans+1); // ans+1 bcz ye original target se ek kam value ka answwer return hoga
        }
    }
    return mini;
}

int solvePlusMethod(vector<int>& arr,int target,int ans){
    if(target==ans){
        return 0;
    }
    if(ans>target){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i=0;i<arr.size();i++){
        int val = solvePlusMethod(arr,target,ans+arr[i]);
        if(val != INT_MAX){
            // update
            mini = min(mini,val+1);
        }
    }
    return mini;
}

int main(){
    vector<int> ans {1,2};
    int target = 5;
    // int value = solveMinusMethod(ans,target);

    int a = 0;
    int value = solvePlusMethod(ans,target,a);
    cout << value << endl;
    return 0;
}