#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n + 2*edges) -->
// <!-- space complexity : O(n) -->

bool dfs(int node,int color,vector<int> graph[],int vis[]){
	vis[node]=color;
	for(auto it : graph[node]){
		if(vis[it]==-1){
			if(dfs(it,!color,graph,vis)==false) return false;
		}
		else if(vis[it]==color) return false;
	}
	return true;
}

bool isBipartite(vector<int>graph[],int n){
	int vis[n];
	for(int i=0;i<n;i++) vis[i]=-1;
	for(int i=0;i<n;i++){
		if(vis[i]==-1){
			if(dfs(i,0,graph,vis)==false) return false;
		}
	}
	return true;
}

int main(){
	int m,n;
	cin >> n >> m;
	vector<vector<int>> grid(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> grid[i][j];
		}
	}
	vector<int> adj[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]==1 && i!=j){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	if(isBipartite(adj,n)==false){
		cout << "false";
	}else{
		cout << "true";
	}
	return 0;
}