#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int>nums {1,0,3,4}; // 0134

    // SORT AND CHECK INDEX APPROACH
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++){
        if((nums[i]+1)!=nums[i+1]){
            cout << "missing element : " << i+1 << endl;
        }
    }

    // BINARY SEARCH APPROACH
    sort(nums.begin(),nums.end());
    int x = -1;
    for(int i=0;i<nums.size();i++){
        if(!(binary_search(nums.begin(),nums.end(),i+1))){
            x = i+1;
        }
    }
    cout << "missing element : " << x << endl;

    // VISITED APPROACH
    // for(int i=0;i<nums.size();i++){
    //     int index = abs(nums[i]);
    //     if(nums[index -1]>0){
    //         nums[index-1] *= -1;
    //     }
    // }
    // for(int i=1;i<nums.size();i++){
    //     if(nums[i]>0){
    //         cout << "missing number is : " << i+1 << endl;
    //     }
    // }
    return 0;
}