#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll res = 0;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
            res += a[i - 1] - a[i], a[i] = a[i - 1];
    }
    cout << res;
    return 0;
}