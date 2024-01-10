#include <iostream>
#include <vector>
using namespace std;

void unions(vector<int>& arr1,vector<int>& arr2){
    vector<int>ans;
    for(int i=0;i<arr1.size();i++){
        ans.push_back(arr1[i]);
    }

    for(int i=0;i<arr2.size();i++){
        // Duplicate values
        for(int j=0;j<arr1.size();j++){
            if(arr2[i]==arr1[j]){
                arr2[i]=INT_MIN;
            }
        }
        if(arr2[i]!=INT_MIN)
            ans.push_back(arr2[i]);
    }
    arr1.clear();
    for(int i=0;i<ans.size();i++){
        arr1.push_back(ans[i]);
    }
}
int main(){
    vector<int>arr1;
    vector<int>arr2;
    int n;
    cin >> n;
    cout << "enter elements of vector 1 : " << endl;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        arr1.push_back(a);
    }
    int m;
    cin >> m;
    cout << "enter elements of vector 2 : " << endl;
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        arr2.push_back(a);
    }
    unions(arr1,arr2);
    for(int i=0;i<arr1.size();i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    return 0;
}