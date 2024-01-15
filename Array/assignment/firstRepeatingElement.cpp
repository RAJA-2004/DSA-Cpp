#include <iostream>
#include <vector>
using namespace std;
int firstRepeat(vector<int>& arr,int n){
    // HASHING APPROACH
    unordered_map<int,int> hash;
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(hash[arr[i]]>1){
            return i;
        }
    }
    return -1;
}
int noWithoutHash(vector<int>& arr,int n){
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    vector<int> ans(max+1);
    for(int i=0;i<=max;i++){
        ans[i]=i;
    }
    for(int i=0;i<n;i++){
        ans[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(ans[arr[i]]>=2){
            return arr[i];
        }
    }
    return -1;
}
int main(){
    vector<int> arr{1,2,3,4};
    int n = arr.size();
    cout << "first repeating element is on index : " << firstRepeat(arr,n) << endl;

    cout << "first repeating element is on index : " << noWithoutHash(arr,n) << endl;
    return 0;
}