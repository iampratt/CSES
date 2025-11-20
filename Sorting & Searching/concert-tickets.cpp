#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<ll> h;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        h.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        ll t;
        cin >> t;
        auto it = h.lower_bound(t + 1);
        if (it == h.begin())
            cout << -1 << endl;
        else
        {
            cout << *(--it) << endl;
            h.erase(it);
        }
    }
    return 0;
}