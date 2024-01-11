#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int>nums {4,2,3,1,4};

    // SORTING APPROACH
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]){
            cout << "duplicate is " << nums[i] << endl;
        }
    }

    // VISITED APPROACH

    // int ans = -1;
    // for(int i=0;i<nums.size();i++){
    //     int index = abs(nums[i]);
    //     if(nums[index]<0){
    //         ans = index;
    //     }
    //     nums[index] *= -1;
    // }
    // cout << "duplicate is : " << ans << endl;

    // PLACING ON CORRECT INDEX APPROACH

    // while(nums[0]!=nums[nums[0]]){
    //     swap(nums[0],nums[nums[0]]);
    // }
    // cout << "duplicate element is : " << nums[0] << endl;
    return 0;
}