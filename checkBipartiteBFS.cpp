// check bipartite using BFS traversal of graph in c++

#include <bits/stdc++.h>

using namespace std;

bool checkBipartiteBFS(vector<int> adj[], int n, int s)
{
    vector<int> visited(n+1, -1); // change in bfs
    
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        // cout<<node<<" ";
 
        for(auto i: adj[node])
        {
            if(visited[i]==-1)
            {
                visited[i] = !visited[node]; // change in bfs
                q.push(i);
            }
            else if(visited[i]==visited[node]) return false; // change in bfs
        }
    }
    return true;
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

    if(checkBipartiteBFS(adjList, n, 1)) cout<<"YES";
    else cout<<"NO";
    
    return 0;
}
