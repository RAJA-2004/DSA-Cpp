#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// void ss(vector<int>& ans){
//     for(int i=0;i<=ans.size()-2;i++){
//         int min = i;
//         for(int j=i+1;j<=ans.size()-1;j++){
//             if(ans[j]<ans[min]){
//                 min=j;
//             }
//         }
//         swap(ans[i],ans[min]);
//     }
// }

void selectionsort(vector<int>& ans){
    int n = ans.size();
    for(int i=0;i<n-1;i++){
        int mini = i;
        for(int j=i;j<n;j++){
            if(ans[j]<ans[mini]){
                mini = j;
            }
        }
        swap(ans[i],ans[mini]);
    }
}

int main(){
    vector<int>ans{2,4,5,1,3,0};
    // ss(ans);
    selectionsort(ans);
    for(auto values : ans){
        cout << values << " ";
    }
    cout << endl;
    return 0;
}