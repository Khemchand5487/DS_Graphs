// BFS traversal of graph using adjacency list in c++

#include <bits/stdc++.h>

using namespace std;

void BFS(vector<int> adj[], int n, int s)
{
    int visited[n+1];
    memset(visited, 0, sizeof(visited));
    
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        cout<<node<<" ";
 
        for(auto i: adj[node])
        {
            if(!visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
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
    BFS(adjList, n, 1);
    
    return 0;
}
