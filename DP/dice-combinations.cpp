#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n + 1);

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            dp[i] = 1;
        else
        {
            dp[i] = 0;
            for (int j = 1; j <= 6; j++)
            {
                if (j <= i)
                    dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    cout << dp[n];
    return 0;
}