#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n*n) -->
// <!-- space complexity : O(n*n) -->

int s(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j,int n){
	
	// <!-- dp + memoisation (started from beginning not the end) -->
	
	if(i==n-1) return grid[i][j];
	if(dp[i][j]!=-1) return dp[i][j];
	int down = grid[i][j] + s(grid,dp,i+1,j,n);
	int diagonal = grid[i][j] + s(grid,dp,i+1,j+1,n);
	return dp[i][j] = min(down,diagonal);
}

int solve(vector<vector<int>>& grid,int n){
	// vector<vector<int>> dp(n,vector<int>(n,-1));
	// return s(grid,dp,0,0,n);
	
	// <!-- tabulation -->
	
	vector<vector<int>> dp(n,vector<int>(n,0));
	for(int j=0;j<n;j++){
		dp[n-1][j] = grid[n-1][j];
	}
	for(int i=n-2;i>=0;i--){
		for(int j=i;j>=0;j--){
			int down = grid[i][j] + dp[i+1][j];
			int diagonal = grid[i][j] + dp[i+1][j+1];
			dp[i][j] = min(down,diagonal);
		}
	}
	return dp[0][0];
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> grid(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=i;j>=0;j--){
			cin >> grid[i][j];
		}
	}
	cout << solve(grid,n);
	return 0;
}