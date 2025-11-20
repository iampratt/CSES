#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n), dp(x + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i <= x; i++)
    {
        if (i == 0)
            dp[i] = 1;
        else
        {
            dp[i] = 0;
            for (int j = 0; j < n; j++)
                if (a[j] <= i)
                    dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
        }
    }
    cout << dp[x];
    return 0;
}