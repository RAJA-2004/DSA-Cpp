#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // sort & 2 pointer approach
        sort(nums.begin(),nums.end());
        set<pair<int,int>>ans;
        int i=0,j=1;
        int count = 0;
        while(j<nums.size()){
            int diff = nums[j]-nums[i];
            if(diff==k){
                ans.insert({nums[i],nums[j]});
                i++;
                j++;
            }
            else if(diff<k){
                j++;
            }
            else{
                i++;
            }
            if(i==j){
                j++;
            }
        }
        return ans.size();
    }
};
int main(){
    vector<int>ans{1,2,3,1,4};
    int k = 2;
    Solution s1;
    cout << s1.findPairs(ans,k)<<endl;
    return 0;
}