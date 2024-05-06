#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    int m = nums.size();
    int sum = accumulate(nums.begin(),nums.end(),0);
    int n = sum;
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
    if(sum%2!=0) return false;
    else{
        n/=2;
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0) dp[i][j]=false;
                if(j==0) dp[i][j]=true;
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
   	}
}

int main(){
	int m;
	cin >> m;
	vector<int> ans(m);
	for(int i=0;i<m;i++){
		cin >> ans[i];
	}
	if(canPartition(ans)){
		cout << "yes" << endl;	
	}
	else cout << "no" << endl;	
	return 0;
}