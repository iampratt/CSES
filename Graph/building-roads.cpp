#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> res;

void dfs(int u)
{
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    adj.resize(n);
    vis.resize(n, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            res.push_back(i);
            dfs(i);
        }
    }
    cout << res.size() - 1 << '\n';
    for (int i = 0; i < res.size() - 1; i++)
        cout << res[i] + 1 << " " << res[i + 1] + 1 << '\n';
    return 0;
}