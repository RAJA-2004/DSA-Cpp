#include <bits/stdc++.h>
using namespace std;

void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>>& vec, int rbase,int cbase){
        vis[row][col]=1;
        vec.push_back({row-rbase,col-cbase});
        int d1[] = {0,-1,0,+1};
        int d2[] = {-1,0,+1,0};
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<4;i++){
            int nrow = row + d1[i];
            int ncol = col + d2[i];
            
            if(nrow>=0 && ncol >=0 && nrow<n && ncol <m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,vis,vec,rbase,cbase);
            }
        }
    }
int countDistinctIslands(vector<vector<int>>& grid){
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> vis(n,vector<int>(m,0));
	set<vector<pair<int,int>>> st;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			vector<pair<int,int>> v;
			if(!vis[i][j] && grid[i][j]==1){
				dfs(i,j,grid,vis,v,i,j);
				st.insert(v);
			}
		}
	}
	return st.size();
}

int main(){
	int m,n;
	cin >> n >> m;
	vector<vector<int>> grid(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> grid[i][j];
		}
	}
	cout << countDistinctIslands(grid);
	return 0;
}