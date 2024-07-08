#include <bits/stdc++.h>
using namespace std;

int canPartition(vector<int>& nums,int sum) {
    int m = nums.size();
    int n = sum;
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0) dp[i][j]=0;       
            if(j==0) dp[i][j]=1;
        }
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(nums[i-1]<=j){
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[m][n];
}

int main(){
	int m;
	cin >> m;
	vector<int> ans(m);
	for(int i=0;i<m;i++){
		cin >> ans[i];
	}
	cout << canPartition(ans,10) << endl;
	return 0;
}