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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        adj[u].pb({v, d});
    }
    vector<ll> dist(n, LLONG_MAX);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [cd, u] = pq.top();
        pq.pop();
        if (dist[u] < cd)
            continue;
        for (auto [v, nd] : adj[u])
        {
            if (cd + nd < dist[v])
            {
                dist[v] = cd + nd;
                pq.push({dist[v], v});
            }
        }
    }
    for (ll i : dist)
        cout << i << " ";
    return 0;
}