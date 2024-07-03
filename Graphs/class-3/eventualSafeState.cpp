#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n+edge) -->
// <!-- space complexity : O(3n) -->

bool dfs(int node, vector<int> graph[], int vis[], int pathVis[],int check[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;
    for (auto it : graph[node]) {
        if (!vis[it]) {
            if (dfs(it, graph, vis, pathVis,check) == true) return true;
        } else if (pathVis[it]) return true;
    }
    check[node] = 1;
    pathVis[node] = 0;
    return false;
}

vector<int> cycle(vector<int> graph[], int n) {
    int vis[n];
    int pathVis[n];
    int check[n];
    vector<int> ans;
    for(int i=0;i<n;i++){
    	vis[i]=0;
    	pathVis[i]=0;
        check[i]=0;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, graph, vis, pathVis,check);
       }
    }
    for(int i=0;i<n;i++){
        if(check[i]==1){
            ans.push_back(i);
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
    vector<int> ans = cycle(adj,n);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}
