#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(n+edge) -->
// <!-- space complexity : O(2n) -->

// <!-- O(n) approach -->

// bool dfs(int node, vector<int> graph[], int vis[]) {
//     vis[node] = 2;
//     for (auto it : graph[node]) {
//         if (!vis[it]) {
//             if (dfs(it, graph, vis) == true) return true;
//         } else if (pathVis[it]) return true;
//     }
//     vis[node] = vis[node]-1;
//     return false;
// }

// bool cycle(vector<int> graph[], int n) {
//     int vis[] = {0};
//     for (int i = 0; i < n; i++) {
//         if (!vis[i]) {
//             if (dfs(i, graph, vis) == true) return true;
//         }
//     }
//     return false;
// }


bool dfs(int node, vector<int> graph[], int vis[], int pathVis[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : graph[node]) {
        if (!vis[it]) {
            if (dfs(it, graph, vis, pathVis) == true) return true;
        } else if (pathVis[it]) return true;
    }
    pathVis[node] = 0;
    return false;
}

bool cycle(vector<int> graph[], int n) {
    int vis[n];
    int pathVis[n];
    for(int i=0;i<n;i++){
    	vis[i]=0;
    	pathVis[i]=0;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, graph, vis, pathVis) == true) return true;
        }
    }
    return false;
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

    if (cycle(adj, n) == false) {
        cout << "no cycle";
    } else {
        cout << "cycle";
    }
    return 0;
}
