#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n*sum) -->
// <!-- space complexity : O(1) -->

bool subset(vector<int>& ans, int sum){
    int n = ans.size();
    bool dp[n+1][sum+1];
    memset(dp,false,sizeof(dp));
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum+1; j++){
        	if(i==0) dp[i][j]=false;
        	if(j==0) dp[i][j]=true;
        }
    }
    
    for(int i=1;i<n+1;i++){
    	for(int j=1;j<sum+1;j++){
    		if(ans[i-1]<=j){
    			dp[i][j]=dp[i-1][j-ans[i-1]] || dp[i-1][j];
    		}
    		else{
    			dp[i][j]=dp[i-1][j];
    		}
    	}
    }
    return dp[n][sum];
}

int main(){
    int n;
    cin >> n;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        ans.push_back(a);
    }
    int sum;
    cin >> sum;
    cout << subset(ans, sum) << endl;
    return 0;
}
