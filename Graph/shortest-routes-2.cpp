#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<ll>> dist(n, vector<ll>(n, 1e18));
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        adj[u].pb({v, d});
        if (d < dist[u][v])
            dist[u][v] = dist[v][u] = d;
    }
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                ll nd = dist[i][k] + dist[k][j];
                if (nd < dist[i][j])
                    dist[i][j] = dist[j][i] = nd;
            }
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << (dist[u][v] == 1e18 ? -1 : dist[u][v]) << '\n';
    }
    return 0;
}