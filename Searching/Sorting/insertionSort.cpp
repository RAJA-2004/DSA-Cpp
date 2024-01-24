#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void is(vector<int>& ans){
    for(int i=0;i<ans.size();i++){
        int j=i;
        while(j>0 && ans[j-1]>ans[j]){
            swap(ans[j],ans[j-1]);
            j--;
        }
    }
}
int main(){
    vector<int>ans{2,4,5,1,3,0};
    is(ans);
    for(auto values : ans){
        cout << values << " ";
    }
    cout << endl;
    return 0;
}