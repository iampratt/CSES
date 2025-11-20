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
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        int j = i;
        while (j != 0)
        {
            dp[i] = min(dp[i], dp[i - j % 10] + 1);
            j /= 10;
        }
    }
    cout << dp[n];
    return 0;
}