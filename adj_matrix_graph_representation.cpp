// Undirected graph representation using adjacency matrix

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    
    /*
        n:= number of nodes of vertices
        m:= number of edges
    */
    
    int adj[n+1][n+1]; // adjacency matrix
    
    //initializing matrix with zeroes
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++) adj[i][j] = 0;
    }
    
    int u, v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    //printing the graph
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++) cout<<adj[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
