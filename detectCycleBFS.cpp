// Detect Cycle in graph using BFS traversal of graph in c++

#include <bits/stdc++.h>

using namespace std;

bool detectCycleBFS(vector<int> adj[], int n, int s)
{
    int visited[n+1];
    memset(visited, 0, sizeof(visited));
    
    queue<pair<int, int>> q;
    q.push({s,-1});
    visited[s] = 1;
    
    while(!q.empty())
    {
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();
        
        // cout<<node<<" ";
        for(auto i: adj[node])
        {
            if(!visited[i])
            {
                visited[i] = 1;
                q.push({i, node});
            }
            else if(i != prev)
            {
                return true;
            }
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
    if(detectCycleBFS(adjList, n, 1)) cout<<"YES";
    else cout<<"NO";
    
    return 0;
}
