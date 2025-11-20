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
    int n;
    cin >> n;
    ll curr = -1e18, res = -1e18;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        curr = max(x, curr + x);
        res = max(res, curr);
    }
    cout << res;
    return 0;
}