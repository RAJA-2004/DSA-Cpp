#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(V+edges) -->
// <!-- space complexity : O(n) -->

vector<int> topo(vector<int> adj[],int n){
	int indegree[n];
	for(int i=0;i<n;i++) indegree[i]=0;
	queue<int> q;
	for(int i=0;i<n;i++){
		for(auto it : adj[i]){
			indegree[it]++;
		}
	}
	for(int i=0;i<n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	vector<int> ans;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		ans.push_back(node);
		
		for(auto it : adj[node]){
			indegree[it]--;
			if(indegree[it]==0){
				q.push(it);
			}
		}
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
