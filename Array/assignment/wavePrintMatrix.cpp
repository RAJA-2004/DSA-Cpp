#include <iostream>
#include <vector>
using namespace std;
void waveMatrix(vector<vector<int>>v){
    int r = v.size();
    int c = v[0].size(); 
    for(int i=0;i<c;i++){
        if((i & 1) == 0){
            for(int j=0;j<r;j++){
                cout << v[j][i] << " ";
            }
        }
        else{
            for(int k=r-1;k>=0;k--){
                cout << v[k][i] << " ";
            }
        }
    }
}
int main(){
    vector<vector<int>>ans {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    waveMatrix(ans);
    return 0;
} 