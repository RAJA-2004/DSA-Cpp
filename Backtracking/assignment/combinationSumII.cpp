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
    for(int i=index;i<candidates.size();i++){
        v.push_back(candidates[i]);
        // i+1 bcz we dont want same values to repeat
        solve(candidates,target-candidates[i],ans,v,i+1);
        // backtracking
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int> > ans;
    vector<int> v;
    solve(candidates,target,ans,v,0);

    // set made bcz we needed unique pairs
    set<vector<int> >st;
    for(auto val : ans){
        st.insert(val);
    }
    ans.clear();
    for(auto val : st){
        ans.push_back(val);
    }
    return ans;
}

int main(){
    vector<int> v{10,1,2,7,6,1,5};
    vector<vector<int> > ans;
    ans=combinationSum(v,8);
    for(auto value : ans){
        for(auto values : value){
            cout << values << " ";
        }
        cout << endl;
    }
    return 0;
}