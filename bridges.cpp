/*
Title: Finding number of bridges in given graph or Tarjans Algorithm
Complexity: Time - O(N+E); Space - O(N)
where,
      N: Number of nodes
      E: Number of edges
*/

#include <bits/stdc++.h>

using namespace std;

void dfs(int node, int parent, int timer, vector<int>& inTime, vector<int>& low, vector<int> adj[], vector<int>& visited) {
    
    visited[node] = 1;
    low[node] = timer;
    inTime[node] = timer++;
    for(int i: adj[node]) {
        if(i==parent) continue;
        
        if(!visited[i]) {
            dfs(i, node, timer, inTime, low, adj, visited);
            low[node] = min(low[i], low[node]);
            if(low[i] > low[node]) {
                cout<<node<<" "<<i<<endl;
            }
        }
        else low[node] = min(low[i], low[node]);
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    int u, v;
    std::vector<int> adj[n];
    for(int i=0;i<m;i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> visited(n, 0), inTime(n,-1), low(n, -1);
    int timer=0;
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            dfs(i, -1, timer, inTime, low, adj, visited);
        }
    }

    return 0;
}
