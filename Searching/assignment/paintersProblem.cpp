
// define search space -> 0 (min) to (max) sum of all pages
// apply the BS in the search space
// find the minimum value of mid and return 

#include <iostream>
#include <vector>
using namespace std;
bool isPossible(vector<int>& ans,int target,int mid){
    int count = 1;
    int sum = 0;
    for(int i=0;i<ans.size();i++){
        if(ans[i]>mid){
            return false;
        }
        if(sum+ans[i]>mid){
            count++;
            sum=ans[i];
            if(count>target){
                return false;
            }
        }
        else{
            sum+=ans[i];
        }
    }
    return true;
}
int book(vector<int>& ans,int target){
    int start = 0;
    int end = 0;
    for(auto values : ans){
        end+=values;
    }
    int a = 1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(isPossible(ans,target,mid)){
            a = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return a;
}
int main(){
    vector<int> ans{12,32,64,90}; // amount of time

    // 12,32+64+90 =  186
    // 12+32,64+90 =  154
    // 12+32+64,90 =  108

    int target = 2; // no of boards
    cout << book(ans,target) << endl;
    return 0;
}