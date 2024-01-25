#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPossible(vector<int>& ans,int k,int mid){
    int position = ans[0];
    int count = 1;
    for(int i=1;i<ans.size();i++){
        if(ans[i]-position>=mid){
            count++;
            position=ans[i];
        }
        if(count==k){
            return true;
        }
    }
    return false;
}
int aggCows(vector<int>& ans,int n,int k){
    sort(ans.begin(),ans.end());
    int start = 0;
    int end = ans[ans.size()-1]-ans[0];
    int a = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(isPossible(ans,k,mid)){
            a = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return a;
}
int main(){
    vector<int> ans{10,1,2,7,5};
    int n = 5;
    int k = 3;
    cout << aggCows(ans,n,k) << endl;
    return 0;
}