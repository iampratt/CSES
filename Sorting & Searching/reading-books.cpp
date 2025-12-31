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
    ll total = 0, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        total += t;
        maxi = max(maxi, t);
    }
    cout << max(total, 2 * maxi);
    return 0;
}