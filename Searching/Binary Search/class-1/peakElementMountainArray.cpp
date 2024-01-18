#include <iostream>
#include <vector>
using namespace std;
int peak(vector<int>ans){
    int start = 0;
    int end = ans.size()-1;
    int mid = start + (end-start)/2;
    while(start<end){
        if(ans[mid]<ans[mid+1]){
            return mid+1;
        }
        else{
            return mid;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){
    vector<int> arr{0,10,5,2};
    int x = peak(arr);
    cout << "peak element index : " << x << endl;
    return 0;
}