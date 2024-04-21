#include <bits/stdc++.h>
using namespace std;

int main(){
    // input n = rows
    // input m = edges
    int n,m;
    cin >> n >> m;
    vector<vector<int> > adj(n+1,vector<int>(m+1,0));

    // input of m lines
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        // ! mark the points as 1 and also the reverse
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}