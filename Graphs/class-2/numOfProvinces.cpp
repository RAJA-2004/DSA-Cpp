#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> adj[],vector<vector<int>>& isConnected,vector<int>& vis) {
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,isConnected,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,adj,isConnected,vis);
            }
        }
        return count;
    }
    
int main(){
	int n;
	cin >> n;
	vector<vector<int>> isConnected(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> isConnected[i][j];
		}
	}
	cout << findCircleNum(isConnected);
	return 0;
}