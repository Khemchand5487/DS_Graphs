// Cycle detecttion in undirected graph using DFS traversal of graph in c++

#include <bits/stdc++.h>

using namespace std;

bool cycleDetectionDFS(vector<int> adj[], int s, vector<int>& visited, int prev)
{
    visited[s] = 1;
    // cout<<s<<" ";
    
    for(auto i: adj[s])
    {
        if(!visited[i])
        {
            if(cycleDetectionDFS(adj, i, visited, s)) return true;
        }
        else if( i!=prev)
        {
            return true;
        }
    }
    
    return false;
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
    if(cycleDetectionDFS(adjList, 1, visited, -1)) cout<<"YES";
    else cout<<"NO";
    
    return 0;
}
