#include <iostream>
#include <vector>
using namespace std;

// largest element will be the answer
// first increase then pivot then sudden fall then again increase

int pivot(vector<int>ans){
    int start = 0;
    int end = ans.size()-1;
    int mid = start + (end-start)/2;
    while(start<=end){
        if(start==end){
            return start;
        }
        if(mid+1<=ans.size() && ans[mid]>ans[mid+1]){
            return mid;
        }
        else if(mid-1>=0 && ans[mid]<ans[mid-1]){
            return mid-1;
        }

        if(ans[start]>ans[mid]){
            // pivot element on first line
            // left search
            end = mid - 1;
        }
        else{
            // pivot element on second line
            // right search & mid can also be the answer
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){
    vector<int>arr{8,9,10,5,6};
    int x = pivot(arr);
    cout << x << endl;
    return 0;
}