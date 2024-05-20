#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n+2*edges) -->
// <!-- space complexity : O(n) -->

bool detect(int src, vector<int> adj[],vector<int>& vis){
	vis[src] = 1;
	queue<pair<int,int>> q;
	q.push({src,-1});
	while(!q.empty()){
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();
		
		for(auto adjnodes : adj[node]){
			if(!vis[adjnodes]){
				vis[adjnodes]=1;
				q.push({adjnodes,node});
			}
			else if(parent != adjnodes){
				return true;
			}
		}
	}
	return false;
}

bool cycle(int V, vector<int> adj[]) {
	vector<int> vis(V,0);
	
	// if connected components are present and it is 0 based numbering
	for(int i=0;i<V;i++){
      	if(!vis[i]){
      		if(detect(i,adj,vis)==true){
      			return true;
      		}
      	}
    }
    return false;
}
int main(){
	int n;
	cin >> n;
	vector<int> adj[n];
	vector<vector<int>> isConnected(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> isConnected[i][j];
		}
	}
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
	cout << cycle(n,adj);
	return 0;
}