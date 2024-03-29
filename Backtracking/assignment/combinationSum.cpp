#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void solve(vector<int>& candidates, int target,vector<vector<int> >& ans,vector<int> &v,int index){
    // base case
    if(target == 0){
        ans.push_back(v);
        return;
    }
    if(target < 0){
        return;
    }
    // processing
    for(int i=0;i<candidates.size();i++){
        v.push_back(candidates[i]);
        solve(candidates,target-candidates[i],ans,v,i);
        // backtracking
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> > ans;
    vector<int> v;
    solve(candidates,target,ans,v,0);
    return ans;
}

int main(){
    vector<int> v{2,3,6,7};
    vector<vector<int> > ans;
    ans=combinationSum(v,7);
    for(auto value : ans){
        for(auto values : value){
            cout << values << " ";
        }
        cout << endl;
    }
    return 0;
}