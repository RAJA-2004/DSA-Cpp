#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void solve(vector<vector<int> >& ans,vector<int>& nums,int i){
    // base case
    if(i==nums.size()){
        ans.push_back(nums);
        return;
    }
    unordered_map<int,bool>visited;
    for(int j=i;j<nums.size();j++){
        if(visited.find(nums[j]) != visited.end()){
            continue;
        }
        visited[nums[j]]=true;
        swap(nums[i],nums[j]);
        // recursion
        solve(ans,nums,i+1);
        // backtracking
        swap(nums[i],nums[j]);
    }
}

vector<vector<int> > permuteUnique(vector<int>& nums) {
    vector<vector<int> > ans;
    solve(ans,nums,0);
    return ans;
}

int main(){
    vector<int>ans{1,1,2};
    vector<vector<int> > f = permuteUnique(ans);
    for(auto val : f){
        for(auto values : val){
            cout << values << " ";
        }
        cout << endl;
    }

    return 0;
}