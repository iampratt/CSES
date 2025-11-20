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
    vector<int> a(n), dp(x + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
            if (a[i] <= j)
                dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
    }
    cout << dp[x];
    return 0;
}