#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(m*n) -->
// <!-- space complexity : O(m*n) -->

int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int count = 0;
        int countFresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1) count++;
            }
        }
        int time = 0;
        int d1[] = {0,-1,0,+1};
        int d2[] = {-1,0,+1,0};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(t,time);
            q.pop();
            for(int i=0;i<4;i++){
                int nr = row + d1[i];
                int nc = col + d2[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc]==1 && vis[nr][nc] != 2){
                    vis[nr][nc]=2;
                    q.push({{nr,nc},t+1});
                    countFresh++;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]==1 && vis[i][j]!=2){
        //             return -1;
        //         }
        //     }
        // }
        if(count != countFresh) return -1;
        return time;
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
	cout << orangesRotting(isConnected);
	return 0;
}