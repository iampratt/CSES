#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    if (x[0] == 0)
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    else
        dp[0][x[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        if (x[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j - 1 > 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                if (j + 1 <= m)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
        else
        {
            dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i]]) % MOD;
            if (x[i] - 1 > 0)
                dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] - 1]) % MOD;
            if (x[i] + 1 <= m)
                dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] + 1]) % MOD;
        }
    }
    int res = 0;
    for (int i = 1; i <= m; i++)
        res = (res + dp[n - 1][i]) % MOD;
    cout << res;
    return 0;
}