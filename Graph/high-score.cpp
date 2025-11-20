#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> adj1, adj2;
vector<ll> dist;
vector<bool> vis1, vis2;

void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj)
{
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v, vis, adj);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    adj.resize(n);
    adj1.resize(n);
    adj2.resize(n);
    vis1.resize(n, false);
    vis2.resize(n, false);
    dist.resize(n, -1e18);
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        adj[u].pb({v, d});
        adj1[u].pb(v);
        adj2[v].pb(u);
    }
    dfs(0, vis1, adj1);
    dfs(n - 1, vis2, adj2);
    dist[0] = 0;
    bool cycle = false;
    for (int i = 0; i < n; i++)
    {
        cycle = false;
        for (int u = 0; u < n; u++)
            for (auto [v, d] : adj[u])
                if (dist[u] != -1e18 && dist[v] < dist[u] + d)
                {
                    if (vis1[v] && vis2[v])
                        cycle = true;
                    dist[v] = dist[u] + d;
                }
    }
    if (cycle == true)
        cout << -1;
    else
        cout << dist[n - 1];
    return 0;
}