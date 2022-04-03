// BFS traversal of graph using adjacency list in c++

#include <bits/stdc++.h>

using namespace std;

void DFS(vector<int> adj[], int s, vector<int>& visited)
{
    visited[s] = 1;
    cout<<s<<" ";
    
    for(auto i: adj[s])
    {
        if(!visited[i])
        {
            DFS(adj, i, visited);
        }
    }
}

int main()
{
    int n; // number of nodes
    cin>>n;
    int e; // number of edges
    cin>>e;

    vector<int> adjList[n+1]; //adjacency list declaration

    int u, v;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;

        //input using adjacency list
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    //printing adjList
    vector<int> visited(n+1, 0);
    DFS(adjList, 1, visited);
    
    return 0;
}
