#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int bs1(vector<int>& ans,int start,int end,int target){
    // base case
    int mid = start + (end - start)/2;
    if(start > end){ // case-1
        return -1;
    }
    if(ans[mid]==target){ // case-2
        return mid;
    }

    // processing
    // if ans[mid] < target
    if(ans[mid] < target){
        return bs1(ans,mid+1,end,target);
    }
    else{
        return bs1(ans,start,mid-1,target);
    }
}

int main(){
    vector<int> ans{1,2,3,4,5,6,7,8,9};
    int target = 6;
    int a = bs1(ans,0,ans.size(),target);
    cout << a << endl;
    return 0;
}