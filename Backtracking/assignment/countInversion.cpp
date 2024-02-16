#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

// time complexity : o(n logn)
// space complexity : o(n)

int ms(vector<int>& ans,int low,int mid,int high){
    int count = 0;
    vector<int> arr;
    int i = low;
    int j = mid+1;
    while(i<=mid && j<=high){
        if(ans[i]<=ans[j]){
            arr.push_back(ans[i++]);
        }else{
            arr.push_back(ans[j++]);
            count += (mid-i+1);
        }
    }
    while(i<=mid){
        arr.push_back(ans[i++]);
    }
    while(j<=high){
        arr.push_back(ans[j++]);
    }
    while(low<=high){
        arr[low]=ans[low];
        low++;
    }
    return count;
}

int solve(vector<int>& ans,int low,int high){
    int count = 0;
    if(low>=high) return count;
    int mid = low + (high-low)/2;
    count += solve(ans,low,mid);
    count += solve(ans,mid+1,high);
    count += ms(ans,low,mid,high);
    return count;
}

int countInversion(vector<int>& ans){
    int count = 0;
    count = solve(ans,0,ans.size()-1);
    return count;
}

int main(){
    vector<int> ans{2,3,1,4};
    int inv = countInversion(ans);
    cout << inv << endl;
    return 0;
}