#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void solve(vector<int>& nums,int i,int sum,int& maxi){
    // base case
    if(i>=nums.size()){
        maxi = max(sum,maxi);
        return;
    }
    // include
    solve(nums,i+2,sum+nums[i],maxi);
    // exclude
    solve(nums,i+1,sum,maxi);
}

int rob(vector<int>& nums) {
    int i = 0;
    int sum = 0;
    int maxi = INT_MIN;
    solve(nums,i,sum,maxi);
    return maxi;
}


int main(){
    vector<int> ans{1,2,3,1};
    int r = rob(ans);
    cout << r << endl;
    return 0;
}