#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(m*n) -->
// <!-- space complexity : O(m*n) -->

int solve(vector<vector<int>>& grid,int m, int n,vector<vector<int>>& dp){
	
	// <!-- dp + memoisation -->
	
	if(m==0 and n==0) return grid[0][0];
	if(m<0 || n<0) return 1e9;
	if(dp[m][n]!=-1) return dp[m][n];
	int up = grid[m][n] + solve(grid,m-1,n,dp);
	int left = grid[m][n] + solve(grid,m,n-1,dp);
	return dp[m][n] = min(left,up);
}

int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	
	// vector<vector<int>> dp(m,vector<int>(n,-1));
	// return solve(grid,m-1,n-1,dp);
	
	// <!-- top down -->
	// vector<vector<int>> dp(m,vector<int>(n,0));
	// for(int i=0;i<m;i++){
	// 	for(int j=0;j<n;j++){
	// 		if(i==0 && j==0) dp[i][j] = grid[i][j];
	// 		else{
	// 			int up = grid[i][j];
	// 			if(i > 0) up+=dp[i-1][j];
	// 			else up+=1e9;
				
	// 			int left = grid[i][j];
	// 			if(j > 0) left+=dp[i][j-1];
	// 			else left+=1e9;
				
	// 			dp[i][j] = min(up,left);
	// 		}
	// 	}
	// }
	// return dp[m-1][n-1];
	
	// <!-- space optimisation to O(n) -->
	vector<int> dp(m,0);
	for(int i=0;i<m;i++){
		vector<int> temp(n,0);
		for(int j=0;j<n;j++){
			if(i==0 && j==0) temp[j] = grid[i][j];
			else{
				int up = grid[i][j];
				if(i > 0) up += dp[j];
				else up += 1e9;
				
				int left = grid[i][j];
				if(j > 0) left += temp[j-1];
				else left += 1e9;
				
				temp[j] = min(up,left);
			}
		}
		dp = temp;
	}
	return dp[n-1];
}

int main(){
	int m,n;
	cin >> m >> n;
	vector<vector<int>> grid(m, vector<int>(n,0));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> grid[i][j];
		}
	}
	cout << minPathSum(grid);
	return 0;
}