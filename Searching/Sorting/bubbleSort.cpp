#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bs(vector<int>& ans){
    for(int i=ans.size()-1;i>=1;i--){
        for(int j=0;j<i;j++){
            if(ans[j]>ans[j+1]){
                swap(ans[j+1],ans[j]);
            }
        }
    }
}
int main(){
    vector<int>ans{2,4,5,1,3,9};
    bs(ans);
    for(auto values : ans){
        cout << values << " ";
    }
    cout << endl;
    return 0;
}