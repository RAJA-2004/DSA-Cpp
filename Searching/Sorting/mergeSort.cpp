#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void m(vector<int>& ans,int low,int mid,int high){
    int i,j,k;
    int n1 = mid-low+1;
    int n2 = high-mid;
    vector<int>left(n1);
    vector<int>right(n2);
    for(int i=0;i<n1;i++){
        left[i]=ans[low+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=ans[mid+1+i];
    }
    i=0;
    j=0;
    k=low;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            ans[k]=left[i];
            i++;
        }else{
            ans[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        ans[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        ans[k]=right[j];
        j++;
        k++;
    }
}
void ms(vector<int>& ans,int low,int high){
    if(low==high){
        return;
    }
    int mid = low + (high-low)/2;
    ms(ans,low,mid);
    ms(ans,mid+1,high);
    m(ans,low,mid,high);
    
}
int main(){
    vector<int>ans{2,4,5,1,3,0};
    ms(ans,0,ans.size()-1);
    for(auto values : ans){
        cout << values << " ";
    }
    cout << endl;
    return 0;
}