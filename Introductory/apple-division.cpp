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
    int n;
    cin >> n;
    vector<int> p(n);
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        total += p[i];
    }
    ll res = LLONG_MAX;
    for (int mask = 0; mask < 1 << n; mask++)
    {
        ll curr = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                curr += p[i];
        res = min(res, abs(curr - (total - curr)));
    }
    cout << res;
    return 0;
}