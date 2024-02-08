#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void print(vector<int>& arr,int i,int j){
    if(j==arr.size()){
        return;
    }
    for(int k=i;k<=j;k++){
        cout << arr[k] << " ";
    }
    cout << endl;
    print(arr,i,j+1);
}

void print1(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        int j = i;
        print(arr,i,j);
    }
}

void p(vector<int>& ans,vector<int>& arr,int i){
    if(i>=ans.size()){
        arr.push_back(ans[i]);
        return;
    }
    // exclude
    p(ans,arr,i+1);
    // include 
    arr.push_back(ans[i]);
    p(ans,arr,i+1);
} 

int main(){
    vector<int> arr{1,2,3,4,5};
    vector<int> ans;
    // print1(arr);
    p(arr,ans,0);
    for(auto val : ans){
        cout << val << endl;
    }
    return 0;
}