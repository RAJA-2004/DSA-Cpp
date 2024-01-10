#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int>arr;
    vector<int>ans;
    int n;
    cout << "enter number of elments : ";
    cin >> n;
    int sum;
    cout << "enter sum : ";
    cin >> sum;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if((arr[i]+arr[j]+arr[k])==sum){
                    cout << arr[i] << "," << arr[j] << "," << arr[k] << endl;
                }
            }
        }
    }
    return 0;
}