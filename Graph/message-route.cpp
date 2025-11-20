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
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<int> q;
    vector<int> p(n, -1);
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == n - 1)
            break;
        for (int v : adj[u])
        {
            if (p[v] == -1)
            {
                q.push(v);
                p[v] = u;
            }
        }
    }
    if (p[n - 1] == -1)
        cout << "IMPOSSIBLE";
    else
    {
        int u = n - 1;
        vector<int> res;
        while (u != 0)
        {
            res.pb(u);
            u = p[u];
        }
        res.pb(0);
        reverse(all(res));
        cout << res.size() << '\n';
        for (int i : res)
            cout << i + 1 << " ";
    }
    return 0;
}