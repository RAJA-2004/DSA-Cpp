#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n) + O(2*Edges) -->
// <!-- space complexity : O(n) -->

void df(int node,vector<int> vis,vector<int>& ls,vector<int> adj[]){
	vis[node] = 1;
	ls.push_back(node);
	for(auto it : adj[node]){
		if(!vis[it]){
			df(it,vis,ls,adj);
		}
	}
}

vector<int> dfs(int n, vector<int> adj[]){
	vector<int> vis(n,0);
	vis[0] = 1;
	vector<int> ls;
	df(0,vis,ls,adj);
	return ls;
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	vector<int> ans;
	ans = dfs(n,adj);
	for(auto val : ans){
		cout << val << " ";
	}
	return 0;
}