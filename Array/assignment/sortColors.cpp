#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // USING SORT
        // sort(nums.begin(),nums.end());

        // 3 POINTER APPROACH
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }

        // COUNTING EACH ELEMENT
        // int count0=0;
        // int count1=0;
        // int count2=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         count0++;
        //     }
        //     else if(nums[i]==1){
        //         count1++;
        //     }
        //     else if(nums[i]==2){
        //         count2++;
        //     }
        // }
        // nums.clear();
        // while(count0>0){
        //     nums.push_back(0);
        //     count0--;
        // }
        // while(count1>0){
        //     nums.push_back(1);
        //     count1--;
        // }
        // while(count2>0){
        //     nums.push_back(2);
        //     count2--;
        // }
    }
};