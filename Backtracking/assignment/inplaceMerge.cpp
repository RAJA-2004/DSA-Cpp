#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

// time complexity : o(n logn)
// space complexity : 0(1)

void m(vector<int>& ans,int low,int mid,int high){
    int total_length = high - low + 1;
    int gap = (total_length/2)+(total_length%2);
    while(gap > 0){
        int i = low,j=low+gap;
        while(j<=high){
            if(ans[i]>ans[j]){
                swap(ans[i],ans[j]);
            }
            ++i;
            ++j;
        }
        gap = gap <= 1 ? 0 : (gap/2)+(gap%2);
    }
}

void ms(vector<int>& ans,int low,int high){
    if(low>=high) return;
    int mid = low + (high-low)/2;
    ms(ans,low,mid);
    ms(ans,mid+1,high);
    m(ans,low,mid,high);
}

int main(){
    vector<int> ans{5,3,4,2,1};
    ms(ans,0,ans.size()-1);
    for(auto val : ans){
        cout << val << " ";
    }
    return 0;
}