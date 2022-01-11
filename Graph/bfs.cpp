#include <bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[], int n)
{
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = true;

            while (!q.empty())
            {
                int node = q.front();
                cout << node << " ";
                q.pop();

                for (auto u : adj[node])
                {
                    if (!vis[u])
                    {
                        q.push(u);
                        vis[u] = true;
                    }
                }
            }
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
    bfs(adj, n);
}