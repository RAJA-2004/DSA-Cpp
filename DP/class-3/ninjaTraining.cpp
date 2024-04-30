#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n*4)*3 -->
// <!-- space complexity : O(n) + O(n) -->

int solve(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
	if(day == 0){
		int maxi = 0;
		for(int i=0;i<3;i++){
			if(i != last){
				maxi = max(maxi,points[0][i]);
			}
		}
		return maxi;
	}
	if(dp[day][last] != -1) return dp[day][last];
	int maxi = 0;
	for(int i=0;i<3;i++){
		if(i != last){
			int p = points[day][i] + solve(day-1,i,points,dp);
			maxi = max(maxi,p);
		}
	}
	return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points){
	
	// <!-- memoisation -->
	
	// vector<vector<int>> dp(n,vector<int>(4,-1));
	// return solve(n-1,3,points,dp);
	
	// <!-- top down -->
	
	// vector<vector<int>> dp(n,vector<int>(4,0));
	// dp[0][0] = max(points[0][1],points[0][2]);
	// dp[0][1] = max(points[0][0],points[0][2]);
	// dp[0][2] = max(points[0][0],points[0][1]);
	// dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
	
	// for(int i=1;i<n;i++){
	// 	for(int j=0;j<4;j++){
	// 		dp[i][j] = 0;
	// 		for(int k=0;k<3;k++){
	// 			if(k!=j){
	// 				int p = points[i][k] + dp[i-1][k];
	// 				dp[i][j] = max(dp[i][j],p);
	// 			}
	// 		}
	// 	}
	// }
	// return dp[n-1][3];
	
	
	// <!-- space optimisation to O(4)-->
	
	vector<int> dp(4,0);
	dp[0] = max(points[0][1],points[0][2]);
	dp[1] = max(points[0][0],points[0][2]);
	dp[2] = max(points[0][0],points[0][1]);
	dp[3] = max(points[0][0],max(points[0][1],points[0][2]));
	
	for(int i=1;i<n;i++){
		vector<int> temp(4,0);
		for(int j=0;j<4;j++){
			temp[j] = 0;
			for(int k=0;k<3;k++){
				if(k!=j){
					temp[j] = max(temp[j],points[i][k]+dp[k]);
				}
			}
		}
		dp = temp;
	}
	return dp[3];
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> points(n, vector<int>(3,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			int a;
			cin >> a;
			points[i][j]=a;
		}
	}
	cout << ninjaTraining(n,points) << endl;
	return 0;
}