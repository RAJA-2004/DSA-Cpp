#include <bits/stdc++.h>
using namespace std;

int solve(int n,int m, vector<vector<int> >& dp,vector<int>& arr){
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(arr[m-1]<=n){
        return dp[n][m] = max(arr[n-1]+solve(n-arr[n-1],m-1,dp,arr),solve(n,m-1,dp,arr));
    }
    else{
        return dp[n][m] = solve(n,m-1,dp,arr);
    }
}

int pro(int n,vector<int>& arr){
    int m = arr.size();
    vector<vector<int>  > dp(n+1,vector<int>(m+1,-1));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(i==0) dp[i][j]=0;
    //         if(j==0) dp[i][j]=1;
    //     }
    // }
    return solve(n,m,dp,arr);
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> ans(m);
    for(int i=0;i<m;i++){
        cin >> ans[i];
    }
    cout << pro(n,ans) << endl;
}