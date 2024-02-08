
// HOUSE ROBBER without DP but TLE

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void solve(vector<int>& arr,int i,int sum,int& maxi){
    if(i>=arr.size()){
        maxi = max(sum,maxi);
        return;
    }
    // inclusion
    solve(arr,i+2,sum+arr[i],maxi);
    // exclusion
    solve(arr,i+1,sum,maxi);
}
int main(){
    vector<int> ans{1,2,3,4,5,6};
    int maxi = INT_MIN;
    int i = 0;
    int sum = 0;
    solve(ans,i,sum,maxi);
    cout << maxi << endl;
    return 0;
}