#include <bits/stdc++.h>
using namespace std;

vector<int> cs(vector<vector<int>> grid,int n){
	vector<int> adj[n];
	vector<int> indegree(n,0);
	for(auto it : grid){
		adj[it[0]].push_back(it[1]);
	}
	for(int i=0;i<n;i++){
		for(auto it : adj[i]){
			indegree[it]++;
		}
	}
	queue<int> q;
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
    vector<vector<int>> grid(n,vector<int>(n,0));
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	    {
    	    	cin >> grid[i][j];
    	    }
    }
    vector<int> ans = cs(grid,n);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}