#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void ss(vector<int>& ans){
    for(int i=0;i<=ans.size()-2;i++){
        int min = i;
        for(int j=i+1;j<=ans.size()-1;j++){
            if(ans[j]<ans[min]){
                min=j;
            }
        }
        swap(ans[i],ans[min]);
    }
}
int main(){
    vector<int>ans{2,4,5,1,3,0};
    ss(ans);
    for(auto values : ans){
        cout << values << " ";
    }
    cout << endl;
    return 0;
}