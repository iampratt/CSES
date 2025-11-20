#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    vector<vector<ll>> dp(s.size() + 1, vector<ll>(t.size() + 1, 1e9));
    for (int i = 0; i <= s.size(); i++)
        dp[i][0] = i;
    for (int i = 0; i <= t.size(); i++)
        dp[0][i] = i;
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }
    cout << dp[s.size()][t.size()];
    return 0;
}