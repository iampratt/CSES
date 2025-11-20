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
    vector<int> x(n);
    vector<vector<ll>> dp(n, vector<ll>(n, -1e18)); // dp[l][r]=Net score of first in range l..r
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        dp[i][i] = x[i];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int l = 0; l + i - 1 < n; l++)
        {
            int r = l + i - 1;
            dp[l][r] = max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
        }
    }
    ll total = accumulate(all(x), 0LL);
    ll res = (total + dp[0][n - 1]) / 2;
    cout << res;
    return 0;
}