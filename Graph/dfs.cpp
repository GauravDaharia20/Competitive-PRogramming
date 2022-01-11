#include<bits/stdc++.h>
using namespace std;
void helpdfs(int node, vector<bool>&vis,vector<int> adj[])
{
    cout<<node<<" ";

    vis[node]=true;

    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            helpdfs(i,vis,adj);
        }
    }

}
void dfs( vector<int> adj[],int n)
{
    vector<bool>vis(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            helpdfs(i,vis,adj);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj, n);
}