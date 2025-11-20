#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> adj;
vector<int> res;
bool imp = false;

void dfs(int u, int c)
{
    if (res[u] != -1)
        return;
    res[u] = c;
    int nc = (c == 1 ? 2 : 1);
    for (int v : adj[u])
    {
        if (res[v] == c)
        {
            imp = true;
            return;
        }
        dfs(v, nc);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    adj.resize(n);
    res.resize(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 0; i < n; i++)
        if (res[i] == -1 && !imp)
            dfs(i, 1);
    if (!imp)
        for (int i : res)
            cout << i << " ";
    else
        cout << "IMPOSSIBLE";
    return 0;
}