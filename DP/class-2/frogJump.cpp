#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n) -->
// <!-- space complexity : O(n) -->

int solve(int n, vector<int>& ans, vector<int>& dp){
	
	if(n==0) return 0;
	if(dp[n]!=-1) return dp[n];
	int left = solve(n-1,ans,dp) + abs(ans[n]-ans[n-1]);
	int right = INT_MAX;
	if(n>1) right = solve(n-2,ans,dp) + abs(ans[n]-ans[n-2]);
	return dp[n] = min(left,right);	
}

int frogjump(int n, vector<int>& ans){
	
	// <!-- memoisation -->
	
	// vector<int> dp(n,-1);
	// return solve(n-1,ans,dp);
	
	// <!-- top-down -->
	
	// vector<int> dp(n,-1);
	// dp[0] = 0;
	// for(int i=1;i<n;i++){
	// 	int right = INT_MAX;
	// 	int left = dp[i-1] + abs(ans[i]-ans[i-1]);
	// 	if(i>1){
	// 		right = dp[i-2] + abs(ans[i]-ans[i-2]);
	// 	}
	// 	dp[i] = min(left,right);
	// }
	// return dp[n-1];
	
	// <!-- space optimisation -->
	
	vector<int> dp(n,-1);
	int prev1 = 0;
	int prev2 = 0;
	for(int i=1;i<n;i++){
		int right = INT_MAX;
		int left = prev1 + abs(ans[i]-ans[i-1]);
		if(i>1){
			right = prev2 + abs(ans[i]-ans[i-2]);
		}
		int curr = min(left,right);
		prev2 = prev1;
		prev1 = curr;
		
	}
	return prev1;
}

int main(){
	int n;
	cin >> n;
	vector<int> ans;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		ans.push_back(a);
	}
	cout << frogjump(n,ans) << endl;
	return 0;
}