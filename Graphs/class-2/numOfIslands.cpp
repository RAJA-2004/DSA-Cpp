#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> adj[],vector<int>& vis,vector<vector<int>>& isConnected){
	vis[node] = 1;
	for(auto it : adj[node]){
		if(!vis[it]){
			dfs(it,adj,vis,isConnected);
		}
	}
}

void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>> adj){
	vis[row][col] = 1;
	queue<pair<int,int>> q;
	q.push({row,col});
	
	int n = adj.size();
	int m = adj[0].size();
	
	while(!q.empty()){
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		
		vector<pair<int,int>> direction = {{0,1},{1,0},{-1,0},{0,-1}};
		for(auto val : direction){
			int nr = row + val.first;
			int nc = col + val.second;
			if(nr >= 0 && nr < n && nc >= 0 && nc < m && adj[nr][nc] == '1' && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
            }
		}
	}
}

int numIsland(vector<vector<char>> isConnected){
	
	// <!-- DFS -->
	
	// int V = isConnected.size();
	// vector<int> adj[V];
	// for(int i=0;i<V;i++){
	// 	for(int j=0;j<V;j++){
	// 		if(isConnected[i][j]==1 && i!=j){
	// 			adj[i].push_back(j);
	// 			adj[j].push_back(i);
	// 		}
	// 	}
	// }
	// vector<int> vis(V,0);
	// int count = 0;
	// for(int i=0;i<V;i++){
	// 	if(!vis[i])
	// 		count++;
	// 		dfs(i,adj,vis,isConnected);
	// }
	// return count;
	
	// <!-- BFS -->
	int n = isConnected.size();
	int m = isConnected[0].size();
	vector<vector<int>> vis(n,vector<int>(m,0));
	int count = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j] && isConnected[i][j]=='1'){
				count++;
				bfs(i,j,vis,isConnected);
			}
		}
	}
	return count;
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<char>> isConnected(n,vector<char>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> isConnected[i][j];
		}
	}
	cout << numIsland(isConnected);
	return 0;
}