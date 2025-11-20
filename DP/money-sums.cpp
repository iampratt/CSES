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
    for (int i = 0; i < n; i++)
        cin >> x[i];
    vector<bool> dp(1e5 + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1e5; j > 0; j--)
        {
            if (x[i] <= j && dp[j - x[i]])
                dp[j] = true;
        }
    }
    set<int> res;
    for (int i = 1; i <= 1e5; i++)
    {
        if (dp[i])
            res.insert(i);
    }
    cout << res.size() << '\n';
    for (int i : res)
        cout << i << " ";
    return 0;
}