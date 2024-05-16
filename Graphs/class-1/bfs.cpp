#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n) + O(2*Edges) -->
// <!-- space complexity : O(n) -->

vector<int> bfs(int n, vector<int> adj[]){
	queue<int> q;
	q.push(0);
	vector<int> vis(n,0);
	vis[0] = 1;
	vector<int> bf;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		bf.push_back(node);
		for(auto it : adj[node]){
			if(!vis[it]){
				vis[it] = 1;
				q.push(it);
			}
		}
	}
	return bf;
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
	ans = bfs(n,adj);
	for(auto val : ans){
		cout << val << " ";
	}
	return 0;
}