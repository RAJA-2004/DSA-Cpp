#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n) -->
// <!-- space complexity : O(1) -->

int solve(int n){
	
	// if(n<=1) return 1;
	// return solve(n-1)+solve(n-2);
	
	vector<int> dp(n+1,-1);
	
	// if(n<=1) return 1;
	// if(dp[n]!=-1) return dp[n];
	// return dp[n] = solve(n-1)+solve(n-2);
	
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2;i<n+1;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int main(){
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}