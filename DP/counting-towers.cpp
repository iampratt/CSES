#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int MOD = 1e9 + 7;

vector<vector<ll>> dp(1e6, vector<ll>(2));

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        dp[0][0] = 1; // double 1 row
        dp[0][1] = 1; // single 2 rows
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = (2LL * dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][1] = (dp[i - 1][0] + 4LL * dp[i - 1][1]) % MOD;
        }
        cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;
    }
    return 0;
}