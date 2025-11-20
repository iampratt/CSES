#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;
int n, m;
vector<vector<pair<int, int>>> adj1, adj2;
vector<ll> dist1, dist2;

void dijkstra(int i, vector<vector<pair<int, int>>> &adj, vector<ll> &dist)
{
    dist[i] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, i});
    while (!pq.empty())
    {
        auto [cd, u] = pq.top();
        pq.pop();
        if (dist[u] < cd)
            continue;
        for (auto [v, nd] : adj[u])
        {
            if (dist[v] > dist[u] + nd)
            {
                dist[v] = dist[u] + nd;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    adj1.resize(n);
    adj2.resize(n);
    dist1.resize(n, 1e18);
    dist2.resize(n, 1e18);
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        adj1[u].pb({v, d});
        adj2[v].pb({u, d});
    }
    dijkstra(0, adj1, dist1);
    dijkstra(n - 1, adj2, dist2);
    ll res = 1e18;
    for (int u = 0; u < n; u++)
    {
        for (auto [v, d] : adj1[u])
        {
            res = min(res, dist1[u] + dist2[v] + d / 2);
        }
    }
    cout << res;
    return 0;
}