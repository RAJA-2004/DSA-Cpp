#include <iostream>
#include <vector>
using namespace std;
void in(vector<int>& arr1,vector<int>& arr2){
    vector<int>ans;
    for(int i=0;i<arr1.size();i++){
        int element = arr1[i];
        for(int j=0;j<arr2.size();j++){
            if(element==arr2[j]){
                // mark so that it doest not repeat
                arr2[j]=INT_MIN;
                ans.push_back(element);
            }
        }
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
    in(arr1,arr2);
    for(auto values:arr1){
        cout << values << " ";
    }
    cout << endl;
    return 0;
}