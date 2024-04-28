#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n*W) -->
// <!-- space complexity : O(n*W) -->

int solve(int W, int wt[], int val[], int n, int dp[][1002]){
	if(n==0 || W==0) return 0;
	if(dp[n][W]!=-1) return dp[n][W];
	if(wt[n-1]<=W){
		return dp[n][W]=max(val[n-1]+solve(W-wt[n-1],wt,val,n-1,dp),solve(W,wt,val,n-1,dp));
	}
	else if(wt[n-1]>W){
		return dp[n][W]=solve(W,wt,val,n-1,dp);
	}
}

int knapSack(int W, int wt[], int val[], int n){
    int dp[1002][1002];
    memset(dp,-1,sizeof(dp));
   	return solve(W,wt,val,n,dp);
}

int main(){
	int n,w;
	cin >> n >> w;
	int wt[n];
	int val[n];
	for(int i=0;i<n;i++){
		cin >> wt[i];
	}
	for(int i=0;i<n;i++){
		cin >> val[i];
	}
	cout << knapSack(w,wt,val,n);
	return 0;
}