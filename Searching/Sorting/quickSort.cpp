#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int p(vector<int>& ans,int low,int high){
    int pivot = ans[low];
    int i = low;
    int j = high;
    while(i<j){
        while(ans[i]<=pivot && i<=high-1){
            i++;
        }
        while(ans[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(ans[i],ans[j]);
        }
    }
    swap(ans[low],ans[j]);
    return j;
}
void qs(vector<int>& ans,int low,int high){
    if(low<high){
        int partition = p(ans,low,high);
        qs(ans,low,partition-1);
        qs(ans,partition+1,high);
    }
}
int main(){
    vector<int>ans{2,4,5,1,3,0};
    qs(ans,0,ans.size()-1);
    for(auto values : ans){
        cout << values << " ";
    }
    cout << endl;
    return 0;
}