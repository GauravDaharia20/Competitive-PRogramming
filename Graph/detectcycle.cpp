#include <bits/stdc++.h>
using namespace std;
/*
    logic : check if the current element is vis and not equal to parent then it has loop.
*/
bool check(int s, vector<int> adj[], vector<bool> &vis)
{
    queue<pair<int, int>> q;
    vis[s] = true;
    q.push({s, -1});

    while (!q.empty())
    {
        pair<int, int> node = q.front();

        int p = node.first;
        int c = node.second;

        q.pop();

        for (auto i : adj[p])
        {
            if (!vis[i])
            {
                vis[i] = true;
                q.push({i, p});
            }
            else if (c != i)
            {
                return true;
            }
        }
    }
    return false;
}
bool checkloop(vector<int> adj[], int n)
{
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (check(i, adj, vis))
                return true;
        }
    }
    return false;
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

    cout << checkloop(adj, n);
}