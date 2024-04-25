#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity : O(n)  -->
// <!-- space complexity : O(n)+O(n) -->
int fibo(int n, vector<int>& dp){
	if(n<=1) return n;
	if(dp[n]!=-1) return dp[n];
	return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
}

int main(){
	int n;
	cin >> n;
	// vector<int> dp(n+1,-1);
	// cout << fibo(n,dp);
	
	// <!-- time complexity  : O(n) -->
	// <!-- space complexity : O(n) -->
	// vector<int> dp(n+1,-1);
	// dp[0] = 0;
	// dp[1] = 1;
	// for(int i=2;i<=n;i++){
	// 	dp[i] = dp[i-1]+dp[i-2];
	// }
	// cout << dp[n] << endl;
	
	// <!-- time complexity  : O(n) -->
	// <!-- space complexity : O(1) -->
	int prev1 = 0;
	int prev2 = 1;
	for(int i=2;i<=n;i++){
		int curr = prev1+prev2;
		prev1 = prev2;
		prev2 = curr;
	}
	cout << prev2 << endl;
	
	return 0;
}