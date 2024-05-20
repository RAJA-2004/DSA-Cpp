#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int d1[] = {0,-1,0,+1};
        int d2[] = {-1,0,+1,0};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            ans[row][col] = dis;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + d1[i];
                int ncol = col + d2[i];

                if(nrow >= 0 && ncol >=0 && nrow < n && ncol <m && !vis[nrow][ncol] && mat[nrow][ncol]!=0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dis+1});
                }
            }
        }
        return ans;
    }

int main(){
    int n;
    cin >> n;
    vector<vector<int>> isConnected(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> isConnected[i][j];
        }
    }
    vector<vector<int>> ans=updateMatrix(isConnected);
    for(auto val : ans){
        for(auto vals : val){
            cout << vals << " ";
        }
        cout << endl;
    }
    return 0;
}