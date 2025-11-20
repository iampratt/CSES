#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int n, m, k;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
vector<vector<pair<int, int>>> adj;
vector<vector<ll>> res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    adj.resize(n);
    res.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        adj[u].pb({v, d});
    }
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [cd, u] = pq.top();
        pq.pop();
        if (res[u].size() >= k)
            continue;
        for (auto [v, nd] : adj[u])
        {
            pq.push({cd + nd, v});
        }
        for (int i : res[n - 1])
            cout << i << " ";
        return 0;
    }
}