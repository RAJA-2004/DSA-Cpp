#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralMatrix(vector<vector<int>>v){
    vector<int> ans;
    int rows = v.size();
    int cols = v[0].size();
    int total = rows*cols;
    int count = 0;
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = rows-1;
    int endingCol = cols-1;

    while(count < total){
        for(int i=startingCol;i<=endingCol && count<total;i++){
            ans.push_back(v[startingRow][i]);
            count++;
        }
        startingRow++;

        for(int i=startingRow;i<=endingRow && count<total;i++){
            ans.push_back(v[i][endingCol]);
            count++;
        }
        endingCol--;

        for(int i=endingCol;i>=startingCol && count<total;i--){
            ans.push_back(v[endingRow][i]);
            count++;
        }
        endingRow--;

        for(int i=endingRow;i>=startingRow && count<total;i--){
            ans.push_back(v[i][startingCol]);
            count++;
        }
        startingCol++;

    }
    return ans;
}
int main(){
    vector<vector<int>>ans {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    vector<int>vrr=spiralMatrix(ans);
    for(auto it:vrr){
        cout << it << " ";
    }
    return 0;
}