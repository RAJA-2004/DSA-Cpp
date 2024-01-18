#include <iostream>
#include <vector>
using namespace std;

// first increase then pivot then sudden fall then again increase
int bs(vector<int>& ans,int start,int end,int target){
    int mid = start + (end-start)/2;
    while(start<=end){
        if(target==ans[mid]){
            return mid;
        }
        else if(target>ans[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}
int pivot(vector<int>&ans){
    int start = 0;
    int end = ans.size()-1;
    int mid = start+(end-start)/2;
    while(start<end){
        if(mid+1 <= ans.size() && ans[mid]>ans[mid+1]){
            return mid;
        }
        else if(mid-1 >= 0 && ans[mid-1]>ans[mid]){
            return mid-1;
        }

        // comparing with ans[start] to find rotated array is on which side
        if(ans[start]>=ans[mid]){
            end = mid-1;
        }
        else{
            start = mid;
        }
        mid = start+(end-start)/2;
    }
    return start;
}
int search(vector<int>& ans,int target){
    int start = 0;
    int end = ans.size()-1;
    int piv = pivot(ans);
    if(target >= ans[start] && target<=ans[piv]){
        int x = bs(ans,start,piv,target);
        return x;
    }
    else{
        int x = bs(ans,piv+1,end,target);
        return x;
    }
    return -1;
}
int main(){
    vector<int>arr{1};
    int target = 1;
    int x = search(arr,target);
    int y = pivot(arr);
    cout << y << endl;
    cout << x << endl;
    return 0;
}