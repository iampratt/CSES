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
    vector<int> h(n), s(n), dp(x + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = x; j >= 0; j--)
            if (j >= h[i])
                dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
    cout << dp[x];
    return 0;
}