#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& ans, vector<int>& dp){
	if(n==0) return 0;
	if(dp[n]!=-1) return dp[n];
	int left = solve(n-1,ans,dp) + abs(ans[n]-ans[n-1]);
	int right = INT_MAX;
	if(n>1) right = solve(n-2,ans,dp) + abs(ans[n]-ans[n-2]);
	return dp[n] = min(left,right);
}

int frogjump(int n, vector<int>& ans){
	vector<int> dp(n,-1);
	return solve(n-1,ans,dp);
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