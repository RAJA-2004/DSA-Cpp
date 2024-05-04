#include <bits/stdc++.h>
using namespace std;

// <!-- Variable Starting and Ending Points -->

// <!-- time complexity  : O(n*n) -->
// <!-- space complexity : O(n*n) -->

int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp,int n){
	if(j<0 || j>=n) return 1e9;
	if(i==0) return matrix[0][j];
	if(dp[i][j]!=-1) return dp[i][j];
	
	int move1 = matrix[i][j] + solve(i-1,j,matrix,dp,n);
	int move2 = matrix[i][j] + solve(i-1,j+1,matrix,dp,n);
	int move3 = matrix[i][j] + solve(i-1,j-1,matrix,dp,n);
	
	return dp[i][j] = min(move1,min(move2,move3));
}

int minFallingPathSum(vector<vector<int>>& matrix) {
	
	// <!-- dp + memoisation -->
	
	// int m = matrix.size();
	// int n = matrix[0].size();
	// vector<vector<int>> dp(n,vector<int>(n,-1));
	// int mini = INT_MAX;
	// for(int i=0;i<n;i++){
	// 	int point = solve(m-1,i,matrix,dp,n);
	// 	mini = min(point,mini);
	// }
	// return mini;
	
	// <!-- tabulation -->
	
	int m = matrix.size();
	int n = matrix[0].size();
	int dp[m][n];
	for(int j=0;j<n;j++){
		dp[0][j] = matrix[0][j];
	}
	
	for(int i=1;i<m;i++){
		for(int j=0;j<n;j++){
			 int move1 = matrix[i][j] + dp[i-1][j];
			 int move2 = matrix[i][j]; 
			 if(j+1 <n) move2 += dp[i-1][j+1];
			 else move2+=1e9;
			 
			 int move3 = matrix[i][j];
			 if(j-1>=0) move3 += dp[i-1][j-1];
			 else move3 += 1e9;
			 
			 dp[i][j] = min(move1,min(move2,move3));
		}
	}
	
	int mini = INT_MAX;
	for(int j=0;j<n;j++){
		mini = min(mini,dp[n-1][j]);
	}
	return mini;
}
int main(){
	int n;
	cin >> n;
	vector<vector<int>> matrix(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> matrix[i][j];
		}
	}
	cout << minFallingPathSum(matrix) << endl;
	return 0;
}