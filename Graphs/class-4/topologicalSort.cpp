#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(V+Edges) -->
// <!-- space complexity : O(n) -->

void dfs(int node,vector<int> adj[],int vis[],stack<int>& st){
	vis[node] = 1;
	for(auto it : adj[node]){
		if(!vis[it]){
			dfs(it,adj,vis,st);
		}
	}
	st.push(node);
}

vector<int> topo(vector<int> adj[],int n){
	int vis[n];
	for(int i=0;i<n;i++) vis[i]=0;
	stack<int> st;
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i,adj,vis,st);
		}
	}
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int edge;
            cin >> edge;
            if (edge == 1) {
                adj[i].push_back(j);
            }
        }
    }
    vector<int> ans = topo(adj,n);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}
