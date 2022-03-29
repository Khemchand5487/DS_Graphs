// Representation of graph using adjacency matrix and adjacency list in c++

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; // number of nodes
    cin>>n;
    int e; // number of edges
    cin>>e;
    
    int adjMat[n+1][n+1]; //adjacency matrix declaration
    vector<int> adjList[n+1]; //adjacency list declaration
    
    //initializing adjacency matrix with zeros;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++) adjMat[i][j] = 0;
    }
    
    for(int i=0;i<e;i++)
    {
        int u, v;
        cin>>u>>v;
        
        //input using adjacency matirx
        adjMat[u][v] = 1; // means node u is connected with node v 
        adjMat[v][u] = 1; //means node v is connected with u
        
        //input using adjacency list
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    //printing adjMat
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++) cout<<adjMat[i][j]<<" ";
        cout<<endl;
    }
    
    //printing adjList
    for(int i=0;i<=n;i++)
    {
        for(auto j: adjList[i]) cout<<j<<" ";
        cout<<endl;
    }
    
    return 0;
}
