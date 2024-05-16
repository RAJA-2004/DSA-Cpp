#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(m) -->
// <!-- space complexity : O(2*edges) -->

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        // ! for undirected graph -> O(2*E)
        adj[u].push_back(v);
        adj[v].push_back(u);

        // ! for directed graph only one will be true -> O(E)
        // adj[u].push_back(v);
    }
    return 0;
}