#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(m*n) -->
// <!-- space complexity : O(n) -->

int solve(int m,int n,vector<vector<int>>& dp){
	if(m==0 && n==0) return 1;
	if(m<0 || n<0) return 0;
	if(dp[m][n]!=-1) return dp[m][n];
	int up = solve(m-1,n,dp);
	int left = solve(m,n-1,dp);
	return dp[m][n] = left + up; 
}

int uniquePath(int m,int n){
	
	// <!-- memoisation -->
	
	// vector<vector<int>> dp(m,vector<int>(n,-1));
	// return solve(m-1,n-1,dp);
	
	// <!-- top down -->
	
	// vector<vector<int>> dp(m,vector<int>(n,-1));
	// for(int i=0;i<m;i++){
	// 	for(int j=0;j<n;j++){
	// 		if(i==0 && j==0) dp[i][j] = 1;
	// 		else{
	// 			int up = 0;
	// 			int left = 0;
	// 			if(i>0) up = dp[i-1][j];
	// 			if(j>0) left = dp[i][j-1];
	// 			dp[i][j] = up + left; 
	// 		}
	// 	}
	// }
	// return dp[m-1][n-1];
	
	// <!-- space optimisation to O(n) -->
	
	vector<int> dp(n,-1);
	for(int i=0;i<m;i++){
		vector<int> temp(n,-1);
		for(int j=0;j<n;j++){
			if(i==0 && j==0) temp[j] = 1;
			else{
				int up = 0;
				int left = 0;
				if(i>0) up = dp[j];
				if(j>0) left = temp[j-1];
				temp[j] = up + left; 
			}
		}
		dp = temp;
	}
	return dp[n-1];

}

int main(){
	int m,n;
	cin >> m >> n;
	cout << uniquePath(m,n) << endl;
	return 0;
}