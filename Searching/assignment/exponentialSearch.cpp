
// Exponential Sorting
// array should be sorted
// Time complexity bit less than Binary search
// Instead of applying BS on full array we apply on smaller portion of array

// Time Comp :- O(log m) where m is the index of i where while loop stops

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int bs(vector<int>& ans,int start,int end,int x){
    
    while(start<=end){
        int mid = start+(end-start)/2;
        if(ans[mid]==x){
            return mid;
        }
        else if(x>ans[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}
int expSearch(vector<int>& ans,int k){
    if(ans[0]==k){
        return 0;
    }
    int i=1;
    int n = ans.size();
    while(i<n && ans[i]<=k){
        i*=2;
    }
    return bs(ans,i/2,min(i,n-1),k);
}

// end is not known
int expS(vector<int>& ans,int target){
    int i=0,j=1;
    while(ans[j]<target){
        i=j;
        j=j*2;
    }
    int start = i;
    int end = j;
    return bs(ans,start,end,target);
}
int main(){
    vector<int>ans{2,5,6,8,17,19};
    vector<int>veryLargeArray{1,2,3,13,14,18,19,22,23,24,25,26,27,28,29,30,31,32,33,34,45,46};
    int k = 18;
    // int x = expSearch(ans,k);
    int x = expS(veryLargeArray,k); 
    if(x==-1){
        cout << "not found" << endl;
    }else{
        // cout << "found at index : " << x << endl;
        cout << "found at index : " << x << endl;
    }
    return 0;
}