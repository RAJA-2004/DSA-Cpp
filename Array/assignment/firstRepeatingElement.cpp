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
int main(){
    vector<int> arr{1,2,3,2,3,4};
    int n = arr.size();
    cout << "first repeating element is on index : " << firstRepeat(arr,n) << endl;
    return 0;
}