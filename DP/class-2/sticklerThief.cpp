#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n) -->
// <!-- space complexity : O(n) -->

int solve(vector<int>& ans,int n, vector<int>& dp){
	if(n==0) return 0;
	if(dp[n]!=-1) return dp[n];
	int include = ans[n-1]+solve(ans,n-2,dp);
	int exclude = solve(ans,n-1,dp);
	return dp[n] = max(include,exclude);
}

int thief(vector<int>& ans){
	
	// <!-- memoisation -->
	
	// vector<int> dp(ans.size()+1,-1);
	// int n = ans.size();
	// return solve(ans,n,dp);
	
	// <!-- top-down -->
	
	// int n = ans.size();
	// vector<int> dp(n+1,-1);
	// dp[0] = 0;
	// for(int i=1;i<n+1;i++){
	// 	int include = ans[i-1] + dp[i-2];
	// 	int exclude = dp[i-1];
	// 	dp[i] = max(include,exclude);
	// }
	// return dp[n];
	
	// <!-- space optimisation to O(1)-->
	
	int n = ans.size();
	int prev1 = ans[0];
	int prev2 = 0;
	for(int i=1;i<n+1;i++){
		int include = ans[i];
		if(i>1) include += prev2;
		int exclude = 0 + prev1;
		int curr = max(exclude,include);
		prev2 = prev1;
		prev1 = curr;
	}
	return prev1;
}

int main(){
	int n;
	cin >> n;
	vector<int> ans;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		ans.push_back(a);
	}
	cout << thief(ans) << endl;
	return 0;
}