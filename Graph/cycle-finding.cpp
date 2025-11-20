#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<ll> dist;
vector<int> parent;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    adj.resize(n);
    dist.resize(n, 1e18);
    parent.resize(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        adj[u].pb({v, d});
    }
    dist[0] = 0;
    int start = -1;
    for (int i = 0; i < n; i++)
    {
        start = -1;
        for (int u = 0; u < n; u++)
            for (auto [v, d] : adj[u])
                if (dist[v] > dist[u] + d)
                {
                    dist[v] = dist[u] + d;
                    parent[v] = u;
                    start = v;
                }
    }
    if (start == -1)
        cout << "NO";
    else
    {
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++)
            start = parent[start];
        vector<int> res;
        int curr = start;
        do
        {
            res.pb(curr);
            curr = parent[curr];
        } while (curr ^ start);
        res.pb(start);
        reverse(all(res));
        for (int i : res)
            cout << i + 1 << " ";
    }
    return 0;
}