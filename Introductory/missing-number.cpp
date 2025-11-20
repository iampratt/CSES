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
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (mp[i] == 0)
            cout << i << endl;
    }
    return 0;
}