#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& board,vector<vector<int>>& vis){
	vis[row][col]=1;
	int n = board.size();
	int m = board[0].size();
	int d1[] = {0,-1,0,+1};
	int d2[] = {-1,0,+1,0};
	for(int i=0;i<4;i++){
		int nrow = row + d1[i];
		int ncol = col + d2[i];
		if(nrow >=0 && ncol >= 0 && nrow < n && ncol < m && board[nrow][ncol]==0 && !vis[nrow][ncol]){
			dfs(nrow,ncol,board,vis);
		}
	}
}

void solve(vector<vector<int>>& board){
	int n = board.size();
	int m = board[0].size();
	vector<vector<int>> vis(n,vector<int>(m,0));
	for(int i=0;i<m;i++){
		if(board[0][i]==0 && !vis[0][i]){
			dfs(0,i,board,vis);
		}
	}
	for(int i=0;i<m;i++){
		if(board[n-1][i]==0 && !vis[n-1][i]){
			dfs(n-1,i,board,vis);
		}
	}
	for(int i=0;i<n;i++){
		if(board[i][0]==0 && !vis[i][0]){
			dfs(i,0,board,vis);
		}
	}
	for(int i=0;i<n;i++){
		if(board[i][m-1]==0 && !vis[i][m-1]){
			dfs(i,m-1,board,vis);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j] && board[i][j]==0){
				board[i][j]=1;
			}
		}
	}
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
	solve(grid);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}