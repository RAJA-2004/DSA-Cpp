#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n+2*edges) -->
// <!-- space complexity : O(n) -->

bool detect(int node, int parent, vector<int> adj[],vector<int>& vis){
	vis[node] = 1;
	for(auto adjnodes : adj[node]){
		if(!vis[adjnodes]){
			if(detect(adjnodes, node, adj, vis)==true) return true;
			
		}
		else if(parent != adjnodes){
			return true;
		}
	}
	return false;	
}

bool cycle(int V, vector<int> adj[]) {
	vector<int> vis(V,0);
	
	// if connected components are present and it is 0 based numbering
	for(int i=0;i<V;i++){
      	if(!vis[i]){
      		if(detect(i,-1,adj,vis)==true){
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