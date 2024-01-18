#include <iostream>
#include <vector>
using namespace std;

// first increase then pivot then sudden fall then again increase

int pivot(vector<int>ans){
    int start = 0;
    int end = ans.size()-1;
    int mid = start + (end-start)/2;
    while(start<end){
        if(mid+1<=ans.size() && ans[mid]>ans[mid+1]){
            return mid;
        }
        else if(mid-1>=0 && ans[mid]<ans[mid-1]){
            return mid-1;
        }

        if(ans[start]>=ans[mid]){
            end = mid - 1;
        }
        else{
            start = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}
int main(){
    vector<int>arr{7,7,7,7,1,2};
    int x = pivot(arr);
    cout << x << endl;
    return 0;
}