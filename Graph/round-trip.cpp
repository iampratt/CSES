#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> parent;
int cycleStart = -1;
int cycleEnd = -1;

bool dfs(int u, int p)
{
    parent[u] = p;
    vis[u] = true;
    for (int v : adj[u])
    {
        if (!vis[v])
            dfs(v, u);
        else if (v != p)
        {
            cycleStart = v;
            cycleEnd = u;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    adj.resize(n);
    vis.resize(n, false);
    parent.resize(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 0; i < n; i++)
        if (!vis[i] && dfs(i, -1))
            break;
    if (cycleStart == -1)
        cout << "IMPOSSIBLE";
    else
    {
        vector<int> res;
        res.pb(cycleEnd);
        int x = cycleStart;
        while (x ^ cycleEnd)
        {
            res.pb(x);
            x = parent[x];
        }
        res.pb(cycleEnd);
        cout << res.size() << '\n';
        for (int i : res)
            cout << i + 1 << " ";
    }
    return 0;
}